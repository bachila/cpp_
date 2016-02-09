
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <tchar.h>
#include <sstream>
#include <Windowsx.h>

//1.�������� ����������, ����������� ������� �� ����� ������� ������ � ������� ������������������ 
//���� ��������� (���������� ���� ��������� � �� ����� ���).
//�� ��������� ���������� ���� ��������� ������ ������ - ������ ������� ����� �������� �� 
//��������(����� ����� �������� � ������ �������� �� ���������� ���� ���������).

typedef std::basic_string<TCHAR> tstring;
#ifdef _UNICODE
#define TO_TSTRING to_wstring
#else
#define TO_TSTRING to_string
#endif

// Global variables
tstring GlueTwoLinesAndNum(tstring oneString, int number, tstring twoString);
tstring GlueTwoLines(tstring oneString, tstring twoString);

INT WINAPI _tWinMain(HINSTANCE hInstance /*���������� �������� ����������*/, HINSTANCE hPrevInstance/*���������� ����������� ����������*/, LPTSTR lpCmdLine/*���������� ��������� ���������*/, INT nCmdShow/*����������� ����������� �������*/)
{
	tstring s = TEXT("���� ����� ������");
	int size = s.size();
	auto x = MessageBox(NULL, s.c_str(), TEXT("test"), MB_OKCANCEL | MB_DEFBUTTON2);
	if (x == IDOK)
	{
		tstring s1 = TEXT("��� 24 ����");
		x = MessageBox(NULL, s1.c_str(), TEXT("test"), MB_OKCANCEL);
		size += s1.size();
	}
	if (x == IDOK)
	{
		tstring s1 = TEXT("����� � \"����\"");
		x = MessageBox(NULL, s1.c_str(), TEXT("test"), MB_OKCANCEL);
		size += s1.size();
	}
	tstring resum = TEXT("���� ������ ������� �� ");
	resum += std::TO_TSTRING(size);
	resum += TEXT(" ��������.");
	MessageBox(NULL, resum.c_str(), TEXT("test"), MB_OK);


	/*2.	�������� ����������, ������� ���������� ���������� ������������� ����� �� 1 �� 100. ��� ������� � ������������ ������������ ���� ������ - ���.
		����� ����, ��� ����� ��������, ���������� ������� ���������� ���� - ���, ��������������� ��� �����, � ������������
		������������ ����������� ������� ��� ���, �� �������� ���������.
		���� ��������� ������� �������� �������� � �������� � ������������ � ���������� ���������.
		��� ���������� ��������������� ������� ����� ���������� ������ - �������  �������� �������� ���� ����������, 
		���������� ��������� ����� �������� ��������������� � ������� ������� ���������.
		����� ������ ���������� ����� ����� ��������� ��� :*/
	bool game = true;
	while (game)
	{
		static UINT num = 0;
		static UINT count = 1;
		tstring str = GlueTwoLines(TEXT("���� ����� = "), std::TO_TSTRING(num));
		INT a = MessageBox(NULL, str.c_str(), TEXT("������ �����"), MB_ICONQUESTION | MB_OKCANCEL);
		if (a == IDOK)
		{
			tstring counter = GlueTwoLinesAndNum(TEXT("�� ������� ����� � "), count, TEXT(" �������"));
			MessageBox(NULL, counter.c_str(), TEXT("�� ��������"), MB_OK | MB_ICONASTERISK);
			INT restart = MessageBox(NULL, TEXT("������� OK ��� �� ������� ������ ��� ������� ������ ��� ������"), TEXT("�������� ����?"), MB_OKCANCEL | MB_ICONQUESTION);
			if (restart == IDOK)
			{
				num = 0;
				count = 1;
				continue;
			}
			else
				game = false;
		}
		++num;
		++count;
	}

	return 0;
}

tstring GlueTwoLinesAndNum(tstring oneString, int number, tstring twoString)
{
	tstring str = oneString;
	str += std::TO_TSTRING(number);
	str += twoString;
	return str;
}
tstring GlueTwoLines(tstring oneString, tstring twoString)
{
	tstring str = oneString;
	str += twoString;
	return str;
}