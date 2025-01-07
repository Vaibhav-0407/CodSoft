#include<iostream>
using namespace std;
int main()
{
    int number1,number2;
    char opr;

    cout<<"Enter the Operator. (+ - * /) : ";
    cin>>opr;

    cout<<"Enter the numbers. ";
    cin>>number1>>number2;

    switch (opr)
    {
    case '+':
        cout<<number1<<opr<<number2<<"="<<number1+number2;
        break;
    case '-':
        cout<<number1<<opr<<number2<<"="<<number1-number2;
        break;
    case '*':
        cout<<number1<<opr<<number2<<"="<<number1*number2;
        break;
    case '/':
        if(number2==0.0)
        {
            cout<<"Divide by zero situation.";
        }
        else
        {
        cout<<number1<<opr<<number2<<"="<<number1/number2;
        }
        break;
    
    default:
    cout<<"Invalid Operator";
        break;
    }
}