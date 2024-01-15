#include <iostream>
#include <map>
#include <string>

int main() {
	std::cout << "***** 점수관린 프로그램 HIGH SCORE을 시작합니다 *****" << std::endl;
	std::map<std::string, int> Student;
	while (1) {
		std::cout << "입력:1, 조회:2, 종료:3 >> ";
		int Start = 0;
		std::cin >> Start;

		if (Start == 1) {
			std::string name;
			int score = 0;
			std::cout << "이름과 점수>>";
			std::cin >> name >> score;
			Student.insert(make_pair(name, score));
		}

		else if (Start == 2) {
			std::string name;
			std::cout << "이름>> ";
			std::cin >> name;
			if (Student.find(name) == Student.end())
				std::cout << "존재하지 않습니다." << std::endl;
			else
				std::cout << name << "의 점수는 " << Student[name] << "점입니다. " << std::endl;
		}

		else if (Start == 3)
			break;
	}
}