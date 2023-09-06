#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include"Functions.h"
#include"STD_TYPES.h"
    /* Function to print the board */    
void print_board(uint8 arr[])
{
     printf("     |     |     \n",arr[6],arr[7],arr[8]);
	 printf("  %c  |  %c  |  %c  \n");
	 printf("     |     |     \n");
     printf("-----+-----+-----\n");
     printf("     |     |     \n",arr[3],arr[4],arr[5]);
	 printf("  %c  |  %c  |  %c  \n");
	 printf("     |     |     \n");
     printf("-----+-----+-----\n");
     printf("     |     |     \n",arr[0],arr[1],arr[2]);
	 printf("  %c  |  %c  |  %c  \n");
	 printf("     |     |     \n");
}


        /* Function to check if player one is winner or not */
uint8 player1_check(uint8 arr[])       
{
    if (arr[0]==arr[1]&&arr[1]==arr[2]&&arr[2]=='X')
     {
        return 1;
     }
     else if((arr[3]==arr[4])&&(arr[4]==arr[5])&&(arr[5]=='X'))
     {     
        return 1;
     }
     else if (arr[6]==arr[7]&&arr[7]==arr[8]&&arr[8]=='X')
     {
        return 1;
     }
     else if (arr[0]==arr[4]&&arr[4]==arr[8]&&arr[8]=='X')
     {
        return 1;
     }
     else if (arr[2]==arr[4]&&arr[4]==arr[6]&&arr[6]=='X')
     {
        return 1;
     }
     else if (arr[0]==arr[3]&&arr[3]==arr[6]&&arr[6]=='X')
     {
        return 1;
     }
     else if (arr[1]==arr[4]&&arr[4]==arr[7]&&arr[7]=='X')
     {
        return 1;
     }
     else if (arr[2]==arr[5]&&arr[5]==arr[8]&&arr[8]=='X')
     {
        return 1;
     }
}

     /* Function to check if player two is winner or not */
 
uint8 player2_check(uint8 arr[])
{
    if (arr[0]==arr[1]&&arr[1]==arr[2]&&arr[2]=='O')
     {
        return 2;
     }
     else if((arr[3]==arr[4])&&(arr[4]==arr[5])&&(arr[5]=='O'))
     {
        return 2;
        
     }
     else if (arr[6]==arr[7]&&arr[7]==arr[8]&&arr[8]=='O')
     {
        return 2;
     }
     else if (arr[0]==arr[4]&&arr[4]==arr[8]&&arr[8]=='O')
     {
        return 2;
     }
     else if (arr[2]==arr[4]&&arr[4]==arr[6]&&arr[6]=='O')
     {
        return 2;
     }
     else if (arr[0]==arr[3]&&arr[3]==arr[6]&&arr[6]=='O')
     {
        return 2;
     }
     else if (arr[1]==arr[4]&&arr[4]==arr[7]&&arr[7]=='O')
     {
        return 2;
     }
     else if (arr[2]==arr[5]&&arr[5]==arr[8]&&arr[8]=='O')
     {
        return 2;
     }
}


   /* Function for multiplayers mode */
uint8 mod1(uint8 arrc[], uint8 name1[],uint8 name2[] )
{
    uint32	num=0,ret,val=0;
    uint8 j=0,i=0, arr[9]={0};
    for (i=0;i<9;i++)
    {
        arr[i]=arrc[i];
    }
    while(1)
    {
     system("cls");
     print_board(arr);
     val=player2_check( arr );
     if (val==2)
     {
        printf("%s is the winner\nTo play again press 1, To exit press 0\n",name2);
        scanf("%d",&ret);
        return ret;
     }
     else
     {
       printf("%s please enter a number,To exit press 0\n",name1);
       scanf("%d",&num);
	   while(num>9||num<0)
		{	
			system("cls");
			printf("Invalid input, Enter a number 1:9\n") ; 
			print_board(arr);
			printf("%s please enter a number\n ",name1);
			scanf("%d",&num);
			
		}
       if (num==0)
       {
         return 0;
       }
       j++;
       while((arr[num-1]=='X')||(arr[num-1]=='O'))
       {
        
        system("cls");
		printf("Choose correct plaese, This place is not empty\n");
        print_board(arr);
        printf("%s please enter a number ,To exit press \"0\"\n",name1);
        scanf("%d",&num);
		while(num>9||num<0)
		{	
			system("cls");
			printf("Invalid input, Enter a number 1:9\n") ; 
			print_board(arr);
			printf("%s please enter a number\n ",name2);
			scanf("%d",&num);
			
		}
		if (num==0)
        {
         return 0;
        }
       }
     arr[num-1]='X';
     system("cls");
     print_board(arr);
     val=player1_check(arr);
     if (val==1)
     {
        printf("%s is the winner\nTo play again press 1, To exit press 0\n",name1);
        scanf("%d",&ret);
        return ret;
     }
     else
     {
        if (j==5)
        {
			
            arr[num-1]='X';
            system("cls");
			printf("Game ended with draw !!\n");
            print_board(arr);
            printf("To play again press 1, To exit press 0\n");
            scanf("%d",&ret);
			return ret;
        }
        printf("%s please enter a number, To exit press 0\n",name2);
        scanf("%d",&num);
		while(num>9||num<0)
		{	
			system("cls");
			printf("Invalid input, Enter a number 1:9\n") ; 
			print_board(arr);
			printf("%s please enter a number\n ",name2);
			scanf("%d",&num);
			
		}
        if (num==0)
        {
         return 0;
        }
        while((arr[num-1]=='X')||(arr[num-1]=='O'))
       {
       
        system("cls");
		printf("Choose correct please, This place is not empty\n");
        print_board(arr);
        printf("%s please enter a number , To exit press \"0\"\n ",name2);
        scanf("%d",&num);
		while(num>9||num<0)
		{	
			system("cls");
			printf("Invalid input, Enter a number 1:9\n") ; 
			print_board(arr);
			printf("%s please enter a number\n ",name2);
			scanf("%d",&num);
			
		}
		if (num==0)
        {
         return 0;
        }
       }
      arr[num-1]='O'; 
    }

   }
  }
}
  /*Function for single player mode*/
uint8 mod2(uint8 arr2[],uint8 name1[])
{
    uint32 num=0,ret,val=0;
    uint8 j=0,i=0, arr[9]={0};
    for (i=0;i<9;i++)
    {
        arr[i]=arr2[i];
    }
	system("cls");
	printf("Please enter your name : ");
	scanf("%s",name1);
    while(1)
    {
     system("cls");
     print_board(arr);
     val=player2_check( arr );
     if (val==2)
     {
        printf("Computer is the winner, You lost \nTo play again press 1, To exit press 0\n");
        scanf("%d",&ret);
        return ret;
     }
     else
     {
       printf(" %s It's your turn please enter a number, To exit press 0\n",name1);
       scanf("%d",&num);
	   while(num>9||num<0)
		{	
			system("cls");
			printf("Invalid input, Enter a number 1:9\n") ; 
			print_board(arr);
			printf("%s please enter a number\n ",name1);
			scanf("%d",&num);
			
		}
       if (num==0)
       {
         return 0;
       }
       j++;
       while((arr[num-1]=='X')||(arr[num-1]=='O'))
       {
        
        system("cls");
		printf("Choose correct plaese, This place is not empty\n");
        print_board(arr);
        printf("%s It's your turn, Please enter a number To exit press 0\n",name1);
        scanf("%d",&num);
		while(num>9||num<0)
		{	
			system("cls");
			printf("Invalid input, Enter a number 1:9\n") ; 
			print_board(arr);
			printf("%s please enter a number\n ",name1);
			scanf("%d",&num);
			
		}
       if (num==0)
       {
         return 0;
       }
       }
     arr[num-1]='X';
     system("cls");
     print_board(arr);
     val=player1_check(arr);
     if (val==1)
     {
        printf("%s You are the winner\nTo play again press 1, To exit press 0\n",name1);
        scanf("%d",&ret);
        return ret;
     }
     else
     {
        if (j==5)
        {
			
            arr[num-1]='X';
            system("cls");
            print_board(arr);
			printf("Game ended with draw !!\n");
            printf("To play again press 1, To exit press 0\n");
            scanf("%d",&ret);
			return ret;
        }
        while((arr[num-1]=='X')||(arr[num-1]=='O'))
        {
           srand(time(NULL));
           num = rand() % 9; 
           num++;
           
        }
        arr[num-1]='O';
        system("cls");
        print_board(arr);   
	}

   }
  }
}