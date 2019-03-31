#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n=500;
	clrscr();
	textmode(2);
	textcolor(4);
	gotoxy(10,5);
	cprintf("I will saying some word!!!");
	gotoxy(50,50);
	printf("\n\n\nPress Enter...");
getch();
	for(i=0;i<=n;i++)
	{
		textmode(3);
		textcolor(1);
		textbackground(11);
		cprintf("\tI am so Sorry!!!");
		textcolor(4);
		textbackground(0);
		cprintf("\tSwt heart...");
	}
getch();

}
