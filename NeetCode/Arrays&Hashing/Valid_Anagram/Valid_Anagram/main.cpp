#include <iostream> 
#include <iomanip> 
#include <string> 
#include <unordered_map> 
#include <algorithm>

bool Sorting(std::string s, std::string t)                //Time complexity: O(nlogn)
{                                                         //Space complexity: O(1) or O(n) depending on the sorting algorithm
    if (s.length() != t.length())
    {
        return false;
    }
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return s == t;
}

bool Vector(std::string s, std::string t)                 //Time complexity: O(n)
{                                                         //Space complexity: O(1)
    if (s.length() != t.length()) {
        return false;
    }

    std::vector<int> count(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int val : count)
    {
        if (val != 0) {
            return false;
        }
    }
    return true;
}

bool Hash_Table(std::string s, std::string t)             //Time complexity:  O(n)
{                                                         //Space complexity: O(1)
    if (s.length() != t.length())
    {
        return false;
    }

    std::unordered_map<char, int> count;
    for (char c : s)
    {
        count[c]++;
    }
    for (char c : t)
    {
        count[c]--;
        if (count[c] < 0)
        {
            return false;
        }
    }
    return true;
}

bool Hash_Table_Optimal(std::string s, std::string t)      //Time complexity: O(n)+O(n)=O(n)
{                                                          //Space complexity: O(1)
    if (s.length() != t.length())
    {
        return false;
    }

    std::unordered_map<char, int> countS;
    std::unordered_map<char, int> countT;
    for (int i = 0; i < s.length(); i++)
    {
        countS[s[i]]++;
        countT[t[i]]++;
    }
    return countS == countT;
}


int main()
{
    std::string s;
    std::string t;

    std::cout << std::setw(10) << std::left << "Input: ";
    std::cin >> s;

    std::cout << std::setw(10) << std::left << "Input: ";
    std::cin >> t;

    std::cout << "\n" << std::setw(30) << std::left << "Output with use Sort: " << (Sorting(s, t) ? "True" : "False");
    std::cout << "\n" << std::setw(30) << std::left << "Output with use Maps: " << (Vector(s, t) ? "True" : "False");
    std::cout << "\n" << std::setw(30) << std::left << "Output with use Vector: " << (Hash_Table(s, t) ? "True" : "False");
    std::cout << "\n" << std::setw(30) << std::left << "Output with use Single Map: " << (Hash_Table_Optimal(s, t) ? "True" : "False");
}
