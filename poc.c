#ifdef _WIN32
#define WIN32_MEAN_AND_LEAN
#include <windows.h>
#else
#include <sys/time.h>
#endif

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int main() {
  struct timeval tv = {0};

#ifdef _WIN32
  SYSTEMTIME st;
  GetSystemTime(&st);

  // Contains a 64-bit value representing the number of 100-nanosecond
  // intervals since January 1, 1601 (UTC).
  FILETIME ft;
  assert(SystemTimeToFileTime(&st, &ft));

  ULARGE_INTEGER i;
  i.u.LowPart  = ft.dwLowDateTime;
  i.u.HighPart = ft.dwHighDateTime;

  tv.tv_sec = i.QuadPart / (100 * 1000 * 1000);
  tv.tv_usec = (i.QuadPart / 100) % (1000 * 1000);
#else
  gettimeofday(&tv, NULL);
#endif

  printf("Timestamp = %ld %ld\n", tv.tv_sec, tv.tv_usec);
}
