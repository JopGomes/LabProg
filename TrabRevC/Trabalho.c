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

int buscar_aluno_LA(LAlunos **inicio, char codigo_input[], char printar[])
{
    int achou = 0;
    LAlunos *aux;
    aux = *inicio;
    while (aux)
    {
        if ((strcmp(aux->aluno.codigo, codigo_input) == 0) && (strcmp(printar, "printar") == 0))
        {
            printf("\nNome:%s \ncodigo: %s \ncpf: %s \n ", aux->aluno.nome, aux->aluno.codigo, aux->aluno.cpf);
            achou++;
            return 1;
            break;
        }
        aux = aux->prox;
    }
    if (achou == 0 && (strcmp(printar, "printar") == 0))
        printf("\n Nao ha aluno com esse codigo\n");
    return 0;
}
int buscar_disciplinas_periodo(LDisciplinas **pInicio, char codigo_disciplina[], char periodo[], char printa_dados[]) // consertar n acha todas disciplinas
{
    int acabar = 0, count = 0;
    LDisciplinas *aux_disciplinas;
    aux_disciplinas = *pInicio;

    while (aux_disciplinas)
    {
        if (strcmp(aux_disciplinas->disciplina.periodo, periodo) == 0)
        {
            count = 1;
            if (strcmp(aux_disciplinas->disciplina.codigo, codigo_disciplina) == 0)
            {
                acabar = 1;
            }
            if ((strcmp(printa_dados, "printar") == 0) && (acabar || strcmp("XXXX", codigo_disciplina) == 0))
            {
                printf("\nMateria: %s", aux_disciplinas->disciplina.nome_materia);
                printf("\nCodigo da disciplina:%s", aux_disciplinas->disciplina.codigo);

                if (acabar)
                {
                    printf("\nProfessor: %s", aux_disciplinas->disciplina.nome_professor);
                    printf("\nCreditos da disciplina:%d \n", aux_disciplinas->disciplina.creditos);
                }
            }
            printf("\n");
            if (acabar)
            {
                return 1;
                break;
            }
        }
        aux_disciplinas = aux_disciplinas->prox;
    }
    if ((strcmp(printa_dados, "printar") == 0) && count == 0 && acabar == 1)
    {
        printf("\nDisciplina nao inserida nesse periodo, faca a insercao dela antes");
    }
    if ((strcmp(printa_dados, "printar") == 0) && acabar == 0 && count == 0)
    {
        printf("\nDisciplina nao inserida, faca a insercao dela antes");
    }
    return 0;
}
void buscar_disciplinas_aluno(LAlunos **pInicio, char codigo_aluno[], char periodo_input[])
{
    LAlunos *aux;
    int count = 1;
    aux = *pInicio;
    while (aux)
    {
        if (strcmp(aux->aluno.codigo, codigo_aluno) == 0)
        {
            count = 0;
            LDisciplinas *aux_disciplinas;
            aux_disciplinas = aux->aluno.inicio;
            buscar_disciplinas_periodo(&aux_disciplinas, "XXXX", periodo_input, "printar");
            break;
        }
        aux = aux->prox;
    }
    if (count)
    {
        printf("\nAluno %s nao esta cadastrado com essa disciplina, cadastre-o antes\n", codigo_aluno);
    }
}
int buscar_alunos_disciplina(LAlunos **pInicio, char codigo_disc[], char periodo[],char printar[])
{
    LAlunos *auxAlu;
    auxAlu = *pInicio;

    while (auxAlu)
    {
        int cursou;
        LDisciplinas *auxDA;
        auxDA = auxAlu->aluno.inicio;                                                    // embaixo
        cursou = buscar_disciplinas_periodo(&auxDA, codigo_disc, periodo, "nao printa"); // Melhorar para ordem de n, mudando o pInicio de cada aluno ( em tese ja passou por aqueles antes)
        if (cursou && strcmp(printar,"printar")==0)
            printf("\n%s", auxAlu->aluno.nome);
            return 1;
        if(strcmp(printar,"printar")==0){
            printf("\n");
        }
        auxAlu = auxAlu->prox;
    }
 
    return 0;
}
void inserir_aluno(LAlunos **pInicio, char nome_input[], char codigo_input[], char cpf_input[], char printar[])
{
    if (buscar_aluno_LA(pInicio, nome_input, "nao printar") == 0)
    {
        LAlunos *novo_elemento = (LAlunos *)malloc(sizeof(LAlunos)); // dar free()
        strcpy(novo_elemento->aluno.nome, nome_input);
        strcpy(novo_elemento->aluno.codigo, codigo_input);
        strcpy(novo_elemento->aluno.cpf, cpf_input);
        novo_elemento->aluno.inicio = NULL; //------
        novo_elemento->prox = *pInicio;
        *pInicio = novo_elemento;
    }
    else if ((strcmp(printar, "printar") == 0))
    {
        printf("Esse aluno ja existe no banco de dados");
    }
}
void inserir_disc_aluno(LDisciplinas **pInicioD, LAlunos **pInicio, char codigo[], char codigo_disciplina[], char periodo[], char printar[])
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
                    if (buscar_alunos_disciplina(&aux,codigo_disciplina,periodo,"nao printar")==0)
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
                }
                aux = aux->prox;
            }
            if (achou == 0 && (strcmp(printar, "printar") == 0))
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
    if (buscar_disciplinas_periodo(pInicio, codigo_disciplina, periodo, "nao printa") != 1)
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
    else
    {
        printf("Essa disciplina ja existe nesse periodo,remova para alterar\n");
    }
}
int remove_disciplina(LDisciplinas **pInicio, char codigo_disc[], char periodo[], char printar[])
{
    LDisciplinas *aux, *ant = NULL;
    int count = 0;
    aux = *pInicio;
    while (aux)
    {
        if (strcmp(aux->disciplina.codigo, codigo_disc) == 0 && strcmp(aux->disciplina.periodo, periodo) == 0)
        {
            count = 1;
            if (ant)
            {
                ant->prox = aux->prox;
            }
            else
            {
                *pInicio = aux->prox;
            }
            free(aux);
            return 1;
            break;
        }
        ant = aux;
        aux = aux->prox;
    }
    if (count == 0 && (strcmp(printar, "printar") == 0))
    {
        printf("\nEssa disciplina ja nao se encontrava no banco de dados\n");
    }
    return 0;
}
void remove_Disci_Do_Alu(LAlunos **pInicio, char codigo_aluno[], char codigo_disciplina[], char periodo_input[], int tipo)
{ // Função para remover uma disciplina do aluno
    int foi_removido;
    LAlunos *aux;
    aux = *pInicio;
    while (aux)
    {
        if (strcmp(aux->aluno.codigo, codigo_aluno) == 0 || strcmp("XXXXX", codigo_aluno) == 0)
        {
            foi_removido = remove_disciplina(&aux->aluno.inicio, codigo_disciplina, periodo_input, "nao_printar");
            if ((strcmp(aux->aluno.codigo, codigo_aluno) == 0) && (strcmp("XXXXX", codigo_aluno) == 1))
                break;
        }
        aux = aux->prox;
    }
    if (tipo && foi_removido)
        printf("Materia removida com sucesso\n");

    if (tipo && !foi_removido)
        printf("\nO Aluno nao cursou essa materia\n");
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

        // printf("nome:%s\ncodigo da materia:%s\nperiodo:%s\n", nome_prof, codigo, periodo);

        inserir_disc(&inicio_disc_todas, nome_prof, nome_disc, codigo, periodo, creditos);
    }
    fclose(arquivo_disciplinas);

    // lista de alunos
    arquivo_alunos = fopen(lista_alunos, "r");
    if (arquivo_alunos == NULL)
        printf("Erro ao abrir lista de alunos salva");
    char nome_aluno[100];

    while (fscanf(arquivo_alunos, " %[^\n]", nome_aluno) != -1)
    {
        char codigo[6];
        char cpf[12];
        char codigo_disciplina[5];
        char periodo_disciplina[7];
        fscanf(arquivo_alunos, " %[^\n]", codigo);
        fscanf(arquivo_alunos, " %[^\n]", cpf);

        inserir_aluno(&inicio, nome_aluno, codigo, cpf, "nao printar");

        while (1)
        {
            fscanf(arquivo_alunos, " %[^\n]", codigo_disciplina);
            if (strcmp(codigo_disciplina, "----") == 0)
                break;
            fscanf(arquivo_alunos, " %[^\n]", periodo_disciplina);
            inserir_disc_aluno(&inicio_disc_todas, &inicio, codigo, codigo_disciplina, periodo_disciplina, "nao printar");
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
        {
            break;
        }
        if (operacao == 1 || operacao == 2 || operacao == 3)
        {
            printf("\nEm qual lista deseja fazer a operacao?\n[1]Alunos [2]Disciplinas\n");
            scanf("%d", &lista);
        }
        else
        {
            printf("\nDigite uma opcao valida \n");
        }

        if (lista == 1)
        { // mexendo na lista de alunos
            char codigo[6];
            if (operacao == 1)
            { // consulta de aluno
                int opcao2;
                printf("\nQual o codigo do aluno? ");
                scanf(" %[^\n]", codigo);
                printf("\nO que deseja consultar?\n[1]Dados do aluno [2]Disciplinas do aluno\n");
                scanf("%d", &opcao2);
                if (opcao2 == 1)
                {
                    buscar_aluno_LA(&inicio, codigo, "printar"); // busca de aluno no sistema
                }
                else if (opcao2 == 2)
                {
                    while (1)
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
                        printf("\nQual o codigo de 5 digitos? ");
                        scanf(" %[^\n]", codigo);
                        printf("\nQual o cpf(numero inteiro)? ");
                        scanf(" %[^\n]", num_cpf);
                        inserir_aluno(&inicio, nome, codigo, num_cpf, "printar");
                        printf("\nDeseja inserir novo aluno?\n[1]Sim [2]Nao\n ");
                        scanf("%d", &opcao3);
                        if (opcao3 == 2)
                            break;
                    }
                }
                else if (tipo_insercao == 2)
                { // inserir disciplina no aluno
                    char codigo_disciplina[5];
                    char periodo[7];
                    printf("\nQual o codigo da disciplina? ");
                    scanf(" %[^\n]", codigo_disciplina);
                    printf("\nQual o codigo do aluno? ");
                    scanf(" %[^\n]", codigo);
                    printf("\nQual o periodo que o aluno %s cursou a disciplina? ", codigo);
                    scanf(" %[^\n]", periodo);
                    inserir_disc_aluno(&inicio_disc_todas, &inicio, codigo, codigo_disciplina, periodo, "nao printar");
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
                while (1)
                {
                    printf("\nEm qual lista?\n[1]Alunos [2]Disciplina\n");
                    scanf("%d", &opcao_aluno_remocao);
                    if (opcao_aluno_remocao == 1)
                    {
                        remove_LA(&inicio, codigo);
                        break;
                    }
                    else if (opcao_aluno_remocao == 2)
                    {
                        char codigo_disciplina[5];
                        char periodo[7];
                        printf("Qual o codigo da disciplina? ");
                        scanf(" %[^\n]", codigo_disciplina);
                        printf("Em qual periodo foi cursada? ");
                        scanf(" %[^\n]", periodo);
                        remove_Disci_Do_Alu(&inicio, codigo, codigo_disciplina, periodo, 1);
                        break;
                    }
                    else
                    {
                        printf("\nDigite uma opcao valida\n");
                    }
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
                int opcao2;
                printf("\nQual o periodo da disciplina? ");
                scanf(" %[^\n]", periodo);
                printf("\nLista de disciplinas:");
                buscar_disciplinas_periodo(&inicio_disc_todas, "XXXX", periodo, "printar");
                printf("\nQual o codigo da disciplina? ");
                scanf(" %[^\n]", codigo);
                while (1)
                {
                    if (buscar_disciplinas_periodo(&inicio_disc_todas, codigo, periodo, "nao printar") == 0)
                        printf("\nNao existe disciplina com esse codigo nesse periodo, insira ela na lista de disciplinas\n");
                    else
                    {
                        printf("\nQual verificacao deseja fazer?\n[1]Dados da disciplina %s [2]Alunos matriculados nela no periodo %s\n", codigo, periodo);
                        scanf("%d", &opcao2);

                        if (opcao2 == 1)
                        {
                            buscar_disciplinas_periodo(&inicio_disc_todas, codigo, periodo, "printar");
                            break;
                        }
                        else if (opcao2 == 2)
                        {
                            printf("Lista de alunos:");
                            buscar_alunos_disciplina(&inicio, codigo, periodo,"printar");
                            break;
                        }
                        else
                        {
                            printf("\nDigite uma opcao valida\n");
                        }
                    }
                }
            }
            else if (operacao == 2)
            { // insercao
                char nome_prof[100], codigo[5];
                char nome_dis[50];
                char periodo[7];
                int tipo_insercao;
                while (1)
                {
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
                        break;
                    }
                    else if (tipo_insercao == 2)
                    { // inserir disciplina em aluno
                        char codigo_disciplina[5];
                        printf("\nQual o codigo da disciplina? ");
                        scanf(" %[^\n]", codigo_disciplina);
                        printf("\nQual o codigo do aluno? ");
                        scanf(" %[^\n]", codigo);
                        printf("\nQual o periodo que o aluno %s cursou a disciplina? ", codigo);
                        scanf(" %[^\n]", periodo);
                        inserir_disc_aluno(&inicio_disc_todas, &inicio, codigo, codigo_disciplina, periodo, "printar");
                        break;
                    }
                    else
                    {
                        printf("\nDigite uma opcao valida\n");
                    }
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
                remove_disciplina(&inicio_disc_todas, codigo_disciplina, periodo, "printar");
                remove_Disci_Do_Alu(&inicio, "XXXXX", codigo_disciplina, periodo, 0);
            }
        }
        if (lista != 2 && lista != 1 && (operacao==1 || operacao==2 || operacao ==3))
        {
            printf("\nDigite uma lista valida \n");
        }
    }

    // Frees necessarios

    // liberar memoria da lista de disciplinas e passar salvamento em documento
    arquivo_disciplinas = fopen(nome_lista_disciplinas, "w");

    LDisciplinas *aux;
    aux = inicio_disc_todas;

    while (aux)
    {
        LDisciplinas *tmp = aux->prox;
        fprintf(arquivo_disciplinas, "%s\n", aux->disciplina.nome_professor);
        fprintf(arquivo_disciplinas, "%s\n", aux->disciplina.nome_materia);
        fprintf(arquivo_disciplinas, "%s\n", aux->disciplina.codigo);
        fprintf(arquivo_disciplinas, "%s\n", aux->disciplina.periodo);
        fprintf(arquivo_disciplinas, "%d\n", aux->disciplina.creditos);
        free(aux);
        aux = tmp;
    }

    fclose(arquivo_disciplinas);

    //  liberar memoria da lista de alunos
    arquivo_alunos = fopen(lista_alunos, "w");
    if (arquivo_alunos == NULL)
        printf("Falha na abertura do aquivo\n");
    LAlunos *auxAluno;
    auxAluno = inicio;
    while (auxAluno)
    {
        LAlunos *tmp = auxAluno->prox;
        fprintf(arquivo_alunos, "%s\n", auxAluno->aluno.nome);
        fprintf(arquivo_alunos, "%s\n", auxAluno->aluno.codigo);
        fprintf(arquivo_alunos, "%s\n", auxAluno->aluno.cpf);

        // liberar memoria da lista de disciplinas de um aluno
        LDisciplinas *auxDisciplina;
        auxDisciplina = auxAluno->aluno.inicio;
        while (auxDisciplina)
        {
            LDisciplinas *tmp = auxDisciplina->prox;
            fprintf(arquivo_alunos, "%s\n", auxDisciplina->disciplina.codigo);
            fprintf(arquivo_alunos, "%s\n", auxDisciplina->disciplina.periodo);
            free(auxDisciplina);
            auxDisciplina = tmp;
        }
        // defindo o final da lista de disciplinas de um aluno
        fprintf(arquivo_alunos, "----\n");
        free(auxAluno);
        auxAluno = tmp;
    }
    fclose(arquivo_alunos);

    return 0;
}