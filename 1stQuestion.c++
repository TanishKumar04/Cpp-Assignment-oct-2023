#include<iostream>
using namespace std;

class Student {
    int roll_no;
    string name;
    int marks[3];
    float total;
    float average;

public:
    Student(int r, string n, int m1, int m2, int m3) {
        roll_no = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;

        total = m1 + m2 + m3;
        average = total / 3;
    }

    void displayStudentInfo() {
        cout << "Roll No: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Total: " << total << endl;
        cout << "Average: " << average << endl;
    }
};

int main() {
    Student s1(1, "Alice", 85, 90, 80);
    s1.displayStudentInfo();

    Student s2(2, "Bob", 75, 85, 90);
    s2.displayStudentInfo();

    return 0;
}