//Bank Management System Using file handling and oops
#include<iostream> 
#include<climits>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;


void write_account();
void delete_account(long);
void display_acc(long);
void Modify(long);
void Deposit_withdraw(long , int );

class Bank_acc{ // class is used to create a new data type which is used to create a new object 
long acc_no;
char name[50]; // string dont work after space so we use char array
char type;
long deposit;


public:
void modify(){
    cout<<"Enter Modify account Holder name :: ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"Enter the account number :: ";
    cin>>acc_no;
    cout<<"Enter new account type (Current/Saving (C/S)):: ";
    cin>>type;
    type = toupper(type); // to convert lower case to upper case
    cout<<"Modify amount :: "<<endl;
    cin>>deposit;
    cout<<"\tAccount updated successfully"<<endl;
}
int retacno() const{
    return acc_no;
}
void create_acc();
void show_acc();
void Deposit_withdraw(int amount){
    deposit += amount;
}
int retdeposit() const{
    return deposit;
}
void withdraw(int amount){
    deposit -=  amount;
}
};


void Bank_acc::create_acc(){

system("cls");
cout<<"Enter your name :: ";
cin.ignore();
cin.getline(name,50);
cout<<"Enter your account number :: ";
cin>>acc_no;
cout<<"Enter your account type (Current/Saving (C/S)):: ";
cin>>type;
type = toupper(type); // to convert lower case to upper case
cout<<"Enter some amount to deposit :: "<<endl;
cin>>deposit;

cout<<"\tAccount created successfully"<<endl;
}

void Bank_acc::show_acc(){
cout<<endl<<"\tAccount number :: "<<acc_no<<endl;
cout<<"\tAccount holder name :: "<<name<<endl;
cout<<"\tAccount type :: "<<type<<endl;
cout<<"\tAccount balance is :: "<<deposit<<endl;

}

void display_menu(){

    cout<<"\t\t ************************************************"<<endl;
    cout<<"\t\t *|___Welcome To My Bank Command line portal___|*"<<endl;
    cout<<"\t\t ************************************************"<<endl;
cout<<endl;


cout<<"\t--:: Main Menu ::--"<<endl;
cout<<"\t1. Create new account"<<endl;
cout<<"\t2. Deposit amount"<<endl;
cout<<"\t3. Withdraw amount"<<endl;
cout<<"\t4. Balance enquiry"<<endl;
cout<<"\t5. Close an account"<<endl;
cout<<"\t6. Modify an account"<<endl;
cout<<"\t7. Exit"<<endl<<endl;
cout<<"\tSelect your option (1-7) :: ";
cout<<endl;

}


int main(){
    char ch;
    int num;
    long acc_num;
    do{
display_menu();
cin>>num;
switch(num){
case 1:
    cout<<"1. Create new account selected"<<endl;
    write_account();
    break;
case 2:
    system("cls");
    cout<<"2. Enter the Account number :: "<<endl;
    cin>>acc_num;
    Deposit_withdraw(acc_num,1);
    break;
case 3:
    system("cls");
    cout<<"3. Enter the Account number :: "<<endl;
    cin>>acc_num;
    Deposit_withdraw(acc_num,2);
    break;
case 4:
    system("cls");
    cout<<"4. Enter the Account number :: "<<endl;
    cin>>acc_num;
    display_acc(acc_num);
    break;
case 5:
    system("cls");
    cout<<"5. Enter the Account number :: "<<endl;
    cin>>acc_num;
    delete_account(acc_num);
    break;
case 6:
    system("cls");
    cout<<"6. Enter the Account number :: "<<endl;
    cin>>acc_num;
    Modify(acc_num);
    break;
case 7:
    system("cls");
    cout<<"Program exit succesfully"<<endl;
    exit(0);
    break;
}
cin.ignore();
cin.get();
}while(num != 7);


return 0;
}


void write_account(){
Bank_acc ac;
ofstream outFile;
outFile.open("account.dat",ios::binary|ios::app); // ios::binary is used to write in binary format
ac.create_acc();
outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_acc)); // reinterpret_cast is used to convert one pointer of another pointer type convert char* to Bank_acc*
outFile.close();
}

void delete_account(long n){
Bank_acc ac;
ifstream inFile; 
ofstream outFile;
inFile.open("account.dat",ios::binary); // ios::binary is used to write in binary format 
if(!inFile){
    cout<<"File could not be open !! Press any key...";
    return;
}
outFile.open("Temp.dat",ios::binary); // Temp.dat is a temporary file
inFile.seekg(0,ios::beg);
while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_acc))){
    if(ac.retacno() != n){
        outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_acc));
    }

}
inFile.close();
outFile.close();

remove("account.dat");
rename("Temp.dat","account.dat");
cout<<"\t Account deleted successfully"<<endl;

}

void display_acc(long n){

Bank_acc ac;
bool flag = false;
ifstream inFile;
inFile.open("account.dat",ios::binary);
if(!inFile){
    cout<<"File could not be open !! Press any key...";
    return;
}
cout<<"\t Balance Details"<<endl;
while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_acc))){
    if(ac.retacno() == n){
        ac.show_acc();
        flag = true;
    }

}
inFile.close();
if(flag == false){
    cout<<"\t Account number does not exist"<<endl;
}

}

void Deposit_withdraw(long n, int option){
    long amount;
    bool flag = false;
    Bank_acc ac;
    fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File could not be open !! Press any key...";
        return;
    }
    while(!File.eof() && flag == false){
        File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_acc));
        if(ac.retacno() == n){
            ac.show_acc();
            if(option == 1){
                cout<<"\t To deposit amount"<<endl;
                cout<<"\t Enter the amount to deposit :: ";
                cin>>amount;
                ac.Deposit_withdraw(amount);
            }
            if(option == 2){
                cout<<"\t To withdraw amount"<<endl;
                cout<<"\t Enter the amount to withdraw :: ";
                cin>>amount;
                int bal = ac.retdeposit() - amount;
                if(bal < 0){

                    cout<<"\t Insufficient balance"<<endl;
                }else{
                    ac.withdraw(amount);
                }
            }
            int pos = (-1)*static_cast<int>(sizeof(ac)); // to store the size of ac object in pos variable multiplying by 1
            File.seekp(pos,ios::cur); // to move the pointer from the current position to pos position
            File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_acc)); // to write the data in the file in binary file using type casting
            cout<<"\t Record updated"<<endl; 
            flag = true;
        }
    }
    File.close();
    if(flag == false){
        cout<<"\t Account number does not exist"<<endl;
    }
}


void Modify(long n){
    bool flag = false;
    Bank_acc ac;
    fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File could not be open !! Press any key...";
        return;
    }
    while(!File.eof() && flag == false){
        File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_acc));
        if(ac.retacno() == n){
            ac.show_acc();
            cout<<"\t Enter the new details of account"<<endl;
            ac.modify();
            int pos = (-1)*static_cast<int>(sizeof(ac)); // to move the pointer to the current position 
            File.seekp(pos,ios::cur); // to move the pointer to the current position    
            File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_acc)); // to write the data in the file  
            cout<<"\t Record updated"<<endl; 
            flag = true;
        }
    }
    File.close();
    if(flag == false){
        cout<<"\t Account number does not exist"<<endl;
    }
}