#ifndef STRINGS_H
#define STRINGS_H

void userInputInt(int *variable, char *message);

void fillStringManually(int numberOfStrings, int lengthOfString, char **strings);

void printStrings(int numberOfStrings, char *strings[]);

int validateString(char *string, const int lengthOfString);

int userChoice(char *message);

void generateStr(const int numberOfStrings, const int lengthOfString, char **arr);

char getRandomChar();
#endif
