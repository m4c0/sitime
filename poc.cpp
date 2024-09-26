#pragma leco tool
import silog;
import sitime;

int main() {
  sitime::stopwatch w{};
  silog::log(silog::info, "Before sleeping: %d", w.millis());
  sitime::sleep(1);
  silog::log(silog::info, "After sleeping: %d", w.millis());
  // Giving out some space, because this actually when up to 1190 in a
  // particular test execution.
  if (w.millis() < 990 || w.millis() > 1300)
    throw "Time scale is not correct";
}
