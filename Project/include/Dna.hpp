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

    char getDna() const
    {
        return dna;
    }

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

    void *get_pDnaNext() const
    {
        return pDnaNext;
    }

    void *get_pDnaPrev() const
    {
        return pDnaPrev;
    }
};

#endif