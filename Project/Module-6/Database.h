#pragma once
#include "../Module-4/History-1.h"
#include "../Headers/MyArray.h" 
#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;

class Database {
private:
    Database() {} // private constructor for singleton

public:
    static Database& getInstance() {
        static Database instance;
        return instance;
    }

    Database(Database const&) = delete;
    void operator=(Database const&) = delete;

    void writeHistory(const History& h);
    void readHistory(MyArray<History>& historyArray);
};