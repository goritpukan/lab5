#include <string.h>
#include "../include/sort.h"

void sort(char **arr, const int numberOfStrings) {
  int i, j;
  for (i = 0; i < numberOfStrings - 1; i++) {
    for (j = i + 1; j < numberOfStrings; j++) {
      if (strcmp(arr[i], arr[j]) > 0) {
        char *tmp;
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

void sortReverse(char **arr, const int numberOfStrings) {
  int i, j;
  for (i = 0; i < numberOfStrings - 1; i++) {
    for (j = i + 1; j < numberOfStrings; j++) {
      if (strcmp(arr[i], arr[j]) < 0) {
        char *tmp;
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

