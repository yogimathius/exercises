#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Example 00:

Input: "FOR PONIES"
Output: "PONIES"
Example 01:

Input: "this        ...       is sparta"
Output: "sparta"
Example 02:

Input "  lorem,ipsum  "
Output: "ipsum"
Example 03:

Input ""
Output: ""
*/

typedef struct word {
  char* word;
  struct word* next;
} word;

void addToLinkedList(word* list, char str[]) {
  word* newNode = (word*)malloc(sizeof(word));
  newNode->word = (char*)malloc(strlen(str) + 1);
  strcpy(newNode->word, str);
  newNode->next = NULL;

  while (list->next != NULL) {
    list = list->next;
  }
  list->next = newNode;
}


char* last_word(char* param_1) {

  if (strlen(param_1) == 0) {
    return param_1;
  }
  unsigned long i, j;
  word* head;
  head = (struct word*)malloc(sizeof(struct word));
  if (head == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
  }

  head->next = NULL;
  head->word = (char*)malloc(strlen(param_1) + 1);
  word* temp = head;
  j = 0;

  char* word = (char*)malloc(strlen(param_1) + 1);

  for (i = 0; i <= strlen(param_1); i++) {
    if (param_1[i] == ' ' || param_1[i] == '\0') {
      if (j > 0) {
        word[j] = '\0';  // Append null terminator
        addToLinkedList(temp, word);
        temp = temp->next;
        j = 0;
      }
    }
    else {
      word[j] = param_1[i];
      j++;
    }
  }

  printf("head->word: %s\n", temp->word);
  return temp->word;
}

int main(void) {
  printf("Result 1:%s\n", last_word("FOR PONIES"));
  printf("Result 2:%s\n", last_word("this        ...       is sparta"));
  printf("Result 3:%s\n", last_word("  lorem,ipsum  "));
  printf("Result 4:%s\n", last_word(""));

  return 0;
}