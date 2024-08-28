double potencia_Atual = 0;
double kW_Consumido =0;
double kWh_Instantaneo =0;
unsigned long lastmillis = millis();
int aux_bandeira = 0;
float restante_Mes = 0;


void Task1code( void * pvParameters ){
 for(;;) {
 
  if( aux == 0){
    delay(45000);
    aux++;
  }


     if((millis() - lastmillis)>1000){
      lastmillis = millis();


 
         
//      Serial.print("A potencia total consumida é: ");
//      Serial.print(potencia_Total);
//      Serial.println("kWh");
  
      potencia_Atual = corrente_Atual*tensao_Atual;  //potencia

      kW_Consumido = potencia_Atual/1000;            //kw
    
      kWh_Instantaneo = kW_Consumido/3600;           //kwh

      potencia_Total += kWh_Instantaneo;

      fatura_Atual = potencia_Total*preco_kWh;      //fatura_Atual -----------

      kWh_Hora += kWh_Instantaneo*preco_kWh;
      kWh_Diario += kWh_Instantaneo*preco_kWh;    

//      Serial.print("O preço do kWh é: R$");
//      Serial.println(preco_kWh);
//
//      Serial.print("A fatura atual é: R$");
//      Serial.println(fatura_Atual);
   






    restante_Mes = 30 - dia_Mes;
    Proxima_fatura = fatura_Atual/dia_Mes*30;
    
    //fatura_Estimada = fatura_Atual + (kWh_Seg + kWh_Ter + kWh_Qua + kWh_Qui + kWh_Sex + kWh_Sab + kWh_Dom)/7*restante_Mes*preco_kWh;
    
    }
    
    vTaskDelay(pdMS_TO_TICKS(100)); 
} 
}
