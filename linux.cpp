module;
#include <time.h>
#include <unistd.h>

module sitime;

uint64_t sitime::current_timestamp() {
  timepoint tp{};
  clock_gettime(CLOCK_REALTIME, &tp);
  return tp.tv_sec * 1000 + tp.tv_nsec / 1000000;
}

void sleep(unsigned secs) { ::sleep(secs); }
void sleep_ms(unsigned ms) { ::usleep(ms * 1000); }
