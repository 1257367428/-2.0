#include <cstdlib>
#include<stdio.h>
struct student
{
    int number;
    char name[20];
    char sex[20];
    int birth;
    char class1[20];
    char telephone[20];
    int judge1,judge2,judge3,judge4,judge5;
    int score;
};
int main()
{
    struct student s[1000];
    FILE *a,*b;
    int i=0,j;
    a =fopen("/Users/S20171105117/Desktop/studentdata.csv","r");
    if(a==NULL)
    {
        printf("打开错误，或者找不到文件\n");
        exit(-1);
    }
    else
    {
        fscanf(a,"%*[^\n]%*c");
        while(!feof(a))
        {
            fscanf(a,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d,",
                   &s[i].number,s[i].name,s[i].sex,&s[i].birth,s[i].class1,s[i].telephone,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            i++;
        }
        j=i;
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d\n",s[i].number,s[i].name,s[i].sex,s[i].birth,s[i].class1,s[i].telephone,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
        }
        fclose(a);
    }
    j=i;
    int max[100],min[100];
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;
    }
    j=i;
    for(i=0;i<j;i++)
    {
        if(s[i].judge2>max[i])
            max[i]=s[i].judge2;
        if(s[i].judge3>max[i])
            max[i]=s[i].judge3;
        if(s[i].judge4>max[i])
            max[i]=s[i].judge4;
        if(s[i].judge5>max[i])
            max[i]=s[i].judge5;
    }
    j=i;
    for(i=0;i<j;i++)
    {
        if(s[i].judge2<min[i])
            min[i]=s[i].judge2;
        if(s[i].judge3<min[i])
            min[i]=s[i].judge3;
        if(s[i].judge4<min[i])
            min[i]=s[i].judge4;
        if(s[i].judge5<min[i])
            min[i]=s[i].judge5;
    }
    j=i;
    for(i=0;i<j;i++)
    {
        s[i].score=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;
    }
    
    b=fopen("/Users/S20171105117/Desktop/studentdada2.0.csv","w");
              fprintf(b,"number,name,sex,birth,class,telephone,judge1,judge2,judge3,judge4,judge5,score\n");
              j=i;
              i=0;
              while(i<j)
              {
                  fprintf(b,"%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d\n",s[i].number,s[i].name,s[i].sex,s[i].birth,
                          s[i].class1,s[i].telephone,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].score);
                  i++;
              }
              fclose(b);             
              return 0;
              }
