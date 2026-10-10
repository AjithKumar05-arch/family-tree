#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char name[50];
    int age;
    struct person *father;
    struct person *mother;
} Person;

Person *create_person(const char *name, int age)
{
    Person *person = malloc(sizeof(Person));
    if (person == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    if(name == NULL) {
        fprintf(stderr, "Name cannot be NULL\n");
        free(person);
        exit(EXIT_FAILURE);
    }
    if(strlen(name) >= sizeof(person->name)) {
        fprintf(stderr, "Name is too long\n");
        free(person);
        exit(EXIT_FAILURE);
    }
    
    strcpy(person->name, name);
    person->age = age;
    person->father = NULL;
    person->mother = NULL;
    return person;
}
int main(){
    Person *me= create_person("Ajeet", 21);
    printf("Name: %s, Age: %d\n", me->name, me->age);
    free(me);
    return 0;
}