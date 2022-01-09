#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <array>
#include <string>

class Roster {
public:
	Roster();
	virtual ~Roster();
	void printAll();
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int numDaysComplete1, int numDaysComplete2,
		int numDaysComplete3, Degree);
	void remove(string studentId);
	void printnumDaysComplete(string);
	void printInvalidEmail();
	void printByDegree(int degreePro);

	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

};
#endif // !ROSTER_H

