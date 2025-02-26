#include <stdio.h> // Biblioeteca da linguagem capaz de ler e imprimir.

//Dados selecionados
typedef struct {

    int id;                       // ID de identificação
    char nome[100];               // Nome do filme
    int ano_de_lancamento;        // Ano de lançamento
    int duracao_min;              // Duração (em minutos)
    float nota_do_usuario;        // Nota de avaliação do usuário em relação o filme

} Filme;

int contador_filmes = 0; // Conta quantos filmes foram registrados, varável importante para a opção 2!
Filme assistidos [200];  // Array para guardar as Structs inteiras...

//'[1] - Adicionar NOVO filme assistido\n'
void opcao_1(){
    
    printf("\nUtilize um número para identificar este filme: ");
    scanf("%d", &assistidos[contador_filmes].id);

    printf("Qual o nome do filme?\n");
    scanf(" %[^\n]", assistidos[contador_filmes].nome);

    printf("Em que ano foi lançado?\n");
    scanf("%d", &assistidos[contador_filmes].ano_de_lancamento);

    printf("Qual a duração, em minutos, do filme?\n");
    scanf("%d", &assistidos[contador_filmes].duracao_min);

    printf("E que nota você dá para esse filme? (Ex: 7.5):\n");
    scanf("%f", &assistidos[contador_filmes].nota_do_usuario);

    printf("\nTudo ok! Tudo registrado! :)\n");

    contador_filmes++; // Incrementando de acordo com quantos filmes registrados.

}

//'[2] - Filmes já assistidos'
void opcao_2(){
    // Caso não tenha nenhum filme registrado
    if(contador_filmes == 0){
        printf("\nOpa! Você não registrou nenhum filme :(");
    }
    // Caso contrário...
    else{
        printf("\nAqui estão TODOS os seus filmes já assistidos ;) \n");

        for(int i = 0; i < contador_filmes; i++){

            printf("\nID do filme: %d\n", assistidos[i].id);
            printf("Nome do filme: %s\n", assistidos[i].nome);
            printf("Ano de lançamento: %d\n", assistidos[i].ano_de_lancamento);
            printf("Duração: %d minutos. \n", assistidos[i].duracao_min);
            printf("Sua nota para %s foi %.1f\n", assistidos[i].nome, assistidos[i].nota_do_usuario);
            printf("---"); // Divisor de filmes
        }
    }

}
// '[3] - Salvar lista de já assistidos em arquivo'
void opcao_3(){

    FILE *dados = fopen("FilmesEmArquivo.txt", "w");

    fprintf(dados, "Lista dos filmes já assistidos (e salvos em arquivo)"); // cabeçalho

    for(int i = 0; i < contador_filmes; i++){

        fprintf(dados, "\nID do filme: %d\n", assistidos[i].id);
        fprintf(dados, "Nome do filme: %s\n", assistidos[i].nome);
        fprintf(dados, "Ano de lançamento: %d\n", assistidos[i].ano_de_lancamento);
        fprintf(dados, "Duração: %d minutos. \n", assistidos[i].duracao_min);
        fprintf(dados, "Sua nota para %s foi %.1f\n", assistidos[i].nome, assistidos[i].nota_do_usuario);
        fprintf(dados, "---");
    }

    fclose(dados); // Encerrar
}
void opcao_4() {

    // Verificar se tem de fato algum filme registrado.
    if (contador_filmes == 0){
        printf("\n Sem filmes assistidos para remover :(\n"); 
        return; // Encerra a função
    }

    // Escolher o filme a ser removido;
    int id_para_remover;
    printf("\nQual o ID do filme que você quer remover? ");
    scanf("%d", &id_para_remover);

    // Procurar o filme na lista
    int encontrar = 0;
    // Percorre a lista

    for(int i = 0; i < contador_filmes; i++){
        if(assistidos[i].id == id_para_remover)
        {
            encontrar = 1;

            for (int j = i; j < contador_filmes - 1; j++){

                assistidos[j] = assistidos[j + 1];

            }

            contador_filmes--; // Decrementando

            printf("\nFilme removido! Confira a lista atualizada: ;)\n");
            opcao_2();
            break;
        }
    }
    if (!encontrar) {
        printf("\n⚠️ Nenhum filme encontrado com o ID informado.\n");
    }
}

// Menu principal.
void Menu (){
    Filme novoFilme;

    int opcao;

    do{
        printf("\nMenu:\n");
        printf("[1] - Adicionar NOVO filme assistido\n");
        printf("[2] - Filmes já assistidos\n");
        printf("[3] - Salvar lista de já assistidos em arquivo\n");
        printf("[4] - Remover um filme da lista de já assistidos\n");
        printf("[0] - Sair\n");
        //Selecionando a opção...
        printf("\nSelecione uma opção: ");
        scanf("%d", &opcao);
        //Execução das opções.
        switch (opcao){
            case 1:
                opcao_1();
                break;
            case 2:
                opcao_2();
                break;
            case 3:
                opcao_3();
                break;
            case 4:
                opcao_4();
                break;
            case 0:
                printf("Até mais ;)");
                break;
            default:
                printf("Opa! Essa opção não existe. Vamos tentar novamente?");
                break;
        }
    } while(opcao != 0); // Retornando ao menu.
}

int main (){

    // Introdução.
    printf("Olá, tudo bem, cinéfilos? Sejam muito bem-vindos! ");
    printf("Esta é uma plataforma onde você consegue registrar algumas informações e a sua avaliação dos filmes que você tem assistido!\n");
    printf("\nVamos começar? Irei te direcionar ao Menu! :)\n");
    Menu(); // Função do Menu

    return 0;
}