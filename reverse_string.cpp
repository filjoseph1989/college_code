/**
 * @date Aug 09, 2008
 */
/*without using standard functions*/

#include<stdio.h>

#include<string.h>

#include <conio.h>

main()

{

char s[40],c,r[40];

int i,j,p;

clrscr();

printf("Enter the string:");

gets(s);

for(i=0;s[i]!='';i++);

j=i;

printf("The original string is:%s",s);

printf("nThe reverse string is:");

for(p=j-1,i=0;p>=0;p--,i++)

r[i]=s[p];

r[i]='';

printf("The reverse string is:%s",r);

getch();

}

2.)
#include <stdio.h>
#include <string.h>

int main(void)
{
char str1[] = "Pointers are fun and hard to use";
char str2[80], *p1, *p2;

/* make p point to end of str1 */
p1 = str1 + strlen(str1) - 1;

p2 = str2;

while(p1 >= str1)
*p2++ = *p1--;

/* null terminate str2 */
*p2 = '\0';

printf("%s %s", str1, str2);

return 0;
}
