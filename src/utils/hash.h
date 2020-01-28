// https://blog.csdn.net/yozidream/article/details/22789147

#ifndef CIRCLE_H
#define CIRCLE_H
#include <cstdint>
#include <cstddef>

static constexpr uint64_t prime = 0x100000001B3ull;
static constexpr uint64_t basis = 0xCBF29CE484222325ull;
static uint64_t hash_(char const* str)
{
  uint64_t ret{basis};
  while(*str){
      ret ^= *str;
      ret *= prime;
      str++;
  }
  return ret;
}
static constexpr uint64_t hash_compile_time(char const* str, uint64_t last_value = basis)
{
  return *str ? hash_compile_time(str+1, (*str ^ last_value) * prime) : last_value;
}
// 重载
static constexpr unsigned long long operator "" _hash(char const* p, size_t)
{
	return hash_compile_time(p);
}

#endif