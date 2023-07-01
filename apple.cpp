module;
#include <CoreFoundation/CoreFoundation.h>

module sitime;

using namespace sitime;

namespace sitime {
struct timepoint {
  CFAbsoluteTime time;
};
}; // namespace sitime

void tp_deleter::operator()(timepoint *p) { delete p; }

stopwatch::ptr stopwatch::current_timestamp() noexcept {
  return stopwatch::ptr {new timepoint{CFAbsoluteTimeGetCurrent()}};
}

int stopwatch::millis() const noexcept {
  auto s = 100.0 * (*m_start)->time;
  auto e = 100.0 * CFAbsoluteTimeGetCurrent();
  return static_cast<int>(e - s);
}
