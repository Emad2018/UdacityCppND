#include <iostream>
#include "animal.hpp"

Animal::Animal(/* args */)
{
}

Animal::~Animal()
{
}
Snake::Snake(/* args */)
{
    name_ = "Snake";
    length_ = 5;

    color_ = "red";
}

Snake::~Snake()
{
}
void Snake::MakeSound(void)
{
    std::cout << "Snake\n";
}
Copra::Copra(/* args */)
{
    length_ = 5;
}

Copra::~Copra()
{
}