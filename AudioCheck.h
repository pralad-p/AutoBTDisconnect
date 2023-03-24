//
// Created by prlpr on 24/03/2023.
//
#pragma once
#ifndef AUTOBTDISCONNECT_AUDIOCHECK_H
#define AUTOBTDISCONNECT_AUDIOCHECK_H

#include <Audioclient.h>
#include <Mmdeviceapi.h>
#include <Audiopolicy.h>
#pragma comment(lib, "Ole32.lib")
#pragma comment(lib, "Avrt.lib")
bool isAudioPlaying();

#endif //AUTOBTDISCONNECT_AUDIOCHECK_H
