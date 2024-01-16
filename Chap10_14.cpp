#include <iostream>
#include <map>

int main() {
	std::cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****" << std::endl;
	std::map<std::string, std::string> WHO;
	while (1) {
		std::cout << "삽입:1, 검사:2, 종료:3>>";
		int Start = 0;
		std::cin >> Start;

		if (Start == 1) {
			std::cout << "이름 암호>> ";
			std::string Name, Password;
			std::cin >> Name >> Password;
			WHO.insert(make_pair(Name, Password));
		}
		else if (Start == 2) {
			int flag = 1;
			while (flag) {
				std::cout << "이름? ";
				std::string Name, Password;
				std::cin >> Name;

				if (WHO.find(Name) == WHO.end()) {
					std::cout << "해당하는 이름이 없습니다." << std::endl;
					flag = 0;
				}
				while (flag) {
					std::cout << "암호는? ";
					std::cin >> Password;

					if (Password == WHO[Name]) {
						std::cout << "통과!!" << std::endl;
						flag = 0;
					}
					else {
						std::cout << "실패~~~" << std::endl;
					}
				}
			}
		}
		else if (Start == 3) {
			std::cout << "프로그램을 종료합니다..." << std::endl;
			break;
		}
	}
}