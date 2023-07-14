#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct S{
    char *firstName;
    char* lastName;
    int phone;
    char* emailAddress;
};

static int i, j;
static int count;

void sort_first_name(struct S** ss){
    for(i = 0; i < count; i++)
        for (j = i + 1; j < count; j++)
            if (strcmp(ss[i]->firstName, ss[j]->firstName) > 0) {
                struct S* temp = ss[i];
                ss[i] = ss[j];
                ss[j] = temp;
            }
}

int find_first_name(struct S** ss, char* s){
    int i = -1;
    while(++i < count)
        if(strcmp(ss[i]->firstName, s) == 0)
            return 1;
    return 0;
}

void sort_last_name(struct S** ss){
    for(i = 0; i < count; i++)
        for (j = i + 1; j < count; j++)
            if (strcmp(ss[i]->lastName, ss[j]->lastName) > 0) {
                struct S* temp = ss[i];
                ss[i] = ss[j];
                ss[j] = temp;
            }
}

int find_last_name(struct S** ss, char* s){
    int i = -1;
    while(++i < count){
        if(strcmp(ss[i]->lastName, s) == 0)
            return 1;
    }
    return 0;
}

void sort_emailadress(struct S** ss){
    for(i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(ss[i]->emailAddress, ss[j]->emailAddress) > 0) {
                struct S *s = ss[i];
                ss[i] = ss[j];
                ss[j] = s;
            }
        }
    }
}

int find_emailadress(struct S** ss, char* s){
    for(i = 0; i < count; i++){
        if(strcmp(ss[i]->emailAddress, s) == 0){
            return 1;
        }
    }
    return 0;
}

void sort_phone_number(struct S** ss){
    for(i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (ss[i]->phone < ss[j]->phone) {
                struct S *s = ss[i];
                ss[i] = ss[j];
                ss[j] = s;
            }
        }
    }
}

int find_phone_number(struct S** ss, int s){
    for (i = 0; i < count; i++) {
        if (ss[i]->phone == s) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char ** argv) {
    int i;
    int count = 0;
    char buffer[10];

    struct S** ss = (struct S**) malloc(100*sizeof(struct S**));
    struct S* s = malloc(sizeof(*s));

    FILE *f = fopen(argv[1], "r");

    for(i = 0; i < 50; i++){

        struct S* s = malloc(sizeof(*s));

        s->firstName = (char*) malloc(80 * sizeof(s->firstName[0]));
        s->lastName = (char*) malloc(80 * sizeof(s->firstName[0]));
        s->emailAddress = (char*) malloc(80 * sizeof(s->firstName[0]));

        fscanf(f, "%s %s %d %s", &s->firstName, &s->lastName, &s->phone, &s->emailAddress);

        ss[count] = s;
        count += 1;
    }

    int command = 10;
    while(command != 0){
        char* val = malloc(100*sizeof(val[0]));
        fgets(buffer, 10, stdin);
        command = atoi(buffer);
        fgets(buffer, 10, stdin);
        strcpy(val, buffer);
        switch(command){
            case 1:
            printf("looking for email %s\n", val);
            sort_emailadress(ss);
            printf("found it? %d\n", find_emailadress(ss, val));
            break;
            case 2:
            printf("looking for firstname %s\n", val);
            sort_first_name(ss);
            printf("found it? %d\n", find_first_name(ss, val));
            break;
            case 3:
            printf("looking for lasname %s\n", val);
            sort_last_name(ss);
            printf("found it? %d\n", find_last_name(ss, val));
            break;
            case 4:
            printf("looking for email %s\n", val);
            sort_phone_number(ss);
            printf("found it? %d\n", find_phone_number(ss, atoi(val)));
            break;
            default:
            break;
        }
    }
}