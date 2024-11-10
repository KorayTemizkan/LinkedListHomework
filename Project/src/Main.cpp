#include "Chromosome.hpp"


int main()
{
    Chromosome chromosomeList;

    chromosomeList.AddListItemsFromText();

    chromosomeList.PrintAll();

    // chromosomeList.DeleteAll();

    int temp1 = 0 , temp2= 0;
    chromosomeList.Cross(temp1,temp2);

    return 0;
}