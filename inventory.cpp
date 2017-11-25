/**
 * @date Aug 13, 2008
 */
#include<stdio.h>
#include<conio.h>
#include<alloc.h>

 struct inv
{
 char item[20];
 int mm,dd,yy;
 int price,quantity;
 struct ivn *next;

}*tail,*hold=NULL,*head;
int ino=1;
void inst();
void add();
void display();
void main()
{
 int ch;
 clrscr();
 do
 {
  inst();
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    add();
    break;
   case 2:
    display();    getch();
    break;
   default :
    printf("invalid\n");
    break;
  }
 }while(ch!=3);
}

void inst()
{
 clrscr();
 printf("-------MAIN MENU----------\n\n"
    "1 -----  add\n"
    "2 -----  display\n"
    "3 -----  exit\n"
    "\n\nyour choice?");
}

void add()
{
 FILE *fp;
 clrscr();
 struct inv *temp=NULL;

 temp=(struct inv*)malloc(sizeof(struct inv));
 printf("enter item name");    scanf("%s",&temp->item);
 printf("enter month");        scanf("%d",&temp->mm);
 printf("enter day");          scanf("%d",&temp->dd);
 printf("enter year");         scanf("%d",&temp->yy);
 printf("enter price");        scanf("%d",&temp->price);
 printf("enter quantity");     scanf("%d",&temp->quantity);

 fp=fopen("inv.txt","a+");


 if(temp!=NULL)
 {
  hold=temp;
  temp=tail;
  tail=hold;
  fflush(stdin);
  fprintf(fp,"%d\t%s\t%d%d%d\t%d\t%d\n",ino,tail->item,tail->mm,tail->dd,tail->yy,tail->price,tail->quantity);

 }
 hold=NULL;
 temp=NULL;

 ino++;
}

void display()
{
 FILE *fp;
 int c;
 clrscr();

 printf("%s\n%s\t%s\t%s\t%s\t%s","month","item no","item","date","price","quantity");
 fp=fopen("inv.txt","r+");
 if(head==NULL)
 {

  fscanf(fp,"%d\t%s\t%d%d%d\t%d\t%d\n",ino,tail->item,tail->mm,tail->dd,tail->yy,tail->price,tail->quantity);
  if(tail!=NULL)
  {
   printf("%d\t%s\t%d-%d-%d\t%d\t%d\n",ino,tail->item,tail->mm,tail->dd,tail->yy,tail->price,tail->quantity);
  }
 }
}
