#include "DarkModeDetection.hxx"
#include <QEventLoop>
#include <iostream>

int main(int argc, char** argv) {
  DarkModeDetection darkModeDetection;
  darkModeDetection.connect(&darkModeDetection, &DarkModeDetection::darkModeStatusChanged, [](bool isDarkMode){
    std::cout << "New Dark Mode Status: " << (isDarkMode ? "Enabled" : "Disabled") << "!\n";
  });
  while(true) ;
  return 0;
}
