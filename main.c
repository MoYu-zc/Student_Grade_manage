#include <stdio.h>
#include <process.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N 30
#define M 5

typedef struct student
{

    char number[20]; /*ѧ��*/
    char name[20];/*����*/
    int cla;/*�༶*/
    int score[M];/*����*/
    double average;/*ƽ����*/
    double average_a;/*ÿ��ƽ����*/

}STU;
  STU stu[N];
int n;

void door()
{   int i;
   char a[4],b[100];
   a[0]='8';a[1]='0';a[2]='2';a[3]='3';
   for(i=0;i<3;i++)
   {
       printf("����������:");
     scanf("%s",&b);
    system("cls");
    if(strcmp(b,a)==0)
    {
    	system("cls");
        printf("��ӭ����ϵͳ\n");
        system("pause");
       break;

    }
     else {system("cls");
            printf("�������\n");
            }

    }
     if(i==3)
    {
        printf("�������3�Σ�ϵͳ�˳�\n");

       exit(0);
    }
   }

void zc()
{
    printf("\t\t��ӭ��ӭ\n");
    printf("**********************************************\n");
    printf("1.�ɼ�¼��\t2.�ɼ����\t3.�ɼ�����\n");
    printf("4.�ɼ�����\t5.�ɼ��޸�\t6.�ɼ�׷��\n");
    printf("7.ɾ���ɼ�\t8.�ɼ��ֶ�\t9.�ļ��洢\n");
    printf("      a.�ļ�����\t0.�˳�ϵͳ\n");
    printf("**********************************************\n\n");
    printf("��ѡ��:\n");


}

void input()    //�ɼ�¼��
{
    int w;
    printf("�Ƿ����:��-1�ɷ���,�������������֣�");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
else{
    system("cls");
    int i,j;
    printf("������¼��������");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
  printf("������ѧ��%d��ѧ�š��������༶:\n",i+1);
  scanf("%s%s%d",&stu[i].number,&stu[i].name,&stu[i].cla);
   printf("������ѧ���ɼ���\n");
   printf("����\t����˵\t��д��\tC����\t�����:\n");
   for(j=0;j<M;j++)
   scanf("%d",&stu[i].score[j]);
    }
    average();
     system("cls");

     printf("����ɹ�\n");

}

}

void average()   //ƽ����
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
   printf("ƽ��ֵ�������\n");
}

void output()   //�ɼ����
{
    average();
	system("cls");
	int i,j;
	printf("********************************************************************\n");
	printf("ѧ��\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");
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

void sort()  //�ɼ�����
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


void seek()   //�ɼ�����
{
   int w;
    printf("�Ƿ����:��-1�ɷ���,�������������֣�");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
else{

    int d,a,i,j,o=1;
   average();
   	system("cls");
    printf("��ѡ����ҷ�ʽ��\n1.ѧ��\t2.����\n�����룺");
    scanf("%d",&a);
    if(a==1)
    {
      char b[20];
      system("cls");
      printf("���������ѯ��ѧ��ѧ��:\n");
      scanf("%s",b);
      for(i=0;i<n;i++)
      {
      if(strcmp(b,stu[i].number)==0)
      {
         printf("ѧ��\t\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");

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
      printf("δ�ҵ�������Ϣ\n");}
      }

    else if (a==2)
    {
        char c[20];
         system("cls");
      printf("���������ѯ��ѧ������:\n");
      scanf("%s",c);
      for(i=0;i<n;i++)
      {
      if(strcmp(c,stu[i].name)==0)
      {
         printf("ѧ��\t\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");

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
      printf("δ�ҵ�������Ϣ\n");

      }

    }

}
}


void modify()   //�ɼ��޸�
{
	 int w;
    printf("�Ƿ����:��-1�ɷ���,�������������֣�");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
       else{
    int d,a,i,j;
   average();
  system("cls");
    printf("��ѡ����ҷ�ʽ��\n1.ѧ��\t2.����\n�����룺");
    scanf("%d",&a);
    if(a==1)
    {
      char b[10];
      system("cls");
      printf("���������ѯ��ѧ��ѧ��:\n");
      scanf("%s",b);
      for(i=0;i<n;i++)
      {
      if(strcmp(b,stu[i].number)==0)
      {
         printf("ѧ��\t\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");

        printf("%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
           for(j=0;j<M;j++)
           {
               printf("%d\t",stu[i].score[j]);
           }
          printf("%.2lf",stu[i].average);
          printf("\n");
          printf("���������������ѧ�š��������༶��\n");
          scanf("%s%s%d",&stu[i].number,&stu[i].name,&stu[i].cla);
          printf("����������ĸ���������˵����д�롢C���ԡ�������ĳɼ�:\n");
          for(j=0;j<M;j++)
          {
              scanf("%d",&stu[i].score[j]);
          }
          printf("�޸ĳɹ�");
         output();
          break;
      }
      else {printf("δ�ҵ�������Ϣ");break;}
      }
    }
    else if (a==2)
    {
        char c[20];
         system("cls");
      printf("���������ѯ��ѧ������:\n");
      scanf("%s",c);
      for(i=0;i<n;i++)
      {
      if(strcmp(c,stu[i].name)==0)
      {
         printf("ѧ��\t\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");

        printf("%s\t%s\t%d\t",stu[i].number,stu[i].name,stu[i].cla);
           for(j=0;j<M;j++)
           {
               printf("%d\t",stu[i].score[j]);
           }
          printf("%.2lf",stu[i].average);
          printf("\n");
         printf("���������������ѧ�š��������༶��\n");
          scanf("%s%s%d",&stu[i].number,&stu[i].name,&stu[i].cla);
          printf("����������ĸ���������˵����д�롢C���ԡ�������ĳɼ�:\n");
          for(j=0;j<M;j++)
          {
              scanf("%d",&stu[i].score[j]);
          }
          printf("�޸ĳɹ�");
         output();
          break;
      }
      else
      {printf("δ�ҵ�������Ϣ");break;
      }
      }

    }
    else
    {system("cls");printf("�������\n");}
}}

void add()    //�ɼ�׷��
{ int w;
    printf("�Ƿ����:��-1�ɷ���,�������������֣�");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
       else{

    int a,i,j,b=1;
   system("cls");
    printf("�����������ӵ�ѧ��������\n");
    scanf("%d",&a);
    n=n+a;
    for(i=n-a;i<n;i++)
    {
         printf("�������%dλѧ����ѧ�š��������༶��\n",b);
          scanf("%s%s%d",&stu[i].number,&stu[i].name,&stu[i].cla);
          printf("�������%dλѧ���ĸ���������˵����д�롢C���ԡ�������ĳɼ���\n",b);
          for(j=0;j<M;j++)
          {
              scanf("%d",&stu[i].score[j]);
          }
          b++;
    }
    printf("��ӳɹ�\n");
    output();}
}

void  delete1()   //�ɼ�ɾ��
{
 int w;
    printf("�Ƿ����:��-1�ɷ���,�������������֣�");
    scanf("%d",&w);
    if(w==-1)
      {system("cls");
       return;}
else{
 char l;
     int d,a,i,j,w,o=1;
   average();
	system("cls");
    printf("��ѡ����ҷ�ʽ��\n1.ѧ��\t2.����\n�����룺");
    scanf("%d",&a);
    if(a==1)
    {
      char b[10];
      system("cls");
      printf("���������ѯ��ѧ��ѧ��:\n");
      scanf("%s",b);
      for(i=0;i<n;i++)
      {
      if(strcmp(b,stu[i].number)==0)
      {
         printf("ѧ��\t\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");

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
	   printf("δ�ҵ�������Ϣ");
      }
    }
    else if (a==2)
    {
        char c[20];
         system("cls");
      printf("���������ѯ��ѧ������:\n");
      scanf("%s",c);
      for(i=0;i<n;i++)
      {
      if(strcmp(c,stu[i].name)==0)
      {
         printf("ѧ��\t\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");

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
      printf("δ�ҵ�������Ϣ");

      }

    }
    else
    {system("cls");printf("�������\n");}

   printf("�Ƿ�ɾ����ѧ���ɼ�(y/n)\n");
   scanf("%s",&l);
    if(l=='y')
    {
    for(i=w;i<n-1;i++)
        stu[i]=stu[i+1];
       n=n-1;
      printf("ɾ���ɹ�");
    }
    else if(l=='n')
        printf("ɾ��ʧ��");

}}


void segmentation()    //�ļ��ֶ�
{   system("cls");
    int i,j,c;
      printf("\nA:\n");
      for(i=0;i<n;i++){
       if(stu[i].average>=90)

                      {    c=i;

                       printf("ѧ��\t\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");

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
                        printf("ѧ��\t\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");

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
                      printf("ѧ��\t\t����\t�༶\t����\t����˵\t��д��\tC����\t�����\tƽ���ɼ�\n");



                           printf("%s\t%s\t%d\t",stu[c].number,stu[c].name,stu[c].cla);
                      for(j=0;j<M;j++)
                         printf("%d\t",stu[c].score[j]);
                       printf("%.2lf",stu[c].average);
                              printf("\n");

                     }}


    }


 void export1 ()     //����
 {
     FILE*fp;
     FILE*fa;
   int i,j;
   char m;
    system("cls");
     puts("�Ƿ񱣴�ѧ���ɼ�(y/n)\n");
     scanf("%s",&m);
     if(m=='y')
        {
        	if((fa=fopen("rs.txt","w"))==NULL)
        	{printf("�ļ���ʧ��\n");
          exit(0);
			}
			else{ fprintf(fa,"%d",n);
			}

		if((fp=fopen("score.txt","w"))==NULL)
        {printf("�ļ���ʧ��\n");
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
        printf("����ɹ�\n");
        fclose(fa);
        fclose(fp);
       }
      }
      else

        return;}

void leading()   //����
{
     FILE*fp;
     FILE*fa;
     int i,j,m;
     if((fa=fopen("rs.txt","r"))==NULL)
        	{printf("�ļ���ʧ��\n");
          exit(0);
			}
			else{ fscanf(fa,"%d",&n);
			}
     if((fp=fopen("score.txt","r"))==NULL)
        {printf("�ļ���ʧ��\n");
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
        printf("����ɹ�\n");


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
    default:printf("�������\n");system("cls");
    }
     getch();
     zc();
    }while(a==1);

}


