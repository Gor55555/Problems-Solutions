#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> Sorting(std::vector<std::string>& strs)               //Time complexity:  O(m*nlogn)
{                                                                                           //Space complexity: O(m*n)
	std::unordered_map<std::string, std::vector<std::string>> map;
	for (const auto& s : strs)
	{
		std::string sortedS = s;
		std::sort(sortedS.begin(), sortedS.end());
		map[sortedS].push_back(s);
	}
	std::vector<std::vector<std::string>> result;
	for (auto& pair : map)
	{
		result.push_back(pair.second);
	}
	return result;
}

std::vector<std::vector<std::string>> Hash_Table(std::vector<std::string>& strs)           //Time complexity:  O(m*n)
{                                                                                          //Space complexity: O(m)
	std::unordered_map<std::string, std::vector<std::string>> map;
	for (const auto& s : strs)
	{
		std::vector<int> count(26, 0);
		for (char c : s)
		{
			count[c - 'a']++;
		}
		std::string key = std::to_string(count[0]);
		for (int i = 1; i < 26; ++i)
		{
			key += ',' + std::to_string(count[i]);
		}
		map[key].push_back(s);
	}
	std::vector<std::vector<std::string>> result;
	for (const auto& pair : map)
	{
		result.push_back(pair.second);
	}
	return result;

}

int main()
{
	int size;
	std::cout << std::setw(10) << std::left << "Input: ";
	std::cin >> size;

	std::vector<std::string> strs(size);
	std::cout << std::setw(10) << std::left << "Input: ";
	for (auto& i : strs)
	{
		std::cin >> i;
	}

	std::cout << "\n";
	std::cout << std::setw(10) << std::left << "Outout with use Sorting: " << "\n";
	for (const auto& group : Sorting(strs))
	{
		std::cout << std::setw(10) << std::left << " ";
		for (const auto& str : group)
		{
			std::cout << str << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
	std::cout << std::setw(10) << std::left << "Outout with use Hash Table: " << "\n";
	for (const auto& group : Hash_Table(strs))
	{
		std::cout << std::setw(10) << std::left << " ";
		for (const auto& str : group)
		{
			std::cout << str << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}