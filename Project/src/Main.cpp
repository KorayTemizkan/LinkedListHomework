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
#include <string>
#include <chrono>

using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Chromosome chromosomeList;

    chromosomeList.AddListItemsFromText();

    int choice = 0;
    int temp1 = 0, temp2 = 0; 

    auto end = chrono::high_resolution_clock::now();

    auto sure = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << endl << "Dosyadan okuyup listeyi olusturma suresi : " << sure.count() << " milisaniye" << endl << endl;

    do
    {
        cout << "\n--- Chromosome Bagli Liste Programi ---" << endl << endl;
        cout << "1. Caprazlama islemi yap" << endl;
        cout << "2. Mutasyon islemi yap" << endl;
        cout << "3. Tum listeyi yazdir ( Kontrol icin )" << endl;
        cout << "4. Otomatik islemleri yap" << endl;
        cout << "5. Ekrana yaz ( Projede asil istenilen yontemle )" << endl;
        cout << "6. Cikis" << endl << endl;
        cout << "Seciminizi girin : ";
        cin >> choice;
        

        switch (choice)
        {
        case 1:
            cout << endl <<"Caprazlama islemi icin sifir ya da sifirdan büyük iki kromozom numarasi girin : " << endl;
            cin >> temp1 >> temp2;
            if (temp1 >= 0 && temp2 >= 0)
            {
                chromosomeList.Cross(temp1, temp2);
            }
            else
            {
                cout << endl<< "Sifirdan buyuk girdiler veriniz" << endl;
            }

            break;

        case 2:
            cout << endl <<"Mutasyon islemi icin sifir ya da sifirdan buyuk kromozom ve gen numaralarini giriniz : " << endl;
            cin >> temp1 >> temp2;
            if (temp1 >= 0 && temp2 >= 0)
            {
                chromosomeList.Mutation(temp1, temp2);
            }
            else
            {
                cout << endl << "Sifirdan buyuk girdiler veriniz" << endl;
            }

            break;

        case 3:
            chromosomeList.TestPrint();
            break;

        case 4:
            chromosomeList.Automatic();
            cout << endl << "BILGI : Otomotik islemler yapildi" << endl;
            break;

        case 5:
            cout << endl << "BILGI : Liste hazirlandi : ";
            chromosomeList.Print();
            break;

        case 6:
            cout << endl << "BILGI : Yikici fonksiyonla kromozomlarin icindeki dna listesi ve genel kromozom listesi silindi , programdan cikiliyor..." << endl << endl;
            break;

        default:
            cout << endl << "BILGI : 1-6 arasi rakamlar giriniz ! Lutfen tekrar deneyin ." << endl;
            break;
        }

        cout << endl << "Devam etmek icin enter tusuna basiniz. " << endl << endl << "--------------------------------------------------" << endl;
        cin.ignore(); 
        cin.get();

    } while (choice != 6);

    return 0;
}