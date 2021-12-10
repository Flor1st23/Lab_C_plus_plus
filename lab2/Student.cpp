#include "Student.h"



Student::Student(const std::string& LnNMn, const std::string& gender, const int& graduation, const int& studNum, const double& avRate)
{
	LnNMn_ = LnNMn;
	avRate_ = avRate;
	studNum_ = studNum;
	graduation_ = graduation;
	gender_ = gender;
}

Student::Student()
{


}


std::string Student::getLnNMn()
{
	std::string LnNMn = LnNMn_;
	return LnNMn;
}

void Student::setLnNMn(const std::string& LnNMn)
{
	LnNMn_ = LnNMn;
}

std::string Student::getgender()
{
	std::string gender = gender_;
	return gender;
}
std::string Student::GetInfo()
{
	std::string s = std::to_string(graduation_);
	std::string s1 = std::to_string(studNum_);
	std::string s2 = std::to_string(avRate_);

	return LnNMn_+" "+gender_ + " " + s + " " + s1 + " " + s2;
}

void Student::setgender(const std::string& gender)
{
	gender_ = gender;
}

int Student::getgraduation()
{
	int graduation = graduation_;
	return graduation;
}

void Student::setgraduation(const int& graduation)
{
	graduation_ = graduation;

}

void Student::nAv(double nAv)
{
}

int Student::getstudNum()
{
	int studNum = studNum_;
	return studNum;
}

void Student::setstudNum(const int& studNum)
{
	studNum_ = studNum;

}

double Student::getavRate()
{
	double avRate = avRate_;
	return avRate;
}

double Student::navRate(double nAv)
{
	double avRate = (avRate_ +nAv)/5;
	return avRate;
}


void Student::setavRate(double avRate)
{
	avRate_ = avRate;

}




void Student::serialize()
{
	std::cout << "Writing file" << std::endl;
	std::ofstream writeStream;
	writeStream.open("Students.txt", std::ios::app);
	if (writeStream.is_open() == false) {
		std::cout << "Open file error!";
	}
	else {
		writeStream << getLnNMn() << "\n" << getgender() << "\n" << getgraduation() << "\n" << getstudNum() << "\n"
			<< getavRate() << "\n";
	}
	writeStream.close();

}

void Student::serialize(const std::string& filename)
{
	std::cout << "Writing file" << std::endl;
	std::ofstream writeStream;
	writeStream.open("Students.txt", std::ios::app);
	if (writeStream.is_open() == false) {
		std::cout << "Open file error!";
	}
	else {
		writeStream << getLnNMn() << "\n" << getgender() << "\n" << getgraduation() << "\n" << getstudNum() << "\n"
			<< getavRate() << "\n";
	}
	writeStream.close();
}

void Student::deserialize()
{
	std::cout << "Reading file..." << std::endl;
	std::string line;
	std::ifstream readStream("Students.txt");
	if (!readStream.is_open()) {
		std::cout << "Open file error!" << std::endl;
	}
	else {
		while (getline(readStream, line)) {
			std::cout << line << std::endl;
		}
	}
	readStream.close();
}

void Student::deserialize(const std::string& filename)
{
	std::cout << "Reading file..." << std::endl;
	std::string line;
	std::ifstream readStream("Students.txt");
	if (!readStream.is_open()) {
		std::cout << "Open file error!" << std::endl;
	}
	else {
		while (getline(readStream, line)) {
			std::cout << line << std::endl;
		}
	}
	readStream.close();
}




