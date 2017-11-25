/**
 * traffic light coloring projects in algorithm
 * Oct 08, 2009
 * 
 * [printGraph description]
 * @return [description]
 */
#include <string.h>
#include <stdio.h>
#include<conio.h>

int blue[13],sb=-1,cnt =0,cn=0;
int green[13],sg=-1,cnt1=0,cn1=0;
int red[13],sred=-1,cnt2=0,cn2=0;
int yellow[13],syellow=-1,cnt3=0,cn3=0;
int r[13];
//others

int p=-1,z=-1,h;
int m[50][50];
char string[50][5];
char c[3],v[3];


//group of function
char printGraph();
char setVertices();
int  setEdges();
int findEdges(int a);
int setColour(int b);
void printColour();

//main body
void main(void)
{
  int n,tmp[13],w=-1;
  char ch;

  clrscr();
  setVertices();
  setEdges();
  printGraph();
  do{
    scanf("%s",v);
    if(z ==-1)
    {
    for(int x=0;x<h;x++)
    {
      for(int xx=0;xx<3;xx++)
      {
         c[xx] = string[x][xx];
      }
       p = strcmp(c,v);
      if(p == 0)
      {
       blue[++z]= x;
       tmp[++w]= x;
       sb = z;
      }
     }
    }
    else
    {
    for(int x=0;x<h;x++)
    {
      for(int xx=0;xx<3;xx++)
      {
      c[xx] = string[x][xx];
      }
      p = strcmp(c,v);
      if(p == 0)
      {
         n= x;
         tmp[++w]= x;
         int q=0;
         for(int y=0;y<w;y++){
          if(n == tmp[y])
          ++q;
         }
         if(q > 0){
           printf("already coloured\n");
         }
         else{
         findEdges(n);
         printColour();
         }
      }
    }
    }

    printf("continue:(y/n)? ");
    ch= getch();
 }while(ch != 'n');

}

char printGraph()
{
  clrscr();
  printf("\nVERTICES ={");
  for(int i=0;i<h;i++)
  {
   printf(" %s ",string[i]);
  }
  printf("}\nchoose\n?");
return 0;
}// end of printgraph

char setVertices()
{
int i;
printf("how many? ");
scanf("%d",&h);
printf("vertices\n");
for(i=0;i<h;i++)
{
   scanf("%s",string[i]);
}
return 0;
}//end

int setEdges()
{
char opt,cc[3];
char tp;
int n,a=-1;

do{
   printf("set edges:\nvertex: ");
   scanf("%s",cc);
   for(int i=0;i<h;i++)
   {
  for(int j=0;j<3;j++)
  {
     c[j] = string[i][j];
  }

  a = strcmp(c,cc);
  if(a == 0)
  {
    n= i;
  }
   }
   int t=1,o=0;

   printf("edges:\n");
   do{
  scanf("%s",cc);
  for(int x=0;x<h;x++)
  {
    for(int y=0;y<3;y++)
    {
      c[y] = string[x][y];
    }
    a = strcmp(c,cc);
    if(a == 0)
    {
      m[n][++o]= x;

      ++t;
    }
  }
  printf("more(y/n)? ");
  tp= getch();
   }while(tp != 'n');
   r[n]= t;
   t=0;

   printf("\nset more?");
   opt= getch();
   printGraph();
}while(opt !='n');
return 0;
}//end of setEdges

int findEdges(int a)
{
   int nn,i,j,temp,k,t;
   k= r[a];
   for(j=0;j<=sb;j++)
   {
     temp = blue[j];
     for(i=1;i<k;i++)
     {
      nn = m[a][i];
      if(nn == temp)
      {
       ++cnt;
      }
     }
   }//blue

   for(j=0;j<=sg;j++)
   {
     temp = green[j];
     for(i=1;i<k;i++)
     {
        nn = m[a][i];
        if(nn == temp)
        {
      ++cnt1;
        }
     }
   }//green

   for(j=0;j<=sred;j++)
   {
     temp = red[j];
     for(i=1;i<k;i++)
     {
       nn = m[a][i];
       if(nn == temp)
       {
         ++cnt2;
       }
     }
   }//red

   for(j=0;j<=syellow;j++)
   {
     temp = yellow[j];
     for(i=1;i<k;i++)
     {
       nn = m[a][i];
       if(nn == temp)
       {
         ++cnt3;
       }
     }
   }//yellow

   setColour(a);
   cn = cnt;
   cn1 = cnt1;
   cn2 = cnt2;
   cn2 = cnt2;
   cn3 = cnt3;
   return 0;
}

int setColour(int b)
{
if(cn == cnt)
{
   blue[++sb] = b;
}
if(cn!=cnt && cn1==cnt1)
{
   green[++sg] = b;
}

if(cn!=cnt && cn1!=cnt1 && cn2 == cnt2)
{
   red[++sred] = b;
}

if(cn!=cnt && cn1!=cnt1 && cn2 != cnt2 && cn3 == cnt3)
{
   yellow[++syellow]= b;
}

return 0;
}//end of set colour

void printColour()
{
 int i,j,t;
 char d[4];

 printf("\ncolours\n\nblue = ");
 for(i=0;i<=sb;i++)
 {
  t = blue[i];
  for(j=0;j<3;j++)
  {
    c[j] = string[t][j];
  }
  printf(" %s",c);
 }

 printf("\ngreen = ");
 for(i=0;i<=sg;i++)
 {
  t = green[i];
  for(j=0;j<3;j++)
  {
    d[j] = string[t][j];
  }
     printf(" %s",d);
 }

 printf("\nred = ");
 for(i=0;i<=sred;i++)
 {
  t = red[i];
  for(j=0;j<3;j++)
  {
    c[j] = string[t][j];
  }
  printf(" %s",c);
 }

 printf("\nyellow = ");
 for(i=0;i<=syellow;i++)
 {
  t = yellow[i];
  for(j=0;j<3;j++)
  {
    c[j] = string[t][j];
  }
  printf(" %s",c);
 }

printf("\n\n");
}
