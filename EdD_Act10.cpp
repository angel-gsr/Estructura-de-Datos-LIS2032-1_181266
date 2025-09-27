#include <stdio.h>
#include <string.h>

#define MAX 1000

void check_brackets(const char *s) 
{
    char stack[MAX];
    int index[MAX]; 
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) 
	{
        char c = s[i];

        if (c != '(' && c != ')' && c != '[' && c != ']' && c != '{' && c != '}')
            continue;

        if (c == '(' || c == '[' || c == '{') 
		{
            stack[++top] = c;
            index[top] = i;
        } 
		else 
		{
            if (top == -1) 
			{
                printf("ERROR %d\n", i);
                return;
            }
            char open = stack[top--];
            if ((open == '(' && c != ')') ||
                (open == '[' && c != ']') ||
                (open == '{' && c != '}')) 
				{
                printf("ERROR %d\n", i);
                return;
            }
        }
    }

    if (top != -1) 
	{
        printf("ERROR %d\n", index[0]);
    } else 
	{
        printf("OK\n");
    }
}

int main() 
{
    // 3 pruebas
    check_brackets("([]{})");         //OK
    check_brackets("([)]");           //ERROR 2
    check_brackets("abc(def[ghi]{j}k"); //ERROR 3

    return 0;
}


