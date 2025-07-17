#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> game(3, vector<char> (3));
char p1;
char p2;
int count=0;
int m,n;

bool isSafe(int i, int j){
    if(game[i][j]!=p1 && game[i][j]!=p2) return true;
    if(game[i][j]==p1 || game[i][j]==p2){
        cout<<"enter a different cell"<<endl;
        cin>>m>>n;
        return true;
    }
    return false;
}

bool won(vector<vector<char>> &game, char p){
    // Check rows
    for(int i = 0; i < 3; i++){
        if(game[i][0] == p && game[i][1] == p && game[i][2] == p)
            return true;
    }

    // Check columns
    for(int i = 0; i < 3; i++){
        if(game[0][i] == p && game[1][i] == p && game[2][i] == p)
            return true;
    }

    // Check diagonals
    if(game[0][0] == p && game[1][1] == p && game[2][2] == p)
        return true;
    if(game[0][2] == p && game[1][1] == p && game[2][0] == p)
        return true;

    return false;
}

void display(vector<vector<char>> &game){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<game[i][j]<<" | ";
        }
        cout<<endl<<"---------------"<<endl;
    }
}

void TicTacToe(){
    display(game);
    while(count!=9){
        cout<<"Player 1, enter row (1-3) and column (1-3):";
        cin>>m>>n;
        if(isSafe(m-1,n-1)){
            game[m-1][n-1]=p1;
            display(game);
            if(won(game,p1)){
                cout<<"player 1 won!!";
                return;
            }
        }
        
        count++;
        if(count==9) return;

        cout<<"Player 2, enter row (1-3) and column (1-3):";
        cin>>m>>n;
        if(isSafe(m-1,n-1)){
            game[m-1][n-1]=p2;
            display(game);
            if(won(game,p2)){
                cout<<"player 2 won!!";
                return;
            }
        }
        
        count++;
    }
    cout<<"Tie";
    return;
}

int main(){
    cout<<"Hello, Welcome to Tic Tac Toe Game!";
    cout<<endl<<"Give input for the choice of player 1 and 2 (in X or O)"<<endl;

    cout<<"Player 1=";
    cin>>p1;
    if((p1!='X' && p1!='x') && (p1!='O' && p1!='o')){
        cout<<"Enter a valid option"<<endl;
        cin>>p1;
    }

    cout<<"Player 2=";
    cin>>p2;
    if((p2!='X'  && p2!='x') && (p2!='O'  && p2!='o') && p1==p2){
        cout<<"Enter a valid option"<<endl;
        cin>>p2;
    }

    TicTacToe();


    return 0;
}