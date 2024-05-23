#include <stdio.h>

struct studentData
{
    int id;
    char surname[20];
    char name[20];
    double midterm;
    double final;
};

void createFile(char fileName[]);
void listStudents(char fileName[]);
void newStudent(char fileName[]);

int enterChoice();

int main()
{
    FILE *filePointer = NULL;
    int choice;
    char fileName[] = "students.dat";

    while ((choice = enterChoice()) != 0)
    {
        switch (choice)
        {
        case 1:
            createFile(fileName);
            break;
        case 2:
            listStudents(fileName);
            break;
        case 3:
            newStudent(fileName);
            break;
        default:
            printf("\n Invalid choice !!! \n");
        }
    }
    return 0;
}

void createFile(char fileName[])
{
    FILE *fileP;
    if ((fileP = fopen(fileName, "w")) == NULL)
        printf("\n File %s could not be opened!! \n", fileName);
    else
    {
        printf("\n %s file is created successfully. \n", fileName);
        fclose(fileP);
    }
}

void listStudents(char fileName[])
{
    FILE *fileP;
    struct studentData student = {0, "", "", 0.0, 0.0};
    double termGrade = 0.0;

    if ((fileP = fopen(fileName, "r")) == NULL)
        printf("\n File could not be opened!! \n");
    else
    {
        printf("\n%s\t%s\t%s\t%s\t%s\t%s\n", "Student id", "Surname", "Name", "Midterm", "Final", "Term Grade");
        while (fscanf(fileP, "%d\t%s\t%s\t%lf\t%lf", &student.id, student.surname, student.name, &student.midterm, &student.final) == 5)
        {
            termGrade = (student.midterm * 0.4) + (student.final * 0.6);
            printf("%d\t%s\t%s\t%f\t%f\t%f\n", student.id, student.surname, student.name, student.midterm, student.final, termGrade);
        }
        printf("\n End of file... \n");
        fclose(fileP);
    }
}

void newStudent(char fileName[])
{
    FILE *fileP;
    struct studentData student = {0, "", "", 0.0, 0.0};

    if ((fileP = fopen(fileName, "a+")) == NULL)
        printf("\n File could not be opened!! \n");
    else
    {
        printf("\n Enter a new student id: ");
        scanf("%d", &student.id);
        printf("\n Enter student's first name and last name: ");
        scanf("%19s %19s", student.name, student.surname);
        printf("\n Enter student's midterm and final grades in 'xx.x' format: ");
        scanf("%lf %lf", &student.midterm, &student.final);

        fprintf(fileP, "%d %s %s %.1f %.1f ", student.id, student.surname, student.name, student.midterm, student.final);

        fclose(fileP);
    }
}

int enterChoice()
{
    int choice;

    printf("\n Please select the operation \n"
           " 1 - Create a new students.dat file (Warning!! Erases previously existing file)\n"
           " 2 - List all students \n"
           " 3 - Enter new student record \n"
           " 0 - Quit program \n"
           " ???_ ");

    scanf("%d", &choice);
    return choice;
}
