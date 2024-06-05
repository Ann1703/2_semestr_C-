#include "Piquet.h" // Подключаем заголовочный файл Piquet.h
// Конструктор по умолчанию
// Создает пикет с номером 0, смещением 0.0 и длиной 100.0
Piquet::Piquet() : number(0), shift(0.0), length(100.0) {}
// Конструктор с номером пикета
// Создает пикет с заданным номером, смещением 0.0 и длиной 100.0
Piquet::Piquet(int number) : number(number), shift(0.0), length(100.0) {}
// Конструктор с номером пикета и смещением
// Создает пикет с заданным номером и смещением, вычисляя длину
Piquet::Piquet(int number, double shift) : number(number), shift(shift), length(number * 100 + shift) {}
// Конструктор с вещественным значением (для нестандартных пикетов)
// Создает пикет с заданной длиной, вычисляя номер и смещение
Piquet::Piquet(double length) : number(static_cast<int>(length / 100)), shift(length - number * 100), length(length) {}
// Метод получения номера пикета
// Возвращает номер пикета
int Piquet::Number() const {
    return number;
}
// Метод получения смещения
// Возвращает смещение пикета
double Piquet::Shift() const {
    return shift;
}
// Метод получения длины пикета
// Возвращает длину пикета
double Piquet::Length() const {
    return length;
}
// Метод проверки на стандартный пикет
// Возвращает true, если пикет стандартный (смещение равно 0.0), иначе false
bool Piquet::IsStandard() const {
    return shift == 0.0;
}
// Метод проверки на мерный пикет
// Возвращает true, если пикет мерный (длина соответствует номеру и смещению), иначе false
bool Piquet::IsMeasured() const {
    return length == number * 100 + shift;
}
// Метод преобразования пикета в строку
// Возвращает строковое представление пикета в формате "ПКномер+смещение"
std::string Piquet::ToString() const {
    setlocale(LC_ALL, "ru-RUS");
    std::stringstream ss;
    ss << "ПК" << number << "+" << std::fixed << std::setprecision(2) << shift;
    return ss.str();
}
// Перегрузка оператора ==
// Возвращает true, если два пикета имеют одинаковый номер и смещение, иначе false
bool Piquet::operator==(const Piquet& other) const {
    return number == other.number && shift == other.shift;
}
// Перегрузка оператора !=
// Возвращает true, если два пикета не имеют одинаковый номер и смещение, иначе false
bool Piquet::operator!=(const Piquet& other) const {
    return !(*this == other);
}
// Перегрузка оператора <
// Возвращает true, если пикет слева меньше пикета справа, иначе false
bool Piquet::operator<(const Piquet& other) const {
    if (number < other.number) {
        return true;
    }
    else if (number == other.number) {
        return shift < other.shift;
    }
    return false;
}
// Перегрузка оператора <=
// Возвращает true, если пикет слева меньше или равен пикету справа, иначе false
bool Piquet::operator<=(const Piquet& other) const {
    return *this < other || *this == other;
}
// Перегрузка оператора >
// Возвращает true, если пикет слева больше пикета справа, иначе false
bool Piquet::operator>(const Piquet& other) const {
    return !(*this <= other);
}
// Перегрузка оператора >=
// Возвращает true, если пикет слева больше или равен пикету справа, иначе false
bool Piquet::operator>=(const Piquet& other) const {
    return !(*this < other);
}
// Перегрузка оператора + (добавление смещения)
// Возвращает новый пикет с увеличенным смещением на заданное значение
Piquet Piquet::operator+(double value) const {
    return Piquet(number, shift + value);
}
// Перегрузка оператора - (вычитание смещения)
// Возвращает новый пикет с уменьшенным смещением на заданное значение
Piquet Piquet::operator-(double value) const {
    return Piquet(number, shift - value);
}
