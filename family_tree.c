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
void read_person_info(const char *role, char *name_out, size_t name_capacity, int *age_out) {
    printf("Enter %s's name: ", role);
    fgets(name_out, name_capacity, stdin);
    name_out[strcspn(name_out, "\n")] = 0; // Remove newline character
    printf("Enter %s's age: ", role);
    scanf("%d", age_out);
    getchar(); // Consume the newline character left by scanf
}
int main(){
    Person *people[7];
    const char *roles[7] = {"Paternal Grandfather", "Paternal Grandmother", "Maternal Grandfather", "Maternal Grandmother", "Father", "Mother", "Yourself"};
    for(int i = 0; i < 7; i++) {
        people[i] = create_person(roles[i], 0); // Initialize with age 0, will be set later
        read_person_info(roles[i], people[i]->name, sizeof(people[i]->name), &people[i]->age);
    }
    
    for(int i = 0; i < 7; i++) {
        printf("%s: Name: %s, Age: %d\n", roles[i], people[i]->name, people[i]->age);
    }

    for (int i = 0; i < 7; i++) {
    free(people[i]);
    }
    
    return 0;
}