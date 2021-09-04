#include<stdio.h>
#include"struct_head.h"
#include<stdbool.h>
#include<stdlib.h>
#include"event_mang.h"


void module1()
{
	printf("\n MODULE 1 IS INTRESTED IN THIS EVENT");
}
void module2()
{
	printf("\n MODULE 2 IS INTRESTED IN THIS EVENT");
}
void module3()
{
	printf("\n MODULE 3 IS INTRESTED IN THIS EVENT");

}
void module4()
{
	printf("\n MODULE 4 IS INTRESTED IN THIS EVENT");

}
void module5()
{
	printf("\n MODULE 5 IS INTRESTED IN THIS EVENT");
}
void module6()
{
	printf("\n MODULE 6 IS INTRESTED IN THIS EVENT");
}
void module7()
{
	printf("\n MODULE 7 IS INTRESTED IN THIS EVENT");

}
void module8()
{
	printf("\n MODULE 8 IS INTRESTED IN THIS EVENT");

}
void module9()
{
	printf("\n MODULE 9 IS INTRESTED IN THIS EVENT");
}
void module10()
{
	printf("\n MODULE 10 IS INTRESTED IN THIS EVENT");
}
void (*reg_ptr[])()={&module1,&module2,&module3,&module4,&module5,&module6,&module7,&module8,&module9,&module10};

void module_init()
{

	bool result=true;
	int ch;
	printf("\nEnter the no of modules: ");
	scanf("%d",&no_modules);
	if(no_modules<=10)
	{
		for(int i=0;i<no_modules;i++)
		{init_events=0;
			result = get_events(i,reg_ptr[i]);
			if(!result)
			{
				printf("\nDo you want to enter again for module %d.. Press 1 : ",i+1);
				scanf("%d",&ch);
				if(ch==1)
				{
					i--;

				}
				else
				{
					exit(0);
				}
			}

		}
	}
	else
	{
		printf("\nThere are no enough modules..!\nEXITING......");
		exit(0);
	}



}
