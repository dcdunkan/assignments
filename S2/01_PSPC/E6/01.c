#include <stdio.h>

struct Student {
  char name[32];
  int roll;
  float marks[3];
};

struct Student create_student() {
  struct Student student;

  printf("Enter name (32 char limit): ");
  fgets(student.name, 32, stdin);

  printf("Enter roll number: ");
  scanf("%d", &student.roll);

  for (int i = 0; i < 3; i++) {
    printf("Enter the marks of subject %d: ", i + 1);
    scanf("%f", &student.marks[i]);
  }

  return student;
}

float calculateTotal(struct Student student) {
  float sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += student.marks[i];
  }
  return sum;
}

void display_student(struct Student student) {
  printf("Name: %s", student.name);
  printf("Roll number: %d\n", student.roll);
  printf("Marks: %f\n", calculateTotal(student));
  for (int i = 0; i < 3; i++) {
    printf("\tSubject %d: %f\n", i + 1, student.marks[i]);
  }
}

int main() {
  struct Student student = create_student();
  display_student(student);
  printf("Total marks: %f\n", calculateTotal(student));
  return 0;
}
