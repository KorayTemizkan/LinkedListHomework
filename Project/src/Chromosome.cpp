


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

void Chromosome::Cross(int fnum1 , int fnum2)
{   
    int choice1 = 0 , choice2 = 0;
    int length1 = 0 , length2 = 0;
    string temp1="", temp2="" , sub1="" , sub2="" , sub3="" , sub4="" , res1 = "",res2="";
    
    if(fnum1 == 0 && fnum2 == 0)
    {
    cout << "Hangi satirlari caprazlamak istiyorsunuz ? (0-x)" << endl;
    cout << "1 : " << choice1 << endl;
    cin >> choice1;
    cout << "2 : " << choice2 << endl;
    cin >> choice2;
    }

    else
    {
        choice1 = fnum1;
        choice2 = fnum2;
    }
    // Mesela 3 ve 4'e erişelim
    // A C F Y U D K R (15 KARAKTER = %2 = 7.5)
    // M U A D T R     (11 KARAKTER = %2 = 5.5)

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



    length1 = pSel1->genes.length();
    length2 = pSel2->genes.length();



    if (length1%2!=0) // Toplam gen sayısı çift sayıysa
    {
        sub1 = pSel2->genes.substr(0,(length1/2)-1);
        sub2 = pSel2->genes.substr((length1/2)+1,length1);
    }

    /*
    else // Tek sayıysa
    {
        sub1 = pSel1->genes.substr(0,(length1/2));
    }
    */

    if (length2%2==0) // Çift sayıysa
    {
        sub3 = pSel2->genes.substr(0,(length2/2)-1);
        sub4 = pSel2->genes.substr((length2/2)+1,length2);
    }
    
    /*
    else // Tek sayıysa
    {
        sub2 = pSel2->genes.substr((length2/2-1),length2);
    }
    */



    res1 = sub1+sub4;
    res2 = sub2+sub3;



    Chromosome *pSel3 = pRoot;
    Chromosome *pNew1 = new Chromosome();
    Chromosome *pNew2 = new Chromosome();

    while (pSel3!=nullptr)
    {
        pSel3=pSel3->pNext;
    }
 
    pNew1->genes=res1;
    pNew2->genes=res2;
    pSel3->pNext = pNew1;
    pNew1->pNext = pNew2;
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

    // Mesela 2. satıra 3.sütun olsun (indis : 1)(indis : 3) , (D E V U)

    // 1 ÇIKARIP 2 İLE ÇARP
    // 0 2 4 6
    // D E V U
    
    pSel1->genes[(choiceCol-1)*2]='X';
}

void Chromosome::Automatic() // switch case mantıklı
{
    ifstream ReadFile("Islemler.txt");
    string myText;
    char operation = '\0';
    int num1 = 0 ,num2 =0;

    while (getline(ReadFile,myText))
    {
        operation = myText[0];
        num1 = myText[2];
        num2 = myText[4];
        
        if (operation=='C')
        {
            Cross(num1,num2);
        }

        if (operation=='M')
        {
            Mutation(num1,num2);
        }
    } 

    ReadFile.close();
}

void Chromosome::Print()
{
    ifstream ReadFile(("Dna.txt"));
    string myText;
    int length;
    string temp;
    
    while (getline(ReadFile,myText)) // A C F Y U D K R
    {
        length = myText.length();
        for (int i = length; i < 0; i--)
        {
            temp = myText[i];
            
            if(myText[i-1]<myText[i])
            {
                temp = myText[i];
            }
        }
        cout << temp << " ";
    }

    ReadFile.close();
}