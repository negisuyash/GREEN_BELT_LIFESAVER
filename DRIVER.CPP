#include "INCLUDES.cpp"
#include "TIME_CALC.cpp"


void green_belt(ERV vehi[],int n)
{
	int sema=0,WAIT=0;
	for(int i=0;i<n;i++)
	{
		vehi[i].comparsion_param=float((vehi[i].traffic)/(10*(sqrt(vehi[i].time))));
	}

	for( i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(vehi[i].comparsion_param<vehi[j].comparsion_param)
			{

				//ERV temp=vehi[i];
				//vehi[i]=vehi[j];
				//vehi[j]=temp;
				swap(vehi[i],vehi[j]);
			}
		}
	}
	cout<<"\norder of ERV vehicles\n";
	for( i=0;i<n;i++)
	{
		cout<<i+1<<".)"<<vehi[i].name<<endl;
	}

       //	for(int i=0;i<n;i++)
       //delay(4000);
       cout<<"\n\npress any key to continue...";
       getch();
	{
	int timer=int(ceil(vehi[n-1].time));

	//cout<<"flag 1";
	/*for(int i=timer;i>0;i--)
	{       //cout<<"flag 2";
		if(time_limit<i)
			{
				gotoxy(20,20+(timer-i));
				cout<<"lights will go green in for "<<vehi[j].name<<":"<<i-time_limit;
				delay(1000);
			}
		else
		{
			clrscr();
			gotoxy(20,20);
			cout<<"light set green ";
		}
	}*/
	clrscr();
       //	cout<<"MAX WAITING TIME :"<<timer;
	for(int j=timer;j>=0;j--)
	{       clrscr();
		for( i=0;i<n;i++)
		{       //sema=0;
			vehi[i].time--;
			if(vehi[i].time_limit>vehi[i].time&&vehi[i].time>0&&sema==0)
			{
				cout<<"\ngreen light for ERV no.:"<<vehi[i].name;
				sema=1;
			}
			else if(vehi[i].time_limit>vehi[i].time&&vehi[i].time>0&&sema!=0)
			{
				cout<<"\nwaiting for other ERV to pass to avoid congestion";
				WAIT++;
				vehi[i].time++;
				j++;

			}
			else if(vehi[i].time==0)
			{
				sema=0;
				cout<<"\nvehicle no."<<vehi[i].name<<" just cleared";
			}
			else if(vehi[i].time<0)
			{
				cout<<"\nvehicle no."<<vehi[i].name<<" cleared";

			}
			else if(vehi[i].time>vehi[i].time_limit)
			{
				cout<<"\nred light for ERV no."<<vehi[i].name;
			}
			delay(1500);


		}


	}
	}
	cout<<"\ntotal waiting time:"<<WAIT;
	getch();
	cout<<"\n\npress any key to continue..";
}

void main()
{       clrscr();
	//float distance;
	//int speed,traffic;
	int n;
	cout<<"\nNUMBER OF VEHICLES APPROACHING CONCURRENTLY:";
	cin>>n;
	ERV vehi[10];
	for(int i=0;i<n;i++)
	{


		start_again:
		cout<<"\n ERV no."<<i+1;
		cout<<"\nENTER DISTANCE (IN DECIMAL):";
		cin>>vehi[i].distance;
		cout<<"\nENTER SPEED(INTEGER):";
		cin>>vehi[i].speed;
		cout<<"\nENTER TRAFFIC VALUES:";
		cin>>vehi[i].traffic;
		if(vehi[i].speed>60)
		{
			cout<<"ERV vehicles are permitted at max speed of 60kmph,please enter speed again..";
			goto start_again;

		}
		vehi[i].time=cal(vehi[i].distance,vehi[i].speed);
		vehi[i].time_limit=int(critical(vehi[i].traffic));
		vehi[i].name=i+1;

	}


	green_belt(vehi,n);
			       getch();

}
