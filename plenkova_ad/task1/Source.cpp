#include <iostream>
using namespace std;

class weight_converter
{
private:
    double weight;

public:
    void show_kg()
    {
        cout << "Weight in kg = " << weight << endl;
    }
    void set(double x)
    {
        weight = x;
    }
    double conv_carat()
    {
        double weight_1;
        weight_1 = weight * 5000;
        return weight_1;
    }
    double conv_g()
    {
        double weight_1;
        weight_1 = weight * 1000;
        return weight_1;
    }
    double conv_mg()
    {
        double weight_1;
        weight_1 = weight * 1000000;
        return weight_1;
    }
    double conv_oz()
    {
        double weight_1;
        weight_1 = weight * 35.27396194958048;
        return weight_1;
    }
    double conv_lb()
    {
        double weight_1;
        weight_1 = weight * 2.2046226218488;
        return weight_1;
    }
    double conv_ton()
    {
        double weight_1;
        weight_1 = weight * 0.001;
        return weight_1;
    }
};

int main()
{
    weight_converter mass1;
    double n;
    cout << "Enter the weight in kg: ";
    cin >> n;
    mass1.set(n);
    cout << "Print the value in kilograms?\n1)Yes\n2)No" << endl;
    int a;
    cin >> a;
    if (a == 1)
        mass1.show_kg();

    cout << "Choose weight system:\n1)carat\n2)gram\n3)milligram\n4)ounce\n5)lb.\n6)ton" << endl;
    int s;
    cin >> s;

    switch (s)
    {
    case(1):
        cout << "Weight in carat = " << mass1.conv_carat();
        break;
    case(2):
        cout << "Weight in gram = " << mass1.conv_g();
        break;
    case(3):
        cout << "Weight in milligram = " << mass1.conv_mg();
        break;
    case(4):
        cout << "Weight in ounce = " << mass1.conv_oz();
        break;
    case(5):
        cout << "Weight in lb = " << mass1.conv_lb();
        break;
    case(6):
        cout << "Weight in ton = " << mass1.conv_ton();
        break;
    }
    system("pause");
}

