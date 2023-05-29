#pragma once
#include "../include/head.h"
// 命令处理所用的头文件
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
vector<string> split(string str);
void Switch_Demand(vector<string> demand_vector, map<string, File *> file_open);