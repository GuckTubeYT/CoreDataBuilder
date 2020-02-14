#pragma once
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

namespace coredata
{
	void LoadItem(int clothingType, string name, int itemID, int breakhits, int actionType);
	void items_dat();
}