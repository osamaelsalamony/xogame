
#include<stdio.h>
#include<stdlib.h>
#include"Functions.h"
#include"STD_TYPES.h"
int main()
{
   uint32 mode ;
   sint8 res=-1;
   uint8 arr[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '},name1[15],name2[15];
   system("cls");
   printf("\t\t\t\t****Welcome to Tic Tac Toe Game!****\n");
   while(1)
   {   
    printf("\t\t\t\t     For multi players press \"1\"\n");
	printf("\t\t\t\t     For single player press \"2\" \n");

    scanf ("%d",&mode);
    if (mode==1)
    {
		
	   while (1)
       {
         if (res==0)
         {
           printf("***GAME ENDED***");
           break;
         }	
		 system("cls");
		printf("Please enter player one name : ");
		scanf("%s",name1);
		system("cls");
		printf("Please enter player two name : ");
		scanf("%s",name2);
         res=mod1( arr,name1,name2 );
        }
		break;
	   
    }
	 else if (mode==2)
	 {
		while (1)
       {
         if (res==0)
         {
           printf("***GAME ENDED***");
           break;
         }		   
         res=mod2( arr,name1 );
        }
		break;
	 }
	 else 
	{
		system("cls");
		printf("INVALID INPUT!!\n");
	}
   }
}