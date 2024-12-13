#include <iostream>
#include <vector>

int main() {
	std::vector<bool> ans(10001, true);

	for (int i = 1; i < ans.size(); i++) {
		int num = i;
		int sum = 0;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}

		int Self_num = i + sum;

		if (Self_num <= 10000)
		{
			ans[Self_num] = false;
		}
	}
	for (int i = 1; i < ans.size(); i++)
	{
		if (ans[i] == true)
		{
			std::cout << i << '\n';
		}
	}
	return 0;
}