#include <iostream>
using namespace std;

class List {
private:
    int data[100];
    int length;

public:
    List() {
        length = 0;
    }

    void add(int n) {
        data[length++] = n;
    }

    int find(int n) {
        for (int i = 0; i < length; i++) {
            if (data[i] == n) {
                return i;
            }
        }
        return -1;
    }

    void display() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    List list;
    list.add(5);
    list.add(7);
    list.add(9);
    list.add(1);

    list.display();

    int number = 7;
    int index = list.find(number);

    if (index != -1) {
        cout << "Found " << number << " at index " << index << endl;
    } else {
        cout << "Could not find " << number << endl;
    }

    return 0;
}