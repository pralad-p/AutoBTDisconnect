//
// Created by prlpr on 24/03/2023.
//

#include "AudioCheck.h"

bool isAudioPlaying() {
    CoInitialize(nullptr);

    IMMDeviceEnumerator* pEnumerator = nullptr;
    CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);

    IMMDevice* pDevice = nullptr;
    pEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &pDevice);
    pEnumerator->Release();

    IAudioSessionManager2* pSessionManager = nullptr;
    pDevice->Activate(__uuidof(IAudioSessionManager2), CLSCTX_ALL, nullptr, (void**)&pSessionManager);
    pDevice->Release();

    IAudioSessionEnumerator* pSessionEnumerator = nullptr;
    pSessionManager->GetSessionEnumerator(&pSessionEnumerator);
    pSessionManager->Release();

    int sessionCount;
    pSessionEnumerator->GetCount(&sessionCount);

    bool audioPlaying = false;

    for (int i = 0; i < sessionCount; ++i) {
        IAudioSessionControl* pSessionControl = nullptr;
        pSessionEnumerator->GetSession(i, &pSessionControl);

        IAudioSessionControl2* pSessionControl2 = nullptr;
        pSessionControl->QueryInterface(__uuidof(IAudioSessionControl2), (void**)&pSessionControl2);
        pSessionControl->Release();

        AudioSessionState state;
        pSessionControl2->GetState(&state);
        pSessionControl2->Release();

        if (state == AudioSessionStateActive) {
            audioPlaying = true;
            break;
        }
    }

    pSessionEnumerator->Release();
    CoUninitialize();

    return audioPlaying;
}
