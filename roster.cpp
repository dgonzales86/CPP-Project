#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
#include "degree.h"
#include "student.h"





Roster::Roster()
{
	for (int i = 0; i < 5; i++) classRosterArray[i] = nullptr;
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	classRosterArray[++currentRosterIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);  //new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

//removes students from the roster by student ID. If studentID does not exist, prints "Student was not found."
void Roster::remove(std::string studentID)
{
	bool found = false;
	std::cout << "\nRemoving " << studentID << ":\n\n";
	for (int i = 0; i <= currentRosterIndex ; i++)
	{
		if(studentID == classRosterArray[i]->getStudentID())                                            // (classRosterArray[i]->getStudentID() == studentID) 
		{
			found = true;
			delete classRosterArray[i];
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[currentRosterIndex];
			classRosterArray[currentRosterIndex] = temp;
			currentRosterIndex--;
			
		}
		/*else              
			{
			std::cout << classRosterArray[i]->getStudentID() << std::endl;
			std::cout << "The student with ID " << studentID << " was not found\n";
			break;
			}*/
	}

	if (!found) std::cout << "Student not found.\n";
	else { std::cout << studentID << " removed.\n\n"; }
}

int Roster::parseAdd(std::string row)
{
	size_t rhs = row.find(",");
	std::string studentID = row.substr(0, rhs);
	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string firstName = row.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string lastName = row.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string emailAddress = row.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string age = row.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string daysInCourse1 = row.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string daysInCourse2 = row.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string daysInCourse3 = row.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	DegreeProgram degreeprogram;
	
	int ageInt = 0;
	std::stringstream(age) >> ageInt;
	int daysInCourse1int{0};
	std::stringstream(daysInCourse1) >> daysInCourse1int;
	int daysInCourse2int{0};
	std::stringstream(daysInCourse2) >> daysInCourse2int;
	int daysInCourse3int{0};
	std::stringstream(daysInCourse3) >> daysInCourse3int;
	
	int ERROR = 99999;    // maybe try exception for invalid emails??
	try
	{
		std::string programTypeString = row.substr(lhs, row.length() - lhs);
		if (programTypeString == "SECURITY") { degreeprogram = DegreeProgram::SECURITY; }
		else if (programTypeString == "NETWORK") { degreeprogram = DegreeProgram::NETWORK; }
		else if (programTypeString == "SOFTWARE") { degreeprogram = DegreeProgram::SECURITY; }
		else if (programTypeString == "NONE") { degreeprogram = DegreeProgram::NONE; }
		else throw ERROR;
	}
	catch (int z)

	{
		std::cout << "\n\nUNKNOWN DEGREE PROGRAM TYPE DETECTED!\n" << "Error code: " << z << std::endl;
		return z;	
	}

	add(studentID, firstName, lastName, emailAddress, ageInt, daysInCourse1int, daysInCourse2int, daysInCourse3int, degreeprogram);   //classRosterArray[++currentRosterIndex] = new Student(studentID, firstName, lastName, emailAddress, ageInt , daysInCourse1int, daysInCourse2int, daysInCourse3int , degreeprogram);

// Bug * there is no constructor that matches data types. stringstream used to populate new variables with correct variable types to fit constructor. 
// std::cout << "\n\n" << ageInt << " " << daysInCourse1int << " " << daysInCourse2int << " " << daysInCourse3int << std::endl;

	return 0;
}

//prints complete, tab-seperated list of student data. printAll() must loop through all students in classRosterArray and call print() for each student.
void Roster::printAll()
{
	std::cout << "Displaying all students: \n" << std::endl;
	for (int i = 0; i <= currentRosterIndex; i++) classRosterArray[i]->print();
}


void Roster::printAverageDaysInCourse(std::string studentID)
{
	int total{ 0 };
	int* c1{ 0 };
	int* c2{ 0 };
	int* c3{ 0 };
	for (int i = 0; i <= currentRosterIndex; i++)
	{
		if (studentID == classRosterArray[i]->getStudentID())
		{
			c1 = classRosterArray[i]->getdaysInCourse1();
			c2 = classRosterArray[i]->getdaysInCourse2();
			c3 = classRosterArray[i]->getdaysInCourse3();
			total = (*c1 + *c2 + *c3) / 3.0;
			std::cout << "\nStudent ID: " << studentID << ", Averages " << total << " days in a course.";
		}
	}
}

//verifies student email addresses and displays all invalid email addresses to user. 
//valid emails should include ('@') and period ('.') and should NOT include a space (' ')
void Roster::printInvalidEmails()
{	
	std::cout << "\nDisplaying invalid emails: \n\n";
	for (int i = 0; i <=currentRosterIndex; i++)
	{
		std::string email = classRosterArray[i]->getEmail();
		if (email.find("@") == std::string::npos || email.find(".") == std::string::npos || email.find(" ") != std::string::npos)
		std::cout << email << " Is invalid\n";
	}
}

//prints student information for a degree program specified by an enum type. 
void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
		std::cout << "\n\nDisplaying students enrolled in degree program: " << DegreeProgramString[degreeprogram] << "\n" << std::endl;
		if (degreeprogram == SECURITY)
		{
			classRosterArray[0]->print();
			classRosterArray[3]->print();
		}		
		else if(degreeprogram == NETWORK)
		{
			classRosterArray[1]->print();
		}
		else if (degreeprogram == SOFTWARE)
		{
			classRosterArray[2]->print();
			classRosterArray[4]->print();
		}
		else { std::cout << "Not enrolled in a degree program"; }
}

Roster::~Roster()
{
	std::cout << "\n\nDestructor called...\n\n";

	for (int i = 0; i <= currentRosterIndex; i++)
	{
		
		delete classRosterArray[i];
		classRosterArray[i] =nullptr;
		
	}
	std::cout << "Students deleted\n\n";
}
