// Changed L&R system with forget password funtion incomplete
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
string username,password;
int flag = 0;
char ch;
void replaceStringInFile(string& filename, string& searchString, string& replaceString) {
    ifstream inputFile(filename);
    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();
    string Password,username,findPassword;
    
    while(inputFile>>username>>Password){
        if(username==searchString){
            findPassword = Password;
        }
        }
    size_t pos = fileContent.find(findPassword);
    while (pos != string::npos) {
        fileContent.replace(pos, Password.length(), replaceString);
        pos = fileContent.find(Password, pos + replaceString.length());
    }
    ofstream outputFile(filename);
    outputFile << fileContent;
    outputFile.close();
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
    string filename="database.txt";
    cout<<"forget function called"<<endl;
    cout<<"If you want to change your password :: \npress 'y' \n \tor \npress 'n' to continue"<<endl;
    string registered_username,registered_password,*ptrregpass = &registered_password,new_pass;
    char choice;
    cin>>choice;
    if(choice == 'y'){
    string searchString;
    string replaceString;
    cout<<":: Enter the username to change your password :: "<<endl;
    cin>>searchString;
    cout<<"Enter your new password"<<endl;
    cin>>replaceString;
    replaceStringInFile(filename, searchString, replaceString);
    }else{
    ifstream read("database.txt");
    ofstream write("database.txt",ios::app);
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
    ofstream write("database.txt",ios::app); // the ios::app == append 
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