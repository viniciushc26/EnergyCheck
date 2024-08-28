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


 const char* usuarioEmail = "vinicius.hercilio00@gmail.com";






#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h> 
#include <ArduinoJson.h>
#include "time.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <EmonLib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define WIFI_SSID "PATRICIA"
#define WIFI_PASSWORD "28182631"
#define FIREBASE_HOST "https://energy-check-64-default-rtdb.firebaseio.com/"    
#define FIREBASE_AUTH "ah7etohQYaZpkTLBPaGV6tUU4yQp24F1NDhh2vOy"   

#define PINO_CORRENTE 34    // Pino ao qual o sensor de corrente está conectado
#define PINO_TENSAO 32

EnergyMonitor emon1;

TaskHandle_t Task1;
TaskHandle_t Task2;

String emailFormatado;

const long gmtOffset_sec = -3 * 3600;
const int daylightOffset_sec = 0;                                                 // Sem horário de verão 
WiFiUDP ntpUDP;                                                                   // Crie um objeto UDP para comunicação com o servidor NTP
NTPClient timeClient(ntpUDP, "pool.ntp.org", gmtOffset_sec, daylightOffset_sec);  // Crie um objeto NTPClient

int aux = 0;
double tensao_Atual = 0, corrente_Atual = 0;
void setup(){
  Serial.begin(115200);

  emailFormatado = usuarioEmail;
  emailFormatado.replace(".", "_");
  emailFormatado.replace("-", "_");


  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    50000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */  
 delay(500);

  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    50000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 0 */  
 delay(500);
 

  emon1.current(PINO_CORRENTE, 10.7);  // Configura o sensor de corrente, com fator de calibração de 10.7
  emon1.voltage(PINO_TENSAO, 115.55, 1.7);  // Configura o sensor de tensao
  
  conectar_WiFi();
  Ler_dados();
  timeClient.begin();
  hora_Atual();
  data_Atual();
  meses_Passados();
  bandeira();
}

void loop(){
    float tensao_Somada = 0;
    float corrente_Somada = 0;

    for (int i = 0; i < 3; i++) {
        emon1.calcVI(20, 2000);
        tensao_Somada += emon1.Vrms;
        }
   tensao_Atual = tensao_Somada/3;
    if (tensao_Atual > 230 || tensao_Atual < 210) {
        tensao_Atual = 222; 
    } 
    tensao_Somada = 0;
    Serial.print("A tensão é: ");
    Serial.print(tensao_Atual);
    Serial.println("V");

     for (int i = 0; i < 3; i++) {
       corrente_Somada += emon1.calcIrms(1480);
        }
        

        
   
      corrente_Atual = corrente_Somada/3;
      corrente_Somada = 0;
      Serial.print("A corrente é: ");
      Serial.print(corrente_Atual);
      Serial.println("A");
     






}
