
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <tchar.h>
#include <sstream>
#include <Windowsx.h>

//1.Написать приложение, позволяющее вывести на экран краткое резюме с помощью последовательности 
//окон сообщений (количество окон сообщений – не менее трёх).
//На заголовке последнего окна сообщения должно отобра - зиться среднее число символов на 
//странице(общее число символов в резюме поделить на количество окон сообщений).

typedef std::basic_string<TCHAR> tstring;
#ifdef _UNICODE
#define TO_TSTRING std::to_wstring
#else
#define TO_TSTRING std::to_string
#endif

// Global variables
tstring GlueTwoLinesAndNum(tstring oneString, int number, tstring twoString);
tstring GlueTwoLines(tstring oneString, tstring twoString);

INT WINAPI _tWinMain(HINSTANCE hInstance /*дескриптор текущего приложения*/, HINSTANCE hPrevInstance/*дескриптор предыдущего приложения*/, LPTSTR lpCmdLine/*переданные параметры программе*/, INT nCmdShow/*возможность отображение консоли*/)
{
	tstring s = TEXT("Меня зовут Никита");
	int size = s.size();
	auto x = MessageBox(NULL, s.c_str(), TEXT("test"), MB_OKCANCEL | MB_DEFBUTTON2);
	if (x == IDOK)
	{
		tstring s1 = TEXT("Мне 24 года");
		x = MessageBox(NULL, s1.c_str(), TEXT("test"), MB_OKCANCEL);
		size += s1.size();
	}
	if (x == IDOK)
	{
		tstring s1 = TEXT("Учусь в \"ШАГЕ\"");
		x = MessageBox(NULL, s1.c_str(), TEXT("test"), MB_OKCANCEL);
		size += s1.size();
	}
	tstring resum = GlueTwoLinesAndNum(TEXT("Ваше резюме состоит из "), size, TEXT(" символов."));
	MessageBox(NULL, resum.c_str(), TEXT("test"), MB_OK);


	/*2.	Написать приложение, которое «угадывает» задуманное пользователем число от 1 до 100. Для запроса к пользователю использовать окна сообще - ний.
		После того, как число отгадано, необходимо вывести количество попы - ток, потребовавшихся для этого, и предоставить
		пользователю возможность сыграть еще раз, не завершая программу.
		Окна сообщений следует оформить кнопками и иконками в соответствии с конкретной ситуацией.
		При выполнении вышеприведенных заданий ввиду отсутствия необхо - димости  создания главного окна приложения, 
		реализацию алгоритма можно привести непосредственно в главной функции программы.
		Тогда каркас приложения может иметь следующий вид :*/
	while (true)
	{
		static UINT num = 0;
		static UINT count = 1;
		tstring str = GlueTwoLines(TEXT("Ваше число = "), TO_TSTRING(num));
		INT a = MessageBox(NULL, str.c_str(), TEXT("Угадай число"), MB_ICONQUESTION | MB_OKCANCEL);
		if (a == IDOK)
		{
			tstring counter = GlueTwoLinesAndNum(TEXT("Мы угадали число с "), count, TEXT(" попытки"));
			MessageBox(NULL, counter.c_str(), TEXT("Вы победили"), MB_OK | MB_ICONASTERISK);
			INT restart = MessageBox(NULL, TEXT("Нажмите OK что бы сыграть заного или нажмите ОТМЕНА для выхода"), TEXT("Повторим игру?"), MB_OKCANCEL | MB_ICONQUESTION);
			if (restart == IDOK)
			{
				num = 0;
				count = 1;
				continue;
			}
			else
				break;
		}
		++num;
		++count;
	}
	return 0;
}

tstring GlueTwoLinesAndNum(tstring oneString, int number, tstring twoString)
{
	tstring str = oneString;
	str += TO_TSTRING(number);
	str += twoString;
	return str;
}
tstring GlueTwoLines(tstring oneString, tstring twoString)
{
	tstring str = oneString;
	str += twoString;
	return str;
}