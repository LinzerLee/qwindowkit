#ifndef QWINDOWKIT_WINDOWS_H
#define QWINDOWKIT_WINDOWS_H

#include <QtCore/qt_windows.h>
#include <QtCore/qglobal.h>

#include <QWKCore/qwkglobal.h>

#ifndef GET_X_LPARAM
#  define GET_X_LPARAM(lp) (static_cast<int>(static_cast<short>(LOWORD(lp))))
#endif

#ifndef GET_Y_LPARAM
#  define GET_Y_LPARAM(lp) (static_cast<int>(static_cast<short>(HIWORD(lp))))
#endif

#ifndef IsMinimized
#  define IsMinimized(hwnd) (::IsIconic(hwnd))
#endif

#ifndef IsMaximized
#  define IsMaximized(hwnd) (::IsZoomed(hwnd))
#endif

#ifndef RECT_WIDTH
#  define RECT_WIDTH(rect) ((rect).right - (rect).left)
#endif

#ifndef RECT_HEIGHT
#  define RECT_HEIGHT(rect) ((rect).bottom - (rect).top)
#endif

// Maybe undocumented Windows messages
#ifndef WM_UAHDESTROYWINDOW
#  define WM_UAHDESTROYWINDOW (0x0090)
#endif

#ifndef WM_UNREGISTER_WINDOW_SERVICES
#  define WM_UNREGISTER_WINDOW_SERVICES (0x0272)
#endif

#ifndef WM_NCUAHDRAWCAPTION
#  define WM_NCUAHDRAWCAPTION (0x00AE)
#endif

#ifndef WM_NCUAHDRAWFRAME
#  define WM_NCUAHDRAWFRAME (0x00AF)
#endif

namespace QWK {

    QWK_CORE_EXPORT RTL_OSVERSIONINFOW GetRealOSVersion();

    inline bool IsWindows1122H2OrGreater_Real() {
        RTL_OSVERSIONINFOW rovi = GetRealOSVersion();
        return (rovi.dwMajorVersion > 10) ||
               (rovi.dwMajorVersion == 10 && rovi.dwMinorVersion >= 0 &&
                rovi.dwBuildNumber >= 22621);
    }

    inline bool IsWindows11OrGreater_Real() {
        RTL_OSVERSIONINFOW rovi = GetRealOSVersion();
        return (rovi.dwMajorVersion > 10) ||
               (rovi.dwMajorVersion == 10 && rovi.dwMinorVersion >= 0 &&
                rovi.dwBuildNumber >= 22000);
    }

    inline bool IsWindows101903OrGreater_Real() {
        RTL_OSVERSIONINFOW rovi = GetRealOSVersion();
        return (rovi.dwMajorVersion > 10) ||
               (rovi.dwMajorVersion == 10 && rovi.dwMinorVersion >= 0 &&
                rovi.dwBuildNumber >= 18362);
    }

    inline bool IsWindows101809OrGreater_Real() {
        RTL_OSVERSIONINFOW rovi = GetRealOSVersion();
        return (rovi.dwMajorVersion > 10) ||
               (rovi.dwMajorVersion == 10 && rovi.dwMinorVersion >= 0 &&
                rovi.dwBuildNumber >= 17763);
    }

    inline bool IsWindows10OrGreater_Real() {
        RTL_OSVERSIONINFOW rovi = GetRealOSVersion();
        return (rovi.dwMajorVersion > 10) ||
               (rovi.dwMajorVersion == 10 && rovi.dwMinorVersion >= 0);
    }

    inline bool IsWindows8Point1OrGreater_Real() {
        RTL_OSVERSIONINFOW rovi = GetRealOSVersion();
        return (rovi.dwMajorVersion > 6) || (rovi.dwMajorVersion == 6 && rovi.dwMinorVersion >= 3);
    }

    inline bool IsWindows8OrGreater_Real() {
        RTL_OSVERSIONINFOW rovi = GetRealOSVersion();
        return (rovi.dwMajorVersion > 6) || (rovi.dwMajorVersion == 6 && rovi.dwMinorVersion >= 2);
    }

    inline bool IsWindows10_Real() {
        return IsWindows10OrGreater_Real() && !IsWindows11OrGreater_Real();
    }

}

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
Q_DECLARE_METATYPE(QMargins)
#endif

#endif // QWINDOWKIT_WINDOWS_H
