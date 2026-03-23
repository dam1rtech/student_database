#include "student.h"
#include <iomanip>


Student::Student(const std::string& fullName, const std::string& birthDate, int admissionYear,
    const std::string& faculty, const std::string& department, const std::string& group,
    const std::string& studentID, char gender)
    : fullName(fullName), birthDate(birthDate), admissionYear(admissionYear),
    faculty(faculty), department(department), group(group),
    studentID(studentID), gender(gender) {}


std::string Student::getFullName() const {
    return fullName;
}

std::string Student::getBirthDate() const {
    return birthDate;
}

int Student::getAdmissionYear() const {
    return admissionYear;
}

std::string Student::getFaculty() const {
    return faculty;
}

std::string Student::getDepartment() const {
    return department;
}

std::string Student::getGroup() const {
    return group;
}

std::string Student::getStudentID() const {
    return studentID;
}

char Student::getGender() const {
    return gender;
}

std::vector<std::pair<std::string, int>> Student::getSubjectsAndGrades() const {
    return subjectsAndGrades;
}


void Student::addSubjectGrade(const std::string& subject, int grade) {
    subjectsAndGrades.push_back(std::make_pair(subject, grade));
}

void Student::modifySubjectGrade(const std::string& subject, int grade) {
    for (auto& pair : subjectsAndGrades) {
        if (pair.first == subject) {
            pair.second = grade;
            return;
        }
    }
    std::cout << "Erorr: the subject \"" << subject << "\" is not found." << std::endl;
}


void Student::saveToFile(std::ofstream& file) const {
    file << fullName << std::endl;
    file << birthDate << std::endl;
    file << admissionYear << std::endl;
    file << faculty << std::endl;
    file << department << std::endl;
    file << group << std::endl;
    file << studentID << std::endl;
    file << gender << std::endl;
    file << subjectsAndGrades.size() << std::endl;
    for (const auto& subjectGrade : subjectsAndGrades) {
        file << subjectGrade.first << " " << subjectGrade.second << std::endl;
    }
}

void Student::loadFromFile(std::ifstream& file) {
    std::getline(file, fullName);
    std::getline(file, birthDate);
    file >> admissionYear;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(file, faculty);
    std::getline(file, department);
    std::getline(file, group);
    std::getline(file, studentID);
    file >> gender;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int subjectsAndGradesCount;
    file >> subjectsAndGradesCount;
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    subjectsAndGrades.clear();
    for (int i = 0; i < subjectsAndGradesCount; ++i) {
        std::string subject;
        int grade;
        file >> subject >> grade;
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        subjectsAndGrades.push_back(std::make_pair(subject, grade));
    }
}
