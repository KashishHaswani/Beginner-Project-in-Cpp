#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char computer_ch(){
    int randNum = rand()%3;
    if(randNum==0) return 'r';
    else if(randNum==1) return 'p';
    else return 's';
}

bool isValid(char c) {
    return c == 'r' || c == 'p' || c == 's';
}

int main() {
    srand(time(0));

    cout << "Hello, Welcome to ROCK, PAPER AND SCISSORS game!" << endl;

    cout << "Enter choice of player\n(Rock as 'r', Paper as 'p', Scissor as 's')\n";

    int a,b=0,c=0;
    cout<<"enter number of rounds you want to play= "<<endl;
    cin>>a;

    string si;
    cout << "Player name = ";
    cin >> si;

    while(a--){
        char m, n;
       
        
        cout<<"enter "<<si<<"'s choice= ";
        cin>>m;

        n=computer_ch();
        cout<<"computer= "<<n<<endl;

        if (!isValid(m) || !isValid(n)) {
            cout << "Invalid input! Please enter 'r', 'p', or 's' only." << endl;
            return 0;
        }

        if ((m == 'r' && n == 's') || (m == 'p' && n == 'r') || (m == 's' && n == 'p')) {
            b++;
        }
        else {
            c++;
        }
    }
    
    if(b>c) cout<<si<<" won by"<<b-c<<" scores!";
    else if(b<c) cout<<"computer won by"<<c-b<<" scores!";
    else cout<<"draw";

    return 0;
}
