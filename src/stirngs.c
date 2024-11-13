#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/strings.h"

void userInputInt(int *variable, char *message) {
  char isValid = 0;
  do {
    printf("\n%s", message);
    isValid = scanf("%d", &*variable);
    while (getchar() != '\n');
    if (!isValid) {
      printf("\nError, try again.");
      continue;
    }
    if (*variable < 2 || *variable > 20) {
      printf("\nEnter number in range [2, 20]");
      isValid = 0;
    }
  } while (!isValid);
}

void fillStringManually(int numberOfStrings, int lengthOfString, char **strings) {
  for (int i = 0; i < numberOfStrings; i++) {
    do {
      printf("\nEnter a string number %d -> ", i + 1);
      fgets(strings[i], lengthOfString + 1, stdin);
    } while (!validateString(strings[i], lengthOfString));
  }
}

void printStrings(int numberOfStrings, char *strings[]) {
  for (int i = 0; i < numberOfStrings; i++) {
    printf("String %d: %s\n", i + 1, strings[i]);
  }
}

int validateString(char *string, const int lengthOfString) {
  size_t len = strlen(string);
  if (len == 0 || *string == '\n') {
    printf("String is empty");
    return 0;
  }
  if (string[len - 1] != '\n') {
    printf("\nMax length of string is: %d", lengthOfString - 1);
    while (getchar() != '\n');
    return 0;
  }
  if (string[len - 1] == '\n') {
    string[len - 1] = '\0';
    len--;
  }
  for (int i = 0; i < len; i++) {
    if (!isalpha(string[i])) {
      printf("\nString must contain only letters");
      return 0;
    }
  }
  return 1;
}

int userChoice(char *message) {
  int choice = 0;
  do {
    printf("%s", message);
    choice = getchar();
    while (getchar() != '\n');
    if(choice != '0' && choice != '1') {
      printf("Enter 0 or 1");
    }
  }while (choice != '0' && choice != '1');
  return choice == '0' ? 0 : 1;
}

void generateStr(const int numberOfStrings, const int lengthOfString, char **arr) {
  for (int i = 0; i < numberOfStrings; i++) {
    for (int j = 0; j < lengthOfString - 1; j++) {
      arr[i][j] = getRandomChar();
    }
    arr[i][lengthOfString - 1] = '\0';
  }
}
char getRandomChar() {
  char random;
  do {
    random = 65 + rand() % (122 - 65 + 1);  // Generate a random value between 65 and 122
  } while ((random < 65 || (random > 90 && random < 97) || random > 122));
  return random;
}

