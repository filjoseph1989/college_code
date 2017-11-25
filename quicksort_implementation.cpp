/**
 * Oct 08, 2009
 * @param left  [description]
 * @param right [description]
 */
#include<stdio.h>
#include<conio.h>
#include<dos.h>

struct  time t;
struct  time t2;
int a[10];

void quickSort(int left, int right, int s)
{
 int i= left,j= right;
 int pivot= a[(left+right)/2];
 int temp,cheker,c;
 int r= s/2;

 while(i<=j)
 {
    while( a[i] < pivot )
    i++;
    while( a[j] > pivot )
    j--;

    cheker=0; c=0;
    while(cheker < a[c] && c<=s)
    {
     cheker= a[c];
     c++;
    };

    if(i<=j)
    {
      temp= a[i];
      a[i]= a[j];
      a[j]= temp;
      i++;
      j--;
    }
 };

 if(c < r)
   quickSort(left,j,s);
 if(c > r && c < s+1)
   quickSort(r+1,s,s);
}

void main()
{
int left,right;
left= right= 0;

clrscr();
printf("how many input? ");
int n=  getch();
n= n-48;

printf("\nenter %d numbers:",n);
for(int i=0; i<n; i++)
{
 scanf("%d",&a[i]);
 right++;
}


gettime(&t);
printf("The current time is: %2d:%02d:%02d.%02d\n",
    t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);

quickSort(left,right-1,right-1);

gettime(&t2);
printf("The current time is: %2d:%02d:%02d.%02d\n",
    t2.ti_hour, t2.ti_min, t2.ti_sec, t2.ti_hund);


printf("ascending numbers:\n");
for(int j=0; j<n; j++)
{
  printf("%d ",a[j]);
}
getch();
}
