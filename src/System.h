/** @ \file System.h
 * header file que contém a classe System
 */
#ifndef SRC_SYSTEM_H_
#define SRC_SYSTEM_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

class Data
{
private:
	time_t t;
public:
	Data();
	Data(time_t time1);
	void setData(time_t time1);
	time_t getData();

	friend ostream & operator<<(ostream & out, const Data & d);

};



#endif /* SRC_SYSTEM_H_ */
