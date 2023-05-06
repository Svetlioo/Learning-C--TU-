#include <stdio.h>
#include <string.h>

struct Student {
  char name[50];
  int grade;
};

struct Class {
  struct Student students[100];
  int studenti;
};

int main() {
  struct Class class1;
  struct Class class2;
  float sreden_uspeh = 0;
  
  printf("Enter the number of students in the class 1: ");
  scanf("%d", &class1.studenti);
  for(int i = 0; i < class1.studenti; i++) {
    printf("Ime na student %d: ", i+1);
    scanf("%s", class1.students[i].name);
    printf("Ocenka na student %d: ", i+1);
    scanf("%d", &class1.students[i].grade);
    sreden_uspeh += class1.students[i].grade;
  }

float klas_sreden_uspeh = sreden_uspeh / class1.studenti;
float sreden_uspeh_2 = 0;
    printf("Enter the number of students in the class 2: ");
  scanf("%d", &class2.studenti);
  for(int i = 0; i < class2.studenti; i++) {
    printf("Ime na student %d: ", i+1);
    scanf("%s", class2.students[i].name);
    printf("Ocenka na student %d: ", i+1);
    scanf("%d", &class2.students[i].grade);
    sreden_uspeh_2 += class2.students[i].grade;
  }
  
    float klas_sreden_uspeh2 = sreden_uspeh_2 / class2.studenti;
 printf("Sredniq uspeh na klas 1 e: %.2f\n", klas_sreden_uspeh);
  printf("Sredniq uspeh na klas 2 e: %.2f\n", klas_sreden_uspeh2);
  int total_studenti = class1.studenti + class2.studenti;
  float sreden_vipusk_avg_gpa = (sreden_uspeh + sreden_uspeh_2) / total_studenti;
  printf("Sredno za vsichki: %.2f\n", sreden_vipusk_avg_gpa);
  
  return 0;
}
