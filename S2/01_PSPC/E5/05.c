#include <stdio.h>

void to_upper(char *str) {
  int i = 0;
  while (str[i] != 0) {
    if (str[i] >= 97 && str[i] <= 122) {
      str[i] -= 32;
    }
    i++;
  }
  // return str;
}

int main() {
  char *str;
  printf("Enter string: ");
  scanf("%[^\n]s", str);
  to_upper(str);
  printf("%s\n", str);
  return 0;
}
