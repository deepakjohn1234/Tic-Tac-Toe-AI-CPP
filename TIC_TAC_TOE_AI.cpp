#include <iostream>
#include <iomanip>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void show(){
    cout << "\n╔═══╦═══╦═══╗\n║ " << board[0][0] << " ║ " << board[0][1] 
         << " ║ " << board[0][2] << " ║\n╠═══╬═══╬═══╣\n║ " 
         << board[1][0] << " ║ " << board[1][1] << " ║ " << board[1][2] 
         << " ║\n╠═══╬═══╬═══╣\n║ " << board[2][0] << " ║ " << board[2][1] 
         << " ║ " << board[2][2] << " ║\n╚═══╩═══╩═══╝\n";
}

int win(char p){
    for(int i=0;i<3;i++)if(board[i][0]==p&&board[i][1]==p&&board[i][2]==p)return 1;
    for(int i=0;i<3;i++)if(board[0][i]==p&&board[1][i]==p&&board[2][i]==p)return 1;
    if(board[0][0]==p&&board[1][1]==p&&board[2][2]==p)return 1;
    if(board[0][2]==p&&board[1][1]==p&&board[2][0]==p)return 1;return 0;
}

int full(){for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(board[i][j]>='1'&&board[i][j]<='9')return 0;return 1;}

void aiMove(){
    // 1. WIN check
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(board[i][j]>='1'&&board[i][j]<='9'){
        char save=board[i][j];board[i][j]='O';if(win('O')){board[i][j]='O';return;}
        board[i][j]=save;}
    
    // 2. BLOCK check  
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(board[i][j]>='1'&&board[i][j]<='9'){
        char save=board[i][j];board[i][j]='X';if(win('X')){board[i][j]='O';return;}
        board[i][j]=save;}
    
    // 3. STRATEGY - ALWAYS picks something
    if(board[1][1]>='1'&&board[1][1]<='9')board[1][1]='O';
    else if(board[0][0]>='1'&&board[0][0]<='9')board[0][0]='O';
    else if(board[0][2]>='1'&&board[0][2]<='9')board[0][2]='O';
    else if(board[2][0]>='1'&&board[2][0]<='9')board[2][0]='O';
    else if(board[2][2]>='1'&&board[2][2]<='9')board[2][2]='O';
    else if(board[0][1]>='1'&&board[0][1]<='9')board[0][1]='O';
    else if(board[1][0]>='1'&&board[1][0]<='9')board[1][0]='O';
    else if(board[1][2]>='1'&&board[1][2]<='9')board[1][2]='O';
    else if(board[2][1]>='1'&&board[2][1]<='9')board[2][1]='O';
}

int main(){
    cout<<"Tic-Tac-Toe AI - Never Skips!\n\n";show();
    int pos;while(1){
        cout<<"Move (1-9): ";cin>>pos;board[(pos-1)/3][(pos-1)%3]='X';
        show();if(win('X')){cout<<"🎉 YOU WIN!\n";break;}
        aiMove();show();if(win('O')){cout<<"🤖 AI WINS!\n";break;}
        if(full()){cout<<"🤝 DRAW!\n";break;}
    }
    return 0;
}
