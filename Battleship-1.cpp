#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

char cpuBoard[20][20];
char playerBoardH[20][20];
char boardSize;
int size;
int turns = 1;
int hits = 0;
int misses = 0;

void setupCpuBoard() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cpuBoard[i][j] = '+';
			playerBoardH[i][j] = '+';
		}
	}
	if (boardSize == 'e' || boardSize == 'E') {
		size = 10;
	} else if (boardSize == 'm' || boardSize == 'M') {
		size = 15;
	} else if (boardSize == 'h' || boardSize == 'H') {
		size = 20;
	}

	int orientation = 0;
	bool isValidPosition = 0;

	// Place carrier
	orientation = rand() % 2 + 1;
	int xPos = (rand() % (size - 5));
	int yPos = (rand() % (size - 5));

	if (orientation == 1) {
		for (int i = xPos; i < xPos + 5; i++) {
			cpuBoard[i][yPos] = 'A';
		}
	} else {
		for (int i = xPos; i < xPos + 5; i++) {
			cpuBoard[xPos][i] = 'A';
		}
	}

	// Place battleship
	while (!isValidPosition) {
		orientation = rand() % 2 + 1;
		xPos = (rand() % (size - 3));
		yPos = (rand() % (size - 3));
		isValidPosition = true;
		if (orientation == 1) {
			for (int i = xPos; i < xPos + 4; i++) {
				if (cpuBoard[i][yPos] != '+') {
					isValidPosition = false;
				}
			}
		} else {
			for (int i = yPos; i < yPos + 4; i++) {
				if (cpuBoard[xPos][i] != '+') {
					isValidPosition = false;
				}
			}
		}
	}

	if (orientation == 1) {
		for (int i = xPos; i < xPos + 4; i++) {
			cpuBoard[i][yPos] = 'B';
		}
	} else {
		for (int i = yPos; i < yPos + 4; i++) {
			cpuBoard[xPos][i] = 'B';
		}
	}

	// Place cruiser
	isValidPosition = false;
	while (!isValidPosition) {
		orientation = rand() % 2 + 1;
		xPos = (rand() % (size - 2));
		yPos = (rand() % (size - 2));
		isValidPosition = true;
		if (orientation == 1) {
			for (int i = xPos; i < xPos + 3; i++) {
				if (cpuBoard[i][yPos] != '+') {
					isValidPosition = false;
				}
			}
		} else {
			for (int i = yPos; i < yPos + 3; i++) {
				if (cpuBoard[xPos][i] != '+') {
					isValidPosition = false;
				}
			}
		}
	}

	if (orientation == 1) {
		for (int i = xPos; i < xPos + 3; i++) {
			cpuBoard[i][yPos] = 'C';
		}
	} else {
		for (int i = yPos; i < yPos + 3; i++) {
			cpuBoard[xPos][i] = 'C';
		}
	}

	// Place Sub
	isValidPosition = false;
	while (!isValidPosition) {
		orientation = rand() % 2 + 1;
		xPos = (rand() % (size - 1));
		yPos = (rand() % (size - 1));
		isValidPosition = true;
		if (orientation == 1) {
			for (int i = xPos; i < xPos + 2; i++) {
				if (cpuBoard[i][yPos] != '+') {
					isValidPosition = false;
				}
			}
		} else {
			for (int i = yPos; i < yPos + 2; i++) {
				if (cpuBoard[xPos][i] != '+') {
					isValidPosition = false;
				}
			}
		}
	}

	if (orientation == 1) {
		for (int i = xPos; i < xPos + 2; i++) {
			cpuBoard[i][yPos] = 'S';
		}
	} else {
		for (int i = yPos; i < yPos + 2; i++) {
			cpuBoard[xPos][i] = 'S';
		}
	}

	// Place Destroyer
	isValidPosition = false;
	while (!isValidPosition) {
		orientation = rand() % 2 + 1;
		xPos = (rand() % (size - 1));
		yPos = (rand() % (size - 1));
		isValidPosition = true;
		if (orientation == 1) {
			for (int i = xPos; i < xPos + 2; i++) {
				if (cpuBoard[i][yPos] != '+') {
					isValidPosition = false;
				}
			}
		} else {
			for (int i = yPos; i < yPos + 2; i++) {
				if (cpuBoard[xPos][i] != '+') {
					isValidPosition = false;
				}
			}
		}
	}

	if (orientation == 1) {
		for (int i = xPos; i < xPos + 2; i++) {
			cpuBoard[i][yPos] = 'D';
		}
	} else {
		for (int i = yPos; i < yPos + 2; i++) {
			cpuBoard[xPos][i] = 'D';
		}
	}

	// Print board
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			cout << cpuBoard[x][y] << " ";
		}
		cout << endl;
	}
	cout << "\n\n\n" << endl;
}

void printBoard() {
	if (size == 10) {
		cout << "   A B C D E F G H I J" << endl;
		for (int x = 0; x < size; x++) {
			if (x < 9) {
				cout << x + 1 << " |";
			} else {
				cout << x + 1 << "|";
			}
			for (int y = 0; y < size; y++) {
				cout << playerBoardH[x][y] << " ";
			}
			cout << endl;
		}
	}

	if (size == 15) {
		cout << "   A B C D E F G H I J K L M N O" << endl;
		for (int x = 0; x < size; x++) {
			if (x < 9) {
				cout << x + 1 << " |";
			} else {
				cout << x + 1 << "|";
			}

			for (int y = 0; y < size; y++) {
				cout << playerBoardH[x][y] << " ";
			}
			cout << endl;
		}
	}

	if (size == 20) {
		cout << "   A B C D E F G H I J K L M N O P Q R S T" << endl;
		for (int x = 0; x < size; x++) {
			if (x < 9) {
				cout << x + 1 << " |";
			} else {
				cout << x + 1 << "|";
			}

			for (int y = 0; y < size; y++) {
				cout << playerBoardH[x][y] << " ";
			}
			cout << endl;
		}
	}
}

bool updateBoard(char coords[]) {
	int xMove = 0;		   // letter
	int yMove = coords[1]; // number
	if ((coords[1] == '1') && (coords[2] == '0')){
  yMove = yMove + 9;}
  if (coords[2] == '1'){
  yMove = yMove + 10;}
	if (coords[2] == '2'){
  yMove = yMove + 11;}
  if (coords[2] == '3'){
  yMove = yMove + 12;}
  if (coords[2] == '4'){
  yMove = yMove + 13;}
  if (coords[2] == '5'){
  yMove = yMove + 14;} 
  if (coords[2] == '6'){
  yMove = yMove + 15;}
  if (coords[2] == '7'){
  yMove = yMove + 16;}
  if (coords[2] == '8'){
  yMove = yMove + 17;}
  if (coords[2] == '9'){
  yMove = yMove + 18;}
  if ((coords[1] == '2') && (coords[2] == '0')){
  yMove = yMove + 18;}

	yMove -= 48;

	if (coords[0] == 'A' || coords[0] == 'a') {
		xMove = 1;
	}
	if (coords[0] == 'B' || coords[0] == 'b') {
		xMove = 2;
	}
	if (coords[0] == 'C' || coords[0] == 'c') {
		xMove = 3;
	}
	if (coords[0] == 'D' || coords[0] == 'd') {
		xMove = 4;
	}
	if (coords[0] == 'E' || coords[0] == 'e') {
		xMove = 5;
	}
	if (coords[0] == 'F' || coords[0] == 'f') {
		xMove = 6;
	}
	if (coords[0] == 'G' || coords[0] == 'g') {
		xMove = 7;
	}
	if (coords[0] == 'H' || coords[0] == 'h') {
		xMove = 8;
	}
	if (coords[0] == 'I' || coords[0] == 'i') {
		xMove = 9;
	}
	if (coords[0] == 'J' || coords[0] == 'j') {
		xMove = 10;
	}
	if (coords[0] == 'K' || coords[0] == 'k') {
		xMove = 11;
	}
	if (coords[0] == 'L' || coords[0] == 'l') {
		xMove = 12;
	}
	if (coords[0] == 'M' || coords[0] == 'm') {
		xMove = 13;
	}
	if (coords[0] == 'N' || coords[0] == 'n') {
		xMove = 14;
	}
	if (coords[0] == 'O'|| coords[0] == 'o') {
		xMove = 15;
	}
	if (coords[0] == 'P' || coords[0] == 'p') {
		xMove = 16;
	}
	if (coords[0] == 'Q' || coords[0] == 'q') {
		xMove = 17;
	}
	if (coords[0] == 'R' || coords[0] == 'r') {
		xMove = 18;
	}
	if (coords[0] == 'S' || coords[0] == 's') {
		xMove = 19;
	}
	if (coords[0] == 'T' || coords[0] == 't') {
		xMove = 20;
	}

	if (cpuBoard[yMove - 1][xMove - 1] != '+') {
		hits++;
		turns++;
		playerBoardH[yMove - 1][xMove - 1] = 'X';
	} else {
		misses++;
		turns++;
		playerBoardH[yMove - 1][xMove - 1] = 'O';
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (cpuBoard[i][j] != '+' && playerBoardH[i][j] != 'X') {
				return false;
			}
		}
	}
	return true;
}

int main() {
	srand(time(0));
	cout << "What difficulty would you like to play on?" << endl;
	cout << "Easy (10x10) input e" << endl
		 << "Medium (15x15) input m" << endl
		 << "Hard (20x20) input h" << endl;
	bool choice = false;
	// Menu Options
	while (!choice) {
		cin >> boardSize;
		if ((boardSize == 'e') || (boardSize == 'm') || (boardSize == 'h') || (boardSize == 'E') || (boardSize == 'M') || (boardSize == 'H')) {
			choice = true;
		} else {
			cout << "Please enter a valid choice" << endl;
		}
	}
	setupCpuBoard();

	// Game Loop

	bool boardIsClear = false;

	string move = "";
	char coords[3];
coords[2] = 'h';
	while (!boardIsClear) {
		// print board
		printBoard();
		cout << endl;
		cout << "Turn: " << turns << endl;
		cout << "Hits: " << hits << endl;
		cout << "Misses: " << misses << endl;
		cout << "Enter move: ";
		cin >> move;
		strcpy(coords, move.c_str());
		for (int i = 0; i < 3; i++) {
			cout << coords[i] << endl;
		}
		
		boardIsClear = updateBoard(coords);
		if (boardIsClear) {
			cout << "You win!" << endl;
		}
	}
	return 0;
}
