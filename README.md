# **Trabalho de estrutura de dados**
## 1. Descrição do trabalho

O trabalho prático de programação consiste em simular o processo de realização de exames de raio-X de
tórax em um hospital, com ênfase na organização da fila para laudo médico. A cada momento, pacientes
chegam ao hospital e exames são realizados mediante disponibilidade de aparelhos. A IA1 sugere diagnósticos 
preliminares e os exames são encaminhados para laudo de acordo com a disponibilidade da equipe de radiologistas.

Neste etapa do trabalho, o objetivo é implementar dois tipos abstratos de dados (TADs): Patient e
Exam Esses TADs serão utilizados para modelar os pacientes que chegam ao hospital e os exames de
raio-X.

## 2. Tipo abstrato de dados
### 2.1 Patient
O TAD **Patient** representa um paciente no sistema. Ele possui uma estrutura chamada de Patient com as seguintes informações:
- Identificação única do paciente (int id); 
- Nome do paciente (char* name);
- Data de nascimento (struct tm* birthdate).
  
Além dessa estrutura, ele implementa as funções:
- `Patient* create_patient(int id, const char *name, struct tm *birthdate)`: Essa função tem como objetivo cadastrar um novo paciente. Para isso, ela aloca memória para Patient utilizando a função malloc. Após isso, é verificado se a memória foi alocada corretamente, se a função malloc retorna NULL, a memória foi alocada de maneira incorreta e por meio do comando exit( 1 ) o programa é abortado. Mas, se a função malloc retorna qualquer valor diferente de NULL, a função começa a preencher o id, o nome e a data de nascimento do paciente. Após preencher os dados, a função retorna um ponteiro para a estrutura Patient.  
- `void destroy_patient(Patient *patient)`: A função destroy_patient tem como função liberar a memória utilizada por meio do comando free. 
- `int get_patient_id(Patient* patient)`: A função get_patient_id tem como função retornar o id de determinado paciente, utilizando o comando return patient->id. Esse bloco de comando acessa o dado armazenado na estrutura Patient “int id”. 
- `const char* get_patient_name(Patient* patient)`:A função get_patient_name tem como função retornar o nome de determinado paciente, utilizando o comando return patient->name. Esse bloco de comando acessa o dado armazenado na estrutura Patient “char* name”. 
- `struct tm* get_patient_birthdate(Patient *patient)`:A função get_patient_birthdate tem como função retornar a data de nascimento de determinado paciente, utilizando o comando return patient->birthdate. Esse bloco de comando acessa o dado armazenado na estrutura Patient “struct tm* birthdate”.
### 2.2 Exam
O TAD **Exam** representa um exame realizado por um paciente no sistema. Ele possui uma estrutura chamada de Exam com as seguintes informações:
- Identificação única do exame (int id);
- Identificação única do paciente (int patient_id);
- Identificação única do aparelho de raio-X utilizado para realização do exame (int rx_id);
- Horário de realização do exame (struct tm* time).

Além dessa estrutura, ele implementa as funções:
- `Exam* create_exam(int id, int patient_id, int rx_id, struct tm *time)`: Essa função tem como objetivo criar um novo exame para determinado paciente. Para isso, ela aloca memória para Exam utilizando a função malloc. Após isso, é verificado se a memória foi alocada corretamente, se a função malloc retorna NULL, a memória foi alocada de maneira incorreta e por meio do comando exit( 1 ) o programa é abortado. Mas, se a função malloc retorna qualquer valor diferente de NULL, a função começa a preencher a identificação única do exame, identificação única do paciente, identificação única do aparelho de raio-X utilizado para realização do exame e o horário de realização do exame. Após preencher os dados, a função retorna um ponteiro para a estrutura Exam.
-  `void destroy_exam(Exam *exam)`: A função destroy_exam tem como função liberar a memória utilizada por meio do comando free.
-   `int get_exam_id(Exam *exam)`: A função get_exam_id tem como função retornar o id do exame de determinado paciente,

### 2.3 Funções Utilitárias
As funções utilitárias correspondem às funções usadas para auxiliar em tarefas de verificação e obtenção de informações específicas para auxiliar as funções destinadas a operações envolvendo a o tipo de dado Patient e o tipo Exam. Sendo assim, a seguir encontra-se a explicação de cada função auxiliar criada:

-  `int verify_year(int ano)`: essa função irá verificar se o ano de nascimento do paciente está dentro do escopo adequado. Ou seja, irá verificar se o ano encontra-se em um período anterior ao ano vigente, para que não ocorra nenhuma inconsistência em relação aos dados do paciente e para que o sistema desenvolvido estabeleça limites em relação às informações fornecidas pelo usuário.

-  `int is_bissexto(int ano)`: essa função irá verificar se o ano passado como parâmetro é um ano bissexto.

-  `int verify_day(int ano, int mes, int dia, int* max_mes)`: essa função irá verificar se o dia de nascimento informado pelo paciente se enquadra dentro do mês informado, para que não haja nenhuma inconsistência/absurdo. Isso é devido ao fato de que há o ano bissexto, o qual possui um dia a mais, o que deve ser levado em consideração para pacientes que nasceram no dia 29 de fevereiro.

-  `char* get_birthday_weekday(int ano, int mes, int dia, Patient* patient)`: essa função irá retornar o dia da semana em que a pessoa nasceu conforme a data informada.
## Criadores
- Vitor Ramos
- Allicia Rocha
