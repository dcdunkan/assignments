#include <stdio.h>

void copyString(char *source, char *dest) {
  while ((*dest++ = *source++))
    ;
}

int main() {
  char *source, *dest;
  printf("Enter source string: ");
  scanf("%[^\n]s ", source);
  printf("%s\n", source);
  copyString(source, dest);
  printf("%s\n", dest);
  return 0;
}
