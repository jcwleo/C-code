#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<complex>

int main()
{
    int a,b,cnt;
    int i,j;
    
 
    cnt=0;
    
    printf("1부터 300사이 정수 두개 입력 : ");
    scanf("%d %d", &a,&b);

    for(i=1;i<b;i++)
    {
                    for(j=1;j<=i;j++)
                    {
                                    if(i % j==0)
                                    {
                                                          cnt++;
                                    }
                    }
                    if(cnt==2 && i>a)
                    {
                              printf("%d\n",i);
                    }
                    cnt=0;
    }
    
    system("pause");
}
