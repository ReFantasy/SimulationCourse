#pragma once
#include "types.h"
#include <iostream>
#include <string>
#include <vector>
namespace snow
{
    bool readTobjFile(const std::string &filename, std::vector<VECTOR3> &vertices, std::vector<VECTOR4I> &tets);
}
