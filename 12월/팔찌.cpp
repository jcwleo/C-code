#include<stdio.h>
#include<stdlib.h>
#include<complex>
#include<conio.h>


void buffclr() //버퍼를 클리어 시켜주는 함수 
{
     while(getchar()!='\n');
}


int main()
{
    s1:
    
    int num,i,j,k,s;
    int cnt[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  // ={} 를 해주면 기본적으로 0이 다들어감 
    
    do
    {
                 printf("개수를 입력하시오. : "); 
                 scanf("%d",&num);
    }while(num<3 || num >100);   //구슬 갯수 입력해주는 조건 반복문 
    
    buffclr(); //버퍼 클리어 

    char arr[num][2]; //입력받은 수 만큼 배열 지정 
    char pal[num][2]; //최종 팔찌값 넣을 배열 
    
    printf("\n두개의 색을 입력하시오\n"); 
    
    for(i=0;i<num;i++) //구슬 입력 
    {
                      printf("=> %d. : ",i+1);
                      scanf("%c %c",&arr[i][0],&arr[i][1]);   
                      buffclr(); //버퍼 클리어 
    }
    //for(i=0;i<num;i++){printf("%c %c\n",arr[i][0],arr[i][1]);}
    
    for(i=0;i<num;i++) //구슬 색 수가 짝수인지 확인 (짝수면 가능하고 홀수면 짝이 없어서 불가능함) 
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
                                                printf("\n팔찌 만드는데 실패"); 
                                                goto f2; //맨 마지막으로 이동 
                     }
    }// 구슬 색 수 홀수일 경우 종료
     
    pal[0][0]=arr[0][0];      //초기 검색 조건 
    pal[0][1]=arr[0][1];
    
    
    for(i=0;i<num-1;i++)
    {
                        for(j=1;j<num;j++)
                        {
                                          for(k=0;k<2;k++)
                                          {
                                                          if(pal[i][1]==arr[j][k])
                                                          {
                                                                                  if(k==0)   //구슬이 뒤집혔을때 반대로 출력해줄 조건 
                                                                                  {
                                                                                          pal[i+1][0]=arr[j][0];
                                                                                          pal[i+1][1]=arr[j][1];
                                                                                          arr[j][0]=0;
                                                                                          arr[j][1]=0;
                                                                                          j=num;        //다음 검색을 위한 넘기기 
                                                                                  }
                                                                                  else
                                                                                  {
                                                                                      pal[i+1][0]=arr[j][1];
                                                                                      pal[i+1][1]=arr[j][0];   
                                                                                      arr[j][0]=0;
                                                                                      arr[j][1]=0;
                                                                                      j=num;             //다음 검색을 위한 넘기기 
                                                                                  }
                                                                                  if(pal[num-1][1]==pal[0][0])    //끝까지 다 만들었을때 반복문 전체를 빠져나오기 위한 조건 
                                                                                  {
                                                                                                              goto f1;
                                                                                  }
                                                                                  break;
                                                          }
                                          }
                        }                
    }
    
    f1:
    for(i=0;i<num;i++)    //결과 출력 
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
    printf("한번더?");
    scanf("%c", &s);
    if(s=='y')
    {
              goto s1;
    }    
    system("pause");
}
