#include <stdio.h>

union Temperature {
  float celcius;
  float fahrenheit;
};

float to_celcius(float fahrenheit) { return (fahrenheit - 32) * (5.0 / 9.0); }

float to_fahrenheit(float celcius) { return (celcius * (9.0 / 5.0)) + 32; }

int main() {
  union Temperature temp;
unit:
  printf("Enter F or C to convert from: ");
  char unit;
  scanf(" %c", &unit);

  printf("Enter the value: ");
  switch (unit) {
  case 'F':
  case 'f':
    scanf("%f", &temp.fahrenheit);
    temp.celcius = to_celcius(temp.fahrenheit);
    printf("celcius = %f\n", temp.celcius);
    break;
  case 'C':
  case 'c':
    scanf("%f", &temp.celcius);
    temp.fahrenheit = to_fahrenheit(temp.celcius);
    printf("fahrenheit = %f\n", temp.fahrenheit);
    break;
  case 'q':
    return 0;
  default:
    printf("invalid input. use q to quit.\n");
    goto unit;
  }
  return 0;
}
