#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;


int main()
{
	cout << "C867 - Scripting and Programming: Applications\nLanguage: C++\nStudent ID: 000983159\nName: Link ofHyrule" << endl << endl;


	const std::string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
									"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
									"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
									"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
									"A5,Link,ofHyrule,triforce@nintendo.edu,34,45,45,45,SOFTWARE" };
	
	Roster classRoster;


	for (int i = 0; i < 5; i++)
	{
		classRoster.parseAdd(studentData[i]);
	}
		
	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; i++)
	{
		string id = classRoster.classRosterArray[i]->getStudentID();
		classRoster.printAverageDaysInCourse(id);
	}
	classRoster.printByDegreeProgram(SOFTWARE);
	
	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	
	return 0;
	
}