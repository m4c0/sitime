module;
#include <windows.h>

module sitime;

[[nodiscard]] uint64_t sitime::current_timestamp() {
  // GetSystemTimeAsFileTime returns time in 100-nanosecond intervals since
  // 1601. Sounds like some senior engineer went very creative. Maybe I can find
  // a reason for the 100ns precision, but 1601? Why? Who needs that in
  // FILETIME? Doesn't matter here, but still... Why???
  constexpr const auto ft_scale = 10 * 1000;

  FILETIME ft{};
  GetSystemTimeAsFileTime(&ft);

  // Following rekarks here:
  // https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-filetime
  ULARGE_INTEGER uli{};
  uli.u.LowPart = ft.dwLowDateTime;
  uli.u.HighPart = ft.dwHighDateTime;
  return uli.QuadPart / ft_scale;
}

void sitime::sleep(unsigned secs) { SleepEx(secs * 1000, FALSE); }
void sitime::sleep_ms(unsigned ms) { SleepEx(ms, FALSE); }
