
/*
The set of all string such that each block of five consecutive symbols
contains at least two(2) zero's.
Oct 10 2009
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

void main(void)
{
clrscr();
char *str;
int s,i=0;

  gotoxy(25,10);printf("Input a binary number: ");
  fflush(stdin);
  s=strlen(gets(str)); //mukuha ra ni og size sa input

  while(i < s)
  {
      if(str[i] == '0' || str[i] == '1')
      {
      q0:
          if(str[i] == '0')
          {
          i++;
          goto q5;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q1;
          }
          else if(i == s)
          {
          goto istate;
          }
      q1:
          if(str[i] == '0')
          {
          i++;
          goto q6;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q2;
          }
          else if(i == s)
          {
          goto istate;
          }
      q2:
          if(str[i] == '0')
          {
          i++;
          goto q7;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q3;
          }
          else
          {
          goto istate;
          }
      q3:
          if(str[i] == '0')
          {
          i++;
          goto q8;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q4;
          }
          else
          {
          goto istate;
          }

      q4:
          if(str[i] == '0')
          {
          i++;
          goto q18;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q17;
          }
          else
          {
          goto istate;
          }

      q5:
          if(str[i] == '0')
          {
          i++;
          goto q9;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q6;
          }
          else
          {
          goto istate;
          }

      q6:
          if(str[i] == '0')
          {
          i++;
          goto q10;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q7;
          }
          else
          {
          goto istate;
          }

      q7:
          if(str[i] == '0')
          {
          i++;
          goto q11;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q8;
          }
          else
          {
          goto istate;
          }

      q8:
          if(str[i] == '0')
          {
          i++;
          goto q16;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q4;
          }
          else
          {
          goto istate;
          }
      q9:
          if(str[i] == '0')
          {
          i++;
          goto q13;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q10;
          }
          else
          {
          goto istate;
          }

      q10:
          if(str[i] == '0')
          {
          i++;
          goto q15;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q14;
          }
          else
          {
          goto istate;
          }

      q11:
          if(str[i] == '0')
          {
          i++;
          goto q16;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q16;
          }
          else
          {
          goto istate;
          }

      q12:
          if(str[i] == '0')
          {
          i++;
          goto q16;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q16;
          }
          else
          {
          goto istate;
          }

      q13:
          if(str[i] == '0')
          {
          i++;
          goto q14;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q12;
          }
          else
          {
          goto istate;
          }

      q14:
          if(str[i] == '0')
          {
          i++;
          goto q16;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q16;
          }
          else
          {
          goto istate;
          }

      q15:
          if(str[i] == '0')
          {
          i++;
          goto q16;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q16;
          }
          else
          {
          goto istate;
          }

      q16:
          if(str[i] == '0')
          {
          i++;
          goto q5;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q1;
          }
          else if(i == s)
          {
          i++;
          gotoxy(25,12);printf("<< input accepted >>");
          }

      q17:
          if(str[i] == '0')
          {
          i++;
          goto q19;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q4;
          }
          else
          {
          goto istate;
          }

      q18:
          if(str[i] == '0')
          {
          i++;
          goto q4;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q19;
          }
          else
          {
          goto istate;
          }

      q19:
          if(str[i] == '0')
          {
          i++;
          goto q17;
          }
          else if(str[i] == '1')
          {
          i++;
          goto q18;
          }
          else
          {
          goto istate;
          }

      istate:
          if(i == s)
          {
          i++;
          gotoxy(25,12);printf("<< input unaccepted >>");
          goto exit;
          }
          }
          else
          {
          gotoxy(25,12);
          textcolor(RED+BLINK);
          cprintf("ALERT!!!\n\tinvalid input!!!try again...;-(");
          goto exit;
          }
  }
exit:
  while((str[i] =getch()) != '\r');
}

==================palindrome=========================
#include<stdio.h>
#include<string.h>
#define size 26

void main()
{
char strsrc[size];
char strtmp[size];

clrscr();
printf("\n Enter String:= "); gets(strsrc);

strcpy(strtmp,strsrc);
strrev(strtmp);

if(strcmp(strsrc,strtmp)==0)
printf("\n Entered string \"%s\" ispalindrome",strsrc);
else
printf("\n Entered string \"%s\" is not
palindrome",strsrc);
getch();
}
