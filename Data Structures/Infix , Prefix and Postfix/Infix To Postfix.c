#include <stdio.h>
#include <string.h>

int top = -1;
int pref(char symbol)
{
    if(symbol=='^')
    {
        return 3;
    }
    else if(symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if(symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

char pop(int size , char stack[size])
{
    return(stack[top--]);
}

int isOperand(char ch)
{
    
    return((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));

}

char* push(int size ,char stack[size] , char elem)
{
    if(top == size-1)
    {
        return 0;
    }
    else
    {
        stack[++top] = elem;
    }
    return stack;
}

void infixToPostfix(char* exp)
{
    printf("\nPostfix Expression :: ");
    int len = (strlen(exp));
    char stack[len];
    for (int i = 0; i < sizeof(stack); ++i)
    {
        if(isdigit(exp[i]))
        {
            printf("%c" , exp[i]);
        }
        else if (exp[i] == ')')
        {
            char ans;
            while(ans!= '(')
            {
               ans = pop(len , stack);
               if(ans != '(')
               {
                   printf("%c" , ans);
               }
            }
            
        }
        else if( exp[i] == '(')
        {
            push(len , stack , exp[i]);
        }
        else
        {
            int pres = pref(exp[i]);
            char ans;

            while(top!=-1 && (pres<=pref(stack[top])))
            {
                ans = pop(len , stack);
                printf("%c" , ans);
            }
            push(len , stack , exp[i]);
        }
    }
    
      char ans;
        while (top!=-1)
        {
        ans = pop(len,stack);
        if(ans != '(' && ans != ')')
            {printf("%c" , ans);
        }
        }
}
int main(int argc, char const *argv[])
{
    char exp[50];
    printf("Enter Infix Expression : ");
    gets(exp);
    infixToPostfix(exp);
}

