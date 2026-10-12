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

void link_parents(Person *child, Person *father, Person *mother) {
    child->father = father;
    child->mother = mother;
}

void print_family_relationships(const Person *me)
{
    printf("\n=== FAMILY TREE RELATIONSHIPS ===\n");

    // Print yourself
    printf("1. YOURSELF:\n");

    printf("You: %s, Age: %d\n\n", me->name, me->age);

    // Print your parents
    printf("2. YOUR PARENTS:\n");
    if (me->father != NULL) {
        printf("Father: %s, Age: %d\n", me->father->name, me->father->age);
    }
    if (me->mother != NULL) {
        printf("Mother: %s, Age: %d\n\n", me->mother->name, me->mother->age);
    }

    // Print your paternal grandparents
        printf("3. PATERNAL GRANDPARENTS:\n");
    if (me->father != NULL) {
        if (me->father->father != NULL) {
            printf("Paternal Grandfather: %s, Age: %d\n", me->father->father->name, me->father->father->age);
        }
        if (me->father->mother != NULL) {
            printf("Paternal Grandmother: %s, Age: %d\n\n", me->father->mother->name, me->father->mother->age);
        }
    }

    // Print your maternal grandparents
    printf("4. MATERNAL GRANDPARENTS:\n");
    if (me->mother != NULL) {
        if (me->mother->father != NULL) {
            printf("Maternal Grandfather: %s, Age: %d\n", me->mother->father->name, me->mother->father->age);
        }
        if (me->mother->mother != NULL) {
            printf("Maternal Grandmother: %s, Age: %d\n\n", me->mother->mother->name, me->mother->mother->age);
        }
    }
}
int main(){
    Person *people[7];
    const char *roles[7] = {"Paternal Grandfather", "Paternal Grandmother", "Maternal Grandfather", "Maternal Grandmother", "Father", "Mother", "Yourself"};
    for(int i = 0; i < 7; i++) {
        people[i] = create_person(roles[i], 0); // Initialize with age 0, will be set later
        read_person_info(roles[i], people[i]->name, sizeof(people[i]->name), &people[i]->age);
    }
    

    // Link parents for the child (index 6)
    link_parents(people[6], people[4], people[5]); // Yourself's parents
    link_parents(people[4], people[0], people[1]); // Father's parents
    link_parents(people[5], people[2], people[3]); // Mother's parents
    
    print_family_relationships(people[6]); // Print relationships for the child

    return 0;
}