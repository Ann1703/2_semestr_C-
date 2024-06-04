#include "PriorityQueue.h"

namespace Queue
{
	void PriorityQueue::Insert(const std::pair<int, int>& pair)
	{
		pairs.push_back(pair);
		this->SortPairsByFirstElement();
	}

	int PriorityQueue::ExtractMinimum()
	{
		if (pairs.empty())
		{
			throw std::logic_error("В векторе нет данных.");
		}
		int MinValue = pairs[0].second;
		pairs.erase(pairs.begin());
		return MinValue;
	}

	std::string PriorityQueue::ToString() const
	{
		std::stringstream buffer{};
		for (const auto& pair : pairs)
		{
			buffer << pair.second << "\n";
		}
		return buffer.str();
	}

	int PriorityQueue::ElementToString(size_t index) const
	{
		if (index >= pairs.size())
		{
			throw std::logic_error("Проблема с индексом.");
		}
		return pairs[index].second;
	}

	void PriorityQueue::SortPairsByFirstElement()
	{
		sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& FirstPair, const std::pair<int, int>& SecondPair)
			{
				return FirstPair.first < SecondPair.first;
			}
		);
	}

	std::pair<int, int>& PriorityQueue::operator[](int index)
	{
		return pairs[index];
	}
}