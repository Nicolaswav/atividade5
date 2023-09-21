#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso correto: %s <arquivo_entrada>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = "arq_palavras_ordenado.txt";

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (!inputFile) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    if (!outputFile) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    int numWords;
    char **words = readWordsFromFile(inputFile, &numWords);
    fclose(inputFile);

    if (!words) {
        perror("Erro ao ler palavras do arquivo de entrada");
        return 1;
    }

    bubbleSort(words, numWords);

    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    fclose(outputFile);
    free(words);

    printf("Palavras ordenadas com sucesso em %s\n", outputFileName);

    return 0;
}
