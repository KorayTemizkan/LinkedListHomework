#include "Chromosome.hpp"

Chromosome::Chromosome()
{
    pNext = nullptr;
    pPrev = nullptr;

    pRoot = nullptr;
    pTail = nullptr;

    pDnaRoot = nullptr;
    pDnaTail = nullptr;
}

void Chromosome::AddListItemsFromText()
{
    ifstream ReadFile("Dna.txt");
    char myDna;

        if (pRoot == nullptr)
        {
            pRoot = new Chromosome();
        }
        
        Chromosome *pSel1 = pRoot;
        Dna *pDnaSel1 = new Dna();
        int control = 0;

        while (ReadFile.get(myDna))
        {
            if(control%2==0)
            {

                if(myDna == '\n')
                {
                    Chromosome *pSel2 = new Chromosome();
                    pSel1->pNext=pSel2;
                    pSel2->pPrev=pSel1;
                    pSel1=pSel2;
                }
  
                if (pSel1->pDnaRoot == nullptr)
                {
                    pDnaSel1 = pSel1->pDnaRoot;
                    pDnaSel1 = pSel1->pDnaTail;
                    pDnaSel1->setDna(myDna);
                    control++;
                }

                else
                {
                    Dna *pDnaSel2 = new Dna();
                    pDnaSel1->set_pDnaNext(pDnaSel2);
                    pDnaSel2->set_pDnaPrev(pDnaSel2);
                    pDnaSel2->setDna(myDna);
                    pDnaSel2 = pSel1->pDnaTail;
                }

            }
 
            control++;
        }

    ReadFile.close();
}

void Chromosome::Cross(int fnum1 , int fnum2)
{   
    int choice1 = 0 , choice2 = 0;
    int length1 = 0 , length2 = 0;
    
    if(fnum1 == 0 && fnum2 == 0)
    {
        cout << "Hangi satirlari caprazlamak istiyorsunuz ? (0-x)" << endl;
        cout << "1 : " << choice1 << endl;
        cin >> choice1; // 2
        cout << "2 : " << choice2 << endl;
        cin >> choice2; // 3
    }

    else
    {
        choice1 = fnum1;
        choice2 = fnum2;
    }

    Chromosome *pSel1 = pRoot;
    for (int i = 1; i = choice1; i++)
    {
        pSel1 = pSel1->pNext;
    }
    
    Dna *pDna1 = pSel1->pDnaRoot;
    while (pDna1->get_pDnaNext()!= nullptr)
    {
        length1++;
        pDna1 = pDna1->get_pDnaNext();
    }
    
    Chromosome *pSel2 = pRoot;
    for (int i = 1; i = choice2; i++)
    {
        pSel2 = pSel2->pNext;
    }

    Dna *pDna2 = pSel2->pDnaRoot;
    while (pSel2->pDnaRoot->get_pDnaNext() != nullptr)
    {
        length2++;
        pDna2 = pDna2->get_pDnaNext();
    }

    Chromosome *pNewCross1 = new Chromosome;
    Chromosome *pNewCross2 = new Chromosome;

    if (length1 % 2 != 0 && length2 % 2 == 0)
    {
        length1 = length1/2 - 1;
        pDna1 = pSel1->pDnaRoot;                // ana dna'daki kromozom dnaları
        Dna *pSelCross1 = pNewCross1->pDnaRoot; // yeni oluşturulacak kromozom dnaları

        for (int i = 1; i = length1; i++)
        {
            pSelCross1->setDna(pDna1->getDna());
            pDna1 = pDna1->get_pDnaNext();
            pSelCross1 = pSelCross1->get_pDnaNext();
        }   


        pDna2 = pSel2->pDnaRoot;

        for (int i = 0; i = (length2/2); i++)
        {
            pDna2 = pDna2->get_pDnaNext();
        }
        
        for (int i = 1; i = length2; i++)
        {
            pSelCross1->get_pDnaNext()->setDna(pDna2->getDna());
        }

        pTail->pNext = pNewCross1;
        pNewCross1->pPrev = pTail;
        pTail = pNewCross1;
    }   
}

void Chromosome::Mutation(int fnum1 , int fnum2)
{
    int choiceRow = 0 , choiceCol = 0;

    cout << "Sirasiyla mutasyona uğratmak istediğiniz kromozomun satir ve sutun numarasini giriniz." << endl;
    cout << "1 : " << choiceRow << endl;
    cin >> choiceRow;
    cout << "2 : " << choiceCol << endl;
    cin >> choiceCol;

    Chromosome *pSel1 = pRoot;
    for (int i = 0; i < choiceRow; i++)
    {
        pSel1 = pSel1->pNext;
    }

    Dna *pDna1 = pSel1->pDnaRoot;
    for (int i = 0; i < choiceCol; i++)
    {
        pDna1 = pDna1->get_pDnaNext();
        pDna1->setDna('X');
    }
}

void Chromosome::Automatic() // switch case mantıklı
{
    ifstream ReadFile("Islemler.txt");
    char operation = '\0' , myOperation;
    int num1 = 0 ,num2 = 0, control = 0;

    while (ReadFile.get(myOperation)) // C 1 3
    {
        if (control == 0)
        {
            operation = myOperation;
        }

        if(control == 3)
        {
            num1 = myOperation;
        }

        if (control == 5)
        {
            num2 = myOperation;
        }

        if (control == '\n')
        {
            if (operation == 'C')
            {           
                Chromosome::Cross(num1 , num2);
            }
            
            else if (operation == 'M')
            {
                Chromosome::Mutation(num1 , num2);
            }
            
            control = 0;
        }  
    } 

    ReadFile.close();
}

void Chromosome::Print()
{
    ifstream ReadFile(("Dna.txt"));
    int length = 0;
    char dna1 = '\0' , dna2 = '\0', mainDna = '\0';

    Chromosome *pSel = pRoot;
    Dna *pDna = pSel->pDnaTail;

    while (pSel->pNext != nullptr)
    {
        while (!pSel->pDnaRoot)
        {
            dna1 = pDna->getDna();
            dna2 = pDna->get_pDnaPrev()->getDna();
            
            if (dna2 > dna1)
            {
                mainDna = dna2;
            }

            pDna = pDna->get_pDnaPrev();
        }
        cout << mainDna << " ";

        pSel = pSel->pNext;
    }
    
    ReadFile.close();
}