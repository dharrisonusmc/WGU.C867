#pragma once
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"

class SoftwareStudent : public Student {
	using Student::Student;
public:
	virtual Degree getDegreePro();
private:
	Degree degreePro = SOFTWARE;
};


#endif