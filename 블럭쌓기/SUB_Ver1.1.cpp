#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<windows.h>
#include<math.h>



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
     gotoxy(55,20);
     printf("score : %d",sc);
     gotoxy(55,21);
     printf("frame : %f",fr);    
}

float menu()
{
     float lv;
     system("mode con: cols=60 lines=30");
     system("color 40");    
     printf("\n");
     printf("\n");
     printf("         	     ******                      \n");
     printf("         	    *######*                       \n");
     printf("	            *######*                         \n");
     printf("        	    *######*                       \n");
     printf("        	    ******                    ��  \n"); 
     printf("        	     **                        ��\n");
     printf("        	      **                        ��\n");
     printf("        	        *                       \n");
     printf("                                              ��   \n");
     printf("                      ******                   ��     \n");
     printf("                     *######*                          \n");
     printf("                     *######*                ��      \n");
     printf("                     *######*                 ��   \n");
     printf("                      ******                   ��     \n");
     printf("                *                **             Ʈ     \n");
     printf("               **                  ***            \n");
     printf("             ***                     ***            \n");
     printf("        ********                    ******                \n");
     printf("       *######**                   *######*            \n");
     printf("       *######**                   *######*             \n");
     printf("       *######*                    *######*             \n");
     printf("        ******                      ******               \n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     
     
     printf("  ���̵��� �Է��Ͻÿ�(1 < n < 5) ���İ�� ���̵� : 2\n    (�Ҽ��� �Է°���. ������ �������� �������)");
     scanf("%f",&lv);
     printf("    ���̵��� [%f]�Դϴ�.�����Ϸ��� �ƹ�Ű�� �����ÿ�.",lv); 
     while(1)
     {
             if(getch() != 0)
             {
                        
                        break;
             }
     }
     return lv;
}


int main()
{
    system("����� ���� ���� ���α׷�"); 
    
    float level;
    
    level=menu(); // �޴�â �ҷ����� 
    
    system("cls");
    system("mode con: cols=80 lines=50");
    system("color 40");
    
    char a[40][50]={};
    int i,j;
    int x,y;
    double count=0;
    int c=39;  //�� 
    int l=48; //�� 
    int blockfirst=13;
    int blocklast=38;
    int sw=1;
    float frame=200;
    int cnt=0; //�ι� ���ȴٴ°��� Ȯ���ϱ����� ���� 
    int sco=0;
    int height=0;
    int combo=0;
    
    
    
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
    
    
    for(i=blockfirst;i<blocklast;i++) //�⺻ �� 
    {
                       a[38][i]='@';
                       count++;
                       gotoxy(i,38);
                       printf("%c",a[38][i]);
    } 
    
             
    
    while(1) // ���� �� ������ 
    {
             
            g1:
                
            c=c-1;
            if(c==1)
            {
                    goto g2;
            }   
            if(frame<40)
            {
                        frame=frame-2.7;
            }
            else
            {
                        frame=frame-(level*6);
            }
            
            if(frame <= 0)
            {
                     frame=1;
            } 
            score(frame,sco);
            
            
            gotoxy(55,22);
            printf("Combo : %d",combo);
            gotoxy(55,23);
            printf("Level : %f",level);
            
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
                                a[c-1][l-i]='@';
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
                    
                    
                    if(kbhit())                            //Ű �Է��� ������ ���� ��� ������ 
                    {
                               if(getch() != 0)
                               {
                                          height++;
                                          for(i=1;i<49;i++) // ��ĭ �Ʒ�ĭ �´��� Ȯ�� ���� 
                                          {
                                                           if(a[c-1][i] != a[c][i] && a[c-1][i]=='@')
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
                                                    if(combo >= 1)
                                                    {
                                                             sco=sco+(100*combo);
                                                             gotoxy(55,22);
                                                             printf("Combo : %d",combo);
                                                    }
                                                         sco=sco+500+(level*200);   
                                                         combo++;                       
                                          }
                                          else if(cnt<=3)
                                          {
                                               printf("            OOO     OO    OO    OOO                       \n");
                                               printf("           O       O  O  O  O   O  O                        \n");
                                               printf("           O OOO   O  O  O  O   O  O                        \n");
                                               printf("           O  O    O  O  O  O   O  O                       \n");
                                               printf("            OOO     OO    OO    OOO                         \n");
                                               sco=sco+300+(level*200);
                                               combo=0;
                                               gotoxy(55,22);
                                               printf("Combo : %d",combo);
                                          }
                                          else
                                          {
                                              printf("            OOO       O     OOO                    \n");                       
                                              printf("            O  O     O O    O  O                    \n");
                                              printf("            OOO     OOOOO   O  O                     \n");
                                              printf("            O  O   O     O  O  O                   \n");
                                              printf("            OOO    O     O  OOO                       \n");
                                              sco=sco+100+(level*200);
                                              combo=0;
                                              gotoxy(55,22);
                                              printf("Combo : %d",combo);
                                              
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
