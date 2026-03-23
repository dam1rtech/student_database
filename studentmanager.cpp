#include "studentmanager.h"

void StudentManager::addStudent(const Student& student) {
    group.addStudent(student);
}

void StudentManager::modifyStudent(const std::string& studentID, const Student& modifiedStudent) {
    group.modifyStudent(studentID, modifiedStudent);
}

void StudentManager::removeStudent(const std::string& studentID) {
    group.removeStudent(studentID);
}

void StudentManager::printAllStudents() const {
    group.printAllStudents();
}

void StudentManager::printStudentsWithTopAndBottomGrades() const {
    group.printStudentsWithTopAndBottomGrades();
}

void StudentManager::saveToFile(const std::string& filename) const {
    group.saveToFile(filename);
}

void StudentManager::loadFromFile(const std::string& filename) {
    group.loadFromFile(filename);
}
