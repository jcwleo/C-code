#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<windows.h>



void gotoxy(int x,int y)
{
     COORD pos={x, y};
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void score(double frame, int sco)
{
     int sc;   
     double fr;
     sc=sco;
     fr=frame;
     gotoxy(60,20);
     printf("score : %d",sc);
     gotoxy(60,21);
     printf("frame : %f",fr);
     gotoxy(60,22);
     
}

void menu()
{
     system("mode con: cols=60 lines=15");
     system("color 4F");    
     printf("\n");
     printf("\n");
     printf("                 *************************\n");
     printf("                 *     Stack Up Block    *\n");
     printf("                 *************************\n");
     printf("\n");
     printf("\n");
     printf("시작하려면 아무키나 누르시오."); 
     while(1)
     {
             if(getch() != 0)
             {
                        break;
             }
     }
     
}


int main()
{
    system("title Stack Up Block"); 
    menu(); // 메뉴창 불러오기 
    system("cls");
    system("mode con: cols=80 lines=50");
    system("color 0A");
    char a[40][50]={};
    int i,j;
    int x,y;
    double count=0;
    int c=39;  //벽 
    int l=48; //벽 
    int blockfirst=13;
    int blocklast=38;
    int sw=1;
    double frame=200;
    int cnt=0; //두번 돌렸다는것을 확인하기위한 변수 
    int sco=0;
    int height=0;
    
    
    for(i=0;i<40;i++)
    {
                     a[i][0]='*';
                     a[i][49]='*';
    }
    for(j=0;j<50;j++)
    {
                     a[0][j]='*';
                     a[39][j]='*';
    
    }
    
    
    
    for(i=0; i<40 ; i++)
    {
             for(j=0;j<50;j++)
             {
                               printf("%c",a[i][j]);
             }
             printf("\n");
    }
    
    
    for(i=blockfirst;i<blocklast;i++) //기본 블럭 
    {
                       a[38][i]='#';
                       count++;
                       gotoxy(i,38);
                       printf("%c",a[38][i]);
    } 
    
             
    
    while(1) // 실제 블럭 움직임 
    {
             
            g1:
                
            c=c-1;
            if(c==1)
            {
                    goto g2;
            }   
            frame=frame/1.15;  
            score(frame,sco);
            while(1)
            {
                    gotoxy(1,c-1);
                    for(i=1;i<49;i++)
                    {
                                 a[c-1][i]=' ';
                                 printf(" ");
                    }
                    
                    for(i=0;i<count;i++)
                    {
                                a[c-1][l-i]='#';
                    }
                    
                    gotoxy(1,c-1);
                    for(i=1;i<49;i++)
                    {
                                        printf("%c",a[c-1][i]);
                    }
                    
                    
                    
                    if(l-count==0)
                    {
                          sw=sw*(-1);
                    }
                    else if(l==48)
                    {
                          sw=sw*(-1);
                    }
                    l=l+sw;
                    
                    
                    if(kbhit())                            //키 입력이 있을때 뺴고 모두 움직임 
                    {
                               if(getch() != 0)
                               {
                                          height++;
                                          for(i=1;i<49;i++) // 윗칸 아랫칸 맞는지 확인 조건 
                                          {
                                                           if(a[c-1][i] != a[c][i] && a[c-1][i]=='#')
                                                           {
                                                                        cnt++;
                                                                        a[c-1][i]=' ';      
                                                           }                                                           
                                          }
                                         
                                          gotoxy(1,c-1);
                                          for(i=1;i<49;i++)
                                          {
                                                           printf("%c",a[c-1][i]);
                                          }
                                          
                                          count=count-cnt;
                                          l=l-cnt;
                                          
                                          
                                          gotoxy(0,40);
                                          
                                          if(cnt==0)
                                          {
                                                    printf("     OOO   OOOO  OOO   OOOO  OOOO   OOO  OOOOO\n");
                                                    printf("     O  O  O     O  O  O     O     O       O \n");
                                                    printf("     OOO   OOOO  OOO   OOO   OOO   O       O \n");
                                                    printf("     O     O     O O   O     O     O       O \n");
                                                    printf("     O     OOOO  O  O  O     OOOO   OOO    O \n"); 
                                                    sco=sco+500;                          
                                          }
                                          else if(cnt<=3)
                                          {
                                               printf("            OOO     OO    OO    OOO                       \n");
                                               printf("           O       O  O  O  O   O  O                        \n");
                                               printf("           O OOO   O  O  O  O   O  O                        \n");
                                               printf("           O  O    O  O  O  O   O  O                       \n");
                                               printf("            OOO     OO    OO    OOO                         \n");
                                               sco=sco+300;
                                          }
                                          else
                                          {
                                              printf("                                                \n");                       
                                              printf("                                                \n");
                                              printf("                                                \n");
                                              printf("                                                \n");
                                              printf("                                                \n");
                                              sco=sco+100;
                                              
                                          }
                                          if(count <= 0)
                                          {
                                                     goto g2;
                                          }
                                          cnt=0;
                                          goto g1; 
                               }
                    }
                    
                    Sleep(frame);
            }
    } 
    
    g2:
    sco=sco+((height-1)*100);
    score(frame,sco);
    gotoxy(0,40);
    printf("     OOOO      O        O    O    OOOO   OOO   O     O  OOOO  OOO\n");
    printf("    O         O O      O O  O O   O     O   O  O     O  O     O  O     \n");
    printf("    O  OOO   OOOOO    O   OO   O  OOOO  O   O   O   O   OOOO  OOO \n");
    printf("    O   O   O     O   O   O    O  O     O   O    O O    O     O  O      \n");
    printf("     OOOO  O       O  O   O    O  OOOO   OOO      O     OOOO  O   O       \n"); 
    gotoxy(0,46);
    system("pause");
}
