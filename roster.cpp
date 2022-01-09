#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"
#include <array>







bool emailChecker(string email) {
	if (email.find("@") != string::npos && email.find(".") != string::npos && email.find(" ") == string::npos) {
		return true;
	}
	else {
		return false;
	}
};




Roster::Roster() {}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress,
	int age, int numDaysComplete1, int numDaysComplete2, int numDaysComplete3, Degree degree) {

	int days[3] = { numDaysComplete1, numDaysComplete2, numDaysComplete3 };

	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] == nullptr) {
			switch (degree) {
			case Degree::NETWORKING:
				classRosterArray[i] = new NetworkStudent(studentId, firstName, lastName, emailAddress, age, days, degree);
				break;
			case Degree::SECURITY:
				classRosterArray[i] = new SecurityStudent(studentId, firstName, lastName, emailAddress, age, days, degree);
				break;
			case Degree::SOFTWARE:
				classRosterArray[i] = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age, days, degree);
				break;
			default:
				break;
			}
			break;
		}
	}
};
// print full roster
void Roster::printAll() {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

// invalid emails
void Roster::printInvalidEmail() {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (!emailChecker(classRosterArray[i]->getEmailAdd())) {
			cout << "Student ID: " << classRosterArray[i]->getStuId() << " " << "Invalid Email: " << classRosterArray
				[i]->getEmailAdd() << endl;
		}
	}
	cout << endl;
}

// print by degree
void Roster::printByDegree(int degreePro) {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getDegreePro() == degreePro) {
				classRosterArray[i]->print();
			}
		}
	}
	cout << endl;
};

// print by numDays
void Roster::printnumDaysComplete(string studentId) {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStuId() == studentId) {
				const int* daysComp = classRosterArray[i]->getNumberDays();
				int avg = (daysComp[0] + daysComp[1] + daysComp[2]) / 3;
				cout << studentId << " took an average of " << avg << " days to complete a course.";
			}
		}
	}
	cout << endl;
};
//remove student
void Roster::remove(string studentId) {
	bool idfound = false;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStuId() == studentId) {
			classRosterArray[i] = nullptr;
			idfound = true;
			break;
		}
	}
	if (idfound == false) {
		cout << "Student with Student ID: " << studentId << " not found." << endl;
	}
	else { cout << "Student with Student ID: " << studentId << " has been removed from the roster." << endl; }
};



int main() {

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,David,Harrison,dharrisonusmc@gmail.com,34,3,28,30,SOFTWARE"
	};


	Roster classRoster;
	Degree degree;

	cout << "Scripting and Programming Applications - C867" << endl;
	cout << "Coding Language used C++" << endl;
	cout << "David Harrison - 001085830" << endl;
	cout << endl;
	cout << endl;


	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
		string value, studata[9], place = studentData[i];
		istringstream ss(place);

		int index = 0;
		while (getline(ss, value, ',')) {
			studata[index] = value;
			index += 1;
		}

		if (studata[8] == "NETWORK")
			degree = Degree::NETWORKING;
		else if (studata[8] == "SECURITY")
			degree = Degree::SECURITY;
		else
			degree = Degree::SOFTWARE;

		classRoster.add(studata[0], studata[1], studata[2], studata[3], stoi(studata[4]),
			stoi(studata[5]), stoi(studata[6]), stoi(studata[7]), degree);
	}


	classRoster.printAll();
	classRoster.printInvalidEmail();
	
	// To fix the issue of only showing one student average by student ID
	for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
		classRoster.printnumDaysComplete(classRoster.classRosterArray[i]->getStuId());
	};
	cout << endl;
	
	classRoster.printByDegree(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	classRoster.~Roster(); // Call to the decostructor in the main loop
	return 0;

	
};

Roster::~Roster() {};


