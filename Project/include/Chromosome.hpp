#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

class Chromosome
{
private:
    string genes;
    
    Chromosome *pNext;
    Chromosome *pPrev;

public:
    Chromosome *pRoot = nullptr;

    Chromosome();

    void AddListItemsFromText();

    void Cross();

    void Mutation();

    void PrintAll(); 

    void DeleteAll();
};

#endif