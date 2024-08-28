unsigned long Tempo_Funcao = millis();
int aux_Task2 = 0;

void Task2code( void * pvParameters ){

   for(;;) {

    if(aux_Task2 == 0){
      aux_Task2 ++;
      delay(60000);
    }

   if(millis() - Tempo_Funcao > 15000){
      tela_Home();
      hora_Atual();
      data_Atual();
      meses_Passados();
      bandeira();
      Tempo_Funcao = millis(); // Atualiza Tempo_Funcao para o tempo atual
    }

    

    vTaskDelay(pdMS_TO_TICKS(1000)); // Atraso de 1000 milissegundos (1 segundo)

 }
}
