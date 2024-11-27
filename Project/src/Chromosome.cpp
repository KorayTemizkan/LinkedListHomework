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
    ifstream ReadFile("/home/koray/Desktop/Ders/Veri Yapıları/Odev1.1/Project/Dna.txt");

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
    if (fnum1 == -1 && fnum2 == -1)
    {
        cout << "Hangi satirlari caprazlamak istiyorsunuz ? (0-x)" << endl;
        cout << "1: ";
        cin >> choice1;
        cout << "2: ";
        cin >> choice2;
    }

    Chromosome *pSel1 = pRoot;
    for (int i = 0; i < choice1; i++)
    {
        pSel1 = pSel1->pNext;
    }

    Chromosome *pSel2 = pRoot;
    for (int i = 0; i < choice2; i++)
    {
        pSel2 = pSel2->pNext;
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

    if (length1 % 2 != 0) mid1++; 
    if (length2 % 2 != 0) mid2++; 

    Dna *pLeft1 = pSel1->pDnaRoot;
    for (int i = 0; i < mid1; i++)
    {
        pLeft1 = pLeft1->get_pDnaNext();
    }

    Dna *pRight2 = pSel2->pDnaRoot;
    for (int i = 0; i < mid2; i++)
    {
        pRight2 = pRight2->get_pDnaNext();
    }

    Chromosome *pCross1 = new Chromosome();
    Chromosome *pCross2 = new Chromosome();

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

    pDna1 = pLeft1;
    pDna2 = pSel2->pDnaRoot;
    while (pDna2 != pRight2)
    {
        Dna *newDna = new Dna();
        newDna->setDna(pDna2->getDna());
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
        pDna2 = pDna2->get_pDnaNext();
    }

    while (pDna1 != nullptr)
    {
        Dna *newDna = new Dna();
        newDna->setDna(pDna1->getDna());
        pCross2->pDnaTail->set_pDnaNext(newDna);
        newDna->set_pDnaPrev(pCross2->pDnaTail);
        pCross2->pDnaTail = newDna;
        pDna1 = pDna1->get_pDnaNext();
    }

    Chromosome *pTail = pRoot;
    while (pTail->pNext != nullptr)
    {
        pTail = pTail->pNext;
    }

    pTail->pNext = pCross1;
    pCross1->pPrev = pTail;

    pCross1->pNext = pCross2;
    pCross2->pPrev = pCross1;
}


void Chromosome::Mutation(int fnum1 , int fnum2)
{
    int choiceRow = fnum1 , choiceCol = fnum2;
    if (fnum1 == -1 && fnum2 == -1)
    {
        cout << "Kacinci kromozomun kacinci satirini X yapmak istersiniz?" << endl;
        cout << "1 : ";
        cin >> choiceRow;
        cout << "2 : ";
        cin >> choiceCol;
    }

    Chromosome *pSel = pRoot;
    for (int i = 0; i < choiceRow; i++)
    {
        pSel = pSel->pNext;
    }

    Dna *pDna = pSel->pDnaRoot;
    for (int i = 0; i < choiceCol; i++)
    {
        pDna = pDna->get_pDnaNext();
    }

    pDna->setDna('X');

    pDna = pSel->pDnaRoot;
    while (pDna != pSel->pDnaTail)
    {
        pDna=pDna->get_pDnaNext();
    }
}

void Chromosome::Automatic()
{
    ifstream ReadFile("/home/koray/Desktop/Ders/Veri Yapıları/Odev1.1/Project/Islemler.txt");
    char operation = '0', myOperation = '0';
    int num1 = 0, num2 = 0, control = 0;

    while (ReadFile.get(myOperation))
    {
        switch (control)
        {
            case 0: 
                operation = myOperation;
                break;

            case 2:
                num1 = myOperation - '0'; 
                break;

            case 4: 
                num2 = myOperation - '0';
                break;

            default:
                if (myOperation == '\n')
                {
                    if (operation == 'C')
                    {
                        Chromosome::Cross(num1, num2); 
                    }
                    else if (operation == 'M')
                    {
                        Chromosome::Mutation(num1, num2); 
                    }

                    control = -1; 
                }
                break;
        }
        control++;
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
                cout << dna2 << endl;
                break;
            }

            pDna = pDna->get_pDnaPrev();
        }

        if (pDna == pSel->pDnaRoot)
        {
            cout << dna1 << endl;
        }
        
        pSel = pSel->pNext;
    }
}

void Chromosome::TestPrint()
{
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