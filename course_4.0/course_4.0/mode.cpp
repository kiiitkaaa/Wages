#include "mode.hpp"

// Функция Mode1 отвечает за режим редактирования записей сотрудников
void Mode1 (vector<EMPLOYEE>& employees) {
    int mode; // Переменная для хранения выбора пользователя
    
    // Вывод меню редактирования
    cout << "----------" << endl;
    cout << "1. Вывести все записи. " << endl;
    cout << "2. Добавить запись. " << endl;
    cout << "3. Удалить запись. " << endl;
    cout << "4. Редактировать запись. " << endl;
    cout << "5. Назад. " << endl;
    mode = Enter_Check(); // Получение выбора пользователя
    cout << "----------" << endl;
    
    // Обработка выбора пользователя
    switch (mode) {
        case 1:
            Print(employees); // Вывод всех записей
            break;
        case 2:
            Add(employees); // Добавление новой записи
            break;
        case 3:
            Remove(employees); // Удаление записи
            break;
        case 4:
            Edit(employees); // Редактирование записи
            break;
        case 5:
            // Возврат в предыдущее меню
            break;
        default:
            // Сообщение об ошибке при неверном вводе
            cout << "Неверное значение. Попробуйте ещё. " << endl;
            break;
    }
}

// Функция Mode2 отвечает за режим обработки данных сотрудников
void Mode2(vector<EMPLOYEE>& employees) {
    int mode; // Переменная для хранения выбора пользователя
    
    // Вывод меню обработки данных
    cout << "----------" << endl;
    cout << "1. Расчёт размера заработной платы каждого сотрудника. " << endl;
    cout << "2. Подсчёт объёма выплат конкретному сотруднику за требуемый период времени. " << endl;
    cout << "3. Сортивовка данных. " << endl;
    cout << "4. Поиск данных. " << endl;
    cout << "5. Назад. " << endl;
    mode = Enter_Check(); // Получение выбора пользователя
    cout << "----------" << endl;
    
    // Обработка выбора пользователя
    switch (mode) {
        case 1:
            FoundForSalary(employees); // Расчёт зарплаты
            break;
        case 2:
            Payment(employees); // Подсчёт выплат
            break;
        case 3:
            Sort(employees); // Сортировка данных
            break;
        case 4:
            Search(employees); // Поиск данных
            break;
        case 5:
            // Возврат в предыдущее меню
            break;
        default:
            // Сообщение об ошибке при неверном вводе
            cout << "Неверное значение. Попробуйте ещё. " << endl;
            break;
    }
    
}


// Функция Admin для работы с данными сотрудников в режиме администратора
void Admin(vector<EMPLOYEE>& employees){
    bool exit = false; // Флаг для выхода из цикла меню
    int choice; // Переменная для хранения выбора пользователя
    
    // Цикл для работы с меню администратора
    while (!exit) {
        
        // Вывод основного меню администратора
        cout << "Меню: " << endl;
        cout << "1. Режим редактирования " << endl;
        cout << "2. Режим обработки " << endl;
        cout << "3. Выход " << endl;
        choice = Enter_Check(); // Получение выбора пользователя и проверка на корректность
        
        // Обработка выбора пользователя в меню администратора
        switch (choice) {
            case 1:
                Mode1(employees); // Переход в режим редактирования данных сотрудников
                break;
            case 2:
                Mode2(employees); // Переход в режим обработки данных сотрудников
                break;
            case 3:
                exit = true; // Установка флага для выхода из цикла меню
                break;
            default:
                // Сообщение об ошибке при неверном выборе в меню
                cout << "Неверное значение. Введите 1, 2 или 3." << endl;
                break;
        }
    }
}

// Функция User для работы с данными сотрудников в режиме пользователя
void User(vector<EMPLOYEE>& employees){
    bool exit = false; // Флаг для выхода из цикла меню
    int choice; // Переменная для хранения выбора пользователя
    
    // Цикл для работы с меню пользователя
    while (!exit) {
        
        // Вывод основного меню пользователя
        cout << "Меню: " << endl;
        cout << "1. Вывести все записи. " << endl;
        cout << "2. Сортировка данных. " << endl;
        cout << "3. Поиск данных. " << endl;
        cout << "4. Выход " << endl;
        choice = Enter_Check(); // Получение выбора пользователя и проверка на корректность
        
        // Обработка выбора пользователя в меню пользователя
        switch (choice) {
            case 1:
                Print(employees); // Вывод всех записей о сотрудниках
                break;
            case 2:
                Sort(employees); // Сортировка данных о сотрудниках
                break;
            case 3:
                Search(employees); // Поиск данных среди записей о сотрудниках
                break;
            case 4:
                exit = true; // Установка флага для выхода из цикла меню
                break;
            default:
                // Сообщение об ошибке при неверном выборе в меню
                cout << "Неверное значение. Введите 1, 2, 3 или 4." << endl;
                break;
        }
    }
}

// Функция Auth для авторизации пользователя
int Auth() {
    int att = 0; // Счетчик попыток ввода
    bool enter = false; // Флаг успешной авторизации
    string login, password; // Переменные для хранения логина и пароля
    
    // Цикл авторизации с ограничением по количеству попыток
    while (!enter) {
        if (att == 3) {
            cout << "Доступ запрещён." << endl;
            return 0; // Возврат 0 при исчерпании попыток
        }
        
        // Запрос учетных данных у пользователя
        cout << "Авторизация." << endl;
        cout << "Введите логин: ";
        cin >> login;
        cout << "Введите пароль: ";
        cin >> password;
        
        // Проверка учетных данных
        if (login == "admin" && password == "password") {
            cout << "Вы вошли как администратор." << endl;
            return 1; // Возврат 1 при успешной авторизации администратора
        }
        else if (login == "user" && password == "password") {
            cout << "Вы вошли как пользователь." << endl;
            return 2; // Возврат 2 при успешной авторизации пользователя
        }
        else {
            // Сообщение об ошибке при неверных учетных данных
            cout << "Неверный логин или пароль." << endl;
            att += 1; // Увеличение счетчика попыток
            cout << "Осталось попыток: " << 3 - att << endl;
        }
    }
    return 0; // Возврат 0, если авторизация не удалась
}
