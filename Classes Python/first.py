# Made for André Jacob from Brazil in Oct/2022.
# Email: jacob.andre273@gmail.com
# Whatsapp: +55 31994803620

import time
import paho.mqtt.client as mqtt
from pycomm3 import LogixDriver

Broker = "153.92.214.250" # This IP is of Cloud Andre Bazil
porta_broker = 1886
keep_alive_broker = 60
topico_subscribe = "IOTout" # You have to change this name here and in Esp8266 programm.
   
def on_connect (client, userdata, flags, rc):
    client.subscribe(topico_subscribe)
    time.sleep(4) 
    
def on_message(client, userdata, msg):
    global texto;
    texto = msg.payload
    texto = texto.decode()
    client = mqtt.Client("Casa") # You have to change this name Casa to any other
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(Broker, 1886)  #porta_broker, keep_alive_broker)
    time.sleep(0.5)
    print("MQTT recebido do IOT :",  texto)
    
def arquivo():
    global jsonUnico; 
    with LogixDriver('192.168.147.129/2') as plc:
        valor = plc.read('PlcToEsp8266')
        print(valor[1])
        plc.write('PLCout[1]', texto)
        print(texto)
        client.publish("jsonUnico", valor[1])
        #Enviar = plc.read('Enviar_SMS')
        
        
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(Broker, 1886)  #porta_broker, keep_alive_broker)

texto = 0
while True:
    try:
        client.loop_start()
        arquivo()
        time.sleep(1) 
    except:
        print('Excessão: algum erro aconteceu.')