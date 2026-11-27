#include <iostream>
#include <iomanip>
const int MAXN = 8;
struct Chess {
    char board[MAXN][MAXN]; 
    int current; 
    int score1; int score2; int draws; 
    bool over; bool wK; bool wQ; bool bQ; bool bK;
};
bool readint(int *val) {
    using std::cin;
    if(cin >> *(val)) {
        return true;
    }
    cin.clear();
    cin.ignore(10000,'\n');
    return false;

}
void showMenu() {
    using std::cout; using std::setw; using std::endl;
    cout << "====" << std::right << setw(6) << "Chess"  <<setw(5) << "====" << endl
         << endl << " 1. New game\n 2. Save game\n 3. Load game\n 4. Show scores\n 5. Play versus Computer\n 0. Exit"
         << endl << endl << "Choice: ";
}
void newGame(Chess *g) {
    const char pieces[MAXN] = {'r','n','b','q','k','b','n','r'};
    (*g).current = 1;
    (*g).over = false;
    for (int r = 0; r < MAXN; r++) 
        for (int c = 0; c <  MAXN; c++) 
            (*g).board[r][c] = '.';
    for (int c = 0; c <  MAXN; c++) {
        (*g).board[0][c] = pieces[c];
        (*g).board[1][c] = 'p';
        (*g).board[6][c] = 'P';
        (*g).board[7][c] = pieces[c];
        
    }
        
    
}

void printBoard(const Chess *g) {
    using std::cout; using std::setw; using std::endl;
   

    for (int i = 0; i <  MAXN; i++) {
        cout << setw(3) << MAXN-i;
        for (int r= 0; r < MAXN; r++) 
            cout << setw(3) << (*g).board[i][r];
        cout << endl;
    }
    cout << setw(3) << "";
    for (char i = 'a'; i <= 'h'; i++) 
        cout << setw(3) << i;
    cout << endl;
}
void showScores(const Chess *g) {
    using std::cout;
    cout << "Player 1 is at: " << (*g).score1 << " wins.\n";
    cout << "Player 2 is at: " << (*g).score2 << " wins.\n";
    cout << "Currently at " << (*g).draws << " amount of draws\n";
}




int main() {
    using std::cout; using std::cin;
    Chess c = {};
    newGame(&c);
    int choice = 0;
   
    do {
        showMenu();
        while(!readint(&choice)) {
            cout << "Please Enter a number: ";
        }
        switch (choice) {
            case 1: newGame(&c); printBoard(&c); break;
            case 4: showScores(&c); 
            case 0: cout << "Exiting\n"; break;
            default: cout << "Invalid input, 0 to exit.\n";
        }
    } while (choice != 0);



    return 0;
}