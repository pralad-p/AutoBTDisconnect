#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include "BluetoothRadio.h"
#include "BluetoothDevice.h"
#include "AudioCheck.h"
#include "BluetoothAdapter.h"

#define DEBUG true

/*!
 * @brief Entry point for main program
 * @param argc number of CLI arguments
 * @param argv array of CLI arguments
 * @return Status code for good (or bad) exit
 */
int main(int argc, char *argv[]) {
    try {
        std::vector<std::string> args(argv, argv + argc);
        // Remove the first argument, which is the program name
        args.erase(args.begin());

        std::string deviceName, script_location, threshold, scan_interval;
        for (auto it = args.begin(); it != args.end(); ++it) {
            if ((*it == "-n" || *it == "--name") && (it + 1) != args.end()) {
                deviceName = *(it + 1);
                it++;
            } else if ((*it == "-s" || *it == "--script") && (it + 1) != args.end()) {
                script_location = *(it + 1);
                it++;
            } else if ((*it == "-t" || *it == "--threshold") && (it + 1) != args.end()) {
                threshold = *(it + 1);
                it++;
            } else if ((*it == "-si" || *it == "--scan-interval") && (it + 1) != args.end()) {
                scan_interval = *(it + 1);
                it++;
            } else if ((*it == "-v" || *it == "--version") && (it + 1) != args.end()) {
                std::cout << "AutoBTDisconnect 1.0" << std::endl;
                exit(0);
                it++;
            }
        }
        if (deviceName.empty()) {
            if (DEBUG) {
                std::cout << "No device name provided." << std::endl;
            }
            exit(-1);
        }
        if (script_location.empty()) {
            if (DEBUG) {
                std::cout << "No script location provided." << std::endl;
            }
            exit(-1);
        }
        int audioThresholdValue = (threshold.empty()) ? 15 : std::stoi(threshold);
        int scanIntervalValue = (scan_interval.empty()) ? 10 : std::stoi(scan_interval);

        std::wstring device_name(deviceName.begin(), deviceName.end());

        BluetoothRadio radio;
        BluetoothDevice device(radio);
        auto startTime = std::chrono::steady_clock::now();
        std::chrono::time_point<std::chrono::steady_clock> currentTime;
        std::chrono::minutes noAudioThreshold(audioThresholdValue);

        while (true) {
            if (device.IsConnected(device_name)) {
                if (isAudioPlaying()) {
                    startTime = std::chrono::steady_clock::now();
                    if (DEBUG) std::cout << "Audio still playing. \n";
                } else {
                    currentTime = std::chrono::steady_clock::now();
                    auto diff = currentTime - startTime;
                    if (DEBUG) {
                        std::cout << "Current gap: " << std::chrono::duration_cast<std::chrono::minutes>(diff).count()
                                  << "\n";
                    }
                    if (currentTime - startTime >= noAudioThreshold) {
                        reconnectBluetoothAdapter(script_location);
                        if (DEBUG) std::cout << "Bluetooth adapter disabled.\n";
                    }
                }
                std::this_thread::sleep_for(std::chrono::minutes(1));
            } else {
                std::this_thread::sleep_for(std::chrono::minutes(scanIntervalValue));
            }
        }
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
}
