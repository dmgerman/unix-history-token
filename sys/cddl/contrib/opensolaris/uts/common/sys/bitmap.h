begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
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
name|_SYS_BITMAP_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BITMAP_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<sys/feature_tests.h>
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_ASM_INLINES
argument_list|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64
argument_list|)
operator|)
include|#
directive|include
file|<asm/bitmap.h>
endif|#
directive|endif
comment|/*  * Operations on bitmaps of arbitrary size  * A bitmap is a vector of 1 or more ulong_t's.  * The user of the package is responsible for range checks and keeping  * track of sizes.  */
ifdef|#
directive|ifdef
name|_LP64
define|#
directive|define
name|BT_ULSHIFT
value|6
comment|/* log base 2 of BT_NBIPUL, to extract word index */
define|#
directive|define
name|BT_ULSHIFT32
value|5
comment|/* log base 2 of BT_NBIPUL, to extract word index */
else|#
directive|else
define|#
directive|define
name|BT_ULSHIFT
value|5
comment|/* log base 2 of BT_NBIPUL, to extract word index */
endif|#
directive|endif
define|#
directive|define
name|BT_NBIPUL
value|(1<< BT_ULSHIFT)
comment|/* n bits per ulong_t */
define|#
directive|define
name|BT_ULMASK
value|(BT_NBIPUL - 1)
comment|/* to extract bit index */
ifdef|#
directive|ifdef
name|_LP64
define|#
directive|define
name|BT_NBIPUL32
value|(1<< BT_ULSHIFT32)
comment|/* n bits per ulong_t */
define|#
directive|define
name|BT_ULMASK32
value|(BT_NBIPUL32 - 1)
comment|/* to extract bit index */
define|#
directive|define
name|BT_ULMAXMASK
value|0xffffffffffffffff
comment|/* used by bt_getlowbit */
else|#
directive|else
define|#
directive|define
name|BT_ULMAXMASK
value|0xffffffff
endif|#
directive|endif
comment|/*  * bitmap is a ulong_t *, bitindex an index_t  *  * The macros BT_WIM and BT_BIW internal; there is no need  * for users of this package to use them.  */
comment|/*  * word in map  */
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
comment|/*  * bit in word  */
define|#
directive|define
name|BT_BIW
parameter_list|(
name|bitindex
parameter_list|)
define|\
value|(1UL<< ((bitindex)& BT_ULMASK))
ifdef|#
directive|ifdef
name|_LP64
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
define|#
directive|define
name|BT_BIW32
parameter_list|(
name|bitindex
parameter_list|)
define|\
value|(1UL<< ((bitindex)& BT_ULMASK32))
endif|#
directive|endif
comment|/*  * These are public macros  *  * BT_BITOUL == n bits to n ulong_t's  */
define|#
directive|define
name|BT_BITOUL
parameter_list|(
name|nbits
parameter_list|)
define|\
value|(((nbits) + BT_NBIPUL - 1l) / BT_NBIPUL)
define|#
directive|define
name|BT_SIZEOFMAP
parameter_list|(
name|nbits
parameter_list|)
define|\
value|(BT_BITOUL(nbits) * sizeof (ulong_t))
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
ifdef|#
directive|ifdef
name|_LP64
define|#
directive|define
name|BT_BITOUL32
parameter_list|(
name|nbits
parameter_list|)
define|\
value|(((nbits) + BT_NBIPUL32 - 1l) / BT_NBIPUL32)
define|#
directive|define
name|BT_SIZEOFMAP32
parameter_list|(
name|nbits
parameter_list|)
define|\
value|(BT_BITOUL32(nbits) * sizeof (uint_t))
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
endif|#
directive|endif
comment|/* _LP64 */
comment|/*  * BIT_ONLYONESET is a private macro not designed for bitmaps of  * arbitrary size.  u must be an unsigned integer/long.  It returns  * true if one and only one bit is set in u.  */
define|#
directive|define
name|BIT_ONLYONESET
parameter_list|(
name|u
parameter_list|)
define|\
value|((((u) == 0) ? 0 : ((u)& ((u) - 1)) == 0))
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_ASM
argument_list|)
include|#
directive|include
file|<sys/atomic.h>
comment|/*  * return next available bit index from map with specified number of bits  */
specifier|extern
name|index_t
name|bt_availbit
parameter_list|(
name|ulong_t
modifier|*
name|bitmap
parameter_list|,
name|size_t
name|nbits
parameter_list|)
function_decl|;
comment|/*  * find the highest order bit that is on, and is within or below  * the word specified by wx  */
specifier|extern
name|int
name|bt_gethighbit
parameter_list|(
name|ulong_t
modifier|*
name|mapp
parameter_list|,
name|int
name|wx
parameter_list|)
function_decl|;
specifier|extern
name|int
name|bt_range
parameter_list|(
name|ulong_t
modifier|*
name|bitmap
parameter_list|,
name|size_t
modifier|*
name|pos1
parameter_list|,
name|size_t
modifier|*
name|pos2
parameter_list|,
name|size_t
name|end_pos
parameter_list|)
function_decl|;
comment|/*  * Find highest and lowest one bit set.  *	Returns bit number + 1 of bit that is set, otherwise returns 0.  * Low order bit is 0, high order bit is 31.  */
specifier|extern
name|int
name|highbit
parameter_list|(
name|ulong_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|lowbit
parameter_list|(
name|ulong_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|bt_getlowbit
parameter_list|(
name|ulong_t
modifier|*
name|bitmap
parameter_list|,
name|size_t
name|start
parameter_list|,
name|size_t
name|stop
parameter_list|)
function_decl|;
specifier|extern
name|void
name|bt_copy
parameter_list|(
name|ulong_t
modifier|*
parameter_list|,
name|ulong_t
modifier|*
parameter_list|,
name|ulong_t
parameter_list|)
function_decl|;
comment|/*  * find the parity  */
specifier|extern
name|int
name|odd_parity
parameter_list|(
name|ulong_t
parameter_list|)
function_decl|;
comment|/*  * Atomically set/clear bits  * Atomic exclusive operations will set "result" to "-1"  * if the bit is already set/cleared. "result" will be set  * to 0 otherwise.  */
define|#
directive|define
name|BT_ATOMIC_SET
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|{ atomic_or_long(&(BT_WIM(bitmap, bitindex)), BT_BIW(bitindex)); }
define|#
directive|define
name|BT_ATOMIC_CLEAR
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|)
define|\
value|{ atomic_and_long(&(BT_WIM(bitmap, bitindex)), ~BT_BIW(bitindex)); }
define|#
directive|define
name|BT_ATOMIC_SET_EXCL
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|,
name|result
parameter_list|)
define|\
value|{ result = atomic_set_long_excl(&(BT_WIM(bitmap, bitindex)),	\ 	    (bitindex) % BT_NBIPUL); }
define|#
directive|define
name|BT_ATOMIC_CLEAR_EXCL
parameter_list|(
name|bitmap
parameter_list|,
name|bitindex
parameter_list|,
name|result
parameter_list|)
define|\
value|{ result = atomic_clear_long_excl(&(BT_WIM(bitmap, bitindex)),	\ 	    (bitindex) % BT_NBIPUL); }
comment|/*  * Extracts bits between index h (high, inclusive) and l (low, exclusive) from  * u, which must be an unsigned integer.  */
define|#
directive|define
name|BITX
parameter_list|(
name|u
parameter_list|,
name|h
parameter_list|,
name|l
parameter_list|)
value|(((u)>> (l))& ((1LU<< ((h) - (l) + 1LU)) - 1LU))
endif|#
directive|endif
comment|/* _KERNEL&& !_ASM */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_BITMAP_H */
end_comment

end_unit

