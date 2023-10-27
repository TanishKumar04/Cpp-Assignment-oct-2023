#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Student {
protected:
    string name;
    int rollno;
    string subname;

public:
    Student(string name, int rollno, string subname) : name(name), rollno(rollno), subname(subname) {}
    virtual ~Student() {}
    virtual void display() const = 0;

    int getRollno() const {
        return rollno;
    }
};

class InternalStudent : public Student {
private:
    int subcode;
    int internalMarks;
    int externalMarks;

public:
    InternalStudent(string name, int rollno, string subname, int subcode, int internalMarks, int externalMarks)
        : Student(name, rollno, subname), subcode(subcode), internalMarks(internalMarks), externalMarks(externalMarks) {}

    void display() const override {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Subject: " << subname << endl;
        cout << "Subject Code: " << subcode << endl;
        cout << "Internal Marks: " << internalMarks << endl;
        cout << "External Marks: " << externalMarks << endl;
    }
};

void displayStudent(const vector<InternalStudent>& students, int rollno) {
    for (const auto& student : students) {
        if (student.getRollno() == rollno) {
            student.display();
            return;
        }
    }
    cout << "No student found with roll no: " << rollno << endl;
}

int main() {
    vector<InternalStudent> students;
    students.push_back(InternalStudent("John", 1, "Physics", 101, 90, 92));
    students.push_back(InternalStudent("Alice", 2, "Chemistry", 102, 92, 94));
    students.push_back(InternalStudent("Bob", 3, "Mathematics", 103, 89, 90));

    int rollno;
    cout << "Enter roll no to display marks: ";
    cin >> rollno;
    displayStudent(students, rollno);

    return 0;
}