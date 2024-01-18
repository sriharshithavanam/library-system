#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void user_info();
void Student();
void Admin();
int search();
int Searchline();
void Paperback();
void listofbooks();
struct Details
{
    char name[100];
    char book_name[100];
    int bookid;
};
void main(void)
{
   user_info();
}
void user_info()
{
    int user_type;
    printf("Welcome to TECHLIB\n ");
 P: 
 printf("Are you a student or Admin?\n 1-student\n2-Admin");
 scanf(" %d",&user_type);
    if(user_type==1)
    {
        Student();
    }
    else if(user_type==2)
    {
        Admin();
    }
    else
    {
        printf("Please select the correct one");
        goto P;//if user enters something different then it will take input again.
    }
}
void Student()
{
   int mode=0;
   m:
   printf("How can we help you?\n 1-Pick a book\n2-to view the list of books available\n3-search books");
   scanf("%d",&mode);
   if(mode==4)
   {
   	exit(0);
   }
   else if(mode == 1)
   {
    Paperback();
   }
   else if(mode==2)
   {
    listofbooks();
   }
   else if (mode==3)
   {
    search();
   }
   else
   {
    printf("Please choose the any one of the modes");
    goto m;
    mode=4;
   }
}

void Paperback()
{
   printf("�vailable books are\n");
   listofbooks();
   FILE *pb;
   char ch;int num,i;
   struct Details p;
   pb=fopen("D:\\Books.txt","a");
   printf("how many books do you want?");scanf("%d",&num);
   for( i=1;i<=num;i++)
   {
  Q: printf("enter you name,book name, BOOK ID,author's name:");
   scanf(" %s\n %s\n %d",p.name,p.book_name,&p.bookid);
   int found=search();
   if(found==-1)
   {
   	exit(0);
   }
   else if(found==1)
   {
     fprintf(pb," \n%s\t%s\t%d",p.name,p.book_name,p.bookid);
   }
   else
   {
    printf("enter again");
    goto Q; 
    found=-1;
   }
   }
   fclose(pb);
   printf("Thank you. Have a good read!");
}
void listofbooks()
{
  FILE *fp;
  char c;                                                                                  
  fp=fopen("D:\\booklist.txt","r");
  c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
  
    fclose(fp);
}
int search()
{
  FILE *fp;
  char book_name[50];
  char word[50];
  char w[50];
  scanf("%s",w);
  char *search=w;
  char ch;int count=0,pointer=0;
  int pos[10],f=0;
  fp=fopen("D:\\booklist.txt","r");
  do
  {
    ch=fscanf(fp,"%s",word);
    if(strcmp(word,search)==0)
    {
        pos[count]=pointer;
        count++;
    }
    pointer++;
  }while(ch!=EOF);
  if(count==0)
  {
    f=0;
    printf("not found");
  }
  else
  {
    f=1;
    printf("found");
  }
  fclose(fp);
  return f;
  

}
void Admin()
{
   int choice;char c;
    printf("How can we help you?\n1-access the list of customers\n2-search any book\n");
    scanf("%d",&choice);
    if(choice==1)
    {
       FILE *fb;
       fb=fopen("D:\\Books.txt","r");
       c=fgetc(fb);
       while(c!=EOF)
       {
        printf("%c",c);
        c=fgetc(fb);
       }
       fclose(fb);
    }
    else if(choice==2)
    {
      search();
    }
}
