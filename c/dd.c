/*  xmas.c  华丽圣诞树  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#define SLEEP(x) Sleep(x)
#else
#define CLEAR "clear"
#define SLEEP(x) usleep((x)*1000)
#endif

/* 彩色宏 */
const char *col[] = {
    "\033[31m", "\033[32m", "\033[33m", "\033[34m",
    "\033[35m", "\033[36m", "\033[37m", "\033[91m",
    "\033[92m", "\033[93m", "\033[94m", "\033[95m",
    "\033[96m", "\033[97m"
};
#define RESET "\033[0m"
#define STAR  "\033[93m★\033[0m"

int main(void) {
    int h = 23;                 /* 树高（奇数更好看） */
    int snowCnt = 80;           /* 雪花数量 */
    int speed   = 120;          /* 毫秒，越小越快 */
    int snow[80], i, j, k, c = 0;

    srand((unsigned)time(NULL));
    for (i = 0; i < snowCnt; ++i) snow[i] = rand() % (h + 5);

    while (1) {
        system(CLEAR);

        /* 星空背景 */
        for (i = 0; i < 5; ++i) {
            for (j = 0; j < 80; ++j)
                putchar(rand() % 8 == 0 ? '.' : ' ');
            putchar('\n');
        }

        /* 树顶星 */
        printf("%*s%s\n", h, "", STAR);

        /* 树冠层 */
        for (i = 1; i <= h; ++i) {
            int leaf = 2 * i - 1;
            printf("%*s", h - i + 1, "");
            for (j = 0; j < leaf; ++j) {
                /* 随机彩灯 */
                int color = rand() % 14;
                printf("%s", col[color]);
                putchar("*+o"[rand() % 3]);
                printf(RESET);
            }
            putchar('\n');
        }

        /* 树干 */
        int trunk = h / 3 | 1;
        for (i = 0; i < trunk; ++i)
            printf("%*s%s[%s]%s\n", h, "", "\033[90m", "|||", RESET);

        /* 树根祝福 */
        printf("%*s%sMerry Christmas & Happy New Year!%s\n\n",
               h - 16, "", "\033[91m\033[1m", RESET);

        /* 雪花下落 */
        for (i = 0; i < snowCnt; ++i) {
            int line = snow[i];
            if (line < h + 5 + trunk + 3) {
                printf("\033[%d;%dH*", line + 1, rand() % 78 + 1);
                snow[i] = line + 1;
            } else {
                snow[i] = 0;          /* 到底部后重置到顶部 */
            }
        }
        fflush(stdout);
        SLEEP(speed);
    }
    return 0;
}