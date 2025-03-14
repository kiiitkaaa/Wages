// Проверка, определен ли заголовочный файл operating_hpp
#ifndef operating_hpp
#define operating_hpp

// Подключение необходимых заголовочных файлов
#include "lib.hpp" // Базовые библиотеки и определения
#include "check.hpp" // Функции проверки ввода
#include "search.hpp" // Функции поиска

// Прототипы функций для работы с данными сотрудников
void FoundForSalary(vector<EMPLOYEE>& employees); // Расчет зарплаты сотрудников
void Payment(vector<EMPLOYEE>& employees); // Расчет выплат сотруднику за период
void Search(vector<EMPLOYEE>& employees); // Поиск сотрудников по критериям
void Sort(vector<EMPLOYEE>& employees); // Сортировка данных сотрудников

#endif /* operating_hpp */ // Конец охранительной конструкции
