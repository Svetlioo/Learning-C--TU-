#include <stdio.h>
#define SIZE 2

struct student
{
    char name[50];
    long facultyNumber;
    int groupNumber;
    float grade;
};

struct student st[SIZE]; 

void input() {
    for(int i=0;i<SIZE;i++){    
        printf("\nEnter name: ");    
        scanf("%s", st[i].name);    
        printf("\nEnter faculty Number: ");    
        scanf("%ld",&st[i].facultyNumber);    
        printf("\nEnter group Number: ");    
        scanf("%d",&st[i].groupNumber);  
        printf("\nEnter grade: ");    
        scanf("%f",&st[i].grade);  
    }    
}

void printStudents() {
    for(int i = 0;i < SIZE;i++){    
        printf("Student %d\nName: %s,\nFaculty number: %ld,\nGroup number: %d,\nGrade %.2f\n\n",i+1,st[i].name,st[i].facultyNumber, st[i].groupNumber, st[i].grade);  
    }
}

void averageGrade() {
    int groupNum;
    float sum = 0, count = 0;
    printf("Enter group number for average grade: ");
    scanf("%d", &groupNum);
    for(int i = 0;i < SIZE;i++) {
        if (st[i].groupNumber == groupNum) {
            sum+= st[i].grade;
            count++;
        }
    }
    printf("Average grade for group %d: %.2f\n", groupNum, sum / count);
}

void over_5_50() {
    printf("Students with over 5.50: \n");
    for(int i = 0;i < SIZE;i++) {
        if (st[i].grade >= 5.50) {
            printf("%s\n", st[i].name);
        }
    }
    printf("\n");
}

int main() {
    char menuOption;
    printf("Enter A for input, B for printStudents, C for Average Grade, D for Students over 5.50 grade\nPress Q to quit:\n");
    scanf(" %c", &menuOption);

    while(menuOption != 'Q') {
        switch (menuOption) {
            case 'A': 
                input();
                break;
            case 'B': 
                printStudents();    
                break;
            case 'C':
                averageGrade();
                break;
            case 'D': 
                over_5_50();
                break;
        }    
        printf("Enter A for input, B for printStudents, C for Average Grade, D for Students over 5.50 grade\nPress Q to quit:\n");
        scanf(" %c", &menuOption);
    }
    
    return 0;
}