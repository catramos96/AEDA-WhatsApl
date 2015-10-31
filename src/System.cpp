#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include "System.h"

using namespace std;


/********************************
 *	    	CLASSE DATA			*
 *******************************/


Data::Data(){
	t=0;
};

Data::Data(time_t time1){
	t=time1;
}

void Data::setData(){
	t=time(0);
}

time_t Data::getDataCompleta(){
	return t;
}

std::ostream & operator<<(std::ostream & out, const Data & d){
	out << d;
	return out;
}

const string Data::getHora(){
	time_t now=t;
	struct tm tstruct;
	char buf[80];
	tstruct=*localtime(&now);
	strftime(buf,sizeof(buf),"%X",&tstruct);

	return buf;
}

const string Data::getData(){
	time_t now=t;
	struct tm tstruct;
	char buf[80];
	tstruct=*localtime(&now);
	strftime(buf,sizeof(buf),"%Y-%m-%d",&tstruct);

	return buf;
}



