#include <iostream>
#include <cstdlib>
#include <time.h>
#include<iomanip>
#include<windows.h>
#include<string>
#include<cmath>

using namespace std;
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

//Here are added variable for board

int bc=2;//board color;
int p1c=3;//player 1 color;
int p2c=4;//player 2 color;
int p1mc=5;//player 1 main color;
int p2mc=6;//player 2 main color;
int pc=8;//protect color;
int bpc=9;//board power color;
int counterc1=0;

string interaction;

int turn=999;
int* turnptr=&turn;

int rng(){
    return rand();
}
class Player{
public:
    string ascii;
    string name;
    string owned;
    int position;
    int dice;
    int score;
    int ass_mark;
    string power;
    int power_countdown;
    int MM;
    Player() : ascii(""),name(""),owned(""),position(0){}
    Player(string ascii,string name,string owned,int position)
    {
        this->ascii = ascii;
        this->name = name;
        this->owned = owned;
        this->position = position;

    }
    void rolldice()
    {
        dice=rng()%6+1;
    }
    void display(){cout<<ascii<<name<<owned<<position;}
    void getpower(){
        do
        {
            cout<<"***Choose an ability***\n";
            cout<<name<<"'s ability :";
            getline(cin,power);
            if(power!="I" && power!="M" && power != "F")
            {
            cout<<endl<<"Wrong input";
            }
        }while(power!="I" && power!="M" && power != "F");

    }
};
Player player[] = { Player("A","player 1","X",56), Player("B","player 2","O",7)};

int Max=64;
int m=8;
string board[64];
int storage[64];
int miniCount=0;

void prepareBoard()
{
    for(int i=0;i<Max;i++)
    {
        board[i]=" ";
        storage[i]=99;
    }
    board[56]="A";
    board[7]="B";
}

void initilizeturn()
{
    string temp_n1,temp_n2;
    int s_value=50;

    cout<<setw(s_value+s_value/2)<<"Enter The Names Of The Players"<<endl<<endl;
    cout<<setw(s_value)<<"Enter the name of Player: ";
    getline(cin,temp_n1);

    do{
        cout<<setw(s_value)<<"Enter the name of another Player:";
        getline(cin,temp_n2);
        cout<<endl;
        if(temp_n1==temp_n2){
            cout<<setw(s_value)<<"The name is already Taken"<<endl<<endl<<setw(50)<<"Please Try again!"<<endl<<endl;
        }
    }while(temp_n1==temp_n2);
    cout<<setw(s_value+s_value)<<"***Type Anything To Shaffle to see Who go First***";
    getline(cin,interaction);

    if(rng()>rng())
    {
        cout<<endl<<endl<<setw(s_value+s_value/2)<<"Go first"<<endl<<endl<<setw(s_value+s_value/2)<<"Player "<<temp_n1<<" = A "<<endl<<endl<<setw(s_value+s_value/2)<<"Go second"<<endl<<endl<<setw(s_value+s_value/2)<<"Player "<<temp_n2<<" = B "<<endl<<endl;
        player[0].name=temp_n1;player[1].name=temp_n2;
    }
    else
    {
        cout<<endl<<endl<<setw(s_value+s_value/2)<<"Go first"<<endl<<endl<<setw(s_value+s_value/2)<<"Player "<<temp_n2<<" = A "<<endl<<endl<<setw(s_value+s_value/2)<<"Go second"<<endl<<endl<<setw(s_value+s_value/2)<<"Player "<<temp_n1<<" = B "<<endl<<endl;
        player[1].name=temp_n2;player[0].name=temp_n1;
    }


    player[0].getpower();
    player[1].getpower();
    player[0].rolldice();
    player[1].rolldice();
    cout<<player[0].dice<<player[1].dice;
    cout<<"Type Enter to continue to the game";
    getline(cin,interaction);

}

bool hide;
draw(Player currentplayer,Player nextplayer)
{
    int blocktype=0;
    int row=-8;//column
    int col=0;//board count
    int sp=30;//space

    //system("cls");
    cout<<"Hide:"<<hide;
    cout<<endl<<endl;
    cout<<setw(sp-2)<<""<<"    +0   +1    +2    +3    +4    +5    +6    +7\n";
    cout<<setw(sp-2)<<"+"<<"---------------------------------------------------+";

    for(int r=0;r<24;r++)
    {
        //
        if(blocktype==0)
        {
        SetConsoleTextAttribute(h,bc);
        cout<<endl<<setw(sp)<<"| +"<<"\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe+ |";
        row+=8;
        }
        //
        if(blocktype!=1)
        {

            cout<<endl<<setw(sp)<<"| |";
            for(int col=0;col<8;col++)
            {   //
                if(board[col+row]=="X" )
                {
                SetConsoleTextAttribute(h,p1c);
                cout<<"\xfe \xfe \xfe";
                }
                else if(board[col+row]=="O")
                {
                SetConsoleTextAttribute(h,p2c);
                cout<<"\xfe \xfe \xfe";
                }
                else if(board[col+row]==" ")
                {
                SetConsoleTextAttribute(h,0);
                cout<<"\xfe \xfe \xfe";
                }
                else if(board[col+row]=="M" || board[col+row]=="T" || board[col+row]=="P" )
                {
                SetConsoleTextAttribute(h,bpc);
                cout<<"  \xfe  ";
                }
                else if(board[col+row]=="B" )
                {
                SetConsoleTextAttribute(h,p2mc);
                cout<<"  \xfe  ";
                }
                else if(board[col+row]=="A" )
                {
                SetConsoleTextAttribute(h,p1mc);
                cout<<"  \xfe  ";
                }
                else if(board[col+row]=="C")
                {
                SetConsoleTextAttribute(h,pc);
                cout<<"\xfe \xfe \xfe";
                }
                //
                SetConsoleTextAttribute(h,bc);
                cout<<"|";
            }
            cout<<" |";
        }
        else//middle == 0;
        {
            cout<<endl<<setw(sp-3)<<row<<"| |";
            for(int col=0;col<8;col++)
            {
                if(board[col+row]=="X")
                {
                    SetConsoleTextAttribute(h,p1c);
                    cout<<"\xfe \xfe \xfe";
                }
                else if(board[col+row]=="O")
                {
                    SetConsoleTextAttribute(h,p2c);
                    cout<<"\xfe \xfe \xfe";
                }
                else if(board[col+row]=="A")
                {
                    SetConsoleTextAttribute(h,p1mc);
                    cout<<"\xfe A \xfe";

                }
                else if(board[col+row]=="B")
                {
                    SetConsoleTextAttribute(h,p2mc);
                    cout<<"\xfe B \xfe";
                }
                else if(board[col+row]==" ")
                {
                    SetConsoleTextAttribute(h,0);
                    cout<<"\xfe \xfe \xfe";
                }
                else if(board[col+row]=="M" || board[col+row]=="T" || board[col+row]=="P")
                {
                    SetConsoleTextAttribute(h,bpc);
                    cout<<"\xfe "<<board[col+row]<<" \xfe";
                }
                else if(board[col+row]=="C")
                {
                    SetConsoleTextAttribute(h,pc);
                    cout<<"\xfe "<<board[col+row]<<" \xfe";
                }
                //
                SetConsoleTextAttribute(h,bc);
                cout<<"|";
            }
            cout<<" |";
        }
        //Beside bar text..........

        if(hide==false)
        {
            if(r==5)
            {

                cout<<setw(50)<<"Remained turn = "<<counterc1;
            }
            else if(r==8)
            {
                cout<<setw(30)<<"Names :"<<setw(10)<<player[0].name<<setw(10)<<" | "<<setw(10)<<player[1].name;
            }
            else if(r==11)
            {
                cout<<setw(30)<<"Character:"<<setw(10)<<"A(blue)"<<setw(10)<<" | "<<setw(10)<<"B(red)";
            }
            else if(r==14)
            {
                cout<<setw(30)<<"Ability:"<<setw(10)<<player[0].power<<setw(10)<<" | "<<setw(10)<<player[1].power;
            }
            else if(r==17)
            {
                if(counterc1==0)
                {

                    cout<<setw(30)<<"Dices"<<setw(10)<<currentplayer.dice<<setw(10)<<" | "<<setw(10)<<"*******Turn End*******";
                }
                else
                {
                    if(currentplayer.ascii=="A")
                    {
                        cout<<setw(30)<<"Dices"<<setw(10)<<"--> "<<player[0].dice<<" <--"<<setw(6)<<" | "<<setw(10)<<player[1].dice;
                    }
                    else
                    {
                         cout<<setw(30)<<"Dices"<<setw(10)<<player[0].dice<<setw(10)<<" | "<<setw(10)<<"--> "<<player[1].dice<<" <--";
                    }

                }
            }
            else if(r==20)
            {
                cout<<setw(40)<<"Start "<<currentplayer.name;
            }
            else if(r==23)
            {
                cout<<setw(30)<<"Ability info : ";
                if(player[0].power_countdown==0 && player[0].power=="M" && player[0].MM==1){
                        cout<<setw(3)<<" "<<"You marked at "<<player[0].ass_mark<<setw(17)<<" | ";
                }
                else if(player[0].power_countdown==0){
                    cout<<setw(5)<<" "<<"!Ready!"<<setw(15)<<" | ";
                }
                else
                {
                    cout<<setw(2)<<" "<<player[0].power_countdown<<setw(18)<<" | ";
                }


                if(player[1].power_countdown==0 && player[1].power=="M" && player[1].MM==1){
                        cout<<setw(3)<<" "<<"You marked at "<<player[0].ass_mark;
                }
                else if(player[1].power_countdown==0){
                    cout<<setw(5)<<" "<<"!Ready!";
                }
                else
                {
                    cout<<setw(2)<<" "<<player[1].power_countdown;
                }



            }
        }


        //end of text info of game...
        blocktype++;
        if(blocktype==3)
            blocktype=0;

    }

    cout<<endl<<setw(sp)<<"| +"<<"\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe+ |\n";
    cout<<setw(sp-2)<<"+"<<"---------------------------------------------------+\n";
    cout<<endl;
    hide=false;


}


/*******Changes*********/
    //function for controlling errors that trigger when we insert nor-integer data type to int variable
    int checkInt(string inputer) {

    string greeting = inputer;
  int len = greeting.length();
  int n=len-1;
  for(int i=0;i<(len/2);i++){
    //Using the swap method to switch values at each index
    swap(greeting[i],greeting[n]);
    n = n-1;

  }
    int integer = 0;
    long power = 1;
    //cout<<str.size();

    for(int i = 0; i <greeting.length(); i++) {
        for(int j = 0; j < i; j++)
          power*= 10;

        switch(greeting[i]) {
        case '1':
            integer += 1 * power;
            break;
        case '2':
            integer += 2 * power;
            break;
        case '3':
            integer += 3 * power;
            break;
        case '4':
            integer += 4 * power;
            break;
        case '5':
            integer += 5 * power;
            break;
        case '6':
            integer += 6 * power;
            break;
        case '7':
            integer += 7 * power;
            break;
        case '8':
            integer += 8 * power;
            break;
        case '9':
            integer += 9 * power;
            break;

        }
        power = 1;
    }
        return integer;

}
/*******Changes*********/

bool truer ;

void MargeProtectapp(string P)
{
    int temppos;
    do
    {
       temppos= rng()%64+1;
    }while( board[temppos] != "O" && board[temppos]!="X" && board[temppos]!=" ");
    board[temppos]=P;
}
//IN board power functions

int telecount=0;
int margecount=0;
int ppcount=0;

struct teleport{
    int en;//enter;
    int ex;//exit;
};
teleport tele;
void teleport_app()
{
    int loop=1;
    while(loop==1){
        int tel_no=rng()%3;
        if(tel_no==0 && (board[27]==" " || board[27]=="X" || board[27]=="O") && (board[6]==" " || board[6]=="X" || board[6]=="O")){
             tele.en=27;tele.ex=6;
            board[ tele.en]="T";board[tele.ex]="T";
            loop--;
        }
        else if(tel_no==1 && (board[45]==" " || board[45]=="X" || board[45]=="O") && (board[50]==" " || board[50]=="X" || board[50]=="O")){
           tele.en=45;tele.ex=50;
            board[ tele.en]="T";board[tele.ex]="T";
            loop--;
        }
        else if(tel_no==2 && (board[8]==" " || board[8]=="X" || board[8]=="O") && (board[44]==" " || board[44]=="X" || board[44]=="O")){
            tele.en=8;tele.ex=44;
            board[tele.en]="T";board[tele.ex]="T";
            loop--;
        }
    }
}

void spwanpower()
{
    int temp=rng()%3;
    if(temp==0 && telecount==0)
    {
        teleport_app();
        telecount++;
    }
    else if(temp==1 && margecount==0)
    {
        MargeProtectapp("M");
        margecount++;
    }
    else if(temp==2 && ppcount==0)
    {
        MargeProtectapp("P");
        ppcount++;
    }
}


  int movee(string& dir,Player currentplayer) {

        if(dir == "d")
            {
            if(currentplayer.position != 7 && currentplayer.position != 15 && currentplayer.position != 23 && currentplayer.position != 31 && currentplayer.position != 39 && currentplayer.position != 47 && currentplayer.position != 55 && currentplayer.position != 63)
                    {


                            if(board[currentplayer.position+1] != "A" && board[currentplayer.position+1] != "B")/////"A" "B" ko opponent ascii;
                            {
                                return currentplayer.position + 1;

                            }
                    }
                   else{
                    dir="a";
                    if(board[currentplayer.position-1] != "A" && board[currentplayer.position-1] != "B")/////"A" "B" ko opponent ascii;
                            {
                        return  currentplayer.position-1;
                            }

               }
                return currentplayer.position;
            }
        else if(dir == "s")
            {


            if(!(currentplayer.position>55 && currentplayer.position<64))
                    {
                        if(board[currentplayer.position + 8] != "A" && board[currentplayer.position + 8] != "B")
                        {
                            return currentplayer.position+8;
                        }
                    }
                    else
                    {
                        dir="w";
                        if(board[currentplayer.position - 8] != "A" && board[currentplayer.position - 8] != "B")
                        {
                        return currentplayer.position-8;
                        }
                    }

                return currentplayer.position;
            }
        else if(dir == "w")
            {

            if(currentplayer.position>7)
                    {

                        if(board[currentplayer.position - 8] != "A" && board[currentplayer.position - 8] != "B")
                        {
                            return currentplayer.position - 8;
                        }
                    }
                    else
                    {
                        dir="s";
                        if(board[currentplayer.position + 8] != "A" && board[currentplayer.position + 8] != "B")
                        {
                        return currentplayer.position + 8;
                        }
                    }
                return currentplayer.position;

            }
        else if(dir == "a")
            {

            if(currentplayer.position != 7*m && currentplayer.position != 6*m && currentplayer.position != 5*m && currentplayer.position != 4*m && currentplayer.position != 3*m && currentplayer.position != 2*m && currentplayer.position != m && currentplayer.position != 0)
                    {

                        if(board[currentplayer.position - 1] != "A" && board[currentplayer.position - 1] != "B" )
                        {
                            return currentplayer.position - 1;
                        }
                    }
                    else
                    {
                        dir="d";
                         if(board[currentplayer.position + 1] != "A" && board[currentplayer.position + 1] != "B" )
                        {
                        return  currentplayer.position+1;
                        }
                    }
                     return currentplayer.position;
            }
    }


int increase_move(int original_move,string& dir){
    int add_move;
    string getmover;
    bool truee ;
    cout<<"\n!!Your Increase Movement Power activited!!\n";
    do
    {
        cout<<"Power Phrase"<<endl;
        do{
            truee = true;
            cout<<"Enter the number of move you want to extent:(ranging : 1 to 3 )";
            getline(cin,getmover);
            for(char i : getmover)
            {
               if(isdigit(i) == 0)
               {
                    truee = false;
                    break;
                }
            }
            if(truee)
            {
                add_move = checkInt(getmover);
            }
        //cout<<isdigit(i)<<endl;
        } while(add_move > 0 && !truee);
        cout<<"You entered:"<<add_move<<endl;

    }while(add_move<1 || add_move>3);
    cout<<"Your dice count become "<< original_move+add_move<<endl;
    cin.ignore();
    return original_move+add_move;

}
void Ass(Player& p1){//MM is 1 mark  and 2 move
    if(p1.MM==1){

        board[p1.position]=="L";
        p1.ass_mark=p1.position;
    }
    else if(p1.MM==2){
        board[p1.position]=p1.owned;
        p1.position=p1.ass_mark;
    }

}
int teleport(Player p,int trace,int en,int ex){//en-entrance ex exit;
           ///potal is a term for teleport.

    board[en]=p.owned;
    board[ex]=p.owned;


    if(trace==en)
    {
        return ex;
    }
    else
    {
       return en;

    }
}

void marge(Player p1,Player p2,int center){

        if(center>7){
                if(center-m != p2.position && board[center-m] != "T" && board[center-m]!= "P" && board[center-m] !="C"){
                     board[center-m]=p1.owned;
                }

            if(center!=8 && center!=16 && center != 24 && center != 32 &&center != 40 && center != 48 && center != 56 && center-m-1!=p2.position && board[center-m-1]!="T" && board[center-m-1]!="P" && board[center-m-1]!="C"){
                board[center-m-1]=p1.owned;
            }
            if(center != 15 && center!=23 && center != 31 && center != 39 && center != 47 && center != 55 && center != 63 && center-m+1 != p2.position && board[center-m+1] != "T" && board[center-m+1] !="P" && board[center-m+1] != "C"){
                board[center-m+1]=p1.owned;
            }
        }
        if(center<56){
                if(center+m!=p2.position && board[center+m]!="T" && board[center+m]!="P" && board[center+m]!="C" ){
                     board[center+m]=p1.owned;
                }

            if(center!=8 && center!=16 && center != 24 && center != 32 &&center != 40 && center != 48 && center+m-1!=p2.position && board[center+m-1] !="T" && board[center+m-1] !="P" && board[center+m-1] !="C"){
                board[center+m-1]=p1.owned;
            }
            if(center!= 7 && center != 15 && center!=23 && center != 31 && center != 39 && center != 47 && center != 55 && center+m+1 != p2.position && board[center+m+1] != "T" && board[center+m+1] !="P"  && board[center+m+1] !="C" ){
                board[center+m+1]=p1.owned;
            }
        }
        if(center-1!=p2.position && center!=8 && center!=16 && center != 24 && center != 32 &&center != 40 && center != 48 &&center != 56 && board[center-1]!="T" && board[center-1]!="P" && board[center-1]!="C"){
            board[center-1]=p1.owned;
        }
        if(center+1 != p2.position && center!=7 && center != 15 && center!=23 && center != 31 && center != 39 && center != 47 && center != 55 && center != 63 && board[center+1] != "P" && board[center+1] != "T" && board[center+1] != "C"){
            board[center+1]=p1.owned;
        }
}




int main(void){
    srand(time(NULL));

   SetConsoleTextAttribute(h,bc);

   prepareBoard();


   initilizeturn();
    hide=true;
    draw(player[0],player[1]);
                                                    string turner;
                                                        do//turn5and 10 loop
                                                        {
                                                            truer = true;

                                                            //cout<<"Better to test about not int"<<endl;

                                                            cout<<setw(50)<<" "<<"How many turns do you wanna play: (suggesst : 5 - 15 ): ";
                                                            getline(cin,turner);
                                                        for(char i : turner) {
                                                            if(isdigit(i) == 0) {

                                                                truer = false;
                                                                break;
                                                            }
                                                        }
                                                        if(truer) {
                                                           *turnptr = checkInt(turner);
                                                        } else {
                                                            cout<<truer<<endl;
                                                        }

                                                        }while(turn > 0 && !truer);

    int counterc=0;
    counterc1=turn;

    Player currentplayer;
    Player nextplayer;
    int freeze=0;
    bool signal=false;
    bool valid=false;
    int timing;
    while(counterc<turn*2)
    {

        if(counterc%2==0)
        {
           currentplayer= player[0];
           nextplayer = player[1];
           counterc1--;
        }
        else
        {
             currentplayer=player[1];
             nextplayer=player[0];
        }

        spwanpower();
        if(freeze==0)
        {
        draw(currentplayer,nextplayer);




        int pna=0;
        string in;


        do{
//for markpower...............skip if the first time seeing it work after active ability;




            cout<<"YOUr current position is "<<currentplayer.position;
            cout<<endl<<board[1];
            cout<<endl<<"Conquer(by using aswd and x to active ability) :";
            getline(cin,in);

            if (in != "a" && in != "s" && in != "w" && in != "d" && in != "x")
            {
               cout << "\nInput wrong!!"<<endl;
            }


        if(in=="x")
        {

            if(pna==0)
            {
                pna=1;           //power not avialable
                if(currentplayer.power_countdown>0){
                    cout<<endl<<"Your power in cooldown";
                }
                else
                {
                    if(currentplayer.power=="I"){
                        currentplayer.power_countdown=6;
                        currentplayer.dice=increase_move(currentplayer.dice,in);

                    }
                    else if(currentplayer.power=="M"){

                        currentplayer.MM++;
                        Ass(currentplayer);
                        if(currentplayer.MM==2){
                            currentplayer.power_countdown=4;
                            currentplayer.MM==0;
                        }
                    }
                    else if(currentplayer.power=="F"){
                        freeze=1;
                        currentplayer.power_countdown=10;
                        cout<<endl<<endl<<"Player "<<nextplayer.name<<" turn will be skip";
                    }
                }
            }
            else if(pna==1){
                cout<<endl<<endl<<"You already active power"<<endl<<endl;
            }

        }

        }while(in != "a" && in != "s" && in != "w" && in != "d");

        int j=0;

            while(j < currentplayer.dice)

            {

                        int next_move = movee(in,currentplayer);

                        if(board[next_move] == "T")
                                {
                                    //make the initialpos  a little early for teleport function..]
                                    next_move=teleport(currentplayer,next_move,tele.en,tele.ex);
                                    telecount--;

                                } else if(board[next_move]=="M")
                                {
                                        marge(currentplayer,nextplayer,next_move);
                                        margecount--;
                                }
                                else if(board[next_move] == "P")
                                {
                                       //send signal to activate protection
                                       signal = 1;
                                       ppcount--;
                                }


                        //cout<<endl<<"My position is now:"<<currentplayer.position;
                        board[currentplayer.position] = currentplayer.owned;
                        board[next_move] = currentplayer.ascii;
                        currentplayer.position=next_move;
                          j++;
                          draw(currentplayer,nextplayer);

                }
                }
                if(freeze>0){
                    freeze++;
                    if(freeze==3){
                        freeze=0;
                    }
                }
                currentplayer.rolldice();




/////////////////////////////////////
if(signal) {
                timing = counterc;
                for(int i = 0; i < Max; i++) {
                        if(board[i] == currentplayer.owned){
                            board[i]="C";
                            storage[miniCount] = i;
                            miniCount++;
                  }

            }
        }


 ///return protected squares in every turn until they are deactivated
            if(!valid) {
                    for(int i = 0; i < Max; i++) {
                     {
                        if(storage[i] != 99 && board[storage[i]] != "A" && board[storage[i]] != "B")
                         board[storage[i]] = "C";
                     }
                }
            }
            signal = 0;

///determine for stopping protection function
           if(timing + 2 == counterc) {
               for(int i = 0; i < Max; i++) {
                    if(board[i]=="C")
                    {
                        board[i]=currentplayer.owned;
                    }
            }
            valid = true;
            //board[player[0].position] = "A";
            //board[player[1].position] = "B";
            }
            if(currentplayer.power_countdown>0){
                currentplayer.power_countdown--;
            }

        if(counterc%2==0)
        {
            player[0]=currentplayer;
            player[1]=nextplayer;
        }
        else
        {
            player[1]=currentplayer;
            player[0]=nextplayer;
        }
        counterc++;

    }



        for(int i = 0; i < Max; i++) {
            if (board[i]=="X" || board[i]=="A"){
                player[0].score++;
            }
            else if(board[i]=="B" || board [i]== "O"){
                player[1].score++;
            }else if(board[i] == "C"){
                if( currentplayer.ascii == player[0].ascii ){
                    player[0].score++;
                }
                else
                {
                    player[1].score++;
                }
            }
        }
 int o = player[1].score,x = player[0].score;
    cout<<endl<<endl;
    cout<<"Player "<<player[0].name<<" =  "<<x<<endl;
    cout<<"Player "<<player[1].name<<" = "<< o<<endl;



    if(o > x)
    {//condition for winner sentence
        cout<<"player "<<player[1].name<<"= winner"<<endl;
    }
    else if(o == x)
    {
        cout<<"a tie"<<endl;
    }
    else
    {
        cout<<"player  "<<player[0].name<<"= winner"<<endl;

    }
    system("pause");
    return 0;
}





