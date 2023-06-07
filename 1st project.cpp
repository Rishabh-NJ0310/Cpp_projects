#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int PlayerX(){
    int N=100;
    // srand((unsigned)time(0));
    int random;
    random = (rand()%N)+1;
    return random;
}
void display_board(){
    for(int i=0;i<=4;i++){
        for(int k=0;k<15;k++){
            cout<<" ";
        }
        for(int j=0;j<=6;j++){
            PlayerX();
            if(i%2==0 && j%3==0){
                if(PlayerX()%2==0){
                cout<<"X ";
            }
            else{
                cout<<"O ";
            }
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    display_board();

    return 0;
}