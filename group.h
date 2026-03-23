#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include "student.h"

class Group {
private:
    std::vector<Student> students;

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

