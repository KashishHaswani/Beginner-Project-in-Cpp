#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<vector<char>> game(3, vector<char> (3));
char p1;
char p2;
int count=0;
int m,n;
string name;

bool isSafe(int i, int j, int player){
    if(game[i][j]!=p1 && game[i][j]!=p2) return true;
    if(game[i][j]==p1 || game[i][j]==p2){
        cout<<"enter a different cell"<<endl;
        if(player==1){
            do{
                cin>>m>>n;
            }while(!isSafe(m-1,n-1,1));
        }
        else{
            do {
            m = rand() % 3;
            n = rand() % 3;
        } while(!isSafe(m, n, 2));
        }
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
    cout<<endl<<"------------"<<endl;
    for(int i=0; i<3; i++){
        cout<<"| ";
        for(int j=0; j<3; j++){
            cout<<game[i][j]<<" | ";
        }
        cout<<endl<<"------------"<<endl;
    }
}

void TicTacToe(){
    cout<<"Let's start the game"<<endl;
    display(game);
    while(count!=9){
        cout<<name<<", enter row (1-3) and column (1-3)(eg: row column):";
        do{
            cin>>m>>n;
        }while(!isSafe(m-1,n-1,1));
        
            game[m-1][n-1]=p1;
            display(game);
            if(won(game,p1)){
                cout<<name<<" won!!";
                return;
            }
        
        count++;
        if(count==9) return;

        cout << "Computer's turn = " ;
        do {
            m = rand() % 3;
            n = rand() % 3;
        } while(!isSafe(m, n, 2));
        cout<<m+1<<" "<<n+1;

        game[m][n] = p2;
        display(game);
        if(won(game, p2)){
            cout << "Computer won!!";
            return;
        }

        
        count++;
    }
    cout<<"Tie";
    return;
}

int main(){
    srand(time(0)); // Initialize random seed

    cout<<"Hello, Welcome to Tic Tac Toe Game!"<<endl;

    cout<<endl<<"Enter the name of the player= ";
    cin>>name;

    cout<<endl<<"Give input for the choice of "<<name<<" (in X or O)= ";

    cin >> p1;
    while((p1!='X' && p1!='x') && (p1!='O' && p1!='o')){
        cout << "Enter a valid option: ";
        cin >> p1;
    }

    p2 = (p1 == 'X' || p1 == 'x') ? 'O' : 'X';
    cout << "Computer will play as (" << p2 << ")" << endl<<endl;


    TicTacToe();


    return 0;
}