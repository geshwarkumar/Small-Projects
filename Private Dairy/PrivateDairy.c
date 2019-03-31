/*Program to implement menu driven formate
-Geshwar Kumar
-18/02/2016*/

/*INCLUDE HEADER FILES USED IN OUR PROGRAM*/

#include<stdio.h>        //FOR I/O OPERATION
#include<stdlib.h>       //FOR DOS COMMAND
#include<windows.h>    	//FOR GOTO STATEMENT
#include"sys/stat.h"	//MKDIR
#include"string.h"		//STRING HANDLING FUNCTION
#include"stddef.h"		//FOR NULL VALUE
#include"malloc.h"		//FOR MALLOC FUNCTION [MEMEORY ALLOCATION]

#define AUTHOR printf("AUTHOR : GESHWAR KUMAR\n")

/*GLOBLE VARIABLE DCLARATION*/
int choise,drive,sno=1;
char op,ch;
char path[_MAX_PATH];

/*UMASK DECLARATION*/
mode_t getumask()
{
	mode_t mask = umask(0);
	umask(mask);
	return mask;
}

/*FUNCTION FOR GOTO STATEMENT*/
void gotoxy(short x,short y)
{
 	COORD pos = {x,y};
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
/*FUNCTION DECLARATION*/
void ABOUT();	//FOR ABOUT
void CREATE(); //FOR CREATE NEW DIARY
/*MAIN FUNCTION*/
main(int argc,char *argv[])
{
	mode_t mask = getumask();	//OBJECT DECLARATION
	char newfolder[15],pd[]="Private Diary",file[15];	//STRING DECLARATION
	
	system("cls");	//FOR CLEAR SCREEN
	
	/*ODD LOOP*/
start:do       //LABEL 1
	{
	AUTHOR;
 	/*DISPLAY MENUES/OPTIONS USING PRINT FUNCTION*/
gotoxy(30,1);printf("~~~PRIVATE DIARY~~~");
        printf("\n\n ===MENU===\n\n");
		printf("1. Create Diary\n");
		printf("2. Update Diary\n");
		printf("3. Read Diary\n");
		printf("4. About\n");
		printf("5. Exit\n");
		printf("\n Enter your choise (1-5): ");scanf("%d",&choise);
		  /*SWITCH CASE*/
	       switch(choise)
	       {
				 case 1 :
				 		system("cls");
				 		AUTHOR;
					 printf("Available drive in this PC :");
					/*COUNT THE AVAILABLE DRIVE INTO THE PC*/
					for(drive=1;drive<=26;drive++)
					{
						/*CHECK DRIVE AVAILABLE OR NOT*/
						if(!_chdrive(drive))
						{
							printf("\n%d. %c:",sno,drive+64);
							sno += 1;
						}
					}
					/*INPUT DIRECTORY NAME BY USER*/
					printf("\nEnter the Drive which you want to save diary:");fflush(stdin); ch=getchar();
										
					for(drive=1;drive<=26;drive++)
					{
						if(!_chdrive(drive))
						{								
							if(drive+64 == toupper(ch))
							{
								if( _getdcwd( drive, path, _MAX_PATH ) != -1 )
								{
									system("cls");
									AUTHOR;
									printf("\n You Selected Drive :%s",path);
									printf("\n Enter the folder name(UPTO 15 CHARACTER) : ");retype: fflush(stdin); gets(newfolder);	//GIVES FOLDER NAME BY USER
									/*CHECK LENGTH OF NEWFOLDER NAME*/
									if((strlen(newfolder)) > 15)
									{
										printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nError!!! The length of folder name is not in range...\nPlease enter folder name within 25 character...\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
										printf("\n Retype folder name(UPTO 25 CHARACTER) : "); goto retype ;
									}								
									if(strcmp(newfolder,pd) == 0 || strcmp(newfolder,"private diary") == 0 || strcmp(newfolder,"privatediary") == 0 || strcmp(newfolder,"PrivateDiary") == 0 || strcmp(newfolder,"private_diary") == 0 || strcmp(newfolder,"Private_Diary") == 0)
									{
										int check = _mkdir(pd,mask);
										if(check == -1)
										{
											perror(argv[0]);
											if(chdir(pd) != -1)
											{
												
												CREATE(); 	//CALL CREATE FUNCTION FOR CREATE NEW FILE
											}

										}
										else
										{
											if(chdir(pd) != -1)
											{
												
												CREATE(); 	//CALL CREATE FUNCTION FOR CREATE NEW FILE
											}
										}
									}
									else
									{
										int check2 = _mkdir(newfolder,mask);
										if(check2 == -1)
										{
											perror(argv[0]); 
											if(chdir(newfolder) != -1)
											{
												CREATE(); 	//CALL CREATE FUNCTION FOR CREATE NEW FILE
											}
										}
										else
										{
											if(chdir(newfolder) != -1)
											{
												CREATE(); 	//CALL CREATE FUNCTION FOR CREATE NEW FILE
											}
										}
									}

								}
							}
						}
						
					}
				
					 break;
				 case 2 :
				 		system("cls");
				 		AUTHOR;
				 		
				 		printf("\n Enter the Diary Name : ");
				 		/*fflush(stdin);
				 		gets(file);
				 		if((_searchpath(file)) == 1)
				 		{
				 			printf("avaialble file...");	
						}*/
				 break;
				 case 3 :
				 		system("cls");
				 		AUTHOR;
				 break;
				 case 4 :
				 		system("cls");
				 	 	ABOUT();	//ABOUT FUNCTION CALLING
				break;
				case 5 : exit(0);
					break;
			    default :
					    printf("\n You are entered wrong choise...");
					    system("cls");
					    goto start;    //JUMP LABEL 1
	    }         //END SWITCH
	    printf("\n Do you want to cotinue (Y/N) : ");
message : fflush(stdin);scanf("%c",&op);      //LABEL 2
	   system("cls"); //FOR CLEAR SCREEN
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
system("pause");
//return 1;
}

/*FUNCTION DEFINITION*/
void ABOUT()
{
	printf("\n * ABOUT AUTHOR : Geshwar Kumar\n\t\t  MCA 2nd Sem\n\t\t  BIT,Durg(C.G.)");
	printf("\n * ABOUT APP :: This app used for safe our data from unauthorized person,\n\t\tIn this apps our text msg will be saved in encrypted form\n\t\tlike binary file");
	printf("\n\t FACILITIES : i) Create Encrypted file\n\t\t      ii) Read data from autharized person\n");
	printf("\t VERSION : version 1.0.0");
}


void CREATE()
{
	FILE *fp;
	void *file_name ,*data ,*cmd;
	char label[]="infilename";
	
	/*MEMEORY ALLOCATION*/
	/*file_name = (char *) malloc(sizeof(char));
	cmd = (char *) malloc(sizeof(char));
	data = (char *) malloc(sizeof(char));*/
	file_name = (char *) calloc(15,sizeof(char));
	cmd = (char *) calloc(50,sizeof(char));
	data = (char *) calloc(1000,sizeof(char));
	
	printf("\n Enter the Diary name(UPTO 15 CHARACTER) : ");
	infilename:fflush(stdin);gets(file_name);	//INPUT FILE NAME
	
	/*TO CHECK GIVEN FILE NAME EMPTY OR ALREADY EXIST OR NOT*/
	if(file_name == NULL)		//CHECK GIVEN FILE NAME EMPTY OR NOT
	{
		free(file_name);
		printf("\n Are you sure that you use default Diary name (y/n) :");
		fflush(stdin);scanf("%c",&ch);
		
		if(ch=='Y'||ch=='y')
		{
			file_name = "Diary" ;
			goto createfile;
		}
		else
		{
			printf("Re-type diary name:");goto infilename;
		}
	}
	else	//WHEN GIVES ANY FILE NAME BY USER
	{
		
		sprintf(cmd, "if exist %s goto %s", file_name,label);
		if((system(cmd)) == 1)	//CHECK FILE ALREADY EXIST
		{
			printf("Re-type diary name:");
			goto infilename;
		}
			
createfile:	fp = fopen(file_name,"wb");		//CREATE AND OPEN BINARY FILE
	system("cls");
	printf("\n Enter the containt of diary [NOTE : FOR EXIT PRESS DOUBLE ENTER]::\n");
	fflush(stdin);
	/*INPUT DATA*/
	while(strlen(gets(data))>0)
	{
	
		fflush(stdin);
		fwrite(&data,sizeof(data),1,fp);	//WRITE DATA INTO THE FILE
		fputs("\n",fp);
	
	}
	free(data);
	free(file_name);
	free(cmd);
	printf("\nDiary Successfully Created...");
	}fclose(fp);	//CLOSE THE FILE
}
