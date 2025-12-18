module;
#include <CoreFoundation/CoreFoundation.h>

module sitime;

uint64_t sitime::current_timestamp() {
  constexpr const auto scale = 1000.0f; // seconds to millis
  return static_cast<uint64_t>(scale * CFAbsoluteTimeGetCurrent());
}

void sitime::sleep(unsigned secs) { ::sleep(secs); }
void sitime::sleep_ms(unsigned ms) { ::usleep(ms * 1000); }
