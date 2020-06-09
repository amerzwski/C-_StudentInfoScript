#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "student.h"
#include <string>
using namespace std;

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Andrew,Merzwski,amerzw1@wgu.edu,34,33,55,44,SOFTWARE" };

class Roster {
	public:
		Roster();
		Roster(const int NUM_STUDENTS);
		Student *classRosterArray[NUM_STUDENTS]{ nullptr, nullptr, nullptr, nullptr, nullptr };
		virtual ~Roster();
		void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(Degree degreeType);
	protected:
		string dataElement;
		Degree degreeType;
		static int addCounter;

};

#endif /* ROSTER_H */