#include <iostream>
#include <string>
#include "student.h"


using namespace std;

Student::Student() {};

Student::~Student() {};

Student::Student(string id, string fname, string lname, string email, int yearsOld, int days[3], Degree degree) {
	setStuId(id);
	setFirName(fname);
	setLaName(lname);
	setEmailAdd(email);
	setAge(yearsOld);
	setNumberDays(days);
	setDegreePro(degree);
};


void Student::setStuId(string id) {
	studentId = id;
};
void Student::setFirName(string fname) {
	firstName = fname;
};
void Student::setLaName(string lname) {
	lastName = lname;
};
void Student::setEmailAdd(string email) {
	emailAddress = email;
};
void Student::setAge(int yearsOld) {
	age = yearsOld;
};
void Student::setNumberDays(int* days) {
	for (int i = 0; i < 3; i++) {
		numDaysComplete[i] = days[i];
	}
};
void Student::setDegreePro(Degree degree) {
	degreePro = degree;
};



string Student::getStuId()const {
	return studentId;
};
string Student::getFirName() const {
	return firstName;
};
string Student::getLaName() const {
	return lastName;
};
string Student::getEmailAdd() const {
	return emailAddress;
};
int Student::getAge() const {
	return age;
};
const int* Student::getNumberDays() const {
	return numDaysComplete;
};


Degree Student::getDegreePro() {
	return degreePro;
};

void Student::print() {
	string degree;

	if (getDegreePro() == 0)
		degree = "Network";
	else if (getDegreePro() == 1)
		degree = "Security";
	else if (getDegreePro() == 2)
		degree = "Software";



	cout << getStuId() << "\t"
		<< "First Name: " << getFirName() << "\t"
		<< "Last Name: " << getLaName() << "\t"
		<< "Email Address: " << getEmailAdd() << "\t"
		<< "Age: " << getAge() << "\t"
		<< "Days In Course: {" << getNumberDays()[0] << ", " << getNumberDays()[1] << ", " << getNumberDays()[2] << "} \t"
		<< "Degree Program: " << degree
		<< endl;

};
