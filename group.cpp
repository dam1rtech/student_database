#include "group.h"
#include <algorithm>
#include <iomanip>
void Group::addStudent(const Student& student) {
    students.push_back(student);
}

void Group::modifyStudent(const std::string& studentID, const Student& modifiedStudent) {
    for (auto& student : students) {
        if (student.getStudentID() == studentID) {
            student = modifiedStudent;
            return;
        }
    }
    std::cout << "The student with the specified credit card number was not found." << std::endl;
}

void Group::removeStudent(const std::string& studentID) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getStudentID() == studentID) {
            it = students.erase(it);
            std::cout << "The student has been successfully deleted." << std::endl;
            return;
        }
    }
    std::cout << "The student with the specified credit card number was not found." << std::endl;
}

void Group::printAllStudents() const {
    if (students.empty()) {
        std::cout << "The group of students is empty." << std::endl;
        return;
    }
    std::cout << "Data of all students:" << std::endl;
    for (const auto& student : students) {
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "FIO: " << student.getFullName() << std::endl;
        std::cout << "Date of birth: " << student.getBirthDate() << std::endl;
        std::cout << "Year of enter: " << student.getAdmissionYear() << std::endl;
        std::cout << "Institute: " << student.getFaculty() << std::endl;
        std::cout << "Kafedra: " << student.getDepartment() << std::endl;
        std::cout << "Group: " << student.getGroup() << std::endl;
        std::cout << "Number of specified credit card: " << student.getStudentID() << std::endl;
        std::cout << "Gender: " << (student.getGender() == 'M' ? "Male" : "женский") << std::endl;
        std::cout << "Subjects and marks:" << student.getSubjectsAndGrades()<< std::endl;
        for (const auto& subjectGrade : student.getSubjectsAndGrades()) {
            std::cout << subjectGrade.first << ": " << subjectGrade.second << std::endl;
        }
        std::cout << "-------------------------------------------" << std::endl;
    }
}

void Group::printStudentsWithTopAndBottomGrades() const {
    if (students.empty()) {
        std::cout << "The group of students is empty." << std::endl;
        return;
    }
    std::vector<const Student*> studentsPtr;
    for (const auto& student : students) {
        studentsPtr.push_back(&student);
    }

 
    std::sort(studentsPtr.begin(), studentsPtr.end(), [](const Student* a, const Student* b) {
        double avgA = 0.0, avgB = 0.0;
        for (const auto& subjectGrade : a->getSubjectsAndGrades()) {
            avgA += subjectGrade.second;
        }
        avgA /= a->getSubjectsAndGrades().size();

        for (const auto& subjectGrade : b->getSubjectsAndGrades()) {
            avgB += subjectGrade.second;
        }
        avgB /= b->getSubjectsAndGrades().size();

        return avgA > avgB;
        });

    std::cout << "The students with the most success:" << std::endl;
    for (int i = 0; i < 3 && i < studentsPtr.size(); ++i) {
        std::cout << "FIO: " << studentsPtr[i]->getFullName() << ", Average score: ";
        double avgGrade = 0.0;
        for (const auto& subjectGrade : studentsPtr[i]->getSubjectsAndGrades()) {
            avgGrade += subjectGrade.second;
        }
        avgGrade /= studentsPtr[i]->getSubjectsAndGrades().size();
        std::cout << std::fixed << std::setprecision(2) << avgGrade << std::endl;
    }

    std::cout << "The students with the least success:" << std::endl;
    for (int i = studentsPtr.size() - 1; i >= std::max((int)studentsPtr.size() - 3, 0); --i) {
        std::cout << "FIO: " << studentsPtr[i]->getFullName() << ", Average score: ";
        double avgGrade = 0.0;
        for (const auto& subjectGrade : studentsPtr[i]->getSubjectsAndGrades()) {
            avgGrade += subjectGrade.second;
        }
        avgGrade /= studentsPtr[i]->getSubjectsAndGrades().size();
        std::cout << std::fixed << std::setprecision(2) << avgGrade << std::endl;
    }
}

void Group::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erorr: could not open the file to save the data." << std::endl;
        return;
    }

    for (const auto& student : students) {
        student.saveToFile(file);
    }

    file.close();
}

void Group::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erorr: could not open the file to load the data." << std::endl;
        return;
    }

    students.clear(); 

    while (file.peek() != EOF) {
        Student student("", "", 0, "", "", "", "", 'M');
        student.loadFromFile(file);
        addStudent(student);
    }

    file.close();
}
