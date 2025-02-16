#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
    try {
        fraction f1, f2;  // Declare two fraction objects for input
        char choice;      // Variable to store user choice for repeat

        do {
            try {
                // Input two fractions from the user
                cout << "Enter two fractions as A/B \n";
                cout << "Nume1/Deno1: ";
                cin >> f1;
                cout << "Nume2/Deno2: ";
                cin >> f2;
            }
            catch (const invalid_argument& e) {
                // Handle invalid input for fraction format or division by zero
                cerr << "Fraction Error:" << e.what() << endl;
                cout << "Press any key to continue...";
                cin.ignore();
                cin.get();
                system("cls");
                continue;
            }

            // Displaying results for various operations
            cout << "\n-----------------------------------------------------------------\n";
            cout << "\nConverting both fractions to double:\n";
            cout << f1 << " to double: " << static_cast<double>(f1) << endl;
            cout << f2 << " to double: " << static_cast<double>(f2) << endl;
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nMultiplying both fractions:\n";
            cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
            cout << "\n-----------------------------------------------------------------\n";

            // Attempt to divide fractions, catching any division-by-zero error
            cout << "\nDividing both fractions:\n";
            try {
                cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
            }
            catch (const invalid_argument& e) {
                cerr << "DIVISION BY ZERO" << endl;
            }
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nAdding both fractions:\n";
            cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nSubtracting both fractions:\n";
            cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nNegating both fractions:\n";
            cout << "Negated value of " << f1 << " is " << -f1 << endl;
            cout << "Negated value of " << f2 << " is " << -f2 << endl;
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nReciprocal of both fractions:\n";
            try {
                cout << "The reciprocal of " << f1 << " is " << f1.reciprocal() << endl;
            }
            catch (const invalid_argument& e) {
                cerr << "DIVISION BY ZERO" << endl;
            }
            try {
                cout << "The reciprocal of " << f2 << " is " << f2.reciprocal() << endl;
            }
            catch (const invalid_argument& e) {
                cerr << "DIVISION BY ZERO" << endl;
            }
            cout << "\n-----------------------------------------------------------------\n";

            // Comparisons between the two fractions
            cout << "\nChecking if fractions are equalL:\n";
            cout << (f1 == f2 ? "Fractions are equal" : "Fractions are not equal") << endl;
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nChecking if fractions are different:\n";
            cout << (f1 != f2 ? "Fractions are different" : "Fractions are not different") << endl;
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nChecking if f1 is less than f2:\n";
            if (f1 < f2) {
                cout << f1 << " is less than " << f2 << endl;
            }
            else {
                cout << f1 << " is not less than " << f2 << endl;
            }
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nChecking if f1 is less than or equal to f2:\n";
            if (f1 <= f2) {
                cout << f1 << " is less than or equal to " << f2 << endl;
            }
            else {
                cout << f1 << " is not less than or equal to " << f2 << endl;
            }
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nChecking if f1 is greater than f2:\n";
            if (f1 > f2) {
                cout << f1 << " is greater than " << f2 << endl;
            }
            else {
                cout << f1 << " is not greater than " << f2 << endl;
            }
            cout << "\n-----------------------------------------------------------------\n";

            cout << "\nChecking if f1 is greater than or equal to f2:\n";
            if (f1 >= f2) {
                cout << f1 << " is greater than or equal to " << f2 << endl;
            }
            else {
                cout << f1 << " is not greater than or equal to " << f2 << endl;
            }
            cout << "\n-----------------------------------------------------------------\n";

            // Reassign fractions based on new user input
            cout << "\nASSIGNING A NEW VALUE TO A FRACTION:\n";
            cout << "Type a new value for f1: ";
            cin >> f1;
            cout << "Type a new value for f2: ";
            cin >> f2;
            cout << "\n-----------------------------------------------------------------\n";

            // Power operation on fractions
            int power;
            cout << "\nFractions to the power of n:\n";
            cout << "Please enter the power value: ";
            cin >> power;
            cout << f1 << " to the power of " << power << " is " << f1.exp(power) << endl;
            cout << f2 << " to the power of " << power << " is " << f2.exp(power) << endl;

            // Prompt for repeating the process
            cout << "\n=================================================================\n";
            cout << "WOULD YOU LIKE TO START OVER? YES -->(Press any key) : NO --> (Enter 0): ";
            cin >> choice;

        } while (choice != '0');

    }
    catch (const exception& e) {
        // Handle any unexpected exceptions
        cerr << "Error: " << e.what() << endl;
    }

    return 0;  // Exit program successfully
}
