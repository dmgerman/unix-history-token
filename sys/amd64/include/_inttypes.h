begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Klaus Klein.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	From: $NetBSD: int_fmtio.h,v 1.2 2001/04/26 16:25:21 kleink Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INTTYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INTTYPES_H_
end_define

begin_comment
comment|/*  * Macros for format specifiers.  */
end_comment

begin_comment
comment|/* fprintf(3) macros for signed integers. */
end_comment

begin_define
define|#
directive|define
name|PRId8
value|"d"
end_define

begin_comment
comment|/* int8_t */
end_comment

begin_define
define|#
directive|define
name|PRId16
value|"d"
end_define

begin_comment
comment|/* int16_t */
end_comment

begin_define
define|#
directive|define
name|PRId32
value|"d"
end_define

begin_comment
comment|/* int32_t */
end_comment

begin_define
define|#
directive|define
name|PRId64
value|"lld"
end_define

begin_comment
comment|/* int64_t */
end_comment

begin_define
define|#
directive|define
name|PRIdLEAST8
value|"d"
end_define

begin_comment
comment|/* int_least8_t */
end_comment

begin_define
define|#
directive|define
name|PRIdLEAST16
value|"d"
end_define

begin_comment
comment|/* int_least16_t */
end_comment

begin_define
define|#
directive|define
name|PRIdLEAST32
value|"d"
end_define

begin_comment
comment|/* int_least32_t */
end_comment

begin_define
define|#
directive|define
name|PRIdLEAST64
value|"lld"
end_define

begin_comment
comment|/* int_least64_t */
end_comment

begin_define
define|#
directive|define
name|PRIdFAST8
value|"d"
end_define

begin_comment
comment|/* int_fast8_t */
end_comment

begin_define
define|#
directive|define
name|PRIdFAST16
value|"d"
end_define

begin_comment
comment|/* int_fast16_t */
end_comment

begin_define
define|#
directive|define
name|PRIdFAST32
value|"d"
end_define

begin_comment
comment|/* int_fast32_t */
end_comment

begin_define
define|#
directive|define
name|PRIdFAST64
value|"lld"
end_define

begin_comment
comment|/* int_fast64_t */
end_comment

begin_define
define|#
directive|define
name|PRIdMAX
value|"lld"
end_define

begin_comment
comment|/* intmax_t */
end_comment

begin_define
define|#
directive|define
name|PRIdPTR
value|"d"
end_define

begin_comment
comment|/* intptr_t */
end_comment

begin_define
define|#
directive|define
name|PRIi8
value|"i"
end_define

begin_comment
comment|/* int8_t */
end_comment

begin_define
define|#
directive|define
name|PRIi16
value|"i"
end_define

begin_comment
comment|/* int16_t */
end_comment

begin_define
define|#
directive|define
name|PRIi32
value|"i"
end_define

begin_comment
comment|/* int32_t */
end_comment

begin_define
define|#
directive|define
name|PRIi64
value|"lli"
end_define

begin_comment
comment|/* int64_t */
end_comment

begin_define
define|#
directive|define
name|PRIiLEAST8
value|"i"
end_define

begin_comment
comment|/* int_least8_t  */
end_comment

begin_define
define|#
directive|define
name|PRIiLEAST16
value|"i"
end_define

begin_comment
comment|/* int_least16_t */
end_comment

begin_define
define|#
directive|define
name|PRIiLEAST32
value|"i"
end_define

begin_comment
comment|/* int_least32_t */
end_comment

begin_define
define|#
directive|define
name|PRIiLEAST64
value|"lli"
end_define

begin_comment
comment|/* int_least64_t */
end_comment

begin_define
define|#
directive|define
name|PRIiFAST8
value|"i"
end_define

begin_comment
comment|/* int_fast8_t */
end_comment

begin_define
define|#
directive|define
name|PRIiFAST16
value|"i"
end_define

begin_comment
comment|/* int_fast16_t */
end_comment

begin_define
define|#
directive|define
name|PRIiFAST32
value|"i"
end_define

begin_comment
comment|/* int_fast32_t */
end_comment

begin_define
define|#
directive|define
name|PRIiFAST64
value|"lli"
end_define

begin_comment
comment|/* int_fast64_t */
end_comment

begin_define
define|#
directive|define
name|PRIiMAX
value|"lli"
end_define

begin_comment
comment|/* intmax_t */
end_comment

begin_define
define|#
directive|define
name|PRIiPTR
value|"i"
end_define

begin_comment
comment|/* intptr_t */
end_comment

begin_comment
comment|/* fprintf(3) macros for unsigned integers. */
end_comment

begin_define
define|#
directive|define
name|PRIo8
value|"o"
end_define

begin_comment
comment|/* uint8_t */
end_comment

begin_define
define|#
directive|define
name|PRIo16
value|"o"
end_define

begin_comment
comment|/* uint16_t */
end_comment

begin_define
define|#
directive|define
name|PRIo32
value|"o"
end_define

begin_comment
comment|/* uint32_t */
end_comment

begin_define
define|#
directive|define
name|PRIo64
value|"llo"
end_define

begin_comment
comment|/* uint64_t */
end_comment

begin_define
define|#
directive|define
name|PRIoLEAST8
value|"o"
end_define

begin_comment
comment|/* uint_least8_t */
end_comment

begin_define
define|#
directive|define
name|PRIoLEAST16
value|"o"
end_define

begin_comment
comment|/* uint_least16_t */
end_comment

begin_define
define|#
directive|define
name|PRIoLEAST32
value|"o"
end_define

begin_comment
comment|/* uint_least32_t */
end_comment

begin_define
define|#
directive|define
name|PRIoLEAST64
value|"llo"
end_define

begin_comment
comment|/* uint_least64_t */
end_comment

begin_define
define|#
directive|define
name|PRIoFAST8
value|"o"
end_define

begin_comment
comment|/* uint_fast8_t */
end_comment

begin_define
define|#
directive|define
name|PRIoFAST16
value|"o"
end_define

begin_comment
comment|/* uint_fast16_t */
end_comment

begin_define
define|#
directive|define
name|PRIoFAST32
value|"o"
end_define

begin_comment
comment|/* uint_fast32_t */
end_comment

begin_define
define|#
directive|define
name|PRIoFAST64
value|"llo"
end_define

begin_comment
comment|/* uint_fast64_t */
end_comment

begin_define
define|#
directive|define
name|PRIoMAX
value|"llo"
end_define

begin_comment
comment|/* uintmax_t */
end_comment

begin_define
define|#
directive|define
name|PRIoPTR
value|"o"
end_define

begin_comment
comment|/* uintptr_t */
end_comment

begin_define
define|#
directive|define
name|PRIu8
value|"u"
end_define

begin_comment
comment|/* uint8_t */
end_comment

begin_define
define|#
directive|define
name|PRIu16
value|"u"
end_define

begin_comment
comment|/* uint16_t */
end_comment

begin_define
define|#
directive|define
name|PRIu32
value|"u"
end_define

begin_comment
comment|/* uint32_t */
end_comment

begin_define
define|#
directive|define
name|PRIu64
value|"llu"
end_define

begin_comment
comment|/* uint64_t */
end_comment

begin_define
define|#
directive|define
name|PRIuLEAST8
value|"u"
end_define

begin_comment
comment|/* uint_least8_t */
end_comment

begin_define
define|#
directive|define
name|PRIuLEAST16
value|"u"
end_define

begin_comment
comment|/* uint_least16_t */
end_comment

begin_define
define|#
directive|define
name|PRIuLEAST32
value|"u"
end_define

begin_comment
comment|/* uint_least32_t */
end_comment

begin_define
define|#
directive|define
name|PRIuLEAST64
value|"llu"
end_define

begin_comment
comment|/* uint_least64_t */
end_comment

begin_define
define|#
directive|define
name|PRIuFAST8
value|"u"
end_define

begin_comment
comment|/* uint_fast8_t */
end_comment

begin_define
define|#
directive|define
name|PRIuFAST16
value|"u"
end_define

begin_comment
comment|/* uint_fast16_t */
end_comment

begin_define
define|#
directive|define
name|PRIuFAST32
value|"u"
end_define

begin_comment
comment|/* uint_fast32_t */
end_comment

begin_define
define|#
directive|define
name|PRIuFAST64
value|"llu"
end_define

begin_comment
comment|/* uint_fast64_t */
end_comment

begin_define
define|#
directive|define
name|PRIuMAX
value|"llu"
end_define

begin_comment
comment|/* uintmax_t */
end_comment

begin_define
define|#
directive|define
name|PRIuPTR
value|"u"
end_define

begin_comment
comment|/* uintptr_t */
end_comment

begin_define
define|#
directive|define
name|PRIx8
value|"x"
end_define

begin_comment
comment|/* uint8_t */
end_comment

begin_define
define|#
directive|define
name|PRIx16
value|"x"
end_define

begin_comment
comment|/* uint16_t */
end_comment

begin_define
define|#
directive|define
name|PRIx32
value|"x"
end_define

begin_comment
comment|/* uint32_t */
end_comment

begin_define
define|#
directive|define
name|PRIx64
value|"llx"
end_define

begin_comment
comment|/* uint64_t */
end_comment

begin_define
define|#
directive|define
name|PRIxLEAST8
value|"x"
end_define

begin_comment
comment|/* uint_least8_t */
end_comment

begin_define
define|#
directive|define
name|PRIxLEAST16
value|"x"
end_define

begin_comment
comment|/* uint_least16_t */
end_comment

begin_define
define|#
directive|define
name|PRIxLEAST32
value|"x"
end_define

begin_comment
comment|/* uint_least32_t */
end_comment

begin_define
define|#
directive|define
name|PRIxLEAST64
value|"llx"
end_define

begin_comment
comment|/* uint_least64_t */
end_comment

begin_define
define|#
directive|define
name|PRIxFAST8
value|"x"
end_define

begin_comment
comment|/* uint_fast8_t */
end_comment

begin_define
define|#
directive|define
name|PRIxFAST16
value|"x"
end_define

begin_comment
comment|/* uint_fast16_t */
end_comment

begin_define
define|#
directive|define
name|PRIxFAST32
value|"x"
end_define

begin_comment
comment|/* uint_fast32_t */
end_comment

begin_define
define|#
directive|define
name|PRIxFAST64
value|"llx"
end_define

begin_comment
comment|/* uint_fast64_t */
end_comment

begin_define
define|#
directive|define
name|PRIxMAX
value|"llx"
end_define

begin_comment
comment|/* uintmax_t */
end_comment

begin_define
define|#
directive|define
name|PRIxPTR
value|"x"
end_define

begin_comment
comment|/* uintptr_t */
end_comment

begin_define
define|#
directive|define
name|PRIX8
value|"X"
end_define

begin_comment
comment|/* uint8_t */
end_comment

begin_define
define|#
directive|define
name|PRIX16
value|"X"
end_define

begin_comment
comment|/* uint16_t */
end_comment

begin_define
define|#
directive|define
name|PRIX32
value|"X"
end_define

begin_comment
comment|/* uint32_t */
end_comment

begin_define
define|#
directive|define
name|PRIX64
value|"llX"
end_define

begin_comment
comment|/* uint64_t */
end_comment

begin_define
define|#
directive|define
name|PRIXLEAST8
value|"X"
end_define

begin_comment
comment|/* uint_least8_t */
end_comment

begin_define
define|#
directive|define
name|PRIXLEAST16
value|"X"
end_define

begin_comment
comment|/* uint_least16_t */
end_comment

begin_define
define|#
directive|define
name|PRIXLEAST32
value|"X"
end_define

begin_comment
comment|/* uint_least32_t */
end_comment

begin_define
define|#
directive|define
name|PRIXLEAST64
value|"llX"
end_define

begin_comment
comment|/* uint_least64_t */
end_comment

begin_define
define|#
directive|define
name|PRIXFAST8
value|"X"
end_define

begin_comment
comment|/* uint_fast8_t */
end_comment

begin_define
define|#
directive|define
name|PRIXFAST16
value|"X"
end_define

begin_comment
comment|/* uint_fast16_t */
end_comment

begin_define
define|#
directive|define
name|PRIXFAST32
value|"X"
end_define

begin_comment
comment|/* uint_fast32_t */
end_comment

begin_define
define|#
directive|define
name|PRIXFAST64
value|"llX"
end_define

begin_comment
comment|/* uint_fast64_t */
end_comment

begin_define
define|#
directive|define
name|PRIXMAX
value|"llX"
end_define

begin_comment
comment|/* uintmax_t */
end_comment

begin_define
define|#
directive|define
name|PRIXPTR
value|"X"
end_define

begin_comment
comment|/* uintptr_t */
end_comment

begin_comment
comment|/* fscanf(3) macros for signed integers. */
end_comment

begin_define
define|#
directive|define
name|SCNd8
value|"hhd"
end_define

begin_comment
comment|/* int8_t */
end_comment

begin_define
define|#
directive|define
name|SCNd16
value|"hd"
end_define

begin_comment
comment|/* int16_t */
end_comment

begin_define
define|#
directive|define
name|SCNd32
value|"d"
end_define

begin_comment
comment|/* int32_t */
end_comment

begin_define
define|#
directive|define
name|SCNd64
value|"lld"
end_define

begin_comment
comment|/* int64_t */
end_comment

begin_define
define|#
directive|define
name|SCNdLEAST8
value|"hhd"
end_define

begin_comment
comment|/* int_least8_t */
end_comment

begin_define
define|#
directive|define
name|SCNdLEAST16
value|"hd"
end_define

begin_comment
comment|/* int_least16_t */
end_comment

begin_define
define|#
directive|define
name|SCNdLEAST32
value|"d"
end_define

begin_comment
comment|/* int_least32_t */
end_comment

begin_define
define|#
directive|define
name|SCNdLEAST64
value|"lld"
end_define

begin_comment
comment|/* int_least64_t */
end_comment

begin_define
define|#
directive|define
name|SCNdFAST8
value|"d"
end_define

begin_comment
comment|/* int_fast8_t */
end_comment

begin_define
define|#
directive|define
name|SCNdFAST16
value|"d"
end_define

begin_comment
comment|/* int_fast16_t */
end_comment

begin_define
define|#
directive|define
name|SCNdFAST32
value|"d"
end_define

begin_comment
comment|/* int_fast32_t */
end_comment

begin_define
define|#
directive|define
name|SCNdFAST64
value|"lld"
end_define

begin_comment
comment|/* int_fast64_t */
end_comment

begin_define
define|#
directive|define
name|SCNdMAX
value|"lld"
end_define

begin_comment
comment|/* intmax_t */
end_comment

begin_define
define|#
directive|define
name|SCNdPTR
value|"d"
end_define

begin_comment
comment|/* intptr_t */
end_comment

begin_define
define|#
directive|define
name|SCNi8
value|"hhi"
end_define

begin_comment
comment|/* int8_t */
end_comment

begin_define
define|#
directive|define
name|SCNi16
value|"hi"
end_define

begin_comment
comment|/* int16_t */
end_comment

begin_define
define|#
directive|define
name|SCNi32
value|"i"
end_define

begin_comment
comment|/* int32_t */
end_comment

begin_define
define|#
directive|define
name|SCNi64
value|"lli"
end_define

begin_comment
comment|/* int64_t */
end_comment

begin_define
define|#
directive|define
name|SCNiLEAST8
value|"hhi"
end_define

begin_comment
comment|/* int_least8_t */
end_comment

begin_define
define|#
directive|define
name|SCNiLEAST16
value|"hi"
end_define

begin_comment
comment|/* int_least16_t */
end_comment

begin_define
define|#
directive|define
name|SCNiLEAST32
value|"i"
end_define

begin_comment
comment|/* int_least32_t */
end_comment

begin_define
define|#
directive|define
name|SCNiLEAST64
value|"lli"
end_define

begin_comment
comment|/* int_least64_t */
end_comment

begin_define
define|#
directive|define
name|SCNiFAST8
value|"i"
end_define

begin_comment
comment|/* int_fast8_t */
end_comment

begin_define
define|#
directive|define
name|SCNiFAST16
value|"i"
end_define

begin_comment
comment|/* int_fast16_t */
end_comment

begin_define
define|#
directive|define
name|SCNiFAST32
value|"i"
end_define

begin_comment
comment|/* int_fast32_t */
end_comment

begin_define
define|#
directive|define
name|SCNiFAST64
value|"lli"
end_define

begin_comment
comment|/* int_fast64_t */
end_comment

begin_define
define|#
directive|define
name|SCNiMAX
value|"lli"
end_define

begin_comment
comment|/* intmax_t */
end_comment

begin_define
define|#
directive|define
name|SCNiPTR
value|"i"
end_define

begin_comment
comment|/* intptr_t */
end_comment

begin_comment
comment|/* fscanf(3) macros for unsigned integers. */
end_comment

begin_define
define|#
directive|define
name|SCNo8
value|"hho"
end_define

begin_comment
comment|/* uint8_t */
end_comment

begin_define
define|#
directive|define
name|SCNo16
value|"ho"
end_define

begin_comment
comment|/* uint16_t */
end_comment

begin_define
define|#
directive|define
name|SCNo32
value|"o"
end_define

begin_comment
comment|/* uint32_t */
end_comment

begin_define
define|#
directive|define
name|SCNo64
value|"llo"
end_define

begin_comment
comment|/* uint64_t */
end_comment

begin_define
define|#
directive|define
name|SCNoLEAST8
value|"hho"
end_define

begin_comment
comment|/* uint_least8_t */
end_comment

begin_define
define|#
directive|define
name|SCNoLEAST16
value|"ho"
end_define

begin_comment
comment|/* uint_least16_t */
end_comment

begin_define
define|#
directive|define
name|SCNoLEAST32
value|"o"
end_define

begin_comment
comment|/* uint_least32_t */
end_comment

begin_define
define|#
directive|define
name|SCNoLEAST64
value|"llo"
end_define

begin_comment
comment|/* uint_least64_t */
end_comment

begin_define
define|#
directive|define
name|SCNoFAST8
value|"o"
end_define

begin_comment
comment|/* uint_fast8_t */
end_comment

begin_define
define|#
directive|define
name|SCNoFAST16
value|"o"
end_define

begin_comment
comment|/* uint_fast16_t */
end_comment

begin_define
define|#
directive|define
name|SCNoFAST32
value|"o"
end_define

begin_comment
comment|/* uint_fast32_t */
end_comment

begin_define
define|#
directive|define
name|SCNoFAST64
value|"llo"
end_define

begin_comment
comment|/* uint_fast64_t */
end_comment

begin_define
define|#
directive|define
name|SCNoMAX
value|"llo"
end_define

begin_comment
comment|/* uintmax_t */
end_comment

begin_define
define|#
directive|define
name|SCNoPTR
value|"o"
end_define

begin_comment
comment|/* uintptr_t */
end_comment

begin_define
define|#
directive|define
name|SCNu8
value|"hhu"
end_define

begin_comment
comment|/* uint8_t */
end_comment

begin_define
define|#
directive|define
name|SCNu16
value|"hu"
end_define

begin_comment
comment|/* uint16_t */
end_comment

begin_define
define|#
directive|define
name|SCNu32
value|"u"
end_define

begin_comment
comment|/* uint32_t */
end_comment

begin_define
define|#
directive|define
name|SCNu64
value|"llu"
end_define

begin_comment
comment|/* uint64_t */
end_comment

begin_define
define|#
directive|define
name|SCNuLEAST8
value|"hhu"
end_define

begin_comment
comment|/* uint_least8_t */
end_comment

begin_define
define|#
directive|define
name|SCNuLEAST16
value|"hu"
end_define

begin_comment
comment|/* uint_least16_t */
end_comment

begin_define
define|#
directive|define
name|SCNuLEAST32
value|"u"
end_define

begin_comment
comment|/* uint_least32_t */
end_comment

begin_define
define|#
directive|define
name|SCNuLEAST64
value|"llu"
end_define

begin_comment
comment|/* uint_least64_t */
end_comment

begin_define
define|#
directive|define
name|SCNuFAST8
value|"u"
end_define

begin_comment
comment|/* uint_fast8_t */
end_comment

begin_define
define|#
directive|define
name|SCNuFAST16
value|"u"
end_define

begin_comment
comment|/* uint_fast16_t */
end_comment

begin_define
define|#
directive|define
name|SCNuFAST32
value|"u"
end_define

begin_comment
comment|/* uint_fast32_t */
end_comment

begin_define
define|#
directive|define
name|SCNuFAST64
value|"llu"
end_define

begin_comment
comment|/* uint_fast64_t */
end_comment

begin_define
define|#
directive|define
name|SCNuMAX
value|"llu"
end_define

begin_comment
comment|/* uintmax_t */
end_comment

begin_define
define|#
directive|define
name|SCNuPTR
value|"u"
end_define

begin_comment
comment|/* uintptr_t */
end_comment

begin_define
define|#
directive|define
name|SCNx8
value|"hhx"
end_define

begin_comment
comment|/* uint8_t */
end_comment

begin_define
define|#
directive|define
name|SCNx16
value|"hx"
end_define

begin_comment
comment|/* uint16_t */
end_comment

begin_define
define|#
directive|define
name|SCNx32
value|"x"
end_define

begin_comment
comment|/* uint32_t */
end_comment

begin_define
define|#
directive|define
name|SCNx64
value|"llx"
end_define

begin_comment
comment|/* uint64_t */
end_comment

begin_define
define|#
directive|define
name|SCNxLEAST8
value|"hhx"
end_define

begin_comment
comment|/* uint_least8_t */
end_comment

begin_define
define|#
directive|define
name|SCNxLEAST16
value|"hx"
end_define

begin_comment
comment|/* uint_least16_t */
end_comment

begin_define
define|#
directive|define
name|SCNxLEAST32
value|"x"
end_define

begin_comment
comment|/* uint_least32_t */
end_comment

begin_define
define|#
directive|define
name|SCNxLEAST64
value|"llx"
end_define

begin_comment
comment|/* uint_least64_t */
end_comment

begin_define
define|#
directive|define
name|SCNxFAST8
value|"x"
end_define

begin_comment
comment|/* uint_fast8_t */
end_comment

begin_define
define|#
directive|define
name|SCNxFAST16
value|"x"
end_define

begin_comment
comment|/* uint_fast16_t */
end_comment

begin_define
define|#
directive|define
name|SCNxFAST32
value|"x"
end_define

begin_comment
comment|/* uint_fast32_t */
end_comment

begin_define
define|#
directive|define
name|SCNxFAST64
value|"llx"
end_define

begin_comment
comment|/* uint_fast64_t */
end_comment

begin_define
define|#
directive|define
name|SCNxMAX
value|"llx"
end_define

begin_comment
comment|/* uintmax_t */
end_comment

begin_define
define|#
directive|define
name|SCNxPTR
value|"x"
end_define

begin_comment
comment|/* uintptr_t */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_INTTYPES_H_ */
end_comment

end_unit

