#include "DarkModeDetection.hxx"

using winrt::Windows::UI::Colors;
using winrt::Windows::UI::ViewManagement::UIColorType;

void DarkModeDetection::onThemeChange(UISettings const&, IInspectable const&) {
  auto newStatus = this->isDarkMode();

  if (this->m_lastDarkModeStatus != newStatus) {
    this->m_lastDarkModeStatus = newStatus;
    emit this->darkModeStatusChanged(newStatus);
  }
}

bool DarkModeDetection::isDarkMode() {
  return this->m_uiSet.GetColorValue(UIColorType::Background) == Colors::Black() && this->m_uiSet.GetColorValue(UIColorType::Foreground) == Colors::White();
}

DarkModeDetection::DarkModeDetection() {
  this->m_lastDarkModeStatus = this->isDarkMode();
  this->m_uiSet.ColorValuesChanged({this, &DarkModeDetection::onThemeChange});
}
