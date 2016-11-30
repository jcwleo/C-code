
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<windows.h>
#include<math.h>




float lv;
int block_cnt;

void buffclr() //버퍼를 클리어 시켜주는 함수 
{
     while(getchar()!='\n');
}

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
     
     int i=0;
     bool a=true;
     
     system("mode con: cols=60 lines=30");
     system("color 40");    
     printf("\n");
     printf("\n");
     printf("         	     ******                      \n");
     printf("         	    *######*                       \n");
     printf("	            *######*                         \n");
     printf("        	    *######*                       \n");
     printf("        	    ******                    사  \n"); 
     printf("        	     **                        륜\n");
     printf("        	      **                        안\n");
     printf("        	        *                       \n");
     printf("                                              개   \n");
     printf("                      ******                   안     \n");
     printf("                     *######*                          \n");
     printf("                     *######*                프      \n");
     printf("                     *######*                 로   \n");
     printf("                      ******                   젝     \n");
     printf("                                 **             트     \n");
     printf("                 *                 ***            \n");
     printf("              ***                    ***            \n");
     printf("      **********                     *****                \n");
     printf("     *######***                    *######*            \n");
     printf("     *######**                     *######*             \n");
     printf("     *######*                      *######*             \n");
     printf("      ******                        ******               \n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     while(i<30)
     {
             if(a==true)
             {
                        system("color 04");
                        a=false;
                        i++;
             }
             else
             {
                 system("color 40");
                 a=true;
                 i++;
             }
             Sleep(50);
     }
     
     printf("  난이도를 입력하시오(1 < n < 5) 공식경기 난이도 : 2\n    (소수점 입력가능. 높으면 높을수록 어려워짐)");
     scanf("%f",&lv);
     buffclr();
     printf("  블럭 갯수를 입력하시오.");
     scanf("%d", &block_cnt);  
     printf("    난이도는 [%f]입니다. 블럭 갯수는 [%d]입니다. 시작하려면 아무키나 누르시오.",lv,block_cnt); 
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
    system("사륜안 개안 수련 프로그램"); 
    bool b=true;
    
    int sec=0;
    
    menu(); // 메뉴창 불러오기 
    
    system("cls");
    system("mode con: cols=80 lines=50");
    system("color 40");
    
    char a[40][50]={};
    int i,j;
    int x,y;
    double count=0;
    int c=39;  //벽 
    int l=48; //벽 
    int blockfirst =25;
    int blocklast =26;
    
    int sw=1;
    float frame=200;
    int cnt=0; //두번 돌렸다는것을 확인하기위한 변수 
    int sco=0;
    int height=0;
    int combo=0;
    
    
    
    for(i=0;i<40;i++)                               //기본 배경 틀 입력 
    {
                     a[i][0]='*';
                     a[i][49]='*';
    }
    for(j=0;j<50;j++)
    {
                     a[0][j]='*';
                     a[39][j]='*';
    
    }
    
    
    
    for(i=0; i<40 ; i++)                           //기본 배경 틀 출력 
    {
             for(j=0;j<50;j++)
             {
                               printf("%c",a[i][j]);
             }
             printf("\n");
    }
    
    
    if(block_cnt % 2 ==0)                            //블럭 갯수 입력 
    {
                 blocklast=blocklast+(block_cnt/2);
                 blockfirst=blockfirst-(block_cnt/2)+1;
    } 
    else if(block_cnt != 1)
    {
                 blockfirst=blockfirst-(block_cnt/2)+1;
                 blocklast=blocklast+(block_cnt/2)-1;
    }
    
    
    for(i=blockfirst;i<blocklast;i++) //기본 블럭 
    {
                       a[38][i]='@';
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
            if(frame<40)
            {
                        frame=frame-2.7;
            }
            else
            {
                        frame=frame-(lv*6);
            }
            
            if(frame <= 0)
            {
                     frame=1;
            } 
            score(frame,sco);
            
            
            gotoxy(55,22);
            printf("Combo : %d",combo);
            gotoxy(55,23);
            printf("Level : %f",lv);
            
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
                    
                    
                    if(kbhit())                            //키 입력이 있을때 뺴고 모두 움직임 
                    {
                               if(getch() != 0)
                               {
                                          height++;
                                          for(i=1;i<49;i++) // 윗칸 아랫칸 맞는지 확인 조건 
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
                                          
                                          
                                          gotoxy(1,20);
                                          
                                          if(cnt==0)
                                          {
                                                    printf("     OOO   OOOO  OOO   OOOO  OOOO   OOO  OOOOO\n");
                                                    gotoxy(1,21);
                                                    printf("     O  O  O     O  O  O     O     O       O \n");
                                                    gotoxy(1,22);
                                                    printf("     OOO   OOOO  OOO   OOO   OOO   O       O \n");
                                                    gotoxy(1,23);
                                                    printf("     O     O     O O   O     O     O       O \n");
                                                    gotoxy(1,24);
                                                    printf("     O     OOOO  O  O  O     OOOO   OOO    O \n"); 
                                                    if(combo >= 1)
                                                    {
                                                             sco=sco+(100*combo);
                                                             gotoxy(55,22);
                                                             printf("Combo : %d",combo);
                                                    }
                                                         sco=sco+500+(lv*200);   
                                                         combo++;                       
                                          }
                                          else if(cnt<=3)
                                          {
                                               printf("            OOO     OO    OO    OOO            \n");
                                               gotoxy(1,21);
                                               printf("           O       O  O  O  O   O  O           \n");
                                               gotoxy(1,22);
                                               printf("           O OOO   O  O  O  O   O  O           \n");
                                               gotoxy(1,23);
                                               printf("           O  O    O  O  O  O   O  O           \n");
                                               gotoxy(1,24);
                                               printf("            OOO     OO    OO    OOO             ");
                                               sco=sco+300+(lv*200);
                                               combo=0;
                                               gotoxy(55,22);
                                               printf("Combo : %d",combo);
                                          }
                                          else
                                          {
                                              printf("            OOO       O     OOO            \n");                       
                                              gotoxy(1,21);
                                              printf("            O  O     O O    O  O            \n");
                                              gotoxy(1,22);
                                              printf("            OOO     OOOOO   O  O            \n");
                                              gotoxy(1,23);
                                              printf("            O  O   O     O  O  O             \n");
                                              gotoxy(1,24);
                                              printf("            OOO    O     O  OOO             \n");
                                              sco=sco+100+(lv*200);
                                              combo=0;
                                              gotoxy(55,22);
                                              printf("Combo : %d",combo);
                                              while(1)
                                              {
                                                      if(b==true)
                                                      {
                                                                 system("color 07");
                                                                 b=false;
                                                      }
                                                      else
                                                      {
                                                                 system("color 70");
                                                                 b=true;                 
                                                      }
                                                      sec++;
                                                      if(sec==20)
                                                      {
                                                                 sec=0;
                                                                 break;
                                                      } 
                                                      Sleep(50);
                                              }
                                              
                                          }
                                          if(count <= 0)
                                          {
                                                     goto g2;
                                          }
                                          cnt=0;
                                          goto g1; 
                               }
                    }
                    else
                    {
                        if(b==true)
                        {
                                   system("color 04");
                                   b=false;
                        
                        }
                        else
                        {
                                   system("color 40");
                                   b=true;
                 
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
