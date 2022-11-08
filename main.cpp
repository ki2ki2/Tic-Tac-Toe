//CODE BY KRITI KUMARI
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define PI 3.1415926535
#define pb push_back
#define mpr make_pair
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
bool draw=false;

void display_board(){
    system("cls");
    cout<<"\n\n\tT I C - T A C  G A M E"<<endl;
    cout<<"\t----------------------\n"<<endl;
    cout<<"\t      Player1 [X]\n\t      Player2 [O]\n"<<endl;
    cout<<"\t       |     |     "<<endl;
    cout<<"\t    "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"\t  _____|_____|_____"<<endl;
    cout<<"\t       |     |     "<<endl;
    cout<<"\t    "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"\t  _____|_____|_____"<<endl;
    cout<<"\t       |     |     "<<endl;
    cout<<"\t    "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"\t       |     |     "<<endl;
}

void player_turn(){
    int choice;
    if(turn=='X')
        cout<<"\n\tPlayer1 [X] Turn :";

    if(turn=='O')
        cout<<"\n\tPlayer2 [O] Turn :";

    cin>>choice;
    switch (choice)
    {
    case 1:row=0;column=0;break;
    case 2:row=0;column=1;break;
    case 3:row=0;column=2;break;
    case 4:row=1;column=0;break;
    case 5:row=1;column=1;break;
    case 6:row=1;column=2;break;
    case 7:row=2;column=0;break;
    case 8:row=2;column=1;break;
    case 9:row=2;column=2;break;                         
    default:
        cout<<"Invalid Choice."<<endl;
        break;
    }
    if(turn=='X' && board[row][column]!='X' && board[row][column]!='O'){
        board[row][column]='X';
        turn='O';
    }
    else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O'){
        board[row][column]='O';
        turn='X';
    }
    else{
        cout<<"\n\tBOX ALREADY FILLED!\n\tPLEASE TRY AGAIN!!\n";
        player_turn();
    }
    display_board();
}

bool game_over(){
    //check win!!
    for(int i=0;i<3;i++){
        if( (board[i][0]==board[i][1] && board[i][0]==board[i][2]) || (board[0][i]==board[1][i] && board[0][i]==board[2][i]) ){
            return false;
        }       
    }
    for(int i=0;i<3;i++){
        if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0]){
        return false;
    }
    }
    //if there is any box not filled!!
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!='X' && board[i][j]!='O'){
                return true;
            }
        }
    }
    //game draw!!
    draw=true;
    return false;
}

int main(){
    while(game_over()){
        display_board();
        player_turn();
        game_over();
    }
    if(turn=='X' && draw==false){
        cout<<"\n\tPlayer2 [O] Wins!!\n\n\t  Congratulations\n";
    }
    else if(turn=='O' && draw==false){
        cout<<"\n\tPlayer1 [X] Wins!!\n\n\t  Congratulations\n";
    }
    else{
        cout<<"\n\t    GAME DRAW!! \n";
    }
return 0;
}