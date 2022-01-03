#pragma once 

#include<iostream>
#include <conio.h>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <stdio.h>

using namespace std;

//�������� ����� ������, ������������ ����������� ������ �� ����� 10x10, 
//� �������� ���� �����, ���������� ������� ������������� �� �������� �������.
//��� ������ ������ ��������� ������ - ���������� OffTheField, ���� ����� ������ ���� � �����,
//� IllegalCommand, ���� ������ �������� �������(����������� �� ��������� � ������ ���������).
//������ ���������� ������ ��������� ��� ����������� ���������� � ������� ������� � ����������� ��������.
//�������� ������� main, ������������ ���� ������� � ��������������� ��� ���������� �� ��� �������,
//� ����� ��������� ��������� ���������� � ���� ����������� �������.
const int Sz = 20;
struct Matrix
{
	int width = Sz;
	int height = Sz;
};
Matrix point;
class OffTheField : public exception
{
public:
	void error()
		{
		cout << "�� ��������� ����� �� ������� ����!!! � ��� ������ ������!!!!" << endl;
		}
};

class IllegalCommand : public exception
{
public:
	void error()
	{
		cout << "�� ������� �� ����!!!" << endl;

	}
};
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
void ClearrScr()
{
	system("cls");
}

//-----------------------------------------------------------------------------------------
enum rb
{
	EMPTY = ' ',
	ROBOT = '@'
};
//-----------------------------------------------------------------------------------------
class Robot
{
public:

	Robot() : upDown(Sz / 2 - 1), rightLeft(Sz / 2 - 1)
	{
		for (point.height = 0; point.height < Sz; point.height++)
		{
			
			for (point.width = 0; point.width < Sz; point.width++)
			{
				 coord[point.height][point.width] = EMPTY;
			}
			coord[upDown][rightLeft] = ROBOT;
		}
		
	}


	void progressWork()
	{
		cout << "������� ����������� �������� ������: 4 - < (����) , 6 - > (�����) , 8 - ^ (����) , 9 - v (���).    ";

		int direction;
		cin >> direction;
		if (direction == 8)
		{
			point.width = (--upDown);
			point.height = rightLeft;
		}
		else if (direction == 2)
		{
			point.width = (++upDown);
			point.height = rightLeft;
		}
		else if (direction == 4)
		{
			point.height = (--rightLeft);
			point.width = upDown;
		}
		else if (direction == 6)
		{
			point.height = (++rightLeft);
			point.width = upDown;
		}
		else
		{
			coord[upDown][rightLeft] = ROBOT;
			throw IllegalCommand();
		}

		if (point.height < 0 || point.height > Sz - 1 || point.width < 0 || point.width > Sz - 1 )
		{
			if (upDown < 0)
			{
				upDown = 0;
			}
			if (upDown > Sz - 1)
			{
				upDown = Sz - 1;
			}
			if (rightLeft < 0)
			{
				rightLeft = 0;
			}
			if (rightLeft > Sz - 1)
			{
				rightLeft = Sz - 1;
			}
			coord[upDown][rightLeft] = ROBOT;
			throw OffTheField();
		}
		coord[point.width][point.height] = ROBOT;
	}
	void  clearing_the_field()
	{
		for (point.height = 0; point.height < Sz; point.height++)
		{
			for (point.width = 0; point.width < Sz; point.width++)
			{
				coord[point.height][point.width] = EMPTY;
			}
		}
	}
	void output_to_the_screen()
	{
		for (point.height = 0; point.height < Sz; point.height++)
		{
			for (point.width = 0; point.width < Sz; point.width++)
			{
				cout << '|' << static_cast <char>(coord[point.height][point.width]);
			}

			cout << '|' << endl;
		}
	}
	
private:
	rb coord[Sz][Sz];
	int upDown;
	int rightLeft;
	
};
//-----------------------------------------------------------------------------------------
