#include <iostream>
#include "Peregon.h" // Подключите заголовочный файл Peregon.h

int main() {
    // Создание перегона из двух пикетов
    Peregon peregon1(Piquet(12, 28.37), Piquet(13, 15.72));
    std::cout << peregon1.ToString() << std::endl;

    // Создание перегона из двух вещественных значений
    Peregon peregon2(1228.37, 1315.72);
    std::cout << peregon2.ToString() << std::endl;

    // Добавление пикета в перегон
    peregon2.AddPiquet(Piquet(12, 50.0));
    std::cout << peregon2.ToString() << std::endl;

    // Чтение информации о перегоне из ввода
    Peregon peregon3;
    peregon3.ReadFromInput();
    std::cout << peregon3.ToString() << std::endl;

    return 0;
} 