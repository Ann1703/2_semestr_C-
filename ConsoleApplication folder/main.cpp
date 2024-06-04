#include "../Ex2.2.2/PriorityQueue.h"
#include <iostream>

using namespace std;
using namespace Queue;

int main()
{
	PriorityQueue pq;
	pq.Insert({ 10, 100 });
	pq.Insert({ 5, 50 });
	pq.Insert({ 20, 200 });
	pq.Insert({ 1, 10 });

	std::cout << "������� ����� ������� ���������:" << std::endl;
	std::cout << pq.ToString() << std::endl;

	std::cout << "���������� �������� � ����������� �����������: " << pq.ExtractMinimum() << std::endl;
	std::cout << "������� ����� ���������� ������������ ��������:" << std::endl;
	std::cout << pq.ToString() << std::endl;

	std::cout << "������ �������: " << pq.ElementToString(1) << std::endl;

	auto pair = pq[1];
	std::cout <<"������ ����: {" << pair.first << ", " << pair.second << "}" << std::endl;

	return 0;
}
