/**
* Dosya adı = Dna.hpp  
* Bu dosya Dna sınıf yapisi , bu sınıf icin gereken değişkenleri ve fonksiyonların prototiplerini tanimlamak icin kullanilir.
* 1. Ogretim A grubu
* 1. Odev
* 27/11/2024 Çarşamba
* Koray Temizkan - koray.temizkan@ogr.sakarya.edu.tr
*/

#ifndef DNA_HPP
#define DNA_HPP

#include <iostream>
#include <string>

using namespace std;

class Dna
{
private:
    char dna;
    Dna *pDnaNext;
    Dna *pDnaPrev;

public:
    Dna();

    void setDna(char d);

    char getDna();
 
    void set_pDnaNext(Dna *pSelNext);

    void set_pDnaPrev(Dna *pSelPrev);

    Dna *get_pDnaNext();

    Dna *get_pDnaPrev();
};

#endif