#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <windows.h>
//#include <mmsystem.h>
#include <locale>
#include <codecvt>
//#include "Keys.h"   // Include the Keys header file
//#include "Pedals.h" // Include the Pedals header file
//#include "Piano.h"  // Include the Piano header file

//#pragma comment(lib, "winmm.lib")

//void playAudio(const std::string& audioPath) {
//    std::cout << "Attempting to play audio file: " << audioPath << std::endl;
//
//
//    // Check if the file exists
//    std::ifstream file(audioPath);
//    if (!file) {
//        std::cerr << "Error: Audio file not found at " << audioPath << std::endl;
//        return;
//    }
//
//    // Convert std::string to std::wstring
//    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//    std::wstring wideAudioPath = converter.from_bytes(audioPath);
//
//    // Attempt to play the audio file
//    if (!PlaySound(wideAudioPath.c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
//        std::cerr << "Error: Could not play audio file. Error code: " << GetLastError() << std::endl;
//    }
//    else {
//        std::cout << "Audio file is playing." << std::endl;
//    }
//}

int main() {
    //Keys pianoKeys(88, "Ivory");
    //Pedals sustainPedal("Sustain");
    //Pedals softPedal("Soft");

    //std::vector<Pedals> pianoPedals = { sustainPedal, softPedal };

    //Piano myPiano("Yamaha", 88, pianoKeys, pianoPedals);

    //myPiano.play();

    //pianoPedals[0].pressPedal();
    //pianoPedals[1].releasePedal();

    // Remove the second call to play() if not needed
    // myPiano.play();

    // Set up the audio path
    //std::string audioPath = "C:\\Users\\danie\\OneDrive\\TJC\\2024 Fall Semester\\COSC\\Lab 3d - Piano\\Chopin Ettude Op 25. No. 9.wav";


    system("ChopinEttudeOp25No9.wav");
    // Check if the audio file exists before attempting to play it
    //std::ifstream file(audioPath);
    //if (!file) {
    //    std::cerr << "Error: Audio file not found at " << audioPath << std::endl;
    //    return 1;
    //}

    //playAudio(audioPath);

    //// Keep the program running to allow the audio to play
    //std::cout << "Press Enter to exit..." << std::endl;
    //std::cin.get();

    return 0;
}
