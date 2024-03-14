# Proposta de Tema de PI3
Título: Desenvolvimento de um Aplicativo Android para Monitoramento de Consumo de Energia Elétrica Residencial

Aluno(s): Vinícius Hercilio Correa

Orientador: Fernanda Isabel Marques Argoud da Silva

# Objetivo geral
* Desenvolver um medidor de energia residencial para cálculo de gastos com energia elétrica no estado de SC através de um aplicativo android


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
