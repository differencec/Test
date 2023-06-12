#include <iostream>
using namespace std;
int main(){
/*	float ctemp,ftemp;
	cout<<"Enter Temperature in Fahrenheit: ";
	cin>>ftemp;
	cout<<endl;
	ctemp=(ftemp-32)*5/9;
	cout<<"Equalvalent Temperature in Celcius is: "<< ctemp;
	return 0;*/
		float ctemp,ftemp;
	cout<<"Enter Temperature in Celcius : ";
	cin>>ctemp;
	cout<<endl;
	ftemp=((9*ctemp)/5)+32;
	cout<<"Equalvalent Temperature in Fahrenheit is: "<< ftemp;
	return 0;
}