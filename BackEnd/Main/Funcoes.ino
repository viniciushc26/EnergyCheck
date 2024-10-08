double fatura_Atual, Gasto_ultimo_Mes, Gasto_penultimo_Mes, Gasto_antepenultimo_Mes, potencia_Total, Proxima_fatura;
double kWh_Seg = 0, kWh_Ter = 0, kWh_Qua = 0, kWh_Qui = 0, kWh_Sex = 0, kWh_Sab = 0, kWh_Dom = 0;

int Aux_hora = 300, mes, dia_Semana, mes_Passado1, mes_Passado2, mes_Passado3, dia_Mes; 
int bandeira_vigente = 0;
int   AuxDom  = 0, AuxSeg  = 0, AuxTer  = 0, AuxQua  = 0, AuxQui  = 0, AuxSex  = 0, AuxSab  = 0;

int Aux_dia_Semana = 100;
float kWh_Diario = 0;
String aux_ultimo_Mes;
double preco_kWh =0;
double kWh_Hora = 0;


void conectar_WiFi() {
  unsigned long startTime = millis();
  const unsigned long timeout = 30000; // 30 segundos de timeout

  if (WiFi.status() != WL_CONNECTED) {
    while (WiFi.status() != WL_CONNECTED && millis() - startTime < timeout) {
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      Serial.print("Connecting to Wi-Fi");

      while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(300);
      }

      Serial.println();
      Serial.print("Conectado ao IP: ");
      Serial.println(WiFi.localIP());
      Serial.println();
      conectar_FireBase();
  
    }
  }
}


/************************************************************************************************************************************************/

void conectar_FireBase() {
      Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
      Serial.println("Conectado ao Firebase");
      Serial.println();
    }



/************************************************************************************************************************************************/

void Ler_dados() {
      
  Serial.println("Obtendo dados");
  
  if (WiFi.status() == WL_CONNECTED) {
    String path = "users/" + emailFormatado + "/dados/home/Fatura_atual";
    String path2 = "users/" + emailFormatado + "/dados/relatorios/Mensal/Ultimo_mes";
    String path3 = "users/" + emailFormatado + "/dados/relatorios/Mensal/Gasto_ultimo_Mes";
    String path4 = "users/" + emailFormatado + "/dados/relatorios/Mensal/Gasto_penultimo_Mes";
    String path5 = "users/" + emailFormatado + "/dados/relatorios/Mensal/Gasto_antepenultimo_Mes";
    String path6 = "users/" + emailFormatado + "/dados/relatorios/Semanal/Dia";
    String path7 = "users/" + emailFormatado + "/dados/relatorios/Diario/Hora";
    String path8 = "/configuracoes/bandeira";
    String path9 = "users/" + emailFormatado + "/dados/home/Potencia_total";
    String path10 = "users/" + emailFormatado + "/dados/relatorios/Semanal/DiaAuxiliar";

    
    fatura_Atual = Firebase.getFloat(path);
    //Serial.print("A fatura atual é ");
    //Serial.println(fatura_Atual);
    
    aux_ultimo_Mes = Firebase.getString(path2);
    //Serial.print("o aux_ultimo_Mes é ");
    //Serial.println(aux_ultimo_Mes);

    Gasto_ultimo_Mes = Firebase.getFloat(path3);
    //Serial.print("o Gasto_ultimo_Mes é ");
    //Serial.println(Gasto_ultimo_Mes);
    
    Gasto_penultimo_Mes = Firebase.getFloat(path4);
    //Serial.print("o Gasto_penultimo_Mes é ");
    //Serial.println(Gasto_penultimo_Mes);
    
    Gasto_antepenultimo_Mes = Firebase.getFloat(path5);
    //Serial.print("o Gasto_antepenultimo_Mes é ");
    //Serial.println(Gasto_antepenultimo_Mes);
    
    Aux_dia_Semana = Firebase.getInt(path6);
    //Serial.print("o Aux_dia_Semana é ");
    //Serial.println(Aux_dia_Semana);
    
    Aux_hora = Firebase.getInt(path7);
    //Serial.print("o Aux_hora é ");
    //Serial.println(Aux_hora);
    
    bandeira_vigente = Firebase.getInt(path8);
    //Serial.print("a bandeira_vigente é ");
    //Serial.println(bandeira_vigente);
    
    potencia_Total = Firebase.getFloat(path9);
    //Serial.print("a potencia_Total é ");
    //Serial.println(potencia_Total);

    kWh_Diario = Firebase.getFloat(path10);

    Serial.println("Dados obtidos");
    Serial.println();
  
}
}



/************************************************************************************************************************************************/

void hora_Atual(){
  
Serial.println("Obtendo o tempo");

  timeClient.update();
  time_t epochTime = timeClient.getEpochTime();
  struct tm *ptm = localtime(&epochTime);
  int Hora = ptm->tm_hour;
  int Min = ptm->tm_min;
  dia_Semana = ptm->tm_wday;
  mes = ptm->tm_mon + 1;
  mes_Passado1 = (ptm->tm_mon + 11) % 12 + 1;
  mes_Passado2 = (ptm->tm_mon + 10) % 12 + 1;
  mes_Passado3 = (ptm->tm_mon + 9) % 12 + 1;
  dia_Mes = ptm->tm_mday;

  /*
  Serial.print("Hora: ");
  Serial.println(Hora);
  Serial.print("Minutos: ");
  Serial.println(Min);
  Serial.print("Dia da semana: ");
  Serial.println(dia_Semana);
  Serial.print("Mês: ");
  Serial.println(mes);
  Serial.println("");
  */

  
    double kWh_3, kWh_6, kWh_9, kWh_12, kWh_15, kWh_18, kWh_21, kWh_23; 

    String path  = "users/" + emailFormatado + "/dados/relatorios/Diario/Hora";
    String path2 = "users/" + emailFormatado + "/dados/relatorios/Diario/d3h";
    String path3 = "users/" + emailFormatado + "/dados/relatorios/Diario/d6h";
    String path4 = "users/" + emailFormatado + "/dados/relatorios/Diario/d9h";
    String path5 = "users/" + emailFormatado + "/dados/relatorios/Diario/d12h";
    String path6 = "users/" + emailFormatado + "/dados/relatorios/Diario/d15h";
    String path7 = "users/" + emailFormatado + "/dados/relatorios/Diario/d18h";
    String path8 = "users/" + emailFormatado + "/dados/relatorios/Diario/d21h";
    String path9 = "users/" + emailFormatado + "/dados/relatorios/Diario/d2359h";
   
       if(Hora != Aux_hora){
          Firebase.setFloat(path,Hora);
          Aux_hora = Hora;


    
    switch (Hora) {
      case 3:
        kWh_3 = kWh_Hora;
        Firebase.setFloat(path2,kWh_3);
        kWh_Hora = 0;
        break;
      case 6:
        kWh_6 = kWh_Hora;
        Firebase.setFloat(path3,kWh_6);
        kWh_Hora = 0;
        break;
      case 9:
        kWh_9 = kWh_Hora;
        Firebase.setFloat(path4,kWh_9);
        kWh_Hora = 0;
        break;
      case 12:
        kWh_12 = kWh_Hora;
        Firebase.setFloat(path5,kWh_12);
        kWh_Hora = 0;
        break;
      case 15:
        kWh_15 = kWh_Hora;
        Firebase.setFloat(path6,kWh_15);
        kWh_Hora = 0;
        break;
      case 18:
        kWh_18 = kWh_Hora;
        Firebase.setFloat(path7,kWh_18);
        kWh_Hora = 0;
        break;
      case 21:
        kWh_21 = kWh_Hora;
        Firebase.setFloat(path8,kWh_21);
        kWh_Hora = 0;
        break;
      case 23:
        if(Min >50){
          kWh_23 = kWh_Hora;
          Firebase.setFloat(path9,kWh_23);
          kWh_Hora = 0;
        }
        default:
        break;
    }

}
}



/************************************************************************************************************************************************/

void data_Atual(){
  
  //Serial.println("Começando a obter os gastos da semana ");

    String path  = "users/" + emailFormatado + "/dados/home/Proxima_fatura";
    String path2 = "users/" + emailFormatado + "/dados/relatorios/Semanal/Dia";
    String path3 = "users/" + emailFormatado + "/dados/relatorios/Semanal/Dom";
    String path4 = "users/" + emailFormatado + "/dados/relatorios/Semanal/Seg";
    String path5 = "users/" + emailFormatado + "/dados/relatorios/Semanal/Ter";
    String path6 = "users/" + emailFormatado + "/dados/relatorios/Semanal/Qua";
    String path7 = "users/" + emailFormatado + "/dados/relatorios/Semanal/Qui";
    String path8 = "users/" + emailFormatado + "/dados/relatorios/Semanal/Sex";
    String path9 = "users/" + emailFormatado + "/dados/relatorios/Semanal/Sab";
    String path10 = "users/" + emailFormatado + "/dados/relatorios/Semanal/DiaAuxiliar";

    String path11 = "users/" + emailFormatado + "/dados/relatorios/Diario/d3h";
    String path12 = "users/" + emailFormatado + "/dados/relatorios/Diario/d6h";
    String path13 = "users/" + emailFormatado + "/dados/relatorios/Diario/d9h";
    String path14 = "users/" + emailFormatado + "/dados/relatorios/Diario/d12h";
    String path15 = "users/" + emailFormatado + "/dados/relatorios/Diario/d15h";
    String path16 = "users/" + emailFormatado + "/dados/relatorios/Diario/d18h";
    String path17 = "users/" + emailFormatado + "/dados/relatorios/Diario/d21h";
    String path18 = "users/" + emailFormatado + "/dados/relatorios/Diario/d2359h";
    
    
  
  if(dia_Semana != Aux_dia_Semana){
    Firebase.setFloat(path,Proxima_fatura);
    Firebase.setFloat(path2,dia_Semana);
    Aux_dia_Semana = dia_Semana;
  
     
     

    switch (dia_Semana) {
      case 0:
        kWh_Sab = kWh_Diario;
        Firebase.setFloat(path9,kWh_Sab);
        kWh_Diario = 0;
        Firebase.setFloat(path10,kWh_Diario);
        break;
      case 1:
        kWh_Dom = kWh_Diario;
        Firebase.setFloat(path3,kWh_Dom);
        kWh_Diario = 0;
        Firebase.setFloat(path10,kWh_Diario);
        break;
      case 2:
        kWh_Seg = kWh_Diario;
        Firebase.setFloat(path4,kWh_Seg);
        kWh_Diario = 0;
        Firebase.setFloat(path10,kWh_Diario);
        break;
      case 3:
        kWh_Ter = kWh_Diario;
        Firebase.setFloat(path5,kWh_Ter);
        kWh_Diario = 0;
        Firebase.setFloat(path10,kWh_Diario);
        break;
      case 4:
        kWh_Qua = kWh_Diario;
        Firebase.setFloat(path6,kWh_Qua);
        kWh_Diario = 0;
        Firebase.setFloat(path10,kWh_Diario);
        Serial.print("Hoje já gastou ");
        Serial.print(kWh_Qui);
        Serial.println("kWh ");
        break;
      case 5:
        kWh_Qui = kWh_Diario;
        Firebase.setFloat(path7,kWh_Qui);
        kWh_Diario = 0;
        Firebase.setFloat(path10,kWh_Diario);
        break;
      case 6:
        kWh_Sex = kWh_Diario;
        Firebase.setFloat(path8,kWh_Sex);
        kWh_Diario = 0;
        Firebase.setFloat(path10,kWh_Diario);
      default:
        break;
    }
    
    Firebase.setFloat(path11,0);
    Firebase.setFloat(path12,0);
    Firebase.setFloat(path13,0);
    Firebase.setFloat(path14,0);
    Firebase.setFloat(path15,0);
    Firebase.setFloat(path16,0);
    Firebase.setFloat(path17,0);
    Firebase.setFloat(path18,0);
    
    }

  //Serial.println("Gastos da semana obtidos ");
  //Serial.println();
}
/**************************************************************************************************/

void meses_Passados(){

//  Serial.println("Começando a obter os meses passados ");
  
  const char *nomesMeses[] = {"", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};


    String path  = "users/" + emailFormatado + "/dados/relatorios/Mensal/Gasto_antepenultimo_Mes";
    String path2 = "users/" + emailFormatado + "/dados/relatorios/Mensal/Gasto_penultimo_Mes";
    String path3 = "users/" + emailFormatado + "/dados/relatorios/Mensal/Gasto_ultimo_Mes";
    String path4 = "users/" + emailFormatado + "/dados/relatorios/Mensal/Ultimo_mes";
    String path5 = "users/" + emailFormatado + "/dados/relatorios/Mensal/Penultimo_mes";
    String path6 = "users/" + emailFormatado + "/dados/relatorios/Mensal/Antepenultimo_mes";
    String path7 = "users/" + emailFormatado + "/dados/home/Fatura_atual";
    String path8 = "users/" + emailFormatado + "/dados/home/Potencia_total";



  if (mes >= 1 && mes <= 12) {
    String ultimo_Mes = nomesMeses[mes_Passado1];
    String penultimo_Mes = nomesMeses[mes_Passado2];
    String antepenultimo_Mes = nomesMeses[mes_Passado3];

    if (aux_ultimo_Mes != ultimo_Mes) {
      aux_ultimo_Mes = ultimo_Mes;                // Atualiza a variável auxiliar
  

      Firebase.setFloat(path,Gasto_penultimo_Mes);
      
      Firebase.setFloat(path2,Gasto_ultimo_Mes);

      Gasto_ultimo_Mes = fatura_Atual;

      Firebase.setFloat(path3,Gasto_ultimo_Mes);
     
      fatura_Atual = 0;
      Firebase.setFloat(path7,fatura_Atual);
      
      potencia_Total = 0;
      Firebase.setFloat(path8,potencia_Total);

      Firebase.setFloat(path,Gasto_penultimo_Mes);

      Firebase.setString(path4, ultimo_Mes);

      Firebase.setString(path5, penultimo_Mes);

      Firebase.setString(path6, antepenultimo_Mes);
  }

  
    
  } 
//    Serial.println("Meses passados obtidos ");
//    Serial.println();
}


/**************************************************************************************************/


 
  void tela_Home(){
  if (WiFi.status() == WL_CONNECTED) {
    String path1 ="users/" + emailFormatado + "/dados/home/Fatura_atual";
    String path2 ="users/" + emailFormatado + "/dados/home/Potencia_total";
    String path3 ="users/" + emailFormatado + "/dados/home/Proxima_fatura";
    String path4 ="users/" + emailFormatado + "/dados/home/Corrente";

    Firebase.setFloat(path1,fatura_Atual);
    Firebase.setFloat(path2,potencia_Total);
    Firebase.setFloat(path3,Proxima_fatura);
    Firebase.setFloat(path4,corrente_Atual);

} 
}



/**************************************************************************************************/

 
 
void bandeira(){

//Serial.println("Obtendo a bandeira tarifária"); 


String path1 ="/configuracoes/bandeira";
bandeira_vigente = Firebase.getInt(path1);

  switch (bandeira_vigente){
    case 0: 
      if(potencia_Total <= 150){
        preco_kWh = 0.73;
    }else{
      preco_kWh = 0.77;
    }

    case 1:
    //Serial.println("A bandeira tarifária é a amarela"); 
      if(potencia_Total <= 150){
        preco_kWh = 0.77;
    }else{
      preco_kWh = 0.82;
    }
    //Serial.print("O preço do kWh é: R$");
    //Serial.println(preco_kWh);
    break;

    case 2: 
      if(potencia_Total <= 150){
        preco_kWh = 0.83;
    }else{
      preco_kWh = 0.88;
    }
    break;

    case 3: 
      if(potencia_Total <= 150){
        preco_kWh = 0.96;
    }else{
      preco_kWh = 1.02;
    }
    break;
    
    default:
     Serial.println("Não consegui encontrar o preço do kwh correto!");
    break;
    
    
  }
}

/**************************************************************************************************/
