export module sitime;
import hai;

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
} // namespace sitime