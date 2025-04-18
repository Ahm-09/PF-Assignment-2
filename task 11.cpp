#include <iostream>
#include <fstream>
using namespace std;
bool equal(char a[], char b[]);
void addStudent();
void viewStudents();
void searchStudent();
void updateGPA();
void deleteStudent();
int main() {
    int c;
    do {
        cout << " Student Management System " << endl;
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Update Student GPA\n";
        cout << "5. Delete Student Record\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> c;

        switch (c) {
        case 1: addStudent(); break;
        case 2: viewStudents(); break;
        case 3: searchStudent(); break;
        case 4: updateGPA(); break;
        case 5: deleteStudent(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }

    } while (c != 0);

    return 0;
}
bool equal(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return false;
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}
void addStudent() {
    ofstream file("students.txt", ios::app);
    char name[50], roll[20], dept[30];
    float gpa;

    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(name, 50);
    cout << "Enter Roll Number: ";
    cin.getline(roll, 20);    cout << "Enter Department: ";
    cin.getline(dept, 30);
    cout << "Enter GPA: ";
    cin >> gpa;
    file << name << "," << roll << "," << dept << "," << gpa << "\n";
    file.close();
    cout << "Student record added!\n";
}
void viewStudents() {
    ifstream file("students.txt");
    char ch;

    cout << "\nName\tRoll No\tDepartment\tGPA\n";
    while (file.get(ch)) {
        if (ch == ',')
            cout << '\t';
        else if (ch == '\n')
            cout << endl;
        else
            cout << ch;
    }
    file.close();
}
void searchStudent() {
    ifstream file("students.txt");
    char name[50], roll[20], dept[30], searchRoll[20];
    float gpa;
    bool found = false;

    cout << "Enter Roll Number to search: ";
    cin >> searchRoll;

    while (file.getline(name, 50, ',') &&
        file.getline(roll, 20, ',') &&
        file.getline(dept, 30, ',') &&
        file >> gpa) {
        file.ignore();
        if (equal(roll, searchRoll)) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << name << "\nRoll: " << roll << "\nDept: " << dept << "\nGPA: " << gpa << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found.\n";

    file.close();
}
void updateGPA() {
    ifstream f1("students.txt");
    ofstream f2("temp.txt");
    char name[50], roll[20], dept[30], searchRoll[20];
    float gpa, newGPA;
    bool updated = false;

    cout << "Enter Roll Number to update GPA: ";
    cin >> searchRoll;
    cout << "Enter new GPA: ";
    cin >> newGPA;

    while (f1.getline(name, 50, ',') &&
        f1.getline(roll, 20, ',') &&
        f1.getline(dept, 30, ' ') &&
        f1 >> gpa) {
        f1.ignore();

        if (equal(roll, searchRoll)) {
            gpa = newGPA;
            updated = true;
        }

        f2 << name << "," << roll << "," << dept << "," << gpa << "\n";
    }
    f1.close();
    f2.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (updated)
        cout << "GPA updated!\n";
    else
        cout << "Roll number not found.\n";
}
void deleteStudent() {
    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");
    char name[50], roll[20], dept[30], deleteRoll[20];
    float gpa;
    bool deleted = false;

    cout << "Enter Roll Number to delete: ";
    cin >> deleteRoll;

    while (inFile.getline(name, 50, ',') &&
        inFile.getline(roll, 20, ',') &&
        inFile.getline(dept, 30, ',') &&
        inFile >> gpa) {
        inFile.ignore();

        if (!equal(roll, deleteRoll)) {
            outFile << name << "," << roll << "," << dept << "," << gpa << "\n";
        }
        else {
            deleted = true;
        }
    }

    inFile.close();
    outFile.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (deleted)
        cout << "Student deleted successfully!\n";
    else
        cout << "Roll number not found.\n";
}
