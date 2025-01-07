#include<iostream>
#include <time.h>
using namespace std;
void DrawBoard(char *space);
void PlayerMove(char *space,char player);
void ComputerMove(char *space,char computer);
bool CheckWinner(char *space,char player,char computer);
bool CheckTie(char *space);

int main()
{
    char space[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer='O';
    bool running=true;

    DrawBoard(space);

    while(running)
    {
        PlayerMove(space,player);
        DrawBoard(space);

        if(CheckWinner(space,player,computer))
        {
            running=false;
            break;
        }

        else if(CheckTie(space))
        {
            running=false;
            break;
        }

        ComputerMove(space,computer);
        DrawBoard(space);

        if(CheckWinner(space,player,computer))
        {
            running=false;
            break;
        }
        else if(CheckTie(space))
        {
            running=false;
            break;
        }
    }

    cout<<"Thanks For Playing! \n";

    return 0;
}
void DrawBoard(char *space){
    cout<<"     |     |     "<<'\n';
    cout<<"  "<<space[0]<< "  |  "<<space[1]<< "  |  "<<space[2]<< "   "<<'\n';
    cout<<"_____|_____|_____"<<'\n';

    cout<<"     |     |     "<<'\n';
    cout<<"  "<<space[3]<< "  |  "<<space[4]<< "  |  "<<space[5]<< "   "<<'\n';
    cout<<"_____|_____|_____"<<'\n';

    cout<<"     |     |     "<<'\n';
    cout<<"  "<<space[6]<< "  |  "<<space[7]<< "  |  "<<space[8]<< "   "<<'\n';
    cout<<"     |     |     "<<'\n';
    cout<<'\n';



}
void PlayerMove(char *space,char player){
    int number;
    do
    {
        cout<<"Enter a spot to place mark : ";
        cin>>number;
        number--;
        if(space[number]==' ')
        {
            space[number]=player;
            break;
        }
    } while (!number>0 || !number<8);
    

}
void ComputerMove(char *space,char computer){
    int number;
    srand(time(0));
    while(true)
    {
        number=rand()%9;
        if(space[number]==' ')
        {
            space[number]=computer;
            break;
        }
    }

}
bool CheckWinner(char *space,char player,char computer){
if((space[0]!=' ') && (space[0]==space[1]) && (space[1]==space[2]))
{
    space[0]==player ? cout<<"You Win! \n":cout<<"You Lose! \n";
}

else if((space[3]!=' ') && (space[3]==space[4]) && (space[4]==space[5]))
{
    space[3]==player ? cout<<"You Win! \n":cout<<"You Lose! \n";
}

else if((space[6]!=' ') && (space[6]==space[7]) && (space[7]==space[8]))
{
    space[6]==player ? cout<<"You Win! \n":cout<<"You Lose! \n";
}

else if((space[0]!=' ') && (space[0]==space[3]) && (space[3]==space[6]))
{
    space[0]==player ? cout<<"You Win! \n":cout<<"You Lose! \n";
}

else if((space[1]!=' ') && (space[1]==space[4]) && (space[4]==space[7]))
{
    space[1]==player ? cout<<"You Win! \n":cout<<"You Lose! \n";
}

else if((space[2]!=' ') && (space[2]==space[5]) && (space[5]==space[8]))
{
    space[2]==player ? cout<<"You Win! \n":cout<<"You Lose! \n";
}

else if((space[0]!=' ') && (space[0]==space[4]) && (space[4]==space[8]))
{
    space[0]==player ? cout<<"You Win! \n":cout<<"You Lose! \n";
}

else if((space[2]!=' ') && (space[2]==space[4]) && (space[4]==space[6]))
{
    space[2]==player ? cout<<"You Win! \n":cout<<"You Lose! \n";
}

else
{
    return false;
}
return true;
}
bool CheckTie(char *space){
    for(int i=0;i<9;i++)
    {
        if(space[i]==' ')
        {
            return false;
        }
    }
    cout<<"It's a TIE! \n";
    return true;
}
