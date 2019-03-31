/*Program to implement menu driven formate
-Geshwar Kumar
-18/02/2016*/

/*INCLUDE HEADER FILES USED IN OUR PROGRAM*/
#include<stdio.h>
#include<stdlib.h>

/*MAIN FUNCTION*/
int main()
{
	/*VARIABLE DECLARATION USED IN PROGRAM*/
	int choise;
	char op;
	system("cls");

	/*ODD LOOP*/
start:do       //LABEL 1
	{

		  /*DISPLAY MENUES/OPTIONS USING PRINT FUNCTION*/
		  printf("\n 1 : For exit. ");
		  printf("\n Enter your choise : ");scanf("%d",&choise);
		  /*SWITCH CASE*/
	       switch(choise)
	       {
				 case 0 :break;
				 case 1 :
					exit(0);
					 //return 0;
					 break;
				 default :
					    printf("\n You are entered wrong choise...");
					    system("cls");
					    goto start;    //JUMP LABEL 1
	    }         //END SWITCH
	    printf("\n Do you want to cotinue (Y/N) : ");
message : fflush(stdin);scanf("%c",&op);      //LABEL 2
     }while(op == 'Y' || op == 'y');  //END ODD LOOP
     /*CHECK CONDITION FOR EXIT OR CONTINUE*/
     if(op == 'Y' || op == 'y')
     {
		  goto start;               //JUMP LABEL 1
     }
     else if(op == 'N' || op == 'n')
     {
		 //return 0;                  //EXIT PROGRAM
		 exit(0);
     }
     else
     {
		printf("\n Your entered wrong choise...\n For exit press /'N/' OR For continue press /'Y/' \n :: ");
		goto message;
     }
//return 1;
system("pause");
}


