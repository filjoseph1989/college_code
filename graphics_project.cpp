/**
 * March 15, 2011
 */
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<dos.h>
#include<stdlib.h>

void *ball;     //declare siya og pointer

void image()    //nagbuhat og module
{
//ball
  setcolor(RED);  //nagset og color
  setfillstyle(SOLID_FILL,RED);  //images backgound images
  fillellipse(10,10,10,10); //nagbuhat og circle
  ball=malloc(imagesize(0,0,20,20));//Returns the number of bytes required to store a bit image
  getimage(0,0,20,20,ball);//saves a bit image of the specified region into memory
  cleardevice();//hinloan ang screen
}

int main(void)
{
 FILE *f;
 int gdriver = DETECT, gmode, errorcode;
 int temp,tempo;
 int l=0,r=0,t=0,b=0;
 int x=1,y=1;
 int s=0,key=0;
 int xstep=1,ystep=1;
 char c;

 initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
 errorcode = graphresult();
 if (errorcode != grOk){
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1);
 }
 int xx = getmaxx()/2;
 int yy = getmaxy()/2;

 do{

 /* draw the bar */
 image();
 setfillstyle(1, getmaxcolor());
 rectangle(50,400,600,80);// //left, top, right, bottom
 bar(50,400,600,80);
 outtextxy(xx-100,yy-30,"menu:");
 outtextxy(xx-100,yy-10,"Esc: kung paundang(stop)");
 outtextxy(xx-100,yy+0,"x: exit sa programme:");
 outtextxy(xx-100,yy+10,"r: replay sa animation");
 outtextxy(xx-100,yy+20,"a: para animation");
 outtextxy(xx-100,yy+30,"k: with keyboard controls");
 outtextxy(xx-100,yy+40,"d: delete file");
 outtextxy(xx-100,yy+60,"choose?:");

 c= getch();
 cleardevice();
 setfillstyle(1, getmaxcolor());
 rectangle(50,400,600,80);// //left, top, right, bottom
 bar(50,400,600,80);

 switch(c){
  case 'd':
  f= fopen("laststate.txt","w+");
  while(!feof(f))
      fscanf(f,"%i%i",&temp,&tempo);
  break;

  case 'r':
  f= fopen("laststate.txt","r+");
  while(!feof(f)){
      fscanf(f,"%i%i",&temp,&tempo);
      putimage(temp,tempo,ball,XOR_PUT);
      delay(20);
      putimage(temp,tempo,ball,XOR_PUT);
  }// while
  putimage(temp,tempo,ball,XOR_PUT);
  outtextxy(xx-100,yy+10,"mao ra to tanan I guess:");
  outtextxy(50,380,"Press Esc:");
  getch();
  break;

  case 'a':

   f= fopen("laststate.txt","a+");
   while(key != 27){
     while(!kbhit()){
        putimage(l,t,ball,XOR_PUT);
        delay(5);
        putimage(l,t,ball,XOR_PUT);
        fprintf(f,"%d %d\n",l,t);
        if(l>=590||l<=50){
       x *= -1;
       s=0;
       xstep=x*(random(4)+1);
       ystep=y*(random(3)+1);
       if(l<=50)
          l=50;
       else
          l=590;
        }
        if(t>=390||t<=80){
       y*=-1;
       s=0;
       ystep=y*(random(4)+1);
       xstep=x*(random(3)+1);
       if(t<=80)
          t=80;
       else
          t=390;
        }
        l += x+xstep;
        t += y+ystep;
        s++;
     }//while nested end
    key=getch();
   }
   fclose(f);
   break;

   case 'k':
   while(key != 27){
     while(!kbhit()){
        putimage(l,t,ball,XOR_PUT);
        delay(5);
        putimage(l,t,ball,XOR_PUT);

        if(l>=590||l<=50){
       if(l<=50)
          l=50;
       else
          l=590;
        }
        if(t>=390||t<=80){
       if(t<=80)
          t=80;
       else
          t=390;
        }
     }//while nested end
     key=getch();
     if(key == 72){//up
       t= t- 5;
       f= fopen("laststate.txt","a+");
       fprintf(f,"%d %d\n",l,t);
       fclose(f);
     }
     if(key == 80){//down
       t= t+ 5;
       f= fopen("laststate.txt","a+");
       fprintf(f,"%d %d\n",l,t);
       fclose(f);
     }
     if(key == 75){//left
       l= l- 5;
       f= fopen("laststate.txt","a+");
       fprintf(f,"%d %d\n",l,t);
       fclose(f);
     }
     if(key == 77){//up
       l= l+ 5;
       f= fopen("laststate.txt","a+");
       fprintf(f,"%d %d\n",l,t);
       fclose(f);
     }
   }
   break;
 }

 }while(c != 'x');
 /* clean up */
 closegraph();

 return 0;
}
