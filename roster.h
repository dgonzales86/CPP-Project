#pragma once
#include <string>
#include "student.h"
#include "degree.h"

class Roster
{
private:
	
	  
	int currentRosterIndex = -1;

public:
	Student* classRosterArray[5];
	Roster();
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	int parseAdd(std::string row);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	~Roster();
};