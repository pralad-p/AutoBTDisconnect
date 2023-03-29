#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include "BluetoothRadio.h"
#include "BluetoothDevice.h"
#include "AudioCheck.h"
#include "BluetoothAdapter.h"

int main(int argc, char* argv[]) {
    try {
        // Parse the command-line arguments
        std::vector<std::string> args(argv, argv + argc);
        // Remove the first argument, which is the program name
        args.erase(args.begin());

        // Look for -n and -s flags and their arguments
        std::string deviceName;
        std::string script_location;
        for (auto it = args.begin(); it != args.end(); ++it) {
            if (*it == "-n" && (it + 1) != args.end()) {
                deviceName = *(it + 1);
                it++;
            }
            else if (*it == "-s" && (it + 1) != args.end()) {
                script_location = *(it + 1);
                it++;
            }
        }

        std::wstring device_name(deviceName.begin(), deviceName.end());

        BluetoothRadio radio;
        BluetoothDevice device(radio);
        auto startTime = std::chrono::steady_clock::now();
        std::chrono::time_point<std::chrono::steady_clock> currentTime;
        std::chrono::minutes noAudioThreshold(10);

        while (true) {
            if (device.IsConnected(device_name)) {
                if (isAudioPlaying()) {
                    startTime = std::chrono::steady_clock::now();
                    std::cout << "Audio still playing. \n";
                } else {
                    currentTime = std::chrono::steady_clock::now();
                    auto diff = currentTime - startTime;
                    std::cout << "Current gap: " << std::chrono::duration_cast<std::chrono::minutes>(diff).count()
                              << "\n";
                    if (currentTime - startTime >= noAudioThreshold) {
                        reconnectBluetoothAdapter(script_location);
                        std::cout << "Bluetooth adapter disabled.\n";
                        exit(0);
                    }
                }
                std::this_thread::sleep_for(std::chrono::minutes(1));
            } else {
                std::this_thread::sleep_for(std::chrono::minutes(10));
            }
        }
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
}
