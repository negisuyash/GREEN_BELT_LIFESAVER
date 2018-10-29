#include<iostream.h>
#include<conio.h>

float cal(float distance,int speed)

{
	float time=distance/speed;
	return time;

}
float critical(int traffic)
{
	float time_limit=float(traffic/2);
	return time_limit;
}
/* FOR TESTING THIS FILE
void main()
{                clrscr();
	float dis=400.5;
	int s=60;
	cout<<cal(dis,s);
	getch();
}
*/