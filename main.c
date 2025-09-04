#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main(void) {
    FILE *file;
    file = fopen("database.txt", "w");
    if (file == NULL) {
	perror("Error opening file for writing");
	exit(EXIT_FAILURE);
    }

    int n;
    printf("Введите количество студентов: ");
    scanf("%d", &n);
    
    struct Student *students = (struct Student*)malloc(n * sizeof(struct Student));
    
    for (int i = 0; i < n; i++) {
        printf("Студент %d:\n", i + 1);
        printf("Имя: ");
        scanf("%s", students[i].name);
        printf("Возраст: ");
        scanf("%d", &students[i].age);
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
    }
    
    printf("\nСписок студентов:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: возраст %d, GPA %.2f\n", 
               students[i].name, students[i].age, students[i].gpa);
    }
    fprintf(file, "Список студентов:\n"); 
    for (int i = 0; i < n; i++) {
	fprintf(file, "%s: возраст %d, GPA %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }    
    free(students);
    
    return 0;
}
