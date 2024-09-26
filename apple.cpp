module;
#include <CoreFoundation/CoreFoundation.h>

module sitime;

using namespace sitime;

namespace sitime {
struct timepoint {
  CFAbsoluteTime time;
};
struct timer_ptr {
};
}; // namespace sitime

void tp_deleter::operator()(timepoint *p) { delete p; }
void tp_deleter::operator()(timer_ptr *p) { delete p; }

stopwatch::ptr stopwatch::current_timestamp() {
  return stopwatch::ptr{new timepoint{CFAbsoluteTimeGetCurrent()}};
}

int stopwatch::millis() const {
  constexpr const auto scale = 1000.0f; // seconds to millis
  auto s = scale * (*m_start)->time;
  auto e = scale * CFAbsoluteTimeGetCurrent();
  return static_cast<int>(e - s);
}

void sitime::sleep(unsigned secs) { ::sleep(secs); }
void sitime::sleep_ms(unsigned ms) { ::usleep(ms * 1000); }

timer::ptr timer::create_ptr(unsigned ms) {
  // Create timer
  // Add Timer
  // Setup notifications for enter bg
  return {};
}
