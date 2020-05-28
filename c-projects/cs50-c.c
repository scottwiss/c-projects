#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_letters(void);

int main(void) {
    get_letters;
}

int get_letters(void) {
  string text = get_string("Text: \n"); // need to look into how to do this
  int textlen = strlen(text);
  int letter_count;
  int i = 0;
  for (i = 0; i <= textlen; i++) {
    if (isalpha(text[i]) {
      letter_count += 1;
    }
  }
  printf("%i\n",letter_count);
}
