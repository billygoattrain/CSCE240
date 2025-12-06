/*
 * Programmer: [Your Firstname] [Your Lastname]
 * Date: November 3, 2025
 * Time: [Current Time]
 * 
 * Implementation file for myString class
 */

#include "assignment4.h"
#include <iostream>
using namespace std;

/*
 * Default Constructor
 * Description: Initializes an empty string with size 0 and null data pointer
 * Input: None
 * Output: None
 */
myString::myString() {
    size = 0;
    data = nullptr;
}

/*
 * Alternate Constructor
 * Description: Initializes string with given size and copies character array
 * Input: size - size of the string
 *        arr - pointer to character array with initial values
 * Output: None
 * Notes: Performs deep copy of input array
 */
myString::myString(int size, char* arr) {
    this->size = size;
    if (size > 0) {
        data = new char[size];
        for (int i = 0; i < size; i++) {
            data[i] = arr[i];
        }
    } else {
        data = nullptr;
    }
}

/*
 * Destructor
 * Description: Frees dynamically allocated memory to prevent memory leaks
 * Input: None
 * Output: None
 */
myString::~myString() {
    if (data != nullptr) {
        delete[] data;
    }
}

/*
 * Insert Method
 * Description: Adds a character at the specified index, shifting elements right
 * Input: index - position to insert (0 to size inclusive)
 *        value - character to insert
 * Output: None (prints error if index out of bounds)
 * Notes: Creates new array with size+1, copies old data with new element inserted
 */
void myString::insert(int index, char value) {
    // Check bounds - can insert at positions 0 through size (inclusive)
    if (index < 0 || index > size) {
        std::cout << "Error: Index out of bounds for insert operation." << std::endl;
        return;
    }

    // Create new array with increased size
    char* newData = new char[size + 1];

    // Copy elements before insertion point
    for (int i = 0; i < index; i++) {
        newData[i] = data[i];
    }

    // Insert new value
    newData[index] = value;

    // Copy elements after insertion point
    for (int i = index; i < size; i++) {
        newData[i + 1] = data[i];
    }

    // Delete old array and update pointer
    if (data != nullptr) {
        delete[] data;
    }
    data = newData;
    size++;
}

/*
 * Remove Method
 * Description: Removes character at specified index and shifts elements left
 * Input: index - position to remove (0 to size-1)
 * Output: None (prints error if index out of bounds)
 * Notes: Creates new array with size-1, copies data excluding removed element
 */
void myString::remove(int index) {
    // Check bounds
    if (index < 0 || index >= size) {
        std::cout << "Error: Index out of bounds for remove operation." << std::endl;
        return;
    }

    // Special case: removing last element results in empty string
    if (size == 1) {
        delete[] data;
        data = nullptr;
        size = 0;
        return;
    }

    // Create new array with decreased size
    char* newData = new char[size - 1];

    // Copy elements before removal point
    for (int i = 0; i < index; i++) {
        newData[i] = data[i];
    }

    // Copy elements after removal point
    for (int i = index + 1; i < size; i++) {
        newData[i - 1] = data[i];
    }

    // Delete old array and update pointer
    delete[] data;
    data = newData;
    size--;
}

/*
 * Get Method
 * Description: Returns the character at specified index
 * Input: index - position to retrieve (0 to size-1)
 * Output: Character at given index, or '\0' if out of bounds
 * Notes: Prints error message for invalid indices
 */
char myString::get(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Error: Index out of bounds for get operation." << std::endl;
        return '\0';
    }
    return data[index];
}

/*
 * Clear Method
 * Description: Removes all elements and resets string to empty state
 * Input: None
 * Output: None
 * Notes: Frees memory and sets size to 0
 */
void myString::clear() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
    size = 0;
}

/*
 * Find Method
 * Description: Searches for first occurrence of a character in the string
 * Input: value - character to search for
 * Output: Index of first occurrence, or -1 if not found
 * Notes: Performs linear search from beginning of array
 */
int myString::find(char value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;  // Not found
}

/*
 * Equals Method
 * Description: Compares this string with another myString object for equality
 * Input: other - reference to another myString object
 * Output: true if contents are equal, false otherwise
 * Notes: Checks size first, then compares each character
 */
bool myString::equals(myString& other) {
    // If sizes differ, strings are not equal
    if (size != other.size) {
        return false;
    }

    // Compare each character
    for (int i = 0; i < size; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}

/*
 * Print Method
 * Description: Prints the string contents to stdout
 * Input: None
 * Output: Prints each character followed by newline
 * Notes: Handles empty strings gracefully
 */
void myString::print() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i];
    }
    std::cout << std::endl;
}

/*
 * GetSize Method
 * Description: Returns current size of the string
 * Input: None
 * Output: Current size value
 * Notes: Helper method for testing and external access
 */
int myString::getSize() {
    return size;
}