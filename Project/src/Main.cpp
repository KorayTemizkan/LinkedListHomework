/**
* Dosya adı = Main.cpp  
* Bu dosya main fonksiyonunun bulunduğu yerdir.
* 1. Ogretim A grubu
* 1. Odev
* 27/11/2024 Çarşamba
* Koray Temizkan - koray.temizkan@ogr.sakarya.edu.tr
*/

#include "Chromosome.hpp"
#include "Dna.hpp"
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Chromosome chromosomeList;

    chromosomeList.AddListItemsFromText();

    int choice = 0;
    int temp1 = -1, temp2 = -1; 

    auto end = chrono::high_resolution_clock::now();

    auto sure = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << endl << "Dosyadan okuyup listeleri olusturma suresi : " << sure.count() << " milisaniye" << endl << endl;

    do
    {
        cout << "\n--- Chromosome Programi ---" << endl;
        cout << "1. Crossover islemi yap" << endl;
        cout << "2. Mutasyon islemi yap" << endl;
        cout << "3. Tum listeyi yazdir ( Kontrol icin )" << endl;
        cout << "4. Otomatik islemleri yap" << endl;
        cout << "5. Ekrana yaz ( Projede asil istenilen )" << endl;
        cout << "6. Cikis" << endl << endl;
        cout << "Seciminizi girin: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Caprazlama islemi icin sifir ya da sifirdan büyük iki kromozom numarasi girin : ";
            cin >> temp1 >> temp2;
            chromosomeList.Cross(temp1, temp2);
            break;

        case 2:
            cout << "Kacinci kromozomun kacinci satirini X yapmak istersiniz ? : " << endl;
            cin >> temp1 >> temp2;
            chromosomeList.Mutation(temp1, temp2);
            break;

        case 3:
            chromosomeList.TestPrint();
            break;

        case 4:
            chromosomeList.Automatic();
            break;

        case 5:
            chromosomeList.Print();
            break;

        case 6:
            cout << "Programdan cikiliyor..." << endl;
            break;

        default:
            cout << "Gecersiz sayi ! Lutfen tekrar deneyin ." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}