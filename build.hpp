#include "../ecow/ecow.hpp"

auto sitime() {
  using namespace ecow;
  return unit::create<box>("sitime");
}
