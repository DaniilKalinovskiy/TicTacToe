//◦ Playrix ◦


#include <iostream>

using namespace std;

void Draw();
void Input();
void isGameEnded();
void Restart();
void ChangePlayer();
void GameFinish(int);

int FirstPlayerScore = 0;
int SecondPlayerScore = 0;

char PlayingField[3][3];
int PlayerNo = 1;

int main()
{
    Draw();
    while (true)
    {        
        Input();
        system("cls");
        Draw();
        isGameEnded();
        ChangePlayer();
    }
    return 0;
}

void Draw()
{
    cout << "Score: " << FirstPlayerScore << " : " << SecondPlayerScore << endl << endl;

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
    }
    cout << endl;
}

void Input()
{
    bool isFullFieldSelected = false;
    int x;
    int y;

    while (!isFullFieldSelected)            //Проверяем, не занята ли ячейка, если да, просим ввести координаты ещё раз
    {
        cout << "Player " << PlayerNo << " Please, enter the X coordinate:" << endl;
        cin >> x;
        cout << "Please, enter the Y coordinate:" << endl;
        cin >> y;
     
        if (PlayingField[x][y] == 0)                
        {
            if (PlayerNo == 1) PlayingField[x][y] = 1;
            else PlayingField[x][y] = -1;
            isFullFieldSelected = !isFullFieldSelected;
        }
        else
            cout << "This field is not empty! \n";
    }
}

void isGameEnded()
{
    int columnSum, stringSum, generalAbsSum = 0;
    bool _isGameEnded = false;

    for (int coordX = 0; coordX < 3; coordX++)
    {
        columnSum = 0;
        stringSum = 0;
        for (int coordY = 0; coordY < 3; coordY++)
        {
            columnSum += PlayingField[coordX][coordY];
            stringSum += PlayingField[coordY][coordX];
            generalAbsSum += abs(PlayingField[coordY][coordX]);

            if (columnSum == 3 || stringSum == 3 || PlayingField[0][0] + PlayingField[1][1] + PlayingField[2][2] == 3)
            {
                FirstPlayerScore++;
                GameFinish(1);
            }
            else if (columnSum == - 3 || stringSum == - 3 || PlayingField[0][0] + PlayingField[1][1] + PlayingField[2][2] == - 3)
            {
                 SecondPlayerScore++;
                 GameFinish(-1);
            }
            else if (generalAbsSum == 9)
            {
                GameFinish(0);
            }
        }        
    }
}

void GameFinish(int winner)
{
    if (winner == 1 || winner == -1)
    {
        cout << "\n Player " << PlayerNo << " win!";
    }
    else cout << "\n All fields are filled!";
    
    cout << "\n \n want to replay? 1 - yes / 2 - no" << endl;

    int isReplayGame;
    cin >> isReplayGame;

    if (isReplayGame == 1)
    {
        Restart();
    }
    exit(0);
}

void Restart()
{
    for (int coordX = 0; coordX < 3; coordX++)
    {
        for (int coordY = 0; coordY < 3; coordY++)
        {
            PlayingField[coordX][coordY] = 0;
        }
    }
    system("cls");
    PlayerNo = 1;

    main();
}

void ChangePlayer()
{
    if (PlayerNo == 1) PlayerNo++;
    else PlayerNo--;
}




//Добавить проверку ввода данных











// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file