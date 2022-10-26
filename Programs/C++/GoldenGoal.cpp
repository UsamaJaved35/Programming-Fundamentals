#include<iostream>
#include <cstdlib>
#include<string>
using namespace std;

/************* SOME INSTRUCTION****************/
// O DENOTES PLAYER O
// X DENOTES PLAYER X
// O(B) DENOTES PLAYER O IS IN POSESSION OF BALL
// X(B) DENOTES PLAYER X IS IN POSESSION OF BALL

/**********************************************/

/****************** GLOBAL VARIABLES *********************/
string Field[3][5];//FIELD STATIC ARRAY TO STORE TE STATE OF GAME
int col_Location, row_Location;//GLOBAL VARIABLES FOR STORING RANDOM NUMBERS GENERATED
int playerXrow=1, playerXcol=0;//PLAYER X INITIAL POSITIONS
int playerOrow=1, playerOcol=4;//PLAYER O INITIAL POSITIONS
int updated_Xrow=0, updated_Xcol=0;//UPDATED PLAYER X LOCATION VARIABLES
int updated_Orow = 0, updated_Ocol = 0;//UPDATED PLAYER O LOCATION VARIABLES
bool tackled = false, afterTackle=false;//VARIABLES FOR HANDELING TACKLING 
void move_playerO(bool);//FUNCTION PROTOTYPES
void move_playerX(bool);

/***************** FUCTIONS ***********************/
void printField() //FUNCTION FOR PRINITNG FIELD ON CONSOLE
{
	for (int i = 0;i < 3;i++)
	{
		cout << "=========================================================";
		cout << "\n";
		cout << "| ";
		for (int j = 0;j < 5;j++)
		{
			cout << Field[i][j] << "|";
		}
		cout << "\n";
	}
	cout << "=========================================================\n";
}
void setInitialField()//FUNCTION FOR STORING INITIAL POSITIONS IN FIELD ARRAY
{
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			Field[i][j] = "  (" + to_string(i) + ',' + to_string(j) + ")   ";
		}
	}
}
/****** FUNCTION FOR GENERATING RANDOM KICKS FOR BOTH PLAYERS*****/
void randomKick(int colNumber,string player) {
	srand(time(0));//SEEDING RAND FUNCTION FOR RANDOM GENERATION EVERY TIME
	if (player == "X")//IF PLAYER X KICKS
	{
		while (true)
		{
			if (col_Location != 0)
				col_Location = rand() % 4 + colNumber - 1;//STORING NEW COLUMN LOCATION FOR BALL
			else
				col_Location = 0;
			row_Location = rand() % 3;//STORING NEW ROW POSITION FOR BALL
			if (col_Location > colNumber && col_Location<5 ||(col_Location==4 &&row_Location!=playerXrow)) //IF BALL GOES  AWAY FROM PLAYER BREAK THE LOOP
				break;
		}
	}
	else if (player == "O")//IF PLAYER O KICKS
	{
		while (true)
		{
			if (colNumber != 0)
				col_Location = rand() % colNumber;//STORING NEW COLUMN LOCATION FOR BALL
			else
				col_Location = 0;
			row_Location = rand() % 3;//STORING NEW ROW POSITION FOR BALL
			if (col_Location <= colNumber)//IF BALL GOES  AWAY FROM PLAYER BREAK THE LOOP
				break;
		}
	}
}
/********* FUNCTION FOR CHECKING WINNER********/
void checkWinner(string winner)
{
	if (winner == "X")//IF PLAYER X GOALS
	{
		system("cls");
		cout << "********** CONGRATULATIONS!! ************\n";
		cout << "********* PLAYER X WON **********\n";
		return;//USED TO EXIT THE BLOCK CODE
	}
	else if (winner == "O")//IF PLAYER Y GOALS
	{
		system("cls");
		cout << "********** CONGRATULATIONS!! ************\n";
		cout << "********* PLAYER O WON **********\n";
		return;
	}

}
/********* FUNCTION FOR TACKLE HANDLING ********/
void tackle(string mov_Player,int row,int col)
{
	//GETTING ROW AND COLUMN POSITION OF MOVING PLAYER ALONG PLAYER NAME IN ARGUMENTS
	if (mov_Player == "X")//IF PLAYER X TACKLED
	{
		cout << "*********** PLAYER X TACKLED WITH PLAYER O *************\n";
		cout << "*********** PLAYER X & PLAYER O ARE ON SAME PLACE *************\n";
		Field[row][col] = "   X(B)   ";//SETTING X(B) THAT PLAYER X HOLDS THE BALL
		updated_Xrow = row;//UPDATING ROW AND COLUMNS
		updated_Xcol = col;
		tackled = true;//TACKLE HAPPENED SO TRUE
		move_playerX(false);//GIVE PLAYER X ONE BONUS CHANCE 
	}
	else // IF PLAYER O TACKLED
	{
		cout << "*********** PLAYER O TACKLED WITH PLAYER X *************\n";
		cout << "*********** PLAYER O & PLAYER X ARE ON SAME PLACE *************\n";
		Field[row][col] = "   O(B)   ";//SETTING O(B) THAT PLAYER X HOLDS THE BALL
		updated_Orow = row;//UPDATING ROW AND COLUMNS
		updated_Ocol = col;
		tackled = true;//TACKLE HAPPENED SO TRUE
		move_playerO(false);//GIVE PLAYER O ONE BONUS CHANCE 
	}
}
/******** FUNCTION FOR MOVING AND KICKING OF  PLAYER X*********/
void move_playerX(bool toss)
{
	string choice;//VARIABLE FOR STORING CHOICE
	int new_rowPosition, new_colPosition;//VARIABLES FOR STORING NEW ROW AND COLUMN POSITIONS 
	if (toss) {//IF PLAYER X WINS THE TOSS THEN FIRST MOVE
		playerXcol = 2;
		playerXrow = 1;//SETTING PLAYER X POSITION TO CENTER
		Field[1][2] = "   X(B)   ";
		Field[playerOrow][playerOcol] = "    O     ";//PLAYER O ON GOAL POSITION
		printField();
	}
	cout << "\n=========> PLAYER X TURN <==========\n";
	//IF MOVING PLAYER HAS BALL OR DID TACKLE
	if (toss || Field[playerXrow][playerXcol] == "   X(B)   "||tackled) {
		cout << "Enter K if you want to kick the ball :\n";
		cout << "Enter M if you want to Move with the ball :";
		cin >> choice;
		while (!(choice == "K" || choice == "k" || choice == "M" || choice == "m"))
		{
			cout << "*********** INVALID CHOICE **********\n";
			cout << "Enter K if you want to kick the ball : \n";
			cout << "Enter M if you want to Move with the ball : ";
			cin >> choice;
		}//VALIDATION CHECKS
	}
	else //PLAYER WANTS TO MOVE
		choice = "m";
		if (choice == "K" || choice == "k") {//IF PLAYER WANTS TO KICK
			if(toss)
				randomKick(2, "X");//INITIAL RANDOM KICK STARTING FROM CENTER
			else
				randomKick(playerXcol, "X");//CALLING RANDOM KICK FUNCTION
			cout << "********* KICKED BY PLAYER X ********\n";
			
			if (Field[row_Location][col_Location] == "    O     ")//IF THERE WAS A KEEPER
				Field[row_Location][col_Location] = "   O(B)   ";//HE WILL GRAB THE BALL
			else
			Field[row_Location][col_Location] = "    B     ";//ELSE BALL GOES ON POSITION
			if (tackled)//IF TACKLE WAS HAPPENED
			{
				//HANDLE TACKLING POSITIONS
				Field[updated_Xrow][updated_Xcol] = "    X     ";
				Field[playerXrow][playerXcol] = "  (" + to_string(playerXrow) + "," + to_string(playerXcol) + ")   ";
				playerXrow = updated_Xrow;
				playerXcol = updated_Xcol;
				tackled = false;//TACKLE DONE SO FALSE
				afterTackle = true;//AFTER TACKLE WE WANT TO MOVE PLAYERS ACCURATELY
			}
			else //IF THERE WAS NO TACKLE
			Field[playerXrow][playerXcol] = "    X     ";
			printField();
			/*IF ROW IS 1 AND COLUMN IS 4 AND NO GOAL KEEPER THEN X WINS */
			if (row_Location == 1 && col_Location == 4 && (Field[row_Location][col_Location]) != "    O     "
				&& Field[row_Location][col_Location] != "   O(B)   ")
			{
				checkWinner("X");
				return;
			}
			else if(row_Location == 1 && col_Location == 4 && (Field[row_Location][col_Location] == "    O     "
				|| Field[row_Location][col_Location] == "   O(B)   ")){
				Field[row_Location][col_Location] = "   O(B)   ";
			}
			move_playerO(false);//MOVE PLAYER O FOR HIS/HER TURN
		}
		else if (choice == "M" || choice == "m")//IF PLAYER WANTS TO MOVE 
		{
			cout << "Enter Row Number you want to move :";
			cin >> new_rowPosition;
			cout << "Enter Column Number you want to move :";
			cin >> new_colPosition;//GETTING NEW POSITIONS
	/******* CHECKING THAT THE PLAYER ONLY TAKES ONE STEP PER TURN AND MOVE TO VALID POSITION******/
			while (!(new_rowPosition < 3 && (new_colPosition - playerXcol == 1
				|| new_colPosition - playerXcol == 0)
				&& (abs(new_rowPosition - playerXrow)==1|| abs(new_rowPosition - playerXrow) == 0) ||
				(new_rowPosition==playerXrow && new_colPosition==playerXcol)))
			{
				cout << "Enter Valid Row Number you want to move :";
				cin >> new_rowPosition;
				cout << "Enter Valid Column Number you want to move :";
				cin >> new_colPosition;
			}//VALIDATION CHECKS
			/******* CHECKS FOR THE CURRENT STATE OF GAME ********/
			//IF PLAYER HAS BALL AND MOVE TO GOAL WITH BALL
			if (new_rowPosition == 1 && new_colPosition == 4 &&
			Field[new_rowPosition][new_colPosition] != "    O     " && Field[new_rowPosition][new_colPosition] != "   O(B)   "
				&& Field[playerXrow][playerXcol]!="    X     ")
			{
				checkWinner("X");
				return;
			}
			if (Field[playerXrow][playerXcol] == "   X(B)   ")
			{
				//IF PLAYER CARRIES THE BALL
				Field[new_rowPosition][new_colPosition] = "   X(B)   ";
			}
			else if (Field[new_rowPosition][new_colPosition] == "    B     ")
			{
				//IF THERE IS A BALL ON NEW LOCATION
				//PLAYER X WILL GRAB IT
				Field[new_rowPosition][new_colPosition] = "   X(B)   ";
			}
			else if (Field[new_rowPosition][new_colPosition] == "   O(B)   ")
			{
				//IF PLAYER X TACKLES WITH O WITH BALL
				tackle("X",new_rowPosition,new_colPosition);
			}
			else
			{
				//PLAYER X MOVING TO NEW POSITION
				Field[new_rowPosition][new_colPosition] = "    X     ";
			}
			if(!afterTackle)//IF NO TACKLE PRINT THE REAL LOCATIONS
			Field[playerXrow][playerXcol] = "  (" + to_string(playerXrow) + "," + to_string(playerXcol) + ")   ";
			playerXrow = new_rowPosition;
			playerXcol = new_colPosition;
			if (tackled) {// IF A TACKLE HAPPENED THEN PLAYER X CARRY THE BALL
				Field[playerOrow][playerOcol] = "    O     ";
				Field[new_rowPosition][new_colPosition] = "   X(B)   ";
				tackled = false;
			}
			afterTackle = false;//NO AFTER EFFECTS OF TACKLE
			printField();
			move_playerO(false);//PLAYER O TURN 
		}
}
/******** FUNCTION FOR MOVING AND KICKING OF  PLAYER O *********/
void move_playerO(bool toss)
{
	int new_rowPosition, new_colPosition;//VARIABLES FOR STORING NEW ROW AND COLUMN POSITIONS
	string choice;//IF MOVING PLAYER HAS BALL OR DID TACKLE
	if (toss) {//IF PLAYER X WINS THE TOSS THEN FIRST MOVE
		playerOcol = 2;
		playerOrow = 1;
		Field[1][2] = "   O(B)   ";//SETTING PLAYER O POSITION TO CENTER
		Field[playerXrow][playerXcol] = "    X     ";//PLAYER X ON GOAL POSITION
		printField();
	}
	cout << "\n=========> PLAYER O TURN <==========\n";
	//IF MOVING PLAYER HAS BALL OR DID TACKLE
	if (toss || Field[playerOrow][playerOcol] == "   O(B)   " ||tackled) {
		cout << "Enter K if you want to kick the ball :\n";
		cout << "Enter M if you want to Move with the ball :";
		cin >> choice;
		while (!(choice == "K" || choice == "k" || choice == "M" || choice == "m"))
		{
			cout << "*********** INVALID CHOICE **********\n";
			cout << "Enter K if you want to kick the ball :\n";
			cout << "Enter M if you want to Move with the ball : ";
			cin >> choice;
		}//VALIDATION CHECKS
	}
	else
		choice = "m";//PLAYER WANTS TO MOVE
	if(choice=="K"||choice=="k")//IF PLAYER WANTS TO KICK
	{
		if (toss)
			randomKick(2, "O");//INITIAL RANDOM KICK STARTING FROM CENTER
		else
			randomKick(playerOcol, "O");//CALLING RANDOM KICK FUNCTION
		cout << "********* KICKED BY PLAYER O ********\n";
		if(Field[row_Location][col_Location] == "    X     ")//IF THERE WAS A KEEPER
			Field[row_Location][col_Location] = "   X(B)   ";//HE WILL GRAB THE BALL
		else
			Field[row_Location][col_Location] = "    B     ";//ELSE BALL GOES ON POSITION
		if (tackled)//IF TACKLE WAS HAPPENED
		{
			//HANDLE TACKLING POSITIONS
			Field[updated_Orow][updated_Ocol] = "    O     ";
			Field[playerOrow][playerOcol] = "  (" + to_string(playerXrow) + "," + to_string(playerXcol) + ")   ";
				playerOrow = updated_Orow;
				playerOcol = updated_Ocol;
				tackled = false;//TACKLE DONE SO FALSE
				afterTackle = true;	//AFTER TACKLE WE WANT TO MOVE PLAYERS ACCURATELY		
		}
		else //AFTER TACKLE WE WANT TO MOVE PLAYERS ACCURATELY
		Field[playerOrow][playerOcol] = "    O     ";
		printField();
		/*IF ROW IS 1 AND COLUMN IS 0 AND NO GOAL KEEPER THEN O WINS */
		if (row_Location == 1 && col_Location == 0 && Field[row_Location][col_Location] != "    X     "
			&& Field[row_Location][col_Location] != "   X(B)   ")
		{
			checkWinner("O");
			return;
		}
		else if (row_Location == 1 && col_Location == 0 && (Field[row_Location][col_Location] == "    X     "
			|| Field[row_Location][col_Location]== "   X(B)   "))
		{
			Field[row_Location][col_Location] = "   X(B)   ";
		}
		move_playerX(false);//PLAYER X TURN
	}
	else //IF PLAYER WANTS TO MOVE
	{
		cout << "Enter Row Number you want to move :";
		cin >> new_rowPosition;
		cout << "Enter Column Number you want to move :";
		cin >> new_colPosition;//GETTING NEW POSITIONS
	/******* CHECKING THAT THE PLAYER ONLY TAKES ONE STEP PER TURN AND MOVE TO VALID POSITION******/
		while (!(new_rowPosition <3 && (abs(playerOcol -new_colPosition)==1 ||
			abs(playerOcol - new_colPosition) == 0) && (abs(playerOrow-new_rowPosition)==1 ||
				abs(playerOrow - new_rowPosition) == 0) ||
			(new_rowPosition == playerOrow && new_colPosition == playerOcol)))
		{
			cout << "Enter Valid Row Number you want to move :";
			cin >> new_rowPosition;
			cout << "Enter Valid Column Number you want to move :";
			cin >> new_colPosition;
		}//VALIDATION CHECKS
		/******* CHECKS FOR THE CURRENT STATE OF GAME ********/
		//IF PLAYER HAS BALL AND MOVE TO GOAL WITH BALL
		if (new_rowPosition == 1 && new_colPosition == 0 && Field[new_rowPosition][new_colPosition] != "    X     "
			&& Field[new_rowPosition][new_colPosition]!= "   X(B)   " && Field[playerOrow][playerOcol] != "    O     ")
		{
			checkWinner("O");
			return;
		}
		if (Field[playerOrow][playerOcol] == "   O(B)   ")
		{
			//IF PLAYER CARRIES THE BALL
			Field[new_rowPosition][new_colPosition] = "   O(B)   ";
		}
		else if (Field[new_rowPosition][new_colPosition] == "    B     ")
		{
			//IF THERE IS A BALL ON NEW LOCATION
			//PLAYER O WILL GRAB IT
			Field[new_rowPosition][new_colPosition] = "   O(B)   ";
		}
		else if (Field[new_rowPosition][new_colPosition] == "   X(B)   ")
		{
			//IF PLAYER O TACKLES WITH X WITH BALL
			tackle("O",new_rowPosition,new_colPosition);
		}
		else
		{
			//PLAYER O MOVING TO NEW POSITION
			Field[new_rowPosition][new_colPosition] = "    O     ";
		}
		if(!afterTackle)//IF NO TACKLE PRINT THE REAL LOCATIONS
		Field[playerOrow][playerOcol] = "  (" + to_string(playerOrow) + "," + to_string(playerOcol) + ")   ";
		playerOrow = new_rowPosition;
		playerOcol = new_colPosition;
		if (tackled) {// IF A TACKLE HAPPENED THEN PLAYER O CARRY THE BALL
			Field[playerXrow][playerXcol] = "    X     ";
			Field[new_rowPosition][new_colPosition] = "   O(B)   ";
			tackled = false;
		}
		afterTackle = false;//NO AFTER EFFECTS OF TACKLE
		printField();
		move_playerX(false);//PLAYER X TURN 
	}
}
/*************** FUNCTION FOR DISPLAYING MENU *****************/
void displayMenu()
{
	char choosenPlayer;
	cout << "==> Enter X if you want Player X to Start Game <==\n";
	cout << "==> Enter O if you want Player O to Start Game <== \n";
	cin >> choosenPlayer;
	choosenPlayer=(char)toupper(choosenPlayer);//CONVERTING CHOOSEN PLAYER TO UPPER CASE 
	if (choosenPlayer == 'X' || choosenPlayer == 'O')//FOR VALIDATIONS
	{
		if (choosenPlayer== 'X')
		{
			system("cls");//TO CLEAR CONSOLE SCREEN
			move_playerX(true);//TRUE MEANS PLAYER WON THE TOSS
		}
		else if (choosenPlayer == 'O')
		{
			system("cls");
			move_playerO(true);
		}
	}
	else
	{
		while (true)//VALIDATION CHECKS
		{
			cout << "Enter a Valid Player name : ";
			cin >> choosenPlayer;
			choosenPlayer = (char)toupper(choosenPlayer);
			if (choosenPlayer == 'X' || choosenPlayer == 'O')
				break;
		}
		if (choosenPlayer == 'X')
		{
			move_playerX(true);
		}
		else if (choosenPlayer == 'O')
		{
			system("cls");
			move_playerO(true);
		}
	}
}
/***************** FUNCTION FOR DISPLAYING INSTRUCTIONS********************/
void displayInstructions()
{
	string choice;
	cout << "DO YOU WANT TO READ INSTRUCTIONS (Y/N): ";
	cin >> choice;
	while (!(choice == "Y" || choice == "y" || choice == "N" || choice == "n"))
	{
		cout << "*********** INVALID CHOICE ********\n";
		cout << "DO YOU WANT TO READ INSTRUCTIONS (Y/N): ";
		cin >> choice;
	}
	if (choice == "Y" || choice == "y")
	{
		cout << "1- PLAYER X CAN ONLY MOVE FROM LEFT TO RIGHT. \n";
		cout << "2- PLAYER O CAN ONLY MOVE FROM RIGHT TO LEFT. \n";
		cout << "3- BOTH PLAYERS CAN ONLY TAKE ONE STEP INTO THEIR RESPPECTIVE DIRECTIONS.\n";
		cout << "3- B REPRESENTS BALL. \n";
		cout << "4- X(B) REPRESENTS THAT PLAYER X HAS POSESSION OF BALL. \n";
		cout << "5- O(B) REPRESENTS THAT PLAYER O HAS POSESSION OF BALL. \n";
		cout << "6- WHEN TACKLE HAPPENS BETWEEN PLAYERS BOTH RESIDES ON THE SAME LOCATION\n";
	}
	else if (choice == "N" || choice == "n"){}
}
int main() //MAIN METHOD
{
	//MAIN INTERFACE
	cout << "***********************************\n";
	cout << "* \t\t\t\t  *\n";
	cout << "*\tWELCOME TO GOLDEN GOAL\t  *\n";
	cout << "* \t\t\t\t  *\n";
	cout << "***********************************\n";
	displayInstructions();
	setInitialField();
	displayMenu();
	return 0;
}