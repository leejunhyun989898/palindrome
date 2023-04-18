#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef char element;

typedef struct StackType{
    element stack[MAX];
    int top;
} Stacktype;

void init_stack(Stacktype* s) {
    s->top = -1;
}

int is_empty(Stacktype* s) {
    return (s->top == -1);
}

int is_full(Stacktype* s) {
    return (s->top == (MAX - 1));
}

void push(Stacktype* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 가득 참\n");
        return;
    }
    else {
        s->stack[++(s->top)] = item;
    }
}

element pop(Stacktype* s) {
    if (is_empty(s)) {
        return 0;
    }
    else {
        return s->stack[(s->top)--];
    }
}

element peek(Stacktype* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 빔\n");
        return 0;
    }
    else {
        return s->stack[(s->top)];
    }
}

int palindrome(char string[])
{
    Stacktype s;
    int i = 0;
    init_stack(&s);

    while (string[i] != NULL)
    {
        if (isalpha(string[i]))
        {
            char c = tolower(string[i]); // 모두 소문자로 변환하여 스택에 push
            push(&s, c);
        }
        i++;
    }

    i = 0;
    while (string[i] != NULL)
    {
        if (isalpha(string[i]))
        {
            char c = tolower(string[i]); // 모두 소문자로 변환하여 스택과 비교
            if (pop(&s) != c)
            {
                return 0; // 스택과 비교한 결과가 다르면 화문이 아님
            }
        }
        i++;
    }
    if (is_empty)return 1;
    else return 0;

}
int main(void)
{
    char string[MAX] = { NULL };
    char check[MAX] = { NULL };
    int c = 1;
    while (c)
    {
        printf("문자열을 입력하세요: ");
        gets(string);
        if (palindrome(string) == 1)
        {
            printf("화문입니다\n");
        }
        else {
            printf("화문이 아닙니다\n");
        }
        printf("\n계속 하시려면 아무키나, 그만두시려면 no를 입력해주세요: ");
        gets(check);   
        printf("\n");
        if (strcmp(check, "no") == 0) // 입력값이 "no"일 때
        {
            c = 0;
            printf("종료합니다.\n");
        }
    }
    
    return 0;
}