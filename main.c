#include <stdio.h>
#include <process.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N 30
#define M 5

typedef struct student
{

    char number[20]; /*学号*/
    char name[20];/*名字*/
    int cla;/*班级*/
    int score[M];/*分数*/
    double average;/*平均分*/
    double average_a;/*每科平均分*/

}STU;
  STU stu[N];
int n;

void door()
{   int i;
   char a[4],b[100];
   a[0]='8';a[1]='0';a[2]='2';a[3]='3';
   for(i=0;i<3;i++)
   {
       printf("请输入密码:");
     scanf("%s",&b);
    system("cls");
    if(strcmp(b,a)==0)
    {
    	system("cls");
        printf("欢迎进入系统\n");
        system("pause");
       break;

    }
     else {system("cls");
            printf("密码错误\n");
            }

    }
     if(i==3)
    {
        printf("密码错误3次，系统退出\n");

       exit(0);
    }
   }

void zc()
{
    printf("\t\t欢迎欢迎\n");
    printf("**********************************************\n");
    printf("1.成绩录入\t2.成绩输出\t3.成绩排序\n");
    printf("4.成绩查找\t5.成绩修改\t6.成绩追加\n");
    printf("7.删除成绩\t8.成绩分段\t9.文件存储\n");
    printf("      a.文件导入\t0.退出系统\n");
    printf("**********************************************\n\n");
    printf("请选择:\n");


}

void input()    //成绩录入
{
    int w;
    printf("是否继续:（-1可返回,继续按任意数字）");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
else{
    system("cls");
    int i,j;
    printf("请输入录入人数：");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
  printf("请输入学生%d的学号、姓名、班级:\n",i+1);
  scanf("%s%s%d",&stu[i].number,&stu[i].name,&stu[i].cla);
   printf("请输入学生成绩：\n");
   printf("高数\t试听说\t读写译\tC语言\t计算机:\n");
   for(j=0;j<M;j++)
   scanf("%d",&stu[i].score[j]);
    }
    average();
     system("cls");

     printf("输入成功\n");

}

}

void average()   //平均数
{



   int i,j;

   for(i=0;i<n;i++)
   {  stu[i].average=0;
       for(j=0;j<M;j++)
       {
           stu[i].average+=stu[i].score[j];
       }

       stu[i].average=stu[i].average/M;
    }
    for(j=0;j<M;j++)
    {  stu[j].average_a=0;
        for(i=0;i<n;i++)
        {
            stu[j].average_a+=stu[i].score[j];
        }

       stu[j].average_a=stu[j].average_a/n;
    }
   system("cls");
   printf("平均值计算完成\n");
}

void output()   //成绩输出
{
    average();
	system("cls");
	int i,j;
	printf("********************************************************************\n");
	printf("学号\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");
	for(i=0;i<n;i++)
    {printf("%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
           for(j=0;j<M;j++)
           {
               printf("%d\t",stu[i].score[j]);
           }
          printf("%.2lf",stu[i].average);
          printf("\n");
    }
}

void sort()  //成绩排序
{

    int i,j,k;
    STU t;
    average();
    	system("cls");
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(stu[j].average>stu[j+1].average)
            {
                t=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=t;

        }
    }
    }
   output();

}


void seek()   //成绩查找
{
   int w;
    printf("是否继续:（-1可返回,继续按任意数字）");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
else{

    int d,a,i,j,o=1;
   average();
   	system("cls");
    printf("请选择查找方式：\n1.学号\t2.姓名\n请输入：");
    scanf("%d",&a);
    if(a==1)
    {
      char b[20];
      system("cls");
      printf("请输入需查询的学生学号:\n");
      scanf("%s",b);
      for(i=0;i<n;i++)
      {
      if(strcmp(b,stu[i].number)==0)
      {
         printf("学号\t\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");

        printf("%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
           for(j=0;j<M;j++)
           {
               printf("%d\t",stu[i].score[j]);
           }
          printf("%.2lf",stu[i].average);
          printf("\n");

      }
      else o++;
      if(o==n+1)
      printf("未找到该生信息\n");}
      }

    else if (a==2)
    {
        char c[20];
         system("cls");
      printf("请输入需查询的学生姓名:\n");
      scanf("%s",c);
      for(i=0;i<n;i++)
      {
      if(strcmp(c,stu[i].name)==0)
      {
         printf("学号\t\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");

        printf("%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
           for(j=0;j<M;j++)
           {
               printf("%d\t",stu[i].score[j]);
           }
          printf("%.2lf",stu[i].average);
          printf("\n");

      }
      else  o++;
      if(o==n+1)
      printf("未找到该生信息\n");

      }

    }

}
}


void modify()   //成绩修改
{
	 int w;
    printf("是否继续:（-1可返回,继续按任意数字）");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
       else{
    int d,a,i,j;
   average();
  system("cls");
    printf("请选择查找方式：\n1.学号\t2.姓名\n请输入：");
    scanf("%d",&a);
    if(a==1)
    {
      char b[10];
      system("cls");
      printf("请输入需查询的学生学号:\n");
      scanf("%s",b);
      for(i=0;i<n;i++)
      {
      if(strcmp(b,stu[i].number)==0)
      {
         printf("学号\t\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");

        printf("%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
           for(j=0;j<M;j++)
           {
               printf("%d\t",stu[i].score[j]);
           }
          printf("%.2lf",stu[i].average);
          printf("\n");
          printf("请重新输入该生的学号、姓名、班级：\n");
          scanf("%s%s%d",&stu[i].number,&stu[i].name,&stu[i].cla);
          printf("请输入该生的高数、试听说、读写译、C语言、计算机的成绩:\n");
          for(j=0;j<M;j++)
          {
              scanf("%d",&stu[i].score[j]);
          }
          printf("修改成功");
         output();
          break;
      }
      else {printf("未找到该生信息");break;}
      }
    }
    else if (a==2)
    {
        char c[20];
         system("cls");
      printf("请输入需查询的学生姓名:\n");
      scanf("%s",c);
      for(i=0;i<n;i++)
      {
      if(strcmp(c,stu[i].name)==0)
      {
         printf("学号\t\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");

        printf("%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
           for(j=0;j<M;j++)
           {
               printf("%d\t",stu[i].score[j]);
           }
          printf("%.2lf",stu[i].average);
          printf("\n");
         printf("请重新输入该生的学号、姓名、班级：\n");
          scanf("%s%s%d",&stu[i].number,&stu[i].name,&stu[i].cla);
          printf("请输入该生的高数、试听说、读写译、C语言、计算机的成绩:\n");
          for(j=0;j<M;j++)
          {
              scanf("%d",&stu[i].score[j]);
          }
          printf("修改成功");
         output();
          break;
      }
      else
      {printf("未找到该生信息");break;
      }
      }

    }
    else
    {system("cls");printf("输入错误\n");}
}}

void add()    //成绩追加
{ int w;
    printf("是否继续:（-1可返回,继续按任意数字）");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
       else{

    int a,i,j,b=1;
   system("cls");
    printf("请输入新增加的学生人数：\n");
    scanf("%d",&a);
    n=n+a;
    for(i=n-a;i<n;i++)
    {
         printf("请输入第%d位学生的学号、姓名、班级：\n",b);
          scanf("%s%s%d",&stu[i].number,&stu[i].name,&stu[i].cla);
          printf("请输入第%d位学生的高数、试听说、读写译、C语言、计算机的成绩：\n",b);
          for(j=0;j<M;j++)
          {
              scanf("%d",&stu[i].score[j]);
          }
          b++;
    }
    printf("添加成功\n");
    output();}
}

void  delete1()   //成绩删除
{
 int w;
    printf("是否继续:（-1可返回,继续按任意数字）");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
else{
 char l;
     int d,a,i,j,w,o=1;
   average();
	system("cls");
    printf("请选择查找方式：\n1.学号\t2.姓名\n请输入：");
    scanf("%d",&a);
    if(a==1)
    {
      char b[10];
      system("cls");
      printf("请输入需查询的学生学号:\n");
      scanf("%s",b);
      for(i=0;i<n;i++)
      {
      if(strcmp(b,stu[i].number)==0)
      {
         printf("学号\t\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");

        printf("%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
           for(j=0;j<M;j++)
           {
               printf("%d\t",stu[i].score[j]);
           }
          printf("%.2lf",stu[i].average);
          printf("\n");
          w=i;
         break;

      }
      else o++;
	  if(o==n+1)
	   printf("未找到该生信息");
      }
    }
    else if (a==2)
    {
        char c[20];
         system("cls");
      printf("请输入需查询的学生姓名:\n");
      scanf("%s",c);
      for(i=0;i<n;i++)
      {
      if(strcmp(c,stu[i].name)==0)
      {
         printf("学号\t\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");

        printf("%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
           for(j=0;j<M;j++)
           {
               printf("%d\t",stu[i].score[j]);
           }
          printf("%.2lf",stu[i].average);
          printf("\n");
          w=i;
        break;
      }
      else o++;
      if(o==n+1)
      printf("未找到该生信息");

      }

    }
    else
    {system("cls");printf("输入错误\n");}

   printf("是否删除该学生成绩(y/n)\n");
   scanf("%s",&l);
    if(l=='y')
    {
    for(i=w;i<n-1;i++)
        stu[i]=stu[i+1];
       n=n-1;
      printf("删除成功");
    }
    else if(l=='n')
        printf("删除失败");

}}


void segmentation()    //文件分段
{   system("cls");
    int i,j,c;
      printf("\nA:\n");
      for(i=0;i<n;i++){
       if(stu[i].average>=90)

                      {    c=i;

                       printf("学号\t\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");

                       printf("%s\t%s\t%d\t",stu[c].number,stu[c].name,stu[c].cla);
                      for(j=0;j<M;j++)
                         printf("%d\t",stu[c].score[j]);
                       printf("%.2lf",stu[c].average);
                        printf("\n");
                      }}


    printf("\nB:\n");
    for(i=0;i<n;i++){
       if(stu[i].average>=60&&stu[i].average<90)
                      {
                          c=i;
                        printf("学号\t\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");

                           printf("%s\t%s\t%d\t",stu[c].number,stu[c].name,stu[c].cla);
                      for(j=0;j<M;j++)
                         printf("%d\t",stu[c].score[j]);
                       printf("%.2lf",stu[c].average);

                      printf("\n");
                      }}


      printf("\nC:\n");
          for(i=0;i<n;i++){
                if (stu[i].average>=0&&stu[i].average<60)
                      {    c=i;
                      printf("学号\t\t姓名\t班级\t高数\t试听说\t读写译\tC语言\t计算机\t平均成绩\n");



                           printf("%s\t%s\t%d\t",stu[c].number,stu[c].name,stu[c].cla);
                      for(j=0;j<M;j++)
                         printf("%d\t",stu[c].score[j]);
                       printf("%.2lf",stu[c].average);
                              printf("\n");

                     }}


    }


 void export1 ()     //导出
 {
     FILE*fp;
     FILE*fa;
   int i,j;
   char m;
    system("cls");
     puts("是否保存学生成绩(y/n)\n");
     scanf("%s",&m);
     if(m=='y')
        {
        	if((fa=fopen("rs.txt","w"))==NULL)
        	{printf("文件打开失败\n");
          exit(0);
			}
			else{ fprintf(fa,"%d",n);
			}

		if((fp=fopen("score.txt","w"))==NULL)
        {printf("文件打开失败\n");
          exit(0);}
       else {

	   for(i=0;i<n;i++)
                 {

                           fprintf(fp,"%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
                      for(j=0;j<M;j++)
                         fprintf(fp,"%d\t",stu[i].score[j]);
                       fprintf(fp,"%.2lf\n",stu[i].average);


                 }

       system("cls");
        printf("保存成功\n");
        fclose(fa);
        fclose(fp);
       }
      }
      else

        return;}

void leading()   //导入
{
     FILE*fp;
     FILE*fa;
     int i,j,m;
     if((fa=fopen("rs.txt","r"))==NULL)
        	{printf("文件打开失败\n");
          exit(0);
			}
			else{ fscanf(fa,"%d",&n);
			}
     if((fp=fopen("score.txt","r"))==NULL)
        {printf("文件打开失败\n");
          exit(0);}
    else{
	   for(i=0;i<n;i++)
	   {

          fscanf(fp,"%s%s%d",&stu[i].number,&stu[i].name,&stu[i].cla);
                      for(j=0;j<M;j++)
                         fscanf(fp,"%d",&stu[i].score[j]);
		  fscanf(fp,"%lf",&stu[i].average);
          }
            system("cls");
        printf("导入成功\n");


	   }
	    fclose(fa);
	    fclose(fp);



	   }



int main()
{

    door();
   int a=1;
   zc();
    do
    {
    switch(getch())
    {

    case '1':input();break;
    case '2':output();break;
    case '3':sort();break;
    case '4':seek();break;
    case '5':modify();break;
    case '6':add();break;
    case '7':delete1();break;
    case '8':segmentation();break;
    case '9':export1();break;
    case 'a':leading();break;
    case '0':exit(0);break;
    default:printf("输入错误\n");system("cls");
    }
     getch();
     zc();
    }while(a==1);

}


