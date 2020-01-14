#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define max 130
int rear=-1;
int front=-1;
int queue[max];
int q[5][26];
void push(char);
char pop();
void display();
int TOP=-1;
char stack[100];
char name2[100];
struct booking
{
	char code[40];
	char name[40];
	char date[40];
	char time[40];
	int cost;
	char day[40];
	char venue[40];
};

int seat = 130;

void insert_new_movie();
void insert_new_match();
void view_available_movies();
void view_available_match();
void book_ticket();
void book_ticket2();
void old_record();
void old_record2();
void view_available_pt();
int main()
{
    int c,i,j;
    int id,pin;
    printf("enter your choice");
    printf("\nenter 1 for movies");
    printf("\nenter 2 for matches\n");
    scanf("%d",&c);
    //fflush(stdin);
    switch (c)
    {
    case 1:
    {
            int ch;
 	do{
	printf("\n********************************************************************");
	printf("\n");
	printf("\t welcome to M-SQUARE (Movies)");
	printf("\n");
	printf("\n********************************************************************");
	printf("\nPress <1> Insert Movie(Only Administrator)");
   	printf("\nPress <2> View All Movie");
	printf("\nPress <3> Book Ticket");
	printf("\nPress <4> View All Transactions");
   	printf("\nPress <0> Exit ");

   	printf("\nEnter your Choice--->");
   	scanf("%d",&ch);

   	switch (ch)
   	{
        case 1 :
            printf("Enter UserId and Password:");
            scanf("%d",&id);
            scanf("%d",&pin);
            if(pin!=1234)
            {
                printf("OOOps Wrong Password");
            }
    		insert_new_movie();
   		    break;
		case 2:
		    printf("Code\t\t\tName\t\t\tDate\t\t\tCost:\n\n");
    		view_available_movies();
   		    break;
		case 3:
		    printf("Code\t\t\tName\t\t\tDate\t\t\tCost:\n\n");
		    book_ticket();
		    break;

		case 4:
		    old_record();
		    break;
        case 0:
            exit(0);
        default:
            printf("Wrong choice !");
            break;
   	}
 }while(ch!=0);
           break;
}
            case 2:
                {
                int ch2;
                do
                {
                printf("\n********************************************************************");
	            printf("\n");
	            printf("\t welcome to M-SQUARE (IPL)");
	            printf("\n");
	            printf("\n********************************************************************");
	            printf("\nPress <1> Insert IPL Matches(Only Administrator)");
   	            printf("\nPress <2> View IPL Schedule");
   	            printf("\nPress <3> View Point Table");
	            printf("\nPress <4> Book Ticket");
	            printf("\nPress <5> View All Transactions");
   	            printf("\nPress <0> Exit ");

   	            printf("\nEnter your Choice--->");
   	            scanf("%d",&ch2);

   	            switch (ch2)
   	             {
                 case 1 :
                     printf("Enter UserId and Password:");
                     scanf("%d",&id);
                     scanf("%d",&pin);
                     if(pin!=1234)
                     {
                      printf("OOOps Wrong Password");
                      exit(0);
                      }
                      insert_new_match();
   		              break;
                case 2:
                    //printf("Code\t\t\tName\t\t\tDate\t\t\tCost:\n\n");
    		        view_available_match();
   		            break;
		        case 4:
		            printf("Code\t\t\tName\t\t\tDate\t\t\tCost:\n\n");
		           book_ticket2();
		            break;
                case 5:
	            	old_record2();
		            break;
                case 0:
    		        exit(0);
                case 3:
                   view_available_pt();
                    break;
                default:
                    printf("Wrong choice !");
                    break;
   	}
 }while(ch2!=0);
 break;
}
    }
}
void insert_new_movie()
{

	FILE *nm;
	struct booking x;
	printf("enter movie code :- ");
	scanf("%s",x.code);
	printf("enter name :- ");
	fflush(stdin);
	gets(x.name);
	fflush(stdin);
	printf("enter release Date:- ");
	scanf("%s",x.date);
	fflush(stdin);
	printf("enter Ticket Price:- ");
	scanf("%d",&x.cost);

	nm=fopen("data.txt","a");

	if(nm == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(nm,"%s.%s.%s.%d.\n",x.code,x.name,x.date,x.cost);
		printf("Record insert Successfull");
	}
		printf("\n");
	fclose(nm);
}
void insert_new_match()
{
    FILE *nm;
	struct booking x,y;
	printf("enter match number :- ");
	scanf("%s",x.code);
	printf("enter name of rival teams :- ");
	fflush(stdin);
	gets(x.name);
	gets(y.name);
	fflush(stdin);
	printf("Enter the name of day:-");
	fflush(stdin);
	gets(x.day);
	fflush(stdin);
	printf("enter  Date(in format Name of month followed by date): and Time:- ");
	scanf("%s",x.date);
	fflush(stdin);
	scanf("%s",x.time);
	fflush(stdin);
	printf("enter Ticket Price:- ");
	scanf("%d",&x.cost);
	printf("Enter Venue:-");
	scanf("%s",x.venue);

	nm=fopen("IPL.txt","a");

	if(nm == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(nm,"   %s,%s:\n %s vs %s at %s IST in %s.",x.day,x.date,x.name,y.name,x.time,x.venue);
		fprintf(nm,"\n\n\t\tAll Ticket costs Rs.%d",x.cost);
		printf("Record insert Successfull");
	}
		printf("\n");
	fclose(nm);
}
void view_available_movies()
{
	char ch;
	FILE *av;
    int i;
	av = fopen("data.txt","r");
	if(av == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
	    int count=0,c2=0;
		while( ( ch = fgetc(av) ) != EOF )
        {
            if(ch=='.')
            {
                for(i=1;i<25-count;i++)
                {
                    printf(" ");
                }
                count=0;
            }
            else
            {
                count++;
               printf("%c",ch);
            }
        }

	}
	fclose(av);
}
void view_available_match()
{
	char ch;
	FILE *av;
    int i=0;
	av = fopen("IPL.txt","r");
	if(av == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		while( ( ch = fgetc(av) ) != EOF )
        {
            if(ch==':')
            {
                printf("\n");
            }
            else
            {
               printf("%c",ch);
            }
        }
	}
	fclose(av);
}
void view_available_pt()
{
    FILE *f;
    char ch;
    f=fopen("PT.txt","r");
    if(f==NULL)
    {
        printf("File does not found");
    }
    else
    {
        while((ch=fgetc(f))!=EOF)
        {
                printf("%c",ch);

        }
    }
    fclose(f);
}
void book_ticket()
{
 struct booking y;
	FILE *fp;
	int sum=0;
	FILE *ufp;
	FILE *a;
	int total_amount;
	char mobile[11];
	char name[20];
	char ch;
	char movie_code[20];
	view_available_movies();
    char xy[1500],str[100];
    int c=0;
	printf("\n For Book ticket Choose Movie:");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);

	}

	else
	{
	    int i,k,num;
		while(getc(fp) != EOF)
		{
		    i=0;
			fscanf(fp,"%[^\t\n]s",xy);
		    k=0;
			while(xy[i]!='.')
            {
                str[k]=xy[i];
                i++;
                k++;
            }
            str[i]='\0';
			if(strcmp(str,movie_code) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",str);
				i++;
			while(xy[i]!='.')
            {
                push(xy[i]);
                i++;
            }
            i++;
				printf("\n\t\tMovie name ::");
				display();
				strcpy(y.name,name2);
			while(xy[i]!='.')
            {
                push(xy[i]);
                i++;
            }
            i++;
				printf("\n\t\tRelease date ::");
				display();
			while(xy[i]!='.')
            {
                //printf("%d\n",xy[i]);
                sum=sum*10+((int)xy[i]-48);
                i++;
            }
            i++;
            y.cost=sum;
            printf("\n\t\tcost per ticket : %d\n",y.cost);
				c++;
				break;
			}
		}
	}
	if(c!=0)
    {
	printf("\n*********************************************************\n Fill Details :\n ");
	printf("\n your name :");
	fflush(stdin);
	scanf("%[^\t\n]s",name);
	fflush(stdin);
	printf("\n mobile number :");
	scanf("%s",mobile);
            printf("\t\t\tSee sitting arrangement:\n\n");
            int q[5][26]={0};
            int i,j;
                for (i=0;i<5;i++)
                {
                    for (j=0;j<26;j++)
                        {
                        printf("%d ",j+1);
                        }
                    printf("\n");
                }
            printf("enter the number of seats you want to book");
            int number;
            scanf("%d",&number);
            int rr[number],cc[number];
            for (i=0;i<number;i++)
            {
                printf("\nEnter the row:");
            scanf("%d",&rr[i]);
            printf("\nEnter the column:");
            scanf("%d",&cc[i]);
            q[rr[i]][cc[i]]=1;
            }
            int conf;
                int k;
            printf("Press 1 to confirm:\n");
            conf=getch();
            for (i=0;i<5;i++)
            {
                for (j=0;j<26;j++)
                {
                    for(k=0;k<number;k++)
                    if (i==rr[k]&&j==cc[k])
                    q[i][j]=1;
                }
            }
            int u=1;
            for (i=0;i<5;i++)
            {
                for (j=0;j<26;j++)
                printf("%d",q[i][j]);
                printf("\n");
            }
             for (i=0;i<number;i++)
                {
                    if (rear==max-1)
                       {
                           printf("houseful");
                           u=0;
                       }
                     rear=(rear+1)%max;
                queue[rear]==1;
                }


            if (conf==1);
                  printf("your booking is successfull");
            total_amount=number*sum;
	printf("\n ENJOY MOVIE \n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %s",mobile);
	printf("\n\t\tmovie name : %s",y.name);
	printf("\n\t\tTotal seats : %d",number);
	printf("\n\t\tcost per ticket : %d",y.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);
	ufp=fopen("oldTransaction.txt","a");
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"%s %s %d %d %s %d \n",name,mobile,number,total_amount,y.name,y.cost);
		printf("\n Record insert Sucessfull to the old record file");
	}
    }
    else
    {
        printf("Entered Code does not Exists.");
    }
		printf("\n");
	fclose(ufp);
	fclose(fp);
}
void book_ticket2()
{
 struct booking y;
	FILE *fp;
	int sum=0;
	FILE *ufp;
	int total_amount;
	char mobile[11];
	char name[20];
	char ch;
	char code[20];
	view_available_match();
    char xy[1500],str[100];
    int c=0;
	printf("\n For Book ticket Choose IPL:");
	printf("\n Enter Match Number :");
	scanf("%s",code);
	fp = fopen("IPL.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);
	}

	else
	{
	    int i,k,j,num;
		while(getc(fp) != EOF)
		{

		    i=0;
			fscanf(fp,"%[^\t\n]s",xy);
		    k=0;
		    //printf("%s",xy);
		    while(xy[i]!=':')
            {
                push(xy[i]);
                i++;
            }
            i++;
            while(xy[i]!='.')
            {
                str[k]=xy[i];
                i++;
                k++;
            }
            str[i]='\0';
            //printf("%s",str);
			if(strcmp(str,code) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",str);
				i++;
				printf("\n\t\tDate ::");
				display();
				strcpy(y.day,name2);
				while(xy[i]!='.')
                {
                push(xy[i]);
                i++;
                }
                i++;
				printf("\n\t\tRival Teams name ::");
				display();
				strcpy(y.name,name2);
			while(xy[i]!='I')
            {
                push(xy[i]);
                i++;
            }
            i++;
            printf("\n\t\tTime of Match ::");
            display();
            y.cost=1000;
            printf("\n\t\tcost per ticket : %d",y.cost);
            while(xy[i]!='n')
            {
                i++;
            }
            i++;
            while(xy[i]!='\0')
            {
                push(xy[i]);
                i++;
            }
            printf("\n\t\tVenue ::");
            display();
				c++;
				break;
			}
			else
            {
            int o;
            char op;
            for(o=0;o<TOP*20;o++)
            {
              op=pop();
            }
            }
		}
	}
	if(c!=0)
    {
	printf("\n*********************************************************\n Fill Details :\n ");
	printf("\n your name :");
	fflush(stdin);
	scanf("%[^\t\n]s",name);
	fflush(stdin);
	printf("\n mobile number :");
	scanf("%s",mobile);
            printf("\t\t\tSee sitting arrangement:\n\n");
            int q[5][26]={0};
            int i,j;
                for (i=0;i<5;i++)
                {
                    for (j=0;j<26;j++)
                        {
                        printf("%d ",j+1);
                        }
                    printf("\n");
                }
            printf("enter the number of seats you want to book");
            int number;
            scanf("%d",&number);
            int rr[number],cc[number];
            for (i=0;i<number;i++)
            {
                printf("\nEnter the row:");
            scanf("%d",&rr[i]);
            printf("\nEnter the column:");
            scanf("%d",&cc[i]);
            q[rr[i]][cc[i]]=1;
            }
            int conf;
                int k;
            printf("Press 1 to confirm:\n");
            conf=getch();
            for (i=0;i<5;i++)
            {
                for (j=0;j<26;j++)
                {
                    for(k=0;k<number;k++)
                    if (i==rr[k]&&j==cc[k])
                    q[i][j]=1;
                }
            }
            int u=1;
            for (i=0;i<5;i++)
            {
                for (j=0;j<26;j++)
                printf("%d",q[i][j]);
                printf("\n");
            }
             for (i=0;i<number;i++)
                {
                    if (rear==max-1)
                       {
                           printf("houseful");
                           u=0;
                       }
                     rear=(rear+1)%max;
                queue[rear]==1;
                }


            if (conf==1);
                  printf("your booking is successfull");
            total_amount=number*y.cost;
	printf("\n ENJOY IPL Match \n");
	printf("\n\t\tname : %s",name);
	printf("\n\t\tmobile Number : %s",mobile);
	printf("\n\t\tmovie name : %s",y.name);
	printf("\n\t\tTotal seats : %d",number);
	printf("\n\t\tcost per ticket : %d",y.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);
	ufp=fopen("oldTransaction2.txt","a");
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"%s %s %d %d %s %d \n",name,mobile,number,total_amount,y.name,y.cost);
		printf("\n Record insert Sucessfull to the old record file");
	}
    }
    else
    {
        printf("Entered Code does not Exists.");
    }
		printf("\n");
	fclose(ufp);
	fclose(fp);
}
void old_record()
{
	char ch;
	FILE *fp;
	fp = fopen("oldTransaction.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
}
void old_record2()
{
	char ch;
	FILE *fp;
	fp = fopen("oldTransaction2.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
}
void push(char ch)
{
    if(TOP>=100-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        TOP++;
        stack[TOP]=ch;
    }
}
char pop()
{

    if(TOP<=-1)
    {
        printf("Stack Underflow");
    }
    else
    {
        return stack[TOP--];
    }
}
void display()
{
    int i=0,j=0;
    int k=0;
    char str2[100];
    char ret[100];
    if(TOP!=-1)
    {
    while(TOP!=-1)
    {
        str2[i]=pop();
        i++;
    }
    for(k=i-1;k!=-1;k--)
    {
        name2[j]=str2[k];
        printf("%c",str2[k]);
        j++;
    }
    }
    else
    {
        printf("Stack is empty.");
    }
}

