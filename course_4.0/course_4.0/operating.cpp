#include "operating.hpp"

// Функция для расчета зарплаты сотрудника
double Salary(EMPLOYEE empl) {
    double sal = 0;
    
    // Если количество отработанных часов больше 144, применяется повышенный тариф
    if (empl.amount_hours > 144) {
         sal = 144 * empl.tarif + 2 * (empl.amount_hours - 144) * empl.tarif;
        return sal;
    }
    else {
        // Иначе зарплата рассчитывается по стандартному тарифу
        sal = empl.amount_hours * empl.tarif;
        return sal;
    }
    // В случае ошибки в логике, функция вернет 0
    return 0;
}

// Функция для расчета зарплаты сотрудника с учетом налога
double SalaryTax(EMPLOYEE empl) {
    double salary = 0, sal_tax = 0;
    salary = Salary(empl);
    // Налог составляет 12% от зарплаты
    sal_tax = salary - (salary * 0.12);
     
    return sal_tax;
}

// Функция для вывода информации о зарплате всех сотрудников
void FoundForSalary(vector<EMPLOYEE>& employees) {
    // Проверка на наличие сотрудников
    if (!None(employees)) {
        return;
    }
    
    // Сортировка сотрудников по табельному номеру
    sort(employees.begin(), employees.end(), [](const EMPLOYEE& a, const EMPLOYEE& b) {
        return a.number < b.number;
      });

    cout << "Заработная плата всех сотрудников по месяцам. " << endl;
    cout << "----------" << endl;

    // Вектор для хранения уже обработанных номеров сотрудников
    vector<int> processedNumbers;

    for (const auto& empl : employees) {
        // Проверка, была ли уже обработана информация о сотруднике
        if (find(processedNumbers.begin(), processedNumbers.end(), empl.number) == processedNumbers.end()) {
            // Вывод информации о сотруднике
            cout << empl.surname << " " << empl.name << " " << empl.number << endl;
            // Добавление номера сотрудника в список обработанных
            processedNumbers.push_back(empl.number);
        }
        
        cout << empl.month << "." << empl.year << endl;
        cout << "Заработная плата без учёта налога за месяц: " << Salary(empl) << endl;
        cout << "Заработная плата с учётом налога за месяц: " << SalaryTax(empl) << endl;
        cout << "----------" << endl;
    }
}

// Функция для расчета общей суммы выплат сотруднику за определенный период
void Payment(vector<EMPLOYEE>& employees){
    // Объявление переменных для хранения вводимых данных
    int panumber, start_year, start_month, end_year, end_month;
    string input;
    float total_payment = 0.0;
    
    // Блок try-catch для обработки исключений при вводе данных
    try {
        cout << "Введите табельный номер сотрудника: ";
        cin >> input;
        panumber = stoi(input);
        cout << "Введите год начала периода: ";
        cin >> input;
        start_year = stoi(input);
        cout << "Введите месяц начала периода: ";
        cin >> input;
        start_month = stoi(input);
        cout << "Введите год конца периода: ";
        cin >> input;
        end_year = stoi(input);
        cout << "Введите месяц конца периода: ";
        cin >> input;
        end_month = stoi(input);
    }
    catch (const exception& e) {
        // Обработка ошибки ввода
        cout << "Ошибка при вводе данных. " << endl;
        return;
    }
    
    // Проверки корректности введенных данных
    if (Month_Check(start_month) == -1 || Month_Check(end_month) == -1 || Year_Check(start_year) == -1 || Year_Check(end_year) == -1) {
        cout << "Вы ввели неверные значения месяца или года. " << endl;
        return;
    }
    if (start_year > end_year) {
        cout << "Вы ввели неверные значения. " << endl;
        return;
    } else if (start_year == end_year && start_month > end_month) {
        cout << "Вы ввели неверные значения. " << endl;
        return;
    } else if (start_year == end_year && start_month == end_month) {
        cout << "Вы ввели неверные значения. " << endl;
        return;
    } else {
        
        EMPLOYEE* employee = nullptr;
        for (EMPLOYEE& emp : employees) {
            if (emp.number == panumber) {
                employee = &emp;
                break;
            }
        }
        
        if (employee == nullptr) {
            cout << "Сотрудник с таким табельным номером не найден." << endl;
            cout << "----------" << endl;
            return;
        }
        
        // Расчет общей суммы выплат
        for (int year = start_year; year <= end_year; ++year) {
            for (int month = 1; month <= 12; ++month) {
                if (employee->year == year && employee->month == month) {
                    if ((year == start_year && month >= start_month) || (year == end_year && month <= end_month)) {
                        total_payment += SalaryTax(*employee);
                    }
                }
            }
        }
        cout << "Объем выплат сотруднику " << employee->name << " " << employee->surname << " за период с " << start_month << "." << start_year << " по " << end_month << "." << end_year << " составляет: " << total_payment << endl;
        cout << "----------" << endl;
    }
}

void Search(vector<EMPLOYEE>& employees){
    int punkt; // Переменная для хранения выбора пользователя
    
    // Вывод меню поиска
    cout << "Поиск записей: " << endl;
    cout << "1. По ФИО " << endl;
    cout << "2. По дате " << endl;
    cout << "3. По почасовому тарифу " << endl;
    cout << "4. Назад " << endl;
    
    punkt = Enter_Check(); // Получение выбора пользователя
    cout << "----------" << endl;
    
    // Проверка наличия записей перед поиском
    if (!None(employees)) {
        return; // Выход из функции, если записей нет
    }
    
    // Выбор действия в зависимости от выбора пользователя
    switch (punkt) {
        case 1:
            Search1(employees); // Поиск по ФИО
            break;
        case 2:
            Search2(employees); // Поиск по дате
            break;
        case 3:
            Search3(employees); // Поиск по почасовому тарифу
            break;
        case 4:
            // Возврат в предыдущее меню
            break;
        default:
            // Сообщение об ошибке при неверном вводе
            cout << "Неверное значение. Введите 1, 2, 3 или 4." << endl;
            cout << "----------" << endl;
            break;
    }
}

// Функция для сортировки записей сотрудников
void Sort(vector<EMPLOYEE>& employees){
    int punkt; // Переменная для хранения выбора пользователя
    
    // Проверка наличия записей перед сортировкой
    if (!None(employees)){
        return; // Выход из функции, если записей нет
    }
    
    // Вывод меню сортировки
    cout << "Сортировка: " << endl;
    cout << "1. По табельному номеру " << endl;
    cout << "2. По количеству проработанных часов " << endl;
    cout << "3. По почасовому тарифу " << endl;
    cout << "4. Назад " << endl;
    
    punkt = Enter_Check(); // Получение выбора пользователя
    cout << "----------" << endl;
    
    switch (punkt) {
        case 1:
            sort(employees.begin(), employees.end(), [](const EMPLOYEE& a, const EMPLOYEE& b) {
                return a.number < b.number;
              });
            cout << "Данные отсортированы. " << endl;
            break;
        case 2:
            sort(employees.begin(), employees.end(), [](const EMPLOYEE& a, const EMPLOYEE& b) {
                return a.amount_hours < b.amount_hours;
              });
            cout << "Данные отсортированы. " << endl;
            break;
        case 3:
            sort(employees.begin(), employees.end(), [](const EMPLOYEE& a, const EMPLOYEE& b) {
                return a.tarif < b.tarif;
              });
            cout << "Данные отсортированы. " << endl;
            break;
        case 4:
            break;
        default:
            cout << "Неверное значение. Введите 1, 2, 3 или 4." << endl;
            cout << "----------" << endl;
            break;
    }
}
