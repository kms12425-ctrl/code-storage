#include "SAT.hpp"
void main_sudoku() // 数独主函数
{
    int fixed_board[SIZE + 1][SIZE + 1] = {0};  // 生成的数独
    int answer_board[SIZE + 1][SIZE + 1] = {0}; // 答案数独
    int play_board[SIZE + 1][SIZE + 1] = {0};   // 用来玩的数独
    bool is_num[SIZE + 1][SIZE + 1] = {0};      // 判断数独某个位置存不存在数字
    int choice = 1;
    display_sudoku();
    bool flag = 0;
    while (choice)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // 生成数独
            /* code */
            printf("你想要多少个提示数[18~81]\n");
            int hint;
            do
            {
                scanf("%d", &hint);
                if (hint < 18 || hint > 81)
                    printf("数字无效，请重新输入");
            } while (hint < 18 || hint > 81);
            generate_sudoku(fixed_board, answer_board, play_board, hint);
            printf("生成成功!\n");
            break;
        case 2: // 查看答案
            if (!flag)
            {
                printf("请先生成数独\n");
                continue;
            }
            flag = 0;
            printf("答案是：\n");
            print_board(answer_board);
            break;
        case 3: // 游玩数独
            if (!flag)
            {
                printf("请先生成数独\n");
                continue;
            }
            play_sudoku(answer_board, play_board);
            //
            break;
        case 0: // Exit
            return;
        default:
            printf("指令无效\n");
            break;
        }
    }
}

void generate_sudoku(int (&fixed_board)[SIZE + 1][SIZE + 1], int (&answer_board)[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1], int hint)
{
}

void play_sudoku(int answer_board[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1])
{
    while (1)
    {

        int hang, lie;
        printf("请输入行与列,如'2 2'\n查看答案就输入'0 0'\n退出程序就输入'-1 -1'\n提交总答案就输入'-2 -2'\n");
        scanf("%d %d", &hang, &lie);
        if (hang == 0 && lie == 0) // 查看答案
        {
            print_board(answer_board);
            return;
        }

        else if (hang == -1 && lie == -1) // 退出程序
            return;

        else if (hang == -2 && lie == -2) // 提交答案
        {
            bool is_complete = 1;
            for (int i = 1; i < SIZE + 1; i++)
            {
                if (is_complete == 0)

                    break;

                for (int j = 1; j < SIZE + 1; j++)
                {
                    if (play_board[hang][lie] == 0)
                    {
                        is_complete = 0;
                        break;
                    }
                }
            }
            if (is_complete == 0)
            {
                printf("数独还没有完成\n");
                continue;
            }
            else if (is_complete == 1)
            {
                printf("恭喜挑战成功!\n");
                return;
            }
        }

        else if (hang > 9 || hang < 1 || lie > 9 || lie < 1)
        {
            printf("数值非法,请重新输入\n");
            continue;
        }

        else if (play_board[hang][lie])
        {
            printf("此位置已经存在数值,请重新输入\n");
            continue;
        }

        printf("请输入要插入的值\n");
        int value;
        scanf("%d", &value);
        if (value < 1 || value > 9)
        {
            printf("数值非法,请重新输入\n");
            continue;
        }
        if (is_valid(hang, lie, value, answer_board))
        {
            printf("插入成功!\n");
            play_board[hang][lie] = value;
            print_board(play_board);
        }
        else
            printf("错误答案,请重新输入");
    }
}

void print_board(int board[SIZE + 1][SIZE + 1]) // 打印数独
{
    for (int i = 1; i < SIZE + 1; i++)
    {
        for (int j = 1; j < SIZE + 1; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" .");
            }
            else
                printf("%2d", board[i][j]);
            if (j % 3 == 0 || j != SIZE)
                printf(" |");
        }
        printf("\n");
        if (i % 3 == 0 || i != SIZE)
        {
            printf("-------+-------+-------\n");
        }
    }
}
bool is_valid(int hang, int lie, int value, int answer_board[SIZE + 1][SIZE + 1]) // 判断插入的数字在那个位置是不是有效的
{
}