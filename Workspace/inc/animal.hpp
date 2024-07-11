#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <vector>

class Animal
{
private:
    int age_;

protected:
    /* data */
    std::string name_;

public:
    Animal(/* args */);
    ~Animal();
    std::string color_;
};

class Snake : private Animal
{
private:
    /* data */

protected:
    /* data */
    int length_;

public:
    Snake(/* args */);
    ~Snake();
    void MakeSound(void);
};

class Copra : public Snake
{
private:
    /* data */
public:
    Copra(/* args */);
    ~Copra();
};

#endif /* ANIMAL_HPP */
