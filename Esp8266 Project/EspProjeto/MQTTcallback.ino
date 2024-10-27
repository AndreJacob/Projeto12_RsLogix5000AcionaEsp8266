
void mqtt_callback(char* topic, byte* payload, unsigned int length)
{ //Função: função de callback esta função é chamada toda vez que uma informação de um dos tópicos subescritos chega)
  //Parâmetros: nenhum
  //Retorno: nenhum
  String msg;
  //obtem a string do payload recebido
  for (int i = 0; i < length; i++)
  { char c = (char)payload[i];
    msg += c;
  }
  delay(5);
  Serial.println(msg);

 // DESLIGAR SAÍDAS DIGITAIS
  if ((msg == "0")||(msg == "2")||(msg == "4")||(msg == "6")||
     (msg == "8")||(msg == "10")||(msg == "12")||(msg == "14")||
     (msg == "16")||(msg == "18")||(msg == "20")||(msg == "22")||
     (msg == "24")||(msg == "26")||(msg == "28")||(msg == "30"))
     {digitalWrite(D0, LOW);}

  if ((msg == "0")||(msg == "1")||(msg == "4")||(msg == "5")||
      (msg == "8")||(msg == "9")||(msg == "12")||(msg == "13")||
      (msg == "16")||(msg == "17")||(msg == "20")||(msg == "21")||
      (msg == "24")||(msg == "25")||(msg == "28")||(msg == "29"))
      {digitalWrite(D2, LOW);}

  if ((msg == "0")||(msg == "1")||(msg == "2")||(msg == "3")||
      (msg == "8")||(msg == "9")||(msg == "10")||(msg == "11")||
      (msg == "16")||(msg == "17")||(msg == "18")||(msg == "19")||
      (msg == "24")||(msg == "25")||(msg == "26")||(msg == "27"))
      {digitalWrite(D3, LOW);}

  if ((msg == "0")||(msg == "1")||(msg == "2")||(msg == "3")||
      (msg == "4")||(msg == "5")||(msg == "6")||(msg == "7")||
      (msg == "16")||(msg == "17")||(msg == "18")||(msg == "19")||
      (msg == "20")||(msg == "21")||(msg == "22")||(msg == "23"))
      {digitalWrite(D5, LOW);}

  if ((msg == "0")||(msg == "1")||(msg == "2")||(msg == "3")||
      (msg == "4")||(msg == "5")||(msg == "6")||(msg == "7")||
      (msg == "8")||(msg == "9")||(msg == "10")||(msg == "11")||
      (msg == "12")||(msg == "13")||(msg == "14")||(msg == "15"))
      {digitalWrite(D6, LOW);}

   //LIGAR SAÍDAS DIGITAIS
  if ((msg == "1")||(msg == "3")||(msg == "5")||(msg == "7")||
     (msg == "9")||(msg == "11")||(msg == "13")||(msg == "15")||
     (msg == "17")||(msg == "19")||(msg == "21")||(msg == "23")||
     (msg == "25")||(msg == "27")||(msg == "29")||(msg == "31"))
     {digitalWrite(D0, HIGH);}

  if ((msg == "2")||(msg == "3")||(msg == "6")||(msg == "7")||
      (msg == "10")||(msg == "11")||(msg == "14")||(msg == "15")||
      (msg == "18")||(msg == "19")||(msg == "22")||(msg == "23")||
      (msg == "26")||(msg == "27")||(msg == "30")||(msg == "31"))
      {digitalWrite(D2, HIGH);}

  if ((msg == "4")||(msg == "5")||(msg == "6")||(msg == "7")||
      (msg == "12")||(msg == "13")||(msg == "14")||(msg == "15")||
      (msg == "20")||(msg == "21")||(msg == "22")||(msg == "23")||
      (msg == "28")||(msg == "29")||(msg == "30")||(msg == "31"))
      {digitalWrite(D3, HIGH);}

  if ((msg == "8")||(msg == "9")||(msg == "10")||(msg == "11")||
      (msg == "12")||(msg == "13")||(msg == "14")||(msg == "15")||
      (msg == "24")||(msg == "25")||(msg == "26")||(msg == "27")||
      (msg == "28")||(msg == "29")||(msg == "30")||(msg == "31"))
      {digitalWrite(D5, HIGH);}

  if ((msg == "16")||(msg == "17")||(msg == "18")||(msg == "19")||
      (msg == "20")||(msg == "21")||(msg == "22")||(msg == "23")||
      (msg == "24")||(msg == "25")||(msg == "26")||(msg == "27")||
      (msg == "28")||(msg == "29")||(msg == "30")||(msg == "31"))
      {digitalWrite(D6, HIGH);}


  //Controle de Inputs:
  if(digitalRead(D1)==0 &&digitalRead(D7)==0 &&digitalRead(D8)==0){MQTT.publish(TOPICO_PUBLISH, "Input_000");}
  if(digitalRead(D1)==0 &&digitalRead(D7)==0 &&digitalRead(D8)==1){MQTT.publish(TOPICO_PUBLISH, "Input_001");}
  if(digitalRead(D1)==0 &&digitalRead(D7)==1 &&digitalRead(D8)==0){MQTT.publish(TOPICO_PUBLISH, "Input_010");}
  if(digitalRead(D1)==0 &&digitalRead(D7)==1 &&digitalRead(D8)==1){MQTT.publish(TOPICO_PUBLISH, "Input_011");}
  if(digitalRead(D1)==1 &&digitalRead(D7)==0 &&digitalRead(D8)==0){MQTT.publish(TOPICO_PUBLISH, "Input_100");}
  if(digitalRead(D1)==1 &&digitalRead(D7)==0 &&digitalRead(D8)==1){MQTT.publish(TOPICO_PUBLISH, "Input_101");}
  if(digitalRead(D1)==1 &&digitalRead(D7)==1 &&digitalRead(D8)==0){MQTT.publish(TOPICO_PUBLISH, "Input_110");}
  if(digitalRead(D1)==1 &&digitalRead(D7)==1 &&digitalRead(D8)==1){MQTT.publish(TOPICO_PUBLISH, "Input_111");}

}
