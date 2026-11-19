#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NUM 69
#define PICK_COUNT 7
#define MAX_SETS 5

void generate_lotto(int numbers[]) {
    int used[MAX_NUM + 1] = {0};
    int count = 0;

    while (count < PICK_COUNT) {
        int num = rand() % MAX_NUM + 1;   // 1 ~ 69
        if (!used[num]) {
            used[num] = 1;
            numbers[count++] = num;
        }
    }

    for (int i = 0; i < PICK_COUNT - 1; i++) {
        for (int j = i + 1; j < PICK_COUNT; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    int lotto[MAX_SETS][PICK_COUNT];
    time_t now;
    struct tm *t;
    FILE *fp;

    srand((unsigned)time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("輸入錯誤！n 必須介於 1~5\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        generate_lotto(lotto[i]);
    }

    fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟檔案！\n");
        return 1;
    }

    now = time(NULL);
    t = localtime(&now);

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s", asctime(t));   

    for (int i = 0; i < MAX_SETS; i++) {
        fprintf(fp, "[%d]: ", i + 1);
        if (i < n) {
            for (int j = 0; j < PICK_COUNT; j++) {
                fprintf(fp, "%02d", lotto[i][j]);
                if (j < PICK_COUNT - 1) fprintf(fp, " ");
            }
        } else {
            for (int j = 0; j < PICK_COUNT; j++) {
                fprintf(fp, "--");
                if (j < PICK_COUNT - 1) fprintf(fp, " ");
            }
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
