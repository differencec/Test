#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

string board[36] = " ";

//Here is teleport function;



int teleport(int initipos,int c){
    int potal_1;
    int potal_2;
    //potal is short for teleport.
    cout<<"The initial position is "<<initipos<<endl;   //To know is it work or not can be detect.
    if(initipos==7)
    {
        potal_1=7;
        potal_2=27;
    }
    else
    {
        potal_1=27;
        potal_2=7;

    }
    if(c%2==0){
         board[potal_1]="X";
         board[potal_2]="A";

    }
    else
    {
        board[potal_1]="O";
        board[potal_2]="B";
    }
    return potal_2;
}


void introduction()
{


    cout<<"Player 1) A\n";
    cout<<"Player 2) B\n";


    cout<<endl<<endl;

}



//actual board


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


//move function for a
int move(int mark)
{
    int first = mark;



    cout<<endl<<endl;


    return mark + 1;

}
//move function for s
int moveDown(int mark)
{
    int first = mark;



    cout<<endl<<endl;


    return mark + 6;

}

//move function for w
int moveUp(int mark)
{
    int first = mark;



    cout<<endl<<endl;


    return mark - 6;

}

//move function for d

int moveRight(int mark)
{
    int first = mark;



    cout<<endl<<endl;


    return mark - 1;

}



int main(void)
{
    //for random function
    srand(time(0));
    board[30] = "A";
    board[5] = "B";
    board[7]="T";
    board[27]="T";
    board[11] = "P";
    int storage[6] = {99,99,99,99,99,99};
    int miniCount = 0;
    bool valid = false;

    //for the character
    string tempo;
    string initial1 = board[30];
    string initial2 = board[5];
    //for  the current index
    int inipos1 = 30;
    int inipos2 = 5;
    int turn = 2,j = 0;
    int c = 0;
    int signal = 0,timing = 100;
    string lastMove;
    string in;
    string name;
    introduction();
    draw();
    cout<<endl<<"HOw many turn you wanna play: (5 or 10): ";
    cin>>turn;
    //checking whether the input is 5 or 10
    while(turn != 5) {
        while(turn != 10) {
                if(turn != 5)
                    break;
            cout<<"Input wrong";
            cout<<endl<<"HOw many turn you wanna play: (5 or 10): ";
    cin>>turn;
        }
        if(turn == 10)
            break;
        cout<<"Input wrong";
            cout<<endl<<"HOw many turn you wanna play: (5 or 10): ";
    cin>>turn;
    }

    //first while loop for turn
    do
    {
        //just comment
        if(c != 0) {
            cout<<endl<<endl<<endl<<"stop!!!!!!"<<endl<<endl<<endl;
        }

        int ran = (rand() % (6 - 1 + 1)) + 1;
        cout<<endl<<endl;


        //for determining player 1 or 2
        if(c % 2 == 0)
        {
            cout<<"Start player 1"<<endl<<endl;
            name = "player 1";
        }
        else
        {
            cout<<"Start player 2"<<endl<<endl;
            name = "player 2";
        }
        cout<<endl<<endl;
        cout<<name<<"'s available move according to rolling dice = "<<ran<<endl<<endl;
        j = 0;
        //while loop for running due to the control of randomized dice number
        if(c == 0) {
            cin.ignore();
        }

        cout<<endl<<endl<<"Conquer(by using aswd): ";
                getline(cin,in);
        while(j < ran)
        {

            //It's kinda messy code,sorry 'bout that.
            //Use if to determine player 1's turn or player 2's
            if(c % 2 == 0)
            {

                /*if(c == 0 && j == 0)
                {
                    cin.ignore();
                }*/

                //when user type 'd'
                if(in == "d")  ///Right Boundary
                {
                    if(inipos1 != 35 && inipos1 != 29 && inipos1 != 23 && inipos1 != 17 && inipos1 != 11 && inipos1 != 5)
                    {
                        if(board[move(inipos1)] != "B")
                        {
                            inipos1 = move(inipos1);
                            if(board[inipos1]=="T")
                            {
                                board[inipos1 - 1] = "X";
                                cout<<"Teleport actived"<<endl;
                                inipos1=teleport(inipos1,c);
                            }else if(board[inipos1]=="M"){
                                board[8]="X";
                                board[9]="X";
                                board[10]="X";
                                board[14]="X";
                                board[16]="X";
                                board[20]="X";
                                board[21]="X";
                                board[22]="X";
                            }
                            else
                            {
                                //sending signal
                                if(board[inipos1] == "P") {
                            //send signal to activate protection
                             signal = 1;
                            }

                                board[inipos1] = "A";
                                board[inipos1 - 1] = "X";


                            }

                        }

                    }
                    else
                    {
                        //draw();
                    }

                }
                //when user type 's'
                else if(in == "s")     ///Lower Boundary
                {
                    if(inipos1 != 30 && inipos1 != 31 && inipos1 != 32 && inipos1 != 33 && inipos1 != 34 && inipos1 != 35)
                    {
                        if(board[moveDown(inipos1)] != "B")
                        {
                            inipos1 = moveDown(inipos1);
                            if(board[inipos1]=="T")
                            {
                                //make the initialpos  a little early for teleport function..

                                board[inipos1 - 6] = "X";
                                cout<<"Teleport actived"<<endl;
                                inipos1=teleport(inipos1,c);
                            }else if(board[inipos1]=="M"){
                                board[8]="X";
                                board[9]="X";
                                board[10]="X";
                                board[14]="X";
                                board[16]="X";
                                board[20]="X";
                                board[21]="X";
                                board[22]="X";
                            }
                            else
                            {
                                //sending signal
                                if(board[inipos1] == "P") {
                             signal = 1;
                            }

                                board[inipos1] = "A";

                                    board[inipos1 - 6] = "X";

                            }

                        }
                    }
                    else
                    {
                        //draw();
                    }

                    }
                //when user type 'w'
                else if(in == "w")     //Upper Boundary
                {
                    if(inipos1 != 0 && inipos1 != 1 && inipos1 != 2 && inipos1 != 3 && inipos1 != 4 && inipos1 != 5)
                    {
                        if(board[moveUp(inipos1)] != "B")
                        {
                            inipos1 = moveUp(inipos1);
                            if(board[inipos1]=="T")
                            {
                                //make the initialpos  a little early for teleport function..

                                board[inipos1 + 6] = "X";
                                cout<<"Teleport actived"<<endl;
                                inipos1=teleport(inipos1,c);
                            }else if(board[inipos1]=="M"){
                                board[8]="X";
                                board[9]="X";
                                board[10]="X";
                                board[14]="X";
                                board[16]="X";
                                board[20]="X";
                                board[21]="X";
                                board[22]="X";
                            }
                            else
                                //sending signal
                            {
                                if(board[inipos1] == "P") {
                             signal = 1;
                            }


                                board[inipos1] = "A";

                                    board[inipos1 + 6] = "X";

                            }
                        }

                    }
                    else
                    {
                        //draw();
                    }


                }
                //when user type 'a'
                else if(in == "a")     ///Left Boundary
                {
                    if(inipos1 != 30 && inipos1 != 24 && inipos1 != 18 && inipos1 != 12 && inipos1 != 6 && inipos1 != 0)
                    {
                        if(board[inipos1] != "B")
                        {
                            inipos1 = moveRight(inipos1);
                            if(board[inipos1]=="T")
                            {
                                //make the initialpos  a little early for teleport function..

                                board[inipos1 + 1] = "X";
                                cout<<"Teleport actived"<<endl;
                                inipos1=teleport(inipos1,c);
                            }else if(board[inipos1]=="M"){
                                board[8]="X";
                                board[9]="X";
                                board[10]="X";
                                board[14]="X";
                                board[16]="X";
                                board[20]="X";
                                board[21]="X";
                                board[22]="X";
                            }
                            else
                                //sending signal
                            {
                                if(board[inipos1] == "P") {
                             signal = 1;
                            }



                                board[inipos1] = "A";


                                    board[inipos1 + 1] = "X";


                            }

                        }
                    }
                    else
                    {
                        //draw();
                    }

                //draw();
                }
            }
            else
            {
                /*cout<<"where you wanna go: ";
                getline(cin,in);*/

                //It's player 2 codes.

                //when user type 'd'
                if(in == "d")    ///Right Boundary
                {
                    if(inipos2 != 35 && inipos2 != 29 && inipos2 != 23 && inipos2 != 17 && inipos2 != 11 && inipos2 != 5)
                    {
                        if(board[move(inipos2)] != "A")
                        {
                            inipos2 = move(inipos2);
                            if(board[inipos2]=="T")
                            {
                                //make the initialpos  a little early for teleport function..

                                board[inipos2 - 1] = "O";
                                cout<<"Teleport actived"<<endl;
                                inipos2=teleport(inipos2,c);
                            }else if(board[inipos2]=="M"){
                                board[8]="O";
                                board[9]="O";
                                board[10]="O";
                                board[14]="O";
                                board[16]="O";
                                board[20]="O";
                                board[21]="O";
                                board[22]="O";
                            }
                            else
                            {
                                //sending signal
                                if(board[inipos2] == "P") {
                             signal = 1;
                            }

                                board[inipos2] = "B";



                                    board[inipos2 - 1] = "O";

                                //draw();
                            }
                        }
                    }
                    else
                    {
                        //draw();
                    }




                }
                //when user type 's'
                else if(in == "s")     ///Lower Boundary
                {
                    if(inipos2 != 30 && inipos2 != 31 && inipos2 != 32 && inipos2 != 33 && inipos2 != 34 && inipos2 != 35)
                    {
                        if(board[moveDown(inipos2)] != "A")
                        {
                            inipos2 = moveDown(inipos2);
                            if(board[inipos2]=="T")
                            {
                                //make the initialpos  a little early for teleport function..

                                board[inipos2 - 6] = "O";
                                cout<<"Teleport actived"<<endl;
                                inipos2=teleport(inipos2,c);
                            }else if(board[inipos2]=="M"){
                                board[8]="O";
                                board[9]="O";
                                board[10]="O";
                                board[14]="O";
                                board[16]="O";
                                board[20]="O";
                                board[21]="O";
                                board[22]="O";
                            }
                            else
                            {
                                //sending signal
                                if(board[inipos2] == "P") {
                             signal = 1;
                            }


                                board[inipos2] = "B";


                                    board[inipos2 - 6] = "O";

                                //draw();
                            }

                        }
                        else
                        {
                            //draw();
                        }
                    }

                }

                //when user type 'w'
                else if(in == "w")    ///Upper Boundary
                {
                    if(inipos2 != 0 && inipos2 != 1 && inipos2 != 2 && inipos1 != 3 && inipos2 != 4 && inipos2 != 5)
                    {
                        if(board[moveUp(inipos2)] != "A")
                        {
                            inipos2 = moveUp(inipos2);
                            if(board[inipos2]=="T")
                            {
                                //make the initialpos  a little early for teleport function..

                                board[inipos2 + 6] = "O";
                                cout<<"Teleport actived"<<endl;
                                inipos2=teleport(inipos2,c);
                            }else if(board[inipos2]=="M"){
                                board[8]="O";
                                board[9]="O";
                                board[10]="O";
                                board[14]="O";
                                board[16]="O";
                                board[20]="O";
                                board[21]="O";
                                board[22]="O";
                            }
                            else
                                //sending signal
                            {
                                if(board[inipos2] == "P") {
                             signal = 1;}

                                board[inipos2] = "B";

                                    board[inipos2 + 6] = "O";

                                //draw();
                            }



                        }
                        else
                        {
                            //draw();
                        }
                    }

                }

                //when user type 'a'
                else if(in == "a")     ///Left Boundary
                {
                    if(inipos2 != 30 && inipos2 != 24 && inipos2 != 18 && inipos2 != 12 && inipos2 != 6 && inipos2 != 0)
                    {
                        if(board[moveRight(inipos2)] != "A")
                        {
                            inipos2 = moveRight(inipos2);
                            if(board[inipos2]=="T")
                            {
                                //make the initialpos  a little early for teleport function..

                                board[inipos2 + 1] = "O";
                                cout<<"Teleport actived"<<endl;
                                inipos2=teleport(inipos2,c);
                            }else if(board[inipos2]=="M"){
                                board[8]="O";
                                board[9]="O";
                                board[10]="O";
                                board[14]="O";
                                board[16]="O";
                                board[20]="O";
                                board[21]="O";
                                board[22]="O";
                            }
                            else
                                //sending signal
                            {
                                if(board[inipos2] == "P") {
                             signal = 1;
                            }



                                board[inipos2] = "B";

                                    board[inipos2 + 1] = "O";

                                //draw();
                            }

                        }

                    }
                    else
                    {
                        //draw();
                    }

                }

            }





            j++;




        };





//changing normal square to protected square once they have signal
        if(signal) {

                for(int i = 0; i < 36; i++) {
                    if(name == "player 1") {
                            if(board[i] == "X") {
                                board[i] = "C";

                            }
                } else if(name == "player 2") {
                    if(board[i] == "O")
                        board[i] = "C";

                }
            }

            timing = c;

        }
    //when they get signal, they start storing the protected square
        if(signal) {
                for(int i = 0; i < 36; i++) {
                    if(board[i] == "C") {
                        storage[miniCount] = i;
                                miniCount++;
                    }
                }

            }

            //return square that are protected in every turn until they are deactivated
            if(!valid) {
                    for(int i = 0; i < 6; i++) {

                 {
                     board[storage[i]] = "C";
                 }
            }


            }

            signal = 0;

//determine for stopping protectin function
        if(timing + 8
            == c) {
            for(int i = 0; i < 36; i++) {
                    if(name == "player 1") {
                            if(board[i] == "C") {
                                board[i] = "X";
                            }
                } else if(name == "player 2") {
                    if(board[i] == "C")
                        board[i] = "O";
                }
            }
            valid = true;
        }
        board[inipos1] = "A";
        board[inipos2] = "B";
        draw();

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
    cout<<endl<<endl;
    cout<<"Player 1 = "<< x<<endl;
    cout<<"Player 2 = "<< o<<endl;

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
