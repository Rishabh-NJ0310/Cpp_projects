// So close to the password change feature in the login system c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void writefile(){
    ofstream write("example.txt",ios::app);
    string username,password;
    cout<<"Enter your username :: "<<endl;
    cin>>username;
    cout<<"Enter your password :: "<<endl;
    cin>>password;
    write<<username<<" "<<password<<endl;
    write.close();
}

void replaceStringInFile( string& filename,  string& searchString,  string& replaceString) {
    ifstream inputFile(filename);
    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    size_t pos = fileContent.find(searchString);

    while (pos != string::npos) {
        fileContent.replace(pos, searchString.length(), replaceString);
        pos = fileContent.find(searchString, pos + replaceString.length());
    }

    ofstream outputFile(filename);
    outputFile << fileContent;
    outputFile.close();
}

int main() {
    string filename = "example.txt";
    writefile();
    string searchString,replaceString;
    cout<<"Enter your username which you want to change :: "<<endl;
    cin>>searchString;
    cout<<"Enter your new username :: "<<endl;
    cin>>replaceString;
    cout<<searchString<<" +++ "<<replaceString<<endl;
    replaceStringInFile(filename, searchString, replaceString);

    cout << "Replacement completed." << endl;

    return 0;
}