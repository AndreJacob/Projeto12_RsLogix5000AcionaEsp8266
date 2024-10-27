void EnviaEstadoOutputMQTT(void)
{ //Função: envia ao Broker o estado atual do output
  //Parâmetros: nenhum
  //Retorno: nenhum

  if (EstadoSaida == '0')
    //MQTT.publish(TOPICO_PUBLISH, "D");
    delay(1);
  if (EstadoSaida == '1')
    //MQTT.publish(TOPICO_PUBLISH, "L");
  //Serial.println("- Estado da saida D0 enviado ao broker!");
  delay(0);
}
