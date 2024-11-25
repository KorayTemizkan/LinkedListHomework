#ifndef DNA_HPP
#define DNA_HPP

#include <iostream>
#include <fstream>
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

    void *setDna(char d)
    {
        dna = d;
    }
 
    void *set_pDnaNext(Dna *pSelNext)
    {
        pDnaNext = pSelNext;
    }

    void *set_pDnaPrev(Dna *pSelPrev)
    {
        pDnaPrev = pSelPrev;
    }

    char getDna()
    {
        return dna;
    }

    Dna *get_pDnaNext()
    {
        return pDnaNext;
    }

    Dna *get_pDnaPrev()
    {
        return pDnaPrev;
    }
};

#endif