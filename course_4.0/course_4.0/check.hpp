// Проверка, определен ли заголовочный файл check_hpp
#ifndef check_hpp
#define check_hpp

// Подключение необходимых заголовочных файлов
#include "lib.hpp" // Базовые библиотеки и определения

// Прототипы функций для проверки данных
bool None(vector<EMPLOYEE>& employees); // Проверка на наличие данных о сотрудниках
int Enter_Check(); // Проверка ввода пользователя
void CheckName(const string& name); // Проверка корректности имени
int Month_Check(const int month); // Проверка корректности месяца
int Year_Check(const int year); // Проверка корректности года

#endif /* check_hpp */ // Конец охранительной конструкции
