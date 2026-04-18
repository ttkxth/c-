#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN system("cls")
#else
#define CLEAR_SCREEN system("clear")
#endif

// 定义颜色代码
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define GOLD    "\033[1;38;5;220m"
#define SILVER  "\033[1;38;5;255m"
#define ORANGE  "\033[1;38;5;214m"
#define PINK    "\033[1;38;5;213m"

// 随机颜色数组
const char* colors[] = {RED, YELLOW, BLUE, MAGENTA, CYAN, GOLD, SILVER, ORANGE, PINK};

void printSpaces(int n) {
    for(int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printTreeLayer(int width, int level, int offset) {
    for(int j = 0; j < width; j++) {
        // 随机决定是否添加装饰
        int isDeco = rand() % 4;
        int colorIndex = rand() % 9;
        
        if(j == 0) printf(GREEN "[");
        else if(j == width - 1) printf(GREEN "]");
        else if(isDeco == 0) {
            // 装饰球
            printf("%s●" RESET, colors[colorIndex]);
        } else if(isDeco == 1 && j == width/2) {
            // 星星或装饰
            printf(YELLOW "★" RESET);
        } else {
            printf(GREEN "*" RESET);
        }
    }
}

void printTrunk(int width, int treeWidth) {
    int trunkWidth = treeWidth / 3;
    int trunkOffset = (treeWidth - trunkWidth) / 2;
    
    printSpaces(trunkOffset);
    printf(YELLOW "[");
    for(int i = 0; i < trunkWidth-2; i++) printf("|");
    printf("]" RESET "\n");
}

void printMessage(char* message) {
    printf("\n\n");
    printSpaces(20);
    for(int i = 0; i < strlen(message)+4; i++) printf(CYAN "=");
    printf("\n");
    printSpaces(20);
    printf(CYAN "| " WHITE "%s " CYAN "|\n", message);
    printSpaces(20);
    for(int i = 0; i < strlen(message)+4; i++) printf(CYAN "=");
    printf(RESET "\n\n");
}

void animateTree(int height, int duration) {
    time_t startTime = time(NULL);
    int frame = 0;
    
    while(difftime(time(NULL), startTime) < duration) {
        CLEAR_SCREEN;
        
        printf("\n\n");
        printSpaces(35);
        printf(YELLOW "🎄" RED " 圣诞快乐! " YELLOW "🎄\n\n");
        
        // 打印树冠
        for(int i = 0; i < height; i++) {
            int width = 2 * i + 1;
            int offset = height - i - 1;
            
            printSpaces(offset + 30); // 居中显示
            
            // 树尖的星星
            if(i == 0) {
                printSpaces(width/2);
                printf(YELLOW "★\n");
                continue;
            }
            
            printTreeLayer(width, i, offset);
            printf("\n");
        }
        
        // 打印树干
        printSpaces(30 + height - 2);
        printTrunk(5, height*2);
        
        // 打印额外的装饰层
        printSpaces(28);
        for(int i = 0; i < height*2+3; i++) {
            if(rand() % 3 == 0) printf(RED "♥" RESET);
            else if(rand() % 3 == 1) printf(BLUE "♦" RESET);
            else printf(GOLD "♣" RESET);
        }
        printf("\n");
        
        // 闪烁的祝福语
        printMessage("圣诞快乐! 愿你平安喜乐!");
        
        // 底部装饰
        printSpaces(25);
        for(int i = 0; i < 10; i++) {
            int colorIdx = (frame + i) % 9;
            printf("%s🎁" RESET, colors[colorIdx]);
        }
        printf("\n");
        
        printSpaces(28);
        for(int i = 0; i < 6; i++) {
            printf(YELLOW "✦" RESET);
            printf(RED "❤" RESET);
        }
        printf("\n\n");
        
        // 闪烁效果
        printf("\033[5m"); // 开启闪烁
        printSpaces(40);
        printf(RED "Merry Christmas!" RESET);
        printf("\033[0m\n"); // 关闭闪烁
        
        // 刷新输出
        fflush(stdout);
        
        // 等待下一帧
        usleep(300000); // 0.3秒
        frame++;
    }
}

void printStaticTree() {
    printf("\n\n");
    printSpaces(35);
    printf(YELLOW "🎄 华丽圣诞树 🎄\n\n");
    
    // 树冠
    int height = 8;
    for(int i = 0; i < height; i++) {
        int width = 2 * i + 1;
        int offset = height - i - 1;
        
        printSpaces(offset + 30);
        
        if(i == 0) {
            printSpaces(width/2);
            printf(YELLOW "★\n");
            continue;
        }
        
        for(int j = 0; j < width; j++) {
            if(j == 0) printf(GREEN "[");
            else if(j == width - 1) printf(GREEN "]");
            else if(j % 3 == 0) printf(RED "●" RESET);
            else if(j % 5 == 0) printf(BLUE "●" RESET);
            else if(j % 4 == 0) printf(YELLOW "●" RESET);
            else printf(GREEN "*" RESET);
        }
        printf("\n");
    }
    
    // 树干
    printSpaces(30 + height - 2);
    printf(YELLOW "[|||]\n");
    
    // 底部装饰
    printSpaces(28);
    printf(GOLD "══════════════════════\n\n");
    
    printMessage("祝你圣诞快乐，新年如意!");
}

int main() {
    srand(time(NULL));
    
    printf(RED "\n\n        欢迎来到" GREEN " C语言" YELLOW " 圣诞树" BLUE " 生成器!\n" RESET);
    printf(CYAN "        ==============================\n\n");
    
    printf(WHITE "请选择模式:\n");
    printf(GREEN "1. 动态闪烁圣诞树 (10秒)\n");
    printf(YELLOW "2. 静态华丽圣诞树\n");
    printf(BLUE "3. 自定义高度圣诞树\n");
    printf(MAGENTA "0. 退出\n\n");
    printf(WHITE "请输入选择: " RESET);
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            CLEAR_SCREEN;
            animateTree(8, 10); // 8层高，显示10秒
            break;
        case 2:
            CLEAR_SCREEN;
            printStaticTree();
            break;
        case 3:
            CLEAR_SCREEN;
            printf(WHITE "\n请输入圣诞树的高度(4-15): " RESET);
            int customHeight;
            scanf("%d", &customHeight);
            if(customHeight < 4) customHeight = 4;
            if(customHeight > 15) customHeight = 15;
            CLEAR_SCREEN;
            animateTree(customHeight, 8);
            break;
        case 0:
            printf(RED "\n再见！祝你圣诞快乐！\n" RESET);
            return 0;
        default:
            printf(RED "\n无效选择，显示默认圣诞树\n" RESET);
            CLEAR_SCREEN;
            printStaticTree();
    }
    
    // 结束祝福
    printf("\n\n");
    printSpaces(30);
    printf(GREEN "🎅" RED " 来自C语言的祝福 " GREEN "🎅\n");
    printSpaces(28);
    printf(YELLOW "══════════════════════════\n");
    printSpaces(30);
    printf(WHITE "愿你的每一天都充满欢乐!\n\n" RESET);
    
    return 0;
}