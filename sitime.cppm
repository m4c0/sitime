export module sitime;

namespace sitime {
[[nodiscard]] unsigned long current_timestamp() noexcept;

class stopwatch {
  unsigned long m_start;

public:
  stopwatch() : m_start{current_timestamp()} {}

  [[nodiscard]] unsigned long millis() const noexcept {
    return current_timestamp() - m_start;
  }
};
} // namespace sitime
