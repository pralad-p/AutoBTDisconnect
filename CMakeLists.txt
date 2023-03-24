cmake_minimum_required(VERSION 3.24)
project(AutoBTDisconnect)

set(CMAKE_CXX_STANDARD 17)

add_executable(AutoBTDisconnect main.cpp BluetoothRadio.h BluetoothRadio.cpp BluetoothDevice.cpp BluetoothDevice.h)

find_package(cppwinrt CONFIG REQUIRED)
target_link_libraries(AutoBTDisconnect PRIVATE Microsoft::CppWinRT)