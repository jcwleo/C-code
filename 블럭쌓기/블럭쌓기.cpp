#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<math.h>
#include<dos.h>
#include<windows.h>

int main()
{
    /*
    printf("                 *************************\n");
    printf("                 *     Stack Up Block    *\n");
    printf("                 *************************\n");
    printf("\n");
    printf("시작하려면 아무키나 누르시오."); 
    while(1)
    {
            if(getch() != 0)
            {
                     break;
            }
    }
    */
    
    
    char a[40][50]={};
    int i,j;
    for(i=0; i<40 ; i++)
    {
             for(j=0;j<50;j++)
             {
                               a[i][j]='*';
             }
    }
    
    for(i=0; i<40 ; i++)
    {
             for(j=0;j<50;j++)
             {
                               printf("%c",a[i][j]);
             }
             printf("\n");
    }
    
    
    
    
    
    
    system("pause");
}
