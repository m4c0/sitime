export module sitime;
import hai;

#if LECO_TARGET_APPLE
#pragma leco add_impl apple
#pragma leco add_framework CoreFoundation
#elif LECO_TARGET_ANDROID
#pragma leco add_impl android
#elif LECO_TARGET_WINDOWS
#pragma leco add_impl windows
#elif LECO_TARGET_LINUX
#pragma leco add_impl linux
#elif LECO_TARGET_WASM
#pragma leco add_impl wasm
#endif

namespace sitime {
struct timepoint;
struct timer_ptr;

struct tp_deleter {
  void operator()(timepoint *);
  void operator()(timer_ptr *);
};

export class stopwatch {
  using ptr = hai::value_holder<timepoint *, tp_deleter>;

  ptr m_start;

  [[nodiscard]] ptr current_timestamp();

public:
  stopwatch() : m_start{current_timestamp()} {}

  [[nodiscard]] int millis() const;
};
export class timer {
  using ptr = hai::value_holder<timer_ptr *, tp_deleter>;

  hai::fn<void> m_fn;
  ptr m_ptr;

  [[nodiscard]] ptr create_ptr(unsigned ms);

public:
  timer(unsigned ms, hai::fn<void> fn) : m_fn { fn }, m_ptr { create_ptr(ms) } {}
};

export void sleep(unsigned secs);
export void sleep_ms(unsigned ms);
} // namespace sitime
