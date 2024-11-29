#include <stdio.h>

struct Student {
  int number;
  char name[20];
  char surname[20];
  char department[50];
};

void createFile() {
  FILE *file = fopen("students.txt", "wb");
  if (file == NULL) {
    printf("File could not be opened.\n");
    return;
  }
  struct Student student = {0, "", "", ""};
  for (int i = 0; i < 100; i++) {
    fwrite(&student, sizeof(struct Student), 1, file);
  }
  printf("File created successfully.\n");
  fclose(file);
}

void addStudent() {
  FILE *file = fopen("students.txt", "rb+");
  if (file == NULL) {
    printf("File could not be opened.\n");
    return;
  }

  struct Student student;
  printf("Enter student number(1-100): ");
  int stuNum;
  scanf("%d", &stuNum);
  if (stuNum < 1 || stuNum > 100) {
    printf("Invalid number.\n");
    fclose(file);
    return;
  }
  fseek(file, (stuNum - 1) * sizeof(struct Student), SEEK_SET);
  fread(&student, sizeof(struct Student), 1, file);

  if (student.number != 0) {
    printf("Student already exists.\n");
    fclose(file);
    return;
  }
  printf("Enter student name: ");
  scanf("%s", student.name);
  printf("Enter student surname: ");
  scanf("%s", student.surname);
  printf("Enter student department: ");
  scanf("%s", student.department);
  student.number = stuNum;

  fseek(file, (stuNum - 1) * sizeof(struct Student), SEEK_SET);
  fwrite(&student, sizeof(struct Student), 1, file);

  fclose(file);
  printf("Student data written to file successfully\n");
}

void findStudent() {
  FILE *file = fopen("students.txt", "rb");
  if (file == NULL) {
    printf("File could not be opened.\n");
    return;
  }

  struct Student student;
  printf("Enter student number to find(1-100): ");
  int stuNum;
  scanf("%d", &stuNum);

  if (stuNum < 1 || stuNum > 100) {
    printf("Invalid number.\n");
    fclose(file);
    return;
  }

  fseek(file, (stuNum - 1) * sizeof(struct Student), SEEK_SET);
  fread(&student, sizeof(struct Student), 1, file);

  if (student.number == 0) {
    printf("Student not found.\n");
  } else {
    printf("%d, %s, %s, %s\n", student.number, 
      student.name, student.surname, student.department);
  }

  fclose(file);
}

int main(void) {
  int choice;

  while (1) {
    printf("\n1. Create new file\n2. Add new student\n3. Find students\n4. "
           "Exit\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      createFile();
      break;
    case 2:
      addStudent();
      break;
    case 3:
      findStudent();
      break;
    case 4:
      printf("Exiting program...\n");
      return 0;
    default:
      printf("Invalid choice. Please enter a valid option.\n");
    }
  }

  return 0;
}