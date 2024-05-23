
def newStudent():
    fname = open('students.txt', 'a+')

    first_name = input("Please enter student's first name: ")
    last_name = input("Please enter student's last name: ")
    midterm = input("Please enter student's midterm grade : ")
    final = input("Please enter student's final grade : ")

    fname.write(first_name + " " + last_name + " " + midterm + " " + final + "\n")

    fname.close()


def printAllStudents():

    fname = open('students.txt', 'r')

    min = 1000
    max = 0
    sum = 0
    count = 0

    print("Students and their midterm and final grades:")
    print("Name\t\tSurname\t\tMidterm\t\tFinal\t\tEoS_Grade")

    for line in fname:
        words = line.split()
        for word in words:
            print(word, end="\t\t")

        grade = (int(words[2]) * 0.4) + (int(words[3]) * 0.6)
        print(grade)

        if grade < min:
            min = grade

        if grade > max:
            max = grade

        sum += grade
        count += 1

    print("\n\n")
    print("Min grade: ", min)
    print("Max grade: ", max)
    print("Average: ", sum/count)

    fname.close()
    print()


print("Welcome to student file system")

while True:
    print("Please choose an option: ")
    print("  1 for appending a new student to the file\n  2 for reading all students' data from the file\n  3 for EXIT")
    choice = input("Your choice ?? ")

    if choice == '1':
        newStudent()
    elif choice == '2':
        printAllStudents()
    elif choice == '3':
        print("Goodbye...")
        break
    else:
        print("Invalid choice")
