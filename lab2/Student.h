#pragma once
#include<iostream>
#include <string>
#include <fstream>

class Student {

public:

	Student();
	Student(const std::string& LnNMn, const std::string& gender, const int& graduation, const int& studNum, const double& avRate);

	std::string getLnNMn();
	void setLnNMn(const std::string& LnNMn);

	std::string getgender();
	

	void setgender(const std::string& gender);


	int getgraduation();
	void setgraduation(const int& graduation);

	
	void nAv(double nAv);

	int getstudNum();
	void setstudNum(const int& studNum);

	double getavRate();
	void setavRate(double avRate);

	void serialize();
	void serialize(const std::string& filename);
	void deserialize();
	void deserialize(const std::string& filename);

	std::string GetInfo();

private:
	std::string LnNMn_;
	std::string gender_;
	int graduation_;
	int studNum_;
	double nAv_;
	double avRate_;



};