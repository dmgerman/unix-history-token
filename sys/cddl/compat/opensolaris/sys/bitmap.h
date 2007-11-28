begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
end_comment

begin_comment
comment|/*	  All Rights Reserved  	*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_OPENSOLARIS_SYS_BITMAP_H
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_OPENSOLARIS_SYS_BITMAP_H
end_define

begin_include
include|#
directive|include
file|<sys/atomic.h>
end_include

begin_comment
comment|/*  * Operations on bitmaps of arbitrary size  * A bitmap is a vector of 1 or more ulong_t's.  * The user of the package is responsible for range checks and keeping  * track of sizes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_define
define|#
directive|define
name|BT_ULSHIFT
value|6
end_define

begin_comment
comment|/* log base 2 of BT_NBIPUL, to extract word index */
end_comment

begin_define
define|#
directive|define
name|BT_ULSHIFT32
value|5
end_define

begin_comment
comment|/* log base 2 of BT_NBIPUL, to extract word index */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BT_ULSHIFT
value|5
end_define

begin_comment
comment|/* log base 2 of BT_NBIPUL, to extract word index */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BT_NBIPUL
value|(1<< BT_ULSHIFT)
end_define

begin_comment
comment|/* n bits per ulong_t */
end_comment

begin_define
define|#
directive|define
name|BT_ULMASK
value|(BT_NBIPUL - 1)
end_define

begin_comment
comment|/* to extract bit index */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_define
define|#
directive|define
name|BT_NBIPUL32
value|(1<< BT_ULSHIFT32)
end_define

begin_comment
comment|/* n bits per ulong_t */
end_comment

begin_define
define|#
directive|define
name|BT_ULMASK32
value|(BT_NBIPUL32 - 1)
end_define

begin_comment
comment|/* to extract bit index */
end_comment

begin_define
define|#
directive|define
name|BT_ULMAXMASK
value|0xffffffffffffffff
end_define

begin_comment
comment|/* used by bt_getlowbit */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BT_ULMAXMASK
value|0xffffffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * bitmap is a ulong_t *, bitindex an index_t  *  * The macros BT_WIM and BT_BIW internal; there is no need  * for users of this package to use them.  */
end_comment

begin_comment
comment|/*  * word in map  */
end_comment

begin_define
define|#
directive|define
name|BT_WIM
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|((bitmap)[(bitindex)>> BT_ULSHIFT])
end_define

begin_comment
comment|/*  * bit in word  */
end_comment

begin_define
define|#
directive|define
name|BT_BIW
parameter_list|(
name|bitindex
parameter_list|)
define|\
value|(1UL<< ((bitindex)& BT_ULMASK))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_define
define|#
directive|define
name|BT_WIM32
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|((bitmap)[(bitindex)>> BT_ULSHIFT32])
end_define

begin_define
define|#
directive|define
name|BT_BIW32
parameter_list|(
name|bitindex
parameter_list|)
define|\
value|(1UL<< ((bitindex)& BT_ULMASK32))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These are public macros  *  * BT_BITOUL == n bits to n ulong_t's  */
end_comment

begin_define
define|#
directive|define
name|BT_BITOUL
parameter_list|(
name|nbits
parameter_list|)
define|\
value|(((nbits) + BT_NBIPUL - 1l) / BT_NBIPUL)
end_define

begin_define
define|#
directive|define
name|BT_SIZEOFMAP
parameter_list|(
name|nbits
parameter_list|)
define|\
value|(BT_BITOUL(nbits) * sizeof (ulong_t))
end_define

begin_define
define|#
directive|define
name|BT_TEST
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|((BT_WIM((bitmap), (bitindex))& BT_BIW(bitindex)) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|BT_SET
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|{ BT_WIM((bitmap), (bitindex)) |= BT_BIW(bitindex); }
end_define

begin_define
define|#
directive|define
name|BT_CLEAR
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|{ BT_WIM((bitmap), (bitindex))&= ~BT_BIW(bitindex); }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_define
define|#
directive|define
name|BT_BITOUL32
parameter_list|(
name|nbits
parameter_list|)
define|\
value|(((nbits) + BT_NBIPUL32 - 1l) / BT_NBIPUL32)
end_define

begin_define
define|#
directive|define
name|BT_SIZEOFMAP32
parameter_list|(
name|nbits
parameter_list|)
define|\
value|(BT_BITOUL32(nbits) * sizeof (uint_t))
end_define

begin_define
define|#
directive|define
name|BT_TEST32
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|((BT_WIM32((bitmap), (bitindex))& BT_BIW32(bitindex)) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|BT_SET32
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|{ BT_WIM32((bitmap), (bitindex)) |= BT_BIW32(bitindex); }
end_define

begin_define
define|#
directive|define
name|BT_CLEAR32
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|{ BT_WIM32((bitmap), (bitindex))&= ~BT_BIW32(bitindex); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LP64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPAT_OPENSOLARIS_SYS_BITMAP_H */
end_comment

end_unit

