//
// Created by prlpr on 24/03/2023.
//
#pragma once
#ifndef AUTOBTDISCONNECT_BLUETOOTHDEVICE_H
#define AUTOBTDISCONNECT_BLUETOOTHDEVICE_H

#include <string>
#include "BluetoothRadio.h"

class BluetoothDevice {
public:
    BluetoothDevice(const BluetoothRadio &radio);
    bool IsConnected(const std::wstring &deviceName) const;

private:
    const BluetoothRadio &m_radio;
};

#endif //AUTOBTDISCONNECT_BLUETOOTHDEVICE_H
