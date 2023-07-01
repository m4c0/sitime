#include "../ecow/ecow.hpp"
#include "../hai/build.hpp"

auto sitime() {
  using namespace ecow;

  auto m = unit::create<per_feat<mod>>("sitime");
  m->add_wsdep("hai", hai());

  m->for_feature(android_ndk).add_impl("android");
  m->for_feature(objective_c).add_impl("apple");
  m->for_feature(windows_api).add_impl("windows");
  
  return m;
}
