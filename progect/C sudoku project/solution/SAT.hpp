#pragma once
/*头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <winnt.h>

typedef struct literal_node // 子句中的文字的链表
{
    int literal;
    struct literal_node *next;
} literal_node, *literal_list;

typedef struct clause_node // 每个子句的链表
{
    literal_list head;
    struct clause_node *next;
} clause_node, *clause_list;

typedef struct cnfNode // 总的cnf文件链表
{
    clause_list root;
    int bool_count;
    int clause_count;
} cnf_node, *CNF;

#define SIZE 9
// display.cpp
void main_display();
void display_menu();
//%_sudoku.cpp
void main_sudoku();
void display_sudoku();
void generate_sudoku(int (&fixed_board)[SIZE + 1][SIZE + 1], int (&answer_board)[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1], int hint);
void print_board(int board[SIZE + 1][SIZE + 1]);
void play_sudoku(int answer_board[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1], bool is_num[SIZE + 1][SIZE + 1]);
void print_board(int board[SIZE + 1][SIZE + 1]);
bool is_valid(int hang, int lie, int value, int play_board[SIZE + 1][SIZE + 1]);
//
bool read_file(char file_name[], CNF &cnf);
bool destroy_cnf(CNF &cnf);