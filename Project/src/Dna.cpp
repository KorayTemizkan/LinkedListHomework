/**
* Dosya adı = Dna.cpp  
* Bu dosya Dna sınıfı için gereken fonksiyonların gövdelerini tutar
* 1. Ogretim A grubu
* 1. Odev
* 27/11/2024 Çarşamba
* Koray Temizkan - koray.temizkan@ogr.sakarya.edu.tr
*/

#include "Dna.hpp"

Dna::Dna()
{
    dna = '0';
    pDnaNext = nullptr;
    pDnaPrev = nullptr;
}

void Dna::setDna(char d)
{
    dna = d;
}

void Dna::set_pDnaNext(Dna *pSelNext)
{
    pDnaNext = pSelNext;
}

void Dna::set_pDnaPrev(Dna *pSelPrev)
{
    pDnaPrev = pSelPrev;
}

char Dna::getDna()
{
    return dna;
}

Dna *Dna::get_pDnaNext()
{
    return pDnaNext;
}

Dna *Dna::get_pDnaPrev()
{
    return pDnaPrev;
}