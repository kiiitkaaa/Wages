#include "search.hpp"

// Функция для поиска сотрудника по ФИО
void Search1(vector<EMPLOYEE>& employees) {
    // Объявление переменных для хранения данных для поиска
    bool flag = false;
    string name_search, surname_search, father_name_search;
    
    try {
        cout << "Вводите значения только латинскими символами!" << endl;
        cout << "Введите фамилию сотрудника: ";
        cin >> surname_search;
        CheckName(surname_search);
        cout << "Введите имя сотрудника: ";
        cin >> name_search;
        CheckName(name_search);
        cout << "Введите отчество сотрудника: ";
        cin >> father_name_search;
        CheckName(father_name_search);
    }
    catch (const exception& e) {
        cout << "Ошибка при вводе данных. " << endl;
        return;
    }
    
    for (auto empl = employees.begin(); empl != employees.end(); empl++) {
        if (empl->surname == surname_search && empl->name == name_search && empl->father_name == father_name_search) {
            cout << "Фамилия: " << empl->surname << endl;
            cout << "Имя: " << empl->name << endl;
            cout << "Отчество: " << empl->father_name << endl;
            cout << "Табельный номер: " << empl->number << endl;
            cout << "Год: " << empl->year << endl;
            cout << "Месяц: " << empl->month << endl;
            cout << "Количество часов: " << empl->amount_hours << endl;
            cout << "Почасовой тариф: " << empl->tarif << endl;
            cout << "---------------------" << endl;
            flag = true;
        }
    }
    
    if (!flag) {
        cout << "Данные не найдены" << endl;
        cout << "----------" << endl;
    }
}

// Функция для поиска сотрудника по дате
void Search2(vector<EMPLOYEE>& employees) {
    bool flag = false;
    int month_search, year_search;
    
    cout << "Введите месяц: ";
        if (!(cin >> month_search)) {
            cin.clear(); // Сбрасываем флаг ошибки cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем оставшийся ввод до конца строки
            cout << "Ошибка: введено не число." << endl;
            return; // Выходим из функции, если введено не число
        }
        
        cout << "Введите год: ";
        if (!(cin >> year_search)) {
            cin.clear(); // Сбрасываем флаг ошибки cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем оставшийся ввод до конца строки
            cout << "Ошибка: введено не число." << endl;
            return; // Выходим из функции, если введено не число
        }
    
    for (auto empl = employees.begin(); empl != employees.end(); empl++) {
        if (empl->month == month_search && empl->year == year_search) {
            cout << "Фамилия: " << empl->surname << endl;
            cout << "Имя: " << empl->name << endl;
            cout << "Отчество: " << empl->father_name << endl;
            cout << "Табельный номер: " << empl->number << endl;
            cout << "Год: " << empl->year << endl;
            cout << "Месяц: " << empl->month << endl;
            cout << "Количество часов: " << empl->amount_hours << endl;
            cout << "Почасовой тариф: " << empl->tarif << endl;
            cout << "---------------------" << endl;
            flag = true;
        }
    }
    
    if (!flag) {
        cout << "Данные не найдены" << endl;
        cout << "----------" << endl;
    }
}

// Функция для поиска сотрудника по тарифу
void Search3(vector<EMPLOYEE>& employees) {
    bool flag = true;
    int tarif_search;
    
    cout << "Введите почасовой тариф: ";
    cin >> tarif_search;
    if (cin.fail()) {
            cin.clear(); // Сбрасываем флаг ошибки cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем оставшийся ввод до конца строки
            cout << "Ошибка: введено не число." << endl;
            return; // Выходим из функции, если введено не число
        }
    
    for (auto empl = employees.begin(); empl != employees.end(); empl++) {
        if (empl->tarif == tarif_search) {
            cout << "Фамилия: " << empl->surname << endl;
            cout << "Имя: " << empl->name << endl;
            cout << "Отчество: " << empl->father_name << endl;
            cout << "Табельный номер: " << empl->number << endl;
            cout << "Год: " << empl->year << endl;
            cout << "Месяц: " << empl->month << endl;
            cout << "Количество часов: " << empl->amount_hours << endl;
            cout << "Почасовой тариф: " << empl->tarif << endl;
            cout << "---------------------" << endl;
            flag = true;
        }
    }
    
    if (!flag) {
        cout << "Данные не найдены" << endl;
        cout << "----------" << endl;
    }
}
