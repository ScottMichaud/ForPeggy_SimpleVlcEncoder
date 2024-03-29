#include "SimpleCodewordTableContainer.hpp"

#include <iostream>

bool descendSortTupleSecond(const std::pair<char, int>& i, const std::pair<char, int>& j) { return i.second > j.second; }

// Pass by value copies the histogram into the function. This might be suboptimal.
// Could be better by pre-sorting the histogram outside this function. Just an example though.
SimpleCodewordTableContainer::SimpleCodewordTableContainer(std::vector<std::pair<char, int>> histogram)
{
	std::sort(histogram.begin(), histogram.end(), descendSortTupleSecond);

	int idx = 0;
	std::vector<std::pair<char, int>>::const_iterator itr;
	for (itr = histogram.begin(); itr < histogram.end(); itr++, idx++)
	{
		codewordTable.push_back(std::pair<char, std::string>(itr->first, SimpleCodewordTableConstants::codes[idx])); //Don't really like accessing arrays by index but it works.
	}

	for (auto code_to_word : codewordTable)
	{
		std::cout << "key = " << code_to_word.first << " value = " << code_to_word.second << std::endl;
	}
}

std::string SimpleCodewordTableContainer::decode(const std::string& inString) const
{
	std::string output("");

	std::string::const_iterator itr;
	for (itr = inString.begin(); itr < inString.end(); itr++)
	{
		output += get_char_string(*itr);
	}

	return output;
}

std::string SimpleCodewordTableContainer::get_char_string(char inChar) const
{
	std::vector<std::pair<char, std::string>>::const_iterator itr;
	for (itr = codewordTable.begin(); itr < codewordTable.end(); itr++)
	{
		if (itr->first == inChar) {
			return itr->second;
		}
	}
}
