#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>
#include <ostream>
#include <stdexcept>

namespace Queue
{
	/**
	* @brief Класс очереди с приоритетом.
	*/
	class PriorityQueue
	{
	private:
		std::vector < std::pair<int, int> >pairs;

	public:
		/**
		* @brief Сортирует пары по первому элементу.
		*/
		void SortPairsByFirstElement();

		/**
		* @brief Вставляет пару в очередь.
		* @param pair - пара, которую необходимо добавить в очередь.
		*/
		void Insert(const std::pair<int, int>& pair);

		/**
		* @brief Извлекает минимальный элемент из очереди.
		* @return Значение минимального элемента.
		* @throws Если очередь пуста.
		*/
		int ExtractMinimum();

		/**
		* @brief Преобразует все элементы очереди в строку.
		* @return Строковое представление всех элементов очереди.
		*/
		std::string ToString() const;

		/**
		* @brief Возвращает значение элемента очереди по индексу.
		* @param index - индекс элемента.
		* @return Значение элемента по указанному индексу.
		* @throws Если индекс неверен.
		*/
		int ElementToString(size_t index) const;

		/**
		* @brief Перегрузка оператора доступа к элементу по индексу.
		* @param index - индекс элемента.
		* @return Ссылка на пару с указанным индексом.
		*/
		std::pair<int, int>& operator[](int index);
	};
}