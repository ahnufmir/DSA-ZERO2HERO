#include "Database.h"

void Database::writeHistory(const History& h) {
    json allData = json::array();

    ifstream inFile("history.json");
    if (inFile.is_open() && inFile.peek() != ifstream::traits_type::eof()) {
        inFile >> allData;
        inFile.close();
    }

    json j;
    j["Case ID"] = h.getCaseID();
    j["Case Type"] = h.getCaseType();
    j["Severity"] = h.getSeverity();
    j["Case Status"] = h.getCaseStatus();
    j["Unit ID"] = h.getUnitID();
    j["Unit Type"] = h.getUnitType();
    j["Unit Status"] = h.getUnitStatus();
    j["Estimated Time"] = h.getETA();

    allData.push_back(j);

    ofstream outFile("history.json");
    outFile << allData.dump(4);
    outFile.close();
}

void Database::readHistory(MyArray<History>& historyArray) {
    ifstream inFile("history.json");
    if (!inFile.is_open() || inFile.peek() == ifstream::traits_type::eof())
        return; // file empty or not found

    json allData;
    inFile >> allData;
    inFile.close();

    for (const auto& item : allData) {
        History h;
        h.setCaseID(item["Case ID"]);
        h.setCaseType(item["Case Type"]);
        h.setSeverity(item["Severity"]);
        h.setCaseStatus(item["Case Status"]);
        h.setunitID(item["Unit ID"]);
        h.setUnitType(item["Unit Type"]);
        h.setUnitStatus(item["Unit Status"]);
        h.setETA(item["Estimated Time"]);

        historyArray.append(h); // your dynamic array push
    }
}
