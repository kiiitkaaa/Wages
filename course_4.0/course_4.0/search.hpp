// Проверка, определен ли заголовочный файл search_hpp
#ifndef search_hpp
#define search_hpp

// Подключение необходимых заголовочных файлов
#include "lib.hpp" // Базовые библиотеки и определения
#include "check.hpp" // Функции проверки ввода

// Прототипы функций для поиска данных сотрудников
void Search1(vector<EMPLOYEE>& employees); // Поиск сотрудника по ФИО
void Search2(vector<EMPLOYEE>& employees); // Поиск сотрудника по дате
void Search3(vector<EMPLOYEE>& employees); // Поиск сотрудника по тарифу

#endif /* search_hpp */ // Конец охранительной конструкции
