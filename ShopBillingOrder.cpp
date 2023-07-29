#include<bits/stdc++.h>
using namespace std;

class shopping{
    private:
    int pcode;
    float price;
    float dis;
    string pname;

    public:
    void login();
    void menu();
    void chPw();
    void admin();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
    void confirm();
    void exitPro();
};

void shopping :: menu(){
    m:
    
    int choice;
    

    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t               Shop Main Menu              \n";
    cout << "\t\t\t\t                                           \n";
    cout << "\t\t\t\t___________________________________________\n";
    cout << "\t\t\t\t                                           \n";

    cout <<"\t\t\t\t\t|   1) Administrator   |\n";
    cout <<"\t\t\t\t\t|                      |\n";
    cout <<"\t\t\t\t\t|   2) Buyer           |\n";
    cout <<"\t\t\t\t\t|                      |\n";
    cout <<"\t\t\t\t\t|   3) Exit            |\n";
    cout <<"\t\t\t\t\t                        \n";

    cout<<"\n\t\t\t\t Please enter your choice: ";
    cin>>choice;
    cout<<"\n\n";

    switch (choice)
    {
        case 1:{
            login();
            break;
        }
        case 2:
        {
            buyer();
            break;
        }
        case 3:{
            exit(0);
        }
        default:
        {
            cout << "\n\n\t\t\t\tPlease select from the above options!\n\n";
            break;
        }
    }
    goto m;
}

void shopping :: login(){
    fstream data2;
    string username;
    string password;
    string un;
    string pw;

    data2.open("credentials.txt",ios::in);
    data2>>un>>pw;

    cout<<"\t\t\t\t          - Administrator login - \n\n";
    cout<<"\t\t\t\t Enter Username: ";
    cin>> username;
    cout<<"\t\t\t\t Enter Password: ";
    cin>> password;

    if(username==un && password==pw){
        admin();
    }
    else
    {
        cout<<"\n\n\t\t\t\tInvalid username/password!\n\n\n";
    }
    data2.close();
}

void shopping :: admin(){
    m:
    int choice;
    cout <<"\n\n\t\t\t\t\t__________________________";
    cout << "\n\t\t\t\t\t                            ";
    cout <<"\n\n\t\t\t\t\t     Administrator Menu\n";
    cout <<"\n\t\t\t\t\t__________________________\n\n";
    cout << "\n\t\t\t\t\t|   1) Add product         |";
    cout << "\n\t\t\t\t\t|                          |";
    cout << "\n\t\t\t\t\t|   2) Modify product      |";
    cout << "\n\t\t\t\t\t|                          |";
    cout << "\n\t\t\t\t\t|   3) Delete product      |";
    cout << "\n\t\t\t\t\t|                          |";
    cout << "\n\t\t\t\t\t|   4) Show product list   |";
    cout << "\n\t\t\t\t\t|                          |";
    cout << "\n\t\t\t\t\t|   5) Change password     |";
    cout << "\n\t\t\t\t\t|                          |";
    cout << "\n\t\t\t\t\t|   6) Back to main menu   |";
    cout << "\n\t\t\t\t\t                            ";

    cout <<"\n\n\t\t\t\t Please enter your choice: ";
    cin>> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        list();
        break;
    case 5:
        chPw();
        break;
    case 6:
        menu();
        break;
    
    default:
        cout << "Please select from the above options!";
        break;
    }
    goto m;
}
void shopping :: chPw(){
    fstream data2,data3;
    string un,un1,pw,oPw,nPw,nPwA;

    data2.open("credentials.txt",ios::in);
    data2>>un>>pw;

    un1=un;
    cout <<"\n\n\t\t\t\t\t__________________________";
    cout << "\n\t\t\t\t\t                            ";
    cout <<"\n\n\t\t\t\t\t      Change password\n";
    cout <<"\n\t\t\t\t\t__________________________\n\n";

    cout << "\n\n\t\t\t\tEnter current password: ";
    cin>>oPw;
    cout << "\n\n\t\t\t\tEnter new password: ";
    cin>>nPw;
    cout << "\n\n\t\t\t\tEnter new password again: ";
    cin>>nPwA;

    data2.close();
    if(oPw!=pw){
        cout << "\n\n\t\t\t\tWrong current password!\n\n";
    }
    else if (nPw!=nPwA)
    {
        cout << "\n\n\t\t\t\tNew passwords not matched!\n\n";
    }
    else
    {
        data2.open("credentials.txt",ios::out|ios::trunc);
        data2.close();

        data2.open("credentials.txt",ios::app|ios::out);
        data2<<un1<<" "<<nPw;

        cout << "\n\n\t\t\t\t-> Password changed successfully!\n\n";

        data2.close();
    }
}

void shopping :: buyer(){
    m:
    int choice;

    cout <<"\n\t\t\t\t\t_________________\n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t    Buyer Menu \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t_________________\n";
    cout <<"\n\t\t\t\t\t 1) Buy product \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t 2) Go back \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t Enter your choice: ";

    cin>>choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;    
    default:
        cout <<"\n\n\t\t\t\t Please select from the above options!\n\n";
        goto m; 
        break;
    }
}

void shopping :: add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout <<"\n\t\t\t\t_________________________\n";
    cout <<"                  \n";
    cout <<"\n\t\t\t\t     -Add new product- \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t_________________________\n";
    cout <<"                  \n";
    cout <<"\t\t\t\t Enter product code: ";
    cin>>pcode;
    cout <<"                  \n";
    cout <<"\t\t\t\t Enter product name: ";
    cin>>pname;
    cout <<"                  \n";
    cout <<"\t\t\t\t Enter product price: ";
    cin>>price;
    cout <<"                  \n";
    cout << "\t\t\t\t Enter Discount on product: ";
    cin>>dis;
    cout <<"                  \n";

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while (!data.eof())
        {
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if (token==1)
        {
            goto m;
        }
        else if(token==0){
            data.open("database.txt",ios::app|ios::out);
            data<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }

        
    }

    cout<<"\n\t\t\t\t Record inserted successfully!";
}

void shopping :: edit(){
    fstream data,data1;

    int pkey;
    int token=0,c;
    float p,d;
    string n;

    cout <<"\t\t\t\t_____________________\n";
    cout <<"                  \n";
    cout <<"\n\n\t\t\t\t -Modify product- \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t_____________________\n";
    cout <<"                  \n";
    cout <<"\t\t\t\t Enter product code: ";
    cin>>pkey;
    cout <<"                  \n";

    data.open("database.txt",ios::in);
    if(!data){
        cout << "\t\t\t\t File doesn't exist!";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if (pkey==pcode)
            {
                cout<<"\n\n\t\t\t\t Enter new product code: ";
                cin>>c;
                cout<<"\n\n\t\t\t\t Enter product name: ";
                cin>>n;
                cout<<"\n\n\t\t\t\t Enter product price: ";
                cin>>p;
                cout<<"\n\n\t\t\t\t Enter discount on product: ";
                cin>>d;

                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";

                cout << "\n\n\t\t\t\t Record modified successfully!";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n\t\t\t\t Record not found!";
        }
    }
}

void shopping :: rem(){
    fstream data,data1;

    int pkey;
    int token=0;

    cout <<"\t\t\t\t_________________\n";
    cout <<"                  \n";
    cout <<"\n\n\t\t\t\t -Delete product- \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t_________________\n";
    cout <<"                  \n";
    cout <<"\t\t\t\t Enter product code: ";
    cin>>pkey;
    cout <<"                  \n";

    data.open("database.txt",ios::in);
    if(!data){
        cout << "\t\t\t\t File doesn't exist!";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if (pkey==pcode)
            {
                cout<<"\n\n\t\t\t\t Product deleted successfully!";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n\t\t\t\t Record not found!";
        }
    }
}

void shopping :: list(){
    fstream data;

    data.open("database.txt",ios::in);

    if(!data){
        cout<<"\n\n\t\t\t\t Empty database!";
    }
    else{
        cout << "\n\n\t\t_______________________________Product list_____________________________\n\n";
        cout<<"\t\t\tProNo\t\tProName\t\tPrice\t\tDiscount";
        cout << "\n\t\t________________________________________________________________________\n\n";
        data>>pcode>>pname>>price>>dis;

        while (!data.eof())
        {
            cout<<"\t\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<dis<<"%"<<"\n";
            data>>pcode>>pname>>price>>dis;

        }
        data.close();
    }
}

void shopping :: receipt(){
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0,dis=0,total=0;

    data.open("database.txt",ios::in);

    if(!data){
        cout<<"\n\n\t\t\t\t Empty database!";
    }
    else
    {
        data.close();

        list();
        cout<<"\n\t\t\t\t______________________________________\n";
        cout<<"\t\t\t\t                                          ";
        cout<<"\n\t\t\t\t            Place the order           \n";
        cout<<"\t\t\t\t                                          ";
        cout<<"\n\t\t\t\t______________________________________\n";

        do
        {
            m:
            cout<<"\n\n\t\t\t\t Enter product code: ";
            cin>>arrc[c];
            cout<<"\n\n\t\t\t\t Enter quantity: ";
            cin>>arrq[c];

            for (int i = 0; i < c; i++)
            {
                if (arrc[c]==arrc[i])
                {
                    cout<<"\n\n\t\t\t\t Duplicate product code! please try again.";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n\t\t Do you want to buy another product? If yes then type Y else any key: ";
            cin>>choice;
        }while (choice=='Y' || choice=='y');
        
        cout << "\n\n\n\n\t___________________________________________Receipt___________________________________________\n";
        cout <<"\n\tProduct no\t Product name\t Product quantity\t Price\t Amount\t Amount with discount\n";

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while (!data.eof())
            {
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout <<"\n\t"<<pcode<<"\t\t " <<pname<<"\t\t "<<arrq[i]<<"\t\t\t "<<price<<"\t "<<amount<<"\t "<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();   
        }
    }
    cout<<"\n\n\t_____________________________________________________________________________________________";
    cout<<"\n\n\t Total Amount: "<<total<<"\n\n";
    confirm();
}

void shopping :: confirm(){
    k:
    int choice2;
    
    cout <<"\t\t\t\t\t_______________________\n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t     Confirm order     \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t_______________________\n";
    cout <<"\n\t\t\t\t\t 1) Pay now! \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t 2) Cancel buying \n";
    cout <<"                  \n";
    cout <<"\n\t\t\t\t\t Enter your choice: ";

    cin>>choice2;
    
    switch(choice2){
        case 1:{
            cout <<"\n\n\t\t\t\t      _______________________________\n";
            cout <<"\t\t\t\t      |                             |\n";
            cout <<"\t\t\t\t      |  Thank you for shopping :)  |\n";
            cout <<"\t\t\t\t      |                             |\n";
            cout <<"\t\t\t\t      |_____________________________|\n\n";
            exitPro();
            break;
        }
        case 2:{
            cout <<"\n\n\t\t\t\t      _______________________________\n";
            cout <<"\t\t\t\t      |                             |\n";
            cout <<"\t\t\t\t      |      Order cancelled :(     |\n";
            cout <<"\t\t\t\t      |                             |\n";
            cout <<"\t\t\t\t      |_____________________________|\n\n";
            exitPro();
            break;
        }
        default:
        {
            cout<<"\n\n\t\t\t Please select from the above options!\n\n";
            goto k;
            break;
        }
    }
}

void shopping :: exitPro(){
    m:
    int choice;

    cout <<"\n\t\t\t\t\t______________________\n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t Do you want to exit? \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t______________________\n";
    cout <<"\n\t\t\t\t\t 1) Yes \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t 2) No \n";
    cout <<"                  \n";
    cout <<"\t\t\t\t\t Enter your choice: ";

    cin>>choice;

    switch (choice)
    {
    case 1:
        exit(0);
        break;
    case 2:
        menu();
        break;    
    default:
        cout <<"\n\n\t\t\t\t Please select from the above options!\n\n";
        goto m; 
        break;
    }
}
int main()
{
    shopping s;
    s.menu();
    return 0;
}