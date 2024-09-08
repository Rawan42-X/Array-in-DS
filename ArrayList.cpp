#include <iostream>
#include <algorithm>
using namespace std;

class ArrayList {
private:
    int* Array;
    int size;
    int length;

public:
    // Constructor
    ArrayList(int size) {
        this->size = size;
        length = 0;
        Array = new int[size];
    }

    // Destructor
    ~ArrayList() {
        delete[] Array;
    }

    // Check if the array is empty => TC: O(1) SC: O(1)
    bool isEmpty() {
        return (length == 0);
    }

    // Check if the array is full => TC: O(1) SC: O(1)
    bool isFull() {
        return (length == size);
    }

    // Add value to the end => TC: O(1) SC: O(1)
    void Append(int value) {
        if (isFull()) {
            cout << "The array is full\n";
        }
        else {
            Array[length++] = value;
        }
    }

    // Insert value at a specific index => TC: O(n) SC: O(1)
    void Insert(int index, int value) {
        if (isFull()) {
            cout << "The array is full\n";
            return;
        }
        else if (index < 0 || index > length) {
            cout << "Invalid index\n";
            return;
        }

        for (int i = length; i > index; i--) {
            Array[i] = Array[i - 1];
        }
        Array[index] = value;
        length++;
    }

    // Print the array => TC: O(n) SC: O(1)
    void Print() {
        if (isEmpty()) {
            cout << "The array is empty\n";
        }
        else {
            for (int i = 0; i < length; i++) {
                cout << Array[i] << " ";
            }
            cout << endl;
        }
    }

    // Print the array in reverse => TC: O(n) SC: O(1)
    void PrintReverse() {
        if (isEmpty()) {
            cout << "The array is empty\n";
        }
        else {
            for (int i = length - 1; i >= 0; i--) {
                cout << Array[i] << " ";
            }
            cout << endl;
        }
    }

    // Reverse the array => TC: O(n) SC: O(1)
    void Reverse() {
        for (int i = 0; i < length / 2; i++) {
            swap(Array[i], Array[length - 1 - i]);
        }
    }

    // Rotate array by given positions => TC: O(n) SC: O(1)
    void rotateArray(int positions, bool toLeft = true) {
        if (isEmpty()) return;

        positions = positions % length;
        if (toLeft) {
            reverse(Array, Array + positions);
            reverse(Array + positions, Array + length);
            reverse(Array, Array + length);
        }
        else {
            reverse(Array, Array + length - positions);
            reverse(Array + length - positions, Array + length);
            reverse(Array, Array + length);
        }
    }

    // Find and return duplicates in the array => TC: O(n^2) SC: O(n)
    void findDuplicates() {
        bool foundDuplicate = false;
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                if (Array[i] == Array[j]) {
                    cout << "Duplicate found: " << Array[i] << endl;
                    foundDuplicate = true;
                    break;
                }
            }
        }
        if (!foundDuplicate) {
            cout << "No duplicates found\n";
        }
    }

    // Merge with another array => TC: O(n + m) SC: O(n + m)
    void merge(const ArrayList& otherArray) {
        int newSize = length + otherArray.length;
        int* newArray = new int[newSize];

        for (int i = 0; i < length; i++) {
            newArray[i] = Array[i];
        }

        for (int i = 0; i < otherArray.length; i++) {
            newArray[length + i] = otherArray.Array[i];
        }

        delete[] Array;
        Array = newArray;
        length = newSize;
        size = newSize;
    }

    // Resize the array => TC: O(n) SC: O(n)
    void resizeArray(int newSize) {
        if (newSize < length) {
            cout << "Cannot resize to a smaller size than current length\n";
            return;
        }

        int* newArray = new int[newSize];

        for (int i = 0; i < length; i++) {
            newArray[i] = Array[i];
        }

        delete[] Array;
        Array = newArray;
        size = newSize;
    }
};

int main() {
    ArrayList list(5);

    // Testing append and print
    list.Append(10);
    list.Append(20);
    list.Append(30);
    list.Append(40);
    list.Append(50);
    list.Print();  // Output: 10 20 30 40 50

    // Testing rotateArray
    list.rotateArray(2);
    list.Print();  // Output: 30 40 50 10 20 (rotated to the left by 2)

    // Testing reverse
    list.Reverse();
    list.Print();  // Output: 20 10 50 40 30

    // Testing findDuplicates
    list.Append(10);
    list.findDuplicates();  // Output: Duplicate found: 10

    // Testing resizeArray
    list.resizeArray(10);
    list.Append(60);
    list.Append(70);
    list.Print();  // Output: 20 10 50 40 30 10 60 70

    // Testing mergeWith
    ArrayList list2(3);
    list2.Append(100);
    list2.Append(200);
    list2.Append(300);
    list.merge(list2);
    list.Print();  // Output: 20 10 50 40 30 10 60 70 100 200 300

    return 0;
}
