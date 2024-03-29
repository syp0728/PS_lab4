#ifndef BOOK_H
#define BOOK_H

// 도서 구조체
typedef struct
{
    char title[100];
    char author[100];
    int pages;
} Book;

void addBook();         // 도서 추가
void listBooks();       // 도서 목록 조회
void updateBook();      // 도서 정보 수정
void deleteBook();      // 도서 삭제
void searchBook();      // 도서 검색
void saveBooksToFile(); // 도서 정보 파일로 저장

#endif // BOOK_H
