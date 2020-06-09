#pragma once
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
#include <string>
using namespace std;

class SoftwareStudent : public Student {
	public:
		SoftwareStudent();
		SoftwareStudent(string studentID, string firstName, 
			string lastName, string emailAddress, int studentAge, 
			int daysInCourseArray[NUM_COURSES], Degree degreeType);
		~SoftwareStudent();

		void SetDegreeProgram(Degree degreeType);
		Degree GetDegreeProgram();
		void Print();
};

#endif /* SOFTWARESTUDENT_H */
