//
// Created by Youssef Abbas on 27/03/2023.
//

/*
 *
 *
1. Test the main flow against the wrong symbol choice
2. Test the main flow against repeated symbol choice
3. Test the main flow against X player winning:
- All Rows winning (3)
- All Columns winning (3)
- All Diagonals winning (2)
4. Test the main flow against O player winning:
- All Rows winning (3)
- All Columns winning (3)
- All Diagonals winning (2)
5. Test the main flow against X player draw case at least three draw cases
 */
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>


// Board size
#define BOARD_SIZE 9
#define NUM_OF_PLAYER 2

// Possible game states
#define GAME_CONTINUE 2
#define GAME_DRAW 1
#define GAME_WIN 0

// Board representation
uint8_t board[BOARD_SIZE];
// Players' configurations
uint8_t configArray[2];

void drawBoard(uint8_t *board){
    // This function will take a board as an input and prints it on the console

    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}
void updateBoard(uint8_t *board,uint8_t position , uint8_t value){
    // This function will take the board, position to update and value to set in this position
    if(position <= BOARD_SIZE)
        board[position] = value;
}

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol){
    //This function will take player number and asks the player to choose between X and O (case insensitive)
    // This function will return 0 when the input symbol is not wrong and/or was not chosen before
    // This function will return 1 when the input symbol is wrong and/or was chosen before
    printf(" Player # %d , Choose Symbol ( X | O )\n",playerNumber);
    static uint8_t symbolSelected ;
    uint8_t symbolInput;
    scanf(" %c",&symbolInput);
    if((toupper(symbolInput) == 'X')&& symbolSelected != 'X'){
        *symbol = 'X';
        symbolSelected = 'X';
        return 0;
    }else if((toupper(symbolInput) == 'O')&& symbolSelected != 'O'){
        *symbol = 'O';
        symbolSelected = 'O';
        return 0;
    }else{
        return 1;
    }


}

void setPlayerConfig(uint8_t *configArray){
    // This function will prompt and asks each user about their preferred symbols and saves it in the configArray
    int8_t i = 0 ;
    while(i< NUM_OF_PLAYER){
//        printf("Player %d :\n",i);
        if (getPlayerSymbol(i+1, &configArray[i])){
            printf("You entered wrong symbol or chosen before\n");
        } else{
            i++;
        }
    }
}
void loadAndUpdate(uint8_t playerNumber) {
    uint8_t position, symbol;
    printf("Player %d, please enter a position (1-9): ", playerNumber+1);
    scanf("%hhu", &position);
    position--; // Decrement position to match array index
    if (position < 0 || position >= BOARD_SIZE) {
        printf("Invalid position. Please enter a number between 1 and 9.\n");
        loadAndUpdate( playerNumber);
    }
    else if (board[position] != ' ') {
        printf("Position already taken. Please choose another position.\n");
        loadAndUpdate( playerNumber);
    } else{
        symbol = (playerNumber == 1) ? configArray[1] : configArray[0];
        updateBoard(board, position, symbol);
    }

}


void getGameState(uint8_t *gameState){
    int i, j;
    // Check rows
    for (i = 0; i < BOARD_SIZE; i+=3) {
        if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] && board[i] != ' ') {
            *gameState = GAME_WIN;
            return;
        }
    }
    // Check columns
    for (i = 0; i < (BOARD_SIZE/3); i++) {
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ') {
            *gameState = GAME_WIN;
            return;
        }
    }
    // Check diagonals
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
        *gameState = GAME_WIN;
        return;
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
        *gameState = GAME_WIN;
        return;
    }
    // Check for draw
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == ' ') {
            break;
        }
        if (i == BOARD_SIZE - 1) {
            *gameState = GAME_DRAW;
            return;
        }
    }
    // Continue playing
    *gameState = GAME_CONTINUE;
}
// This function will check after each move if there is a win, draw or continue playing.

//- Returns 0 for winning
//- Returns 1 for draw
//- Returns 2 for continue

int main() {
    uint8_t player = 0, gameState;
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = ' ';
    }
    setPlayerConfig(configArray);
    do {
        drawBoard(board);
        loadAndUpdate(player);
        getGameState(&gameState);
        player = (player + 1) % NUM_OF_PLAYER;
    } while (gameState == GAME_CONTINUE);
    drawBoard(board);
    if (gameState == GAME_WIN) {
        printf("Player %d wins!\n", player);
    } else {
        printf("Draw!\n");
    }
    return 0;
}
