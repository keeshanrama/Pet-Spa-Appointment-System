//Keeshan Rama
//Lab 10
//* Tuesday 2:15 Section */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void request();
void cancel();
void list();
void letter();
void namewithPets();
int countLetter(char);
void priority();

char phonenumbers[5][20]={'\0','\0','\0','\0','\0'};
char calendar[5][20]={'\0','\0','\0','\0','\0'}; 
int numofpets[5]={0,0,0,0,0};
int ctr;
int number=0;
int flag=0;
int main() {
char ltr;	
	int selection;

	while (1)
	{
		printf(" Welcome to Stinky Pet Spa\n");
		printf(" Select an option:\n");
		printf(" 1 for scheduling\n");
		printf(" 2 for cancelling\n");
		printf(" 3 for calendar view\n");
		printf(" 4 to search for a guest in the system\n");
		printf(" 5 to search for guests with a certain number of pets\n");
		printf(" 6 to make a priority booking\n");
		printf(" 7 to search for occurences of a letter\n");
		printf(" & 9 to exit the reservation system\n");
	
		scanf("%d",&selection);
		switch(selection) {	
			case 1:
				request();
				break;		
			case 2:
				cancel();
				break;
			case 3: 
				list();
				break;
			case 4:
				letter();
				break;
			case 5:
				namewithPets();
				break;	
		
			case 6:	
				if(flag==0)
				{	priority();
					flag=1;
				}
				else
					printf("A priority booking has already been made\n");
					break;
			case 7:
				
				printf("Please enter a letter:\n");
				scanf(" %c",&ltr);
				number = countLetter(ltr);
				printf("There are %d occurences of %c.\n\n", number, ltr);
				break;
			case 9:
				printf("Program closed\n");
				return 1;
				break;
			default:
				printf("Bad Option\n");
				break;
								
		
		}
	}	
}
			

void request() {
char name[20];
int i;
char clientnumber[20];
int petnumber;
int j;
{
if (ctr==5)
	printf("We are currently full. Check back again later\n");
else
{ 
	printf("Who is the appointment for?");
        scanf("%s",name);
	for(j=0;j<5;j++)
	{	if(strcmp(calendar[j],name)==0)
		{	printf("This name is already registered\n");
			return;
		}	
	}	
				
		printf("How many pets are you bringing in?");
		scanf("%d",&petnumber);
		printf("Please provide a phone number");
		scanf("%s",clientnumber);      
          	for(i=0;i<5;i++)     
			if(calendar[i][0]=='\0')
                        {	strcpy(calendar[i],name);        
				ctr++;	
                                printf("You are scheduled for %d pm under %s\n",i+1,&name);	                                                       
                      		i++;
          	    		break;              		             		        
			}	
				
					
		for(i=0;i<5;i++)
	{		if(numofpets[i]==0)
			{	numofpets[i]=petnumber;
                                i++;
                                break;
                        }	
	}	
               	for(i=0;i<5;i++)
	{		if(phonenumbers[i][0]=='\0')
			{	strcpy(phonenumbers[i],clientnumber);
				i++;
				break;
			}
      	}	  

}       
}	
				                                 
}
        
		
void cancel() {int j;
int i;
int found;
int flag=0;
char name[20];
{
if(ctr==0)
	printf("All appointments are open\n");
else
{      	found=0;
        printf("Which appointment would you like to cancel?\n");
        scanf("%s",name);
       	for(i=0;i<5;i++)
        {
        	if(strcmp(calendar[i],name)==0)
                {       calendar[i][0]='\0';
                       	printf("This appointment has been cancelled and %s has been moved up to %d pm\n",calendar[i+1],i+1);
                        ctr--;
                        found=1;
                        for(j=i;j<ctr;j++)
			
                        {	printf("%s has been moved up to %d pm\n",calendar[j+1],j+1);
				strcpy(calendar[j],calendar[j+1]);
                           	strcpy(calendar[j+1],"\0");
        	                        calendar[j+1][0]='\0';
			}
			for(j=i;j<5;j++)
			{	strcpy(phonenumbers[j],phonenumbers[j+1]);
				strcpy(phonenumbers[j+1],"\0");
				phonenumbers[j+1][0]='\0';
                        }
		
			for(j=i;j<5;j++)
			{	numofpets[j]=numofpets[j+1];
				numofpets[j+1]=0;
			}	
		}	
       }
                if(strcmp(calendar[i],name)==1)
                	printf("This appointment is already open\n");



}
                              
}


}

void list() {
int i;	

if (ctr==0)
	printf("The schedule is empty\n");
else
					
	("Guest                           Number                          Pets\n"); 
	for(i=0;i<5;i++)
        {	if(calendar[i][0]=='\0')
                	printf("%d pm is free\n",i+1);
                else
                        printf("%d is filled by %s		%s				%d\n",i+1,calendar[i],phonenumbers[i],numofpets[i]);
        }	

 
}
                     
				


void letter() {
char initial;	
int i;
	{		
if(ctr==0)
	printf("No names in system\n");
else
{
        int flag=0;
        printf("Enter the first Initial of guest name\n");
        scanf(" %c",&initial);
        for(i=0;i<5;i++)
        {
        	if(calendar[i][0]==initial)
                {
                	printf("%s at %d pm\n", calendar[i],i+1);
                        flag=1;
                }

       	}
        if (flag=0)
        	printf("No name with the initial found");

}

	}	
}

void namewithPets() {
int petnumber;
int flag;
int i;
if(ctr==0)
	printf("No appoinments in schedule");

else
{
	flag=0;
	printf("How many pets does the guest have?");
	scanf("%d",&petnumber);
	for(i=0;i<5;i++)
	{	
		if(numofpets[i]==petnumber)
		{	
			printf("%s has %d pets coming in at %d\n",calendar[i],petnumber,i+1);
			flag=1;
		}
	}
	if(flag=0)
		printf("No names with that number of pets");
}				

				
}

void priority() {
int flag=0;
char name[20];
int j;
int petnumber;
char clientnumber[20];
int i;
	if(flag==1)
        {       printf("A priority booking has already been made");
                return;
        }
	else

		printf("Who is the appointment for?");
       	 	scanf("%s",name);
		for(j=0;j<5;j++)
       		{	if(strcmp(calendar[j],name)==0)
                	{       	printf("This name is already registered\n"); 
                        	return;
                	}	
        	}
		printf("How many pets are you bringing in?");
        	scanf("%d",&petnumber);
        	printf("Please provide a phone number");
       		scanf("%s",clientnumber);					
		printf("You are scheduled for %d pm under %s\n",1,&name);
		if(ctr==5)
		{	ctr--;
			printf("%s at %d pm was cancelled to make space\n",calendar[4],5);
		}
		for(j=ctr-1;j>=0;j--)
		{	strcpy(calendar[j+1],calendar[j]);
			printf("%s has been moved down to %d pm\n",calendar[j+1],j+2);
			strcpy(phonenumbers[j+1],phonenumbers[j]);
			numofpets[j+1]=numofpets[j];
	
		}	
		strcpy(calendar[0],name);
		strcpy(phonenumbers[0],clientnumber);
		numofpets[0]=petnumber;
		
	flag=1;
}
int countLetter(char letter) {
int number=0;
int i;
char*p=calendar[0];
if(ctr==0)
	printf("No appointments in schedule");
else
{	for(i=0;i<5;i++)
	{	p=calendar[i];
		while(*p!='\0')
		{	if(*p == letter)
			{	
				number++;
			}
		p++;		
		}
	
	}
}
return number;
}


