module sitime;

using namespace sitime;

void tp_deleter::operator()(timepoint *) {}

stopwatch::ptr stopwatch::current_timestamp() { return {}; }

int stopwatch::millis() const { return 0; }

void sitime::sleep(unsigned secs) {}
