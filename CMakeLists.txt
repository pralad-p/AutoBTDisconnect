cmake_minimum_required(VERSION 3.24)
project(AutoBTDisconnect)

set(CMAKE_CXX_STANDARD 17)

add_executable(AutoBTDisconnect src/main.cpp include/BluetoothRadio.h src/BluetoothRadio.cpp src/BluetoothDevice.cpp
        include/BluetoothDevice.h src/AudioCheck.cpp include/AudioCheck.h src/BluetoothAdapter.cpp
        include/BluetoothAdapter.h)

find_package(cppwinrt CONFIG REQUIRED)
target_link_libraries(AutoBTDisconnect PRIVATE Microsoft::CppWinRT)
target_include_directories(AutoBTDisconnect PRIVATE include)
