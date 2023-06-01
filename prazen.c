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


// int arrayLength = 0;

void InputMember(TMember* members) {
    TMember member;
    FILE* f;
    static int arrayLength = 0;
    arrayLength++;
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
    if (members == NULL) {
        perror("Error reallocating memorry: ");
        exit(1);
    }
    members[arrayLength-1] = member;
    if ((f = fopen("membersText.txt", "a")) == NULL) {
        perror("Error opening text file: ");
        exit(1);
    }
    int nameLength = strlen(members[arrayLength-1].Names);
    fprintf(f, "%d;%s;%s;%.2f;%d\n", nameLength, member.Names, member.ID, member.M_PRICE, member.LOCKER);
    fclose(f);
}

void srednoAritm(TMember members[]) {
    int broiMembers = 3;
    // int broiMembers = sizeof(members) / sizeof(members[0]);
    float srednoaritm = 0;
    for (int i = 0; i < broiMembers; i++) {
        srednoaritm += members[i].M_PRICE;
    }
    srednoaritm /= broiMembers;
    printf("Sredno aritm: %.2f\n", srednoaritm);
    for (int i = 0; i < broiMembers; i++) {
        if(members[i].M_PRICE < srednoaritm) {
            printf("%s - %s - %.2f\n", members[i].Names, members[i].ID, members[i].M_PRICE);
        }
    }
}

void WriteToBin(char ID[]) {
    FILE* f;
    TMember member;
    unsigned len;
    if ((f=fopen("members.bin", "rb")) == NULL) {
        perror("Error reading binary file: ");
        exit(1);
    }
    while (true) {
        if ((fread(&len,sizeof(unsigned), 1, f)) != 1) {
            if (!feof(f)) {
                perror("Reading bin error: ");
                exit(1);
            }
            else {
                break;
            }
        }
        if ((fread(member.Names,sizeof(char), len, f)) != len) {
            perror("Reading bin error: ");
                exit(1);
        }
        member.Names[len] = '\0';
        if ((fread(member.ID,sizeof(char), SIZE_ID-1, f)) != SIZE_ID-1) {
            perror("Reading bin error: ");
                exit(1);
        }
        member.ID[SIZE_ID-1] = '\0';
        if ((fread(member.Names,sizeof(char), len, f)) != len) {
            perror("Reading bin error: ");
                exit(1);
        }
        if ((fread(&member.M_PRICE,sizeof(float), 1, f)) != 1) {
            perror("Reading bin error: ");
                exit(1);
        }
        if ((fread(&member.LOCKER,sizeof(int), 1, f)) != 1) {
            perror("Reading bin error: ");
                exit(1);
        }
        if (member.ID == ID) {
            printf("Bin Names: %s\n", member.Names);
            printf("Bin ID: %s\n", member.ID);
            printf("Bin M_Price: %.2f\n", member.M_PRICE);
            printf("Bin Locker: %d\n", member.LOCKER);
        }
}
    fclose(f);
}



int main() {
    TMember* members = (TMember*)calloc(0,sizeof(TMember));
    InputMember(members);
    InputMember(members);
    InputMember(members);
    // srednoAritm("NQKAKUV ARRAY");
    printf("%s, %s, %s\n", members[0].Names,members[1].Names,members[2].Names);

    free(members);
    return 0;
}