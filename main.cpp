#include <iostream>
#include <iomanip>
#include "studentmanager.h"
void printMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1.Add Student " << std::endl;
    std::cout << "2. Modify student data" << std::endl;
    std::cout << "3. Remove student data" << std::endl;
    std::cout << "4. Display all student data" << std::endl;
    std::cout << "5. Find students with highest and lowest success" << std::endl;
    std::cout << "6. Save data to file" << std::endl;
    std::cout << "7. Load data from file" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    StudentManager studentManager;

    int choice;
    do {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch (choice) {
        case 1: {
            
            std::string fullName, birthDate, faculty, department, group, studentID;
            int admissionYear;
            char gender;

            std::cout << "Введите ФИО студента: ";
            std::getline(std::cin, fullName);
            std::cout << "Введите дату рождения студента (дд.мм.гггг): ";
            std::getline(std::cin, birthDate);
            std::cout << "Введите год поступления в институт: ";
            std::cin >> admissionYear;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Введите факультет студента: ";
            std::getline(std::cin, faculty);
            std::cout << "Введите кафедру студента: ";
            std::getline(std::cin, department);
            std::cout << "Введите группу студента: ";
            std::getline(std::cin, group);
            std::cout << "Введите номер зачетной книжки студента: ";
            std::getline(std::cin, studentID);
            std::cout << "Введите пол студента (M - мужской, F - женский): ";
            std::cin >> gender;
            Student student(fullName, birthDate, admissionYear, faculty, department, group, studentID, gender, addMark);

            // Добавляем оценки за предметы
            std::string subject;
            int mark;
            char addMark;
            do {
                std::cout << "Введите предмет: ";
                std::cin >> subject;
                std::cout << "Введите оценку за предмет: ";
                std::cin >> mark;
                student.addMark(subject, mark);
                std::cout << "Хотите добавить еще один предмет? (y/n): ";
                std::cin >> addMark;
            } while (addMark == 'y' || addMark == 'Y');


            Student student(fullName, birthDate, admissionYear, faculty, department, group, studentID, gender);
            studentManager.addStudent(student);
            std::cout << "Студент успешно добавлен." << std::endl;
            break;
        }
        case 2: {
            std::string studentID;
            std::cout << "Введите номер зачетной книжки студента, данные которого хотите изменить: ";
            std::getline(std::cin, studentID);

            if (studentManager.modifyStudent(studentID)) {
                std::cout << "Данные студента успешно изменены." << std::endl;
            }
            else {
                std::cout << "Студент с указанным номером зачетной книжки не найден." << std::endl;
            }
            
            break;
        }
        case 3: {
            std::string studentID;
            std::cout << "Введите номер зачетной книжки студента, которого хотите удалить: ";
            std::getline(std::cin, studentID);

            if (studentManager.removeStudent(studentID)) {
                std::cout << "Студент успешно удален." << std::endl;
            }
            else {
                std::cout << "Студент с указанным номером зачетной книжки не найден." << std::endl;
            }
            break;
        }
        case 4: {
            // Вывод данных всех студентов
            studentManager.printAllStudents();
            break;
        }
        case 5: {
            // Поиск студентов с наибольшим и наименьшим успехом
            studentManager.printStudentsWithTopAndBottomGrades();
            break;
        }
        case 6: {
            // Сохранение данных в файл
            studentManager.saveToFile("students.txt");
            std::cout << "Данные успешно сохранены в файл." << std::endl;
            break;
        }
        case 7: {
            // Загрузка данных из файла
            studentManager.loadFromFile("students.txt");
            std::cout << "Данные успешно загружены из файла." << std::endl;
            break;
        }
        case 8:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Ошибка: неверный выбор. Попробуйте еще раз." << std::endl;
            break;
        }
    } while (choice != 8);

    return 0;
}
