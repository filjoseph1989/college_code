/**
 * Oct 08, 2009
 * @param left  [description]
 * @param right [description]
 */
#include<stdio.h>
#include<conio.h>

int a[10];
void quickSort(int left, int right)
{
  int i= left,j= right;
 int temp;
 int pivot= a[(left+right)/2];
 printf("\npivot %d\n",pivot);

 while(i<=j)
 {
    while(a[i]<pivot)
    i++;
    while(a[j] > pivot)
    j--;

    if(i<=j)
    {
       temp= a[i];
       a[i]= a[j];
       a[j]= temp;
       i++;
       j--;
    }

 };

 if(left < j)
  quickSort(left,j);
 if(i < right)
  quickSort(i,right);
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

quickSort(left,right);
printf("ascending numbers:\n");
for(int j=1; j<=n; j++)
{
 printf("%d ",a[j]);
}

getch();
}
