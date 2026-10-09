#include <iostream>
using namespace std;

int * allocateArray(int size) {
    int * arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    return arr;
}

// if called in main >> memory leak
void doSum() {
    int * x = allocateArray(5);
    return;
}

int main() {
    int myInteger = 5;
    cout << "\n\nThe value of myInteger is: " << myInteger << "\n\n";
    cout << "\n\nThe address of myInteger is: " << &myInteger << "\n\n";
    int * myPointer;
    myPointer = &myInteger;
    cout << "\n\nThe value of myPointer is: " << myPointer << "\n\n";
    cout << "\n\nThe address of myPointer is: " << &myPointer << "\n\n";
    
    int size = 99;

    cout << "Please enter the size of the class: ";
    cin >> size;

   // int studentIDs[size]; // wrong, not C++, do it like this:
  /*   int * studentIDs = new int[size]; // allocates RAM when program alr running
    // pointer integer representing array, can use array syntax

    for (int i = 0; i < size; i++) {
        cout << "\n\nPlease put in the student ID for the " << i << " index: ";
        cin >> studentIDs[i];

        cout << "\n\nThe memory address where the ID will be stored is: " << &studentIDs[i];
        
    } */

    // can do this instead w/ function

    int * studentIDs = allocateArray(size);

    cout << "\n\nDeferencing syntax...\n\n";

    for (int i = 0; i < size; i++) {
        cout << "\n\nAddress: " << (studentIDs + i);
        cout << "\nValue: " << *(studentIDs + i);
    }

    cout << "\n\n";

    delete studentIDs; // deleting value
    // Danger: dangling pointer
    studentIDs = nullptr; // retiring memory address, points to nothing

    cout << "The pointer points to: " << studentIDs;
    cout << "The value is: " << studentIDs[0];

    return 0;
}
