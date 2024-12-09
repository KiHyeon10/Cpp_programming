#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int T;
	std::cin >> T;
	int count = 0;

	for (int i = 0; i < T; i++)
	{
		std::string sen;
		std::cin >> sen;
		int j = 1;
		int flag = 0;
		std::vector<char> ans;
		ans.push_back(sen[0]);

		if (sen.size() != 1)
		{
			while (j != sen.size())
			{
				if (find(ans.begin(), ans.end(), sen[j]) == ans.end())
				{
					ans.push_back(sen[j]);
				}
				else
				{
					if (sen[j - 1] != sen[j])
					{
						flag = 1;
						break;
					}
				}
				j++;
			}
		}
		if (flag == 0 || sen.size() == 1)
		{
			count += 1;
		}
	}
	std::cout << count << '\n';

	return 0;
}