module sitime;
import traits;

using namespace sitime;
using namespace traits::ints;

namespace sitime {
  struct timepoint { uint64_t val; };
}

void tp_deleter::operator()(timepoint *p) { delete p; }

extern "C" void clock_time_get(int, uint64_t, uint64_t * out) __attribute__((import_module("wasi_snapshot_preview1"), import_name("clock_time_get"))) ;

static uint64_t current_timestamp() {
  uint64_t x{};
  clock_time_get(0, 0, &x);
  return x;
}

stopwatch::ptr stopwatch::current_timestamp() {
  return stopwatch::ptr{new timepoint{::current_timestamp()}};
}

int stopwatch::millis() const {
  constexpr const auto ft_scale = 1000 * 1000;

  auto s = (*m_start)->val;
  auto e = ::current_timestamp();
  return static_cast<int>((e - s) / ft_scale);
}
