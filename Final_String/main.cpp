#include<iostream>
#include<string>

std::string space_str(std::string str);
bool is_spam(std::string str);

int main() {
	setlocale(LC_ALL, "ru");
	int n;

	// задача 1
	//std::cout << " Задача 1 \n  Введите строку ";
	//std::string str1;
	//std::getline(std::cin, str1);
	//std::cout << space_str(str1) << "\n\n";


	//задача 2
	/*std::cout << " задача 2\n введите строку: ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << " Обнаружен спам \n\n";
	else
		std::cout << " НЕобнаружен спам \n\n";*/


	//задача 3 разбивка URL
	std::cout << " задача 3\n Адрес: ";
	std::string URL = "http://google.com/search/results";
	std::cout << URL << std::endl;

	int domen_index = URL.find("://") + 3;
	int path_index = URL.find("/", domen_index) + 1;



	std::string protocol= URL.substr(0, domen_index-3);
	std::string domen = URL.substr(domen_index, path_index-1-domen_index);
	std::string path = URL.substr(path_index);

	std::cout << " Протокол:" << protocol << std::endl;
	std::cout << " Домен:" << domen << std::endl;
	std::cout << " Путь:" << path << std::endl;


	return 0;

}

std::string space_str(std::string str) {
	std::string result;
	for (int i = 0; i < str.length(); i++) {
		result += str[i];
		if(i!=str.length()-1)
			result += ' ';
	}
	return result;

}
bool is_spam(std::string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);

	static const int spams_number = 4;
	static std::string spams[spams_number]{
		"100% free",
		"sales increase",
		"only today"
		"black Friday"
	};

	for (int i = 0; i < spams_number; i++)
		if (str.find(spams[i]) < str.length())
			return true;
	return false;

}
