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
            achou++;
            break;
        }
        aux = aux->prox;
    }
    if (achou == 0)
        printf("\n Nao ha aluno com esse codigo\n");
}
void remove_Disci_Do_Alu(LAlunos **pInicio, LDisciplinas **pInicioDisc, char codigo_aluno[], char codigo_disciplina[], char periodo_input[], int tipo)
{ // Função para remover uma disciplina do aluno
    int countDisc = 0;
    int countAlu = 0;
    LAlunos *aux;
    aux = *pInicio;
    while (aux)
    {
        if (strcmp(aux->aluno.codigo, codigo_aluno) == 0)
        {
            countAlu++;
            LDisciplinas *aux_disciplinas, *anterior = NULL;
            aux_disciplinas = aux->aluno.inicio;
            while (aux_disciplinas)
            {
                if (strcmp(aux_disciplinas->disciplina.periodo, periodo_input) == 0 && strcmp(aux_disciplinas->disciplina.codigo, codigo_disciplina) == 0)
                {
                    countDisc++;
                    if (aux_disciplinas)//-----
                    {
                        // Alterando a lista de disciplinas
                        if (anterior)
                            anterior->prox = aux_disciplinas->prox;
                        else
                            aux->aluno.inicio= aux_disciplinas->prox;
                        free(aux_disciplinas);
                    }
                    break;
                }
                anterior = aux_disciplinas;
                aux_disciplinas = aux_disciplinas->prox;
            }

            if (countDisc == 0 && tipo == 1)
            {
                //printf("\n O aluno nao cursou essa disciplina , verifique o periodo\n");
            }
        }
        aux = aux->prox;
    }
    /*if (aux && countAlu == 0 && tipo == 1)
    {
        printf("\nNao existe aluno com esse codigo\n");
    }*/

}
void remove_LA(LAlunos **pInicio, char codigo[])
{ // Função para remover o aluno
    int count = 0;
    LAlunos *aux = *pInicio, *anterior = NULL;
    while (aux)
    {
        if (strcmp(aux->aluno.codigo, codigo) == 0)
        {
            count++;
            break;
        }
        anterior = aux;
        aux = aux->prox;
    }
    if (aux && count == 1)
    {
        if (anterior)
            anterior->prox = aux->prox;
        else
            *pInicio = aux->prox;

        // liberar memoria da lista de disciplina do aluno
        LDisciplinas *auxDisciplina;
        auxDisciplina = aux->aluno.inicio;
        while (auxDisciplina)
        {
            LDisciplinas *tmp = auxDisciplina->prox;
            free(auxDisciplina);
            auxDisciplina = tmp;
        }
        free(aux);
        printf("\nAluno removido com sucesso\n");
    }
    else
    {
        printf("\nNao ha aluno com esse codigo\n");
    }
}
void inserir_aluno(LAlunos **pInicio, char nome_input[], char codigo_input[], char cpf_input[])
{
    LAlunos *novo_elemento = (LAlunos *)malloc(sizeof(LAlunos)); // dar free()
    strcpy(novo_elemento->aluno.nome, nome_input);
    strcpy(novo_elemento->aluno.codigo, codigo_input);
    strcpy(novo_elemento->aluno.cpf, cpf_input);
    novo_elemento->aluno.inicio = NULL; //------
    novo_elemento->prox = *pInicio;
    *pInicio = novo_elemento;
}

void inserir_disc_aluno(LDisciplinas **pInicioD, LAlunos **pInicio, char codigo[], char codigo_disciplina[], char periodo[])
{
    LDisciplinas *aux_disciplinas;
    aux_disciplinas = *pInicioD;
    while (aux_disciplinas)
    {
        if ((strcmp(aux_disciplinas->disciplina.periodo, periodo) == 0) && (strcmp(aux_disciplinas->disciplina.codigo, codigo_disciplina) == 0))
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
                    strcpy(novo_elemento->disciplina.nome_professor, aux_disciplinas->disciplina.nome_professor);
                    strcpy(novo_elemento->disciplina.nome_materia, aux_disciplinas->disciplina.nome_materia);
                    novo_elemento->disciplina.creditos = aux_disciplinas->disciplina.creditos;
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
        aux_disciplinas = aux_disciplinas->prox;
    }
    if (aux_disciplinas == NULL)
    {
        printf("\nNao existe disciplina com esse codigo, insira ela na lista de disciplinas");
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
        {   int tem_disc = 0;
            LDisciplinas *aux_disciplinas;
            aux_disciplinas = aux->aluno.inicio;
            while (aux_disciplinas)
            {
                if (strcmp(aux_disciplinas->disciplina.periodo, periodo_input) == 0)
                {   tem_disc++;
                    printf("\nMateria: %s", aux_disciplinas->disciplina.nome_materia);
                    printf("\nProfessor: %s", aux_disciplinas->disciplina.nome_professor);
                    printf("\nCodigo da disciplina:%s", aux_disciplinas->disciplina.codigo);
                    printf("\nCreditos da disciplina:%d \n", aux_disciplinas->disciplina.creditos);
                }
                aux_disciplinas = aux_disciplinas->prox;
            }
            if(tem_disc == 0) printf("Aluno nao cursou materias nesse periodo\n");
            break;
        }
        aux = aux->prox;
    }
}
int buscar_disciplinas_LD(LDisciplinas **pInicio, char codigo_disciplina[], char periodo[])
{
    LDisciplinas *aux_disciplinas;
    aux_disciplinas = *pInicio;
    while (aux_disciplinas)
    {
        if (strcmp(aux_disciplinas->disciplina.periodo, periodo) == 0)
        {
            if (strcmp(aux_disciplinas->disciplina.codigo, codigo_disciplina) != 0)
                break;
            printf("\nMateria: %s", aux_disciplinas->disciplina.nome_materia);
            printf("\nProfessor: %s", aux_disciplinas->disciplina.nome_professor);
            printf("\nCodigo da disciplina:%s", aux_disciplinas->disciplina.codigo);
            printf("\nCreditos da disciplina:%d \n", aux_disciplinas->disciplina.creditos);
            return 1;
        }
        aux_disciplinas = aux_disciplinas->prox;
    }
    return 0;
}
void remove_disci_da_lista(LAlunos **pInicio, LDisciplinas **pInicioDisc, char codigo_disciplina[], char periodo_input[])
{ // Função para remover o aluno
    int count = 0;
    LDisciplinas *aux, *anterior = NULL;
    aux = *pInicioDisc;
    while (aux)
    {
        if ((strcmp(aux->disciplina.codigo, codigo_disciplina) == 0) && (strcmp(aux->disciplina.periodo, periodo_input) == 0))
        {   if(anterior == NULL) *pInicioDisc = aux->prox;
            else{
                anterior->prox = aux->prox;
            }
            printf("\nDisciplina removida com sucesso\n");
            break;
        }
        anterior = aux;
        aux = aux->prox;
    }
    if(aux == NULL) printf("\nNao ha disciplina com esse codigo\n");
    free(aux);
    // Função para remover a disciplina de todos os alunos
    LAlunos *auxAlu;
    auxAlu = *pInicio;

    while(auxAlu)
    {   LDisciplinas *auxDA;
        auxDA = auxAlu->aluno.inicio; //embaixo
        remove_Disci_Do_Alu(&auxAlu, &auxDA, auxAlu->aluno.codigo, codigo_disciplina, periodo_input, 2); // Melhorar para ordem de n, mudando o pInicio de cada aluno ( em tese ja passou por aqueles antes)
        auxAlu = auxAlu->prox;
    }
}
void recuperar_lista_disc()
{
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
    char nome_lista_disciplinas[] = "arquivos_de_textos/lista_disciplinas.txt";
    char lista_alunos[] = "arquivos_de_textos/lista_alunos.txt";
    FILE *arquivo_disciplinas;
    FILE *arquivo_alunos;
    arquivo_disciplinas = fopen(nome_lista_disciplinas, "r");
    if (arquivo_disciplinas == NULL)
        printf("não abriu lista de disciplinas");

    LAlunos *inicio = NULL;

    LDisciplinas *inicio_disc_todas = NULL;

    // buscar lista de disciplinas ja existente
    char nome_prof[100];

    while (fscanf(arquivo_disciplinas, " %[^\n]", nome_prof) != -1)
    {
        char nome_disc[40];
        char codigo[6];
        char periodo[8];
        int creditos;
        fscanf(arquivo_disciplinas, " %[^\n]", nome_disc);
        fscanf(arquivo_disciplinas, " %[^\n]", codigo);
        fscanf(arquivo_disciplinas, " %[^\n]", periodo);
        fscanf(arquivo_disciplinas, "%d", &creditos);

        //printf("nome:%s\ncodigo da materia:%s\nperiodo:%s\n", nome_prof, codigo, periodo);

        inserir_disc(&inicio_disc_todas,nome_prof,nome_disc,codigo,periodo,creditos);
    }
    fclose(arquivo_disciplinas);

    //lista de alunos
    arquivo_alunos =fopen(lista_alunos, "r");
    if(arquivo_alunos == NULL)
        printf("Erro ao abrir lista de alunos salva");
    char nome_aluno[100];

    while(fscanf(arquivo_alunos," %[^\n]", nome_aluno) != -1){
        char codigo[6];
        char cpf[12];
        char codigo_disciplina[5];
        char periodo_disciplina[7];
        fscanf(arquivo_alunos, " %[^\n]",codigo);
        fscanf(arquivo_alunos, " %[^\n]",cpf);

        inserir_aluno(&inicio,nome_aluno,codigo,cpf);

        while(1){
            fscanf(arquivo_alunos," %[^\n]", codigo_disciplina);
            if(strcmp(codigo_disciplina,"----") == 0) break;
            fscanf(arquivo_alunos," %[^\n]", periodo_disciplina);
            inserir_disc_aluno(&inicio_disc_todas, &inicio, codigo, codigo_disciplina, periodo_disciplina);
        }
    }
    fclose(arquivo_alunos);

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
                if (opcao2 == 1)
                {
                    buscar_aluno_LA(&inicio, codigo); // busca de aluno no sistema
                }
                else if (opcao2 == 2)
                {
                    int opcao3;
                    printf("Qual o periodo? ");
                    scanf(" %[^\n]", periodo);
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
                    inserir_disc_aluno(&inicio_disc_todas, &inicio, codigo, codigo_disciplina, periodo);
                }
                else
                {
                    break;
                }
            }
            else if (operacao == 3)
            { // remover aluno
                int opcao_aluno_remocao;
                printf("\nQual o codigo do aluno? ");
                scanf(" %[^\n]", codigo);
                printf("\nEm qual lista?\n[1]Alunos [2]Disciplina\n");
                scanf("%d", &opcao_aluno_remocao);
                if (opcao_aluno_remocao == 1)
                    remove_LA(&inicio, codigo);
                if (opcao_aluno_remocao == 2)
                {
                    char codigo_disciplina[5];
                    char periodo[7];
                    printf("Qual o codigo da disciplina? ");
                    scanf(" %[^\n]", codigo_disciplina);
                    printf("Em qual periodo foi cursada? ");
                    scanf(" %[^\n]", periodo);
                    remove_Disci_Do_Alu(&inicio, &inicio_disc_todas, codigo, codigo_disciplina, periodo, 1);
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
                if (buscar_disciplinas_LD(&inicio_disc_todas, codigo, periodo) == 0)
                    printf("\nNao existe essa materia nesse periodo\n");
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
                    inserir_disc_aluno(&inicio_disc_todas, &inicio, codigo, codigo_disciplina, periodo);
                }
                else
                {
                    break;
                }
            }
            else if (operacao == 3)
            { // remover disciplina
                char codigo_disciplina[5];
                char periodo[7];
                printf("\nQual o codigo da disciplina? ");
                scanf(" %[^\n]", codigo_disciplina);
                printf("\nQual o periodo que a disciplina %s foi cursada? ", codigo_disciplina);
                scanf(" %[^\n]", periodo);
                remove_disci_da_lista(&inicio, &inicio_disc_todas, codigo_disciplina, periodo);
            }
        }
    }
    // Frees de teste

    // Frees necessarios

    // liberar memoria da liata de disciplinas e passar salvamento em documento
    arquivo_disciplinas = fopen(nome_lista_disciplinas, "w");

    LDisciplinas *aux;
    aux = inicio_disc_todas;

    while (aux)
    {
        char texto[100];
        LDisciplinas *tmp = aux->prox;
        fprintf(arquivo_disciplinas,"%s\n",aux->disciplina.nome_professor);
        fprintf(arquivo_disciplinas,"%s\n",aux->disciplina.nome_materia);
        fprintf(arquivo_disciplinas,"%s\n",aux->disciplina.codigo);
        fprintf(arquivo_disciplinas,"%s\n",aux->disciplina.periodo);
        fprintf(arquivo_disciplinas, "%d\n", aux->disciplina.creditos);
        free(aux);
        aux = tmp;
    }

    fclose(arquivo_disciplinas);

    //  liberar memoria da lista de alunos
    arquivo_alunos = fopen(lista_alunos,"w");
    if(arquivo_alunos == NULL) printf("Falha na abertura do aquivo\n"); 
    LAlunos *auxAluno;
    auxAluno = inicio;
    while (auxAluno)
    {   char linha[100];
        LAlunos *tmp = auxAluno->prox;
        fprintf(arquivo_alunos,"%s\n",auxAluno->aluno.nome);
        fprintf(arquivo_alunos,"%s\n",auxAluno->aluno.codigo);
        fprintf(arquivo_alunos,"%s\n",auxAluno->aluno.cpf);
        // liberar memoria da lista de disciplina do aluno
        //Salvar os dados: nome,codigo,cpf ( tudo ) do aluno no arquivo texto
        //Definir um simbolo para fim de dados do aluno ou ->só contar 3 informações<-
        LDisciplinas *auxDisciplina;
        auxDisciplina = auxAluno->aluno.inicio;
        while (auxDisciplina)
        {
            LDisciplinas *tmp = auxDisciplina->prox;
            fprintf(arquivo_alunos,"%s\n",auxDisciplina->disciplina.codigo);
            fprintf(arquivo_alunos,"%s\n",auxDisciplina->disciplina.periodo);
            free(auxDisciplina);
            auxDisciplina = tmp;
        }
        fprintf(arquivo_alunos,"----\n");
        free(auxAluno);
        auxAluno = tmp;
    }
    fclose(arquivo_alunos);
    return 0;
}