#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    long facultyNumber;
    int groupNumber;
    float grade;
};

struct student *students;

void input(int size) {
    students = malloc(size * sizeof(struct student));
    for (int i = 0; i < size; i++) {
        printf("\nEnter name: ");
        scanf("%s", students[i].name);
        printf("Enter faculty Number: ");
        scanf("%ld", &students[i].facultyNumber);
        printf("Enter group Number: ");
        scanf("%d", &students[i].groupNumber);
        printf("Enter grade: ");
        scanf("%f", &students[i].grade);
    }
}

void printStudents(int size) {
    for (int i = 0; i < size; i++) {
        printf("\nStudent %d\nName: %s\nFaculty number: %ld\nGroup number: %d\nGrade: %.2f\n", i + 1, students[i].name, students[i].facultyNumber, students[i].groupNumber, students[i].grade);
    }
}

void averageGrade(int size) {
    int groupNum;
    float sum = 0, count = 0;
    printf("\nEnter group number for average grade: ");
    scanf("%d", &groupNum);
    for (int i = 0; i < size; i++) {
        if (students[i].groupNumber == groupNum) {
            sum += students[i].grade;
            count++;
        }
    }
    if (count > 0) {
        printf("\nAverage grade for group %d: %.2f\n", groupNum, sum / count);
    } else {
        printf("\nNo students found in group %d\n", groupNum);
    }
}

void over_5_50(int size) {
    printf("\nStudents with grade over 5.50:\n");
    for (int i = 0; i < size; i++) {
        if (students[i].grade >= 5.50) {
            printf("%s\n", students[i].name);
        }
    }
    printf("\n");
}

void groupList(int size) {
    int groupNum;
    printf("\nEnter group number for student list: ");
    scanf("%d", &groupNum);
    printf("\nStudents in group %d:\n", groupNum);
    for (int i = 0; i < size; i++) {
        if (students[i].groupNumber == groupNum) {
            printf("%s\n", students[i].name);
        }
    }
    printf("\n");
}

int main() {
    int size;
    char menuOption;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    students = malloc(size * sizeof(struct student));
    printf("\nEnter A for input, B for printStudents, C for Average Grade, D for Students over 5.50 grade, E for student list for a group\nPress Q to quit:\n");
    scanf(" %c", &menuOption);

    while (menuOption != 'Q') {
        switch (menuOption) {
            case 'A':
                input(size);
                break;
            case 'B':
                printStudents(size);
                break;
            case 'C':
                averageGrade(size);
                break;
            case 'D':
                over_5_50(size);
                break;
            case 'E':
                groupList(size);
                break;
        }
        printf("Enter A for input, B for printStudents, C for Average Grade, D for Students over 5.50 grade\nPress Q to quit:\n");
        scanf(" %c", &menuOption);
    }
    
    return 0;
}