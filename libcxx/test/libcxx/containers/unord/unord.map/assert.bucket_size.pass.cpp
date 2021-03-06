//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <unordered_map>

// template <class Key, class T, class Hash = hash<Key>, class Pred = equal_to<Key>,
//           class Alloc = allocator<pair<const Key, T>>>
// class unordered_map

// size_type bucket_size(size_type n) const

// UNSUPPORTED: c++03, windows
// UNSUPPORTED: use_system_cxx_lib && target={{.+}}-apple-macosx{{10.9|10.10|10.11|10.12|10.13|10.14|10.15|11|12}}
// ADDITIONAL_COMPILE_FLAGS: -D_LIBCPP_ENABLE_ASSERTIONS=1

#include <unordered_map>
#include <string>

#include "check_assertion.h"

int main(int, char**) {
    typedef std::unordered_map<int, std::string> C;
    C c;
    TEST_LIBCPP_ASSERT_FAILURE(c.bucket_size(3), "unordered container::bucket_size(n) called with n >= bucket_count()");

    return 0;
}
