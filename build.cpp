#include "../silog/build.hpp"
#include "build.hpp"

int main(int argc, char **argv) {
  using namespace ecow;

  auto all = unit::create<app>("poc");
  all->add_wsdep("silog", silog());
  all->add_ref(sitime());
  all->add_unit<>("poc");
  return run_main(all, argc, argv);
}
