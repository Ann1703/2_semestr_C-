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
	* @brief ����� ������� � �����������.
	*/
	class PriorityQueue
	{
	private:
		std::vector < std::pair<int, int> >pairs;

	public:
		/**
		* @brief ��������� ���� �� ������� ��������.
		*/
		void SortPairsByFirstElement();

		/**
		* @brief ��������� ���� � �������.
		* @param pair - ����, ������� ���������� �������� � �������.
		*/
		void Insert(const std::pair<int, int>& pair);

		/**
		* @brief ��������� ����������� ������� �� �������.
		* @return �������� ������������ ��������.
		* @throws ���� ������� �����.
		*/
		int ExtractMinimum();

		/**
		* @brief ����������� ��� �������� ������� � ������.
		* @return ��������� ������������� ���� ��������� �������.
		*/
		std::string ToString() const;

		/**
		* @brief ���������� �������� �������� ������� �� �������.
		* @param index - ������ ��������.
		* @return �������� �������� �� ���������� �������.
		* @throws ���� ������ �������.
		*/
		int ElementToString(size_t index) const;

		/**
		* @brief ���������� ��������� ������� � �������� �� �������.
		* @param index - ������ ��������.
		* @return ������ �� ���� � ��������� ��������.
		*/
		std::pair<int, int>& operator[](int index);
	};
}