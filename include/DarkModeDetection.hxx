#if !defined(DARK_MODE_DETECTION_HXX)
#define DARK_MODE_DETECTION_HXX
#if defined(WIN32)
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.Foundation.h>

using winrt::Windows::Foundation::IInspectable;
using winrt::Windows::UI::ViewManagement::UISettings;

class DarkModeDetection {
private:
  bool m_isDarkMode;
  UISettings m_uiSet;
  void printCurrentDarkModeStatus();
  void onThemeChange(UISettings const&, IInspectable const&);

public:
  DarkModeDetection();
};

#endif // WIN32
#endif // DARK_MODE_DETECTION_HXX
