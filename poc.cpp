import silog;
import sitime;

int main() {
  sitime::stopwatch w{};
  silog::log(silog::info, "Before sleeping: %d", w.millis());
  sitime::sleep(1);
  silog::log(silog::info, "After sleeping: %d", w.millis());
  if (w.millis() < 990 || w.millis() > 1100)
    throw "Time scale is not correct";
}
