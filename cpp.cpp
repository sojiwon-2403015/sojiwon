#include <stdio.h>      // #은 특별한 명령어 지시 라는 의미, include 끼워넣다 <stdio.h>는 std (Standard) 표준의 기본적인 io(Input/ Output) 입력 출력 .h (Header file) 헤더파일 이라서 "이 코드를 시작하기 전에(#) 화면에 글자를 보여주거나 숫자를 입력받는 (<stdio.h>) 기본 도구 상자를 우리 프로그램 안에 미리 가져와서 끼워 넣어줘 (include)"
#include <stdlib.h>     // lib = library 도서관 도구 모음 .h = header file 헤더 파일 함수 선언 모음 rand, srand (난수생성 무작위 숫자를 만들어내는 기능 / stdlib.h 안에 들어있는 기능)를 사용하기 위해서 헤더 추가
#include <time.h>       // time 함수를 사용하기 위해서 헤더 추가
 
int main(void)      // 프로그램을 실행하는 main 함수, int 프로그램이 끝날 때 정수 값을 운영체제에 돌려줌, void 시작할 때 외부에서 아무것도 안 받음
{                   // 메인함수의 시작
    
    srand(time(NULL));          // srand 난수 발생기 시작점,time(NULL)은 시계에서 현재 초 가져오기 실행할 때마다 시간이 달라지니까 매번 다른 난수 순서가 만들어짐         

    do {                    // do{}무조건 한 번은 실행해라,{}실행할 코드 범위 지정 
        ball[0]= rand() % 10 + 1;       // ball[0] 배열의 첫 번째 칸, = 오른쪽에서 만든 난수를 왼쪽의 ball[0] 칸에 집어넣는다, %10 그 숫자를 10으로 나눈 나머지만 가져옴 (결과는 항상 0~9 범위), +1 범위를 10으로 바꿔줌 또한 시작점을 0이 아닌 1부터 [왜 구지 나눠서 쓰는지? rand()는 너무 큰 숫자를 주기 때문에 ], ; 문장의 끝 표시
        ball[1] = rand() % 10 + 1;      // ball[1] 배열의 두 번째 칸
        ball[2] = rand() % 10 + 1;      // ball[2] 배열의 세 번째 칸
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);    
      // while(조건); 조건이 참일 경우 계속 반복하는 반복문, ball[0] == ball[1] 첫번째 칸과 두번째 칸 값이 같으면 참 [== 왼쪽과 오른쪽 값이 같은지 비교 의미], || 또는 이라는 의미

    printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]);
      // printf() 함수(기계)에 전달하는 통로, %d는 int(정수)를 출력하는 자리표, \n 줄바꿈(Enter), ,의 의미는 이 값은 따로따로 전달, 
      // ball[0], ball[1], ball[2] %d(빈칸자리표)에 채워 넣어야 할 값들, "" 안에 있는 것은 그대로 출력

    //3개의 숫자를 입력
    int input[3];       // int 숫자 담을 그릇, 즉 정수, input 배열 이름 사람이 직접 잆력값, [3] 3개의 정수, ;끝
    printf("Enter the first number: ");     // printf 출력 함수, ()안에 있는 것을 
    scanf("%d", &input[0]);     //scanf 입력값을 변수(값을 담아두는 이름 붙은 그릇)에 저장, "%d" 정수 그대로 저장하겠다, & 저장한 변수 주소 위치, &input[0] 첫번째 입력한 값의 주소 (여기에 저장해 %d이걸 그대로)
                                // printf는 , 뒤에 있는걸 %d에 넣어서 그대로 출력 하라는거고 scanf는 %d 정수를 그대로 저장을  &intput[0]에 저장해라

    printf("Enter the second number: ");    // printf 출력 함수, ()안에 있는 것을 
    scanf("%d", &input[1]);     // %d를 그대로 저장하는데 &input[1] 위치에 저장해라

    printf("Enter the third number: ");     // printf 출력 함수, ()안에 있는 것을
    scanf("%d", &input[2]);     // %d를 그대로 저장하는데 &input[2] 위치에 저장해라


    printf("input : %d %d %d\n", input[0], input[1], input[2]) ;
        // printf()안에 있는 것을 출력 하는데 "" 안에 있는 input과 정수 3개를 출력하고 줄바꿔라 정수는 배열intput 123 (각각 배열 의 첫 번째, 두 번째, 세 번째 칸에 저장된 값) 

    int strike_count = 0;       // int 변수 를 담을 수 있는 그릇을 만든다, strike_count 변수 이름, =0 변수에 0을 대입한다(처음 값 만 0)
    int ball_count = 0 ;        // ball_count에 0을 대입한다 (처음에만)
    int out_count = 3 ;         //out_count에 3을 대입한다 (처음에만)
    if( ball[0] == input[0] )       // 만약 ball[0] 과 input[0] 이 비교하여 같으면 실행해라 (첫번째 숫자랑 첫번쨰 숫자)
    {
        strike_count = strike_count + 1;        // strike_count는 처음 시작 값이 0이라서 +1
        out_count = out_count - 1 ;             // out_count는 처음 시작 값이 3이라서 -1 해야 2아웃
    }
    if( ball[0] == input[1] )     //  만약 ball[0] 과 input[1] 이 비교하여 같으면 실행해라 (첫번째 숫자랑 두번째 숫자)
    {
        ball_count = ball_count + 1 ;      // 1ball
        out_count = out_count - 1 ;        // -1 out
    }
    {
    if( ball[0] == input[2] )     // 만약 ball[0] 과 input[2] 이 비교하여 같으면 실행해라 (첫번째 숫자랑 세번째 숫자)
    {
        ball_count = ball_count + 1 ;   //1ball
        out_count = out_count - 1 ;     //-1 out
    }

    if( ball[0] == input[0] && ball[1] == input[1] && ball[2] == input[2] )  
        //첫번째 자리랑 첫번째 자리랑 같으면 참 두번째 자리랑 두번째 자리랑 같으면 참 세번째 자리랑 세번째 자리랑 같으면 참, && 모든 조건이 참 일 때만 전체가 참
    {
	    printf("Home Run~\n") ; //""안에 있는 문자 출력
    }
    else    //if문이 거짓일 때 
    {
        printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count) ;
        //strike_count, ball_count, out_count 값을 출력
    }

    return 0; //종료
}

