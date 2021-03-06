/*******************************************************************************
The MIT License (MIT)

Copyright (c) 2015 Dmitry "Dima" Korolev <dmitry.korolev@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

#ifndef BRICKS_TEMPLATE_IS_UNIQUE_PTR_H
#define BRICKS_TEMPLATE_IS_UNIQUE_PTR_H

#include <memory>

#include "decay.h"

namespace current {

template <typename T>
struct is_unique_ptr_impl {
  enum { value = false };
  using underlying_type = T;
  static T& extract(T& x) { return x; }
  static const T& extract(const T& x) { return x; }
  static T& extract(T* x) { return *x; }
  static const T& extract(const T* x) { return *x; }
  static T* pointer(T& x) { return &x; }
  static const T* pointer(const T& x) { return x; }
  static T* pointer(T* x) { return x; }
  static const T* pointer(const T* x) { return x; }
};

template <typename T, typename D>
struct is_unique_ptr_impl<std::unique_ptr<T, D>> {
  enum { value = true };
  using underlying_type = T;
  static T& extract(std::unique_ptr<T, D>& x) { return *x.get(); }
  static const T& extract(const std::unique_ptr<T, D>& x) { return *x.get(); }
  static T* pointer(std::unique_ptr<T, D>& x) { return x.get(); }
  static const T* pointer(const std::unique_ptr<T, D>& x) { return x.get(); }
};

template <typename T>
using is_unique_ptr = is_unique_ptr_impl<decay_t<T>>;

}  // namespace current

#endif  // BRICKS_TEMPLATE_IS_UNIQUE_PTR_H
