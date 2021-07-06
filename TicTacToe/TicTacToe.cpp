//◦ Playrix ◦
// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void Setup();
void Draw();
void Input();
void Score();

int PlayerScore = 0;
char PlayingField[3][3];
bool PlayerNo = true;
bool isGameEnded = false;

int main()
{
    while (!isGameEnded)
    {
        Draw();
        Input();
    }
    return 0;
}

void Setup()
{
    
}

void Draw()
{
    for (int coordX = 0; coordX < 3; coordX++)
    {
        for (int coordY = 0; coordY < 3; coordY++)
        {
            switch (PlayingField[coordX][coordY])
            {
            case -1:
                cout << "[O]";
                break;
            case 0:
                cout << "[ ]";
                break;
            case 1:
                cout << "[X]";
                break;
            }
        }
        cout << endl;
    }                           //Добавить вывод счета
}

void Input()
{
    int playerNo;
    int x;
    int y;

    if (PlayerNo) playerNo = 1;
    else playerNo = 2;

    cout << "Player " << playerNo << " Please, enter the X coordinate:" << endl;
    cin >> x;
    cout << "Please, enter the Y coordinate:" << endl;
    cin >> y;

    //Сделать возможность заново вводить координаты, если ячейка заполнена

    if (PlayingField[x][y] == 0)                //Проверяем, не занята ли ячейка
    {
        if (PlayerNo) PlayingField[x][y] = 1;
        else PlayingField[x][y] = -1;
    }
    else cout << "This field is not empty!";



    PlayerNo = !PlayerNo;
}

void Score()
{
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file