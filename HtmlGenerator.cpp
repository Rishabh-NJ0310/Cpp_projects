// create a html file using c++ file handling
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    string name;
    cout<<"Enter your name: ";
    cin>>name;
    string filename=name+".html";
    ofstream fout(filename.c_str());
    if(!fout)
    {
        cout<<"Error in creating file.."<<endl;
        return -1;
    }
    fout<<"<html>"<<endl;
    fout<<"<head>"<<endl;
    fout<<"<title>"<<name<<"'s web page</title>"<<endl;
    fout<<"</head>"<<endl;
    fout<<"<body>"<<endl;
    fout<<"<h1>"<<name<<"'s web page</h1>"<<endl;
    fout<<"<p>This is "<<name<<"'s web page.</p>"<<endl;
    fout<<"<p>It is created using c++.</p>"<<endl;
    fout<<"<p>It is created on ";
    time_t now=time(0);
    fout<<ctime(&now)<<"</p>"<<endl;
    fout<<"</body>"<<endl;
    fout<<"</html>"<<endl;
    fout.close();
    cout<<"File "<<filename<<" created successfully."<<endl;
    return 0;
}
