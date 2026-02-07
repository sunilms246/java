#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

typedef struct {
float item[20];
int top;

}STACK;

void PUSH(STACK *s, float data)
{
    s->item[++s->top] = data;
}

float POP(STACK *s)
{
    return s->item[s->top--];

}

float compute(float n1, char symb, float n2)
{
    switch(symb)
    {
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        case '*': return n1 * n2;
        case '/': return n1 / n2;
        case '&':
        case '^': return pow(n1, n2);
    }
}

int main()
{
    STACK s;
    char postfix[20], symb, ch;
    float n1, n2, res, data;
    s.top = -1;

    printf("\nEnter valid postfix expression:");
    scanf("%s", postfix);

    for(int i=0; postfix[i]!='\0'; i++)
    {
        symb = postfix[i];
        if(isdigit(symb))
            PUSH(&s, symb - '0');
        else if(isalpha(symb))
        {
            printf("%c = ", symb);
            scanf("%f", &data);
            PUSH(&s, data);
        }
        else {
            n2 = POP(&s);
            n1 = POP(&s);
            res = compute(n1, symb, n2);
            PUSH(&s, res);
        }
    }

    printf("resultant is %f", POP(&s));
    return 0;
}
