#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./include/strings.h"
#include "./include/sort.h"

int main(void) {
  srand((unsigned int) time(NULL));
  do {
    int numberOfStrings = 0;
    int lengthOfString = 0;

    userInputInt(&numberOfStrings, "Enter a number of strings [2, 20]: ");
    userInputInt(&lengthOfString, "Enter a length of strings [2, 20]: ");

    lengthOfString++;

    char str[numberOfStrings][lengthOfString];
    char *addr[numberOfStrings];
    for (int i = 0; i < numberOfStrings; i++) {
      addr[i] = str[i];
    }
    userChoice("Choose method of filling strings: (0 - manually, 1 - generated): ")
      ? generateStr(numberOfStrings, lengthOfString, addr)
      : fillStringManually(numberOfStrings, lengthOfString, addr);

    printf("Your strings: \n");
    printStrings(numberOfStrings, addr);

    userChoice("Choose sorting method (0 - default, 1 - reverse): ")
      ? sortReverse(addr, numberOfStrings)
      : sort(addr, numberOfStrings);

    printf("Strings after sort\n");
    printStrings(numberOfStrings, addr);

    printf("\nType \'r\' to restart: ");
  } while (getchar() == 'r');
  return 0;
}
