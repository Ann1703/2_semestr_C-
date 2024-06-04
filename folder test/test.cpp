#include "pch.h"
#include "CppUnitTest.h"
#include "../Ex2.2.2/PriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Queue;

namespace Tests
{
	/**
	* @brief Класс тестов для PriorityQueue.
	*/
	TEST_CLASS(Priority_Queue_Tests)
	{
	public:
		/**
		* @brief Тест для проверки добавления элементов в очередь.
		*/
		TEST_METHOD(Insert_DifferentPoints_True)
		{
			PriorityQueue pq;
			pq.Insert({ 10, 100 });
			pq.Insert({ 5, 50 });
			pq.Insert({ 20, 200 });
			pq.Insert({ 1, 10 });

			std::string expected = "10\n50\n100\n200\n";
			Assert::AreEqual(expected, pq.ToString());
		}

		/**
		* @brief Тест для проверки минимального элемента в очереди.
		*/
		TEST_METHOD(ExtractMinimum_DifferentPoints_True)
		{
			PriorityQueue pq;
			pq.Insert({ 10, 100 });
			pq.Insert({ 5, 50 });
			pq.Insert({ 20, 200 });
			pq.Insert({ 1, 10 });

			Assert::AreEqual(10, pq.ExtractMinimum());
			std::string expected = "50\n100\n200\n";
			Assert::AreEqual(expected, pq.ToString());
		}

		/**
		* @brief Тест для проверки преобразования элемента в строку по индексу.
		*/
		TEST_METHOD(ToString_Point_True)
		{
			PriorityQueue pq;
			pq.Insert({ 10, 100 });
			pq.Insert({ 5, 50 });
			pq.Insert({ 20, 200 });
			pq.Insert({ 1, 10 });

			Assert::AreEqual(50, pq.ElementToString(1));
		}

		/**
		* @brief Тест для проверки перегрузки оператора доступа к элементу.
		*/
		TEST_METHOD(ToString_DifferentPoints_True)
		{
			PriorityQueue pq;
			pq.Insert({ 10, 100 });
			pq.Insert({ 5, 50 });
			pq.Insert({ 20, 200 });
			pq.Insert({ 1, 10 });

			auto pair = pq[1];
			Assert::AreEqual(5, pair.first);
			Assert::AreEqual(50, pair.second);
		}

		/**
		* @brief Тест для проверки выявления пустой очереди.
		*/
		TEST_METHOD(ElementToString_ZeroData_Success)
		{
			PriorityQueue pq;
			Assert::ExpectException<std::logic_error>([&pq] { pq.ExtractMinimum(); }, L"В векторе нет данных.");
		}
	};
}
