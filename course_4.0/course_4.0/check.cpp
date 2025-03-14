// Подключение заголовочного файла check.hpp
#include "check.hpp"

// Функция для проверки наличия данных о сотрудниках
bool None(vector<EMPLOYEE>& employees) {
    
    // Если вектор сотрудников пуст, выводится сообщение и возвращается false
    if (employees.empty()) {
        cout << "Нет данных. " << endl;
        return false;
    } else {
        // Если данные есть, возвращается true
        return true;
    }
}

// Функция для проверки ввода пользователя
int Enter_Check() {
    int mode, a;
    
    // Запрос у пользователя выбора пункта меню
    cout << "Выберите пункт: ";
    cin >> mode;
    
    // Проверка на ошибки ввода
    if (cin.fail()){
        // Очистка потока ввода и игнорирование оставшихся символов
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Возврат значения 0 при ошибке ввода
        return a = 0;
    } else {
        // Очистка потока ввода и игнорирование оставшихся символов
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Возврат введенного пользователем значения
        return mode;
    }
}

// Функция для проверки корректности имени
void CheckName(const string& name) {
    
    // Перебор всех символов в строке
    for (char c : name) {
        // Если символ не является буквой, выбрасывается исключение
        if (!isalpha(c)) {
            throw invalid_argument("Имя должно содержать только буквы.");
        }
    }
}

// Функция для проверки корректности месяца
int Month_Check(const int month) {
    // Если месяц больше 12, возвращается -1
    if (month >= 13){
        return -1;
    }
    // Иначе возвращается 0
    return 0;
}

// Функция для проверки корректности года
int Year_Check(const int year) {
    // Если год не входит в диапазон [2005, 2025], возвращается -1
    if (year >= 2025 || year <= 2005){
        return -1;
    }
    // Иначе возвращается 0
    return 0;
}
