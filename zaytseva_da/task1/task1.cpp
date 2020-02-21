#include <iostream>
using namespace std;

class weightkg
{
private:
    double weight = 0;
public:

    void weightnow()
    {
        do
        {
            cout << "Please enter the weight you want to work with (kg)\n";
            cin >> weight;
            if (weight < 0) cout << "Yours weight is less than zero. Please try again:\n\n";
        } while (weight < 0);
        cout << "weight now:" << weight << "kg\n\n";
    }

    void print()
    {
        std::cout << "weight now:" << weight << " kg\n\n" << std::endl;
    }

    void kg_oz()
    {
        double weightoz;
        weightoz = weight * 35.27;
        cout << "Result:" << weight << "kg =  " << weightoz << " ounces'\n\n";
    }

    void kg_pound()
    {
        double weightpo;
        weightpo = weight * 2.2;
        cout << "Result:" << weight << "kg =  " << weightpo << " pounds'\n\n";
    }

    void kg_stone()
    {
        double weightst;
        weightst = weight * 0.16;
        cout << "Result:" << weight << "kg =  " << weightst << " stones'\n\n";
    }

    void kg_ruspound()
    {
        double weightrus;
        weightrus = weight * 2.44;
        cout << "Result:" << weight << "kg =  " << weightrus << " russian pounds'\n\n";
    }
    void kg_carat()
    {
        double weightcar;
        weightcar = weight * 5000;
        cout << "Result:" << weight << "kg =  " << weightcar << " carats'\n\n";
    }
    void kg_apothecarypound()
    {
        double weightapo;
        weightapo = weight * 2.68;
        cout << "Result:" << weight << "kg =  " << weightapo << " apothecary pounds'\n\n";
    }
};

int main()
{
    weightkg a;
    int mainchoice;
    int choice;
    while (true)
    {
        do
        {
            cout << "Please select an action\n 1) find out the current weight\n 2) Set a new weight\n 3) Transfer to another measure of weight\n 4) Exit\n";
            cin >> mainchoice;
            if (mainchoice < 1 || mainchoice > 4) cout << "You entered the wrong answer.\nPlease try again:\n\n";
        } while (mainchoice < 1 || mainchoice > 4);

        switch (mainchoice)
        {
        case 1:
            a.print();
            break;
        case 2:
            a.weightnow();
            break;
        case 3:
            do
            {
                cout << "in what measure of weight do you want to transfer?\n 1) ounce\n 2) pound\n 3) stone\n 4) russian pound\n 5) carat\n 6) apothecary pound\n";
                cin >> choice;
                if (choice < 1 || choice > 6) cout << "You entered the wrong answer.\nPlease try again:\n\n";
            } while (choice < 1 || choice > 6);

            switch (choice)
            {
            case 1:
                a.kg_oz();
                break;
            case 2:
                a.kg_pound();
                break;
            case 3:
                a.kg_stone();
                break;
            case 4:
                a.kg_ruspound();
                break;
            case 5:
                a.kg_carat();
                break;
            case 6:
                a.kg_apothecarypound();
                break;
            }
            break;
        case 4:
            return 0;
            break;
        }
    }
}