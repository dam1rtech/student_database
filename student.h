#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Student {
private:
    std::string fullName;
    std::string birthDate;
    int admissionYear;
    std::string faculty;
    std::string department;
    std::string group;
    std::string studentID;
    char gender;
    std::vector<std::pair<std::string, int>> subjectsAndGrades; 

public:
    
    Student(const std::string& fullName, const std::string& birthDate, int admissionYear,
        const std::string& faculty, const std::string& department, const std::string& group,
        const std::string& studentID, char gender);

    
    std::string getFullName() const;
    std::string getBirthDate() const;
    int getAdmissionYear() const;
    std::string getFaculty() const;
    std::string getDepartment() const;
    std::string getGroup() const;
    std::string getStudentID() const;
    char getGender() const;
    std::vector<std::pair<std::string, int>> getSubjectsAndGrades() const;

   
    void addSubjectGrade(const std::string& subject, int grade);
    void modifySubjectGrade(const std::string& subject, int grade);

  
    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);
};

#endif 

