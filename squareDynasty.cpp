#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

string board[36] = " ";


void introduction()
{


    cout<<"Player 1) X\n";
    cout<<"Player 2) O\n";

    cout<<"The 3x3 grid is shown below:\n\n";
    cout << "_____ _____ _____  ______ _______ _______ \n";
    cout << "     |     |      |      |       |       |\n";
    cout << "  1  |  2  |  3   |  4   |   5   |   6   |\n";
    cout << "_____|_____|_____ |______|_______|_______|\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "  7  |  8  |  9   |  10  |   11  |   12  |\n";
    cout << "_____|_____|_____ |______|_______|_______|\n";
    cout << "     |     |      |      |       |       |\n";
    cout << " 13  | 14  | 15   |  16  |   17  |   18  |\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "_____|_____|_____ |______|_______|_______|\n";
    cout << "     |     |      |      |       |       |\n";
    cout << " 19  | 20  | 21   |  22  |   23  |   24  |\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "_____|_____|_____ |______|_______|_______|\n";
    cout << "     |     |      |      |       |       |\n";
    cout << " 25  | 26  | 21   |  28  |   29  |   30  |\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "_____|_____|_____ |______|_______|_______|\n";
    cout << "     |     |      |      |       |       |\n";
    cout << " 31  | 32  | 33   |  34  |   35  |   36  |\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "_____|_____|_____ |______|_______|_______|\n";
    cout<<endl;

}










//move with aswd


void draw()
{
    cout << "_____ _____ ______ ______ _______ _______ \n";
    cout << "     |     |      |      |       |       |\n";
    cout << "  " << board[0] << "  |   " << board[1] << " |   " << board[2] << "  |   " <<board[3] <<"  |   "<<board[4]<<"   |   "<<board[5]<<"   |   "<< "\n";
    cout << "|____|_____|______|______|_______| ______| \n";
    cout << "     |     |      |      |       |       |\n";
    cout << "  " << board[6] << "  |   " << board[7] << " |   " << board[8] << "  |   " <<board[9] <<"  |   "<<board[10]<<"   |   "<<board[11]<<"   |   "<< "\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "|____|_____|______|______|_______| ______| \n";
    cout << "     |     |      |      |       |       |\n";
    cout << "  " << board[12] << "  |   " << board[13] << " |   " << board[14] << "  |   " <<board[15] <<"  |   "<<board[16]<<"   |   "<<board[17]<<"   |   "<< "\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "|____|_____|______|______|_______| ______| \n";
    cout << "     |     |      |      |       |       |\n";
    cout << "  " << board[18] << "  |   " << board[19] << " |   " << board[20] << "  |   " <<board[21] <<"  |   "<<board[22]<<"   |   "<<board[23]<<"   |   "<< "\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "|____|_____|______|______|_______| ______| \n";
    cout << "     |     |      |      |       |       |\n";
    cout << "  " << board[24] << "  |   " << board[25] << " |   " << board[26] << "  |   " <<board[27] <<"  |   "<<board[28]<<"   |   "<<board[29]<<"   |   "<< "\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "|____|_____|______|______|_______| ______| \n";
    cout << "     |     |      |      |       |       |\n";
    cout << "  " << board[30] << "  |   " << board[31] << " |   " << board[32] << "  |   " <<board[33] <<"  |   "<<board[34]<<"   |   "<<board[35]<<"   |   "<< "\n";
    cout << "|____|_____|______|______|_______| ______| \n";
    /*cout << "     |     |      |      |       |       |\n";
    cout << "  " << board[0] << "  |   " << board[1] << "  |   " << board[2] << "   |   " <<board[3] <<"   |   "<<board[4]<<"    |   "<<board[5]<<"    |   "<< "\n";
    cout << "     |     |      |      |       |       |\n";
    cout << "|____|_____|______|______|_______| ______| \n";
    cout << "\n";*/

}



int move(int mark)
{
    int first = mark;



    cout<<endl<<endl;


    return mark + 1;

}

int moveDown(int mark)
{
    int first = mark;



    cout<<endl<<endl;


    return mark + 6;

}

int moveUp(int mark)
{
    int first = mark;



    cout<<endl<<endl;


    return mark - 6;

}

int moveRight(int mark)
{
    int first = mark;



    cout<<endl<<endl;


    return mark - 1;

}






int main(void)
{
    srand(time(0));
    board[30] = "A";
    board[5] = "B";
    string initial1 = board[30];
    string initial2 = board[5];
    int inipos1 = 30;
    int inipos2 = 5;
    int turn,j = 0;
    int c = 0;
    introduction();
    draw();
    cout<<endl<<"HOw many turn you wanna play: ";
    cin>>turn;
    do
    {

        int ran = (rand() % (6 - 1 + 1)) + 1;
        cout<<"Your available move = "<<ran;
        cout<<endl<<endl;
        if(c % 2 == 0)
        {
            cout<<"Start player 1";
        }
        else
        {
            cout<<"Start player 2";
        }
        cout<<endl<<endl;
        j = 0;
        while(j < ran)
        {
            string in;
            if(c % 2 == 0)
            {

                if(c == 0 && j == 0)
                {
                    cin.ignore();
                }

                cout<<"where you wanna go: ";
                getline(cin,in);
                if(in == "d")
                {
                    if(inipos1 != 35 && inipos1 != 29 && inipos1 != 23 && inipos1 != 17 && inipos1 != 11 && inipos1 != 5)
                    {
                        if(board[move(inipos1)] != "B")
                        {
                            inipos1 = move(inipos1);
                            board[inipos1] = "A";
                            board[inipos1 - 1] = "X";
                            draw();
                        }
                    }
                    else
                    {
                        draw();
                    }

                }
                else if(in == "s")
                {
                    if(inipos1 != 30 && inipos1 != 31 && inipos1 != 32 && inipos1 != 33 && inipos1 != 34 && inipos1 != 35)
                    {
                        if(board[moveDown(inipos1)] != "B")
                        {
                            inipos1 = moveDown(inipos1);
                            board[inipos1] = "A";
                            board[inipos1 - 6] = "X";
                            draw();
                        }
                    }
                    else
                    {
                        draw();
                    }

                }
                else if(in == "w")
                {
                    if(inipos1 != 0 && inipos1 != 1 && inipos1 != 2 && inipos1 != 3 && inipos1 != 4 && inipos1 != 5)
                    {
                        if(board[moveUp(inipos1)] != "B")
                        {
                            inipos1 = moveUp(inipos1);
                            board[inipos1] = "A";
                            board[inipos1 + 6] = "X";
                            draw();
                        }

                    }
                    else
                    {
                        draw();
                    }


                }
                else if(in == "a")
                {
                    if(inipos1 != 30 && inipos1 != 24 && inipos1 != 18 && inipos1 != 12 && inipos1 != 6 && inipos1 != 0)
                    {
                        if(board[inipos1] != "B")
                        {
                            inipos1 = moveRight(inipos1);
                            board[inipos1] = "A";
                            board[inipos1 + 1] = "X";
                            draw();
                        }
                    }
                    else
                    {
                        draw();
                    }

                }
            }
            else
            {
                cout<<"where you wanna go: ";
                getline(cin,in);
                if(in == "d")
                {
                    if(inipos2 != 35 && inipos2 != 29 && inipos2 != 23 && inipos2 != 17 && inipos2 != 11 && inipos2 != 5)
                    {
                        if(board[move(inipos2)] != "A")
                        {
                            inipos2 = move(inipos2);
                            board[inipos2] = "B";
                            board[inipos2 - 1] = "O";
                            draw();
                        }
                    }
                    else
                    {
                        draw();
                    }




                }
                else if(in == "s")
                {
                    if(inipos2 != 30 && inipos2 != 31 && inipos2 != 32 && inipos2 != 33 && inipos2 != 34 && inipos2 != 35)
                    {
                        if(board[moveDown(inipos2)] != "A")
                        {
                            inipos2 = moveDown(inipos2);
                            board[inipos2] = "B";
                            board[inipos2 - 6] = "O";
                            draw();
                        }
                        else
                        {
                            draw();
                        }
                    }

                }
                else if(in == "w")
                {
                    if(inipos2 != 0 && inipos2 != 1 && inipos2 != 2 && inipos1 != 3 && inipos2 != 4 && inipos2 != 5)
                    {
                        if(board[moveUp(inipos2)] != "A")
                        {
                            inipos2 = moveUp(inipos2);
                            board[inipos2] = "B";
                            board[inipos2 + 6] = "O";
                            draw();


                        }
                        else
                        {
                            draw();
                        }
                    }

                }
                else if(in == "a")
                {
                    if(inipos2 != 30 && inipos2 != 24 && inipos2 != 18 && inipos2 != 12 && inipos2 != 6 && inipos2 != 0)
                    {
                        if(board[moveRight(inipos2)] != "A")
                        {
                            inipos2 = moveRight(inipos2);
                            board[inipos2] = "B";
                            board[inipos2 + 1] = "O";
                            draw();
                        }

                    }
                    else
                    {
                        draw();
                    }

                }

            }



            j++;



        };
        c++;
    }
    while(c != turn * 2);
    int o = 0,x = 0;
    for(int d = 0; d < 36; d++)
    {
        if(board[d] == "O")
        {
            o++;
        }
        else if(board[d] == "X")
        {
            x++;
        }
    }

    if(o > x)
    {
        cout<<"player 2 = winner";
    }
    else if(o == x)
    {
        cout<<"a tie";
    }
    else
    {
        cout<<"player 1 = winner";

    }






    /*take_turn();
    end_game();*/
    return 0;
}
