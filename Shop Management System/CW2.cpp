/*/-------------------------------------------------
        Name            : K.H.N.L.Fernando
        Index Number    : CODSE202F-040
-------------------------------------------------/*/

// Item Numbers must only contain numbers.
// When typing the Item Name use underscore instead of space.

//header Files
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>

using namespace std;

//global declaration for stream object
ofstream outf;
ifstream inf;

//----------------------------Item Class----------------------------
class Item
{   protected:
        int itemno;
        char name[40];
        float price;
    public:
        void getDetails();

};
Item itm; //created item object


void Item::getDetails()
{   cout<<"\n\t(!Use numbers for Item Numbers, Use underscore instead of space for Item Name!)\n\n";
    cout<<"\n\tItem No    : "; cin>>itemno;
    cout<<"\tItem Name  : "; cin>>name;
    cout<<"\tPrice      : "; cin>>price;
}


//----------------------------Imported Item Class----------------------------
class ImportedItem : public Item
{   float tax_amount,qty,last_price;

    public:
        void getDetails(); // function to write item details in file
        void CalculateLastPrice(); // calculate last price of imported item
        void showDetails(); // function to display all items details
        void searchImportedItem(); // function to read specific record from file
        void modifyData(); // function to modify record of file
        void deleteData(); // function to delete record of file

};
ImportedItem i; //created imported item object


//---------Imported Item Class Function Definitions----------

void ImportedItem::getDetails() // function to write item details in file
{
    outf.open("Imported Item Details.txt",ios::app);
    Item::getDetails();
    cout<<"\tTax Amount : "; cin>>tax_amount;
    cout<<"\tQuantity   : "; cin>>qty;
    CalculateLastPrice();
    outf<<setw(4)<<itemno<<setw(10)<<name<<setw(10)<<price<<setw(10)<<tax_amount<<setw(10)<<qty<<setw(10)<<last_price<<"\n"<<endl;
    cout<<endl;
    outf.close();
}

void ImportedItem::CalculateLastPrice() // calculate last price of imported item
{   last_price=price+tax_amount;
}

void ImportedItem::showDetails() // function to display all items details
{
    inf.open("Imported Item Details.txt", ios::in);
    if (!inf)
    {
        cout << "\n\nFile Not Found...";
    }
    else
    {
        while (1)
        {
            inf>>itemno>>name>>price>>tax_amount>>qty>>last_price;
            if (inf.eof())
                break;
            cout<<"\t"<<itemno<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<tax_amount<<"\t\t\t"<<qty<<"\t\t\t"<<last_price<<"\n";

        }

    }
    inf.close();
}

void ImportedItem::searchImportedItem() // function to read specific record from file
{
    int no;
    cout<<"\t\tEnter Item Number: "; cin>>no;
    inf.open("Imported Item Details.txt", ios::in);
    if (!inf)
    {
        cout << "\n\nFile Not Found...";
    }
    else
    {
        while (1)
        {
            inf>>itemno>>name>>price>>tax_amount>>qty>>last_price;
            if (inf.eof())
                break;
            if (itemno==no)
            {
              cout<<"\n\n\tItem No      : "<<itemno
                    <<"\n\tName         : "<<name
                    <<"\n\tPrice        : "<<price
                    <<"\n\tTax Amount   : "<<tax_amount
                    <<"\n\tQuantity     : "<<qty
                    <<"\n\tLast Price   : "<<last_price<<"\n";
            }

        }

    }
    inf.close();

}

void ImportedItem::modifyData() // function to modify record of file
{
    cout<<"\n\n\tEnter Item Number to be Edited : ";
    int no;
    cin>>no;
    inf.open("Imported Item Details.txt");
    outf.open("modify.txt");

    inf>>itemno;
    inf>>name;
    inf>>price;
    inf>>tax_amount;
    inf>>qty;
    inf>>last_price;

    while (!inf.eof())
    {
        if (itemno != no)
        {
            outf<<setw(4)<<itemno<<setw(10)<<name<<setw(10)<<price<<setw(10)<<tax_amount<<setw(10)<<qty<<setw(10)<<last_price<<"\n"<<endl;
        }
        else
        {
            cout<<"\n\n\t\tEnter New Details..\n\n";
            cout<<"\n\tItem No      : "; cin>>itemno;
            cout<<"\n\tName         : "; cin>>name;
            cout<<"\n\tPrice        : "; cin>>price;
            cout<<"\n\tTax Amount   : "; cin>>tax_amount;
            cout<<"\n\tQuantity     : "; cin>>qty;
            CalculateLastPrice();
            outf<<setw(4)<<itemno<<setw(10)<<name<<setw(10)<<price<<setw(10)<<tax_amount<<setw(10)<<qty<<setw(10)<<last_price<<"\n"<<endl;
            cout<<endl;

        }

        inf>>itemno;
        inf>>name;
        inf>>price;
        inf>>tax_amount;
        inf>>qty;
        inf>>last_price;


    }
    outf.close();
    inf.close();

    remove("Imported Item Details.txt");
    rename("modify.txt","Imported Item Details.txt");
}

void ImportedItem::deleteData() // function to delete record of file
{
    cout<<"\n\n\tEnter Item Number to be deleted : ";
    int no;
    cin>>no;
    inf.open("Imported Item Details.txt");
    outf.open("New.txt");

    inf>>itemno;
    inf>>name;
    inf>>price;
    inf>>tax_amount;
    inf>>qty;
    inf>>last_price;

    while (!inf.eof())
    {
        if (itemno != no)
        {
            outf<<setw(4)<<itemno<<setw(10)<<name<<setw(10)<<price<<setw(10)<<tax_amount<<setw(10)<<qty<<setw(10)<<last_price<<"\n"<<endl;
        }
        else
        {
            cout<<"\n\t\tItem Deleted Successfully!";

        }

        inf>>itemno;
        inf>>name;
        inf>>price;
        inf>>tax_amount;
        inf>>qty;
        inf>>last_price;


    }
    outf.close();
    inf.close();

    remove("Imported Item Details.txt");
    rename("New.txt","Imported Item Details.txt");
}


//----------------------------Local Item Class----------------------------
class LocalItem : public Item
{
    float discount_amount,qty,last_price;

    public:
        void getDetails(); // function to write item details in file
        void CalculateLastPrice(); // calculate last price of local item
        void showDetails(); // function to display all items details
        void searchLocalItem(); // function to read specific record from file
        void modifyData(); // function to modify record of file
        void deleteData(); // function to delete record of file

};
LocalItem l; //created local item object



//---------Local Item Class Function Definitions----------

void LocalItem::getDetails() // function to write item details in file
{
    outf.open("Local Item Details.txt",ios::app);
    Item::getDetails();
    cout<<"\tDiscount Amount    : "; cin>>discount_amount;
    cout<<"\tQuantity   : "; cin>>qty;
    CalculateLastPrice();
    outf<<setw(4)<<itemno<<setw(10)<<name<<setw(10)<<price<<setw(10)<<discount_amount<<setw(10)<<qty<<setw(10)<<last_price<<"\n"<<endl;
    cout<<endl;
    outf.close();
}
void LocalItem::CalculateLastPrice() // calculate last price of local item
{   last_price=price-discount_amount;
}

void LocalItem::showDetails() // function to display all items details
{   inf.open("Local Item Details.txt", ios::in);
    if (!inf)
    {
        cout << "\n\nFile Not Found...";
    }
    else
    {
        while (1)
        {
            inf>>itemno>>name>>price>>discount_amount>>qty>>last_price;
            if (inf.eof())
                break;
            cout<<"\t"<<itemno<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<discount_amount<<"\t\t\t"<<qty<<"\t\t\t"<<last_price<<"\n";

        }

    }
    inf.close();
}

void LocalItem::searchLocalItem() // function to read specific record from file
{
    int no;
    cout<<"\t\tEnter Item Number: "; cin>>no;
    inf.open("Local Item Details.txt", ios::in);
    if (!inf)
    {
        cout << "\n\nFile Not Found...";
    }
    else
    {
        while (1)
        {
            inf>>itemno>>name>>price>>discount_amount>>qty>>last_price;
            if (inf.eof())
                break;

            if (itemno==no)
            {
              cout<<"\n\n\tItem No          : "<<itemno
                    <<"\n\tName             : "<<name
                    <<"\n\tPrice            : "<<price
                    <<"\n\tDiscount Amount  : "<<discount_amount
                    <<"\n\tQuantity         : "<<qty
                    <<"\n\tLast Price       : "<<last_price<<"\n";
            }

        }

    }
    inf.close();

}

void LocalItem::modifyData() // function to modify record of file
{
    cout<<"\n\n\tEnter Item Number to be Edited : ";
    int no;
    cin>>no;
    inf.open("Local Item Details.txt");
    outf.open("modify1.txt");

    inf>>itemno;
    inf>>name;
    inf>>price;
    inf>>discount_amount;
    inf>>qty;
    inf>>last_price;

    while (!inf.eof())
    {
        if (itemno != no)
        {
            outf<<setw(4)<<itemno<<setw(10)<<name<<setw(10)<<price<<setw(10)<<discount_amount<<setw(10)<<qty<<setw(10)<<last_price<<"\n"<<endl;
        }
        else
        {
            cout<<"\n\n\t\tEnter New Details..\n\n";
            cout<<"\n\tItem No           : "; cin>>itemno;
            cout<<"\n\tName              : "; cin>>name;
            cout<<"\n\tPrice             : "; cin>>price;
            cout<<"\n\tDiscount Amount   : "; cin>>discount_amount;
            cout<<"\n\tQuantity          : "; cin>>qty;
            CalculateLastPrice();
            outf<<setw(4)<<itemno<<setw(10)<<name<<setw(10)<<price<<setw(10)<<discount_amount<<setw(10)<<qty<<setw(10)<<last_price<<"\n"<<endl;
            cout<<endl;

        }

        inf>>itemno;
        inf>>name;
        inf>>price;
        inf>>discount_amount;
        inf>>qty;
        inf>>last_price;


    }
    outf.close();
    inf.close();

    remove("Local Item Details.txt");
    rename("modify1.txt","Local Item Details.txt");
}

void LocalItem::deleteData() // function to delete record of file
{
    cout<<"\n\n\tEnter Item Number to be deleted : ";
    int no;
    cin>>no;
    inf.open("Local Item Details.txt");
    outf.open("New1.txt");

    inf>>itemno;
    inf>>name;
    inf>>price;
    inf>>discount_amount;
    inf>>qty;
    inf>>last_price;

    while (!inf.eof())
    {
        if (itemno != no)
        {
            outf<<setw(4)<<itemno<<setw(10)<<name<<setw(10)<<price<<setw(10)<<discount_amount<<setw(10)<<qty<<setw(10)<<last_price<<"\n"<<endl;
        }
        else
        {
            cout<<"\n\t\tItem Deleted Successfully!";

        }

        inf>>itemno;
        inf>>name;
        inf>>price;
        inf>>discount_amount;
        inf>>qty;
        inf>>last_price;


    }
    outf.close();
    inf.close();

    remove("Local Item Details.txt");
    rename("New1.txt","Local Item Details.txt");
}



//----------------------------Main Function----------------------------
int main()
{
mainmenu:
    system("cls");
    cout<<"\t------------------------------------\n";
    cout<<"\t      SHOP MANAGEMENT SYSTEM\n";
    cout<<"\t------------------------------------\n\n";
    cout<<"\t\t1.Edit Item Details\n\n";
    cout<<"\t\t2.Show All Item Details\n\n";
    cout<<"\t\t3.Search Item\n\n";
    cout<<"\t\t4.Exit\n\n";
    cout<<"\tPlease Enter Required Option: ";
    int option;
    cin>>option;

    switch(option)
    {
    case 1:
menu:
        system("cls");
        cout<<"\n\n";
        cout<<"\n\t\t1.Add Imported Item Details\n\n";
        cout<<"\t\t2.Add Local Item Details\n\n";
        cout<<"\t\t3.Modify Item Details\n\n";
        cout<<"\t\t4.Delete Item Details\n\n";
        cout<<"\t\t5.Back to Main Menu \n\n";
        cout<<"\tPlease Enter Required Option: ";
        int op;
        cin>>op;
        switch(op)
        {
            case 1:
            {
                system("cls");
                i.getDetails();
                cout<<"\n\t\tItem Added Successfully!";
                getch();
                goto menu;
            }

            case 2:
                system("cls");
                l.getDetails();
                cout<<"\n\t\tItem Added Successfully!";
                getch();
                goto menu;

            case 3:
                system("cls");
                cout<<"\n\n";
                cout<<"\n\t\t1.Imported Items\n\n";
                cout<<"\t\t2.Local Items\n\n";
                cout<<"\t\t3.Back\n\n";
                cout<<"\tPlease Enter Required Option: ";
                int op2;
                cin>>op2;
                switch (op2)
                {
                case 1:
                    system("cls");
                    i.modifyData();
                    cout<<"\n\t\tDetails Changed!";
                    getch();
                    goto menu;

                case 2:
                    system("cls");
                    l.modifyData();
                    cout<<"\n\t\tDetails Changed!";
                    getch();
                    goto menu;

                case 3:
                    goto menu;

                }

            case 4:
                system("cls");
                cout<<"\n\n";
                cout<<"\n\t\t1.Imported Item\n\n";
                cout<<"\t\t2.Local Item\n\n";
                cout<<"\t\t3.Back\n\n";
                cout<<"\tPlease Enter Required Option: ";
                int op;
                cin>>op;
                switch (op)
                {
                case 1:
                    system("cls");
                    i.deleteData();
                    getch();
                    goto menu;

                case 2:
                    system("cls");
                    l.deleteData();
                    getch();
                    goto menu;

                case 3:
                    goto menu;

                }


            case 5:
                goto mainmenu;

        }

    case 2:

        system("cls");
        cout<<"\n\n";
        cout<<"\n\t\t1.Imported Item Details\n\n";
        cout<<"\t\t2.Local Item Details\n\n";
        cout<<"\t\t3.Back\n\n";
        cout<<"\tPlease Enter Required Option: ";
        int op1;
        cin>>op1;
        switch(op1)
        {
            case 1:
                system("cls");
                cout<<"\n\t-----------------------------------------------------------------------------------------------------------\n";
                cout<<"\tItem No"<<"\t\tName"<<"\t\tPrice"<<"\t\tTax Amount"<<"\t\tQuantity"<<"\t\tLast Price";
                cout<<"\n\t-----------------------------------------------------------------------------------------------------------\n\n";
                i.showDetails();
                cout<<"\n\tPress Any Key to continue...";
                getch();
                goto mainmenu;

            case 2:
                system("cls");
                cout<<"\n\t-----------------------------------------------------------------------------------------------------------\n";
                cout<<"\tItem No"<<"\t\tName"<<"\t\tPrice"<<"\t\tDiscount Amount"<<"\t\tQuantity"<<"\t\tLast Price";
                cout<<"\n\t-----------------------------------------------------------------------------------------------------------\n\n";
                l.showDetails();
                cout<<"\n\tPress Any Key to continue...";
                getch();
                goto mainmenu;

            case 3:
                goto mainmenu;

        }

    case 3:
si:
        system("cls");
        cout<<"\n\n";
        cout<<"\n\t\t1.Search Imported Item\n\n";
        cout<<"\t\t2.Search Local Item\n\n";
        cout<<"\t\t3.Back\n\n";
        cout<<"\tPlease Enter Required Option: ";
        int opt3;
        cin>>opt3;
        switch (opt3)
        {
        case 1:
            system("cls");
            cout<<"\n\n";
            i.searchImportedItem();
            cout<<"\n\tPress Any Key to continue...";
            getch();
            goto si;

        case 2:
            system("cls");
            cout<<"\n\n";
            l.searchLocalItem();
            cout<<"\n\tPress Any Key to continue...";
            getch();
            goto si;

        case 3:
            goto mainmenu;
        }

    case 4:
        system("cls");

    }

    return 0;
}

//-------------END-------------
