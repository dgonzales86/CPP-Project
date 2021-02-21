#pragma once
#include<string>

const int degreeProgramTypes = 4;
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE, NONE};
static std::string DegreeProgramString[degreeProgramTypes]{ "SECURITY", "NETWORK", "SOFTWARE", "NONE" };
 

 //DegreeProgram degreeType; <--declares variable of enumeration type DegreeProgram
 //degreeType = SECURITY;  <-- Assigns SECURITY to variable degreeType
 //integer value of SECURITY is 0, enumerations assign integer values{0,1,2,...} by default. They can be manually changed {SECURITY = 2, } for instance.
