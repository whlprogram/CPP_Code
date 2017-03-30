#include <iostream>
using namespace System;
using namespace std;
date::date(int y,int m,int d){
	year=y;
	month=m;
	day=d;
}
/*date::date(int y, int m){
	year=y;
	month=m;
}*/
int date::getday(){
	return day;
}
int date::getmonth(){
	if(month>0&&month<=12)
		return month;
	else
		return 1;;

}
int date::getyear(){
	return year;
}
void date::setday(int d){
	day=d;
}
void date::setmonth(int m){
	if(m>0&&m<=12)
		month=m;
	else
		month=1;
}
void date::setyear(int y){
	year=y;
}
void date::displaydate(){
	cout<<getyear()<<"/"<<getmonth()<<"/"<<getday()<<endl;
}
