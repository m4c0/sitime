#ifdef _WIN32
#define WIN32_MEAN_AND_LEAN
#include <windows.h>
#endif

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int main() {
  uint64_t ts = 0;

#ifdef _WIN32
  SYSTEMTIME st;
  GetSystemTime(&st);

  FILETIME ft;
  assert(SystemTimeToFileTime(&st, &ft));

  ULARGE_INTEGER i;
  i.u.LowPart  = ft.dwLowDateTime;
  i.u.HighPart = ft.dwHighDateTime;

  ts = i.QuadPart;
#endif

  printf("Timestamp = %lld\n", ts);
}
