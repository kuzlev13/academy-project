#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "single_include/nlohmann/json.hpp"
#include "winner1.json"
#include "winner2.json"
#include "winner3.json"
#include "winner4.json"
#include "winner5.json"
using namespace std;
struct Person{
    string name = "Anonymous";
    int time = int(INFINITY);
};
struct TableOfResults{
    Person first;
    Person second;
    Person third;
    Person fourth;
    Person fifth;
};
int main()
{
    /*Creating game zone*/
    int gspace[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            gspace[i][j] = 0;
        }
    }

    /*Creating actived game zone*/
    bool gspace_isactived[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            gspace_isactived[i][j] = false;
        }
    }

    /*Adding bombs*/
    int bombs[2][10];
    int i = 0, x = 0, y = 0;
    srand(time(NULL));
    while (i < 10)
    {
        x = rand() % 10;
        y = rand() % 10;
        if (gspace[y][x] == 0)
        {
            gspace[y][x] = 9; // bomb
            bombs[0][i] = x;
            bombs[1][i] = y;
            i++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (gspace[i][j] != 9)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        if (gspace[i + 1][j] == 9)
                            gspace[i][j]++;
                        if (gspace[i + 1][j + 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i][j + 1] == 9)
                            gspace[i][j]++;
                    }
                    else if (j == 9)
                    {
                        if (gspace[i + 1][j] == 9)
                            gspace[i][j]++;
                        if (gspace[i + 1][j - 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i][j - 1] == 9)
                            gspace[i][j]++;
                    }
                    else
                    {
                        if (gspace[i + 1][j] == 9)
                            gspace[i][j]++;
                        if (gspace[i + 1][j + 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i + 1][j - 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i][j + 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i][j - 1] == 9)
                            gspace[i][j]++;
                    }
                }
                else if (i == 9)
                {
                    if (j == 0)
                    {
                        if (gspace[i - 1][j] == 9)
                            gspace[i][j]++;
                        if (gspace[i - 1][j + 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i][j + 1] == 9)
                            gspace[i][j]++;
                    }
                    else if (j == 9)
                    {
                        if (gspace[i - 1][j] == 9)
                            gspace[i][j]++;
                        if (gspace[i - 1][j - 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i][j - 1] == 9)
                            gspace[i][j]++;
                    }
                    else
                    {
                        if (gspace[i - 1][j] == 9)
                            gspace[i][j]++;
                        if (gspace[i - 1][j + 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i - 1][j - 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i][j + 1] == 9)
                            gspace[i][j]++;
                        if (gspace[i][j - 1] == 9)
                            gspace[i][j]++;
                    }
                }
                else if (j == 0)
                {
                    if (gspace[i + 1][j] == 9)
                        gspace[i][j]++;
                    if (gspace[i + 1][j + 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i][j + 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i - 1][j + 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i - 1][j] == 9)
                        gspace[i][j]++;
                }
                else if (j == 9)
                {
                    if (gspace[i + 1][j] == 9)
                        gspace[i][j]++;
                    if (gspace[i + 1][j - 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i][j - 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i - 1][j] == 9)
                        gspace[i][j]++;
                    if (gspace[i - 1][j - 1] == 9)
                        gspace[i][j]++;
                }
                else
                {
                    if (gspace[i + 1][j] == 9)
                        gspace[i][j]++;
                    if (gspace[i + 1][j + 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i + 1][j - 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i][j + 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i][j - 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i - 1][j] == 9)
                        gspace[i][j]++;
                    if (gspace[i - 1][j + 1] == 9)
                        gspace[i][j]++;
                    if (gspace[i - 1][j - 1] == 9)
                        gspace[i][j]++;
                }
            }
        }
    }

    /*user actions part*/
    int moves = 0;
    clock_t startt = clock();
    Person winner1loc = winner1.json;
    Person winner2loc = winner2.json;
    Person winner3loc = winner3.json;
    Person winner4loc = winner4.json;
    Person winner5loc = winner5.json;
    while (true)
    {
        system("reset");
        cout << "Сапер" << endl;

        /*View of game zone*/
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (gspace_isactived[i][j])
                {
                    cout << gspace[i][j];
                }
                else
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }

        /*user actions part*/
        if (moves >= 90)
        {
            clock_t endt = clock();
            Person winner;
            cout << "You are win;)" << endl;
            cout << "Moves: " << moves << endl;
            cout << "time: " << (double)(endt - startt) / CLOCKS_PER_SEC << endl;
            winner.time = (double)(endt - startt) / CLOCKS_PER_SEC;
            getline(cin, winner.name);
            break;
        }
        cout << "input right down(e.g. 3 5)" << endl
             << moves << " moves" << endl;
        cin >> x >> y;
        if (gspace[y][x] == 9)
        {
            clock_t endt = clock();
            cout << "YOU ARE LOSE ;(" << endl;
            cout << "Moves: " << moves << endl;
            cout << "time: " << (double)(endt - startt) / CLOCKS_PER_SEC << endl;
            break;
        }
        else if (!gspace_isactived[y][x])
        {
            gspace_isactived[y][x] = true;
            moves++;
            /*free zone*/
            for (int o = 0; o < 100; o++)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (gspace[i][j] == 0 && gspace_isactived[i][j])
                        {
                            if (i == 0)
                            {
                                if (j == 0)
                                {
                                    if (!gspace_isactived[i + 1][j])
                                    {
                                        gspace_isactived[i + 1][j] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i + 1][j + 1])
                                    {
                                        gspace_isactived[i + 1][j + 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i][j + 1])
                                    {
                                        gspace_isactived[i][j + 1] = true;
                                        moves++;
                                    }
                                }
                                else if (j == 9)
                                {
                                    if (!gspace_isactived[i + 1][j])
                                    {
                                        gspace_isactived[i + 1][j] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i + 1][j - 1])
                                    {
                                        gspace_isactived[i + 1][j - 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i][j - 1])
                                    {
                                        gspace_isactived[i][j - 1] = true;
                                        moves++;
                                    }
                                }
                                else
                                {
                                    if (!gspace_isactived[i + 1][j])
                                    {
                                        gspace_isactived[i + 1][j] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i + 1][j + 1])
                                    {
                                        gspace_isactived[i + 1][j + 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i + 1][j - 1])
                                    {
                                        gspace_isactived[i + 1][j - 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i][j + 1])
                                    {
                                        gspace_isactived[i][j + 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i][j - 1])
                                    {
                                        gspace_isactived[i][j - 1] = true;
                                        moves++;
                                    }
                                }
                            }
                            else if (i == 9)
                            {
                                if (j == 0)
                                {
                                    if (!gspace_isactived[i - 1][j])
                                    {
                                        gspace_isactived[i - 1][j] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i - 1][j + 1])
                                    {
                                        gspace_isactived[i - 1][j + 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i][j + 1])
                                    {
                                        gspace_isactived[i][j + 1] = true;
                                        moves++;
                                    }
                                }
                                else if (j == 9)
                                {
                                    if (!gspace_isactived[i - 1][j])
                                    {
                                        gspace_isactived[i - 1][j] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i - 1][j - 1])
                                    {
                                        gspace_isactived[i - 1][j - 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i][j - 1])
                                    {
                                        gspace_isactived[i][j] = true;
                                        moves++;
                                    }
                                }
                                else
                                {
                                    if (!gspace_isactived[i - 1][j])
                                    {
                                        gspace_isactived[i - 1][j] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i - 1][j + 1])
                                    {
                                        gspace_isactived[i - 1][j + 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i - 1][j - 1])
                                    {
                                        gspace_isactived[i - 1][j - 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i][j + 1])
                                    {
                                        gspace_isactived[i][j + 1] = true;
                                        moves++;
                                    }
                                    if (!gspace_isactived[i][j - 1])
                                    {
                                        gspace_isactived[i][j - 1] = true;
                                        moves++;
                                    }
                                }
                            }
                            else if (j == 0)
                            {
                                if (!gspace_isactived[i + 1][j])
                                {
                                    gspace_isactived[i + 1][j] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i + 1][j + 1])
                                {
                                    gspace_isactived[i + 1][j + 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i][j + 1])
                                {
                                    gspace_isactived[i][j + 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i - 1][j + 1])
                                {
                                    gspace_isactived[i - 1][j + 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i - 1][j])
                                {
                                    gspace_isactived[i - 1][j] = true;
                                    moves++;
                                }
                            }
                            else if (j == 9)
                            {
                                if (!gspace_isactived[i + 1][j])
                                {
                                    gspace_isactived[i + 1][j] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i + 1][j - 1])
                                {
                                    gspace_isactived[i + 1][j - 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i][j - 1])
                                {
                                    gspace_isactived[i][j - 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i - 1][j])
                                {
                                    gspace_isactived[i - 1][j] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i - 1][j - 1])
                                {
                                    gspace_isactived[i - 1][j - 1] = true;
                                    moves++;
                                }
                            }
                            else
                            {
                                if (!gspace_isactived[i + 1][j])
                                {
                                    gspace_isactived[i + 1][j] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i + 1][j + 1])
                                {
                                    gspace_isactived[i + 1][j + 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i + 1][j - 1])
                                {
                                    gspace_isactived[i + 1][j - 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i][j + 1])
                                {
                                    gspace_isactived[i][j + 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i][j - 1])
                                {
                                    gspace_isactived[i][j - 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i - 1][j])
                                {
                                    gspace_isactived[i - 1][j] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i - 1][j + 1])
                                {
                                    gspace_isactived[i - 1][j + 1] = true;
                                    moves++;
                                }
                                if (!gspace_isactived[i - 1][j - 1])
                                {
                                    gspace_isactived[i - 1][j - 1] = true;
                                    moves++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}