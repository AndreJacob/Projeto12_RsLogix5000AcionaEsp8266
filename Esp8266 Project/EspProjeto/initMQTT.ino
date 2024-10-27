
void initMQTT()
{ //Função: inicializa parâmetros de conexão MQTT(endereço do
  //        broker, porta e seta função de callback)
  //Parâmetros: nenhum
  //Retorno: nenhum
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);   //informa qual broker e porta deve ser conectado
  MQTT.setCallback(mqtt_callback);            //atribui função de callback (função chamada quando qualquer informação de um dos tópicos subescritos chega)
}
