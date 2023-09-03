export module sitime;
import hai;

#if __APPLE__
#pragma ecow add_impl apple
#elif __ANDROID__
#pragma ecow add_impl android
#elif _WIN32
#pragma ecow add_impl windows
#else
#pragma ecow add_impl wasm
#endif

namespace sitime {
struct timepoint;

struct tp_deleter {
  void operator()(timepoint *);
};

export class stopwatch {
  using ptr = hai::value_holder<timepoint *, tp_deleter>;

  ptr m_start;

  [[nodiscard]] ptr current_timestamp() noexcept;

public:
  stopwatch() : m_start{current_timestamp()} {}

  [[nodiscard]] int millis() const noexcept;
};

export void sleep(unsigned secs) noexcept;
} // namespace sitime
