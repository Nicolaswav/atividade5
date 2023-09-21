#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

char **readWordsFromFile(FILE *file, int *numWords) {
    char **words = NULL;
    char buffer[100];
    int capacity = 10;
    *numWords = 0;

    words = (char **)malloc(capacity * sizeof(char *));

    if (!words) {
        perror("Erro ao alocar memória");
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove o caractere de nova linha

        if (*numWords >= capacity) {
            capacity *= 2;
            words = (char **)realloc(words, capacity * sizeof(char *));
            if (!words) {
                perror("Erro ao alocar memória");
                return NULL;
            }
        }

        words[*numWords] = strdup(buffer);

        if (!words[*numWords]) {
            perror("Erro ao alocar memória");
            return NULL;
        }

        (*numWords)++;
    }

    return words;
}

void bubbleSort(char **array, int numElements) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < numElements - 1; i++) {
            if (strcmp(array[i], array[i + 1]) > 0) {
                char *temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}
