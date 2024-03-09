// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void Welcome() {
    cout << "Hello World!\n";
    cout << "Input your name: ";
    string a;
    cin >> a;
    cout << "Welcome to C++, " << a << "!\n";
}


void QuadraticEquation(double a, double b, double c) {
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
		cout << "No real solution\n";
	}
    else if (delta == 0) {
		cout << "x = " << -b / (2 * a) << "\n";
	}
    else {
		cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\n";
		cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << "\n";
	}

}


int main()
{
    
    Welcome();

    // Quadratic equation
    QuadraticEquation(1, 6, 8);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
