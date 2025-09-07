#include "SAT.hpp"
// 两个窗口
static const int percentA[9][2] = {
    {2, 2}, {2, 3}, {2, 4}, {3, 2}, {3, 3}, {3, 4}, {4, 2}, {4, 3}, {4, 4}};
static const int percentB[9][2] = {
    {6, 6}, {6, 7}, {6, 8}, {7, 6}, {7, 7}, {7, 8}, {8, 6}, {8, 7}, {8, 8}};
void main_sudoku() // 数独主函数
{
    int fixed_board[SIZE + 1][SIZE + 1] = {0};  // 生成的数独
    int answer_board[SIZE + 1][SIZE + 1] = {0}; // 答案数独
    int play_board[SIZE + 1][SIZE + 1] = {0};   // 用来玩的数独
    bool is_num[SIZE + 1][SIZE + 1];            // 判断数独某个位置存不存在提示数字
    bool value[SIZE * SIZE * SIZE + 1] = {0};
    int choice = 1;
    bool flag = 0;
    while (choice)
    {
        display_sudoku();
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
            generate_sudoku(fixed_board, answer_board, play_board, hint, value, is_num);
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
            play_sudoku(answer_board, play_board, is_num);
            flag = 0;
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

void generate_sudoku(int (&fixed_board)[SIZE + 1][SIZE + 1], int (&answer_board)[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1], int hint, bool value[SIZE * SIZE * SIZE + 1], bool (&is_num)[SIZE + 1][SIZE + 1])
{
    char file_name[100] = "percent_sudoku.cnf";
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
            is_num[i][j] = 1;
    }
    int nA[9], nB[9];
    for (int i = 0; i < SIZE; i++)
    {
        nA[i] = i + 1;
        nB[i] = i + 1;
    }
    shuffle(nA, SIZE);
    shuffle(nB, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        int hang = percentA[i][0];
        int lie = percentA[i][1];
        play_board[hang][lie] = nA[i];
        fixed_board[hang][lie] = nA[i];
        answer_board[hang][lie] = nA[i];
        is_num[hang][lie] = 1;
    }
    for (int i = 0; i < SIZE; i++)
    {
        int hang = percentB[i][0];
        int lie = percentB[i][1];
        play_board[hang][lie] = nB[i];
        fixed_board[hang][lie] = nB[i];
        answer_board[hang][lie] = nB[i];
        is_num[hang][lie] = 1;
    }
    write_file(fixed_board, 27, file_name);
    CNF cnf = new cnf_node;
    cnf->root = NULL;
    read_file(file_name, cnf);
}

void play_sudoku(int answer_board[SIZE + 1][SIZE + 1], int (&play_board)[SIZE + 1][SIZE + 1], bool is_num[SIZE + 1][SIZE + 1])
{
    while (1)
    {
        print_board(play_board);
        int hang, lie;
        printf("请输入要插入的行与列,如'2 2'\n查看答案就输入'0 0'\n退出程序就输入'-1 -1'\n提交总答案就输入'-2 -2'\n");
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

        else if (is_num[hang][lie])
        {
            printf("这个位置已经存在提示数值,请重新输入\n");
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
        if (is_valid(hang, lie, value, play_board))
        {
            printf("插入成功!\n");
            play_board[hang][lie] = value;
            print_board(play_board);
            printf("\n");
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
                printf(" x");
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
bool is_valid(int hang, int lie, int value, int play_board[SIZE + 1][SIZE + 1]) // 判断插入的数字在那个位置是不是有效的
{
    for (int i = 1; i < SIZE + 1; i++) // 一行不能有相同数字
    {
        if (i != lie && value == play_board[hang][i])
            return 0;
    }
    for (int i = 1; i < SIZE + 1; i++) // 一列不能有相同数字
    {
        if (i != hang && value == play_board[i][lie])
            return 0;
    }

    // 每个3x3单元格里面不能有相同数字
    int start_hang = (hang - 1) / 3 * 3 + 1;
    int start_lie = (lie - 1) / 3 * 3 + 1;
    for (int i = start_hang; i < start_hang + 3; i++)
    {
        for (int j = start_lie; j < start_lie + 3; j++)
        {
            if ((i != hang || j != lie) && value == play_board[i][j])
                return 0;
        }
    }

    // 副对角线不能有相同数字
    if (hang + lie == 10)
    {
        for (int i = 1, j = SIZE; i < SIZE + 1, j >= 0; i++, j--)
        {
            if ((i != hang || j != lie) && value == play_board[i][j])
                return 0;
        }
    }

    // 百分号窗口不能有相同数字
    bool in_a = 0, in_b = 0;
    if ((hang >= 1 && hang <= 3) && (lie >= 1 && lie <= 3))
        in_a = 1;
    else if ((hang >= 6 && hang <= 8) && (lie >= 6 && lie <= 8))
        in_b = 1;
    if (in_a) // 在左上的窗口
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if ((i != hang || j != lie) && value == play_board[i][j])
                    return 0;
            }
        }
    }
    else if (in_b) // 在右下的窗口
    {
        for (int i = 6; i <= 8; i++)
        {
            for (int j = 6; j <= 8; j++)
            {
                if ((i != hang || j != lie) && value == play_board[i][j])
                    return 0;
            }
        }
    }
    return 1;
}
void shuffle(int (&arr)[], int size)
{
    srand(time(NULL));
    for (int i = size - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return;
}

bool write_file(int (&board)[SIZE + 1][SIZE + 1], int num, char name[])
{

    FILE *fp;
    if (fopen_s(&fp, name, "w"))
    {
        printf("cnf文件写入失败");
        return 0;
    }
    fprintf(fp, "c %s\n", name);
    fprintf(fp, "p cnf 729 %d", num + 12654);
    for (int i = 1; i <= SIZE; i++) //
    {
        for (int j = 1; j <= SIZE; j++)
        {
            if (board[i][j] != 0)
                fprintf(fp, "%d 0\n", (i - 1) * SIZE * SIZE + (j - 1) * SIZE + board[i][j]);
        }
    }

    for (int i = 1; i <= SIZE; i++) // 每个单元格必须要有数字
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                fprintf(fp, "%d ", (i - 1) * SIZE * SIZE + (j - 1) * SIZE + k);
            }
            fprintf(fp, "0\n");
        }
    }

    for (int i = 1; i <= SIZE; i++) // 每个格子只能有一个数字
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = k + 1; k <= SIZE; k++)
                    fprintf(fp, "%d %d 0", -((i - 1) * SIZE * SIZE + (j - 1) * SIZE + k), -((i - 1) * SIZE * SIZE + (j - 1) * SIZE + l));
            }
        }
    }

    for (int i = 1; i <= SIZE; i++) // 每行要有1~9
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                fprintf(fp, "%d ", (i - 1) * SIZE * SIZE + (k - 1) * SIZE + j);
            }
            fprintf(fp, "0\n");
        }
    }

    for (int i = 1; i <= SIZE; i++) // 每行数字不能重复
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = k + 1; k <= SIZE; k++)
                    fprintf(fp, "%d %d 0", -((i - 1) * SIZE * SIZE + (k - 1) * SIZE + j), -((i - 1) * SIZE * SIZE + (l - 1) * SIZE + j));
            }
        }
    }

    for (int i = 1; i <= SIZE; i++) // 每列要有1~9
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                fprintf(fp, "%d ", (k - 1) * SIZE * SIZE + (i - 1) * SIZE + j);
            }
            fprintf(fp, "0\n");
        }
    }

    for (int i = 1; i <= SIZE; i++) // 每列数字不能重复
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = k + 1; k <= SIZE; k++)
                    fprintf(fp, "%d %d 0", -((k - 1) * SIZE * SIZE + (i - 1) * SIZE + j), -((l - 1) * SIZE * SIZE + (i - 1) * SIZE + j));
            }
        }
    }

    for (int i = 1; i <= SIZE; i += 3) // 每个3x3宫格必须填入1-9
    {
        for (int j = 1; j <= SIZE; j += 3)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    for (int m = 0; m < 3; m++)
                    {
                        fprintf(fp, "%d ", ((i + l - 1) * SIZE * SIZE + (j + m - 1) * SIZE + k));
                    }
                }
                fprintf(fp, "0\n");
            }
        }
    }

    for (int i = 1; i <= SIZE; i += 3) // 每个3x3宫格不能填入两个相同的数字
    {
        for (int j = 1; j <= SIZE; j += 3)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    for (int m = 0; m < 3; m++)
                    {
                        for (int n = k + 1; n <= SIZE; n++)
                        {
                            fprintf(fp, "%d %d 0\n", 0 - ((i + l - 1) * SIZE * SIZE + (j + m - 1) * SIZE + k), 0 - ((i + l - 1) * SIZE * SIZE + (j + m - 1) * SIZE + n));
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= SIZE; i++) // 副对角线要有1~9
    {
        for (int k = 1; k <= SIZE; k++)
        {
            int hang = k, lie = SIZE - k + 1;
            fprintf(fp, "%d ", (hang - 1) * SIZE * SIZE + (lie - 1) * SIZE + k);
        }
        fprintf(fp, "0\n");
    }

    // 副对角线不能在同一数字上重复
    for (int k = 1; k <= SIZE; k++)
    {
        for (int p = 1; p <= SIZE; p++)
        {
            for (int q = p + 1; q <= SIZE; q++)
            {
                int row1 = p, col1 = SIZE - p + 1;
                int row2 = q, col2 = SIZE - q + 1;
                fprintf(fp, "%d %d 0\n", 0 - ((row1 - 1) * SIZE * SIZE + (col1 - 1) * SIZE + k),
                        0 - ((row2 - 1) * SIZE * SIZE + (col2 - 1) * SIZE + k));
            }
        }
    }
    // 两个百分号窗口(9格)对每个数字k必须包含1-9之一
    for (int k = 1; k <= SIZE; k++)
    {
        for (int idx = 0; idx < 9; idx++)
        {
            int i = percentA[idx][0];
            int j = percentA[idx][1];
            fprintf(fp, "%d ", (i - 1) * SIZE * SIZE + (j - 1) * SIZE + k);
        }
        fprintf(fp, "0\n");
        for (int idx = 0; idx < 9; idx++)
        {
            int i = percentB[idx][0];
            int j = percentB[idx][1];
            fprintf(fp, "%d ", (i - 1) * SIZE * SIZE + (j - 1) * SIZE + k);
        }
        fprintf(fp, "0\n");
    }
    // 窗口内不能有两个相同的数字（分别对两个窗口约束）
    for (int k = 1; k <= SIZE; k++)
    {
        for (int a = 0; a < 9; a++)
        {
            for (int b = a + 1; b < 9; b++)
            {
                int i1 = percentA[a][0], j1 = percentA[a][1];
                int i2 = percentA[b][0], j2 = percentA[b][1];
                fprintf(fp, "%d %d 0\n", 0 - ((i1 - 1) * SIZE * SIZE + (j1 - 1) * SIZE + k), 0 - ((i2 - 1) * SIZE * SIZE + (j2 - 1) * SIZE + k));
            }
        }
        for (int a = 0; a < 9; a++)
        {
            for (int b = a + 1; b < 9; b++)
            {
                int i1 = percentB[a][0], j1 = percentB[a][1];
                int i2 = percentB[b][0], j2 = percentB[b][1];
                fprintf(fp, "%d %d 0\n", 0 - ((i1 - 1) * SIZE * SIZE + (j1 - 1) * SIZE + k), 0 - ((i2 - 1) * SIZE * SIZE + (j2 - 1) * SIZE + k));
            }
        }
    }
    fclose(fp);
    return 1;
}

bool solve_sudoku(int (&board)[SIZE + 1][SIZE + 1], bool (&value)[SIZE * SIZE * SIZE + 1])
{
    for (int i = 0; i < SIZE * SIZE * SIZE + 1; i++)
    {
        if (value[i])
        {
            int hang = (i - 1) / (SIZE * SIZE) + 1;
            int lie = (i - 1) / SIZE % SIZE + 1;
            int val = (i - 1) % SIZE + 1;
            board[hang][lie] = val;
        }
    }
    return 1;
}