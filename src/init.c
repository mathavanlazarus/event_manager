#include<stdio.h>
#include"mod_event.h"
#include"event_mang.h"
#include"struct_head.h"
void main()
{	int event_ids,choice;
	module_init();
	do
	{
		printf("\nEnter the event to show : ");
         	scanf("%d",&event_ids);
		trigger_event(event_ids);
		printf("\nDo you want to continue press 1 : ");
		scanf("%d",&choice);

	}while(choice == 1);
	

}
