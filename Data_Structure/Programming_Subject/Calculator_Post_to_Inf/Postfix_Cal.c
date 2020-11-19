#include<string.h> 
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

char stack[100] = { 0}; // 문자 저장배열
double resultfix[100] = { 0 }; // 결과 연산 및 결과값 계산 배열
int p_top = -1; // postfix 배열 순서 번호
int s_top = -1; // stack 배열 순서 번호
int r_top = -1; // resultfix 배열 순서 번호
int temp = 0; // 결과값 저장 변수

int Priority(char c) { //연산 우선순위 지정
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '&':
        return 2;
    case '^':
        return 3;
    case '(':
        return 0;
    }
}

void init(char infix[]) {
   s_top= -1;
}

char push(char infix[]) {
    stack[++s_top] = *infix;
    return *stack;
}

int Check(char infix[])//괄호검사
{
    char ch, open_ch;
    char a[100] = { 0 };
    int a_top = -1;

    for (int i = 0; i < strlen(infix); i++) {
        a[i] = infix[i];
        a_top++;
    }

    
    int i, n = strlen(infix);
  
    for (i = 0; i < n; i++) {
        ch = a[i];

        switch (ch) {
        case'(': case '[': case '{':
            a[++a_top] = ch;
            a_top++;
            break;
        case')': case']': case'}':
            if (a_top== -1) {
                printf(" 괄호가 올바르지 않음.");
                exit(1);
            }
            else {
                open_ch = a[a_top--];
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}')) {
                    printf(" 괄호가 올바르지 않음.");
                    exit(1);
                }
                break;
            }
        
        }
    }
    if (a_top != -1) {
        printf(" 괄호가 올바르지 않음.");
        exit(1);
    }
    return 1;
}

void Infix_to_Postfix(char infix[], char postfix[], char stack[]) { // infix를 postfix로 바꾸는 함수
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] >= 48 && infix[i] <= 57)         // infix[i]가 숫자일경우
            postfix[++p_top] = infix[i];
        else if (infix[i] == '(')                   // '('가 들어올경우
            stack[++s_top] = infix[i];
        else if (infix[i] == ')') {                 // ')'가 들어올경우
            for (; ; ) {
                if (stack[s_top] == '(') {
                    stack[s_top--] = '\0';
                    break;
                }
                postfix[++p_top] = stack[s_top];
                stack[s_top--] = '\0';
            }
        }
        else if (Priority(stack[s_top]) < Priority(infix[i])) // 앞에있는 연산자보다 뒤에오는 연산자의 우선순위가 높을때
            stack[++s_top] = infix[i];
        else if (Priority(stack[s_top]) >= Priority(infix[i])) { // 앞에있는 연산자보다 뒤에오는 연산자의 우선순위가 낮을때
            postfix[++p_top] = stack[s_top];
            stack[s_top--] = 0;
            push(&infix[i]);
        }
    }
    while (s_top != -1) // 마지막 남은 stack의 연산자를 pop해주는 반복문
        postfix[++p_top] = stack[s_top--];
}

int Calculate(char postfix[]) { // 계산
    int a,b;
    
    for (int i = 0; postfix[i] != '\0'; i++) { // postfix의 값을 불러와 연산
        if (postfix[i] >= 48 && postfix[i] <= 57) { // postfix[i]가 숫자일경우
            postfix[i] = (int)postfix[i] - 48;
            resultfix[++r_top] = (double)postfix[i];
        }
        else { // postfix[i]가 연산자일 경우
            if (postfix[i] == '+')
                temp = resultfix[r_top - 1] + resultfix[r_top];
            else if (postfix[i] == '-')
                temp = resultfix[r_top - 1] - resultfix[r_top];
            else if (postfix[i] == '*')
                temp = resultfix[r_top - 1] * resultfix[r_top];
            else if (postfix[i] == '/')
                temp = resultfix[r_top - 1] / resultfix[r_top];
            else if (postfix[i] == '%') {
                a = resultfix[r_top - 1];
                b = resultfix[r_top];
                temp = a % b;
            }
            else if (postfix[i] == '^') {
                temp = pow(resultfix[r_top - 1], resultfix[r_top]);
            }
            resultfix[r_top--] = 0;
            resultfix[r_top] = temp; //결과값을 resultfix배열에 저장
        }
    }
    return resultfix[0]; // 결과값 반환
}
int main() { // 메인함수
    char infix[100] = { 0, };
    char postfix[100] = { 0, };
    printf("계산기 입력 : ");
    scanf("%s", infix);

    printf("\nPOSTFIX : ");
    Infix_to_Postfix(infix, postfix, stack);
    printf("%s\n", postfix);

    printf("\nRESULT : %d", Calculate(postfix));
}
