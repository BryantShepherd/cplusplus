#include <iostream>
using namespace std;
class Gameboard
{
    char gameSpace[3][3];
    public:
        Gameboard() { //tao bang 3x3 voi phan tu la '-'
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    gameSpace[i][j] = '-';
                }
            }
        } 
        void setGameSpace(int row, int column, char value) { //buoc di cua nguoi choi
            while (gameSpace[row - 1][column - 1] != '-') {
                cout << "Invalid Move." << endl;
                cout << "Reenter your move: ";
                cin >> row >> column;
            }
            gameSpace[row - 1][column - 1] = value;
        }

        bool winCondition() { //kiem tra dieu kien thang
            for (int i = 0; i < 3; i++) {
                if (gameSpace[i][0] == gameSpace[i][1] && gameSpace[i][1] == gameSpace[i][2] && gameSpace[i][1] != '-') return true;
                if (gameSpace[0][i] == gameSpace[1][i] && gameSpace[1][i] == gameSpace[2][i] && gameSpace[1][i] != '-') return true;
                if (gameSpace[0][0] == gameSpace[1][1] && gameSpace[1][1] == gameSpace[2][2] && gameSpace[1][1] != '-') return true;
                if (gameSpace[0][2] == gameSpace[1][1] && gameSpace[1][1] == gameSpace[2][0] && gameSpace[1][1] != '-') return true;
                return false;
            }
        }

        void show_gameSpace() { //in game board sau moi nuoc di
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << gameSpace[i][j] << " ";
                }
                cout << endl;
            }
        }


};

int main() {
    Gameboard map;
    map.show_gameSpace();
    int so_luot = 1;
    int row, column;
    while(so_luot <= 9) {
        cout << "Your move: ";
        cin >> row >> column;
        if (so_luot % 2 == 1) map.setGameSpace(row, column, 'X');
        else map.setGameSpace(row, column, 'O');
        map.show_gameSpace();
        if (map.winCondition()) {
            if (so_luot % 2 == 1) {
                cout << "Player 1 Win. " << endl;
                break;
            }
            else {
                cout << "Player 2 Win. " << endl;
                break;
            }
        }
        if (so_luot == 9) cout << "GAME OVER. " << endl;        
        so_luot++;

    }
}