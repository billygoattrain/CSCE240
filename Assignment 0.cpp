#include <iostream> 
using namespace std; 

string freshman = "Freshman";
string sophomore = "Sophomore"; 
string junior = "Junior"; 
string senior = "Senior"; 
string firstName; 
string lastName; 
int yearInCollege;

int main (){

    cout << "Enter your First Name: "; 
    cin >> firstName; 
    cout << "Enter your Last Name: "; 
    cin >> lastName; 
    cout << "Enter your Year in college (numeric): "; 
    cin >> yearInCollege; 

    string yearName;

    if (yearInCollege <= 1)
        yearName = freshman;
    else if (yearInCollege == 2)
        yearName = sophomore;
    else if (yearInCollege == 3)
        yearName = junior; 
    else if (yearInCollege >= 4)
        yearName = senior; 
    else
        yearName = "Unknown";

    cout << "Hello " << firstName << " " << lastName << ", you are a "<< yearName << " in college "<< endl;

    return 0;
}