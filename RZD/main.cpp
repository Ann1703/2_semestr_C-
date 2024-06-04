#include <iostream>
#include "../RZD 2.0/Peregon.h"
#include "../RZD 2.0/Piquet.h"
#include <locale> 


int main() {
   std:: setlocale(LC_ALL, "ru-RU");
    // �������� �������� �� ���� �������
    Peregon peregon1(Piquet(12, 28.37), Piquet(13, 15.72));
    std::cout << peregon1.ToString() << std::endl;

    // �������� �������� �� ���� ������������ ��������
    Peregon peregon2(1228.37, 1315.72);
    std::cout << peregon2.ToString() << std::endl;
    
    // ���������� ������ � �������
    peregon2.AddPiquet(Piquet(12, 50.0));
    std::cout << peregon2.ToString() << std::endl;
    
    // ������ ���������� � �������� �� �����
    Peregon peregon3;
    peregon3.ReadFromInput();
    std::cout << peregon3.ToString() << std::endl;
    return 0;
}