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
  constexpr const auto scale = 1000.0f; // seconds to millis
  auto s = scale * (*m_start)->time;
  auto e = scale * CFAbsoluteTimeGetCurrent();
  return static_cast<int>(e - s);
}
