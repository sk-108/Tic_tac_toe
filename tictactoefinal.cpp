
#include<iostream>
using namespace std;

char board[3][3]={{'.','.','.'},{'.','.','.'},{'.','.','.'}};
char current_maker; int currentplayer;
void drawboard()
{
    cout<<'\t'<<" "<<board[0][0]<<" "<<board[0][1]<<" "<<board[0][2]<<endl;
    cout<<'\t'<<"\n";
    cout<<'\t'<<" "<<board[1][0]<<" "<<board[1][1]<<" "<<board[1][2]<<endl;
    cout<<'\t'<<"\n";
    cout<<'\t'<<" "<<board[2][0]<<" "<<board[2][1]<<" "<<board[2][2]<<endl;

}

bool placemaker(int row,int col)
{

    if(board[row][col]!='X'&&board[row][col]!='O'){

        board[row][col]=current_maker;
        return true;
    }
    else
        return false;

}

int winner()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]  && board[i][2]!='.')
            return currentplayer;
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i] && board[2][i]!='.')
            return currentplayer;
    }
        if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&& board[2][2]!='.')
            return currentplayer;
        if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&& board[1][1]!='.')
            return currentplayer;

    }

    void swap_player()
    {
        if (current_maker=='X')
            current_maker='O';
        else current_maker='X';
        if(currentplayer==1) currentplayer=2;
        else currentplayer=1;
    }






    void game()
    {
        char markerp1;
        int row,col,flag=0;



        string player1,player2,marker;
        cout<< "enter name for player X\n";
        cin>>player1;
        cout<< "enter name for player O\n";
        cin>>player2;

        do{
             cout<< "who will play first,"<<player1<<" or "<<player2<< "?\n";
            cin>>marker;
            if(marker==player1){
                current_maker='X';
                currentplayer=1;
                break;
            }
            else if (marker==player2)
            {
                current_maker='Y';
                currentplayer=2;
                break;
            }
            else
           {
               cout<<marker<< "is not a registered player \n";
            }

        }while(1);



        int playerwon;

        drawboard();

        for(int i=0;i<9;i++)
        {
            cout<<"player of current turn: ";
            if(currentplayer==1)
            {
                cout<<player1<<endl;
            }
            else
            {
                cout<<player2<<endl;
            }

            while(1){

         cout<< "choose a row number (0 to 2)\n";
         cin>>row;
         if(row>2|| row <0){
             cout<<row<< " is not a valid row.\n";
             }
            else { break;}
            }

             while(1){

         cout<< "choose a col number (0 to 2)\n";
         cin>>col;
         if(col>2 || col<0){
              cout<<col<< " is not a valid col.\n";
         }
         else { break;}
            }

            if(!placemaker(row,col)){
                cout<<"the slot is ocupied try again";
            i--;
            continue;
               }

            playerwon=winner();
            if(playerwon==1)
            {
                cout<<"game is over : \n";
                cout<<player1<< " wins !\n";
                flag=1;
                break;
            }
             if(playerwon==2)
            {
                cout<<"game is over : \n";
                cout<<player2<< " wins !\n";
                flag=1;
                break;
            }
           swap_player();
        drawboard();
        }

        if(flag==0){

            cout<<"it is a tie\n";
        }

    }

void newboard()
{

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        board[i][j]='.';

    }
  }
}




int main(){
    char ch;
  do{
     game();
     newboard();
     cout<< "would you like to play again ? (Y/N) \n";
     cin>>ch;
     if(ch!='Y'&& ch!='N')
     {
         cout<< ch << " is not a valid answer.\n";
     }
     if(ch=='N'){
        cout<< " Bye !\n";
        break;
     }
  }while(ch=='Y');

return 0;
}
