//
// Created by prlpr on 24/03/2023.
//

#include "BluetoothRadio.h"

/*!
 * @brief Initializes a Bluetooth radio object.
 * This constructor initializes a Bluetooth radio
 * object by searching for the first available radio.
 * If no radio is found, an exception is thrown.
 */
BluetoothRadio::BluetoothRadio() {
    BLUETOOTH_FIND_RADIO_PARAMS radioParams = {sizeof(BLUETOOTH_FIND_RADIO_PARAMS)};
    HBLUETOOTH_RADIO_FIND hFind = BluetoothFindFirstRadio(&radioParams, &m_hRadio);
    if (hFind == nullptr) {
        throw std::runtime_error("Error finding Bluetooth radio");
    }
    BluetoothFindRadioClose(hFind);
}

/*!
 * @brief Destroys the Bluetooth radio object.
 * This destructor closes the handle to the Bluetooth radio object.
 */
BluetoothRadio::~BluetoothRadio() {
    CloseHandle(m_hRadio);
}

/*!
 * @brief Returns the handle to the Bluetooth radio object.
 * This method returns the handle to the Bluetooth radio
 * object associated with the current instance.
 * @return The handle to the Bluetooth radio object.
 */
HANDLE BluetoothRadio::GetHandle() const {
    return m_hRadio;
}
