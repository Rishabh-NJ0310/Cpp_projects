#include<iostream>
#include<climits>
#include<time.h>

using namespace std;
int main(){

int N=10;
    srand((unsigned)time(0));
    int random;
    random = (rand()%N)+1;
    int N_tails=0,N_heads=0;
    if(random%2 == 0){
        cout<<"Tails"<<endl;
        N_tails++;
    }else{
        cout<<"Heads"<<endl;
        N_heads++;
    }
    cout<<"do you want to continue? (y/n)"<<endl;
    char ch;
    cin>>ch;
    if(ch=='y' || ch=='Y'){
        main();
    }else{
        cout<<"Thank you"<<endl;
    }
return 0;
}