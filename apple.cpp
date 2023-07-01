module sitime;

using namespace sitime;

void tp_deleter::operator()(timepoint *) {}

stopwatch::ptr stopwatch::current_timestamp() noexcept {
  return {};
}

int stopwatch::millis() const noexcept {
  return 0;
}
