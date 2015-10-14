begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IDI,NTNU  *  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://opensource.org/licenses/CDDL-1.0.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * Copyright (C) 2009, 2010, Jorn Amundsen<jorn.amundsen@ntnu.no>  *  * C header file to determine compile machine byte order. Take care when cross  * compiling.  *  * $Id: byteorder.h 517 2013-02-17 20:34:39Z joern $  */
end_comment

begin_comment
comment|/*  * Portions copyright (c) 2013, Saso Kiselkov, All rights reserved  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRYPTO_EDONR_BYTEORDER_H
end_ifndef

begin_define
define|#
directive|define
name|_CRYPTO_EDONR_BYTEORDER_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux
argument_list|)
end_if

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BYTE_ORDER
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
operator|)
end_if

begin_define
define|#
directive|define
name|MACHINE_IS_BIG_ENDIAN
end_define

begin_elif
elif|#
directive|elif
operator|(
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
operator|)
end_elif

begin_define
define|#
directive|define
name|MACHINE_IS_LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
end_elif

begin_if
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
operator|)
end_if

begin_define
define|#
directive|define
name|MACHINE_IS_BIG_ENDIAN
end_define

begin_elif
elif|#
directive|elif
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
end_elif

begin_define
define|#
directive|define
name|MACHINE_IS_LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BYTE_ORDER || BYTE_ORDER */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MACHINE_IS_BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MACHINE_IS_LITTLE_ENDIAN
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_BIG_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|_MIPSEB
argument_list|)
end_if

begin_define
define|#
directive|define
name|MACHINE_IS_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LITTLE_ENDIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|_MIPSEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|MACHINE_IS_LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MACHINE_IS_BIG_ENDIAN&& !MACHINE_IS_LITTLE_ENDIAN */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MACHINE_IS_BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MACHINE_IS_LITTLE_ENDIAN
argument_list|)
end_if

begin_error
error|#
directive|error
error|unknown machine byte sex
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BYTEORDER_INCLUDED
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MACHINE_IS_BIG_ENDIAN
argument_list|)
end_if

begin_comment
comment|/*  * Byte swapping macros for big endian architectures and compilers,  * add as appropriate for other architectures and/or compilers.  *  *     ld_swap64(src,dst) : uint64_t dst = *(src)  *     st_swap64(src,dst) : *(dst)       = uint64_t src  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__PPC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__64BIT__
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ARCH_PWR7
argument_list|)
end_if

begin_define
define|#
directive|define
name|aix_ld_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|__asm__("ldbrx %0,0,%1" : "=r"(d64) : "r"(s64))
end_define

begin_define
define|#
directive|define
name|aix_st_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|__asm__ volatile("stdbrx %1,0,%0" : : "r"(d64), "r"(s64))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|aix_ld_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|{									\ 	uint64_t *s4, h;						\ 									\ 	__asm__("addi %0,%3,4;lwbrx %1,0,%3;lwbrx %2,0,%0;rldimi %1,%2,32,0"\ 		: "+r"(s4), "=r"(d64), "=r"(h) : "b"(s64));		\ }
end_define

begin_define
define|#
directive|define
name|aix_st_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|{									\ 	uint64_t *s4, h;						\ 	h = (s64)>> 32;						\ 	__asm__ volatile("addi %0,%3,4;stwbrx %1,0,%3;stwbrx %2,0,%0"	\ 		: "+r"(s4) : "r"(s64), "r"(h), "b"(d64));		\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 64BIT&& PWR7 */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|aix_ld_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|{									\ 	uint32_t *s4, h, l;						\ 	__asm__("addi %0,%3,4;lwbrx %1,0,%3;lwbrx %2,0,%0"		\ 		: "+r"(s4), "=r"(l), "=r"(h) : "b"(s64));		\ 	d64 = ((uint64_t)h<<32) | l;					\ }
end_define

begin_define
define|#
directive|define
name|aix_st_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|{									\ 	uint32_t *s4, h, l;						\ 	l = (s64)& 0xfffffffful, h = (s64)>> 32;			\ 	__asm__ volatile("addi %0,%3,4;stwbrx %1,0,%3;stwbrx %2,0,%0"	\ 		: "+r"(s4) : "r"(l), "r"(h), "b"(d64));			\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __64BIT__ */
end_comment

begin_define
define|#
directive|define
name|aix_ld_swap32
parameter_list|(
name|s32
parameter_list|,
name|d32
parameter_list|)
define|\
value|__asm__("lwbrx %0,0,%1" : "=r"(d32) : "r"(s32))
end_define

begin_define
define|#
directive|define
name|aix_st_swap32
parameter_list|(
name|s32
parameter_list|,
name|d32
parameter_list|)
define|\
value|__asm__ volatile("stwbrx %1,0,%0" : : "r"(d32), "r"(s32))
end_define

begin_define
define|#
directive|define
name|ld_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|aix_ld_swap32(s, d)
end_define

begin_define
define|#
directive|define
name|st_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|aix_st_swap32(s, d)
end_define

begin_define
define|#
directive|define
name|ld_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|aix_ld_swap64(s, d)
end_define

begin_define
define|#
directive|define
name|st_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|aix_st_swap64(s, d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PPC__ || _ARCH_PPC */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparc
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sparcv8
argument_list|)
operator|&&
name|defined
argument_list|(
name|__sparcv9
argument_list|)
end_if

begin_define
define|#
directive|define
name|__arch64__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__SUNPRO_C
argument_list|)
operator|&&
name|__SUNPRO_C
operator|>
literal|0x590
operator|)
end_if

begin_comment
comment|/* need Sun Studio C 5.10 and above for GNU inline assembly */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arch64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|sparc_ld_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|__asm__("ldxa [%1]0x88,%0" : "=r"(d64) : "r"(s64))
end_define

begin_define
define|#
directive|define
name|sparc_st_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|__asm__ volatile("stxa %0,[%1]0x88" : : "r"(s64), "r"(d64))
end_define

begin_define
define|#
directive|define
name|st_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|sparc_st_swap64(s, d)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sparc_ld_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|{									\ 	uint32_t *s4, h, l;						\ 	__asm__("add %3,4,%0\n\tlda [%3]0x88,%1\n\tlda [%0]0x88,%2"	\ 		: "+r"(s4), "=r"(l), "=r"(h) : "r"(s64));		\ 	d64 = ((uint64_t)h<<32) | l;					\ }
end_define

begin_define
define|#
directive|define
name|sparc_st_swap64
parameter_list|(
name|s64
parameter_list|,
name|d64
parameter_list|)
define|\
value|{									\ 	uint32_t *s4, h, l;						\ 	l = (s64)& 0xfffffffful, h = (s64)>> 32;			\ 	__asm__ volatile("add %3,4,%0\n\tsta %1,[%3]0x88\n\tsta %2,[%0]0x88"\ 		: "+r"(s4) : "r"(l), "r"(h), "r"(d64));			\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc64 */
end_comment

begin_define
define|#
directive|define
name|sparc_ld_swap32
parameter_list|(
name|s32
parameter_list|,
name|d32
parameter_list|)
define|\
value|__asm__("lda [%1]0x88,%0" : "=r"(d32) : "r"(s32))
end_define

begin_define
define|#
directive|define
name|sparc_st_swap32
parameter_list|(
name|s32
parameter_list|,
name|d32
parameter_list|)
define|\
value|__asm__ volatile("sta %0,[%1]0x88" : : "r"(s32), "r"(d32))
end_define

begin_define
define|#
directive|define
name|ld_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|sparc_ld_swap32(s, d)
end_define

begin_define
define|#
directive|define
name|st_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|sparc_st_swap32(s, d)
end_define

begin_define
define|#
directive|define
name|ld_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|sparc_ld_swap64(s, d)
end_define

begin_define
define|#
directive|define
name|st_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|sparc_st_swap64(s, d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC || Sun Studio C> 5.9 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_comment
comment|/* GCC fallback */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|__GNUC__
operator|>=
literal|4
operator|)
operator|||
name|defined
argument_list|(
name|__PGIC__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|ld_swap32
argument_list|)
end_if

begin_define
define|#
directive|define
name|ld_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|(d = __builtin_bswap32(*(s)))
end_define

begin_define
define|#
directive|define
name|st_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|(*(d) = __builtin_bswap32(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC4/PGIC&& !swap32 */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|__GNUC__
operator|>=
literal|4
operator|)
operator|||
name|defined
argument_list|(
name|__PGIC__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|ld_swap64
argument_list|)
end_if

begin_define
define|#
directive|define
name|ld_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|(d = __builtin_bswap64(*(s)))
end_define

begin_define
define|#
directive|define
name|st_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|(*(d) = __builtin_bswap64(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC4/PGIC&& !swap64 */
end_comment

begin_comment
comment|/* generic fallback */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ld_swap32
argument_list|)
end_if

begin_define
define|#
directive|define
name|ld_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|(d = (*(s)>> 24) | (*(s)>> 8& 0xff00) |			\ 	(*(s)<< 8& 0xff0000) | (*(s)<< 24))
end_define

begin_define
define|#
directive|define
name|st_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|(*(d) = ((s)>> 24) | ((s)>> 8& 0xff00) |			\ 	((s)<< 8& 0xff0000) | ((s)<< 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ld_swap64
argument_list|)
end_if

begin_define
define|#
directive|define
name|ld_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|(d = (*(s)>> 56) | (*(s)>> 40& 0xff00) |			\ 	(*(s)>> 24& 0xff0000) | (*(s)>> 8& 0xff000000) |		\ 	(*(s)& 0xff000000)<< 8 | (*(s)& 0xff0000)<< 24 |		\ 	(*(s)& 0xff00)<< 40 | *(s)<< 56)
end_define

begin_define
define|#
directive|define
name|st_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
define|\
value|(*(d) = ((s)>> 56) | ((s)>> 40& 0xff00) |			\ 	((s)>> 24& 0xff0000) | ((s)>> 8& 0xff000000) |		\ 	((s)& 0xff000000)<< 8 | ((s)& 0xff0000)<< 24 |		\ 	((s)& 0xff00)<< 40 | (s)<< 56)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MACHINE_IS_BIG_ENDIAN */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MACHINE_IS_LITTLE_ENDIAN
argument_list|)
end_if

begin_comment
comment|/* replace swaps with simple assignments on little endian systems */
end_comment

begin_undef
undef|#
directive|undef
name|ld_swap32
end_undef

begin_undef
undef|#
directive|undef
name|st_swap32
end_undef

begin_define
define|#
directive|define
name|ld_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|(d = *(s))
end_define

begin_define
define|#
directive|define
name|st_swap32
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|(*(d) = s)
end_define

begin_undef
undef|#
directive|undef
name|ld_swap64
end_undef

begin_undef
undef|#
directive|undef
name|st_swap64
end_undef

begin_define
define|#
directive|define
name|ld_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|(d = *(s))
end_define

begin_define
define|#
directive|define
name|st_swap64
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|(*(d) = s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MACHINE_IS_LITTLE_ENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CRYPTO_EDONR_BYTEORDER_H */
end_comment

end_unit

