#pragma once
#include<iostream>
#include "degree.h"

class Student {
private:

	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysInCourse[3]= {0};
	DegreeProgram degreeprogram;
		
public:


	Student();
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void setStudentID(std::string studentID);
	void setFname(std::string firstName);
	void setLname(std::string lastName);
	void setEmail(std::string emailAddress);
	void setAge(int age);
	void setdaysInCourse1(int daysInCourse1);
	void setdaysInCourse2(int daysInCourse2);
	void setdaysInCourse3(int daysInCourse3);
	void setDegreeProgram(DegreeProgram degreeprogram);
	
	std::string getStudentID() const;
	std::string getFname() const;
	std::string getLName() const;
	std::string getEmail() const;
	int getAge() const;
	int* getdaysInCourse1();
	int* getdaysInCourse2();
	int* getdaysInCourse3();
	std::string getDegreeProgram();
	void print();
	~Student();
};

