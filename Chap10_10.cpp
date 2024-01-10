#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class Country {
	std::string Coun;
	std::string City;
public:
	std::string getCoun() {
		return this->Coun;
	}
	std::string getCity() {
		return this->City;
	}
	void set(std::string Coun, std::string City) {
		this->Coun = Coun;
		this->City = City;
	}
};

std::vector<Country> Info;

int main() {
	int Game_Start = 0;
	Country Country_name;
	Country_name.set("한국", "서울");
	Info.push_back(Country_name);
	Country_name.set("일본", "도쿄");
	Info.push_back(Country_name);
	Country_name.set("중국", "베이징");
	Info.push_back(Country_name);
	Country_name.set("캐나다", "오타와");
	Info.push_back(Country_name);
	Country_name.set("러시아", "모스크바");
	Info.push_back(Country_name);

	std::cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << std::endl;
	while (1) {
		std::cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >> ";
		std::cin >> Game_Start;
		if (Game_Start == 1) {
			std::cout << "현재 " << Info.size() << "개의 나라가 입력되어 있습니다." << std::endl;
			std::cout << "나라와 수도를 입력하세요(no no 이면 입력끝)" << std::endl;
			std::string Coun, City;
			while (1) {
				int i = 0;
				std::cout << Info.size() << ">>";
				std::cin >> Coun >> City;
				int flag = 0;
				for (i = 0; i < Info.size(); i++) {
					if (Info.at(i).getCoun() == Coun) {
						std::cout << "already exists !!" << std::endl;
						flag = 1;
						break;
					}
				}
				if (Coun == "no" && City == "no")
					break;
				if (flag == 0) {
					//std::cout << Coun << City << std::endl;
					Country_name.set(Coun, City);
					Info.push_back(Country_name);
				}
				flag = 0;
			}
		}
		else if (Game_Start == 2) {
			std::cout << Info.size() << std::endl;
			while (1) {
				srand((unsigned)time(0));
				int n = rand() % Info.size();
				std::cout << Info.at(n).getCoun() << "의 수도는? ";
				std::string Ans;
				std::cin >> Ans;
				if (Info.at(n).getCity() == Ans)
					std::cout << "correct !!" << std::endl;
				else if (Ans == "exit")
					break;
				else
					std::cout << "NO !!" << std::endl;
			}
		}
		else if (Game_Start == 3)
			break;
	}
}