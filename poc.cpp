import silog;
import sitime;

extern "C" unsigned sleep(unsigned);

int main() {
  sitime::stopwatch w{};
  silog::log(silog::info, "Before sleeping: %d", w.millis());
  sleep(1);
  silog::log(silog::info, "After sleeping: %d", w.millis());
}
