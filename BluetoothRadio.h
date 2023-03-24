//
// Created by prlpr on 24/03/2023.
//
#pragma once

#ifndef AUTOBTDISCONNECT_BLUETOOTHRADIO_H
#define AUTOBTDISCONNECT_BLUETOOTHRADIO_H

#include <windows.h>
#include <BluetoothApis.h>
#include <string>
#include <stdexcept>
#pragma comment(lib, "Bthprops.lib")

class BluetoothRadio {
public:
    BluetoothRadio();
    ~BluetoothRadio();
    HANDLE GetHandle() const;

private:
    HANDLE m_hRadio;
};




#endif //AUTOBTDISCONNECT_BLUETOOTHRADIO_H
