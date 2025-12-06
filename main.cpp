#include <iostream>
using namespace std;

int main() {
    string firstName;
    string lastName;
    double yearsAtUSC;
    
    // Prompt for input
    cout << "Enter your First Name: ";
    cin >> firstName;
    cout << "Enter your Last Name: ";
    cin >> lastName;
    cout << "Enter your number of years at USC: ";
    cin >> yearsAtUSC;
    
    // Determine standing
    string standing;
    
    if (yearsAtUSC < 1) {
        standing = "Freshman";
    }
    else if (yearsAtUSC >= 1 && yearsAtUSC < 2) {
        standing = "Sophomore";
    }
    else if (yearsAtUSC >= 2 && yearsAtUSC < 3) {
        standing = "Junior";
    }
    else {
        standing = "Senior";
    }
    
    // Output result
    cout << firstName << " " << lastName << ", " << standing << endl;
    
    return 0;
}