#if !defined(DARK_MODE_DETECTION_HXX)
#define DARK_MODE_DETECTION_HXX
#if defined(WIN32)
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.Foundation.h>
#include <QObject>

using winrt::Windows::Foundation::IInspectable;
using winrt::Windows::UI::ViewManagement::UISettings;

class DarkModeDetection : public QObject {
  Q_OBJECT

signals:
  void darkModeStatusChanged(bool isDarkMode);

private:
  bool m_lastDarkModeStatus;
  UISettings m_uiSet;
  bool isDarkMode();
  void onThemeChange(UISettings const&, IInspectable const&);

public:
  DarkModeDetection();
};

#endif // WIN32
#endif // DARK_MODE_DETECTION_HXX
