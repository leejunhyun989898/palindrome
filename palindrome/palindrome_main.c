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
        fprintf(stderr, "���� ���� ��\n");
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
        fprintf(stderr, "���� ��\n");
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
            char c = tolower(string[i]); // ��� �ҹ��ڷ� ��ȯ�Ͽ� ���ÿ� push
            push(&s, c);
        }
        i++;
    }

    i = 0;
    while (string[i] != NULL)
    {
        if (isalpha(string[i]))
        {
            char c = tolower(string[i]); // ��� �ҹ��ڷ� ��ȯ�Ͽ� ���ð� ��
            if (pop(&s) != c)
            {
                return 0; // ���ð� ���� ����� �ٸ��� ȭ���� �ƴ�
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
        printf("���ڿ��� �Է��ϼ���: ");
        gets(string);
        if (palindrome(string) == 1)
        {
            printf("ȭ���Դϴ�\n");
        }
        else {
            printf("ȭ���� �ƴմϴ�\n");
        }
        printf("\n��� �Ͻ÷��� �ƹ�Ű��, �׸��ν÷��� no�� �Է����ּ���: ");
        gets(check);   
        printf("\n");
        if (strcmp(check, "no") == 0) // �Է°��� "no"�� ��
        {
            c = 0;
            printf("�����մϴ�.\n");
        }
    }
    
    return 0;
}