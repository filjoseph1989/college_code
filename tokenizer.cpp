/**
 * April 2, 2011
 * @return [description]
 */
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

char stack[100];
int top=-1;

int main(){
  clrscr();
  char c,temp;
  int result;
  FILE *p;
  p=fopen("token.txt","w+");
  while(!feof(p))
  fscanf(p,"%s",temp);
  fclose(p);

  A:
    c = getchar();

    if((result=isalpha(c))==8)
    goto D;
    if((result=isdigit(c))==2)
    goto B;
    if((result=isascii(c))==1)
    goto F;
    if(c == '@')
    goto exit;

  D:
    if(c != ' '||c!='\n')
   stack[++top]=c;
    c=' ';
    c = getchar();
    if((result=isalpha(c))==8)
    goto D;
    if((result=isdigit(c))==2)
    goto E;
    else goto C;

  E:
    if(c != ' '||c!='\n')
   stack[++top]=c;
    c=' ';
    c = getchar();
    if((result=isdigit(c))==2)
    goto E;
    if((result=isalpha(c))==8)
    goto D;
    else goto C;

  F:
    if(c != ' '||c!='\n')
   stack[++top]=c;
    c=' ';
    c = getchar();
    if((result=isdigit(c))==2)
    goto F;
    else goto C;


  B:
    if(c != ' '||c!='\n')
   stack[++top]=c;
    c=' ';
    c = getchar();
    goto C;

  C:
    if(top != -1){
   p= fopen("token.txt","a+");
   fprintf(p,"%s\n",stack);
   fclose(p);
   int temp=top;
   for(int i=temp; i>=0; i--)
   stack[i]=stack[i+1];
   top=-1;
    }
    if(c != ' '){
   if(c == '@')
       goto exit;
   if((result=isalpha(c))==8)
       goto D;
   if((result=isdigit(c))==2)
       goto F;
   if((result=isascii(c))==1)
       goto B;
    }

  exit:
  return 0;

}
