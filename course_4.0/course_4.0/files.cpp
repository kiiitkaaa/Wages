#include "files.hpp" // Подключение заголовочного файла с определением структуры EMPLOYEE и прототипами функций

// Функция для чтения данных о сотрудниках из файла
void ReadFile(vector<EMPLOYEE>& employees){
    ifstream file_in("employees.txt"); // Поток для чтения файла
    
    // Проверка успешности открытия файла
    if (!file_in) {
        cerr << "Не удалось открыть файл для чтения." << endl;
        return; // Выход из функции, если файл не открылся
    }

    EMPLOYEE emp; // Временная переменная для хранения данных сотрудника
    // Чтение данных из файла и заполнение вектора employees
    while (file_in >> emp.surname >> emp.name >> emp.father_name
                   >> emp.number >> emp.year >> emp.month
                   >> emp.amount_hours >> emp.tarif) {
        employees.push_back(emp); // Добавление сотрудника в вектор
    }

    file_in.close(); // Закрытие файла после чтения
}

// Функция для записи данных о сотрудниках в файл
void WriteFile(vector<EMPLOYEE>& employees){
    
    // Проверка наличия записей перед записью в файл
    if (!None(employees)) {
        return; // Выход из функции, если записей нет
    }

    ofstream fout("employees.txt"); // Поток для записи в файл

    // Проверка успешности открытия файла
    if (fout.is_open()) {
        // Запись данных каждого сотрудника в файл
        for (const auto& emp : employees) {
            fout << emp.surname << " " << emp.name << " " << emp.father_name << " " << emp.number
                 << " " << emp.year << " " << emp.month << " " << emp.amount_hours << " " << emp.tarif << endl;
        }

        fout.close(); // Закрытие файла после записи
        cout << "Данные успешно записаны в файл employees.txt" << endl;
    } else {
        cout << "Ошибка открытия файла для записи." << endl;
    }
}
