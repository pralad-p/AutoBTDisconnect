//
// Created by prlpr on 24/03/2023.
//

#include "BluetoothDevice.h"

/*!
 * @brief Initializes a Bluetooth device with the given radio.
 * This constructor initializes a Bluetooth device object with
 * the given radio.
 * @param radio The Bluetooth radio to associate with the device.
 */
BluetoothDevice::BluetoothDevice(const BluetoothRadio &radio) : m_radio(radio) {}

/*!
 * @brief Checks if the specified Bluetooth device is connected.
 * This method takes a device name as input and searches for it
 * using the radio associated with the device. If the device is
 * found and is currently connected, the method returns true.
 * Otherwise, false is returned.
 * @param deviceName The name of the Bluetooth device to check.
 * @return True if the specified device is connected, false otherwise.
 */
bool BluetoothDevice::IsConnected(const std::wstring &deviceName) const {
    BLUETOOTH_DEVICE_SEARCH_PARAMS searchParams = {sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS)};
    searchParams.fReturnAuthenticated = TRUE;
    searchParams.fReturnConnected = TRUE;
    searchParams.hRadio = m_radio.GetHandle();

    BLUETOOTH_DEVICE_INFO deviceInfo = {sizeof(BLUETOOTH_DEVICE_INFO)};
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
