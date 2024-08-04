#ifdef LECO_TARGET_WASM
#pragma leco app
#endif

import silog;
import sitime;

extern "C"
    __attribute__((import_module("leco"), import_name("set_timeout"))) void
    set_timeout(void (*)(), int);

static sitime::stopwatch w{};

struct init { init(); } i;
init::init() {
  silog::log(silog::info, "Before sleeping: %d", w.millis());
  set_timeout([] { silog::log(silog::info, "After sleeping: %d", w.millis()); },
              1000);
}
