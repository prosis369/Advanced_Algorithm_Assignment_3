/*
    Author: Niharika Pentapati
    SRN: PES1201700215
    Q2: KMP Algorithm
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void kmp(char* pattern, int p_len, char* text, int t_len)
{
    int pi[p_len+1];
    memset(pi,0,(p_len+1)*sizeof(pi[0]));
    for(int i = 0; i<=p_len; i++)
    {
        pi[i] = 0;
    }
    pi[1] = 0;
    int k = 0;
    for(int q=2; q<=p_len; q++)
    {
        while(k>0 && pattern[k] != pattern[q-1])
        {
            k = pi[k];
        }
        if(pattern[k] == pattern[q-1])
        {
            k = k+1;
        }
        pi[q] = k;
    }
   
    int q = 0;
    int flag = 0;
    int a = -1;
    for(int i = 1; i<=t_len; i++)
    {
        while(q>0 && pattern[q] != text[i-1])
        {
            q = pi[q];
        }
        if(pattern[q] == text[i-1])
        {
            q = q+1;
        }
        if(q == p_len)
        {
            flag = 1;
            printf("%d ", i-p_len);
            q = pi[q];
        }
    }
    if(flag == 0)
    {
        printf("%d\n", a);
    }
    else
    {
        printf("\n");
    }
}

int main()
{
    char text[4002];
    char pattern[1001];
    long long int t;
    scanf("%[^\n]s", text);
    int i = 0;
    scanf("%lld",&t);
    int t_len = strlen(text);
    while(t--)
    {
        getchar();
        scanf("%[^\n]s", pattern);
        int j = 0;
        int p_len = strlen(pattern);
        kmp(pattern, p_len, text, t_len);
        fflush(stdin);
    }
    
    return 0;
}



