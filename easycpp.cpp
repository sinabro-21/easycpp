#include "easycpp.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

static bool ensure_capacity(string *s, size_t required) {
  if (s == nullptr)
    return false;

  if (s->capacity >= required)
    return true;

  size_t new_capacity = s->capacity ? s->capacity : 16;

  while (new_capacity < required) {
    new_capacity *= 2;
  }

  char *new_data = static_cast<char *>(std::realloc(s->data, new_capacity));

  if (new_data == nullptr)
    return false;

  s->data = new_data;
  s->capacity = new_capacity;

  return true;
}

// ====================
// string
// ====================

string string_new(const char *text) {
  string s{};

  if (text == nullptr)
    text = "";

  size_t length = std::strlen(text);

  s.capacity = 16;

  while (s.capacity < length + 1) {
    s.capacity *= 2;
  }

  s.data = static_cast<char *>(std::malloc(s.capacity));

  if (s.data == nullptr) {
    s.length = 0;
    s.capacity = 0;
    return s;
  }

  std::memcpy(s.data, text, length + 1);

  s.length = length;

  return s;
}

void string_free(string *s) {
  if (s == nullptr)
    return;

  std::free(s->data);

  s->data = nullptr;
  s->length = 0;
  s->capacity = 0;
}

void string_set(string *s, const char *text) {
  if (s == nullptr)
    return;

  if (text == nullptr)
    text = "";

  std::string temp(text);

  size_t required = temp.size() + 1;

  if (!ensure_capacity(s, required))
    return;

  std::memcpy(s->data, temp.c_str(), required);

  s->length = temp.size();
}

void string_append(string *s, const char *text) {
  if (s == nullptr || text == nullptr)
    return;

  std::string temp(text);

  size_t new_length = s->length + temp.size();

  if (!ensure_capacity(s, new_length + 1))
    return;

  std::memcpy(s->data + s->length, temp.c_str(), temp.size() + 1);

  s->length = new_length;
}

// ====================
// cout
// ====================

void cout_int(int x) { std::cout << x; }

void cout_longlong(long long x) { std::cout << x; }

void cout_float(float x) { std::cout << x; }

void cout_double(double x) { std::cout << x; }

void cout_char(char x) { std::cout << x; }

void cout_string(string s) {
  if (s.data != nullptr)
    std::cout << s.data;
}

void cout_bool(bool x) { std::cout << (x ? "true" : "false"); }