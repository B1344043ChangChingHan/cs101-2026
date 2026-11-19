#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define BOOK_COUNT 6

typedef struct Books {
    int id;
    int price;
    char title[MAX_TITLE];
} book_t;

void total_price(book_t books[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += books[i].price;
    }
    printf("總共價錢：%d\n", sum);
}

void list_books(book_t books[], int count) {
    printf("\n書籍資料：\n");
    printf("%-5s %-8s %s\n", "Id", "Price", "Title");
    printf("--------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-8d %s\n", books[i].id, books[i].price, books[i].title);
    }
}

int main() {
    book_t books[BOOK_COUNT] = {
        {1, 1000, "All the Light We Cannot See"},
        {2,  300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4,  550, "Killers of the Flower Moon"},
        {5,  870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟檔案 Book.bin\n");
        return 1;
    }
    fwrite(books, sizeof(book_t), BOOK_COUNT, fp);
    fclose(fp);
    printf("已將書籍資料寫入 Book.bin\n");

    total_price(books, BOOK_COUNT);
    list_books(books, BOOK_COUNT);

    return 0;
}
