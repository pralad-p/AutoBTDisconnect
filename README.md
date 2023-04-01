# AutoBTDisconnect

AutoBTDisconnect is a Windows app that saves Bluetooth audio device battery by automatically disconnecting them after a
set idle time. Developed in C++, it uses Windows Bluetooth and Core Audio APIs with minimal system resource usage.

## Table of contents

[Features](#features)<br>
[Use-Case](#use-case)<br>
[Requirements](#requirements)<br>
Installation<br>
Usage<br>
[License](#license)<br>

## Features

- Monitors audio playback through Bluetooth device
- Choose device through Bluetooth device name
- Automatically disconnects Bluetooth headphones after a user-defined period of inactivity
- Lightweight and low resource usage

## Use-Case

AutoBTDisconnect is particularly helpful for users of Sony WH-1000XM3 headphones on Windows computers. As there is no
native Headphones Connect app for Windows, the auto-power off functionality is only enabled when the headphones are
disconnected from the computer. This application proves to be valuable for individuals who leave their machines running
for extended periods without an auto-sleep rule (e.g., when running long workloads). By using AutoBTDisconnect, they can
save battery life on their headphones while ensuring seamless connectivity when needed.

## Requirements

- Works on Windows 11
- [ ] Older Windows versions (TBC)

## Installation

## Usage

To use the AutoBTDisconnect tool, run the command with the appropriate options and arguments as described below:

```c++
AutoBTDisconnect.exe [OPTIONS] [ARGUMENTS]
```

### Options

1. **-n, --name <deviceName>**: Specify the Bluetooth device name you want to monitor. Replace <deviceName> with the actual
   device name.
2. **-s, --script <script_location>**: Provide the location of the script to execute for toggling the BT adapter. Replace <
   script_location> with the path to your script.
3. **-t, --threshold <threshold>**: Set the threshold for the inactivity timeout before disconnecting the Bluetooth device.
   Replace <threshold> with the desired value (e.g., 10 for 10 minutes).
4. **-si, --scan-interval <scan_interval>**: Set the interval between scans for connection confirmation. Replace <
   scan_interval> with the desired value in minutes (e.g., 30 for 30 minutes).
5. **-v, --version**: Display the current version of AutoBTDisconnect.

```c++
AutoBTDisconnect.exe -n "My Headphones" -s "C:/path/to/script.sh"
AutoBTDisconnect.exe -n "My Headphones" -s "C:/path/to/script.sh" --threshold 10 --scan-interval 30
AutoBTDisconnect.exe -n "My Headphones" -s "C:/path/to/script.sh" -t 5 -si 2
```

## License

AutoBTDisconnect is released under the [MIT License](/LICENSE).

