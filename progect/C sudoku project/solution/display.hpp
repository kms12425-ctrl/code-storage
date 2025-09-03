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
                    //
                    do
                    {
                        printf("请输入文件地址\n");
                        scanf("%s", file_name);
                    } while (!read_file(file_name, cnf));
                }
            }

            /* code */
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
    printf("|----------------请给出你的选择---------------|\n");
    printf("|--------------------------------------------|\n\n");
    printf("|==================Main Menu=================|\n");
    printf("|--------------------------------------------|\n");
    printf("|            1. SAT求解                      |\n");
    printf("|            2. 百分号数独游戏                |\n");
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