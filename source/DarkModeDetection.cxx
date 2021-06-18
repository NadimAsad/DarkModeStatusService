#include "DarkModeDetection.hxx"
#include <iostream>

using winrt::Windows::UI::Colors;
using winrt::Windows::UI::ViewManagement::UIColorType;

void DarkModeDetection::onThemeChange(UISettings const&, IInspectable const&) {
  auto newStatus = this->m_uiSet.GetColorValue(UIColorType::Background) == Colors::Black() && this->m_uiSet.GetColorValue(UIColorType::Foreground) == Colors::White();

  if (this->m_isDarkMode != newStatus) {
    this->m_isDarkMode = newStatus;
    this->printCurrentDarkModeStatus();
  }
}

void DarkModeDetection::printCurrentDarkModeStatus() {
  std::cout << "Dark Mode: ";

  if (this->m_isDarkMode)
    std::cout << "Enabled!\n";
  else
    std::cout << "Disabled!\n";
}

DarkModeDetection::DarkModeDetection() {
  // Get current GetColorValue for Background & Foreground and check for dark mode
  this->m_isDarkMode = this->m_uiSet.GetColorValue(UIColorType::Background) == Colors::Black() && this->m_uiSet.GetColorValue(UIColorType::Foreground) == Colors::White();
  // Register event handler for UISettings::ColorValuesChanged
  this->m_uiSet.ColorValuesChanged({this, &DarkModeDetection::onThemeChange});

  this->printCurrentDarkModeStatus();
}
