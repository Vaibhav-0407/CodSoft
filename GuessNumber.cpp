#include<iostream>
#include <time.h>
using namespace std;
int main()
{
    int number;
    int guess;
    int tries;

    srand(time(NULL));
    number=rand()%100+1;

    cout<<"#-----------------NUMBER GUESSING GAME---------------#";

    do{
        cout<<"\nEnter a guess number : ";
        cin>>guess;
        tries++;

        if(guess>number)
        {
            cout<<"Number is too high!\n";
        }
         
        else if(guess<number)
        {
            cout<<"Number is too low!\n";
        }

        else
        {
            cout<<"CORRECT! \n#Number of tries : "<<tries<<"\n";
        }

    }while (guess!=number);
    cout<<"-------------------------------------------------------------------------------------------------------------------------------";

    return 0;
}