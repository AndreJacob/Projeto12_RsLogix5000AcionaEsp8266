void InitOutput(void)
{ //Função: inicializa o output em nível lógico baixo
  //Parâmetros: nenhum
  //Retorno: nenhum
  //IMPORTANTE: o Led já contido na placa é acionado com lógica invertida (ou seja,
  //enviar HIGH para o output faz o Led apagar / enviar LOW faz o Led acender)
  pinMode(D2, OUTPUT);
  digitalWrite(D2,LOW);
  pinMode(D0, OUTPUT);
  digitalWrite(D0,LOW);
  pinMode(D3, OUTPUT);
  digitalWrite(D3,LOW);
   pinMode(D5, OUTPUT);
  digitalWrite(D5,LOW);
  pinMode(D6, OUTPUT);
  digitalWrite(D6,LOW);
}
