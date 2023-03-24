#include <iostream>
#include <string>
#include "BluetoothRadio.h"
#include "BluetoothDevice.h"

int main() {
    try {
        BluetoothRadio radio;
        BluetoothDevice device(radio);
        std::wstring deviceName = L"WH-1000XM3";

        if (device.IsConnected(deviceName)) {
            std::wcout << L"Bluetooth device is connected" << std::endl;
        } else {
            std::wcout << L"Bluetooth device is not connected" << std::endl;
        }
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
