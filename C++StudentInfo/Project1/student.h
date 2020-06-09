#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_COURSES = 3;

class Student {
	public:
		Student();
		Student(string studentID, string firstName, string lastName, 
			string emailAddress, int studentAge, 
			int daysInCourseArray[NUM_COURSES], Degree degreeType);

		//Accessor functions:
		string GetStudentID() const;
		string GetFirstName() const;
		string GetLastName() const;
		string GetEmail() const;
		int GetStudentAge() const;
		int* GetDaysToComplete() const;
		virtual Degree GetDegreeProgram() = 0; //Handled by derived class 

		//Mutator functions
		void SetStudentID(string studentID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmail(string emailAddress);
		void SetAge(int studentAge);
		void SetDaysToComplete(int* daysInCourseArray);
		virtual void SetDegreeProgram(Degree degreeType) = 0; //Handled by derived class


		virtual void Print();
		~Student();

	protected:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int studentAge;
		int* daysInCourseArray;
		Degree degreeType;
};

#endif /* STUDENT_H */
