// weight2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "locale.h"
#include "string"
#include "Vec.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    string Arrmeasure[] = { "kg","pound","troy" };
    Vec Apple;
    cout << "Apple: " << Apple << endl;
    Vec Limon(3);
    cout << "Limon: " << Limon << endl;
    Vec Banana(5, troy);
    cout << "Banana: " << Banana << endl;
    Apple = Banana;
    cout << "Apple: " << Apple << endl;
    Apple.Setv(15);
    cout << "Apple: " << Apple << endl;
    cout << "Вес Apple " << Apple.Getv() << " " << Arrmeasure[Apple.GettypeV()] << endl;
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
