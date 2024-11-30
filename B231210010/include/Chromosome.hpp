/**
* Dosya adı = Chromosome.hpp  
* Bu dosya Chromosome sınıf yapisi , bu sınıf icin gereken değişkenleri ve fonksiyonların prototiplerini tanimlamak icin kullanilir.
* 1. Ogretim A grubu
* 1. Odev
* 27/11/2024 Çarşamba
* Koray Temizkan - koray.temizkan@ogr.sakarya.edu.tr
*/

#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <iostream>
#include <fstream>
#include <Dna.hpp>

using namespace std;

class Chromosome
{
private:
    Chromosome *pNext;
    Chromosome *pPrev;

    Dna *pDnaRoot;
    Dna *pDnaTail;

public:
    Chromosome();

    ~Chromosome();

    void AddListItemsFromText();

    void Cross(int fnum1 , int fnum2);

    void Mutation(int fnum1 , int fnum2);

    void Automatic();

    void Print();

    void TestPrint();
};

#endif