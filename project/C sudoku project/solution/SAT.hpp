#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <winnt.h>
#include <chrono>

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
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
// 显示主界面
void main_display();
// 显示菜单
void display_menu();

// 数独主流程
void main_sudoku();
// 显示数独界面
void display_sudoku();
// 生成数独题目
void generate_sudoku(int (&fixed_board)[SIZE + 1][SIZE + 1], int (&answer_board)[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1], int hint, bool value[SIZE * SIZE * SIZE + 1], bool (&is_num)[SIZE + 1][SIZE + 1]);
// 打印棋盘
void print_board(int board[SIZE + 1][SIZE + 1]);
// 数独游戏交互
void play_sudoku(int answer_board[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1], bool is_num[SIZE + 1][SIZE + 1], int fixed_board[SIZE + 1][SIZE + 1]);
// 检查数字是否合法
bool is_valid(int hang, int lie, int value, int play_board[SIZE + 1][SIZE + 1]);
// 写CNF文件
bool write_file(int (&board)[SIZE + 1][SIZE + 1], int num, char name[]);
// 打乱数组
void shuffle(int (&arr)[], int size);
// 用SAT解数独
bool solve_sudoku(int (&board)[SIZE + 1][SIZE + 1], bool (&value)[SIZE * SIZE * SIZE + 1]);

// 读取CNF文件
bool read_file(char file_name[], CNF &cnf);
// 释放CNF链表
void destroy_cnf(CNF &cnf);
// 打印CNF链表
void print_cnf(CNF cnf);

// 查找单子句
int find_unit_clause(clause_list cl);
// 移除子句
void remove_clause(clause_list &cl);
// 化简子句
void simplify(clause_list &cl, int lit);
// 判断是否满足
bool is_satisfy(clause_list cl);
// 判断是否有空子句
bool is_empty_clause(clause_list cl);
// 选择分支变量1
int choose_literal_1(CNF cnf);
// 选择分支变量2
int choose_literal_2(CNF cnf);
// 选择分支变量3
int choose_literal_3(CNF cnf);
// 拷贝子句链表
clause_list copy_cnf(clause_list cl);
// 保存SAT解
bool save_file(int result, char file_name[], double time, bool value[], int bool_count, double time_);
// 基本DPLL算法
bool DPLL(CNF cnf, bool value[], int flag);
// 支持超时的DPLL
int DPLL_2(CNF cnf, bool value[], int flag, const std::chrono::steady_clock::time_point &start, double timeout_seconds);
// 按flag和超时求解，返回耗时
int solve_with_timeout_flag(CNF cnf, bool value[], int flag, double timeout_seconds, double &elapsed_seconds);