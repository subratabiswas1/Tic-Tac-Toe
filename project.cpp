// Tic Tac Toe Game
#include <bits/stdc++.h>
#include <Windows.h> //used for PlaySound function
#include <mmsystem.h>
#include <stdlib.h>
#pragma comment(lib, "-lWinmm.lib")

using namespace std;

class TicTacToe
{
    string square;
    int player,choice,i;
    char mark;
    int checkWin();
    void drawBoard();
    void checkIfDone();
public:
    void init();
};
void TicTacToe::init()
{
start:
    square = "0123456789";
    system("color 5b");
    player = 1,choice=-1;
    do
    {
        drawBoard();
        checkIfDone();
    } while (i == -1);

    drawBoard();
    if (i == 1)
    {
        cout << "\t==>Player " << --player << " won";
        // PlaySound(TEXT("D:\\Data Structures\\StarWars3.wav"),NULL,SND_FILENAME | SND_ASYNC);
        Beep(1000, 2000);
        goto start;
    }
    else
    {
        cout << "\t==>Game draw";
        Beep(1000, 2000);
        goto start;
    }
}
void TicTacToe::checkIfDone(){
    player = (player % 2) ? 1 : 2;
        cout << "\tPlayer " << player << ",enter the choice : ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            cout<<"\tInvalid option !";
            Beep(1000, 500);
            player--;
        }
        Beep(500, 100);
        i = checkWin();
        player++;
}
int TicTacToe::checkWin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
void TicTacToe::drawBoard()
{
    system("cls");
    cout << "\n\n\t\tTic Tac Toe \n\n";
    cout << "\tPlayer1 (X) - Player2 (O) \n\n";
    cout << "\t    _____ _____ _____ " << endl;
    cout << "\t   |     |     |     |" << endl;
    cout << "\t   |  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  |" << endl;
    cout << "\t   |_____|_____|_____|" << endl;
    cout << "\t   |     |     |     |" << endl;
    cout << "\t   |  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  |" << endl;
    cout << "\t   |_____|_____|_____|" << endl;
    cout << "\t   |     |     |     |" << endl;
    cout << "\t   |  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  |" << endl;
    cout << "\t   |_____|_____|_____|" << endl << endl;
}
int main()
{
    TicTacToe t;
    t.init();
}