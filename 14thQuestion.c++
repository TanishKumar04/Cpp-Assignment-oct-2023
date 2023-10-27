#include<iostream>
using namespace std;

class Employee {
    private:
        int code;
        string designation;
        int experience;
        int age;

    public:
        // constructor
        Employee(int c, string d, int e, int a) {
            code = c;
            designation = d;
            experience = e;
            age = a;
        }

        // destructor
        ~Employee() {
            cout << "Destructor called, deleting the memory of the Employee object" << endl;
        }

        // getters
        int getCode() { return code; }
        string getDesignation() { return designation; }
        int getExperience() { return experience; }
        int getAge() { return age; }

        // display details
        void displayDetails() {
            cout << "Employee Code: " << code << endl;
            cout << "Designation: " << designation << endl;
            cout << "Experience: " << experience << " years" << endl;
            cout << "Age: " << age << " years" << endl;
        }
};

int main() {
    // allocate memory for an Employee object dynamically
    Employee* emp = new Employee(123, "Software Engineer", 3, 28);

    // call the member function to display details
    emp->displayDetails();

    // deallocate the memory for the Employee object dynamically
    delete emp;

    return 0;
}
