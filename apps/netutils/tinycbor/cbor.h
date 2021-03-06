/****************************************************************************
 * netutils/tinycbor/cbor.h
 *
 * Copyright (C) 2016 Haltian Ltd. All rights reserved.
 *
 *  Authors: Jussi Kivilinna <jussi.kivilinna@haltian.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 ****************************************************************************/

#ifndef __NUTTX_TINYCBOR_CBOR_H__
#define __NUTTX_TINYCBOR_CBOR_H__

#include <nuttx/config.h>

#define PRIX32  "X"
#define PRIx32  "x"
#define PRIx8   PRIx32

#define PRIu64  "llu"
#define PRIu32  "u"
#define PRIu8   PRIu32

#include <apps/netutils/cbor.h>

#endif /*__NUTTX_TINYCBOR_CBOR_H__*/
