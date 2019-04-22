#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[10000][50];

void Scan(char a[])
{
    int i;
    while((a[i]=getchar())!='\n')
    {
        printf("%c",a[i]);
        i++;
    }
}

int Word(char a[])
{
    int i,j,t=0,m=0;
    for(i=0,j=0;a[i]!='\n';i++)
    {
        if((a[i]>=97 && a[i]<=120) || (a[i]>=65 && a[i]<=90))
        {

            s[j][t]=a[i];
            m=j;
            t++;
        }
        else
        {
            if(m==j)
            {
               j++;
               t=0;
            }
        }
    }
    return j;
}

void JiluNum(int j,int num[])
{
    int i,n;
    for(i=0;i<j;i++)
    {
        for(n=i+1;n<=j;n++)
        {
            if(strcmp(s[i],s[n])==0)
            {
                s[n][0]='0';
                num[i]++;
            }
        }
    }
}
void paixu(int j,int num[])
{
    int i,m,n;
    char st[1][50];
    for(i=0;i<j;i++)
    {
        for(n=i;n<j;n++)
        {
            if(num[i]<num[n])
            {
                m=num[i];
                num[i]=num[n];
                num[n]=m;

                strcpy(st[0],s[i]);
                strcpy(s[i],s[n]);
                strcpy(s[n],st[0]);
            }
        }
    }
}

void Print(int j,int num[])
{
    int i;
    for(i=0;i<j;i++)
    {
        if(s[i][0]!='0')
        printf("%s %d\n",s[i],num[i]+1);
    }
}

int main()
{
    char a[10000];
    int num[10000];
    int i=0,t=0,j,n,m=0;
    Scan(a); //输入
    printf("\n");
    j=Word(a); //把输入的字符拼接成单词
    JiluNum(j,num); //记录单词数量
    paixu(j,num); //对单词按数量排序
    Print(j,num); //输出排序后的
}
