#include "editing.hpp" // Подключение заголовочного файла с определением структуры EMPLOYEE и функциями проверки

// Функция для добавления нового сотрудника в вектор
void Add(vector<EMPLOYEE>& employees) {
    EMPLOYEE newEmpl; // Создание нового объекта структуры EMPLOYEE
    string input; // Строка для временного хранения ввода пользователя

    try {
        // Инструкции по вводу данных
        cout << "Вводите значения только латинскими символами!" << endl;
        // Запрос и проверка имени
        cout << "Введите имя: ";
        cin >> newEmpl.name;
        CheckName(newEmpl.name);
        // Запрос и проверка фамилии
        cout << "Введите фамилию: ";
        cin >> newEmpl.surname;
        CheckName(newEmpl.surname);
        // Запрос и проверка отчества
        cout << "Введите отчество: ";
        cin >> newEmpl.father_name;
        CheckName(newEmpl.father_name);
        // Запрос и преобразование табельного номера
        cout << "Введите табельный номер: ";
        cin >> input;
        newEmpl.number = stoi(input);
        // Запрос и преобразование года
        cout << "Введите год: ";
        cin >> input;
        newEmpl.year = stoi(input);
        // Запрос и преобразование месяца
        cout << "Введите месяц: ";
        cin >> input;
        newEmpl.month = stoi(input);
        // Запрос и преобразование количества часов
        cout << "Введите количество проработанных часов: ";
        cin >> input;
        newEmpl.amount_hours = stof(input);
        // Запрос и преобразование почасового тарифа
        cout << "Введите почасовой тариф: ";
        cin >> input;
        newEmpl.tarif = stof(input);
        
        // Проверка корректности введенного месяца и года
        if (Month_Check(newEmpl.month) == -1 || Year_Check(newEmpl.year) == -1) {
            cout << "Вы ввели неверные значения месяца или года. " << endl;
            return;
        }
            
        employees.push_back(newEmpl); // Добавление нового сотрудника в вектор
        cout << "Сотрудник успешно добавлен." << endl;
    } catch (const exception& e) {
        cout << "Ошибка при вводе данных. " << endl;
    }
}

// Функция для редактирования данных существующего сотрудника
void Edit(vector<EMPLOYEE>& employees){
    int number_edit; // Переменная для хранения табельного номера сотрудника
    string input; // Строка для хранения ввода пользователя
    
    // Проверка наличия сотрудников в векторе
    if (!None(employees)) {
        return; // Если сотрудников нет, выходим из функции
    }
    
    // Запрос табельного номера сотрудника для редактирования
    cout << "Введите табельный номер сотрудника для редактирования: ";
    cin >> number_edit;

    // Перебор всех сотрудников в векторе
    for (auto& empl : employees) {
        // Поиск сотрудника по табельному номеру
        if (empl.number == number_edit) {
            cout << "Редактирование сотрудника с номером " << number_edit << ":" << endl;
            
            // Блок try-catch для обработки исключений при вводе
            try {
                // Инструкция о формате ввода
                cout << "Вводите значения только латинскими символами!" << endl;
                // Редактирование имени сотрудника
                cout << "Текущее имя: " << empl.name << ". Введите новое имя или '-' для пропуска: ";
                cin >> input;
                if (input != "-") empl.name = input;
                CheckName(empl.name); // Проверка корректности имени
                // Редактирование фамилии сотрудника
                cout << "Текущая фамилия: " << empl.surname << ". Введите новую фамилию или '-' для пропуска: ";
                cin >> input;
                if (input != "-") empl.surname = input;
                CheckName(empl.surname); // Проверка корректности фамилии
                // Редактирование отчества сотрудника
                cout << "Текущее отчество: " << empl.father_name << ". Введите новое отчество или '-' для пропуска: ";
                cin >> input;
                if (input != "-") empl.father_name = input;
                CheckName(empl.father_name); // Проверка корректности отчества
                // Редактирование года рождения сотрудника
                cout << "Текущий год: " << empl.year << ". Введите новый год или '-' для пропуска: ";
                cin >> input;
                if (input != "-") empl.year = stoi(input);
                // Редактирование месяца рождения сотрудника
                cout << "Текущий месяц: " << empl.month << ". Введите новый месяц или '-' для пропуска: ";
                cin >> input;
                if (input != "-") empl.month = stoi(input);
                // Редактирование количества проработанных часов
                cout << "Текущее количество часов: " << empl.amount_hours << ". Введите новое количество часов или '-' для пропуска: ";
                cin >> input;
                if (input != "-") empl.amount_hours = stof(input);
                // Редактирование почасового тарифа
                cout << "Текущий почасовой тариф: " << empl.tarif << ". Введите новый тариф или '-' для пропуска: ";
                cin >> input;
                if (input != "-") empl.tarif = stof(input);
                
                // Проверка корректности введенного месяца и года
                if (Month_Check(empl.month) == -1 || Year_Check(empl.year) == -1) {
                    cout << "Вы ввели неверные значения месяца или года. " << endl;
                    return; // Выход из функции, если значения некорректны
                }
                cout << "Запись сотрудника обновлена." << endl; // Сообщение об успешном обновлении данных
            }
            catch (const exception& e) {
                cout << "Ошибка при вводе данных. " << endl; // Сообщение об ошибке при вводе
                return;
            }
            return; // Выход из функции после редактирования данных
        }
    }
    // Если сотрудник с указанным номером не найден
    cout << "Сотрудник с номером " << number_edit << " не найден." << endl;
}

// Функция для удаления сотрудника из вектора
void Remove(vector<EMPLOYEE>& employees){
    // Объявление переменных для хранения ввода пользователя
    int number_remove, month_remove, year_remove;
    string answear, input;
    bool flag = false; // Флаг для отслеживания наличия сотрудника
    
    // Проверка наличия сотрудников в векторе
    if (!None(employees)) {
        return; // Если сотрудников нет, выходим из функции
    }

    // Блок try-catch для обработки исключений при вводе
    try{
        // Запрос табельного номера сотрудника для удаления
        cout << "Введите табельный номер сотрудника для удаления: ";
        cin >> input;
        number_remove = stoi(input);
        // Запрос месяца и года для более точного удаления
        cout << "Введите месяц: ";
        cin >> input;
        month_remove = stoi(input);
        cout << "Введите год: ";
        cin >> input;
        year_remove = stoi(input);
        
        // Проверка корректности введенного месяца и года
        if (Month_Check(month_remove) == -1 || Year_Check(year_remove) == -1) {
            cout << "Вы ввели неверные значения месяца или года. " << endl;
            return;
        }
    }
    catch (const exception& e) {
        cout << "Ошибка при вводе данных. " << endl;
    }
    
    // Перебор сотрудников для поиска и удаления
    for (auto empl = employees.begin(); empl != employees.end(); ) {
        // Проверка соответствия номера, месяца и года
        if (empl->number == number_remove && empl->month == month_remove && empl->year == year_remove) {
            flag = true; // Сотрудник найден
            // Запрос подтверждения удаления
            cout << "Вы действительно хотите удалить запись сотрудника " << empl->surname << " " <<
                empl->name << "? (да/нет)" << endl;
            cin >> answear;
            // Преобразование ответа в нижний регистр
            transform(answear.begin(), answear.end(), answear.begin(), ::tolower);
            
            // Удаление сотрудника, если получено подтверждение
            if (answear == "да") {
                empl = employees.erase(empl);
                cout << "Запись удалена " << endl;
                break;
            } else if (answear == "нет") {
                cout << "Удаление отменено." << endl;
                break;
            } else {
                cout << "Введено неправильное значение. Введите 'да' или 'нет'" << endl;
                empl--; // Возврат к предыдущему элементу для повторного запроса
            }
        } else {
            empl++; // Переход к следующему сотруднику
        }
    }
    // Если сотрудник не найден
    if (!flag) {
        cout << "Запись не найдена. " << endl;
        cout << "----------" << endl;
    }
}

// Функция для вывода списка всех сотрудников
void Print(vector<EMPLOYEE>& employees){
    int index = 0; // Счетчик для нумерации записей
    
    // Проверка наличия сотрудников в векторе
    if (!None(employees)){
        return; // Если сотрудников нет, выходим из функции
    }
    
    // Вывод информации о каждом сотруднике
    cout << "Список сотрудников:" << endl;
    for (const auto& empl: employees) {
        index += 1; // Увеличение счетчика
        // Вывод данных сотрудника
        cout << "Запись №" << index << endl;
        cout << "Фамилия: " << empl.surname << endl;
        cout << "Имя: " << empl.name << endl;
        cout << "Отчество: " << empl.father_name << endl;
        cout << "Табельный номер: " << empl.number << endl;
        cout << "Год: " << empl.year << endl;
        cout << "Месяц: " << empl.month << endl;
        cout << "Количество часов: " << empl.amount_hours << endl;
        cout << "Почасовой тариф: " << empl.tarif << endl;
        cout << "---------------------" << endl;
    }
}
