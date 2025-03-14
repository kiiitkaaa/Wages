// Проверка, определен ли заголовочный файл lib_hpp
#ifndef lib_hpp
#define lib_hpp

// Подключение необходимых заголовочных файлов
#include <iostream> // Ввод-вывод
#include <string> // Работа со строками
#include <vector> // Работа с векторами
#include <fstream> // Работа с файлами
#include <algorithm> // Алгоритмы
#include <stdlib.h> // Стандартные функции
#include <sstream> // Работа со строковыми потоками

using namespace std;

// Определение структуры EMPLOYEE для хранения данных о сотрудниках
struct EMPLOYEE {
    string name; // Имя
    string surname; // Фамилия
    string father_name; // Отчество
    int number; // Табельный номер
    int year; // Год
    int month; // Месяц
    float amount_hours; // Количество отработанных часов
    float tarif; // Почасовой тариф
};

#endif /* lib_hpp */ // Конец охранительной конструкции
