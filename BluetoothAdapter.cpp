//
// Created by prlpr on 25/03/2023.
//


#include "BluetoothAdapter.h"


void reconnectBluetoothAdapter(const std::string &scriptLocation) {
    std::string command1 = "powershell -ExecutionPolicy Bypass -File \"" + scriptLocation + "\" -BluetoothStatus Off";
    system(command1.c_str());
    std::this_thread::sleep_for(std::chrono::minutes(15));
    std::string command2 = "powershell -ExecutionPolicy Bypass -File \"" + scriptLocation + "\" -BluetoothStatus On";
    system(command2.c_str());
}