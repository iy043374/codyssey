#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

int main(void)
{
    char name[100];
    char date[20];

    printf("2006/10/26: ");
    scanf("%19s", date);

    printf("[이용조]: ");
    scanf(" %[^\n]", name); // 공백 포함 입력

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    // 3초 대기
#ifdef _WIN32
    Sleep(3000);
#else
    sleep(3);
#endif

    // 화면 지우기
    system(CLEAR);

    // 스플래시 출력
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    // 왼쪽 정직삼각형 + 오른쪽 역직삼각형 포함 문장 출력
    const char *lines[] = {
        "[마그라테아 ver 0.1]",
        "풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,",
        "사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,",
        "마그라테아에 오신걸 환영합니다."
    };

    int i;
    for (i = 0; i < 5; i++) {
        int j;

        // 왼쪽 정직삼각형
        for (j = 0; j < i + 1; j++) {
            printf("*");
        }

        // 본문 출력 (첫 줄은 문장이 짧아서 위치 보정)
        if (i < 4) {
            printf("   %-80s", lines[i]);
        } else {
            printf("   %-80s", "");
        }

        // 오른쪽 역직삼각형
        for (j = 0; j < 5 - i; j++) {
            printf("*");
        }

        printf("\n");
    }

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %-40s [실행 시간]: %s년 %s월 %s일\n",
           name,
           strtok(date, "-"), // 연도
           strtok(NULL, "-"), // 월
           strtok(NULL, "-")); // 일

    printf("================================================================================\n");

    return 0;
