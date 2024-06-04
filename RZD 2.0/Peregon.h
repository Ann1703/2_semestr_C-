// Peregon.h
#ifndef PEREGON_H
#define PEREGON_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <locale>
#include "Piquet.h"

class Peregon {
private:
    std::vector<Piquet> piquets;

public:
    // Конструктор по умолчанию
    Peregon() {}

    // Конструктор по двум пикетам
    Peregon(const Piquet& start, const Piquet& end) {
        piquets.push_back(start);
        piquets.push_back(end);
        std::sort(piquets.begin(), piquets.end());
    }

    // Конструктор по двум вещественным значениям
    Peregon(double start, double end) : Peregon(Piquet(start), Piquet(end)) {}

    // Метод добавления нового пикета
    void AddPiquet(const Piquet& piquet) {
        auto it = std::lower_bound(piquets.begin(), piquets.end(), piquet);
        piquets.insert(it, piquet);
    }

    // Метод расчета длины перегона
// Метод расчета длины перегона
    double GetLength() const {
        if (piquets.empty()) {
            return 0;
        }
        double length = 0;
        // Добавляем проверку на мерные и немерные пикеты
        for (size_t i = 1; i < piquets.size(); ++i) {
            if (piquets[i].IsMeasured() && piquets[i - 1].IsMeasured()) {
                // Если оба пикета мерные, используем стандартную разницу
                length += piquets[i].Length() - piquets[i - 1].Length();
            }
            else {
                // Если хотя бы один пикет немерный, используем фактическую разницу длин
                length += piquets[i].Length() - piquets[i - 1].Length();
            }
        }
        return length;
    }

    // Метод toString
    std::string ToString() const {
        setlocale(LC_ALL, "ru-RUS");
        std::stringstream ss;
        ss << "Перегон: ";
        for (const auto& piquet : piquets) {
            ss << piquet.ToString() << " ";
        }
        ss << "Длина: " << GetLength() << "м";
        return ss.str();
    }

    // Метод чтения из стандартного потока ввода
    void ReadFromInput() {
        setlocale(LC_ALL, "ru-RUS");
        int startNumber, endNumber;
        double startShift, endShift;
        std::cout << "Введите начальный пикет (номер + смещение): ";
        std::cin >> startNumber >> startShift;
        std::cout << "Введите конечный пикет (номер + смещение): ";
        std::cin >> endNumber >> endShift;
        piquets.clear();
        piquets.push_back(Piquet(startNumber, startShift));
        piquets.push_back(Piquet(endNumber, endShift));
        std::sort(piquets.begin(), piquets.end());
    } 
};

#endif // PEREGON_H
