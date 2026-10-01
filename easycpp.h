#ifndef EASYCPP_H
#define EASYCPP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
  char *data;
  size_t length;
  size_t capacity;
} string;

#ifdef __cplusplus
extern "C" {
#endif

string string_new(const char *text);
void string_free(string *s);
void string_set(string *s, const char *text);
void string_append(string *s, const char *text);

void cout_int(int x);
void cout_longlong(long long x);
void cout_float(float x);
void cout_double(double x);
void cout_char(char x);
void cout_string(string s);
void cout_bool(bool x);

#ifdef __cplusplus
}
#endif

#define cout(expr)                                                             \
  _Generic((expr),                                                             \
      int: cout_int,                                                           \
      long long: cout_longlong,                                                \
      float: cout_float,                                                       \
      double: cout_double,                                                     \
      char: cout_char,                                                         \
      string: cout_string,                                                     \
      bool: cout_bool)(expr)

#endif