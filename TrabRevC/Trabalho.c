#include<stdio.h>
#include<string.h>

typedef struct Disciplina{
    char nome_professor[100];
    char nome_materia[40];
    char codigo[6];
    char periodo[6];
}Odisciplina; 

typedef struct lista_disciplinas{
    Odisciplina disciplina;
    struct lista_disciplinas *prox;
}LDisciplinas;

typedef struct aluno{
    char nome[100];
    char codigo[5];
    char cpf[12];
    LDisciplinas *inicio;
}Oaluno; 

typedef struct lista_aluno{
    Oaluno aluno;
    struct lista_aluno *prox;
}LAlunos;

void buscar_aluno_LA(LAlunos **inicio, char codigo_input[]){
    int achou = 0;
    LAlunos *aux;
    aux = *inicio;
    while(aux){
        if(strcmp(aux->aluno.codigo,codigo_input) == 0){
            printf("\nNome:%s \ncodigo: %s \ncpf: %s ",aux->aluno.nome,aux->aluno.codigo,aux->aluno.cpf);
            achou = 1;
            break;
        }
        aux = aux->prox; 
    }   
    if(achou == 0) printf("\nnao foi achado o aluno\n");
}

void inserir_aluno(LAlunos **pInicio, char nome_input[], char codigo_input[], char cpf_input[]){
    LAlunos *novo_elemento = (LAlunos*)malloc(sizeof(LAlunos));
    strcpy(novo_elemento->aluno.nome, nome_input);
    strcpy(novo_elemento->aluno.codigo, codigo_input);
    strcpy(novo_elemento->aluno.cpf, cpf_input);
    novo_elemento->prox = pInicio;
    *pInicio = novo_elemento;
}
/*
void inserir_materia(LDisciplinas **pInicio, char nome_disciplina[], char nome_professor[], char codigo_input[], char periodo_input[]){
    LDisciplinas *novo_elemento = (LDisciplinas*)malloc(sizeof(LDisciplinas));
    *novo_elemento->disciplina.nome_materia = nome_disciplina;
    *novo_elemento->disciplina.nome_professor = nome_professor;
    *novo_elemento->disciplina.codigo = codigo_input;
    *novo_elemento->disciplina.periodo = periodo_input;
    novo_elemento->prox = pInicio;
    *pInicio = novo_elemento;
}
*/

int main(){
    LAlunos *inicio = NULL; 
    //LDisciplinas *inicio_disp = NULL;
    while(1){
        int operacao, lista;
        char periodo[6];
        printf("\nQual operacao deseja fazer?\n[1]Consulta [2]Insercao [3]Remocao [4]Sair\n");
        scanf("%d", &operacao);
        if(operacao == 4){ // Adicionar o salvamento
            break;
        }
        printf("\nEm qual lista deseja fazer a operacao?\n [1]Alunos [2]Disciplinas\n");
        scanf("%d",&lista);

        if(lista == 1){// mexendo na lista de alunos
            char codigo[5];
            if(operacao == 1){// consulta de aluno
                printf("\nQual o codigo do aluno? ");
                scanf(" %[^\n]",codigo);
                buscar_aluno_LA(&inicio, codigo);// busca de aluno no sistema
                
                // consulta materia periodo
            }
            else if(operacao == 2){// insercao
                char nome[100], codigo[5], num_cpf[12];
                int tipo_insercao;
                printf("\nO que deseja fazer?\n[1]Inserir aluno [2]Inserir disciplina\n");
                scanf("%d",&tipo_insercao);

                if(tipo_insercao == 1){ //inserir aluno
                    while(1){
                        int opcao3;
                        printf("\nQual o nome? ");
                        scanf(" %[^\n]",nome);
                        printf("\nQual o codigo? ");
                        scanf(" %[^\n]",codigo);
                        printf("\nQual o cpf(numero inteiro)? ");
                        scanf(" %[^\n]",num_cpf);
                        inserir_aluno(&inicio, nome, codigo, num_cpf);
                        printf("\nDeseja inserir novo aluno? [1]Sim [2]Nao\n ");
                        scanf("%d",&opcao3);
                        if(opcao3 == 2) break;
                    }
                }
                else if(tipo_insercao == 2 ){ //inserir disciplina no aluno
                    char codigo_disciplina[6];
                    printf("\nQual o codigo? ");
                    gets(codigo);// trocar para scanf
                    printf("\nQual a disciplina? ");
                    gets(codigo_disciplina);
                    printf("\nEm qual periodo? ");
                    gets(periodo);
                    //inserir_disc_aluno(&inicio,codigo,codigo_disciplina,periodo);
                    
                }
                else{break;}
            }
            else{break;}
        }
        if(lista == 2){ //mexendo na lista de disciplinas
        char codigo[6];
           if(operacao == 1){
                printf("\nQual o codigo da disciplina? ");
                gets(codigo);
            }
            else if(operacao == 2){// insercao 
                char nome_prof[100], codigo[6];
                char nome_dis[50];
                int tipo_insercao;
                printf("\nO que deseja fazer?\n[1]Inserir disciplina [2]Inserir aluno\n");
                scanf("%d",&tipo_insercao);
                printf("\nEm qual periodo? ");
                gets(periodo);

                if(tipo_insercao == 1){ //inserir disciplina
                    printf("\nQual o nome da disciplina? ");
                    gets(nome_dis);
                    printf("\nQual o codigo? ");
                    gets(codigo);
                    printf("\nQual o nome do professor? ");
                    gets(nome_prof);
                    //inserir_disciplina(&inicio_disp,nome_dis, nome_prof, codigo, periodo);
                }
                else if(tipo_insercao == 2 ){ //inserir aluno
                    char codigo_aluno[5];
                    printf("\nQual o codigo do aluno? ");
                    gets(codigo_aluno);
                    printf("\nQual o codigo da disciplina? ");
                    gets(codigo);
                    //inserir_disc_aluno(&inicio,codigo,codigo_disciplina,periodo);
                }
                else{break;}
            }
        else{break;}
        }
    }
    return 0;
    
}