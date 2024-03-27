#include <stdio.h>
#include "book.h"

int main() {
    int choice;
    // initBooks(); // 초기 도서 데이터 설정

    do {
        printf("\n===== 도서 관리 프로그램 =====\n");
        printf("1. 도서 추가\n");
        printf("2. 도서 목록 조회\n");
        printf("3. 도서 정보 수정\n");
        printf("4. 도서 삭제\n");
        printf("5. 도서 검색\n");
        printf("6. 저장 및 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                searchBook();
                break;
            case 6:
                saveBooksToFile();
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    } while (choice != 6);

    return 0;
}
