#include "../silog/build.hpp"
#include "build.hpp"

int main(int argc, char **argv) {
  using namespace ecow;

  auto poc = unit::create<app>("poc");
  poc->add_wsdep("silog", silog());
  poc->add_ref(sitime());
  poc->add_unit<>("poc");

  auto test = unit::create<tool>("test");
  test->add_ref(poc);

  auto all = unit::create<seq>("all");
  all->add_ref(test);
  all->add_unit<sys>(test->executable().string());

  return run_main(test, argc, argv);
}
