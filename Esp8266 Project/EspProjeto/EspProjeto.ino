// Backup código Arduino dia 22/08/2022

#include <ESP8266WiFi.h> // Importa a Biblioteca ESP8266WiFi
#include <PubSubClient.h> // Importa a Biblioteca PubSubClient


//defines de id mqtt e tópicos para publicação e subscribe
#define TOPICO_SUBSCRIBE "jsonUnico"     //tópico MQTT de escuta
#define TOPICO_PUBLISH   "IOTout"    //tópico MQTT de envio de informações para Broker                                    
#define ID_MQTT  "HomeAut"     //id mqtt (para identificação de sessão)
//IMPORTANTE: este deve ser único no broker (ou seja, se um client MQTT tentar entrar com o mesmo id de outro já conectado ao broker, o broker irá fechar a conexão de um deles).
//defines - mapeamento de pinos do NodeMCU
#define D0    16
#define D1    5
#define D2    4
#define D3    0
#define D4    2
#define D5    14
#define D6    12
#define D7    13
#define D8    15
#define D9    3
#define D10   1

// WIFI
const char* SSID = "Cobertura"; // SSID / nome da rede WI-FI que deseja se conectar
const char* PASSWORD = "Andre@273"; // Senha da rede WI-FI que deseja se conectar

// MQTT
const char* BROKER_MQTT = "153.92.214.250"; //URL do broker MQTT que se deseja utilizar
int BROKER_PORT = 1886; // Porta do Broker MQTT

//Variáveis e objetos globais
WiFiClient espClient; // Cria o objeto espClient
PubSubClient MQTT(espClient); // Instancia o Cliente MQTT passando o objeto espClient
char EstadoSaida = '0';  //variável que armazena o estado atual da saída

//Prototypes
void initSerial();
void initWiFi();
void initMQTT();
void reconectWiFi();
void mqtt_callback(char* topic, byte* payload, unsigned int length);
void VerificaConexoesWiFIEMQTT(void);
void InitOutput(void);


void setup()
{ //Implementações das funções
  //inicializações:
  InitOutput();
  initSerial();
  initWiFi();
  initMQTT();
  pinMode(D1,INPUT);
  pinMode(D7,INPUT);
  pinMode(D8,INPUT);
}

void loop()
{ //programa principal
  //garante funcionamento das conexões WiFi e ao broker MQTT
  VerificaConexoesWiFIEMQTT();
  //envia o status de todos os outputs para o Broker no protocolo esperado
  EnviaEstadoOutputMQTT();
  //keep-alive da comunicação com broker MQTT
  MQTT.loop();

}
