/*Function for calculate age
-Geshwar Kumar
-18/05/2016 - 06/06/2016*/

#include<stdio.h>
#include<stdlib.h>

/*enum months			/*ENUM DATA TYPE DECLARATION FOR MONTHS*/
/*{
	Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec
};*/

int main()	/*MAIN FUNCTION START*/
{
	int dd,mm,yyyy,cdd,cmm,cyyyy,month,age,day,b_dd; /*b_dd = BORROW DAY*/
	//enum months sm; /*sm = SELECTED MONTH*/
	system("cls");
	printf("\n Enter current date:");/*INPUT CURRENT DATE*/
	printf("\n\tDay(1 to 31) :");reincdd : scanf("%d",&cdd);
	if(cdd >= 1 && cdd <= 31)
	{
		printf("\tMonth(1 to 12) :");reincmm : scanf("%d",&cmm);
		if(cmm >= 1 && cmm <= 12)
		{
			printf("\tYear(1900 to 2050) :");reincyy : scanf("%d",&cyyyy);
			if(cyyyy >= 1900 && cyyyy <= 2050)
			{
				goto DOB;
			}
			else
			{
				printf("Please reenter year(1900 to 2050) : ");
				goto reincyy ;
			}
		}
		else
		{
			printf("Please reenter month(1 to 12) : ");
			goto reincmm ;
		}
	}
	else
	{
		printf("Please reenter day(1 to 31) : ");
		goto reincdd ;
	}


	/*INPUT DATE OF BIRTH*/
DOB : printf("\n Enter birth date:");
	printf("\n\tDay(1 to 31) :");reindd : scanf("%d",&dd);
	if(dd >= 1 && dd <= 31)
	{
		printf("\tMonth(1 to 12) :");reinmm : scanf("%d",&mm);
		if(mm >= 1 && mm <= 12)
		{
			printf("\tYear(1900 to 2050) :");reinyy : scanf("%d",&yyyy);
			if(yyyy >= 1900 && yyyy <= 2050)
			{	
				goto calculate;
			}
			else
			{
				printf("Please re-enter year(1900 to 2050) : ");
				goto reinyy ;
			}
		}	
		else
		{
			printf("Please reenter month(1 to 12) : ");
			goto reinmm ;
		}
	}
	else
	{
		printf("Please reenter day(1 to 31) : ");
		goto reindd ;
	}
calculate : //sm = cmm ;
	/*FIND DAY ACCORDING TO MONTHS*/
	switch(cmm)
	{
		case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
			b_dd = 31 ;
			break;
		case 4 : case 6 : case 9 : case 11 :
			b_dd = 30 ;
			break;
		case 2 :
			/*FOR FEBRUARY*/
			if(cyyyy % 400 == 0 || cyyyy % 4 == 0)
			{
				b_dd = 29 ;
			}
			else if(cyyyy % 100 == 0 || cyyyy % 400 != 0 || cyyyy % 4 != 0)
			{
				b_dd = 28 ;
			}
			break;
	}/*END SWITCH*/
	/*CALCULTAE AGE*/
	if (dd == cdd && mm == cmm)
	{
		day = cdd - dd ;
		month = cmm - mm ;
		age = cyyyy - yyyy ;
	}
	else if(dd > cdd && mm == cmm)
	{
		day = ( cdd + b_dd ) - dd ;
		cmm -= 1 ;				//REMAINING CURRENT MONTH	
		month = (cmm + 12) - mm ;
		age = (cyyyy - 1) - yyyy ;
	}
	else if(dd < cdd && mm == cmm)
	{
		day = cdd - dd ;
		month = cmm - mm ;
		age = cyyyy - yyyy ;
	}
	else if(dd ==cdd && mm < cmm)
	{
		day = cdd - dd ;
		month = cmm - mm ;
		age = cyyyy - yyyy ;
	}
	else if(dd == cdd && mm > cmm)
	{
		day = cdd - dd ;
		month = (cmm + 12) - mm ;
		age = (cyyyy - 1) - yyyy ;
	}
	else if(dd != cdd && mm!= cmm)
	{
		if((cdd == 01 && cmm == 01) || (dd > cdd && mm > cmm))
		{
			day = (cdd + b_dd) - dd ;
			cmm -= 1 ;
			month = (cmm + 12) - mm ;
			age = (cyyyy - 1) - yyyy ;
		}
		else
		{
			day = cdd - dd ;
			month = cmm - mm ;
			age = cyyyy - yyyy ;
		}	
	}
	/*OUTPUT CALCULATED AGE DETAILS*/
	printf("\nCalculated age details are :>>");
	printf("\n***************************************************\n");
	printf("\n You are '%d' years, '%d' months & '%d' days old.",age,month,day);
	/*printf("\n\t\t Age : %d Year ",age);
	printf("\n\t\t Month : %d Month",month);
	printf("\n\t\t Day : %d Day`s",day);*/
	printf("\n\n***************************************************\n");
//system("pause");
}
