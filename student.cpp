#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"

Student::Student() //constructor
{  

	studentID = "NONE";
	firstName = "NONE";
	lastName = "NONE";
	emailAddress = "NONE";
	age = 0;
	int daysInCourse[]{0};
	degreeprogram = DegreeProgram::NONE;
}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
	this->degreeprogram = degreeprogram;
}

void Student::setStudentID(std::string studentID)
{
	this->studentID = studentID;
}

void Student::setFname(std::string firstName)
{
	this->firstName = firstName;
}

void Student::setLname(std::string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(std::string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setdaysInCourse1(int daysInCourse1)
{
	this->daysInCourse[0] = daysInCourse1;
}

void Student::setdaysInCourse2(int daysInCourse2)
{
	this->daysInCourse[1] = daysInCourse2;
}

void Student::setdaysInCourse3(int daysInCourse3)
{
	this->daysInCourse[2] = daysInCourse3;
}

void Student::setDegreeProgram(DegreeProgram degreeprogram)
{
	this->degreeprogram = degreeprogram;
}

std::string Student::getStudentID() const
{
	return studentID;
}

std::string Student::getFname() const
{
	return firstName;
}

std::string Student::getLName() const
{
	return lastName;
}

std::string Student::getEmail() const
{
	return emailAddress;
}

int Student::getAge() const
{
	return age;
}

//an array returned via pointer to an int.
int* Student::getdaysInCourse1()
{ 
		return daysInCourse;
}

int* Student::getdaysInCourse2()
{
	return daysInCourse + 1;
}

int* Student::getdaysInCourse3()
{
	return daysInCourse + 2;
}

std::string Student::getDegreeProgram()
{
	return 	DegreeProgramString[(int)this->degreeprogram];
}

void Student::print()
{	
	std::cout << std::left << getStudentID() << "\t";
	std::cout << std::left << "First Name: " << std::left << getFname() << "\t";
	std::cout << "Last Name: " << std::left << getLName() << "\t";
	std::cout << std::left << "Email Address: " << std::left << getEmail() << "\t";
	std::cout << std::left << "Age: " << std::left << getAge() << "\t";
	std::cout << std::left << "Days in course: " << std::left << "{" << *getdaysInCourse1() << "," << *getdaysInCourse2() << "," << *getdaysInCourse3() << "}" << "\t";
	std::cout << std::left << "Degree Program: " << std::left << getDegreeProgram() << std::endl;
}

Student::~Student()
{
	//no dynamic students created...
}

