# data_structure
## 1. Trabalho de estrutura de dados

O trabalho prático de programação consiste em simular o processo de realização de exames de raio-X de
tórax em um hospital, com ênfase na organização da fila para laudo médico. A cada momento, pacientes
chegam ao hospital e exames são realizados mediante disponibilidade de aparelhos. A IA1 sugere diagnósticos 
preliminares e os exames são encaminhados para laudo de acordo com a disponibilidade da equipe de radiologistas.

Neste etapa do trabalho, o objetivo é implementar dois tipos abstratos de dados (TADs): Patient e
Exam Esses TADs serão utilizados para modelar os pacientes que chegam ao hospital e os exames de
raio-X.

## 2. Tipo abstrato de dados
### 2.1 - Patient
O TAD **Patient** representa um paciente no sistema. Ele possui uma estrutura chamada de Patient com as seguintes informações:
- Identificação única do paciente (int id); 
- Nome do paciente (char* name);
- Data de nascimento (struct tm* birthdate).
