/*
Name: Yilan Ruan
Email: yilanruan1@gmail.com
Project 3 Part A defining all the functions for the tic tac toe board
*/


#include "TicTacToeBoard.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//creates the board
TicTacToeBoard::TicTacToeBoard(){
    int Num = 3;

    //Assigns three rows to the board
    board.resize(Num);

    //Assigns each row to have 3 columns
    for (int row = 0; row < Num; row++) {
        board[row].resize(Num);
    }
    //fill the board with empty string
    for (int r = 0; r < Num; r++) {
        for (int c = 0; c < Num; c++) {
            board[r][c] = ' ';
        }
    }
    //it does not have a return type

}

//return the board size
int TicTacToeBoard::size() const {
    return board.size(); //utilizes the vector library to get size of our board
}

//return the specific value from a specific row and column in the board
char TicTacToeBoard::getValue(int row, int col) const {
    return board[row][col];
}
//update the row and col with the playerID
void TicTacToeBoard::mark(int row, int col, char playerId) {
    board[row][col] = playerId;
}

void TicTacToeBoard::clear(){
    int size = board.size();
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            board[r][c] = ' '; //set each value in the board to empty string
        }
    }
}

bool TicTacToeBoard::isAvailable(int row, int col) const {
    if(!isValidCol(col) || !isValidRow(row)){return false;} //checks if either int or row is out of bounds and if it is then we return false
    if(board[row][col] == ' '){//checks if this position on the board is empty
        return true;
    } else {
        return false;
    }
}
bool TicTacToeBoard::isValidRow(int row) const{
    int size = board.size();
    if(row < 0 || row >= size){ //since our size is one greater than the board number we need to check that the user entered placement isn't greater than size minus one or less than 0
        return false;
    }
    return true;


}

bool TicTacToeBoard::isValidCol(int Col) const{
    int size = board.size();
    if(Col < 0 || Col >= size){
        return false;
    }
    return true;


}

TicTacToeBoard::TicTacToeBoard(int givenSize) {
    int num = 0; //initialize a int variable to hold the size we will use in our for loops
    if(givenSize < 3){
        num = 3;

    } else {
        num = givenSize;
    }

    //Assigns three rows to the board
    board.resize(num);

    //Assigns each row to have 3 columns
    for (int row = 0; row < num; row++) {
        board[row].resize(num);
    }
    //fill the board with empty string
    for (int r = 0; r < num; r++) {
        for (int c = 0; c < num; c++) {
            board[r][c] = ' ';
        }
    }
}
//given separateline
std::string separateLine(int size) {
    std::string str = "   +";
    for (int i = 0; i < size; i++) {
        str += "---+";
    }
    str += "\n";
    return str;
}


string TicTacToeBoard::to_string() const {
    string s;
    int size = board.size();

    // header: "0 1 2"
    s += "     ";
    for (int i = 0; i < size; i++) {
        s += std::to_string(i);
        if (i < size - 1) s += "   ";
    }
    s += "\n";

    for (int r = 0; r < size; r++) {
        s += separateLine(size);
        s += " " + std::to_string(r) + " ";

        for (int c = 0; c < size; c++) {
            char v = getValue(r, c);
            if (v == 0) v = ' ';
            s += "| ";
            s += v;
            s += " ";
        }
        s += "|\n";   // no trailing extra spaces
    }

    s += separateLine(size);
    return s;
}



bool TicTacToeBoard::winByRow(int r, int c) const{
    char check = board[r][c];
    int size = board.size();
    if(board[r][c] == ' '){return false;}
    for(int i = 0; i < size; i++){
        if(board[r][i] != check){
            return false;
        }
    }
    return true;

}

bool TicTacToeBoard::winByCol(int r, int c) const{
    char check = board[r][c];
    int size = board.size();
    if(board[r][c] == ' '){return false;}
    for(int i = 0; i < size; i++){
        if(board[i][c] != check){
            return false;
        }
    }
    return true;
}

bool TicTacToeBoard::winByDiagonal(int r, int c) const{
    char check = board[r][c];
    int size = board.size();
    if(r != c && r + c != size - 1){return false;}//if it doesn't fall on a diagonal then we return false
    if(board[r][c] == ' '){return false;} //if it is an empty field we return false
    if(r == c){ //checking the diagnoal from top left to bot right
        bool allMatch = true;
        for(int i = 0; i < size; i++){
            if(board[i][i] != check){ 
            allMatch = false;
            break; //we stop looking at the other box if there is one incorrect match
            }

        }
        if(allMatch){return true;} //after checking through the adjacent boxes if it all matches then we win
    }
    

    if(r + c == size - 1){ //checks diagnoal from bot right to top left
        bool allMatch = true; //utilize a bool to let us know if it all matches
        for(int i = 0; i < size; i++){
            if(board[i][size-1-i] != check){
            allMatch = false;
            break; //we stop looking at the other box if there is one incorrect match
            }
        }
        if(allMatch){return true;} //after checking through the adjacent boxes if it all matches then we win
    }
    return false;
}


bool TicTacToeBoard::tie() const {
    int n = board.size();
    for (int r = 0; r < n; r++) { //checks if we have seen at least one X or O in the row
        bool SeenX = false; 
        bool SeenO = false;
        for (int c = 0; c < n; c++) {
            if(board[r][c] == 'X'){SeenX = true;} //checks every row if there is a X and O and if thats true then the line is spoiled and cannot win even with future moves and therefore empty space
            if(board[r][c] == 'O'){SeenO = true;}
        }
    if (!(SeenX && SeenO)){return false;} //if we find that the row does not have both X and O then the line can potentially win in a future move
    }

    for (int c = 0; c < n; c++) { //checks if we have seen at least one X or O in the column
        bool SeenX = false; 
        bool SeenO = false;
        for (int r = 0; r < n; r++) {
            if(board[r][c] == 'X'){SeenX = true;}
            if(board[r][c] == 'O'){SeenO = true;}
        }
    //if we see a empty space then it becomes false
        if (!(SeenX && SeenO)){return false;}
    }


    //Checks for diagonals from top left to bottom right
    bool SeenX = false; 
    bool SeenO = false;
    for (int i = 0; i < n; i++) { //checks if we have seen at least one X or O in the diagonals
       //we use one loop because the diagonals are [0,0],[1,1],etc
        if(board[i][i] == 'X'){SeenX = true;}
        if(board[i][i] == 'O'){SeenO = true;}

        
    }
    //checks for diagnoals from top right to bottom left
    if (!(SeenX && SeenO)){return false;}
    for (int i = 0; i < n; i++) { //checks if we have seen at least one X or O in the diagonals
        if(board[i][n-1-i] == 'X'){SeenX = true;}
        if(board[i][n-1-i] == 'O'){SeenO = true;}

        
    }
    if (!(SeenX && SeenO)){return false;}

    return true;

    
}

bool TicTacToeBoard::win(int r, int c) const{
    if(winByCol(r,c)|| winByRow(r,c)||winByDiagonal(r,c)){return true;} //utilizes previous functions to check if we have won
}


        







        






