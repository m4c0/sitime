export module sitime;

namespace sitime {
export [[nodiscard]] long current_timestamp() noexcept;

export class stopwatch {
  long m_start;

public:
  stopwatch() : m_start{current_timestamp()} {}

  [[nodiscard]] int millis() const noexcept {
    // TODO: check if we somehow overflow here
    return static_cast<int>(current_timestamp() - m_start);
  }
};
} // namespace sitime
