#include "Chromosome.hpp"
#include <iostream>

using namespace std;

int main()
{
    Chromosome chromosomeList;

    chromosomeList.AddListItemsFromText();

    int choice;
    int temp1 = 0, temp2 = 0; 

    do
    {
        cout << "\n--- Chromosome Programi ---" << endl;
        cout << "1. Crossover islemi yap" << endl;
        cout << "2. Mutasyon islemi yap" << endl;
        cout << "3. Listeyi yazdir" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminizi girin: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Crossover islemi icin iki indeks girin (temp1 temp2): ";
            cin >> temp1 >> temp2;
            chromosomeList.Cross(temp1, temp2);
            break;

        case 2:
            cout << "Mutasyon islemi icin iki indeks girin (temp1 temp2): ";
            cin >> temp1 >> temp2;
            chromosomeList.Mutation(temp1, temp2);
            break;

        case 3:
            chromosomeList.Print();
            break;

        case 4:
            cout << "Programdan cikiliyor..." << endl;
            break;

        default:
            cout << "Gecersiz secim! Lutfen tekrar deneyin." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
