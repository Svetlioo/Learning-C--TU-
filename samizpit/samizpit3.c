#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_NAME 56
#define SIZE_ID 7

typedef struct {
    char Names[SIZE_NAME];
    char ID[SIZE_ID];
    float M_PRICE;
    int LOCKER;
} TMember;



void InputMember(TMember* members) {
    TMember member;
    FILE* f;
    static int arrayLength = 1;
    printf("Names: ");
    fgets(member.Names, SIZE_NAME, stdin);
    fflush(stdin);
    member.Names[strlen(member.Names)-1] = '\0';
    printf("ID: ");
    fgets(member.ID, SIZE_ID, stdin);
    fflush(stdin);
    printf("M_PRICE: ");
    scanf("%f", &member.M_PRICE);
    fflush(stdin);
    member.LOCKER = 0;
    while(member.LOCKER < 100 || member.LOCKER > 999) {
        printf("LOCKER: ");
        scanf("%d", &member.LOCKER);
    }
    fflush(stdin);
    members = (TMember*)realloc(members,arrayLength*(sizeof(TMember)));
    members[arrayLength-1] = member;
    if ((f = fopen("membersText.txt", "a")) == NULL) {
        perror("Error opening text file: ");
        exit(1);
    }
    int nameLength = strlen(members[arrayLength-1].Names);
    fprintf(f, "%d;%s;%s;%.2f;%d\n", nameLength, member.Names, member.ID, member.M_PRICE, member.LOCKER);
    fclose(f);
    arrayLength++;
}

void srednoAritm(TMember members[]) {
    int broiMembers = 3;
    float srednoaritm;
    for (int i = 0; i < broiMembers; i++) {
        srednoaritm += members[i].M_PRICE;
    }
    srednoaritm /= broiMembers;
    printf("Sredno aritm: %.2f\n", srednoaritm);
    for (int i = 0; i < broiMembers; i++) {
        if(members[i].M_PRICE < srednoaritm) {
            printf("%s - %s - %.2f\n", members[i].Names, members[i].ID, members[i].M_PRICE);
        };
    }
}

int main() {
    TMember* members = NULL;
    InputMember(members);
    InputMember(members);
    srednoAritm(members);
    free(members);
    return 0;
}