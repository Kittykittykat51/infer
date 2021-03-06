/*
 * Copyright (c) 2015 - present Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include <stdlib.h>

extern int add_all_ints(int x, int y, int z, ...) __attribute__((sentinel));

void valid_call(int* a, int* b, int* c) {
  // fine
  int x = add_all_ints(0, 0, 0, a, b, c, NULL);
}

void truncated_call(void) {
  int a = 0, b = 1, c = 2, d = 3;
  int* p = NULL;

  // warning: p is NULL so only first argument sent to add_all_ints
  int x = add_all_ints(0, 0, 0, &a, p, &b, &c, &d, NULL);
}
