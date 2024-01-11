#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Book {
	int year;
	std::string name;
	std::string book;
public:
	void set(int year, std::string name, std::string book) {
		this->year = year;
		this->name = name;
		this->book = book;
	}
	int getYear() {
		return this->year;
	}
	std::string getName() {
		return this->name;
	}
	std::string getBook() {
		return this->book;
	}
};

int main() {
	std::vector<Book> v;
	int Start = 0;
	while (1) {
		std::cout << "입고를 원한다면 1, 검색을 원한다면 2, 입고 현황이 원한다면 3, 종료를 원한다면 -1>>";
		std::cin >> Start;
		if (Start == 1) {
			std::cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << std::endl;
			Book Info;
			while (1) {
				std::cout << "년도>>";
				int year;
				std::cin >> year;
				if (year == -1)
					break;
				std::cin.ignore();
				std::cout << "저자>>";
				char name[100];
				std::cin.getline(name, 100, '\n');
				std::cout << "책이름>>";
				char book[100];
				std::cin.getline(book, 100, '\n');
				if(year != -1) {
					Info.set(year, name, book);
					v.push_back(Info);
				}
			}
		}
		else if (Start == 2) {
			std::cout << "총 입고된 책은 " << v.size() << "권입니다." << std::endl;
			std::cout << "종료를 원한다면 -1을 입력하세요." << std::endl;
			std::cin.ignore();
			char search[100];
			while (1) {
				std::cout << "검색하고자 하는 저자 이름 또는 년도를 입력하세요>>";
				std::cin.getline(search, 100, '\n');
				std::stringstream Input(search);
				int Year_search;
				if (Input >> Year_search) {
					int flag = 0;
					if (Year_search == -1)
						break;
					for (int i = 0; i < v.size(); i++) {
						if (v.at(i).getYear() == Year_search) {
							std::cout << v.at(i).getYear() << "년도, " << v.at(i).getBook() << ", " << v.at(i).getName() << std::endl;
							flag = 1;
						}
					}
					if(flag != 1)
						std::cout << Year_search << "년도에 해당하는 입고된 책이 없습니다." << std::endl;
				}
				else {
					int flag = 0;
					for (int i = 0; i < v.size(); i++) {
						if (v.at(i).getName() == search) {
							std::cout << v.at(i).getYear() << "년도, " << v.at(i).getBook() << ", " << v.at(i).getName() << std::endl;
							flag = 1;
						}
					}
					if(flag != 1)
						std::cout << search << "저자에 해당하는 입고된 책이 없습니다." << std::endl;
				}
			}
		}
		else if (Start == 3) {
			std::cout << "현재 입고된 책은 " << v.size() << "권입니다." << std::endl;
		}
		else if(Start == -1)
			break;
	}
}