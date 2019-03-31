/*Display contact in vcf file*/

#include<stdlib.h>
#include"stdio.h"
#include"conio.h"
#include"ctype.h"

int main()
{
	FILE *fp;
	char ch ;
	int num,count=0 ;
	fp=fopen("F:\\Contact\\gk.vcf","r");

	while((ch=fgetc(fp))!=EOF)
	{
		if((isdigit(ch)) == 1)
		{
			num=getw(fp);
			printf("%d",num);
			count ++;
		}
		if(count>=10 && count<=13)
			{
				printf("\n");
			}
		//printf("%c",ch);
	}
	fclose(fp);

}
