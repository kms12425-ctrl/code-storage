#include <stdio.h>

#define SIZE 9

void main_display();
void display_menu();

void main_sudoku();
void display_sudoku();
void generate_sudoku(int (&fixed_board)[SIZE + 1][SIZE + 1], int (&answer_board)[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1], int hint);
void print_board(int board[SIZE + 1][SIZE + 1]);
void play_sudoku(int answer_board[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1]);
void print_board(int board[SIZE + 1][SIZE + 1]);
bool is_valid(int hang, int lie, int value, int answer_board[SIZE + 1][SIZE + 1]);
