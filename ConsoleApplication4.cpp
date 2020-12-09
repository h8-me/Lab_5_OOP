#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Movie //абстрактный класс
{

public:
	string Name;
	virtual void toString() = 0;//Метод получения значения 

};

class Film : public Movie
{
public:
	string Zhanr;
	int Minutes;
	Film(string s1 = "", int k = 12, string name = "")
		: Zhanr(s1), Minutes(k)
	{
		Name = name;
		cout << "Конструктoр работает" << endl;
	}
	void toString() override
	{
		cout << "Наименование фильма: " << Zhanr << endl << "Жанр: " << Name << endl << "Продолжительность в минутах: " << Minutes << endl;
	}
};

class Anime : public Movie
{
public:
	string Vid;

	Anime(string s1 = "", string s2 = "")
		: Vid(s1)
	{
		Name = s2;
		cout << "Конструктoр работает" << endl;
	}
	void toString() override
	{
		cout << "Жанр аниме: " << Vid << "\n Название: " << Name << endl;
	}
};

class AnimationFilm : public Movie
{
public:
	string technologija;
	string country;
	int god;

	AnimationFilm(string s1 = "", string s2 = "", int s3 = 12, string n = "")
		: technologija(s1), country(s2), god(s3)
	{
		Name = n;
		cout << "Конструктoр работает" << endl;
	}
	void toString() override
	{
		cout << "Технология анимации: " << technologija << endl << "Страна: " << country << endl << "Год издания: " << god << endl;
	}
};
int main()
{
	system("chcp 1251");
	system("cls");
	string a, b, r, t;
	int c = 0, v = 0;
	cout << "Введите наименование фильма:" << endl;
	getline(cin, a);
	cout << "Введите жанр фильма:" << endl;
	getline(cin, b);
	cout << "Введите количество минут в фильме:" << endl;
	regex integers(R"(\d+)"); // формальный язык поиска и осуществления манимуляций с подстракими в тексте
	char input[80];
	do
	{
		memset(input, 0, 80);//Выделяем динамически память для строки // присовние начальных значений
		cin >> input;
		if (regex_match(input, input + strlen(input), integers))//Условие на соответствие регулярному выражения // возвращает длину строки // формальный язык поиска и осуществления манимуляций с подстракими в тексте
		{
			c = atoi(input);//atoi - Преобразуем строку в integer 
			break;
		}
		else
		{
			cout << "Ошибка! Введите число!";
		}
	} while (1);
	cout << "Введите технологию анимации:" << endl;
	cin >> r;
	cout << "Введите страну издания:" << endl;
	cin >> t;
	cout << "Введите год издания:" << endl;
	regex integers1(R"(\d+)");
	char input1[80];
	do
	{
		memset(input1, 0, 80);//Выделяем динамически память для строки
		cin >> input1;
		if (regex_match(input1, input1 + strlen(input1), integers))//Условие на соответствие регулярному выражения
		{
			v = atoi(input1);//atoi - Преобразуем строку в integer 
			break;
		}
		else
		{
			cout << "Ошибка! Введите число!";
		}
	} while (1);
	//cin >> v;
	Movie* movie[3];
	AnimationFilm f2(r, t, v, a);
	Film fi(a, c, b);//Создаем экземпляр объекта Info заносим данные через конструктор(метод инициализации)
	Anime anima("guro-gachi-muchi", a);
	movie[0] = &f2;
	movie[1] = &fi;
	movie[2] = &anima;
	for (int i = 0; i < 3; i++) {
		cout << endl;
		movie[i]->toString();
	}
	system("pause");
	return 0;
}
