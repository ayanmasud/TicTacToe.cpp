#include <iostream>
#include <cstring>

using namespace std;

void printBoard(char board[3][3]);
void clearBoard(char board[3][3]);
bool isTie(char board[3][3]);
bool xWin(char board[3][3]);
bool oWin(char board[3][3]);

int main() {
  bool isPlaying = true;
  char board[3][3];
  for(int i = 0; i < 3; i++) { // creates an empty board
    for(int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }

  int xwins = 0; // keeps track of x wins
  int owins = 0; // keeps track of o wins
  
  bool xturn = true;
  while (isPlaying = true) {
    if(xWin(board) == true) { // checks for x win
      cout << "X Wins!" << endl;
      xwins++; // add x win
      cout << "X Wins: " << xwins << endl;
      cout << "O Wins: " << owins << endl;
      clearBoard(board);
      xturn = true; // start with x
    }
    else if(oWin(board) == true) { // checks for o win
      cout << "O Wins!" << endl;
      owins++; // add o win
      cout << "X Wins: " << xwins << endl;
      cout << "O Wins: " << owins << endl;
      clearBoard(board);
      xturn = true; // start with x
    }
    else if(isTie(board) == true) { // checks for ties
      cout << "Tie!" << endl;
      cout << "X Wins: " << xwins << endl;
      cout << "O Wins: " << owins << endl;
      clearBoard(board);
      xturn = true; // start with x
    }
    printBoard(board);
    
    if (xturn == true) { // x turn to move
      cout << "X move: ";
      char xmove[3];
      //cin.getline(xmove, 2);
      //cin.clear();
      //cin.ignore(2, '\n');
      cin.getline(xmove, 3);
      if (xmove[0] == 'q') { // option to quit
	break;
      }
      int row = int(xmove[0]) - 97; // sets it to the correct row index
      int col = int(xmove[1]) + 1 - 50; // sets it to the correct col index
      //cout << row << " " << col << endl;
      if (board[row][col] == ' ') { // if the spot is empty
	board[row][col] = 'X';
	xturn = false; // swaps it to o turn
      }
      else { // otherwise pick a new spot
	cout << "Pick an empty spot." << endl;
	continue;
      }
    }
    else { // o turn to move
      cout << "O move: ";
      char omove[3];
      cin.getline(omove, 3);
      if (omove[0] == 'q') { // option to quit
        break;
      }
      int row = int(omove[0] - 97); // sets it to the correct row index
      int col = int(omove[1] + 1 - 50); // set it to the correct col index
      if(board[row][col] == ' ') { // if is the spot empty
	board[row][col] = 'O';
	xturn = true; // swaps it to x turn
      }
      else { // otherwise pick a new spot
	cout << "Pick an empty spot." << endl;
	continue;
      }
    }
  }
  
  return 0;
}

void printBoard(char board[3][3]) { // prints the board
  cout << " \t1\t2\t3" << endl;
  for(int i = 0; i < 3; i++) {
    cout << char('a'+i);
    for(int j = 0; j < 3; j++) {
      cout << "\t" << board[i][j];
    }
    cout << endl;
  }
}

void clearBoard(char board[3][3]) { // clears the board
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

bool isTie(char board[3][3]) { // checks for ties by seeing whether any spots are still empty. (this is run after checking the wins just in case the win requires all the spots)
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
	return false;
      }
    }
  }
  return true;
}

bool xWin(char board[3][3]) { // checks whether X wins
  if(board[0][0] == 'X' && board[0][1] == 'X' && board [0][2] == 'X') { // horizontal
    return true;
  }
  else if(board[1][0] == 'X' && board[1][1] == 'X' && board [1][2] == 'X') {
    return true;
  }
  else if(board[2][0] == 'X' && board[2][1] == 'X' && board [2][2] == 'X') {
    return true;
  }
  else if(board[0][0] == 'X' && board[1][0] == 'X' && board [2][0] == 'X') { // vertical
    return true;
  }
  else if(board[0][1] == 'X' && board[1][1] == 'X' && board [2][1] == 'X') {
    return true;
  }
  else if(board[0][2] == 'X' && board[1][2] == 'X' && board [2][2] == 'X') {
    return true;
  }
  else if(board[0][0] == 'X' && board[1][1] == 'X' && board [2][2] == 'X') { // diagonal
    return true;
  }
  else if(board[0][2] == 'X' && board[1][1] == 'X' && board [2][0] == 'X') {
    return true;
  }
  else {
    return false;
  }
}

bool oWin(char board[3][3]) { // checks whether O wins
  if(board[0][0] == 'O' && board[0][1] == 'O' && board [0][2] == 'O') { // horizontal
    return true;
  }
  else if(board[1][0] == 'O' && board[1][1] == 'O' && board [1][2] == 'O') {
    return true;
  }
  else if(board[2][0] == 'O' && board[2][1] == 'O' && board [2][2] == 'O') {
    return true;
  }
  else if(board[0][0] == 'O' && board[1][0] == 'O' && board [2][0] == 'O') { // vertical
    return true;
  }
  else if(board[0][1] == 'O' && board[1][1] == 'O' && board [2][1] == 'O') {
    return true;
  }
  else if(board[0][2] == 'O' && board[1][2] == 'O' && board [2][2] == 'O') {
    return true;
  }
  else if(board[0][0] == 'O' && board[1][1] == 'O' && board [2][2] == 'O') { // diagonal
    return true;
  }
  else if(board[0][2] == 'O' && board[1][1] == 'O' && board [2][0] == 'O') {
    return true;
  }
  else {
    return false;
  }
}
