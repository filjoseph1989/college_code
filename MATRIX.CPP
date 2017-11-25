#include<stdio.h>
#include<conio.h>
int setA[15][15];
int setB[15][15];
int mat_pro[15][15];
int mat_p[15][15];
int rowA=0,colB=0;

void main(){
     int rA=0,cA=0;
     int i=0,j=0;
     clrscr();
     printf("matrix operation \"taman ra sa 15X15 ha!!!! bantay ka!\"\n\n\n");
     printf("put a size of matrix (column and row):");
     scanf("%d%d",&cA,&rA);
     rowA=rA;
     for(i=0;i<cA;i++)
	for(j=0;j<rA;j++)
	   scanf("%d",&setA[j][i]);

     int rB=0,cB=0;
     clrscr();
     printf("put a size of matrix2 (column and row):");
     scanf("%d%d",&cB,&rB);
     colB=cB;
     for(i=0;i<cB;i++)
	for(j=0;j<rB;j++)
	   scanf("%d",&setB[j][i]);

     clrscr();
     printf("matrix 1 (%d x %d)\n",cA,rA);
     for(i=0;i<cA;i++){
	for(j=0;j<rA;j++){
	   printf("%d ",setA[j][i]);
	   if(j==rA-1)
	   printf("\n");
	}
     }
     printf("\n\nmatrix 2 (%d x %d)\n",cB,rB);
     for(i=0;i<cB;i++){
	for(j=0;j<rB;j++){
	   printf("%d ",setB[j][i]);
	   if(j==rB-1)
	   printf("\n");
	}
     }

     printf("\n\nAddition of matrix1 and matrix2\n");
     if(rowA==colB){
       for(i=0;i<cB;i++){
	 for(j=0;j<rB;j++){
	    mat_pro[j][i]=setA[j][i]+setB[j][i];
	    printf("%d ",mat_pro[j][i]);
	    if(j==rB-1)
	       printf("\n");
	 }
       }
     }
     j = i = 0;
     printf("\n\nMultiplication of matrix1 and matrix2\n");
     int m=0,n=0,temp=0;
     if(rowA==colB){
     for(m=0;m<rowA;m++){
	 for(n=0;n<colB;n++){
	     for(int k=0;k<colB;k++)
	     {
		temp= setA[j+k][i+m]* setB[j+n][i+k]+temp;
	     }
	     mat_p[n][m]=temp;
	     temp=0;
	     printf("%d ",mat_p[n][m]);
	     if(n==rowA-1)
	     printf("\n");
	 }
     }
     }

getch();

}

