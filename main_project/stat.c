#include<stdio.h>
struct user{
    int id;
    char name[20];
    char password[20];
    };
/*struct tscore
{
    float accuracy;
    double time_tkn;
    float percent_comp;
};
struct user
{
    int id;
    char name[20];
};
struct fscore
{
    float accuracy;
    double t;//use %f to print this
};*/

struct tscore
{
    float accuracy;
    double time_tkn;
    float percent_comp;
};
struct fscore
{
    float accuracy;
    double t;//use %f to print this
};
struct stat
{int id;
 struct tscore t;
 struct fscore f;
 int wscore;
};
void chstat(struct user u)
{
    system("cls");
    struct stat sts;
    FILE *f1=fopen("stat.txt","r");
    while(fread(&sts,sizeof(sts),1,f1))
    {
        printf("%d\n",sts.id);
        if(sts.id==u.id)
        {
            printf("TIME ATTACK");
            printf("\n%f",sts.t.percent_comp);
            if(sts.t.time_tkn==0)
            {
                printf("Time Not available yet");
            }
            else
            {
                printf("\n %f",sts.t.time_tkn);
            }
            printf("\n %f",sts.t.accuracy);
            printf("\n FREESTYLE");
            printf("\n %f",sts.f.accuracy);
            if(sts.t.time_tkn==0)
            {
                printf("Time Not available yet");
            }
            else
            {
                printf("\n %f",sts.f.t);
            }
            printf("\n WORD GAME");
            printf("%d",sts.wscore);
            break;
        }
    }
    fclose(f1);
    getch();
    fflush(stdin);
}
void rmstat(struct user u)
{
    system("cls");
    struct stat sts;
    FILE *f1=fopen("stat.txt","a+");
    fseek(f1,0,SEEK_SET);
    int k=0;
    while(fread(&sts,sizeof(sts),1,f1))
    {
        if(sts.id==u.id)
        {
            sts.t.percent_comp=0;
            sts.t.time_tkn=0;
            sts.t.accuracy=0;
            sts.f.accuracy=0;
            sts.f.t=0;
            sts.wscore=0;
            fseek(f1,(-1)*(sizeof(sts)),SEEK_CUR);
            fwrite(&sts,sizeof(sts),1,f1);
            break;
            k=1;
        }
    }
    if(k==0)
    {
        sts.t.percent_comp=0;
        sts.t.time_tkn=0;
        sts.t.accuracy=0;
        sts.f.accuracy=0;
        sts.f.t=0;
        sts.wscore=0;
        sts.id=u.id;
        fwrite(&sts,sizeof(sts),1,f1);
    }
    fclose(f1);
    printf("\nTHE STATS ARE RESET\n");
    getch();
    fflush(stdin);
}
void statcmp(struct user u,struct stat s)
{
    system("cls");
    struct stat sts;
    FILE *f1=fopen("stat.txt","a+");
    fseek(f1,0,SEEK_SET);
    while(fread(&sts,sizeof(sts),1,f1))
    {
        if(sts.id==u.id)
        {
            if(sts.t.percent_comp<s.t.percent_comp)
            {
                sts.t.percent_comp=s.t.percent_comp;
            }
            if(sts.t.time_tkn>s.t.time_tkn)
            {
                sts.t.time_tkn=s.t.time_tkn;
            }

            if(sts.t.accuracy<s.t.accuracy)
            {
                sts.t.accuracy=s.t.accuracy;
            }
            if(sts.f.accuracy<s.f.accuracy)
            {
                sts.f.accuracy=s.f.accuracy;
            }
            if(sts.f.t>s.f.t)
            {
                sts.f.t=s.f.t;
            }
            if(sts.wscore<s.wscore)
            {
                sts.wscore=s.wscore;
            }
            fseek(f1,(-1)*(sizeof(sts)),SEEK_CUR);
            fwrite(&sts,sizeof(sts),1,f1);
            break;
        }
    }
    fclose(f1);
    printf("The Stats are saved...\n");
    getch();
}
/*void main()
{
    struct stat s;
    s.id=1;
    s.t.accuracy=100;
    s.t.percent_comp=89;
    s.t.time_tkn=55;
    struct user u;
    u.id=1;
    //FILE *f=fopen("stat.txt","w");
    //fwrite(&s,sizeof(s),1,f);
    rmstat(u);
    //fclose(f);
}*/
