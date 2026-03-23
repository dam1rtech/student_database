#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "group.h"

class StudentManager {
private:
    Group group;

public:
  
    void addStudent(const Student& student);
    void modifyStudent(const std::string& studentID, const Student& modifiedStudent);
    void removeStudent(const std::string& studentID);


    void printAllStudents() const;
    void printStudentsWithTopAndBottomGrades() const;


    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif 

