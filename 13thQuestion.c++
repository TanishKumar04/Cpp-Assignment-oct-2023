#include<iostream>

class MyClass {
    public:
        void display() {
            std::cout << "MyClass object created successfully." << std::endl;
        }
};

int main() {
    MyClass* obj = new MyClass(); // creating memory space for a MyClass object
    obj->display(); // accessing the member function of the MyClass object

    delete obj; // destroying the memory space created for the MyClass object
    obj = nullptr; // setting the pointer to null after deletion

    return 0;
}