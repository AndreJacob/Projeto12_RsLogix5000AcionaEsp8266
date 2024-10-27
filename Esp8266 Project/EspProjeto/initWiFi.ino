
void initWiFi()
{ //Função: inicializa e conecta-se na rede WI-FI desejada
  delay(10);
  Serial.println("------Conexao WI-FI------");
  Serial.print("Conectando-se na rede: ");
  Serial.println(SSID);
  Serial.println("Aguarde");
  reconectWiFi();
}
