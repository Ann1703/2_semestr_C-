Комментарии к коду
language-cpp
 Copy code
#include "Piquet.h" // Подключение заголовочного файла Piquet.h для использования класса Piquet
#include <iostream> // Подключение библиотеки для ввода-вывода
#include <sstream> // Подключение библиотеки для работы с потоками ввода-вывода
#include <iomanip> // Подключение библиотеки для управления форматированием вывода

Piquet::Piquet(int number = 0) : number(number), shift(0), length(100), isStandard(true) {} // Конструктор класса Piquet с параметром по умолчанию

Piquet::Piquet(int number) : number(number), shift(0), length(100), isStandard(true) {} // Конструктор класса Piquet с одним параметром

Piquet::Piquet(int number, double shift) : number(number), shift(shift), length(100 + shift), isStandard(false) {} // Конструктор класса Piquet с двумя параметрами

Piquet::Piquet(double length) : number(static_cast<int>(length / 100)), shift(length - 100 * number), length(length), isStandard(false) {} // Конструктор класса Piquet с параметром типа double

int Piquet::Number() const { return number; } // Метод возврата номера

double Piquet::Shift() const { return shift; } // Метод возврата сдвига

double Piquet::Length() const { return length; } // Метод возврата длины

bool Piquet::IsStandard() const { return isStandard; } // Метод проверки стандарта

bool Piquet::operator==(const Piquet& other) const { // Перегрузка оператора равенства
    return (fabs(number - other.number) < DBL_EPSILON) && (fabs(shift - other.shift) < DBL_EPSILON);
}

bool Piquet::operator!=(const Piquet& other) const { // Перегрузка оператора неравенства
    return !(*this == other);
}

bool Piquet::operator<(const Piquet& other) const { // Перегрузка оператора меньше
    if (number < other.number) {
        return true;
    }
    else if (number == other.number && shift < other.shift) {
        return true;
    }
    return false;
}

bool Piquet::operator<=(const Piquet& other) const { // Перегрузка оператора меньше или равно
    return (*this < other || *this == other);
}

bool Piquet::operator>(const Piquet& other) const { // Перегрузка оператора больше
    return !(*this <= other);
}

bool Piquet::operator>=(const Piquet& other) const { // Перегрузка оператора больше или равно
    return !(*this < other);
}

Piquet Piquet::operator+(const double& offset) const { // Перегрузка оператора сложения
    return Piquet(number, shift + offset);
}

Piquet Piquet::operator-(const double& offset) const { // Перегрузка оператора вычитания
    return Piquet(number, shift - offset);
}

std::string Piquet::ToString() const { // Метод преобразования в строку
    std::stringstream ss;
    ss << "ПК" << (number >= 0 ? "" : "0") << std::abs(number) << "+" << std::fixed << std::setprecision(2) << shift;
    return ss.str();
} 

bool Piquet::IsMeasured() const { // Метод проверки измерения
    return isStandard;
}
