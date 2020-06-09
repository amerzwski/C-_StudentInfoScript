#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"
#include <string>
using namespace std;

class SecurityStudent : public Student {
	public:
		SecurityStudent();
		SecurityStudent(string studentID, string firstName, 
			string lastName, string emailAddress, int studentAge, 
			int daysInCourseArray[NUM_COURSES], Degree degreeType);
		~SecurityStudent();

		void SetDegreeProgram(Degree degreeType);
		Degree GetDegreeProgram();
		void Print();
};

#endif /* SECURITYSTUDENT_H */
