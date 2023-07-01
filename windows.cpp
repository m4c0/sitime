module;
#include <windows.h>

module sitime;

using namespace sitime;

namespace sitime {
struct timepoint {
  ULONGLONG val;
};
} // namespace sitime

void tp_deleter::operator()(timepoint *p) { delete p; }

[[nodiscard]] ULONGLONG current_timestamp() noexcept {
  FILETIME ft{};
  GetSystemTimeAsFileTime(&ft);

  // Following rekarks here:
  // https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-filetime
  ULARGE_INTEGER uli{};
  uli.u.LowPart = ft.dwLowDateTime;
  uli.u.HighPart = ft.dwHighDateTime;
  return uli.QuadPart;
}

stopwatch::ptr stopwatch::current_timestamp() noexcept {
  return stopwatch::ptr{new timepoint{::current_timestamp()}};
}

int stopwatch::millis() const noexcept {
  auto s = (*m_start)->val;
  auto e = ::current_timestamp();
  return static_cast<int>((e - s) / 10);
}
