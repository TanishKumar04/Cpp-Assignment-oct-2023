#include <iostream>
#include <vector>
#include <algorithm>

class List {
private:
    std::vector<int> data;

public:
    void add(int n) {
        data.push_back(n);
        std::sort(data.begin(), data.end());
    }

    int find(int n) {
        auto it = std::lower_bound(data.begin(), data.end(), n);
        if (it != data.end() && *it == n) {
            return it - data.begin();
        }
        return -1;
    }

    void display() {
        for (int n : data) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
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
        std::cout << "Found " << number << " at index " << index << std::endl;
    } else {
        std::cout << "Could not find " << number << std::endl;
    }

    return 0;
}