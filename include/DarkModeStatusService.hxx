#if !defined(DARK_MODE_STATUS_SERVICE_HXX)
#define DARK_MODE_STATUS_SERVICE_HXX
#if defined(WIN32)
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.Foundation.h>
#include <QObject>

using winrt::Windows::Foundation::IInspectable;
using winrt::Windows::UI::ViewManagement::UISettings;

class DarkModeStatusService : public QObject {
  Q_OBJECT

signals:
  void darkModeStatusChanged(bool isDarkMode);

private:
  bool m_lastDarkModeStatus;
  UISettings m_uiSet;
  bool isDarkMode();
  void onThemeChange(UISettings const&, IInspectable const&);

public:
  DarkModeStatusService(QObject *parent = nullptr);
};

#endif // WIN32
#endif // DARK_MODE_STATUS_SERVICE_HXX
