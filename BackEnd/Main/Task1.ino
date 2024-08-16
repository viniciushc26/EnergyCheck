double corrente_Atual = 0;
double tensao_Atual = 220;
double potencia_Atual = 0;
double kW_Consumido =0;
double kWh_Instantaneo =0;
unsigned long lastmillis = millis();
int aux_bandeira = 0;



float restante_Mes = 0;
int aux = 0;

void Task1code( void * pvParameters ){
 for(;;) {
 



  if( aux == 0){
    delay(50000);
    aux++;
  }


    if((millis() - lastmillis)>1000){
      lastmillis = millis();
      corrente_Atual = emon.calcIrms(1480);
      Serial.print("A corrente é: ");
      Serial.print(corrente_Atual);
      Serial.println("A");
    }


    for( int i=0; i<NUM_AMOSTRAST; i++){
      emon.calcVI(20, 100);  // Realiza a medição da tensão e corrente (20 ciclos de amostragem, período de 100 microssegundos)
      double tensao = emon.Vrms;
      tensao_Atual += tensao;}

    tensao_Atual = tensao_Atual/NUM_AMOSTRAST;

  
    potencia_Atual = corrente_Atual*tensao_Atual;  //potencia

    kW_Consumido = potencia_Atual/1000;            //kw
    
    kWh_Instantaneo = kW_Consumido/3600;           //kwh

    potencia_Total += kWh_Instantaneo;

    fatura_Atual += kWh_Instantaneo*preco_kWh;      //fatura_Atual -----------

    kWh_Hora += kWh_Instantaneo*preco_kWh;
    kWh_Diario += kWh_Instantaneo*preco_kWh;    




    //bloco funcional ^^

    








    restante_Mes = 30 - dia_Mes;
    Proxima_fatura = fatura_Atual/dia_Mes*30;
    
    //fatura_Estimada = fatura_Atual + (kWh_Seg + kWh_Ter + kWh_Qua + kWh_Qui + kWh_Sex + kWh_Sab + kWh_Dom)/7*restante_Mes*preco_kWh;

   
}
}
