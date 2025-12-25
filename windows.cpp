module;
#include <windows.h>

module sitime;

[[nodiscard]] uint64_t sitime::current_timestamp() {
  // GetSystemTimeAsFileTime returns time in 100-nanosecond intervals since
  // 1601. Sounds like some senior engineer went very creative. Maybe I can find
  // a reason for the 100ns precision, but 1601? Why? Who needs that in
  // FILETIME?
  //
  // The conversion to Unix timestamps matters because Microsoft's timestamps
  // can trigger all sort of integer overflows. Mainly when using a
  // zero-initialised "sitime::stopwatch".
  //
  // Using Unix epoch will still overflow in 2039, but it will be consistent
  // between platforms.

  constexpr const auto ft_scale = 10'000;  // 100-ns to millis
  constexpr const auto ft_displ = 11644473600000; // Delta timestamp between MS and Unix epoch

  FILETIME ft{};
  GetSystemTimeAsFileTime(&ft);

  // Following rekarks here:
  // https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-filetime
  ULARGE_INTEGER uli{};
  uli.u.LowPart = ft.dwLowDateTime;
  uli.u.HighPart = ft.dwHighDateTime;
  return uli.QuadPart / ft_scale - ft_displ;
}

void sitime::sleep(unsigned secs) { SleepEx(secs * 1000, FALSE); }
void sitime::sleep_ms(unsigned ms) { SleepEx(ms, FALSE); }
