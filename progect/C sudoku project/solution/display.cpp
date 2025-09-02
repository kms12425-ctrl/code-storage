#include "SAT.hpp"
void main_display()
{
    display_menu();
    int choice = 1;
    char file_name[100];
    while (choice)
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // SAT求解
            printf("请输入文件地址");
            scanf("%s", file_name);

            /* code */
            break;
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
    printf("|--------Please Choose Your Operation--------|\n");
    printf("|--------------------------------------------|\n\n");
    printf("|================Menu for SAT================|\n");
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
    printf("|               1. 生成数独                   |\n");
    printf("|               2. 查看答案                   |\n");
    printf("|               3. 游玩数独                   |\n");
    printf("|               0. EXIT                      |\n");
    printf("|********************************************|\n\n");
    return;
}