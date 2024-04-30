module;
#include <time.h>
#include <unistd.h>

module sitime;

namespace sitime {
struct timepoint : timespec {};

void tp_deleter::operator()(timepoint *p) { delete p; }

stopwatch::ptr stopwatch::current_timestamp() noexcept {
  auto tp = new timepoint{};
  clock_gettime(CLOCK_REALTIME, tp);
  return stopwatch::ptr{tp};
}

int stopwatch::millis() const noexcept {
  timepoint tp{};
  clock_gettime(CLOCK_REALTIME, &tp);

  auto s = tp.tv_sec - (*m_start)->tv_sec;
  auto ns = tp.tv_nsec - (*m_start)->tv_nsec;
  return s * 1000 + ns / 1000000;
}

void sleep(unsigned secs) noexcept { ::sleep(secs); }
void sleep_ms(unsigned ms) noexcept { ::usleep(ms * 1000); }
} // namespace sitime
