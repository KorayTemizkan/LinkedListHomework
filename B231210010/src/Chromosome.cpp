/**
* Dosya adı = Chromosome.cpp 
* Bu dosya Chromosome sınıfı için gereken fonksiyonların gövdelerini tutar
* 1. Ogretim A grubu
* 1. Odev
* 27/11/2024 Çarşamba
* Koray Temizkan - koray.temizkan@ogr.sakarya.edu.tr
*/


#include "Chromosome.hpp"
#include "Dna.hpp"


Chromosome::Chromosome()
{
    pNext = nullptr;
    pPrev = nullptr;

    pDnaRoot = nullptr;
    pDnaTail = nullptr;
}

Chromosome *pRoot = new Chromosome();

void Chromosome::AddListItemsFromText()
{
    ifstream ReadFile("./Dna.txt");

    if (!ReadFile)
    {
        cerr << "Dosya acilirken bir hata oluştu." << endl;
        return;
    }

    char myDna;
    Chromosome *pSel1 = pRoot;

    while (ReadFile.get(myDna))
    {
        if (myDna != 32 && myDna != '\n')
        {
            Dna *pNewDna = new Dna();
            pNewDna->setDna(myDna);

            if (pSel1->pDnaRoot == nullptr)
            {
                pSel1->pDnaRoot = pNewDna;
                pSel1->pDnaTail = pNewDna;
            }

            else
            {
                pSel1->pDnaTail->set_pDnaNext(pNewDna);
                pNewDna->set_pDnaPrev(pSel1->pDnaTail);
                pSel1->pDnaTail = pNewDna;
            }
        }

        if (myDna == '\n')
        {
            Chromosome *pNewChromosome = new Chromosome();
            pSel1->pNext = pNewChromosome;
            pNewChromosome->pPrev = pSel1;
            pSel1 = pNewChromosome;
        }
    }
    ReadFile.close();
}

void Chromosome::Cross(int fnum1, int fnum2)
{
    int choice1 = fnum1, choice2 = fnum2;

    Chromosome *pSel1 = pRoot;
    for (int i = 0; i < choice1; i++)
    {
        pSel1 = pSel1->pNext;

        if (pSel1 == nullptr)
        {
            cout << endl << "BILGI : Ilgili kromozom bulunamadi. Tekrar deneyiniz." << endl;
            return;
        }
    }

    Chromosome *pSel2 = pRoot;
    for (int i = 0; i < choice2; i++)
    {
        pSel2 = pSel2->pNext;

        if (pSel2 == nullptr)
        {
            cout << endl << "BILGI : Ilgili kromozom bulunamadi. Tekrar deneyiniz." << endl;
            return;
        }
    }

    int length1 = 0, length2 = 0;

    Dna *pDna1 = pSel1->pDnaRoot;
    while (pDna1 != nullptr)
    {
        length1++;
        pDna1 = pDna1->get_pDnaNext();
    }

    Dna *pDna2 = pSel2->pDnaRoot;
    while (pDna2 != nullptr)
    {
        length2++;
        pDna2 = pDna2->get_pDnaNext();
    }
    
    int mid1 = length1 / 2;
    int mid2 = length2 / 2;

    if (length2 % 2 != 0) mid2++;

    Dna *pLeft1 = pSel1->pDnaRoot;
    for (int i = 0; i < mid1; i++)
    {
        pLeft1 = pLeft1->get_pDnaNext();
    }

    Dna *pRight1 = pLeft1;

    Dna *pLeft2 = pSel2->pDnaRoot;
    for (int i = 0; i < mid2; i++)
    {
        pLeft2 = pLeft2->get_pDnaNext();
    }

    Dna *pRight2 = pLeft2;

    Chromosome *pCross1 = new Chromosome();
    pDna1 = pSel1->pDnaRoot;
    while (pDna1 != pLeft1)
    {
        Dna *newDna = new Dna();
        newDna->setDna(pDna1->getDna());
        if (pCross1->pDnaRoot == nullptr)
        {
            pCross1->pDnaRoot = newDna;
            pCross1->pDnaTail = newDna;
        }
        else
        {
            pCross1->pDnaTail->set_pDnaNext(newDna);
            newDna->set_pDnaPrev(pCross1->pDnaTail);
            pCross1->pDnaTail = newDna;
        }
        pDna1 = pDna1->get_pDnaNext();
    }

    pDna2 = pRight2;
    while (pDna2 != nullptr)
    {
        Dna *newDna = new Dna();
        newDna->setDna(pDna2->getDna());
        pCross1->pDnaTail->set_pDnaNext(newDna);
        newDna->set_pDnaPrev(pCross1->pDnaTail);
        pCross1->pDnaTail = newDna;
        pDna2 = pDna2->get_pDnaNext();
    }

    Chromosome *pCross2 = new Chromosome();
    pDna1 = pRight1;
    while (pDna1 != nullptr)
    {
        Dna *newDna = new Dna();
        newDna->setDna(pDna1->getDna());
        if (pCross2->pDnaRoot == nullptr)
        {
            pCross2->pDnaRoot = newDna;
            pCross2->pDnaTail = newDna;
        }
        else
        {
            pCross2->pDnaTail->set_pDnaNext(newDna);
            newDna->set_pDnaPrev(pCross2->pDnaTail);
            pCross2->pDnaTail = newDna;
        }
        pDna1 = pDna1->get_pDnaNext();
    }
    pDna2 = pSel2->pDnaRoot;
    while (pDna2 != pLeft2)
    {
        Dna *newDna = new Dna();
        newDna->setDna(pDna2->getDna());
        pCross2->pDnaTail->set_pDnaNext(newDna);
        newDna->set_pDnaPrev(pCross2->pDnaTail);
        pCross2->pDnaTail = newDna;
        pDna2 = pDna2->get_pDnaNext();
    }

    Chromosome *pTail = pRoot;
    while (pTail->pNext != nullptr)
    {
        pTail = pTail->pNext;
    }

    if (length2 % 2 != 0 && length1 %2 != 0)
    {
        Dna *oldRoot = pCross2->pDnaRoot;
        pCross2->pDnaRoot = pCross2->pDnaRoot->get_pDnaNext();
        pCross2->pDnaRoot->set_pDnaPrev(nullptr);
        delete oldRoot;  
    
        Dna *oldTail = pCross2->pDnaTail;
        pCross2->pDnaTail = pCross2->pDnaTail->get_pDnaPrev();
        pCross2->pDnaTail->set_pDnaNext(nullptr);
        delete oldTail;  
    }

    if (length1 %2 != 0 && length2 %2 == 0)
    {
        Dna *oldRoot = pCross2->pDnaRoot;
        pCross2->pDnaRoot = pCross2->pDnaRoot->get_pDnaNext();
        pCross2->pDnaRoot->set_pDnaPrev(nullptr);
        delete oldRoot;  
    }
    

    
    pTail->pNext = pCross1;
    pCross1->pPrev = pTail;

    pCross1->pNext = pCross2;
    pCross2->pPrev = pCross1;

    cout << endl << "BILGI : Caprazlama islemi yapildi" << endl;
}

void Chromosome::Mutation(int fnum1 , int fnum2)
{
    int choiceRow = fnum1 , choiceCol = fnum2;

    Chromosome *pSel = pRoot;
    for (int i = 0; i < choiceRow; i++)
    {
        pSel = pSel->pNext;

        if (pSel == nullptr)
        {
            cout << endl << "BILGI : Ilgili kromozom bulunamadi. Tekrar deneyiniz." << endl;
            return;
        }
    }

    Dna *pDna = pSel->pDnaRoot;
    for (int i = 0; i < choiceCol; i++)
    {
        pDna = pDna->get_pDnaNext();

        if (pDna == nullptr)
        {
            cout << endl << "BILGI : Ilgili dna bulunamadi. Tekrar deneyiniz." << endl;
            return;
        }
        
    }
    
    pDna->setDna('X');

    pDna = pSel->pDnaRoot;
    while (pDna != pSel->pDnaTail)
    {
        pDna=pDna->get_pDnaNext();
    }

     cout << endl << "BILGI : Mutasyon islemi yapildi" << endl;
}


void Chromosome::Automatic()
{
    ifstream ReadFile("./Islemler.txt");
    
    if (ReadFile.is_open())
    {
        char operation;
        int num1 = 0, num2 =0;

        while(ReadFile.get(operation))
        {
            if(operation == 'C')
            {
                ReadFile >> num1;
                ReadFile >> num2;
                Chromosome::Cross(num1, num2);
                cout << endl;
            }

            else if(operation == 'M')
            {
                ReadFile >> num1;
                ReadFile >> num2;
                Chromosome::Mutation(num1, num2);
                cout << endl;
            }
        }
    }    

    else    
    {
        cout << "Dosya acilamadi." << endl;
    }

    ReadFile.close();
}

void Chromosome::Print()
{
    char dna1 = '0', dna2 = '0';
    
    Chromosome *pSel = pRoot;
    while (pSel != nullptr)
    {
        dna1 = pSel->pDnaRoot->getDna();
        Dna *pDna = pSel->pDnaTail;

        while (pDna != pSel->pDnaRoot)
        {
            dna2 = pDna->getDna();
            
            if (dna2 < dna1)
            {
                cout << dna2 << " ";
                break;
            }

            pDna = pDna->get_pDnaPrev();
        }

        if (pDna == pSel->pDnaRoot)
        {
            cout << dna1 << " ";
        }
        
        pSel = pSel->pNext;
    }

    cout << endl;
}

void Chromosome::TestPrint()
{
    cout << endl;
    
    Chromosome *pSel = pRoot;
    while (pSel != nullptr)
    {
        Dna *pDnaSel = pSel->pDnaRoot;
        while (pDnaSel != nullptr)
        {
            cout << pDnaSel->getDna();
            pDnaSel = pDnaSel->get_pDnaNext();

            if (pDnaSel != nullptr)
            {
                cout << " ";
            }
        }

        cout << endl;
        pSel = pSel->pNext;
    }
}

Chromosome::~Chromosome()
{
    Chromosome *pDel = pRoot;

    while (pDel != nullptr)
    {
        Dna *pDnaDel = pDel->pDnaRoot;
        while (pDnaDel != nullptr)
        {
            pDel->pDnaRoot = pDnaDel->get_pDnaNext();
            delete pDnaDel;
            pDnaDel = pDel->pDnaRoot;
        }

        pRoot= pDel->pNext;
        delete pDel;
        pDel = pRoot;
    }

    pRoot  = nullptr;
}