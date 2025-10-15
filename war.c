#include <stdio.h>
#include <string.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função auxiliar para limpar o buffer de entrada.
// Essencial para usar depois de um scanf, antes de ler uma string com fgets.
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    // --- MANUTENIBILIDADE: Declaração do Vetor de Structs ---
    // Criamos um vetor (array) chamado 'mapa' que pode armazenar
    // os dados de até 5 territórios. Cada posição do vetor é uma "ficha"
    // completa do tipo Territorio.
    struct Territorio mapa[5];
    int i; // Variável para controlar os laços (loops)

    // --- USABILIDADE E ENTRADA DE DADOS ---
    // Este laço 'for' vai repetir 5 vezes, uma para cada território.
    // A cada repetição, ele pedirá ao usuário para digitar as informações
    // e as armazenará na posição correta do vetor 'mapa'.
    printf("===== CADASTRO DE TERRITORIOS DO MAPA =====\n");
    for (i = 0; i < 5; i++) {
        printf("\n--- Territorio %d ---\n", i + 1);

        printf("Digite o nome: ");
        // Usamos fgets para ler o nome, pois ele aceita espaços (ex: "America do Norte")
        fgets(mapa[i].nome, 30, stdin);
        // Remove a quebra de linha ('\n') que o fgets captura automaticamente
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = 0;

        printf("Digite a cor do exercito: ");
        fgets(mapa[i].cor, 10, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = 0;

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);

        // Limpamos o buffer de entrada para que o '\n' deixado pelo scanf
        // não atrapalhe a próxima leitura do nome do território no loop.
        limparBufferEntrada();
    }

    // --- DESEMPENHO E EXIBIÇÃO DOS DADOS ---
    // Após o cadastro, este segundo laço 'for' percorre o vetor
    // e exibe os dados de cada território que foi cadastrado,
    // de forma organizada e clara.
    printf("\n\n===== RELATORIO DE TERRITORIOS CADASTRADOS =====\n");
    for (i = 0; i < 5; i++) {
        printf("\n---------------------------\n");
        printf(" Territorio: %s\n", mapa[i].nome);
        printf(" Cor do Exercito: %s\n", mapa[i].cor);
        printf(" Quantidade de Tropas: %d\n", mapa[i].tropas);
        printf("---------------------------\n");
    }

    return 0;
}