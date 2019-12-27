/*
    Author: Niharika Pentapati
    SRN: PES1201700215
    Q1: Suffix Tree
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Structure of every node
struct trienode
{
    struct trienode* child[256];
    int* positions;
    int count;
};

struct trienode *getnode();
void insert(struct trienode *, char *, int, int);
int search(struct trienode *,char *);
int indexof(char);
int isalphabet(char);

int main()
{
    struct trienode *root;
    char text[4002];
    char pattern[1001];
    int test;
    int ch,k;
    scanf("%[^\n]s",text);
    root=getnode();
    int len = strlen(text);
    for(int i = len - 1; i>=0; i--)
    {
        // Inserts all the suffixes
        insert(root,text,i,len);
    }
    scanf("%d",&test); 
    while(test--)
    {
        getchar();
        scanf("%[^\n]s", pattern);
        k = search(root,pattern);
        if(k == -1)
            printf("%d\n",k);
        fflush(stdin);
    }
}
  
struct trienode *getnode()
{
    int i;
    struct trienode *temp;
    temp=(struct trienode*)malloc(sizeof(struct trienode));
    for(i=0;i<256;i++)
    {
        temp->child[i]=NULL;
        temp->positions=(int *)malloc(sizeof(int) * 1001);
        temp->count = 0;
    }
    return temp;
}

void insert(struct trienode *root, char *text, int start, int len)
{
    struct trienode *curr;
    int i,index;

    curr=root;
    for(i=start;i<len;i++)
    {
        if(isalphabet(text[i]))
        {
            // Case Insensitive
            text[i] = tolower(text[i]);
            index = indexof(text[i]);
        }
        else
        {
            index = indexof(text[i]);
        }

    if(curr->child[index]==NULL)
        curr->child[index]=getnode();
    curr=curr->child[index];
    curr->positions[curr->count]=start;
    curr->count = curr->count+1;
    }
}

int search(struct trienode * root,char *key)
{
    int i,index;
    int flag = 0;
    struct trienode *curr;
    curr=root;
    for(i=0;key[i]!='\0';i++)
    {
        if(isalphabet(key[i]))
        {
            // Case Insensitive
            key[i] = tolower(key[i]);
            index = indexof(key[i]);
        }
        else
        {
            index = indexof(key[i]);
        }

        if(curr->child[index]==NULL)
        {
            flag = 1;
            return -1;
        }
        curr=curr->child[index];
    }
    if(flag == 0 && curr->count != 0)
    {
        for(int c = curr->count-1; c >= 0; c--)
        {
            printf("%d ",curr->positions[c]);
        }
        printf("\n");
    }
    return 1;
}

// Returns the ascii value of the character
int indexof(char x)
{
    int asc = x;
    return(asc);
}

// Checks if the characer is an alphabet or not.
int isalphabet(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        return 1;
    else 
        return 0;
}


