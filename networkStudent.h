#pragma once
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"

class NetworkStudent : public Student {
	using Student::Student;
public:
	virtual Degree getDegreePro();
private:
	Degree degreePro = NETWORKING;
};


#endif