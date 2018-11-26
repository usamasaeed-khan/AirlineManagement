#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define ENTER 13
#define BKSPC 8

//                          ENTER THE PASSWORD : emirates

void information();
void reservation();
void printticket(char [],char [],int,char,int,float);
void schedule();
void seat_avaliblity(char,int);
void seat_check();
void information_specfic(int);
int amount_per_person(char,int,int);
void cancellation();
main()
{
	system("color C");
	information();
}
void information()
{
	char ch,pass[10];
	char emirates[10],choice;
	int i=0,j,n=1,see=0;
	printf("\t\t|**\t---------------------------\t**|\n");
	printf("\t\t|**\t***************************\t**|\n");
	printf("\t\t|**\t                           \t**|\n");
	printf("\t\t|**\t                           \t**|\n");	
	printf("\t\t|**\t---------------------------\t**|\n\n");
	printf("\t\t|**\tWELCOME TO EMIRATES AIRLINE\t**|\n\n");
	printf("\t\t|**\t---------------------------\t**|\n");
	printf("\t\t|**\t                           \t**|\n");
	printf("\t\t|**\t                           \t**|\n");
	printf("\t\t|**\t***************************\t**|\n");
	printf("\t\t|**\t---------------------------\t**|\n");
    again:
	printf("\nREQUIRED ADMIN PASSWORD:");
	i=0;
    while(1)
 {
    ch = getch();
    pass[i] = ch;
    if(ch==BKSPC)
    {
        continue;
	}
	else if (ch==ENTER)
	{
	   break;
	}
	printf("*");
	i++;
}
pass[i] = '\0';
	if(strcmp("emirates",pass)==0)
	{
		system("cls");
		printf("\n\t\tAccess Granted!!!!");
		printf("\nDEAR CUSTOMER PLEASE TELL WHAT YOU WANT TO KNOW:\n");
	start:
//	system("cls");
	printf("\n1.Reserve a Ticket");
	printf("\n2.View all Planes & Fares");
	printf("\n3.Cancel Reservation");
	printf("\n4.Seat Availiblity");
	printf("\n5.Exit\n:");
	scanf(" %c",&choice);
	switch(choice)
	{
		case '1':
			reservation();
			goto start;
		case '2':
			schedule();
			char p;
			printf("\nYou to goto Main Index(y/n) :");
			scanf(" %c",&p);
			if(p=='y'){
				goto start;
			}
			else if(p == 'n')
			break;
		case '3':
			cancellation();
			printf("\nPress any to return to Main Menu");
			getch();
			goto start;
			case '4':
				seat_check();
				system("cls");
				printf("\nEnter the any letter to return back in main :");
				getch();
				goto start;
			break;
			case '5':
				printf("\nThankyou for visiting our system");
				return;
		default:
			printf("\nwrong choice");
			goto start;
			break;
}
}
	else
	{
		printf("\nAccess Denied!!!!\n");
		goto again;
	}
}
void reservation()
{
	char telephone[15],name[50],sirname[50],CNIC[100];
	int seat_num,fares,plane_code;
	FILE *fp;
	fp=fopen("information.txt","a");
	system("cls");
	printf("\nENTER CUSTOMER PERSNAL INFORAMTION:");
	printf("\nFull Name :");
	fflush(stdin);
	gets(name);
	printf("\nSir Name :");
	fflush(stdin);
	gets(sirname);
	printf("\nCNIC # :");
	fflush(stdin);
	gets(CNIC);
	printf("\nContact Number :");
	fflush(stdin);
	gets(telephone);
	start2:
	schedule();
	start1:
	printf("\nPlane Code :");
	scanf("%d",&plane_code);
	if(plane_code >= 1001 && plane_code <=1020)
	{
//	printf("\nEnter number of Seat you want to avail:");
//	scanf("%d",&seat_num);
    char opt;
    printf("\nPress 1 for business & 2 for economy:\n");
    scanf(" %c",&opt);
	int seats;
	printf("\nEnter the number of seats you want :");
	scanf("%d",&seats);
	seat_avaliblity(opt,seats);
	if(seats==0)
	{
		printf("\nPress any key to check the schedule for flights:");
		getch();
		goto start2;
	}
	int fares;
	fares=amount_per_person(opt,plane_code,seats);
	printticket(name,CNIC,plane_code,opt,seats,fares);
	}
	else
	{
	printf("\nPlane Code is Invalid Try again :");
	goto start1;
	} 
	printf("\n\nTo Confirm the Ticket press 1 or any key for not confirm :");
	start3:
	char confirm;
	scanf(" %c",&confirm);
	if(confirm == '1')
	{
		fprintf(fp,"%s\t\t\t%d\t\t%d\n",name,plane_code,fares);
		printf("\nReservation Done\nPress any key to go back to Main menu :");
	}
	else
	{
		if(confirm!='1')
		{
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu :");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start3;
		}
	}
	fclose(fp);
	getch();
}
void schedule()
{
	int n,opt;
	printf("\n1.Domestic Timing & Fares\n2.International Timing & Fares");
	input:
	printf("\nEnter :");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("\t\tWelcome To Domestic Booking\n");
			start3:
			printf("1.Business Class\n2.Economy Class\n:");
			scanf("%d",&opt);
			if(opt == 1)
			{
				system("cls");
				printf("\t\tBUSINESS CLASS");	
	            printf("\nPlane.Code\t\t\tDestinations\t\tFares\tDeparture Time\n");
	            printf("\nEK-1001\t\tKarachi to Islamabad\t\t\tRs6000\t\t08:00");
	            printf("\nEK-1002\t\tIslamabad To Karachi\t\t\tRs6000\t\t09:15");
	            printf("\nEK-1003\t\tKarachi To Lahore\t\t\tRs5500\t\t09:55");
	            printf("\nEK-1004\t\tLahore To Karachi\t\t\tRs5500\t\t11:00");
	            printf("\nEK-1005\t\tKarachi To Multan\t\t\tRs5000\t\t13:00");
	            printf("\nEK-1006\t\tMultan To Karachi\t\t\tRs5000\t\t15:00");
                printf("\nEK-1007\t\tKarachi To Faisalabad\t\t\tRs4500\t\t18:00");	
                printf("\nEK-1008\t\tFaisalabad To Karachi\t\t\tRs4500\t\t19:45");
                printf("\nEK-1009\t\tKarachi To Peshawar\t\t\tRs7000\t\t22:45");
                printf("\nEK-1010\t\tPeshawar To Karachi\t\t\tRs7000\t\t00:15\n");
			}
			else if(opt == 2)
			{
			    system("cls");	
			    printf("\t\tECONOMY CLASS");	
	            printf("\nPlane.Code\t\t\tDestinations\t\tFares\tDeparture Time\n");
	            printf("\nEK-1001\t\tKarachi to Islamabad\t\t\tRs5000\t\t08:00");
	            printf("\nEK-1002\t\tIslamabad To Karachi\t\t\tRs5000\t\t09:15");
	            printf("\nEK-1003\t\tKarachi To Lahore\t\t\tRs4500\t\t09:55");
	            printf("\nEK-1004\t\tLahore To Karachi\t\t\tRs4500\t\t11:00");
	            printf("\nEK-1005\t\tKarachi To Multan\t\t\tRs4000\t\t13:00");
	            printf("\nEK-1006\t\tMultan To Karachi\t\t\tRs4000\t\t15:00");
                printf("\nEK-1007\t\tKarachi To Faisalabad\t\t\tRs3500\t\t18:00");	
                printf("\nEK-1008\t\tFaisalabad To Karachi\t\t\tRs3500\t\t19:45");
                printf("\nEK-1009\t\tKarachi To Peshawar\t\t\tRs6000\t\t22:45");
                printf("\nEK-1010\t\tPeshawar To Karachi\t\t\tRs6000\t\t00:15\n");	
			}
			else
			{
			    system("cls");
				printf("Invalid Option\n");
				goto start3;
			}
			break;
			case 2:
				printf("\t\tWelcome To International Booking\n");
				start2:
			    printf("1.Business Class\n2.Economy Class\n:");
			    scanf("%d",&opt);
			    if(opt== 1)
				{
					system("cls");
					printf("\t\tBUSINESS CLASS");	
	                printf("\nPlane.Code\t\t\tDestinations\t\tFares\tDeparture Time\n");
	                printf("\nEK-1011\t\tKarachi to Dubai\t\t\tRs18000\t\t08:20");
                	printf("\nEK-1012\t\tDubai To Karachi\t\t\tRs18000\t\t09:30");
	                printf("\nEK-1013\t\tKarachi To Muscat\t\t\tRs13000t\t10:00");
	                printf("\nEK-1014\t\tMuscat To Karachi\t\t\tRs13000\t\t11:10");
	                printf("\nEK-1015\t\tKarachi To London\t\t\tRs46000\t\t13:40");
	                printf("\nEK-1016\t\tLondon To Karachi\t\t\tRs46000\t\t15:15");
                    printf("\nEK-1017\t\tKarachi To Toronto\t\t\tRs66000\t\t17:50");	
                    printf("\nEK-1018\t\tToronto To Karachi\t\t\tRs66000\t\t19:55");
                    printf("\nEK-1019\t\tKarachi To Newyork\t\t\tRs72000\t\t23:05");
                    printf("\nEK-1020\t\tNewyork To Karachi\t\t\tRs72000\t\t00:30\n");
			    }
				else if(opt== 2)
				{
					system("cls");
					printf("\t\tECONOMY CLASS");	
	                printf("\nPlane.Code\t\t\tDestinations\t\tFares\tDeparture Time\n");
	                printf("\nEK-1011\t\tKarachi to Dubai\t\t\tRs17000\t\t08:20");
	                printf("\nEK-1012\t\tDubai To Karachi\t\t\tRs16000\t\t09:30");
            	    printf("\nEK-1013\t\tKarachi To Muscat\t\t\tRs12000t\t10:00");
	                printf("\nEK-1014\t\tMuscat To Karachi\t\t\tRs12000\t\t11:10");
					printf("\nEK-1015\t\tKarachi To London\t\t\tRs45000\t\t13:40");
	                printf("\nEK-1016\t\tLondon To Karachi\t\t\tRs45000\t\t15:15");
                    printf("\nEK-1017\t\tKarachi To Toronto\t\t\tRs65000\t\t17:50");	
                    printf("\nEK-1018\t\tToronto To Karachi\t\t\tRs65000\t\t19:55");
                    printf("\nEK-1019\t\tKarachi To Newyork\t\t\tRs70000\t\t23:05");
                    printf("\nEK-1020\t\tNewyork To Karachi\t\t\tRs70000\t\t00:30\n");
			    }
				else
				{
				    system("cls");
				    printf("Invalid Option\n");
				    goto start2;
			    }
				break;
				default:
					printf("\nInvalid Input choice!!");
					goto input;
 	}
}
int amount_per_person(char decision,int plane_code,int seat_num)
{	
//	printf("\ny.Business Class\nn.Economy Class\n:");
//	scanf("%c",&decision);
	switch(decision)
	{
		case '1':
		if (plane_code==1001)
	{
		return(6000*seat_num);
	}
	if (plane_code==1002)
	{
		return(6000*seat_num);
	}
	if (plane_code==1003)
	{
		return(5500*seat_num);
	}
	if (plane_code==1004)
	{
		return(5500*seat_num);
	}
	if (plane_code==1005)
	{
		return(5000*seat_num);
	}
	if (plane_code==1006)
	{
		return(5000*seat_num);
	}
	if (plane_code==1007)
	{
		return(4500*seat_num);
	}
	if (plane_code==1008)
	{
		return(4500*seat_num);
	}
	if (plane_code==1009)
	{
		return(7000*seat_num);
	}
	if (plane_code==1010)
	{
		return(7000*seat_num);
	}
		if (plane_code==1011)
	{
		return(18000*seat_num);
	}
	if (plane_code==1012)
	{
		return(18000*seat_num);
	}
	if (plane_code==1013)
	{
		return(13000*seat_num);
	}
	if (plane_code==1014)
	{
		return(13000*seat_num);
	}
	if (plane_code==1015)
	{
		return(46000*seat_num);
	}
	if (plane_code==1016)
	{
		return(46000*seat_num);
	}
	if (plane_code==1017)
	{
		return(66000*seat_num);
	}
	if (plane_code==1018)
	{
		return(66000*seat_num);
	}
	if (plane_code==1019)
	{
		return(72000*seat_num);
	}
	if (plane_code==1020)
	{
		return(72000*seat_num);
	}
	break;
	case '2':	
		if (plane_code==1001)
	{
		return(5000*seat_num);
	}
	if (plane_code==1002)
	{
		return(5000*seat_num);
	}
	if (plane_code==1003)
	{
		return(4500*seat_num);
	}
	if (plane_code==1004)
	{
		return(4500*seat_num);
	}
	if (plane_code==1005)
	{
		return(4000*seat_num);
	}
	if (plane_code==1006)
	{
		return(4000*seat_num);
	}
	if (plane_code==1007)
	{
		return(3500*seat_num);
	}
	if (plane_code==1008)
	{
		return(3500*seat_num);
	}
	if (plane_code==1009)
	{
		return(6000*seat_num);
	}
	if (plane_code==1010)
	{
		return(6000*seat_num);
	}
		if (plane_code==1011)
	{
		return(17000*seat_num);
	}
	if (plane_code==1012)
	{
		return(16000*seat_num);
	}
	if (plane_code==1013)
	{
		return(12000*seat_num);
	}
	if (plane_code==1014)
	{
		return(12000*seat_num);
	}
	if (plane_code==1015)
	{
		return(45000*seat_num);
	}
	if (plane_code==1016)
	{
		return(45000*seat_num);
	}
	if (plane_code==1017)
	{
		return(65000*seat_num);
	}
	if (plane_code==1018)
	{
		return(65000*seat_num);
	}
	if (plane_code==1019)
	{
		return(70000*seat_num);
	}
	if (plane_code==1020)
	{
		return(70000*seat_num);
	}
}
}
void seat_avaliblity(char choice,int seat)
{
	int total_seats[100],total_seats_eco[100];
    int i=0,j=0;
    int total,total1,num,num1;
    int seat_available[100]={2000},seat_available_eco[100]={2000};
    int sn,sn1,seatno,seatno1,seat_nos[100],seat_nos_eco[100],SAL=0,SAL1=0;
    char opt,optt;
	if(choice == '1'){/*business class*/
	business:
	FILE *file = fopen("check seats.txt", "r");
    while(fscanf(file, "%d", &num)!=EOF)
	{
        total_seats[i] = num;
        i++;
    }
    fclose(file);
    for(i=0;i<10;i++)
	{
    	if (total_seats[i]==0)
		{
			seat_available[SAL]=i+1;
        	SAL++;
		}	
	}
	total=SAL/2;/*total ko SAL sy divide is liye kiya hai ly hum ko shuru ki 10 seats ki booking mil jye*/
	if(total==0)
	{
		printf(" \n\n\t%d Seats are Not Available in this Flight !!!");
		return ;
	}
	printf("\t\tSeats Number that are  Available in Business class\n\n");	
	for (i=0;i<10;i++)
	{
    	if (total_seats[i]==0)
		printf("%d ",i+1);
    }
//		printf("\n\n   Enter total seats You want  = ");
//		scanf("%d",&sn);
	if(seat>total)
	{
		printf(" \n\n\t%d Seats are Not Available in this Flight !!!",sn);
		printf("\nIf you want to reserve a seat in Economy class press y :");
		scanf("%c",&opt);
		if(opt=='y')goto economy;
		return;	
	} 
	int xx=0;
	for (i=0;i<seat;i++)
	{
		start :
		printf("\n\t %d.Enter Seat Number = ",i+1);
		scanf("%d",&seatno);
		int count=0;
		for(int j=0;j<total;j++)
		{
			if(seatno==seat_available[j])
			{
				count++;
				seat_nos[xx]=seatno;
				xx++;
			}
		}
		if(count==1)
		{
			;
		}
		else
		{
			printf("\n\t This Seat is Not Availabe Enter Again\n");
			goto start;
		} 
	}
	for(i=0;i<seat;i++)
	{
		printf(" \n\n\t\t Your seat nos = ");
		printf(" %d ",seat_nos[i]);
	}
	for(i=0;i<seat;i++)
	{
		int a=0;
		a=seat_nos[i]-1;
		total_seats[a]=1;
	}
	FILE *f = fopen("check seats.txt", "w");
	for(i=0;i<10;i++)
	fprintf(f, "%d\n", total_seats[i]);
    fclose(f);	
	}
	else if(choice != 1)
	{	/*Starting of economy class*/
		economy:
		FILE *file = fopen("economy seats.txt", "r");
    while(fscanf(file, "%d", &num1)!=EOF)
	{
        total_seats_eco[j] = num1;
        j++;
    }
    fclose(file);
    for(j=0;j<10;j++)
	{
    	if (total_seats_eco[j]==0)
		{
			seat_available_eco[SAL1]=j+1;
        	SAL1++;
		}	
	}
	total1=SAL1/2;/*total ko SAL sy divide is liye kiya hai ly hum ko shuru ki 10 seats ki booking mil jye*/
	if(total1==0)
	{
		printf(" \n\n\t%d Seats are Not Available in this Flight !!!");
		return;
	}
	printf("\t\tSeats Number that are  Available in Economy class\n\n");
	for (j=0;j<10;j++)
	{
    	if (total_seats_eco[j]==0)
		printf("%d ",j+1);
    }
//		scanf("%d",&sn1);
//		printf("\n\n   Enter total seats You want  = ");
	if(seat>SAL1)
	{
//		printf(" \n\n\t%d Seats are Not Available in this Flight !!!",sn);
		printf(" \n\n\t%d Seats are Not Available in this Flight !!!",sn1);
		printf("\nIf you want to reserve a seat in business class press y :");
		scanf(" %c",&optt);
		if(optt=='y')goto business;
		return;	
	} 
	for (j=0;j<seat;j++)
	{
		start1 :
		printf("\n\t %d.Enter Seat Number = ",j+1);
		scanf("%d",&seatno1);
		int count1=0;
		for(int k=0;k<SAL1;k++)
		{
			if(seatno1==seat_available_eco[k])
			count1++;
		}
		if(count1==1)
		{
			for(j=0;j<seat;j++)
			{
		    	if(seatno1==seat_nos_eco[j])
			    {
				    printf("\n\n\tYou Have Already Selected This Seat...ENTER AGAIN !!!\n\n");
				    goto start1;
				}
			}
			seat_nos_eco[j]=seatno1;
		}
		else
		{
			printf("\n\t This Seat is Not Availabe Enter Again\n");
			goto start1;
		} 
	}
	for(j=0;j<seat;j++)
	{
		printf(" \n\n\t\t Your seat nos = ");
		printf(" %d ",seat_nos_eco[j]);
	}
	for(j=0;j<seat;j++)
	{
		int a1=0;
		a1=seat_nos_eco[j]-1;
		total_seats_eco[a1]=1;
	}
	FILE *f = fopen("economy seats.txt", "w");
	for(j=0;j<10;j++)
	fprintf(f, "%d\n", total_seats_eco[j]);
	fclose(f);
//	    return sn1;
	}	
}
void information_specific(int plane_code)
{
	if (plane_code==1001)
	{
		printf("\n\tPlane_code:\t\t\tEK-1001");
		printf("\n\tDestination:\t\tKarachi to Islamabad");
		printf("\n\tDeparture:\t\t08:00 ");
	}
	if (plane_code==1002)
	{
		printf("\n\tPlane_code:\t\t\tEK-1002");
		printf("\n\tDestination:\t\tIslamabad to Karachi");
		printf("\n\tDeparture:\t\t09:15");
	}
	if (plane_code==1003)
	{
		printf("\n\tPlane_code:\t\t\tEK-1003");
		printf("\n\tDestination:\t\tKarachi to Lahore");
		printf("\n\tDeparture:\t\t09:55");
	}
	if (plane_code==1004)
	{
		printf("\n\tPlane_code:\t\t\tEK-1004");
		printf("\n\tDestination:\t\tLahore to Karachi");
		printf("\n\tDeparture:\t\t11:00");
	}
	if (plane_code==1005)
	{
		printf("\n\tPlane_code:\t\t\tEK-1005");
		printf("\n\tDestination:\t\tKarachi to Multan");
		printf("\n\tDeparture:\t\t13:00");
	}
	if (plane_code==1006)
	{
		printf("\n\tPlane_code:\t\t\tEK-1006");
		printf("\n\tDestination:\t\tMultan to Karachi");
		printf("\n\tDeparture:\t\t15:00");
	}
	if (plane_code==1007)
	{
		printf("\n\tPlane_code:\t\t\tEK-1007");
		printf("\n\tDestination:\t\tKarachi to Faisalabad");
		printf("\n\tDeparture:\t\t18:00");
	}
	if (plane_code==1008)
	{
		printf("\n\tPlane_code:\t\t\tEK-1008");
		printf("\n\tDestination:\t\tFaisalabad to Karachi");
		printf("\n\tDeparture:\t\t19:45");
	}
	if (plane_code==1009)
	{
		printf("\n\tPlane_code:\t\t\tEK-1009");
		printf("\n\tDestination:\t\tKarachi to Peshawar");
		printf("\n\tDeparture:\t\t22:45");
	}
	if (plane_code==1010)
	{
		printf("\n\tPlane_code:\t\t\tEK-1010");
		printf("\n\tDestination:\t\tPeshawar to Karachi");
		printf("\n\tDeparture:\t\t00:15");
	}
		if (plane_code==1011)
	{
		printf("\n\tPlane_code:\t\t\tEK-1011");
		printf("\n\tDestination:\t\tKarachi to Dubai");
		printf("\n\tDeparture:\t\t08:20");
	}
	if (plane_code==1012)
	{
		printf("\n\tPlane_code:\t\t\tEK-1012");
		printf("\n\tDestination:\t\tDubai to Karachi");
		printf("\n\tDeparture:\t\t09:30");
	}
	if (plane_code==1013)
	{
		printf("\n\tPlane_code:\t\t\tEK-1013");
		printf("\n\tDestination:\t\tKarachi to Muscat");
		printf("\n\tDeparture:\t\t10:00");
	}
	if (plane_code==1014)
	{
		printf("\n\tPlane_code:\t\t\tEK-1014");
		printf("\n\tDestination:\t\tMuscat to Karachi");
		printf("\n\tDeparture:\t\t11:10");
	}
	if (plane_code==1015)
	{
		printf("\n\tPlane_code:\t\t\tEK-1015");
		printf("\n\tDestination:\t\tKarachi to London");
		printf("\n\tDeparture:\t\t13:40");
	}
	if (plane_code==1016)
	{
		printf("\n\tPlane_code:\t\t\tEK-1016");
		printf("\n\tDestination:\t\tLondon to Karachi");
		printf("\n\tDeparture:\t\t15:15");
	}
	if (plane_code==1017)
	{
		printf("\n\tPlane_code:\t\t\tEK-1017");
		printf("\n\tDestination:\t\tKarachi to Toronto");
		printf("\n\tDeparture:\t\t17:50");
	}
	if (plane_code==1018)
	{
		printf("\n\tPlane_code:\t\t\tEK-1018");
		printf("\n\tDestination:\t\tToronto to Karachi");
		printf("\n\tDeparture:\t\t19:55");
	}
	if (plane_code==1019)
	{
		printf("\n\tPlane_code:\t\t\tEK-1019");
		printf("\n\tDestination:\t\tKarachi to Newyork");
		printf("\n\tDeparture:\t\t23:05");
	}
	if (plane_code==1020)
	{
		printf("\n\tPlane_code:\t\t\tEK-1020");
		printf("\n\tDestination:\t\tNewyork to Karachi");
		printf("\n\tDeparture:\t\t00:30");
	}
}
void seat_check()
{
	int total_seats[100],total_seats_eco[100];
    int choice,i=0,j=0;
    int total,total1,num,num1;
    int seat_available[100]={2000},seat_available_eco[100]={2000};
    int sn,sn1,seatno,seatno1,seat_nos[100],seat_nos_eco[100],SAL=0,SAL1=0;
    char opt;
    printf("\nEnter 1 to check the seats in business class or any other number or letter will proceed to Economy class :");
    scanf(" %c",&opt);
    if(opt=='1')
	{
//    	system("cls");
    	FILE *file = fopen("check seats.txt", "r");
        while(fscanf(file, "%d", &num)!=EOF)
	    {
            total_seats[i] = num;
            i++;
        }
        fclose(file);
        for(i=0;i<10;i++)
		{
    	    if (total_seats[i]==0)
		    {
			seat_available[SAL]=i+1;
        	SAL++;
		}	
	}
	total=SAL/2;/* we have divided total by SAL to get booking of starting 10 seats */
	if(total==0)
	{
		printf(" \n\n\t%d Seats are Not Available in this Flight !!!");
	}
	else if(total != 0)
	{
		printf("\t\tSeats Number that are  Available in Business class\n\n");	
	    for (i=0;i<10;i++)
		{
    	    if (total_seats[i]==0)
		    printf("%d ",i+1);
        }
	}
	printf("\nPress any key to move forward");
	getch();
	}
	else if(opt!='1')
	{
		system("cls");
		FILE *file = fopen("economy seats.txt", "r");
        while(fscanf(file, "%d", &num1)!=EOF)
	    {
            total_seats_eco[j] = num1;
            j++;
        }
        fclose(file);
        for(j=0;j<10;j++)
	    {
    	    if (total_seats_eco[j]==0)
		    {
			    seat_available_eco[SAL1]=j+1;
        	    SAL1++;
		    }	
	    }
	    total1=SAL1/2;/*total ko SAL sy divide is liye kiya hai ly hum ko shuru ki 10 seats ki booking mil jye*/
	    if(total1==0)
		{
			printf(" \n\n\t%d Seats are Not Available in this Flight !!!");
		}
		else if(total1 != 0)
		{
			printf("\t\tSeats Number that are  Available in Economy class\n\n");
	        for (j=0;j<10;j++)
			{
    	        if (total_seats_eco[j]==0)
		        printf("%d ",j+1);
            }
		}
	}
	printf("\nPress any key to move forward");
	getch();
}
void printticket(char name[],char CNIC[],int plane_code,char opt,int seats,float fares)
{
	system("cls");
	printf("-------------------TICKET-------------------\n\n");
	printf("\tPassenger Name:\t\t\t%s",name);
	printf("\n\tNumber Of Seats:\t%d",seats);
	printf("\n\tCNIC of Passenger:\t\t%s",CNIC);
	information_specific(plane_code);
	printf("\nFare:\t\t%.2f",fares);
}
void cancellation()
{
	char n; 
	int total_seats[100],total_seats_eco[100];
    int i=0,j=0;
    int total,total1,num,num1;
    int seat_available[100]={2000},seat_available_eco[100]={2000};
    int sn,sn1,seatno,seatno1,seat_nos[100],seat_nos_eco[100],SAL=0,SAL1=0;
	system("cls");
	printf("\nEnter the the option to cancel the reservation :\n1.Business Class\n2.Ecoconmy Class");
	scanf(" %c",&n);
	if(n=='1'){
		printf("*****************Welcome To Bussiness Class Cancellation*******************");
		FILE *file = fopen("check seats.txt", "r");
		while(fscanf(file, "%d", &num)!=EOF)
	    {
            total_seats[i] = num;
            i++;
        }
        fclose(file);
        for(i=0;i<10;i++)
	    {
    	    if (total_seats[i]!=0)
			{
			    seat_available[SAL]=i+1;
        	    SAL++;
		    }	
	    }
	    total=SAL/2;
	    printf("\n\n   Enter total seats You want  to cancel = ");
		scanf("%d",&sn);
		int mxx=0;
		for (i=0;i<sn;i++)
		{
			start :
			printf("\n\t %d.Enter Seat Number = ",i+1);
			scanf("%d",&seatno);
			int count=0;
			for(int j=0;j<total;j++)
			{
				if(seatno==seat_available[j])
				{
					count++;
					seat_nos[mxx]=seatno;
					mxx++;
				}
			}
			if(count==1)
			{
				;
			}
			else
			{
				printf("\n\tInvalid Cancellation\n");
				goto start;
			}
			for(i=0;i<sn;i++)
			{
			    int a=0;
			    a=seat_nos[i]-1;
			    total_seats[a]=0;
		    }
		    FILE *f = fopen("check seats.txt", "w");
		    for(i=0;i<10;i++)
		    fprintf(f, "%d\n", total_seats[i]);
	        fclose(f); 
		}
		printf("\nCancellation is Done Successfully!!!!");
		system("cls");
	}
	else if(n=='2')
	{
		printf("*****************Welcome To Economy Class Cancellation*******************");
		FILE *file = fopen("economy seats.txt", "r");
		while(fscanf(file, "%d", &num1)!=EOF)
	    {
            total_seats_eco[i] = num1;
            i++;
        }
        fclose(file);
        for(i=0;i<10;i++)
	    {
    	    if (total_seats_eco[i]!=0)
		    {
			    seat_available_eco[SAL1]=i+1;
        	    SAL1++;
		    }	
	    }
	    total1=SAL1/2;
	    printf("\n\n   Enter total seats You want  to cancel = ");
		scanf("%d",&sn1);
		int xx=0;
		for (i=0;i<sn1;i++)
		{
			start1:
			printf("\n\t %d.Enter Seat Number = ",i+1);
			scanf("%d",&seatno1);
			int count1=0;
			for(int j=0;j<total1;j++)
			{
				if(seatno1==seat_available_eco[j])
				{
					count1++;
					seat_nos_eco[xx]=seatno1;
					xx++;
				}
			}
			if(count1==1)
			{
				;
			}
			else
			{
				printf("\n\tInvalid Cancellation\n");
				goto start1;
			}
			for(i=0;i<sn1;i++)
			{
			    int a1=0;
			    a1=seat_nos_eco[i]-1;
			    total_seats_eco[a1]=0;
		    }
		    FILE *f = fopen("economy seats.txt", "w");
		    for(i=0;i<10;i++)
		    fprintf(f, "%d\n", total_seats_eco[i]);
	        fclose(f); 
		}
		printf("\nCancellation is Done Successfully!!!!");
		system("cls");
	}
}
