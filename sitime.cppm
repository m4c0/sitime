export module sitime;
import traits;

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

using namespace traits::ints;

namespace sitime {
  export [[nodiscard]] uint64_t current_timestamp();
  
  export class stopwatch {
    uint64_t m_start = current_timestamp();
  
  public:
    stopwatch() = default;
    consteval stopwatch(uint64_t v) : m_start { v } {}

    [[nodiscard]] int millis() const { return current_timestamp() - m_start; }
    [[nodiscard]] float secs() const { return millis() / 1000.0f; };
  };
  
  export void sleep(unsigned secs);
  export void sleep_ms(unsigned ms);
} // namespace sitime
