#pragma once
#include <iostream>
#include <string>
/*�������� ����� Fraction ��� ������������� ������������ ������ (��� ��������� ���� ����� ����� x/y).
 ����������� ��������� +, -, *, / ��� ������.
 ����������� ����� void reduce() ��� ���������� �����, � ����� ����������� ������:
 int gcd(int n, int m)
������� ��� ���������� ����������� ������ �������� ����� n � m;
 void printAsFraction(double decimal_fraction)
 void printAsFraction(char* decimal_fraction)
������������� ������ ������ ���������� ����� � ���� ������������
(��������, ��� �������� decimal_fraction = 0.43 �� ������ ������ ��������� 43/100, ��� 0.25 � 1/4 � �.�.).
����� ����������� � ���� ������������ ����� ������ ������� ���� ��������� �� ������ ������ � ��������� ����������� ������.
������������������ ������ ���������� ������. ������� ��������� �������� ������.
���������� �������� ��������, ���������, ��������� � ������� ������. ������� �� ����� ����������.
�������� ����� ���������� ������ ����������� ������� ������.*/
class Fraction
{

public:
	Fraction();
	Fraction(int n, int m); 
	void setM(int m);
	void setN(int n);
	int getM();
	int getN();
	int getTotalFractions();

	Fraction operator+(const Fraction& term);
	Fraction operator-(const Fraction& subtrahend);
	Fraction operator*(const Fraction& factor);
	Fraction operator/(const Fraction& divisor);

	void reduce(); 
	static int gcd(int n, int m); 
	static int lcm(int a, int b);
	static void printAsFraction(double decimal_fraction); 
	static void printAsFraction(char* decimal_fraction); 
	void printFrac();


private:
	int n_;
	int m_;
	static int countFractions;

};
