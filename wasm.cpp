module sitime;
import traits;
import vaselin;

using namespace sitime;
using namespace traits::ints;

namespace sitime {
  struct timepoint { uint64_t val; };
}

void tp_deleter::operator()(timepoint *p) { delete p; }

static uint64_t current_timestamp() {
  return vaselin::date_now();
}

stopwatch::ptr stopwatch::current_timestamp() {
  return stopwatch::ptr{new timepoint{::current_timestamp()}};
}

int stopwatch::millis() const {
  auto s = (*m_start)->val;
  auto e = ::current_timestamp();
  return static_cast<int>(e - s);
}
