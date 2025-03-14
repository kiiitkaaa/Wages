// Проверка, определен ли заголовочный файл editing_hpp
#ifndef editing_hpp
#define editing_hpp

// Подключение необходимых заголовочных файлов
#include "lib.hpp" // Базовые библиотеки и определения
#include "check.hpp" // Функции проверки ввода

// Прототипы функций для редактирования данных сотрудников
void Add(vector<EMPLOYEE>& employees); // Добавление новой записи о сотруднике
void Edit(vector<EMPLOYEE>& employees); // Редактирование существующей записи
void Remove(vector<EMPLOYEE>& employees); // Удаление записи о сотруднике
void Print(vector<EMPLOYEE>& employees); // Вывод информации о сотрудниках

#endif /* editing_hpp */ // Конец охранительной конструкции
