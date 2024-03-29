#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

#define MAX_BOOKS 100 // 최대 도서 수

// 도서 정보 배열
Book books[MAX_BOOKS]; // Book 구조체 배열 선언
int numBooks = 0; // 현재 도서 수

void addBook() {
    if(numBooks >= MAX_BOOKS){
        printf("더 이상 도서를 추가할 수 없습니다. \n");
        return;
    }

    printf("도서 제목: ");
    scanf("%s", &books[numBooks].title); // 제목 입력
    printf("저자: ");
    scanf("%s", &books[numBooks].author); // 저자 입력
    printf("페이지 수: ");
    scanf("%d", &books[numBooks].pages); // 페이지 수 입력

    numBooks++; // 도서 수 증가
    printf("도서가 추가되었습니다. \n");

}

void listBooks() {
    printf("\n===== 도서 목록 =====\n");
    for(int i = 0; i < numBooks; i++){
        printf("제목: %s | 저자: %s | 페이지 수: %d\n", books[i].title, books[i].author, books[i].pages);
    }

}

void updateBook() {
    char title[100];
    printf("수정할 도서의 제목을 입력하세요: "); // 수정할 도서 
    scanf("%s", title);

    for(int i=0; i<numBooks; i++){
        if(strcmp(books[i].title, title) == 0){ // 입력된 도서와 일치하는 도서 찾기 (strcmp)
            printf("새로운 저자: ");
            scanf("%s", &books[i].author);
            printf("새로운 페이지 수: ");
            scanf("%d", &books[i].pages);
            printf("도서 정보가 수정되었습니다.\n");
            return;
        }
    }
}

void deleteBook() {
    char title[100];
    printf("삭제할 도서의 제목을 입력하세요: "); // 삭제할 도서 제목
    scanf("%s", &title);

    for(int i=0; i<numBooks; i++){
        if(strcmp(books[i].title, title) == 0){ // 입력된 도서와 일치하는 도서 찾기 (strcmp)
            for(int j=i; j<numBooks-1; j++){
                strcpy(books[j].title, books[j+1].title);
                strcpy(books[j].author, books[j+1].author);
                strcpy(books[j].pages, books[j+1].pages);
            }
            numBooks--; // 도서 수 감소
            printf("도서가 삭제되었습니다.\n");
            return;
        }
    }
    printf("해당 제목의 도서를 찾을 수 없습니다.\n");
}

void searchBook() {
    char keyword[100];
    printf("검색할 도서의 키워드를 입력하세요: "); // 검색할 키워드
    scanf("%s", &keyword);

    printf("\n===== 검색 결과 =====\n");
    for(int i=0; i<numBooks; i++){
        if(strstr(books[i].title, keyword) != NULL || strstr(books[i].author, keyword) != NULL) { // 일치하는 문자열이 있는지 확인 (strstr)
            printf("제목: %s | 저자: %s | 페이지 수: %d\n", books[i].title, books[i].author, books[i].pages);
        }
    }
}

void saveBooksToFile() {
    FILE *file = fopen("books.txt", "w"); // 파일 열기
    if(file == NULL){
        printf("파일을 열 수 없습니다. \n");
        return;
    }

    for(int i=0; i<numBooks; i++){
        fprintf(file, "%s %s %d\n", books[i].title, books[i].author, books[i].pages);
    }
    
    fclose(file); // 파일 닫기
    printf("도서 정보가 저장되었습니다.\n");

}
