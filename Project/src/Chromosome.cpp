#include "Chromosome.hpp"

Chromosome::Chromosome()
{
    pNext = nullptr;
    pPrev = nullptr;
}

void Chromosome::AddListItemsFromText()
{
        ifstream ReadFile("Dna.txt");
        string myText;

        if (pRoot == nullptr)
        {
            pRoot = new Chromosome();
        }
        
        Chromosome *pSel1 = pRoot;

        while (getline(ReadFile, myText))
        {
            Chromosome *pSel2 = new Chromosome();
            pSel2->genes = myText;

                pSel1->pNext = pSel2; 
                pSel2->pPrev = pSel1; 
                pSel2->pNext = NULL;
            
            pSel1 = pSel2;
        }

        ReadFile.close();
}

void Chromosome::PrintAll()
{
    Chromosome *pSel = pRoot;

    while (pSel != nullptr)
    {
        cout << pSel->genes << endl;
        pSel = pSel->pNext;
    }
    
}

void Chromosome::DeleteAll()
{
    Chromosome *pSel = pRoot;
    
    while (pSel != nullptr)
    {
        pRoot = pSel->pNext;
        free(pSel);
        pSel = pRoot;
    }
}

