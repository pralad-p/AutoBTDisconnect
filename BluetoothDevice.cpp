//
// Created by prlpr on 24/03/2023.
//

#include "BluetoothDevice.h"

BluetoothDevice::BluetoothDevice(const BluetoothRadio &radio) : m_radio(radio) {}

bool BluetoothDevice::IsConnected(const std::wstring &deviceName) const {
    BLUETOOTH_DEVICE_SEARCH_PARAMS searchParams = { sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS) };
    searchParams.fReturnAuthenticated = TRUE;
    searchParams.fReturnConnected = TRUE;
    searchParams.hRadio = m_radio.GetHandle();

    BLUETOOTH_DEVICE_INFO deviceInfo = { sizeof(BLUETOOTH_DEVICE_INFO) };
    HBLUETOOTH_DEVICE_FIND hDeviceFind = BluetoothFindFirstDevice(&searchParams, &deviceInfo);

    if (hDeviceFind == nullptr) {
        return false;
    }

    bool deviceConnected = false;

    do {
        if (deviceInfo.szName == deviceName && deviceInfo.fConnected) {
            deviceConnected = true;
            break;
        }
    } while (BluetoothFindNextDevice(hDeviceFind, &deviceInfo));

    BluetoothFindDeviceClose(hDeviceFind);
    return deviceConnected;
}