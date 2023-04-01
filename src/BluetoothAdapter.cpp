//
// Created by prlpr on 25/03/2023.
//


#include "BluetoothAdapter.h"

/*!
 * @brief Attempts to reconnect a Bluetooth adapter.
 * This method takes a script location as input and
 * attempts to reconnect a Bluetooth adapter by
 * executing a pair of PowerShell commands. The first
 * command turns off the Bluetooth status, and the second
 * command turns it back on after a 15-minute delay.
 * No return value is provided.
 * @param scriptLocation The file path of the PowerShell script to execute.
 */
void reconnectBluetoothAdapter(const std::string &scriptLocation) {
    std::string command1 = "powershell -ExecutionPolicy Bypass -File \"" + scriptLocation + "\" -BluetoothStatus Off";
    system(command1.c_str());
    std::this_thread::sleep_for(std::chrono::minutes(15));
    std::string command2 = "powershell -ExecutionPolicy Bypass -File \"" + scriptLocation + "\" -BluetoothStatus On";
    system(command2.c_str());
}
