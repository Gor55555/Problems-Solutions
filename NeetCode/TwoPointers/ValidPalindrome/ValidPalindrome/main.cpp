#include <iostream>
#include <iomanip>
#include <string>

bool ReverseString(std::string s)
{
	std::string newStr = "";
	for (char c : s)
	{
		if (isalnum(c))
		{
			newStr += tolower(c);
		}
	}
	return newStr == std::string(newStr.rbegin(), newStr.rend());
}

bool alphaNum(char c)
{
    return (c >= 'A' && c <= 'Z' ||
            c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9');
}

bool TwoPointers(std::string s)
{
    int l = 0, r = s.length() - 1;

    while (l < r) {
        while (l < r && !alphaNum(s[l])) 
        {
            l++;
        }
        while (r > l && !alphaNum(s[r])) 
        {
            r--;
        }
        if (tolower(s[l]) != tolower(s[r])) 
        {
            return false;
        }
        l++; r--;
    }
    return true;
}

int main()
{

	std::string s;
	std::cout << std::setw(15) << std::left << "Input: ";
	std::getline(std::cin, s);

	std::cout << "\n" << std::setw(15) << std::left << "Output: " << (ReverseString(s) ? "True" : "False");
    std::cout << "\n" << std::setw(15) << std::left << "Output: " << (TwoPointers(s) ? "True" : "False");
}