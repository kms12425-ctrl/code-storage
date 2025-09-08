#include "SAT.hpp"
void main_display()
{
    CNF cnf;
    bool file_exist = 0;
    int choice = 1;
    char file_name[100];
    while (choice)
    {
        display_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // SAT求解
        {
            int ch = 0;
            if (!file_exist)
            {
                do
                {
                    printf("请输入文件地址\n");
                    scanf("%s", file_name);
                    file_exist = 1;
                } while (!read_file(file_name, cnf)); // 检查cnf文件是否存在，顺便初始化cnf链表
            }
            else
            {
                printf("已经存在cnf文件,是否覆盖?[1/0]\n");
                scanf("%d", &ch);
                if (ch == 1)
                {
                    destroy_cnf(cnf);
                    do
                    {
                        printf("请输入文件地址\n");
                        scanf("%s", file_name);
                    } while (!read_file(file_name, cnf));
                }
            }
            printf("求解中...\n");
            // CNF cnf_new = new cnf_node;
            // cnf_new->root = copy_cnf(cnf->root);
            // cnf_new->bool_count = cnf->bool_count;
            // cnf_new->clause_count = cnf->clause_count;
            bool *value = new bool[cnf->bool_count + 1];
            // for (int i = 1; i <= cnf->bool_count; i++)
            //     value[i] = 1;

            LARGE_INTEGER frequency, frequency_;    // 计时器频率
            LARGE_INTEGER start, start_, end, end_; // 设置时间变量
            double time, time_;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start); // 计时开始;
            // int result = DPLL(cnf_new, value, 3);
            auto start_time = std::chrono::steady_clock::now();
            int result = solve_with_timeout(cnf, value, 3, 8.0);
            auto end_time = std::chrono::steady_clock::now();
            double elapsed = std::chrono::duration<double>(end_time - start_time).count();
            if (result == -1)
                printf("求解超时,已尝试多种分支变元选取策略但未得到结论。\n");
            QueryPerformanceCounter(&end);                                       // 结束
            time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; // 计算运行时间
            if (result == 1)
            {
                for (int i = 1; i < cnf->bool_count; i++)
                {
                    if (value[i] == 1)
                        printf("T\n");
                    else
                        printf("F\n");
                }
                printf("有解\n\n");
            }
            else if (result == 0)
                printf("无解\n");
            printf("\n Time: %lf ms\n", time * 1000);
            printf("优化率：%.2f\n", (16.0 - time) / 16);
            if (result == 1 || result == 0)
            {
                printf("是否要保存到文件中?[1/0]\n");
                scanf("%d", &ch);
                if (ch)
                {
                    if (save_file(result, file_name, time, value, cnf->bool_count, time_))
                        printf("保存成功!\n");
                    else
                        printf("保存失败\n");
                }
            }
            break;
        }
        case 2: // 百分号数独游戏
            main_sudoku();
            break;
        case 0: // Exit
            return;
        default:
            printf("指令无效\n");
            break;
        }
    }
    return;
}
void display_menu()
{
    printf("\n|--------------------------------------------|\n");
    printf("|----------------请给出你的选择--------------|\n");
    printf("|--------------------------------------------|\n\n");
    printf("|==================Main Menu=================|\n");
    printf("|--------------------------------------------|\n");
    printf("|            1. SAT求解                      |\n");
    printf("|            2. 百分号数独游戏               |\n");
    printf("|            0.  EXIT                        |\n");
    printf("|============================================|\n\n");
    printf("请选择[1/2/0]\n");
    return;
}
void display_sudoku()
{
    printf("|**************Menu for Percent_Sudoku*******|\n");
    printf("|--------------------------------------------|\n");
    printf("|               1. 生成数独                  |\n");
    printf("|               2. 查看答案                  |\n");
    printf("|               3. 游玩数独                  |\n");
    printf("|               0. EXIT                      |\n");
    printf("|********************************************|\n\n");
    printf("请选择[1/2/3/0]\n");
    return;
}