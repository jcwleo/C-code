#include<stdio.h>
#include<stdlib.h>
#include<complex>
#include<conio.h>


void buffclr() //���۸� Ŭ���� �����ִ� �Լ� 
{
     while(getchar()!='\n');
}


int main()
{
    s1:
    
    int num,i,j,k,s;
    int cnt[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  // ={} �� ���ָ� �⺻������ 0�� �ٵ� 
    
    do
    {
                 printf("������ �Է��Ͻÿ�. : "); 
                 scanf("%d",&num);
    }while(num<3 || num >100);   //���� ���� �Է����ִ� ���� �ݺ��� 
    
    buffclr(); //���� Ŭ���� 

    char arr[num][2]; //�Է¹��� �� ��ŭ �迭 ���� 
    char pal[num][2]; //���� ��� ���� �迭 
    
    printf("\n�ΰ��� ���� �Է��Ͻÿ�\n"); 
    
    for(i=0;i<num;i++) //���� �Է� 
    {
                      printf("=> %d. : ",i+1);
                      scanf("%c %c",&arr[i][0],&arr[i][1]);   
                      buffclr(); //���� Ŭ���� 
    }
    //for(i=0;i<num;i++){printf("%c %c\n",arr[i][0],arr[i][1]);}
    
    for(i=0;i<num;i++) //���� �� ���� ¦������ Ȯ�� (¦���� �����ϰ� Ȧ���� ¦�� ��� �Ұ�����) 
    {
                      for(j=0;j<2;j++)
                      {
                                      cnt[arr[i][j]-97]++;                                     
                      }
    }
    for(i=0;i<26;i++)
    {
                     if(cnt[i]%2==1)
                     {
                                                printf("\n���� ����µ� ����"); 
                                                goto f2; //�� ���������� �̵� 
                     }
    }// ���� �� �� Ȧ���� ��� ����
     
    pal[0][0]=arr[0][0];      //�ʱ� �˻� ���� 
    pal[0][1]=arr[0][1];
    
    
    for(i=0;i<num-1;i++)
    {
                        for(j=1;j<num;j++)
                        {
                                          for(k=0;k<2;k++)
                                          {
                                                          if(pal[i][1]==arr[j][k])
                                                          {
                                                                                  if(k==0)   //������ ���������� �ݴ�� ������� ���� 
                                                                                  {
                                                                                          pal[i+1][0]=arr[j][0];
                                                                                          pal[i+1][1]=arr[j][1];
                                                                                          arr[j][0]=0;
                                                                                          arr[j][1]=0;
                                                                                          j=num;        //���� �˻��� ���� �ѱ�� 
                                                                                  }
                                                                                  else
                                                                                  {
                                                                                      pal[i+1][0]=arr[j][1];
                                                                                      pal[i+1][1]=arr[j][0];   
                                                                                      arr[j][0]=0;
                                                                                      arr[j][1]=0;
                                                                                      j=num;             //���� �˻��� ���� �ѱ�� 
                                                                                  }
                                                                                  if(pal[num-1][1]==pal[0][0])    //������ �� ��������� �ݺ��� ��ü�� ���������� ���� ���� 
                                                                                  {
                                                                                                              goto f1;
                                                                                  }
                                                                                  break;
                                                          }
                                          }
                        }                
    }
    
    f1:
    for(i=0;i<num;i++)    //��� ��� 
    {
                      if(i==num-1)
                      {
                                  printf("[%c, %c]\n",pal[i][0],pal[i][1]);
                      }
                      else
                      {
                          printf("[%c, %c]-",pal[i][0],pal[i][1]);
                      }
    }
    f2:
    printf("�ѹ���?");
    scanf("%c", &s);
    if(s=='y')
    {
              goto s1;
    }    
    system("pause");
}
