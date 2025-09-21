/*----------------------------%-Sudoku----------------------------*/

#include "SAT.hpp"

// 百分号数独的两个窗口坐标（默认：窗口A=左上角3x3，窗口B=右下角3x3）
static const int percentA[9][2] = {
    {2, 2}, {2, 3}, {2, 4}, {3, 2}, {3, 3}, {3, 4}, {4, 2}, {4, 3}, {4, 4}};
static const int percentB[9][2] = {
    {6, 6}, {6, 7}, {6, 8}, {7, 6}, {7, 7}, {7, 8}, {8, 6}, {8, 7}, {8, 8}};

/*
 @ 函数名称: %_Sudoku
 @ 函数功能: %数独交互界面
 @ 返回值: void
 */
void X_Sudoku()
{
    system("cls");
    PrintMenu_X();
    int num;                            // 提示数的个数
    bool isFixed[SIZE + 1][SIZE + 1];   // 记录是否为提示数字
    int board[SIZE + 1][SIZE + 1];      // 生成的初始数独
    int newBoard[SIZE + 1][SIZE + 1];   // 用来玩的数独
    int newBoard2[SIZE + 1][SIZE + 1];  // 保存答案的数独
    bool value[SIZE * SIZE * SIZE + 1]; // 记录DPLL的结果
    for (int i = 1; i <= SIZE * SIZE * SIZE; i++)
        value[i] = FALSE;
    int op = 1;   // 操作
    int flag = 0; // 是否生成数独
    while (op)
    {
        printf("\n|********************************************|\n");
        printf("|--------Please Choose Your Operation--------|\n");
        printf("|********************************************|\n\n");
        printf("               Your choice: ");
        scanf("%d", &op);
        system("cls");
        PrintMenu_X();
        switch (op)
        {
        case 1:
        {
            printf(" Please enter the number of prompts(>=18): ");
            scanf("%d", &num);
            while (num < 18 || num > 81) // 提示数的个数必须大于等于18小于等于81
            {
                printf(" Invalid input, please enter again: ");
                scanf("%d", &num);
            }
            if (Generate_Sudoku(board, newBoard, newBoard2, isFixed, num, value))
            {
                printf(" Generate successfully.\n");
                flag = 1; // 生成成功
            }
            else
                printf(" Generate failed.\n");
            break;
        }
        case 2:
        {
            if (flag)
            {
                Play_Sudoku(newBoard, isFixed);
                PrintMenu_X(); // 每次玩完跳转回来重新打印菜单
            }
            else
                printf(" Please generate the %%_Sudoku first.\n");
            break;
        }
        case 3:
        {
            if (flag)
            {
                printf(" Original Percent_Sudoku:\n");
                Print_Sudoku(board); // 打印原始数独
                printf("\n");
                if (Slove(newBoard2, value)) // 求解数独
                {
                    printf(" Reference answer:\n");
                    Print_Sudoku(newBoard2); // 打印答案
                }
                // WriteToFile(newBoard2, num,"X_Sudoku.cnf");
                // int value[SIZE * SIZE * SIZE + 1];
                // for (int i = 1; i <= SIZE * SIZE * SIZE; i++)
                //     value[i] = FALSE;
                // if (Slove(newBoard2, value))
                // {
                //     printf(" Reference answer:\n");
                //     Print_Sudoku(newBoard2);
                // }
                else
                    printf(" No answer.\n"); // 无解
            }
            else
                printf(" Please generate the Percent_Sudoku first.\n");
            break;
        }
        case 0:
        {
            system("cls"); // 退出时清屏
            break;
        }
        default:
        {
            printf(" Invalid input.\n");
            break;
        }
        }
    }
}

/*
 @ 函数名称: PrintMenu_%
 @ 函数功能: 打印%数独菜单
 @ 返回值: void
 */
void PrintMenu_X()
{
    printf("|**************Menu for Percent_Sudoku******|\n");
    printf("|--------------------------------------------|\n");
    printf("|            1. Generate a Percent_Sudoku    |\n");
    printf("|            2. Play the Percent_Sudoku      |\n");
    printf("|            3. Reference answer             |\n");
    printf("|                 0. EXIT                    |\n");
    printf("|********************************************|\n\n");
}

/*
 @ 函数名称: Generate_Sudoku
 @ 接受参数: int[][],bool[][],int
 @ 函数功能: 生成数独
 @ 返回值: status
 */
status Generate_Sudoku(int board[SIZE + 1][SIZE + 1], int newBoard[SIZE + 1][SIZE + 1], int newBoard2[SIZE + 1][SIZE + 1], bool isFixed[SIZE + 1][SIZE + 1], int num, bool value[SIZE * SIZE * SIZE + 1])
{
    char name[100] = "Percent_Sudoku.cnf"; // 文件名
START:
    srand(time(NULL));
    // 初始化棋盘
    for (int i = 1; i <= SIZE; i++)
        for (int j = 1; j <= SIZE; j++)
        {
            board[i][j] = 0;
            newBoard[i][j] = 0;
            newBoard2[i][j] = 0;
            isFixed[i][j] = TRUE; // 默认全为为提示数字
        }
    int nA[SIZE]; // 1-9的数组用于窗口A
    int nB[SIZE]; // 1-9的数组用于窗口B
    for (int i = 0; i < SIZE; i++)
    {
        nA[i] = i + 1;
        nB[i] = i + 1;
    }
    Shuffle(nA, SIZE); // 打乱数组A
    Shuffle(nB, SIZE); // 打乱数组B
    // 随机填充两个“百分号”窗口的9格，作为种子（并设为固定提示）
    for (int idx = 0; idx < 9; idx++)
    {
        int r = percentA[idx][0];
        int c = percentA[idx][1];
        board[r][c] = nA[idx];
        newBoard[r][c] = nA[idx];
        newBoard2[r][c] = nA[idx];
        isFixed[r][c] = TRUE; // 作为提示保留在初始棋盘中
    }
    for (int idx = 0; idx < 9; idx++)
    {
        int r = percentB[idx][0];
        int c = percentB[idx][1];
        board[r][c] = nB[idx];
        newBoard[r][c] = nB[idx];
        newBoard2[r][c] = nB[idx];
        isFixed[r][c] = TRUE; // 作为提示保留在初始棋盘中
    }
    WriteToFile(board, 27, name); // 将数独约束条件写入文件
    CNF p = (CNF)malloc(sizeof(cnfNode));
    p->root = NULL;
    ReadFile(p, name); // 读取文件并解析CNF
    for (int i = 1; i <= SIZE * SIZE * SIZE; i++)
        value[i] = FALSE;
    if (DPLL(p, value, 3) == ERROR) // 求解数独
        goto START;
    // 将DPLL的结果填入数独
    for (int i = 1; i <= SIZE * SIZE * SIZE + 1; i++)
    {
        if (value[i] == TRUE)
        {
            int row = (i - 1) / (SIZE * SIZE) + 1;
            int col = (i - 1) / SIZE % SIZE + 1;
            int v = (i - 1) % SIZE + 1;
            board[row][col] = v;
            newBoard[row][col] = v;
            newBoard2[row][col] = v;
        }
    }
    // 挖洞,剩下num个提示数
    int remove = 81 - num;
    int single = remove / 9; // single一定小于等于7
    int res = remove - 9 * single;
    // int c[SIZE]={9-single};
    for (int row = 1; row <= 9; row++) // 每行挖single个
    {
        int s = single;
        while (s)
        {
            int col = rand() % SIZE + 1;
            if (board[row][col] != 0) // 没有被挖
            {
                board[row][col] = 0;
                newBoard[row][col] = 0;
                newBoard2[row][col] = 0;
                isFixed[row][col] = FALSE;
                s--;
            }
        }
    }
    while (res) // 挖剩下的
    {
        int row = rand() % SIZE + 1;
        // while(c[row-1]<=2)
        // row = rand() % SIZE + 1;
        int col = rand() % SIZE + 1;
        if (board[row][col] != 0)
        {
            board[row][col] = 0;
            newBoard[row][col] = 0;
            newBoard2[row][col] = 0;
            isFixed[row][col] = FALSE;
            res--;
            // c[row-1]--;
        }
    }
    return OK;
}

/*
 @ 函数名称: Is_Valid
 @ 接受参数: int[][],int,int,int
 @ 函数功能: 判断board[row][col]是否可以填入v
 @ 返回值: status
 */
status Is_Valid(int board[SIZE + 1][SIZE + 1], int row, int col, int v)
{
    // 检查行和列
    for (int i = 1; i <= SIZE; i++)
    {
        if (board[row][i] == v || board[i][col] == v) // 行或列有重复
            return FALSE;
    }
    // 检查3x3宫格
    int startRow = (row - 1) / 3 * 3 + 1; // 宫格的起始行
    int startCol = (col - 1) / 3 * 3 + 1; // 宫格的起始列
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == v) // 宫格内有重复
                return FALSE;
        }
    }
    // 检查撇（副对角线）
    if (row + col == SIZE + 1)
    {
        for (int i = 1; i <= SIZE; i++)
        {
            if (board[i][SIZE - i + 1] == v)
                return FALSE;
        }
    }
    // 检查两个百分号窗口区域：不能有重复
    bool inA = false, inB = false;
    for (int idx = 0; idx < 9; idx++)
    {
        if (percentA[idx][0] == row && percentA[idx][1] == col)
        {
            inA = true;
            break;
        }
    }
    if (inA)
    {
        for (int idx = 0; idx < 9; idx++)
        {
            int r = percentA[idx][0], c = percentA[idx][1];
            if (!(r == row && c == col) && board[r][c] == v)
                return FALSE;
        }
    }
    for (int idx = 0; idx < 9; idx++)
    {
        if (percentB[idx][0] == row && percentB[idx][1] == col)
        {
            inB = true;
            break;
        }
    }
    if (inB)
    {
        for (int idx = 0; idx < 9; idx++)
        {
            int r = percentB[idx][0], c = percentB[idx][1];
            if (!(r == row && c == col) && board[r][c] == v)
                return FALSE;
        }
    }
    return TRUE;
}

/*
 @ 函数名称: Print_Sudoku
 @ 接受参数: int[][]
 @ 函数功能: 打印数独
 @ 返回值: void
 */
void Print_Sudoku(int board[SIZE + 1][SIZE + 1])
{
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            if (board[i][j] == 0) // 未填入
                printf(" .");
            else // 已填入
                printf("%2d", board[i][j]);
            if (j % 3 == 0 && j != SIZE) // 每3列打印一个竖线
                printf(" |");
        }
        printf("\n");
        if (i % 3 == 0 && i != SIZE) // 每3行打印一个横线
            printf("-------+-------+-------\n");
    }
}

/*
 @ 函数名称: Play_Sudoku
 @ 接受参数: int[][], bool[][]
 @ 函数功能: 玩数独的交互界面
 @ 返回值: void
 */
void Play_Sudoku(int board[SIZE + 1][SIZE + 1], bool isFixed[SIZE + 1][SIZE + 1])
{
    system("cls");       // 清屏
    Print_Sudoku(board); // 打印初始数独
    printf("\n");
    while (1)
    {
        int row, col, v;
        printf(" Please enter the row, col and value(0 to EXIT): ");
        scanf("%d", &row);
        if (row == 0) // 退出
        {
            system("cls");
            return;
        }
        scanf("%d%d", &col, &v);
        if (row < 1 || row > SIZE || col < 1 || col > SIZE || v < 1 || v > SIZE) // 输入不合法
        {
            printf(" Invalid input.\n");
            continue;
        }
        if (isFixed[row][col]) // 是提示数
        {
            printf(" This is a fixed number.\n");
            continue;
        }
        if (!Is_Valid(board, row, col, v)) // 不符合数独规则
        {
            printf(" Wrong answer.\n");
            continue;
        }
        else // 符合数独规则
        {
            board[row][col] = v;
            system("cls");
            Print_Sudoku(board); // 打印新数独
            printf("\n");
        }
    }
}

/*
 @ 函数名称: WriteToFile
 @ 接受参数: int[][],int
 @ 函数功能: 将数独约束条件写入文件
 @ 返回值: status
 */
status WriteToFile(int board[SIZE + 1][SIZE + 1], int num, char name[])
{
    FILE *fp;
    if (fopen_s(&fp, name, "w"))
    {
        printf(" Fail!\n");
        return ERROR;
    }
    fprintf(fp, "c %s\n", name);
    fprintf(fp, "p cnf 729 %d\n", num + 12654); // 12654是数独的约束条件
    // 数字ijk表示第i行第j列的数字是k
    // 用公式(i-1)*81+(j-1)*9+k将每个变元映射到1-729的变元上
    /*提示数约束(写在前面,便于单子句规则进行)*/
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            if (board[i][j] != 0)
                fprintf(fp, "%d 0\n", (i - 1) * SIZE * SIZE + (j - 1) * SIZE + board[i][j]);
        }
    }
    /*每个格子的约束*/
    // 每个格子必须填入一个数字
    for (int i = 1; i <= SIZE; i++)
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
    // 每个格子不能填入两个数字
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = k + 1; l <= SIZE; l++)
                {
                    fprintf(fp, "%d %d 0\n", 0 - ((i - 1) * SIZE * SIZE + (j - 1) * SIZE + k), 0 - ((i - 1) * SIZE * SIZE + (j - 1) * SIZE + l));
                }
            }
        }
    }
    /*行约束*/
    // 每一行必须填入1-9
    for (int i = 1; i <= SIZE; i++)
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
    // 每一行不能填入两个相同的数字
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = k + 1; l <= SIZE; l++)
                {
                    fprintf(fp, "%d %d 0\n", 0 - ((i - 1) * SIZE * SIZE + (k - 1) * SIZE + j), 0 - ((i - 1) * SIZE * SIZE + (l - 1) * SIZE + j));
                }
            }
        }
    }
    /*列约束*/
    // 每一列必须填入1-9
    for (int i = 1; i <= SIZE; i++)
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
    // 每一列不能填入两个相同的数字
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            for (int k = 1; k <= SIZE; k++)
            {
                for (int l = k + 1; l <= SIZE; l++)
                {
                    fprintf(fp, "%d %d 0\n", 0 - ((k - 1) * SIZE * SIZE + (i - 1) * SIZE + j), 0 - ((l - 1) * SIZE * SIZE + (i - 1) * SIZE + j));
                }
            }
        }
    }
    /*3x3宫格约束*/
    // 每个3x3宫格必须填入1-9
    for (int i = 1; i <= SIZE; i += 3)
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
    // 每个3x3宫格不能填入两个相同的数字
    for (int i = 1; i <= SIZE; i += 3)
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
    /*百分号窗口约束*/
    /*对角线约束（撇/副对角线）*/
    // 副对角线：对每个数字 k，列出副对角线上的 (row=i, col=SIZE-i+1) 的变量
    for (int k = 1; k <= SIZE; k++)
    {
        for (int i = 1; i <= SIZE; i++)
        {
            int row = i;
            int col = SIZE - i + 1;
            fprintf(fp, "%d ", (row - 1) * SIZE * SIZE + (col - 1) * SIZE + k);
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
    return OK;
}

/*
 @ 函数名称: Slove
 @ 接受参数: int[][],int[]
 @ 函数功能: DPLL求解数独
 @ 返回值: status
 */
status Slove(int board[SIZE + 1][SIZE + 1], bool value[SIZE * SIZE * SIZE + 1])
{
    // clauseList p=NULL;
    // char name[100]="X_Sudoku.cnf";
    // if(ReadFile(p,name)==OK)
    // if(DPLL(p,value)==ERROR)
    //     return ERROR;
    // 利用公式(i-1)*81+(j-1)*9+k反解
    for (int i = 1; i <= SIZE * SIZE * SIZE + 1; i++)
    {
        if (value[i] == TRUE)
        {
            int row = (i - 1) / (SIZE * SIZE) + 1;
            int col = (i - 1) / SIZE % SIZE + 1;
            int v = (i - 1) % SIZE + 1;
            board[row][col] = v;
        }
    }
    return OK;
}

/*
 @ 函数名称: Shuffle
 @ 接受参数: int[],int
 @ 函数功能: 洗牌算法,打乱数组顺序
 @ 返回值: void
 */
void Shuffle(int arr[], int n)
{
    srand(time(NULL)); // 用时间做种子
    // 每次从后面的数中随机选一个数与前面的数交换
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// status Generate_Sudoku(int board[SIZE + 1][SIZE + 1], int newBoard[SIZE + 1][SIZE + 1], int newBoard2[SIZE+1][SIZE+1],bool isFixed[SIZE + 1][SIZE + 1], int num)
// {
//     srand(time(NULL));
//     // 初始化棋盘
//     for (int i = 1; i <= SIZE; i++)
//         for (int j = 1; j <= SIZE; j++)
//         {
//             board[i][j] = 0;
//             newBoard[i][j] = 0;
//             newBoard2[i][j] = 0;
//             isFixed[i][j] = FALSE;
//         }
//     // 生成数独
//     while (num)
//     {
//         int row = rand() % SIZE + 1;
//         int col = rand() % SIZE + 1;
//         if (board[row][col] == 0)
//         {
//             int v = rand() % SIZE + 1;
//             if (Is_Valid(board, row, col, v))
//             {
//                 board[row][col] = v;
//                 newBoard[row][col] = v;
//                 newBoard2[row][col] = v;
//                 isFixed[row][col] = TRUE;
//                 num--;
//             }
//         }
//     }
//     return OK;
// }
/*
 @ 函数名称: Fill_Box
 @ 接受参数: int[][],int[][],int[][],int,int
 @ 函数功能: 填充3x3的宫格
 @ 返回值: status
 */
// status Fill_Box(int board[SIZE + 1][SIZE + 1], int newBoard[SIZE + 1][SIZE + 1], int newBoard2[SIZE + 1][SIZE + 1], int rowStart, int colStart)
// {
//     int n[SIZE - 3];       // 除了对角线以外的6个格子
//     bool flag[SIZE] = {0}; // 标记1-9是否已经填入
//     for (int i = 0; i < 3; i++)
//     {
//         flag[board[rowStart + i][colStart + i] - 1] = 1; // 对角线的3个格子上的数字标记为已填入
//     }
//     int index = 0;
//     for (int i = 0; i < SIZE; i++)
//     {
//         if (!flag[i])
//             n[index++] = i + 1;
//     }
//     Shuffle(n, 6); // 打乱数组
//     index = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             if (board[rowStart + i][colStart + j] == 0) // 没有填入
//             {
//                 board[rowStart + i][colStart + j] = n[index];
//                 newBoard[rowStart + i][colStart + j] = n[index];
//                 newBoard2[rowStart + i][colStart + j] = n[index];
//                 index++;
//             }
//         }
//     }
//     return OK;
// }
