#include "build.hpp"

int main(int argc, char **argv) {
  using namespace ecow;

  auto all = unit::create<seq>("all");
  all->add_ref(sitime());
  all->add_unit<>("poc");
  return run_main(all, argc, argv);
}
