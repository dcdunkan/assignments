#include <stdio.h>
#include <string.h>

int main() {
  char str1[] = "hi";
  char str2[] = "hello";
  printf("%s", strcpy(str2, str1));
  return 0;
}
