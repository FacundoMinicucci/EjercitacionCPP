#include <iostream>
#include <Windows.h>
#include <random>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;


void PrintGameOver()
{
    /*
    *   ASCII ART: https://patorjk.com/software/taag/
    *   Font: Small Slant
    */
    cout << "  ________   __  _______  ____ _   _________" << endl;
    cout << " / ___/ _ | /  |/  / __/ / __ \\ | / / __/ _ \\" << endl;
    cout << "/ (_ / __ |/ /|_/ / _/  / /_/ / |/ / _// , _/" << endl;
    cout << "\\___/_/ |_/_/  /_/___/  \\____/|___/___/_/|_|" << endl;
}


void ShowConsoleCursor(bool showFlag)
{
    /*
    * Obtiene las propiedades del cursor en el buffer de salida
    * Modifica la propiedad bVisible para que no pueda visualizarse en terminal
    */
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}


// TODO: ENCHANCEMENT - Lograr que refresque unicamente la zona de juego en vez de todo el mapa
void ClearScreen(int x=0, int y=0)
{
    /*
    * Sobrescribe la salida de la terminal a partir del eje de coordenadas que se le indique
    * Esto permite no tener que reimprimir todo por cada iteracion del ciclo.
    */
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}


bool IsKeyPressed(char key)
{
    return GetKeyState(key) < 0;
}


void PrintWidth(char charToPrint, int widthLength)
{
    for(int i = 0; i < widthLength; i++)
    {
        cout << charToPrint;
        cout << " ";
    }
    cout << endl;
}


int GetNewPointPos(char pos, int xLimit, int yLimit)
{
    int xPos = 1;
    switch (pos)
    {
        case 'X':
            while(xPos % 2 != 0)
            {
                xPos = (rand() % xLimit);
            }
            return xPos;
        case 'Y':
            return (rand() % yLimit);      
        default:
            return 0;
    }
}


int main()
{
    char clearWinCommand[] = "cls";
    const char boxChar = '#';
    const char ballChar = 'o';
    const char player = '@';
    const char point = '*';
    const int boxSize = 20;
    int score = 0;
    int highScore = 0;

    int playerPosX = 0;
    int playerPosY = 10;

    int ballPosX = 10;
    int ballPosY = 5;

    int ballSpeedX = 2;
    int ballSpeedY = 1;

    int playerSpeedXValue = 2;
    int playerSpeedYValue = 1;

    int playerSpeedX = 0;
    int playerSpeedY = 0;

    bool gameRunning = true;

    int realSquareHeight = boxSize - 2;
    int realSquareArea = boxSize * 2 - 3;

    int pointPosX = GetNewPointPos('X', realSquareArea, realSquareHeight);
    int pointPosY = GetNewPointPos('Y', realSquareArea, realSquareHeight);

    system(clearWinCommand);
    ShowConsoleCursor(false);
    srand(time(0));

    // TODO: ENCHANCEMENT - Bloquear el tiempo por ciclo (en criollo, bloquear los FPS)
    while(gameRunning)
    {
        int realSquareHeight = boxSize - 2;
        int realSquareArea = boxSize * 2 - 3;
        cout << "Agarra los * que veas en pantalla y gana puntos. Usa WASD para moverte. Q para salir." << endl;
        
        // Proccess input
        if (IsKeyPressed('Q'))
        {
            gameRunning = !gameRunning;
        }
        if(IsKeyPressed('W'))
        {
            playerSpeedY = -playerSpeedYValue;
        }
        else if(IsKeyPressed('S'))
        {
            playerSpeedY = playerSpeedYValue;
        }
        else
        {
            playerSpeedY = 0;
        }
        if(IsKeyPressed('A'))
        {
            playerSpeedX = -playerSpeedXValue;
        }
        else if(IsKeyPressed('D'))
        {
            playerSpeedX = playerSpeedXValue;
        }
        else
        {
            playerSpeedX = 0;
        }


        // Update cicle
        if (ballPosX == realSquareArea - 1 || ballPosX == 0)
        {
            ballSpeedX = -ballSpeedX;
        }
        if (ballPosY == realSquareHeight - 1 || ballPosY == 0)
        {
            ballSpeedY = -ballSpeedY;
        }

        if (playerPosX > realSquareArea || playerPosX < 0)
        {
            if (playerPosX > realSquareArea) playerPosX = realSquareArea - 1;
            if (playerPosX < 0) playerPosX = 0;
        }
        else
        {
            playerPosX += playerSpeedX;
        }

        if (playerPosY >= realSquareHeight || playerPosY <= -1)
        {
            if (playerPosY >= realSquareHeight) playerPosY = realSquareHeight - 1;
            if (playerPosY <= -1) playerPosY = 0;
        }
        else
        {
            playerPosY += playerSpeedY;
        }

        if (playerPosX == pointPosX && playerPosY == pointPosY)
        {
            score += 10;
            pointPosX = GetNewPointPos('X', realSquareArea, 0);
            pointPosY = GetNewPointPos('Y', 0, realSquareHeight);
        }
        ballPosX += ballSpeedX;
        ballPosY += ballSpeedY;


        // Render
        PrintWidth(boxChar, boxSize);
        for (int i = 0; i < realSquareHeight; i++)  // y axis
        {
            cout << boxChar;
            for (int j = 0; j < realSquareArea; j++)    // x axis
            {
                bool printBall = i == ballPosY && j == ballPosX;
                bool printPlayer = i == playerPosY && j == playerPosX;
                bool printPoint = i == pointPosY && j == pointPosX;
                if (printBall || printPlayer || printPoint)
                {
                    // TODO: BUG - De manera random imprime un # de mas cuando "colisionamos" con el punto
                    if (printBall && printPlayer) gameRunning = !gameRunning;
                    if (printBall && printPoint) cout << ballChar;
                    if (printPlayer && printPoint) cout << player;
                    if (printPlayer) cout << player;
                    if (printBall && !printPoint) cout << ballChar;
                    if (printPoint && !printBall) cout << point;
                }
                else
                {
                    cout << " ";
                }
            }
            cout << boxChar << endl;
        }
        PrintWidth(boxChar, boxSize);
        cout << "   Puntos: " << score << endl;
        cout << "   Record: " << highScore << endl;
        ClearScreen();

        //EndGame
        if (!gameRunning)
        {
            system(clearWinCommand);
            PrintGameOver();
            if (score > highScore)
            {
                highScore = score;
                cout << "Nuevo record! " << highScore << endl;
            }
            else
            {
                cout << "Puntos: " << score << endl;
            }
            cout << "Desea jugar de nuevo? y/n" << endl;
            HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
            FlushConsoleInputBuffer(in);
            char option;
            cin >> option;
            switch (option)
            {
                case 'y':
                    score = 0;
                    gameRunning = true;
                    system(clearWinCommand);
                case 'n':
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}