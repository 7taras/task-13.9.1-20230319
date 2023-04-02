// task-13.9.1-20230319.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "SocialNetwork.h"

std::string name1{ "Oleg" };
std::string name2{ "Nikita" };
std::string name3{ "Nastya" };
std::string name4{ "Vanya" };
std::string name5{ "Jenya" };

int main()
{
    SocialNetwork test;
    test.addUser(1, name1);
    test.addUser(2, name2);
    test.addUser(3, name3);
    test.addUser(4, name4);
    test.addUser(5, name5);
    test.addLink(1, 2);
    test.addLink(2, 3);
    test.addLink(3, 4);
    test.addLink(4, 5);
    std::cout << "Hello World!\n";
}

