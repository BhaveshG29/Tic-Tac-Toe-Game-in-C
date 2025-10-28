#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char Board[3][3]; //Board
static bool GameOn = true; //Equals True if the game is On. False if game is Off.

int x, y; //Player Input Variables
static int CurrentPlayer = 1; //Helps us Choose which player is Playing Currently

//Displays the Board
void DisplayBoard(){
for(int i=0;i<3;i++){
for(int j=0; j<3; j++){
	printf("%c\t", Board[i][j]);
}
printf("\n");
}
}

//Initial Condition of the Board
void initialBoard(){
for(int i=0;i<3;i++){
for(int j=0; j<3; j++){
	Board[i][j] = '_';
}
}
DisplayBoard();
}


//Checking if Any Player Wins
bool checkWin(){
if((Board[0][0] == Board[1][0] && Board[1][0]==Board[2][0] && Board[0][0]!='_') || (Board[0][1] == Board[1][1] && Board[1][1]==Board[2][1] && Board[0][1]!='_') || (Board[0][2] == Board[1][2] && Board[1][2]==Board[2][2] && Board[0][2]!='_') || (Board[0][0] == Board[0][1] && Board[0][1]==Board[0][2] && Board[0][1] !='_') || (Board[1][0] == Board[1][1] && Board[1][1]==Board[1][2] && Board[1][0] !='_') || (Board[2][0] == Board[2][1] && Board[2][1]==Board[2][2] && Board[2][0]!='_') || (Board[0][0] == Board[1][1] && Board[1][1]==Board[2][2] && Board[2][2] !='_') || (Board[0][2] == Board[1][1] && Board[1][1]==Board[2][0] && Board[1][1] !='_')){

if((Board[0][0] == Board[1][0] && Board[1][0]==Board[2][0] && Board[0][0]=='X') || (Board[0][1] == Board[1][1] && Board[1][1]==Board[2][1] && Board[0][1]=='X') || (Board[0][2] == Board[1][2] && Board[1][2]==Board[2][2] && Board[0][2]=='X') || (Board[0][0] == Board[0][1] && Board[0][1]==Board[0][2] && Board[0][1]=='X') || (Board[1][0] == Board[1][1] && Board[1][1]==Board[1][2] && Board[1][0]=='X') || (Board[2][0] == Board[2][1] && Board[2][1]==Board[2][2] && Board[2][0]=='X') || (Board[0][0] == Board[1][1] && Board[1][1]==Board[2][2] && Board[2][2]=='X') || (Board[0][2] == Board[1][1] && Board[1][1]==Board[2][0] && Board[1][1]=='X')){

	printf("Player-1 Wins the Game.\n");

}

else{
	printf("Player-2 Wins the Game.\n");
}

GameOn = false;
return true;
}

else return false;
}

//Checking if the Board is completly Filled
bool FullBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board[i][j] == '_'){
		    return false;
	    }
        }
    }
    GameOn = false;
    return true;
}


//Checking if the Game ends in Draw.
bool checkDraw(){
if(!checkWin() && FullBoard()){
printf("\nIts a Draw.");
return true;
}

else return false;
}


//Checks if the Move is Valid or not
bool Valid(int r, int c){
if(Board[r][c] == '_' && ( r>= 0 && r<3) && (c>=0 && c<3) && GameOn){
return true;
}

else return false;
}

void PlayerOutput(int r, int c);

//Takes User Input
void PlayerInput(){
	printf("\nPlay Your Move Player-%d:", CurrentPlayer);
scanf(" %d %d", &x, &y);
x = x - 1;
y = y - 1;
PlayerOutput(x,y);
}

//Changes the Board if the move is valid
void PlayerOutput(int r, int c){
	if(Valid(r,c) && CurrentPlayer == 1){
Board[r][c] = 'X';
DisplayBoard();
CurrentPlayer = 2;
	}
	else if(Valid(r,c) && CurrentPlayer == 2){
Board[r][c] = 'O';
DisplayBoard();
CurrentPlayer = 1;
	}

	else if(!Valid(r,c) && GameOn){
for(int i=0; i<20; i++){
printf("*");
}

printf("\nEnter a Valid Move\n");

for(int i=0; i<20; i++){
printf("*");
}

printf("\n");
DisplayBoard();
PlayerInput();
	}
}

//If the players want to replay the Game.
void replay(){
	char play;
	printf("Enter Y to play again:");
	scanf(" %c", &play);
	if(play=='Y' || play=='y'){
int cmmd1 = system("clear");
	GameOn = true;
	int cmmd2 = system("./main");
	}

	else{
printf("\nThank You for Playing.\n");
	}
}

//Main Function
int main(){

initialBoard();

while(GameOn){
PlayerInput();
if(checkWin()){
break;
}

else if(checkDraw()){
break;
}

else continue;
}

if(!GameOn){
printf("\nThank You for Playing this game.\n");
replay();
}

return 0;
}

