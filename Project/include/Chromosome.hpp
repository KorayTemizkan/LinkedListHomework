#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Dna.hpp"

using namespace std;

class Chromosome
{
private:
    Chromosome *pNext;
    Chromosome *pPrev;

    Chromosome *pRoot;
    Chromosome *pTail;

    Dna *pDnaRoot;
    Dna *pDnaTail;

public:
    Chromosome();

    void AddListItemsFromText();

    void ConvertChar();

    void Cross(int fnum1 , int fnum2);

    void Mutation(int fnum1 , int fnum2);

    void Automatic();

    void Print();
};

// bu fonksiyonları ve pRoot-pTail kaldır
#endif