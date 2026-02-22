/*
Name: Yilan Ruan
Email: yilanruan1@gmail.com
Project 3 Part B defining all the functions for the tic tac toe game
*/

#include "TicTacToeGame.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//default constructor
TicTacToeGame::TicTacToeGame() 
:   tttBoard(),
    currRow(0),
    currCol(0)
{

}


TicTacToeGame::TicTacToeGame(int size) 
:   tttBoard(size),
    currRow(0),
    currCol(0)
{

}

bool TicTacToeGame::isGameOver() const {

if(tttBoard.tie()) { 
    cout << "It is a tie." << endl; 
    return true;
} //if the game ties it is immediately over

for (int r = 0; r < tttBoard.size(); r++) {
    for (int c = 0; c < tttBoard.size(); c++) {
        if(tttBoard.win(r,c)){
            return true;
        }
    }
}

return false;
    
    
}


void TicTacToeGame::humanPlay(){
    int r, c;
    bool valid;
    //utilizes a do while loop to take in row and column before checking if it works
    do{
    valid = true;
    if(!(cin >> r >> c)) {
    return; 
    }
    
 
    if(!tttBoard.isValidCol(c)){
        cout << "col is not in [0, size-1]" << endl;
        valid = false;
    }
    if(!tttBoard.isValidRow(r)){
        cout << "row is not in [0, size-1]"<< endl;
        valid = false;
    }
    if(tttBoard.isValidRow(r) && tttBoard.isValidCol(c)){
        if(!tttBoard.isAvailable(r,c)){
            cout << "The square you pick up is not available.";
            valid = false;


        }
    }

    } while (!valid); 
    cout << r << " " << c << "\n";
    currRow = r;
    currCol = c;
    tttBoard.mark(currRow, currCol, HUMAN_ID);
    


}
void TicTacToeGame::computerPlay(){
    //check through all of the placements using a nested loopto see if there is a winning placement
    for (int r = 0; r < tttBoard.size(); r++) {
        for (int c = 0; c < tttBoard.size(); c++) {
            if(tttBoard.isAvailable(r,c)){
                tttBoard.mark(r, c, COMPUTER_ID); //temporarily mark the new row/col placement so we can check if it wins
                if(tttBoard.win(r,c)){
                    currRow = r;
                    currCol = c;
                    return;

                } else {
                    tttBoard.mark(r, c, ' '); //undo marking if we don't win with this spot
                }
            }

    
        }
    }

    //try to block the human from winning by checking every cell to see if a human mark there would win them the game if that works then we put our mark there instead
    for (int r = 0; r < tttBoard.size(); r++) {
        for (int c = 0; c < tttBoard.size(); c++) {
            if(tttBoard.isAvailable(r,c)){
                tttBoard.mark(r, c, HUMAN_ID); //temporarily mark the new row/col placement with human IDso we can check if it wins
                if(tttBoard.win(r,c)){
                    currRow = r;
                    currCol = c;
                    tttBoard.mark(currRow, currCol, COMPUTER_ID);
                    return;

                } else {
                    tttBoard.mark(r, c, ' '); //undo marking if we don't win with this spot
                }
            }
    
        }
    }

    //If there isn't a spot where we will win or the human will win then we will play the next available slot as per project guidelines
    for (int r = 0; r < tttBoard.size(); r++) {
        for (int c = 0; c < tttBoard.size(); c++) {
            if(tttBoard.isAvailable(r,c)){
                currCol = c;
                currRow = r;
                tttBoard.mark(r, c, COMPUTER_ID);
                return; 
            }

        }
    }
}
void TicTacToeGame::start(){
    tttBoard.clear(); //clears the board
    int counter = 1; //we start at round 1 and not 0 to assign odd numbers to human and even to computer
    cout << tttBoard.to_string() << "\n";
    while(!isGameOver()){
        if (counter % 2 == 1 ){
            cout << "Round " << counter << ": User, enter row and col to place X: "; //start the empty board at round 1
            humanPlay();
            cout << tttBoard.to_string();
        } else {
            computerPlay();
            cout << "Round " << counter << ": Computer places " << COMPUTER_ID << " at row " << currRow << " and col " << currCol << "." << endl;
            cout << tttBoard.to_string(); //utilize previous function to show the current state of the board

        }
        counter++;
        
    }
    if (tttBoard.tie()) {
    cout << "It is a tie." << endl;
    } else {
    char winner = tttBoard.getValue(currRow, currCol);
    if (winner == HUMAN_ID) cout << "Human wins. Yay!!!" << endl;
    else cout << "Computer wins. Yuck." << endl;
}
}
void TicTacToeGame::runRepeat() {
    while (true) {
        start();

        cout << "Do you want to continue (yes/no): "; //matches gradescope
        string answer;
        cin >> answer;

        if (answer == "no") {
            cout << "Bye." << endl; //matches grader
            break;
        }

    }
}




