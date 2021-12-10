/*Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы No1 с помощью созданных классов.
 Все функции оформить в виде методов классов.
В коде отразить следующее:
 Выделение и освобождение динамической памяти производить в конструкторах и деструкторах классов, соответственно.
 В классе Vector перегрузить оператор индексации []. В классе Matrix добавить методы T at(int i, int j) const и
setAt(int i, int j, T val), которые позволяют получить и установить значение элемента массива с индексом [i][j],
 T – это тип элементов массива по варианту (int или double).
 Перегрузить операторы инкремента и декремента (как префиксного, так и постфиксного).
Смысл инкремента / декремента всего массива заключается в инкременте / декременте каждого элемента массива.*/

/*Преобразование: 1D → 2D. Одномерный массив из 25 вещественных чисел необходимо
разложить по двумерной сетке 5х5 слева направо и сверху вниз, но первый элемент на
каждой строке должен содержать сумму остальных четырех.
Инициализация: заполнить массив числами x[n] = n ∙ sin(πn/25), n – индекс элемента.
Вывод на экран: на каждый элемент массива отвести 10 позиций.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Vector.h"
#include "Matrix.h"
#include "Fraction.h"
#include "Student.h"
#define M_PI 3.14159265358979323846


using namespace std;

 
void From2to1(Matrix& array2D, Vector& array1D);
void Task1();
void Task2();
void Task3();


int main()
{
    std::cout << "Task 1" << std::endl;
    Task1();
    std::cout << std::endl;

    std::cout << "Task 2" << std::endl;
    Task2();
    std::cout << std::endl;

    std::cout << "Task 3" << std::endl;
    Task3();
    std::cout << std::endl;

    return 0;
}


void From2to1(Matrix& array2D, Vector& array1D) {
    int k = 0;
    for (int i = 0; i < array2D.getRows(); i++) {
        for (int j = 0; j < array2D.getCols(); j++) {

            array1D[k++] = array2D.at(i, j);

        }         
    }
}

void Task1() {
    Matrix array2D(5, 5);
    Vector array1D(25);

    int x = 0;

    for (int i = 0; i < array2D.getRows(); i++) {
        for (int j = 0; j < array2D.getCols(); j++) {
            array2D.setAt(i, j, (x * sin((M_PI * x / 25))));
            x++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        double num = 0;
        for (int j = 1; j < 5; j++)
        {
            num = num + array2D.at(i,j);
        }
        array2D.setAt(i, 0, (num));
        num = 0;
    }


    array2D.printFormated();

    std::cout << " => \n" << std::endl;
    From2to1(array2D, array1D);
    std::cout << array1D << std::endl;


    std::cout << "PREFIX & POSTFIX 1D test" << std::endl;
    std::cout << "postfix" << std::endl;
    array1D++;
    std::cout << array1D;
    std::cout << "prefix" << std::endl;
    ++array1D;
    std::cout << array1D;
    std::cout << "PREFIX & POSTFIX 2D test" << std::endl;
    std::cout << "postfix" << std::endl;
    array2D++;
    array2D.printFormated();
    std::cout << std::endl;
    std::cout << "prefix" << std::endl;
    ++array2D;
    array2D.printFormated();
    std::cout << std::endl;

}

void Task2()
{
    Fraction frac(8, 20);
    Fraction frac2(3, 20);
    Fraction frac3 = frac / frac2;

    std::cout << "fraction 1" << std::endl;
    frac.printFrac();
    std::cout << "fraction 2" << std::endl;
    frac2.printFrac();
    std::cout << "fraction 1 / fraction2" << std::endl;
    frac3.printFrac();

    std::cout << "input text" << std::endl;
    char str[] = "0.43";
    std::cout << "input num" << std::endl;
    double numb = 0.25;
    frac.printAsFraction(str);
    frac.printAsFraction(numb);
    std::cout << frac.getTotalFractions();
    std::cout << std::endl;
}

void Task3() 
{
    /*
    Student* stud2 = new Student();
    stud2->setLnNMn("Vasua Pupkin YAroslavovich");
    stud2->setgender("male");
    stud2->setgraduation(2020);
    stud2->setstudNum(00002021);
    stud2->setavRate(3.3);
    stud2->serialize();*/
    /*
    Student* stud1 = new Student();
    stud1->setLnNMn("Pupkin Petya Fedorovitch");
    stud1->setgender("male");
    stud1->setgraduation(2020);
    stud1->setstudNum(00002022);
    stud1->setavRate(3.3);
    stud1->serialize();*/

    Student arr[3];
    arr[0] = Student("Ivanov Ivan Ivanovich", "male", 2020, 00002020, 4.589);
    arr[1] = Student("Pchelkin Boris Leonidovich", "male", 2222, 00002021, 3.125);
    arr[2] = Student("Shlyapkin Anatoliy Borisovich", "male", 2222, 00002021, 5);

    
    for (int i = 0; i < 3; i++) 
    {
        srand(time(0));
        int gr1 = rand() % 5 + 2;
        int gr2 = rand() % 5 + 2;
        int gr3 = rand() % 5 + 2;
        int gr4 = rand() % 5 + 2;


        arr[i].setavRate((arr[i].getavRate()+gr1+gr2+gr3+gr4)/4);

        std::cout << arr[i].GetInfo() << std::endl;
    }

}


