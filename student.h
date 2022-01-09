#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
	Student();
	Student(string, string, string, string, int, int days[3], Degree);

	string getStuId() const;
	string getFirName() const;
	string getLaName() const;
	string getEmailAdd() const;
	int getAge() const;
	const int* getNumberDays() const;

	void setStuId(string studentId);
	void setFirName(string firstName);
	void setLaName(string lastName);
	void setEmailAdd(string emailAddress);
	void setAge(int age);
	void setNumberDays(int* numDaysComplete);
	void setDegreePro(Degree);
	virtual void print();
	virtual Degree getDegreePro();

	~Student();

private:

	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDaysComplete[3];
	Degree degreePro;
};
#endif // !STUDENT_H
