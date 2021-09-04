#include"struct_head.h"
#include<stdio.h>
#include"mod_event.h"
#include<stdbool.h>
#include<stdlib.h>
#include"event_mang.h"
struct modules
{       int mod_id;
	int events_intrested;
	void (*mod_ptr)();
	struct modules *next;
}*list=NULL,*p1,*p2;

void reg_event(int,int,void(*)());


bool get_events(int i,void (*call_fun)())
{       int event_per_module,event_id,ch;
	printf("\nEnter the no of events for module %d : ",i+1);
	scanf("%d",&event_per_module);
	if(event_per_module<=32)
	{
		for(int j=0;j<event_per_module;j++)
		{
			printf("\nEnter the event ID : ");
			scanf("%d",&event_id);
			if(event_id>=32)
			{
				printf("\nIT IS NOT A VALID EVENT ID ....!");
				printf("\nIf you want re enter the event.. press 1..: ");
				scanf("%d",&ch);
				if(ch==1)
				{
					j--;
				}
				else
				{
					exit(0);
				}

			}
			else
			{
				set_bit(init_events,event_id);

			}

		}
		reg_event(i+1,init_events,call_fun);
	}
	else
	{
		printf("\nIT IS NOT A VALID EVENT ID ....!");
		return false;

	}


	return true;
}
void reg_event(int module_id,int event_ids,void (*fun_ptrs)())
{
	p2= (struct modules*)malloc(sizeof(struct modules*));
	p2->mod_id=module_id;
	p2->events_intrested=event_ids;

	p2->mod_ptr=fun_ptrs;
	if(list==NULL)
	{
		list=p1=p2;
		return;
	}
	p1->next=p2;
	p1=p2;
	return;

}

void trigger_event(int req_event)
{


	struct modules *p;
	p=list;
	bool no_intrested=true;
	while(p)
	{ 
		if(get_bit(p->events_intrested,req_event)){
			p->mod_ptr();
			no_intrested=false; 
		}
		p=p->next;
	}
	if(no_intrested)
	{
		printf("\nNo modules intrested in this event..!\n");
	}



}
