//◦ Playrix ◦


#include <iostream>

using namespace std;

void Draw();
void Input();
int isInputCorrect(char);
void isGameEnded();
void Restart();
void ChangePlayer();
void GameFinish(int);

int kFirstPlayerScore = 0;
int kSecondPlayerScore = 0;

char kPlayingField[3][3];
int kPlayerNo = 1;

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
    cout << "Score: " << kFirstPlayerScore << " : " << kSecondPlayerScore << endl << endl;

    for (int coordX = 0; coordX < 3; coordX++)
    {
        for (int coordY = 0; coordY < 3; coordY++)
        {
            switch (kPlayingField[coordX][coordY])
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
        x = isInputCorrect('X');
        if (kPlayingField[x][0] == 0 || kPlayingField[x][1] == 0 || kPlayingField[x][2] == 0)
        {
            y = isInputCorrect('Y');

            if (kPlayingField[x][y] == 0)
            {
                if (kPlayerNo == 1) kPlayingField[x][y] = 1;
                else kPlayingField[x][y] = -1;
                isFullFieldSelected = !isFullFieldSelected;
            }
            else
                cout << "This field is not empty! \n";
        }
        else
            cout << "This row is full! \n";
    }
}

int isInputCorrect(char coord) // Проверяем на корректность введённое значение
{
    int coordValue;
    while (true)
    {
        cout << "Player " << kPlayerNo << ", please, enter the " << coord << " coordinate (1-3):" << endl;
        cin >> coordValue;

        if (coordValue == 1 || coordValue == 2 || coordValue == 3)
        { 
            coordValue--;
            return coordValue;
        }
        else
        {
            cout << "Oops, that input is invalid.  Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
            
        
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
            columnSum += kPlayingField[coordX][coordY];
            stringSum += kPlayingField[coordY][coordX];
            generalAbsSum += abs(kPlayingField[coordY][coordX]);

            if (columnSum == 3 || stringSum == 3 || kPlayingField[0][0] + kPlayingField[1][1] + kPlayingField[2][2] == 3)
            {
                kFirstPlayerScore++;
                GameFinish(1);
            }
            else if (columnSum == - 3 || stringSum == - 3 || kPlayingField[0][0] + kPlayingField[1][1] + kPlayingField[2][2] == - 3)
            {
                 kSecondPlayerScore++;
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
        cout << "\n Player " << kPlayerNo << " win!";
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
            kPlayingField[coordX][coordY] = 0;
        }
    }
    system("cls");
    kPlayerNo = 1;

    main();
}

void ChangePlayer()
{
    if (kPlayerNo == 1) kPlayerNo++;
    else kPlayerNo--;
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