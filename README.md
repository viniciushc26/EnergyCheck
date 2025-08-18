# EnergyCheck - Sua Fatura de Energia na Palma da Mão

**Monitoramento e Estimativa de Consumo de Energia Elétrica em Tempo Real**

O projeto **EnergyCheck** propõe o desenvolvimento de um aplicativo móvel que visa auxiliar usuários residenciais no monitoramento e na estimativa do consumo de energia elétrica. A aplicação aborda a problemática da falta de informação em tempo real sobre o consumo energético, o que dificulta a tomada de decisões conscientes sobre o uso da eletricidade e pode levar a surpresas desagradáveis na fatura mensal.

**Funcionalidades e Implementação:**

O EnergyCheck oferece as seguintes funcionalidades chave:

**Medição em Tempo Real:** Através da integração com um microcontrolador ESP32, o aplicativo coleta e exibe dados de consumo de energia em kWh em tempo real, permitindo ao usuário acompanhar o impacto de seus hábitos de consumo.

**Estimativa de Fatura:** Com base nos dados de consumo e nas tarifas da região de Santa Catarina, o aplicativo realiza uma estimativa do valor da fatura de energia, auxiliando o usuário no planejamento financeiro.

**Previsão de Gastos:** O EnergyCheck projeta o gasto total de energia ao final do mês, considerando o padrão de consumo atual, permitindo ao usuário identificar potenciais excessos e adotar medidas de economia.

**Visualização de Dados:** Gráficos e relatórios detalhados sobre o consumo diário e semanal auxiliam na identificação de padrões de uso e na tomada de decisões para otimizar o consumo.

**Histórico de Faturas:** O aplicativo armazena o histórico das últimas faturas, permitindo ao usuário comparar seu consumo ao longo do tempo e avaliar a efetividade de suas ações para reduzir gastos.

**Notificações:** O usuário pode definir um limite de gasto desejado para o mês e receberá notificações quando o consumo se aproximar desse valor, incentivando o uso consciente da energia.

A implementação do EnergyCheck envolve o desenvolvimento de um front-end em React Native com Expo, responsável pela interface do usuário e pela interação com o usuário, e um back-end utilizando o Arduino IDE para programar o microcontrolador ESP32, que realiza a coleta dos dados de consumo. O Firebase é utilizado como banco de dados para armazenar e gerenciar os dados coletados e as informações do usuário.

**Relevância e Impacto:**

O EnergyCheck apresenta relevância acadêmica e social ao abordar um problema concreto enfrentado por muitos consumidores de energia elétrica: a falta de controle e previsibilidade sobre seus gastos. Ao fornecer informações em tempo real e ferramentas de análise, o aplicativo contribui para a conscientização sobre o consumo energético e incentiva a adoção de práticas mais sustentáveis e econômicas.

**Conclusão:**

O projeto **EnergyCheck** demonstra a aplicação prática de conceitos e tecnologias estudadas no curso de Engenharia Elétrica no IFSC - Itajaí, integrando o desenvolvimento de hardware e software para criar uma solução inovadora e acessível. A implementação bem-sucedida do aplicativo resultará em uma ferramenta valiosa para o controle e a gestão do consumo de energia elétrica em residências, com potencial para impactar positivamente o meio ambiente e a economia dos usuários.
