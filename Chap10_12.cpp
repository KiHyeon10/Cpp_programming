#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class Word {
	std::string Eng;
	std::string Han;
public:

	std::string getEng() {
		return this->Eng;
	}
	std::string getHan() {
		return this->Han;
	}
	void set(std::string Eng, std::string Han) {
		this->Eng = Eng;
		this->Han = Han;
	}
};

int main() {
	std::vector<Word> v;
	Word dic;
	dic.set("human", "인간");
	v.push_back(dic);
	dic.set("society", "사회");
	v.push_back(dic);
	dic.set("doll", "인형");
	v.push_back(dic);
	dic.set("painting", "그림");
	v.push_back(dic);
	dic.set("trade", "거래");
	v.push_back(dic);
	dic.set("emotion", "감정");
	v.push_back(dic);


	std::cout << "***** 영어 어휘 테스트를 시작합니다. *****" << std::endl;
	while (1) {
		std::cout << "어휘 삽입: 1, 어휘 테스트: 2, 프로그램 종료: 그외키>>";
		int Start;
		std::cin >> Start;
		if (Start == 1) {
			std::cout << "영어 단어에 exit을 입력하면 입력 끝" << std::endl;
			std::string Eng, Han;
			while (1) {
				std::cout << "영어 >>";
				std::cin >> Eng;
				if (Eng == "exit")
					break;
				std::cout << "한글 >>";
				std::cin >> Han;
				dic.set(Eng, Han);
				v.push_back(dic);
			}
		}
		else if (Start == 2) {
			while (1) {
				srand((unsigned)time(0));
				int n = rand() % v.size();
				Word Ques = v.at(n);
				std::cout << Ques.getEng() << '?' << std::endl;

				std::vector<std::string> ex;
				int ExEx[6] = { 0, 0 ,0 ,0, 0, 0 };
				ex.push_back(Ques.getHan());
				ExEx[n] = 1;
				for (int i = 0; i < 3;) {
					n = rand() % v.size();
					if (ExEx[n] == 1)
						continue;
					//std::cout << n << std::endl;
					Word ExHan = v.at(n);
					ex.push_back(ExHan.getHan());
					ExEx[n] = 1;
					i++;
				}
				int Example[4] = { 0, 0, 0, 0 };
				int Hannum;
				for (int i = 0; i < 4;) {
					n = rand() % 4;
					if (Example[n] == 1)
						continue;
					//std::cout << n;
					std::cout << "(" << i + 1 << ") " << ex.at(n) << ' ';
					Example[n] = 1;
					if (ex.at(n) == Ques.getHan())
						Hannum = i + 1;
					i++;
				}
				std::cout << ":>";

				int Answer;
				std::cin >> Answer;
				if (Answer == Hannum)
					std::cout << "Excellent!" << std::endl;
				else if (Answer == 0)
					break;
				else
					std::cout << "No!!" << std::endl;
				std::cout << std::endl;
			}
		}
		else
			break;
	}
	std::cout << "프로그램 종료" << std::endl;
	return 0;
}