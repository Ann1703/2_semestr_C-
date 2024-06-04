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
    // ����������� �� ���������
    Peregon() {}

    // ����������� �� ���� �������
    Peregon(const Piquet& start, const Piquet& end) {
        piquets.push_back(start);
        piquets.push_back(end);
        std::sort(piquets.begin(), piquets.end());
    }

    // ����������� �� ���� ������������ ���������
    Peregon(double start, double end) : Peregon(Piquet(start), Piquet(end)) {}

    // ����� ���������� ������ ������
    void AddPiquet(const Piquet& piquet) {
        auto it = std::lower_bound(piquets.begin(), piquets.end(), piquet);
        piquets.insert(it, piquet);
    }

    // ����� ������� ����� ��������
// ����� ������� ����� ��������
    double GetLength() const {
        if (piquets.empty()) {
            return 0;
        }
        double length = 0;
        // ��������� �������� �� ������ � �������� ������
        for (size_t i = 1; i < piquets.size(); ++i) {
            if (piquets[i].IsMeasured() && piquets[i - 1].IsMeasured()) {
                // ���� ��� ������ ������, ���������� ����������� �������
                length += piquets[i].Length() - piquets[i - 1].Length();
            }
            else {
                // ���� ���� �� ���� ����� ��������, ���������� ����������� ������� ����
                length += piquets[i].Length() - piquets[i - 1].Length();
            }
        }
        return length;
    }

    // ����� toString
    std::string ToString() const {
        setlocale(LC_ALL, "ru-RUS");
        std::stringstream ss;
        ss << "�������: ";
        for (const auto& piquet : piquets) {
            ss << piquet.ToString() << " ";
        }
        ss << "�����: " << GetLength() << "�";
        return ss.str();
    }

    // ����� ������ �� ������������ ������ �����
    void ReadFromInput() {
        setlocale(LC_ALL, "ru-RUS");
        int startNumber, endNumber;
        double startShift, endShift;
        std::cout << "������� ��������� ����� (����� + ��������): ";
        std::cin >> startNumber >> startShift;
        std::cout << "������� �������� ����� (����� + ��������): ";
        std::cin >> endNumber >> endShift;
        piquets.clear();
        piquets.push_back(Piquet(startNumber, startShift));
        piquets.push_back(Piquet(endNumber, endShift));
        std::sort(piquets.begin(), piquets.end());
    } 
};

#endif // PEREGON_H