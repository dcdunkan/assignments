#include <stdio.h>
#include <string.h>

struct Census {
  char city[32];
  unsigned long int population;
  float literacy_level;
};

int main() {
  struct Census census[5];

  for (int i = 0; i < 5; i++) {
    printf("Enter name of the city: ");
    fgets(census[i].city, 32, stdin);
    census[i].city[strlen(census[i].city) - 1] = 0;
    printf("Enter the population: ");
    scanf("%lu", &census[i].population);
    printf("Enter literacy level: ");
    scanf("%f", &census[i].literacy_level);
  }

  return 0;
}
