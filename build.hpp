#include "../ecow/ecow.hpp"
#include "../hai/build.hpp"

auto sitime() {
  using namespace ecow;

  auto m = unit::create<mod>("sitime");
  m->add_wsdep("hai", hai());
  return m;
}
