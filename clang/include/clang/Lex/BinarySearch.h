//===- BinarySearchOptions.h ------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LEX_BINARYSEARCH_H
#define LLVM_CLANG_LEX_BINARYSEARCH_H

#include <string>
#include <vector>

namespace clang {

class BinarySearchOptions {
public:
  std::vector<std::string> UserEntries;
};

} // namespace clang

#endif // LLVM_CLANG_LEX_BINARY_SEARCH_H
