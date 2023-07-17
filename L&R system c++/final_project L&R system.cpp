#include <iostream>
#include<fstream>
#include<string>
using namespace std;
string username,password;
int flag = 0;
char ch;
void change_password(){

}
void login(){
    cout<<"Login function called"<<endl;
    cout<<":: Enter your registered username :: "<<endl;
    cin>>username;
    cout<<"Enter your password :: "<<endl;
    cin>>password;
    ifstream read("database.txt");
    string registered_username,registered_password;
    while(read>>registered_username>>registered_password){
        if(registered_username == username && registered_password == password){
            flag=1;
        }
        registered_username.clear();
        registered_password.clear();
    }
    read.close();
    if(flag){
        cout<<":: Login Successfully ::"<<endl;
    }else{
        cout<<"!! Login Error invalid username or password !!"<<endl;
    }

}
void forget(){
    cout<<"forget function called"<<endl;
    cout<<"If you want to change your password :: press 1 or press anykey to continue"<<endl;
    string registered_username,registered_password,*ptrregpass = &registered_password,new_pass;
    int choice;
    cin>>choice;
    ifstream read("database.txt");
    ofstream write("database.txt",ios::app);
    if(choice == 1){
    cout<<":: Enter the username to change your password :: "<<endl;
    cin>>username;
    while(read>>registered_username>>registered_password){
        if(registered_username == username){
            cout<<":: username found ::"<<endl;
            cout<<":: Enter your new password :: "<<endl;
            cin>>new_pass;
            *ptrregpass = new_pass;
            cout<<":*:your password has been updated Successfully :*:"<<endl;
        }
    }
    }else{
    cout<<":: Enter the username to find your password :: "<<endl;
    cin>>username;
    while(read>>registered_username>>registered_password){
        if(registered_username == username){
            cout<<":: username found ::"<<endl;
            cout<<"Your password is * "+registered_password+" *"<<endl;
        }
    }
    }
}

void regi(){
    ifstream read("database.txt");
    cout<<"register function called"<<endl;
    X:
    cout<<":: select a username ::"<<endl;
	cin>>username;
	string existing_string;
	while(read>>existing_string){
        if(username == existing_string){
        cout<<"Username already exist"<<endl;
        goto X;
	}
}
	cout<<":: select a password ::"<<endl;
    cin>>password;
    ofstream write("database.txt",ios::app); // dont know the ios::app right now
    write<<username<<" "<<password<<endl;
    cout<<"Registration is completed"<<endl;
}
int main(){
    cout<<endl<<"##########   Login & Registration System   ##########"<<endl;
    cout<<":: 1.Login :: "<<endl;
    cout<<":: 2.Register :: "<<endl;
    cout<<":: 3.Forget Password (OR) Want to change your password :: "<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
        login();
        cout<<"Do you want to return to main menu (y/n)";
        cin>>ch;
        if(ch=='y'){
        main();
        }else{
            cout<<"program exit successfully \n";
            exit(0);
        }
        break;
        case 2:
        regi();
        cout<<"Do you want to return to main menu (y/n)";
        cin>>ch;
        if(ch=='y'){
        main();
        }else{
            cout<<"program exit successfully \n";
            exit(0);
        }
        main();
        break;
        case 3:
        forget();
        cout<<"Do you want to return to main menu (y/n)";
        cin>>ch;
        if(ch=='y'){
        main();
        }else{
            cout<<"program exit successfully \n";
            exit(0);
        }
        main();
        break;
        default:
        cout<<"Invalid choice :: please select from 1 to 3"<<endl<<endl;
        cout<<"Do you want to return to main menu (y/n)";
        cin>>ch;
        if(ch=='y'){
        main();
        }else{
            cout<<"program exit successfully \n";
            exit(0);
        }
    }
    
    return 0;
}