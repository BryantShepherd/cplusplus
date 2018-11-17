
/*GOAL: Practice writing and calling functions

*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
//main.h 
class Student
{
    int studentID;
    int grades[10];
    public:     
        void setStudentID(int _id) {
            studentID = _id;
        }
        void setGrade(int n, int _grade) {
            grades[n] = _grade;
        }
        void printGrades() {
            for (int i = 0; i < 10; i++){
                cout << grades[i] << " ";
            } 
        }
        int getMin() {
            sort(grades, grades + 9);
            return grades[0];
        }
        int getMax() {
            sort(grades, grades + 9);
            return grades[9];
        }
        double getAverageGrade() {
            double sum = 0;
            for (int i = 0; i < 10; i++) {
                sum += grades[i];
            }
            return sum/10; 
        }
};

//********************
class CourseEnrollment
{
    public:
    Student students[6];
    void addStudents(Student _stu[]) {
        for (int i = 0; i < 6; i++) {
            students[i] = _stu[i];
        }
    }
    int courseMinGrade;
    int courseMaxGrade;
    float courseAvgGrade;
    int grades[60];

};

const int CLASS_SIZE = 6;

int main()
{
    //Use two classes, student and courseEnrollment
    Student studentsInClass[CLASS_SIZE];
    CourseEnrollment course1;
    
    //there are 100 students to be enrolled
    static int studentNumber = 1000;
    int grade;
    int userInput;

    //asign student id to each student
    for(int i = 0; i < CLASS_SIZE; i++)
    {
        studentsInClass[i].setStudentID(studentNumber);
        studentNumber++;
    }

    //assign grades to all students
    for(int i = 0; i <CLASS_SIZE; i++)
    {
      for(int j = 0; j <10 ; j++)
        {
            scanf("%d", &grade);
            studentsInClass[i].setGrade(j,grade);
        }  
    }
    
    //print out all students grades
    for(int i = 0; i < CLASS_SIZE; i++)
    {
        studentsInClass[i].printGrades();
        std::cout<<"\nMin grade = "<<studentsInClass[i].getMin()<<"\n";
        std::cout<<"Max grade = "<<studentsInClass[i].getMax()<<"\n";
        std::cout<<"Grade Average = "<<studentsInClass[i].getAverageGrade()<<"\n\n";
    }
    
    course1.addStudents(studentsInClass);
    
    int *allGrades;
    allGrades = course1.getAllGrades();
    allGrades = course1.sortAllGrades();
    std::cout<<"ALLGRADES\n";
    std::cout<<"Lowest grade for entire course = "<<course1.getMinGrade()<<"\n";
    std::cout<<"Highest grade for entire course = "<<course1.getMaxGrade()<<"\n";
    std::cout<<"Avg grade for entire course = "<<course1.getAvgGrade()<<"\n";
    return 0;
}
