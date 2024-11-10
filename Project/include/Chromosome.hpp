#ifndef CHROMOSOME_HPP
#define CHROMOSOME_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct Node {
    char data;   
    Node* next;  
}; // BUNA DAHA SONRA BAK

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

    void ConvertChar();

    void Cross(int fnum1 , int fnum2);

    void Mutation(int fnum1 , int fnum2);

    void PrintAll(); 

    void DeleteAll();

    void Automatic();

    void Print();
};

#endif