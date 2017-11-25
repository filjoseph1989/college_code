/**
 * Nov 11, 2008
 */
# include<stdio.h>
# include<conio.h>
# include<stdlib.h>

void main()
 { int i,x,fib,a=0,b=1;
  textbackground(BROWN);
  textcolor(BLUE);
  clrscr();
  printf("\t\t THIS PROGRAM GENERATES THE FIBONACCI SEQUENCE\n\n\n\t");
  printf("ENTER THE FIBONACCI NUMBER THAT YOU WANT:\t");
  scanf("%d",&fib);
  if(fib==0)
  printf("\n0");
  else if(fib==1)
  printf("\n%d\t%d",a,b);
  else if(fib<0)
  printf("THE NUMBER IS INVALID");
  else if(fib>1)
  {
  printf("\n%d\t%d",a,b);
  for(i=2;i<=fib;i++)
  {
  x=a;
  a=b;
  b=x+b;
  printf("\t%d",b);
  }
  getch();
  }}

  //recursive function
      //	# include<stdio.h>
      //	# include<conio.h>

   //		int fib(int num);
   //		int main()
   //		{
  //		clrscr();
  //		int num,loop;
  //		printf("enter the fibonacci number");
 //		scanf("%d",&num);
 //		for(loop=0;loop<=num;loop++)
//		printf("%d",fib(loop));
//		getch();
//		return 0;
//		}
//		int fib(num)
//		{
 //		if(num==0)
//		return 0;
//		else if(num==1)
//		return 1;
//		else if(num>1)
//		return (fib(num-1)+fib(num-2)
//		return 0;
//
 }
