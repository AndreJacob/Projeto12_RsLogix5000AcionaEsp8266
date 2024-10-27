PROJETO: 
Comunicação entre PLC Rockwell RSLogix5000 e ESP8266

DESCRIÇÃO:
Este projeto demonstra a integração de um PLC Rockwell RSLogix5000 com um módulo ESP8266, usando Python como intermediário para comunicação via MQTT.

FUNCIONAMENTO:
RSLogix 5000 → Envia dados para um código Python através de uma biblioteca dedicada.
Python:
Recebe e envia dados para o PLC usando a biblioteca pycomm3.
Recebe e envia dados para o ESP8266 através do protocolo MQTT, utilizando o Mosquitto como broker.
ESP8266 → Recebe e envia dados via MQTT, também se conectando ao broker Mosquitto.
O segredo da comunicação está no uso do Python, que permite a integração fluida com diversas bibliotecas e facilita a troca de informações entre o PLC e o ESP8266.

VIDEO DEMONSTRATIVO:
Confira o projeto em funcionamento neste vídeo no YouTube.
Link: https://www.youtube.com/watch?v=-yIeTVzL5c4
