#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"


#define MAX_BOOKS 100 // 최대 도서 수

// 도서 정보 배열
Book books[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    if (numBooks >= MAX_BOOKS) {
        printf("더 이상 도서를 추가할 수 없습니다.\n");
        return;
    }

    printf("도서 제목: ");
    scanf("%s", books[numBooks].title);
    printf("저자: ");
    scanf("%s", books[numBooks].author);
    printf("페이지 수: ");
    scanf("%d", &books[numBooks].pages);

    numBooks++;
    printf("도서가 추가되었습니다.\n");
}

void listBooks() {
    printf("\n===== 도서 목록 =====\n");
    for (int i = 0; i < numBooks; i++) {
        printf("제목: %s | 저자: %s | 페이지 수: %d\n", books[i].title, books[i].author, books[i].pages);
    }
}

void updateBook() {

}

void deleteBook() {

}

void searchBook() {

}

void saveBooksToFile() {

}
