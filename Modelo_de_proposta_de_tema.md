# Proposta de Tema de PI3
Título: Desenvolvimento de um Aplicativo Android para Monitoramento de Consumo de Energia Elétrica Residencial

Aluno(s): Vinícius Hercilio Correa

Orientadora: Fernanda Isabel Marques Argoud da Silva

# Objetivo geral
* Desenvolver um medidor de energia residencial para cálculo de gastos com energia elétrica no estado de Santa Catarina através de um aplicativo android


# Objetivos específicos

* Desenvolver um circuito eletrônico para medir e registrar o consumo de energia elétrica em tempo real.
* Programar o microcontrolador para processar os dados coletados pelo circuito e calcular o consumo de energia em quilowatt-hora.
* Implementar um sistema de comunicação sem fio (Wi-Fi), para transferir os dados de consumo de energia para um dispositivo móvel.
* Desenvolver um aplicativo android para análise dos dados coletados, que permita ao usuário visualizar seu consumo de energia elétrica e estimar os 
  custos com base nas tarifas da CELESC.
* Testar o protótipo em uma residência e realizar ajustes necessários para garantir sua precisão e confiabilidade.
* Elaborar um relatório técnico que documente todo o processo de desenvolvimento do medidor de energia residencial e apresente os resultados obtidos nos 
  testes.

# Metodologia
   O projeto proposto é um medidor de quilowatt-hora, onde se é possível avaliar o custo da fatura da conta de luz. O sistema aborda a medição não invasiva, e os dados são administrados através de um código carregado ao microcontrolador, após isso, será enviado via wifi para um banco de dados, após esta etapa, o aplicativo ficará responsável por ler este banco de dados e apresentar as informações úteis ao consumidor, o usuário poderá visualizar informações como: Preço da fatura atual, preço estimado da próxima fatura com base nos gastos atuais, potência total consumida, relatório de gasto energético tanto semanal quanto diário, e saberá qual bandeira tarifária esta vigente no momento.

   Em suma, será um protótipo acoplado após ao o medidor de energia, que será capaz de analisar a corrente e a tensão através do cabo principal de fornecimento,  módulos de corrente e tensão serão encarregados das medições e estarão conectados ao ESP-32, o mesmo enviará os dados a um banco de dados para que seja possível que o usuário obtenha tais informações.
    Abaixo estão algumas referências encontradas em projetos similares:
    
[MEDIDOR DE DEMANDA DE ENERGIA ELÉTRICA RESIDENCIAL COM ACESSO REMOTO](https://repositorio.uniceub.br/jspui/bitstream/235/3857/1/Gilberto%20Jos%C3%A9%20De%20Paula%20Monografia%201_2013.pdf) : a monografia apresenta um medidor capaz de medir várias grandezas de equipamentos entre elas corrente, tensão e potência ativa,  através de sensores acoplados a um arduino, e envia-las a uma página html, podendo exclusivamente aferir um equipamento por vez, o protótipo apresentado é feito a partir do microcontrolador arduino acoplado ao sensor de corrente ACS712 , onde apresenta uma limitação de até 30 amperes, já para a tensão foi utilizado um transformador de tensão para adequação da tensão suportada pelo arduino. O projeto em si é parecido com a ideia deste projeto, porém, busca-se a medição da rede elétrica toda, pelo padrão CELESC a entrada é de 50A, sendo assim, a medição será feita de forma diferente ao apresentado no protótipo.

[ESTUDO DE UM MEDIDOR DE CORRENTE CONECTADO COM UMA PLATAFORMA IOT](https://repositorio.ifsc.edu.br/bitstream/handle/123456789/1749/Hermeson_TCC_Final.pdf?sequence=1&isAllowed=y) :  Este TCC apresenta uma ideia interessante, o mesmo armazena os dados medidos em uma plataforma chamada "ThingSpeak", e a pessoa responsável pelas aferições pode conferir de forma simples e rápida dados como: Fatura, Consumo por dia, semana e mês, em termos de comparação seria um protótipo parecido, porém limitado a aferição de um equipamento por vez.

[Iot based Smart Electricity Energy meter using ESP32 & blynk application](https://www.youtube.com/watch?v=FVGvR9qlEc8&t=6s): Este vídeo relata sobre um medidor de energia que envia os dados a um aplicativo criado pela plataforma blynk, uma plataforma interessante para criação de aplicativos, porém as referências encontradas batem sempre na mesma tecla, são medidos em equipamentos indivuais e não o consumo de uma residencia em valores monetários.

# Cronograma

Clique [aqui](https://github.com/users/viniciushc26/projects/3) para acessar o cronograma.

# Lista de materiais

| Item | Descrição | Unidade | Valor Unitário | Quantidade | Total |
| ---- | ------------- | --- | ------------- | ------------- | ------------- |
|  01  | Sensor de corrente 100A - SCT013      | peça      | R$ 60,00 | 1 | R$ 60,00  |
|  01  | Módulo Sensor de Tensão AC - ZMPT101B | peça      | R$ 30,00 | 1 | R$ 30,00  |
|  01  | ESP32 DEVKIT V1                       | peça      | R$ 80,00 | 1 | R$ 80,00  |
|  01  | Cabo Jumper                           | conjunto  | R$ 15,00 | 1 | R$ 15,00  | 
|  01  | Resistores e capacitores              | conjunto  | R$ 20,00 | 1 | R$ 20,00  |


# Unidades curriculares envolvidas
* Instalações elétricas;
* Microprocessadores.
* Programação 1
* Programação 2
