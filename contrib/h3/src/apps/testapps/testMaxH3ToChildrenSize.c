/*
 * Copyright 2017-2018 Uber Technologies, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h>

#include "h3Index.h"
#include "test.h"

SUITE(maxH3ToChildrenSize) {
    GeoCoord sf = {0.659966917655, 2 * 3.14159 - 2.1364398519396};

    TEST(maxH3ToChildrenSize) {
        H3Index parent = H3_EXPORT(geoToH3)(&sf, 7);

        t_assert(H3_EXPORT(maxH3ToChildrenSize)(parent, 3) == 0,
                 "got expected size for coarser res");
        t_assert(H3_EXPORT(maxH3ToChildrenSize)(parent, 7) == 1,
                 "got expected size for same res");
        t_assert(H3_EXPORT(maxH3ToChildrenSize)(parent, 8) == 7,
                 "got expected size for child res");
        t_assert(H3_EXPORT(maxH3ToChildrenSize)(parent, 9) == 7 * 7,
                 "got expected size for grandchild res");
    }

    TEST(maxH3ToChildrenSize_largest) {
        // write out the types explicitly, to make sure errors don't go
        // undetected to to type casting.

        H3Index h = 0x806dfffffffffff;       // res 0 *hexagon*
        uint64_t expected = 4747561509943L;  // 7^15
        uint64_t out = H3_EXPORT(maxH3ToChildrenSize)(h, 15);

        t_assert(out == expected,
                 "got right size for hex children 15 levels below");
    }
}
