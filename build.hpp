#include "../ecow/ecow.hpp"

auto sitime() {
  using namespace ecow;

  auto m = unit::create<mod>("sitime");
  return m;
}
