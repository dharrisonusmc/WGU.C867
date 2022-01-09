
#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"

class SecurityStudent : public Student {
	using Student::Student;
public:
	virtual Degree getDegreePro();
private:
	Degree degreePro = SECURITY;
};


#endif
