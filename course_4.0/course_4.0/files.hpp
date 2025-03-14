// Проверка, определен ли заголовочный файл files_hpp
#ifndef files_hpp
#define files_hpp

// Подключение необходимых заголовочных файлов
#include "lib.hpp" // Базовые библиотеки и определения
#include "check.hpp" // Функции проверки ввода

// Прототипы функций для работы с файлами
void ReadFile(vector<EMPLOYEE>& employees); // Чтение данных из файла
void WriteFile(vector<EMPLOYEE>& employees); // Запись данных в файл

#endif /* files_hpp */ // Конец охранительной конструкции
