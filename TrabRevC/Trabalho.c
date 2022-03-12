#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Disciplina
{
    char nome_professor[100];
    char nome_materia[40];
    char codigo[5];
    char periodo[7];
    int creditos;
} Odisciplina;

typedef struct lista_disciplinas
{
    Odisciplina disciplina;
    struct lista_disciplinas *prox;
} LDisciplinas;

typedef struct aluno
{
    char nome[100];
    char codigo[6];
    char cpf[12];
    LDisciplinas *inicio;
} Oaluno;

typedef struct lista_aluno
{
    Oaluno aluno;
    struct lista_aluno *prox;
} LAlunos;

void buscar_aluno_LA(LAlunos **inicio, char codigo_input[])
{
    int achou = 0;
    LAlunos *aux;
    aux = *inicio;
    while (aux)
    {
        if (strcmp(aux->aluno.codigo, codigo_input) == 0)
        {
            printf("\nNome:%s \ncodigo: %s \ncpf: %s ", aux->aluno.nome, aux->aluno.codigo, aux->aluno.cpf);
            achou = 1;
            break;
        }
        aux = aux->prox;
    }
    if (achou == 0)
        printf("\n nao foi achado o aluno\n");
}

void inserir_aluno(LAlunos **pInicio, char nome_input[], char codigo_input[], char cpf_input[])
{
    LAlunos *novo_elemento = (LAlunos *)malloc(sizeof(LAlunos)); // dar free()
    strcpy(novo_elemento->aluno.nome, nome_input);
    strcpy(novo_elemento->aluno.codigo, codigo_input);
    strcpy(novo_elemento->aluno.cpf, cpf_input);
    novo_elemento->prox = *pInicio;
    *pInicio = novo_elemento;
}

void inserir_disc_aluno(LDisciplinas **pInicioD, LAlunos **pInicio, char codigo[], char codigo_disciplina[], char periodo[])
{
    LDisciplinas *aux_disiplinas;
    aux_disiplinas = *pInicioD;
    while (aux_disiplinas)
    {
        if ((strcmp(aux_disiplinas->disciplina.periodo, periodo) == 0) && (strcmp(aux_disiplinas->disciplina.codigo, codigo_disciplina) == 0))
        {
            int achou = 0;
            LAlunos *aux;
            aux = *pInicio;
            while (aux)
            {
                if (strcmp(aux->aluno.codigo, codigo) == 0) 
                {
                    LDisciplinas *novo_elemento = (LDisciplinas *)malloc(sizeof(LDisciplinas));
                    strcpy(novo_elemento->disciplina.codigo, codigo_disciplina);
                    strcpy(novo_elemento->disciplina.periodo, periodo);
                    strcpy(novo_elemento->disciplina.nome_professor, aux_disiplinas->disciplina.nome_professor);
                    strcpy(novo_elemento->disciplina.nome_materia, aux_disiplinas->disciplina.nome_materia);
                    novo_elemento->disciplina.creditos = aux_disiplinas->disciplina.creditos;
                    // novo_elemento->prox = *pInicio;
                    // *pInicio = novo_elemento;
                    // Analogo a parada de cima

                    LDisciplinas *auxD = aux->aluno.inicio;
                    novo_elemento->prox = auxD;
                    aux->aluno.inicio = novo_elemento;
                    achou = 1;
                    // inserir_materia()
                    break;
                }
                aux = aux->prox;
            }
            if (achou == 0)
            {
                printf("\n Nao existe aluno com esse codigo\n");
            }
            break;
        }
        aux_disiplinas = aux_disiplinas->prox;
    }
    if(aux_disiplinas == NULL){
        printf("\nNao existe disciplina com esse codigo");
    }
}

void inserir_disc(LDisciplinas **pInicio, char nome_professor[], char nome_materia[], char codigo_disciplina[], char periodo[], int creditos)
{
    LDisciplinas *novo_elemento = (LDisciplinas *)malloc(sizeof(LDisciplinas)); // dar o free nessa
    strcpy(novo_elemento->disciplina.nome_professor, nome_professor);
    strcpy(novo_elemento->disciplina.nome_materia, nome_materia);
    strcpy(novo_elemento->disciplina.codigo, codigo_disciplina);
    strcpy(novo_elemento->disciplina.periodo, periodo);
    novo_elemento->disciplina.creditos = creditos;
    novo_elemento->prox = *pInicio;
    *pInicio = novo_elemento;
}

void buscar_disciplinas_aluno(LAlunos **pInicio, char codigo_aluno[], char periodo_input[])
{
    LAlunos *aux;
    aux = *pInicio;
    while (aux)
    {
        if (strcmp(aux->aluno.codigo, codigo_aluno) == 0)
        {
            LDisciplinas *aux_disiplinas;
            aux_disiplinas = aux->aluno.inicio;
            while (aux_disiplinas)
            {
                if (strcmp(aux_disiplinas->disciplina.periodo, periodo_input) == 0)
                {
                    printf("\nMateria: %s", aux_disiplinas->disciplina.nome_materia);
                    printf("\nProfessor: %s", aux_disiplinas->disciplina.nome_professor);
                    printf("\nCodigo da disciplina:%s", aux_disiplinas->disciplina.codigo);
                    printf("\nCreditos da disciplina:%d \n", aux_disiplinas->disciplina.creditos);
                }
                aux_disiplinas = aux_disiplinas->prox;
            }
        }
        aux = aux->prox;
    }
}
void buscar_disciplinas_LD(LDisciplinas **pInicio, char codigo_disciplina[], char periodo[])
{
    LDisciplinas *aux_disiplinas;
    aux_disiplinas = *pInicio;
    while (aux_disiplinas)
    {
        if (strcmp(aux_disiplinas->disciplina.periodo, periodo) == 0)
        {
            printf("\nMateria: %s", aux_disiplinas->disciplina.nome_materia);
            printf("\nProfessor: %s", aux_disiplinas->disciplina.nome_professor);
            printf("\nCodigo da disciplina:%s", aux_disiplinas->disciplina.codigo);
            printf("\nCreditos da disciplina:%d \n", aux_disiplinas->disciplina.creditos);
        }
        aux_disiplinas = aux_disiplinas->prox;
    }
}
/*
void inserir_materia(LDisciplinas **pInicio, char nome_disciplina[], char nome_professor[], char codigo_input[], char periodo_input[]){
    LDisciplinas *novo_elemento = (LDisciplinas*)malloc(sizeof(LDisciplinas));
    *novo_elemento->disciplina.nome_materia = nome_disciplina
    *novo_elemento->disciplina.nome_professor = nome_professor;
    *novo_elemento->disciplina.codigo = codigo_input;
    *novo_elemento->disciplina.periodo = periodo_input;
    novo_elemento->prox = pInicio;
    *pInicio = novo_elemento;
}
*/

int main()
{
    // declaracao de um caso inicial para testar insercao na lista de disciplinas de um aluno
    Odisciplina *calculo = (Odisciplina *)malloc(sizeof(Odisciplina)); // dar free()
    strcpy(calculo->nome_materia, "calculoII");
    strcpy(calculo->nome_professor, "rocha");
    strcpy(calculo->codigo, "5552");
    strcpy(calculo->periodo, "2020.2");

    LDisciplinas *inicio_disc = (LDisciplinas *)malloc(sizeof(LDisciplinas)); // dar free()
    inicio_disc->disciplina = *calculo;
    inicio_disc->prox = NULL;

    Oaluno *rafael = (Oaluno *)malloc(sizeof(Oaluno)); // dar free()
    strcpy(rafael->nome, "rafael");
    strcpy(rafael->codigo, "20057");
    strcpy(rafael->cpf, "09020008455");
    rafael->inicio = inicio_disc;

    LAlunos *inicio = NULL;
    LAlunos *novoElemento = (LAlunos *)malloc(sizeof(LAlunos)); // dar free()
    novoElemento->aluno = *rafael;
    novoElemento->prox = NULL;
    inicio = novoElemento;

    LDisciplinas *inicio_disc_todas = (LDisciplinas *)malloc(sizeof(LDisciplinas));
    inicio_disc_todas->disciplina = *calculo;
    inicio_disc_todas->prox = NULL;

    while (1)
    {
        int operacao, lista;
        char periodo[7];
        printf("\nQual operacao deseja fazer?\n[1]Consulta [2]Insercao [3]Remocao [4]Sair\n");
        scanf("%d", &operacao);
        if (operacao == 4)
        { // --------- Adicionar o salvamento
            break;
        }
        printf("\nEm qual lista deseja fazer a operacao?\n[1]Alunos [2]Disciplinas\n");
        scanf("%d", &lista);

        if (lista == 1)
        { // mexendo na lista de alunos
            char codigo[6];
            if (operacao == 1)
            { // consulta de aluno
                int opcao2;
                printf("\nQual o codigo do aluno? ");
                scanf(" %[^\n]", codigo);
                printf("\nDeseja consultar?\n[1]Dados do aluno [2]Disciplinas do aluno\n");
                scanf("%d", &opcao2);
                printf("Qual o periodo? "); // ----------- o periodo pode ser em outro canto
                scanf(" %[^\n]", periodo);
                if (opcao2 == 1)
                {
                    buscar_aluno_LA(&inicio, codigo); // busca de aluno no sistema
                }
                else if (opcao2 == 2)
                {
                    int opcao3;
                    buscar_disciplinas_aluno(&inicio, codigo, periodo); // buscar materia no sistema
                    printf("\nDeseja continuar?\n[1]Sim [2]Nao\n");
                    scanf("%d", &opcao3);
                    if (opcao3 == 2)
                        break;
                }
                else
                {
                    break;
                }
            }
            else if (operacao == 2)
            { // insercao
                char nome[100], codigo[6], num_cpf[12];
                int tipo_insercao;
                printf("\nO que deseja fazer?\n[1]Inserir aluno [2]Inserir disciplina\n");
                scanf("%d", &tipo_insercao);

                if (tipo_insercao == 1)
                { // inserir aluno
                    while (1)
                    {
                        int opcao3;
                        printf("\nQual o nome? ");
                        scanf(" %[^\n]", nome);
                        printf("\nQual o codigo? ");
                        scanf(" %[^\n]", codigo);
                        printf("\nQual o cpf(numero inteiro)? ");
                        scanf(" %[^\n]", num_cpf);
                        inserir_aluno(&inicio, nome, codigo, num_cpf);
                        printf("\nDeseja inserir novo aluno?\n[1]Sim [2]Nao\n ");
                        scanf("%d", &opcao3);
                        if (opcao3 == 2)
                            break;
                    }
                }
                else if (tipo_insercao == 2)
                { // inserir disciplina no aluno
                    char nome_professor[100];
                    char nome_materia[40];
                    char codigo_disciplina[5];
                    char periodo[7];
                    int creditos;
                    printf("\nQual o codigo da disciplina? ");
                    scanf(" %[^\n]", codigo_disciplina);
                    printf("\nQual o codigo do aluno? ");
                    scanf(" %[^\n]", codigo);
                    printf("\nQual o periodo que o aluno %s cursou a disciplina? ", codigo);
                    scanf(" %[^\n]", periodo);
                    inserir_disc_aluno(&inicio_disc_todas,&inicio, codigo, codigo_disciplina, periodo);
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (lista == 2)
        { // mexendo na lista de disciplinas
            char codigo[5];
            if (operacao == 1)
            {
                // consulta
                char periodo[7];
                printf("\nQual o codigo da disciplina? ");
                scanf(" %[^\n]", codigo);
                printf("\nQual o periodo da disciplina? ");
                scanf(" %[^\n]", periodo);
                buscar_disciplinas_LD(&inicio_disc_todas, codigo, periodo);
                //-------- falta busca de alunos em uma disciplina
            }
            else if (operacao == 2)
            { // insercao
                char nome_prof[100], codigo[5];
                char nome_dis[50];
                char periodo[7];
                int tipo_insercao;
                printf("\nO que deseja fazer?\n[1]Inserir disciplina [2]Inserir aluno\n");
                scanf("%d", &tipo_insercao);

                if (tipo_insercao == 1)
                { // inserir disciplina
                    char nome_professor[100];
                    char nome_materia[40];
                    char codigo_disciplina[5];
                    int creditos;
                    printf("\nQual o codigo da disciplina? ");
                    scanf(" %[^\n]", codigo_disciplina);
                    printf("\nQual o nome da disciplina? ");
                    scanf(" %[^\n]", nome_materia);
                    printf("\nQual o nome do professor? ");
                    scanf(" %[^\n]", nome_professor);
                    printf("\nQuantos creditos a disciplina pode dar? ");
                    scanf(" %d", &creditos);
                    printf("\nQual o periodo da disciplina? ", codigo);
                    scanf(" %[^\n]", periodo);
                    inserir_disc(&inicio_disc_todas, nome_professor, nome_materia, codigo_disciplina, periodo, creditos);
                }
                else if (tipo_insercao == 2)
                { // inserir disciplina em aluno
                    char nome_professor[100];
                    char nome_materia[40];
                    char codigo_disciplina[5];
                    int creditos;
                    printf("\nQual o codigo da disciplina? ");
                    scanf(" %[^\n]", codigo_disciplina);
                    printf("\nQual o codigo do aluno? ");
                    scanf(" %[^\n]", codigo);
                    printf("\nQual o periodo que o aluno %s cursou a disciplina? ", codigo);
                    scanf(" %[^\n]", periodo);
                    inserir_disc_aluno(&inicio_disc_todas,&inicio, codigo, codigo_disciplina, periodo);
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    // Frees de teste

    // Frees necessarios
    //  liberar memoria da lista de alunos
    LAlunos *auxAluno;
    auxAluno = inicio;
    while (auxAluno)
    {
        LAlunos *tmp = auxAluno->prox;

        // liberar memoria da lista de disciplina do aluno
        LDisciplinas *auxDisciplina;
        auxDisciplina = auxAluno->aluno.inicio;
        while (auxDisciplina)
        {
            LDisciplinas *tmp = auxDisciplina->prox;
            free(auxDisciplina);
            auxDisciplina = tmp;
        }
        free(auxAluno);
        auxAluno = tmp;
    }
    return 0;
}