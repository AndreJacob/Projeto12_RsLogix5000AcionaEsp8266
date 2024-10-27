
void reconnectMQTT()
{ //Função: reconecta-se ao broker MQTT (caso ainda não esteja conectado ou em caso de a conexão cair)
  //        em caso de sucesso na conexão ou reconexão, o subscribe dos tópicos é refeito.
  //Parâmetros: nenhum
  //Retorno: nenhum
  while (!MQTT.connected())
  { Serial.print("* Tentando se conectar ao Broker MQTT: ");
    Serial.println(BROKER_MQTT);
    if (MQTT.connect(ID_MQTT))
    { Serial.println("Conectado com sucesso ao broker MQTT!");
      MQTT.subscribe(TOPICO_SUBSCRIBE);
    }
    else
    { Serial.println("Falha ao reconectar no broker.");
      Serial.println("Havera nova tentatica de conexao em 2s");
      delay(2000);
    }
  }
}
