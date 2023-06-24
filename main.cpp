#include <iostream>
using namespace std;

int main(){
    /*Creating game zone*/
    int gspace[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            gspace[i][j] = 0;
        }
    }

    /*Creating actived game zone*/
    bool gspace_isactived[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            gspace_isactived[i][j] = false;
        }
    }

    /*Adding bombs*/
    int bombs[2][10];
    int i = 0, x = 0, y = 0;
    srand(time(NULL));
    while (i<10)
    {
        x = rand()%10;
        y = rand()%10;
        if (gspace[y][x] == 0){
            gspace[y][x] = 9; //bomb
            bombs[0][i] = x;
            bombs[1][i] = y;
            i++;
        }
    }

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(gspace[i][j]!=9){
                if(i==0){
                    if(j==0){
                        if(gspace[i+1][j] == 9) gspace[i][j]++;
                        if(gspace[i+1][j+1] == 9) gspace[i][j]++;
                        if(gspace[i][j+1] == 9) gspace[i][j]++;
                    }
                    else if(j==9){
                        if(gspace[i+1][j] == 9) gspace[i][j]++;
                        if(gspace[i+1][j-1] == 9) gspace[i][j]++;
                        if(gspace[i][j-1] == 9) gspace[i][j]++;
                    }
                    else{
                        if(gspace[i+1][j] == 9) gspace[i][j]++;
                        if(gspace[i+1][j+1] == 9) gspace[i][j]++;
                        if(gspace[i+1][j-1] == 9) gspace[i][j]++;
                        if(gspace[i][j+1] == 9) gspace[i][j]++;
                        if(gspace[i][j-1] == 9) gspace[i][j]++;
                    }
                }
                else if(i==9){
                    if(j==0){
                        if(gspace[i-1][j] == 9) gspace[i][j]++;
                        if(gspace[i-1][j+1] == 9) gspace[i][j]++;
                        if(gspace[i][j+1] == 9) gspace[i][j]++;
                    }
                    else if(j==9){
                        if(gspace[i-1][j] == 9) gspace[i][j]++;
                        if(gspace[i-1][j-1] == 9) gspace[i][j]++;
                        if(gspace[i][j-1] == 9) gspace[i][j]++;
                    }
                    else{
                        if(gspace[i-1][j] == 9) gspace[i][j]++;
                        if(gspace[i-1][j+1] == 9) gspace[i][j]++;
                        if(gspace[i-1][j-1] == 9) gspace[i][j]++;
                        if(gspace[i][j+1] == 9) gspace[i][j]++;
                        if(gspace[i][j-1] == 9) gspace[i][j]++;
                    }
                }
                else if(j==0){
                    if(gspace[i+1][j] == 9) gspace[i][j]++;
                    if(gspace[i+1][j+1] == 9) gspace[i][j]++;
                    if(gspace[i][j+1] == 9) gspace[i][j]++;
                    if(gspace[i-1][j+1] == 9) gspace[i][j]++;
                    if(gspace[i-1][j] == 9) gspace[i][j]++;
                }
                else if(j==9){
                    if(gspace[i+1][j] == 9) gspace[i][j]++;
                    if(gspace[i+1][j-1] == 9) gspace[i][j]++;
                    if(gspace[i][j-1] == 9) gspace[i][j]++;
                    if(gspace[i-1][j] == 9) gspace[i][j]++;
                    if(gspace[i-1][j-1] == 9) gspace[i][j]++;
                }
                else{
                    if(gspace[i+1][j] == 9) gspace[i][j]++;
                    if(gspace[i+1][j+1] == 9) gspace[i][j]++;
                    if(gspace[i+1][j-1] == 9) gspace[i][j]++;
                    if(gspace[i][j+1] == 9) gspace[i][j]++;
                    if(gspace[i][j-1] == 9) gspace[i][j]++;
                    if(gspace[i-1][j] == 9) gspace[i][j]++;
                    if(gspace[i-1][j+1] == 9) gspace[i][j]++;
                    if(gspace[i-1][j-1] == 9) gspace[i][j]++;
                }
            }
        }
    }

    /*user actions part*/
    int moves = 0;
    while(true){
        system("reset");
        cout << "Сапер" << endl;

        /*View of game zone*/
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if(gspace_isactived[i][j]){
                    cout << gspace[i][j];
                }
                else{
                    cout << " ";
                }
            }
            cout << "\n";
        }

        /*user actions part*/
        if (moves >= 90){
            cout << "You are win;)" << endl;
            break;
        }
        cout << "input right-left up-down(e.g. 3 5)" << endl << moves << " moves" << endl;
        cin >> x >> y;
        if (gspace[y][x] == 9){
            cout << "YOU ARE LOSE ;(" << endl;
            break;
        }
        else if (!gspace_isactived[y][x]){
            gspace_isactived[y][x] = true;
            moves++;
            /*free zone*/
            for (int o = 0; o < 100; o++){
                for (int i = 0; i < 10; i++){
                    for (int j = 0; j < 10; j++){
                        if (gspace[i][j] == 0 && gspace_isactived[i][j]){
                            if(i==0){
                                if(j==0){
                                    if(!gspace_isactived[i+1][j]) {gspace_isactived[i+1][j]=true;moves++;}
                                    if(!gspace_isactived[i+1][j+1]) {gspace_isactived[i+1][j+1]=true;moves++;}
                                    if(!gspace_isactived[i][j+1]) {gspace_isactived[i][j+1]=true;moves++;}
                                }
                                else if(j==9){
                                    if(!gspace_isactived[i+1][j]) {gspace_isactived[i+1][j]=true;moves++;}
                                    if(!gspace_isactived[i+1][j-1]) {gspace_isactived[i+1][j-1]=true;moves++;}
                                    if(!gspace_isactived[i][j-1]) {gspace_isactived[i][j-1]=true;moves++;}
                                }
                                else{
                                    if(!gspace_isactived[i+1][j]) {gspace_isactived[i+1][j]=true;moves++;}
                                    if(!gspace_isactived[i+1][j+1]) {gspace_isactived[i+1][j+1]=true;moves++;}
                                    if(!gspace_isactived[i+1][j-1]) {gspace_isactived[i+1][j-1]=true;moves++;}
                                    if(!gspace_isactived[i][j+1]) {gspace_isactived[i][j+1]=true;moves++;}
                                    if(!gspace_isactived[i][j-1]) {gspace_isactived[i][j-1]=true;moves++;}
                                }
                            }
                            else if(i==9){
                                if(j==0){
                                    if(!gspace_isactived[i-1][j]) {gspace_isactived[i-1][j]=true;moves++;}
                                    if(!gspace_isactived[i-1][j+1]) {gspace_isactived[i-1][j+1]=true;moves++;}
                                    if(!gspace_isactived[i][j+1]) {gspace_isactived[i][j+1]=true;moves++;}
                                }
                                else if(j==9){
                                    if(!gspace_isactived[i-1][j]) {gspace_isactived[i-1][j]=true;moves++;}
                                    if(!gspace_isactived[i-1][j-1]) {gspace_isactived[i-1][j-1]=true;moves++;}
                                    if(!gspace_isactived[i][j-1]) {gspace_isactived[i][j]=true;moves++;}
                                }
                                else{
                                    if(!gspace_isactived[i-1][j]) {gspace_isactived[i-1][j]=true;moves++;}
                                    if(!gspace_isactived[i-1][j+1]) {gspace_isactived[i-1][j+1]=true;moves++;}
                                    if(!gspace_isactived[i-1][j-1]) {gspace_isactived[i-1][j-1]=true;moves++;}
                                    if(!gspace_isactived[i][j+1]) {gspace_isactived[i][j+1]=true;moves++;}
                                    if(!gspace_isactived[i][j-1]) {gspace_isactived[i][j-1]=true;moves++;}
                                }
                            }
                            else if(j==0){
                                if(!gspace_isactived[i+1][j]) {gspace_isactived[i+1][j]=true;moves++;}
                                if(!gspace_isactived[i+1][j+1]) {gspace_isactived[i+1][j+1]=true;moves++;}
                                if(!gspace_isactived[i][j+1]) {gspace_isactived[i][j+1]=true;moves++;}
                                if(!gspace_isactived[i-1][j+1]) {gspace_isactived[i-1][j+1]=true;moves++;}
                                if(!gspace_isactived[i-1][j]) {gspace_isactived[i-1][j]=true;moves++;}
                            }
                            else if(j==9){
                                if(!gspace_isactived[i+1][j]) {gspace_isactived[i+1][j]=true;moves++;}
                                if(!gspace_isactived[i+1][j-1]) {gspace_isactived[i+1][j-1]=true;moves++;}
                                if(!gspace_isactived[i][j-1]) {gspace_isactived[i][j-1]=true;moves++;}
                                if(!gspace_isactived[i-1][j]) {gspace_isactived[i-1][j]=true;moves++;}
                                if(!gspace_isactived[i-1][j-1]) {gspace_isactived[i-1][j-1]=true;moves++;}
                            }
                            else{
                                if(!gspace_isactived[i+1][j]) {gspace_isactived[i+1][j]=true;moves++;}
                                if(!gspace_isactived[i+1][j+1]) {gspace_isactived[i+1][j+1]=true;moves++;}
                                if(!gspace_isactived[i+1][j-1]) {gspace_isactived[i+1][j-1]=true;moves++;}
                                if(!gspace_isactived[i][j+1]) {gspace_isactived[i][j+1]=true;moves++;}
                                if(!gspace_isactived[i][j-1]) {gspace_isactived[i][j-1]=true;moves++;}
                                if(!gspace_isactived[i-1][j]) {gspace_isactived[i-1][j]=true;moves++;}
                                if(!gspace_isactived[i-1][j+1]) {gspace_isactived[i-1][j+1]=true;moves++;}
                                if(!gspace_isactived[i-1][j-1]) {gspace_isactived[i-1][j-1]=true;moves++;}
                            }
                        }
                    }
                }
            }
        }
    }
}