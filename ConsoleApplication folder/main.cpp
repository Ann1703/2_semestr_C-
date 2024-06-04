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

	std::cout << "Очередь после вставки элементов:" << std::endl;
	std::cout << pq.ToString() << std::endl;

	std::cout << "Извлечение элемента с минимальным приоритетом: " << pq.ExtractMinimum() << std::endl;
	std::cout << "Очередь после извлечения минимального элемента:" << std::endl;
	std::cout << pq.ToString() << std::endl;

	std::cout << "Первый элемент: " << pq.ElementToString(1) << std::endl;

	auto pair = pq[1];
	std::cout <<"Первая пара: {" << pair.first << ", " << pair.second << "}" << std::endl;

	return 0;
}
