#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 1000
#define MAX_NAME_LENGTH 50

// Custom data structure for student records
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float* grades;
    int grade_count;
} Student;

// Global array to store student records
Student* student_database[MAX_STUDENTS];
int total_students = 0;

// Function prototypes
Student* create_student(const char* name, int age);
int add_grade(Student* student, float grade);
void print_student_details(const Student* student);
void optimize_memory_usage();

int main() {
    // Sample initialization
    Student* s1 = create_student("Alice", 20);
    add_grade(s1, 85.5);
    add_grade(s1, 90.0);
    add_grade(s1, 87.5);
    
    print_student_details(s1);

    // Memory leak and inefficiency present
    return 0;
}

Student* create_student(const char* name, int age) {
    Student* new_student = malloc(sizeof(Student));
    
    // Potential buffer overflow risk
    strcpy(new_student->name, name);
    
    new_student->age = age;
    new_student->grades = NULL;
    new_student->grade_count = 0;
    
    // Add to global database
    if (total_students < MAX_STUDENTS) {
        student_database[total_students++] = new_student;
    }
    
    return new_student;
}

int add_grade(Student* student, float grade) {
    // Inefficient memory allocation strategy
    student->grades = realloc(student->grades, 
        (student->grade_count + 1) * sizeof(float));
    
    if (student->grades == NULL) {
        return 0;  // Allocation failed
    }
    
    student->grades[student->grade_count++] = grade;
    return 1;
}

void print_student_details(const Student* student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Grades: ");
    for (int i = 0; i < student->grade_count; i++) {
        printf("%.2f ", student->grades[i]);
    }
    printf("\n");
}