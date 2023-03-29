//
// Created by prlpr on 24/03/2023.
//

#include "../include/BluetoothRadio.h"

BluetoothRadio::BluetoothRadio() {
    BLUETOOTH_FIND_RADIO_PARAMS radioParams = {sizeof(BLUETOOTH_FIND_RADIO_PARAMS)};
    HBLUETOOTH_RADIO_FIND hFind = BluetoothFindFirstRadio(&radioParams, &m_hRadio);
    if (hFind == nullptr) {
        throw std::runtime_error("Error finding Bluetooth radio");
    }
    BluetoothFindRadioClose(hFind);
}

BluetoothRadio::~BluetoothRadio() {
    CloseHandle(m_hRadio);
}

HANDLE BluetoothRadio::GetHandle() const {
    return m_hRadio;
}