#ifdef LECO_TARGET_WASM
#pragma leco app
#endif

import silog;
import sitime;
import vaselin;

static sitime::stopwatch w{};

int main() {
  silog::log(silog::info, "Before sleeping: %d", w.millis());
  vaselin::set_timeout([] { silog::log(silog::info, "After sleeping: %d", w.millis()); },
              1000);
}
