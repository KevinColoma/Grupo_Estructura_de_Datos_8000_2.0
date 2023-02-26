#pragma once
#include <string>
#include <iostream>
#include "avl_node.h"

class Trunk
{
public:
    Trunk* prev = nullptr;
    std::string str;
    Trunk(Trunk* prev, std::string str)
    {
        this->prev = prev;
        this->str = str;
    }
};