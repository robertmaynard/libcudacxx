//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <cuda/std/algorithm>

// template<LessThanComparable T>
//   pair<const T&, const T&>
//   minmax(const T& a, const T& b);

#include <cuda/std/algorithm>
#include <cuda/std/cassert>

#include "test_macros.h"

template <class T>
void
__host__ __device__ test(const T& a, const T& b, const T& x, const T& y)
{
    cuda::std::pair<const T&, const T&> p = cuda::std::minmax(a, b);
    assert(&p.first == &x);
    assert(&p.second == &y);
}

int main(int, char**)
{
    {
    int x = 0;
    int y = 0;
    test(x, y, x, y);
    test(y, x, y, x);
    }
    {
    int x = 0;
    int y = 1;
    test(x, y, x, y);
    test(y, x, x, y);
    }
    {
    int x = 1;
    int y = 0;
    test(x, y, y, x);
    test(y, x, y, x);
    }
#if TEST_STD_VER >= 14
    {
//  Note that you can't take a reference to a local var, since
//  its address is not a compile-time constant.
    constexpr static int x = 1;
    constexpr static int y = 0;
    constexpr auto p1 = cuda::std::minmax (x, y);
    static_assert(p1.first  == y, "");
    static_assert(p1.second == x, "");
    constexpr auto p2 = cuda::std::minmax (y, x);
    static_assert(p2.first  == y, "");
    static_assert(p2.second == x, "");
    }
#endif

    {
    __int128_t x = 0;
    __int128_t y = 0;
    test(x, y, x, y);
    test(y, x, y, x);
    }
    {
    __int128_t x = 0;
    __int128_t y = 1;
    test(x, y, x, y);
    test(y, x, x, y);
    }
    {
    __int128_t x = 1;
    __int128_t y = 0;
    test(x, y, y, x);
    test(y, x, y, x);
    }
#if TEST_STD_VER >= 14
    {
//  Note that you can't take a reference to a local var, since
//  its address is not a compile-time constant.
    constexpr static __int128_t x = 1;
    constexpr static __int128_t y = 0;
    constexpr auto p1 = cuda::std::minmax (x, y);
    static_assert(p1.first  == y, "");
    static_assert(p1.second == x, "");
    constexpr auto p2 = cuda::std::minmax (y, x);
    static_assert(p2.first  == y, "");
    static_assert(p2.second == x, "");
    }
#endif

    {
    __uint128_t x = 0;
    __uint128_t y = 0;
    test(x, y, x, y);
    test(y, x, y, x);
    }
    {
    __uint128_t x = 0;
    __uint128_t y = 1;
    test(x, y, x, y);
    test(y, x, x, y);
    }
    {
    __uint128_t x = 1;
    __uint128_t y = 0;
    test(x, y, y, x);
    test(y, x, y, x);
    }
#if TEST_STD_VER >= 14
    {
//  Note that you can't take a reference to a local var, since
//  its address is not a compile-time constant.
    constexpr static __uint128_t x = 1;
    constexpr static __uint128_t y = 0;
    constexpr auto p1 = cuda::std::minmax (x, y);
    static_assert(p1.first  == y, "");
    static_assert(p1.second == x, "");
    constexpr auto p2 = cuda::std::minmax (y, x);
    static_assert(p2.first  == y, "");
    static_assert(p2.second == x, "");
    }
#endif

  return 0;
}
