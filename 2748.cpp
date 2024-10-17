#include <iostream>
#include <vector>

long long find(int n, std::vector<long long>& fibo) {

	if (fibo[n] != 0) {
		return fibo[n];
	}
	else if (n == 0) {
		return 0;
	}
	else {
		if (n == 1 || n == 2) {
			fibo[n] = 1;
		}
		else {
			fibo[n] = (find(n - 1, fibo) + find(n - 2, fibo) % 10007);
		}
		return fibo[n];
	}
}

int main() {
	int n = 0;
	std::cin >> n;
	
	std::vector<long long> fibo(n + 1, 0);
	
	long long answer = find(n, fibo);

	std::cout << answer << '\n';

	return 0;
}