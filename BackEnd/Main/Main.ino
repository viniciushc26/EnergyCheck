/*/////////////////////////////////////////////////////////////////////////*/
/*                                                                         */
/*                    CONFIGURAÇÕES DO USUÁRIO                            */
/*                                                                         */
/*/////////////////////////////////////////////////////////////////////////*/

/*
  Insira seu endereço de e-mail cadastrado abaixo. Isso permite a
  personalização e envio de dados para o banco de dados. Exemplo:
  
  const char* usuarioEmail = "seu_email@example.com";
*/


 const char* usuarioEmail = "**********************";






#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h> 
#include <ArduinoJson.h>
#include "time.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <EmonLib.h>



#define WIFI_SSID "*********"
#define WIFI_PASSWORD "*********"
#define FIREBASE_HOST "******************************************"    
#define FIREBASE_AUTH "*******************************************"   

#define NUM_AMOSTRAST 10  // Número de amostras para a média da tensão
#define NUM_AMOSTRASC 10  // Número de amostras para a média da corrente
#define PINO_TENSAO 35    // Pino ao qual o sensor de tensão está conectado
#define PINO_CORRENTE 34    // Pino ao qual o sensor de corrente está conectado



//float valor = 0;

//unsigned long sendDataPrevMillis = 0;
//int count = 0;

EnergyMonitor emon;

TaskHandle_t Task1;
TaskHandle_t Task2;

String emailFormatado;

const long gmtOffset_sec = -3 * 3600;
const int daylightOffset_sec = 0;                                                 // Sem horário de verão 
WiFiUDP ntpUDP;                                                                   // Crie um objeto UDP para comunicação com o servidor NTP
NTPClient timeClient(ntpUDP, "pool.ntp.org", gmtOffset_sec, daylightOffset_sec);  // Crie um objeto NTPClient


void setup(){
  Serial.begin(115200);

  emailFormatado = usuarioEmail;
  emailFormatado.replace(".", "_");
  emailFormatado.replace("-", "_");


  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */  
 delay(500);

  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 0 */  
 delay(500);
 

  emon.current(PINO_CORRENTE, 10.35);  // Configura o sensor de corrente no pino 34, com fator de calibração de 12.644
  emon.voltage(PINO_TENSAO, 135.84, 1.7);  // Configura o sensor de tensão no pino 35, com fator de calibração de 220 e offset de 1.7
   
  
  conectar_WiFi();
  Ler_dados();
  timeClient.begin();
  hora_Atual();
  data_Atual();
  meses_Passados();
}

void loop(){
conectar_WiFi();
delay(30000);
}
