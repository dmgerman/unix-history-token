begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: test_helper.h,v 1.7 2017/03/14 01:10:07 dtucker Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* Utility functions/framework for regress tests */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TEST_HELPER_H
end_ifndef

begin_define
define|#
directive|define
name|_TEST_HELPER_H
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDINT_H
end_ifdef

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_enum
enum|enum
name|test_predicate
block|{
name|TEST_EQ
block|,
name|TEST_NE
block|,
name|TEST_LT
block|,
name|TEST_LE
block|,
name|TEST_GT
block|,
name|TEST_GE
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|void
function_decl|(
name|test_onerror_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Supplied by test suite */
end_comment

begin_function_decl
name|void
name|tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|test_data_file
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_start
parameter_list|(
specifier|const
name|char
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_info
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_onerror_func
parameter_list|(
name|test_onerror_func_t
modifier|*
name|f
parameter_list|,
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_done
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|test_subtest_info
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ssl_err_check
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_bignum
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|aa1
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_string
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
specifier|const
name|char
modifier|*
name|aa1
parameter_list|,
specifier|const
name|char
modifier|*
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_mem
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
specifier|const
name|void
modifier|*
name|aa1
parameter_list|,
specifier|const
name|void
modifier|*
name|aa2
parameter_list|,
name|size_t
name|l
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_mem_filled
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|void
modifier|*
name|aa1
parameter_list|,
name|u_char
name|v
parameter_list|,
name|size_t
name|l
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_int
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|int
name|aa1
parameter_list|,
name|int
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_size_t
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|size_t
name|aa1
parameter_list|,
name|size_t
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_u_int
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|u_int
name|aa1
parameter_list|,
name|u_int
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_long
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|long
name|aa1
parameter_list|,
name|long
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_long_long
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|long
name|long
name|aa1
parameter_list|,
name|long
name|long
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_char
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|char
name|aa1
parameter_list|,
name|char
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_ptr
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
specifier|const
name|void
modifier|*
name|aa1
parameter_list|,
specifier|const
name|void
modifier|*
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_u8
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|u_int8_t
name|aa1
parameter_list|,
name|u_int8_t
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_u16
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|u_int16_t
name|aa1
parameter_list|,
name|u_int16_t
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_u32
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|u_int32_t
name|aa1
parameter_list|,
name|u_int32_t
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|assert_u64
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|a1
parameter_list|,
specifier|const
name|char
modifier|*
name|a2
parameter_list|,
name|u_int64_t
name|aa1
parameter_list|,
name|u_int64_t
name|aa2
parameter_list|,
name|enum
name|test_predicate
name|pred
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TEST_START
parameter_list|(
name|n
parameter_list|)
value|test_start(n)
end_define

begin_define
define|#
directive|define
name|TEST_DONE
parameter_list|()
value|test_done()
end_define

begin_define
define|#
directive|define
name|TEST_ONERROR
parameter_list|(
name|f
parameter_list|,
name|c
parameter_list|)
value|set_onerror_func(f, c)
end_define

begin_define
define|#
directive|define
name|SSL_ERR_CHECK
parameter_list|()
value|ssl_err_check(__FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ASSERT_BIGNUM_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_bignum(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_STRING_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_string(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_MEM_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|l
parameter_list|)
define|\
value|assert_mem(__FILE__, __LINE__, #a1, #a2, a1, a2, l, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_MEM_FILLED_EQ
parameter_list|(
name|a1
parameter_list|,
name|c
parameter_list|,
name|l
parameter_list|)
define|\
value|assert_mem_filled(__FILE__, __LINE__, #a1, a1, c, l, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_MEM_ZERO_EQ
parameter_list|(
name|a1
parameter_list|,
name|l
parameter_list|)
define|\
value|assert_mem_filled(__FILE__, __LINE__, #a1, a1, '\0', l, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_INT_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_SIZE_T_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_size_t(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_U_INT_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_LONG_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_CHAR_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_char(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_PTR_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_ptr(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_U8_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u8(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_U16_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u16(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_U32_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u32(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_U64_EQ
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u64(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_EQ)
end_define

begin_define
define|#
directive|define
name|ASSERT_BIGNUM_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_bignum(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_STRING_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_string(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_MEM_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|l
parameter_list|)
define|\
value|assert_mem(__FILE__, __LINE__, #a1, #a2, a1, a2, l, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_MEM_ZERO_NE
parameter_list|(
name|a1
parameter_list|,
name|l
parameter_list|)
define|\
value|assert_mem_filled(__FILE__, __LINE__, #a1, a1, '\0', l, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_INT_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_SIZE_T_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_size_t(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U_INT_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_LONG_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_CHAR_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_char(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_PTR_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_ptr(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U8_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u8(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U16_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u16(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U32_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u32(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U64_NE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u64(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_NE)
end_define

begin_define
define|#
directive|define
name|ASSERT_BIGNUM_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_bignum(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_STRING_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_string(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_MEM_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|l
parameter_list|)
define|\
value|assert_mem(__FILE__, __LINE__, #a1, #a2, a1, a2, l, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_INT_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_SIZE_T_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_size_t(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U_INT_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_LONG_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_CHAR_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_char(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_PTR_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_ptr(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U8_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u8(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U16_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u16(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U32_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u32(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U64_LT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u64(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LT)
end_define

begin_define
define|#
directive|define
name|ASSERT_BIGNUM_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_bignum(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_STRING_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_string(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_MEM_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|l
parameter_list|)
define|\
value|assert_mem(__FILE__, __LINE__, #a1, #a2, a1, a2, l, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_INT_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_SIZE_T_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_size_t(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U_INT_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_LONG_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_CHAR_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_char(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_PTR_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_ptr(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U8_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u8(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U16_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u16(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U32_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u32(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U64_LE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u64(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_LE)
end_define

begin_define
define|#
directive|define
name|ASSERT_BIGNUM_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_bignum(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_STRING_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_string(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_MEM_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|l
parameter_list|)
define|\
value|assert_mem(__FILE__, __LINE__, #a1, #a2, a1, a2, l, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_INT_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_SIZE_T_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_size_t(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U_INT_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_LONG_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_CHAR_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_char(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_PTR_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_ptr(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U8_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u8(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U16_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u16(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U32_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u32(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_U64_GT
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u64(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GT)
end_define

begin_define
define|#
directive|define
name|ASSERT_BIGNUM_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_bignum(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_STRING_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_string(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_MEM_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|l
parameter_list|)
define|\
value|assert_mem(__FILE__, __LINE__, #a1, #a2, a1, a2, l, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_INT_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_SIZE_T_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_size_t(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U_INT_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u_int(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_LONG_LONG_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_long_long(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_CHAR_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_char(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_PTR_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_ptr(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U8_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u8(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U16_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u16(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U32_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u32(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_define
define|#
directive|define
name|ASSERT_U64_GE
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
define|\
value|assert_u64(__FILE__, __LINE__, #a1, #a2, a1, a2, TEST_GE)
end_define

begin_comment
comment|/* Fuzzing support */
end_comment

begin_struct_decl
struct_decl|struct
name|fuzz
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|FUZZ_1_BIT_FLIP
value|0x00000001
end_define

begin_comment
comment|/* Flip one bit at a time */
end_comment

begin_define
define|#
directive|define
name|FUZZ_2_BIT_FLIP
value|0x00000002
end_define

begin_comment
comment|/* Flip two bits at a time */
end_comment

begin_define
define|#
directive|define
name|FUZZ_1_BYTE_FLIP
value|0x00000004
end_define

begin_comment
comment|/* Flip one byte at a time */
end_comment

begin_define
define|#
directive|define
name|FUZZ_2_BYTE_FLIP
value|0x00000008
end_define

begin_comment
comment|/* Flip two bytes at a time */
end_comment

begin_define
define|#
directive|define
name|FUZZ_TRUNCATE_START
value|0x00000010
end_define

begin_comment
comment|/* Truncate from beginning */
end_comment

begin_define
define|#
directive|define
name|FUZZ_TRUNCATE_END
value|0x00000020
end_define

begin_comment
comment|/* Truncate from end */
end_comment

begin_define
define|#
directive|define
name|FUZZ_BASE64
value|0x00000040
end_define

begin_comment
comment|/* Try all base64 chars */
end_comment

begin_define
define|#
directive|define
name|FUZZ_MAX
value|FUZZ_BASE64
end_define

begin_comment
comment|/* Start fuzzing a blob of data with selected strategies (bitmask) */
end_comment

begin_function_decl
name|struct
name|fuzz
modifier|*
name|fuzz_begin
parameter_list|(
name|u_int
name|strategies
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a fuzz context */
end_comment

begin_function_decl
name|void
name|fuzz_cleanup
parameter_list|(
name|struct
name|fuzz
modifier|*
name|fuzz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Prepare the next fuzz case in the series */
end_comment

begin_function_decl
name|void
name|fuzz_next
parameter_list|(
name|struct
name|fuzz
modifier|*
name|fuzz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check whether this fuzz case is identical to the original  * This is slow, but useful if the caller needs to ensure that all tests  * generated change the input (e.g. when fuzzing signatures).  */
end_comment

begin_function_decl
name|int
name|fuzz_matches_original
parameter_list|(
name|struct
name|fuzz
modifier|*
name|fuzz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine whether the current fuzz sequence is exhausted (nonzero = yes) */
end_comment

begin_function_decl
name|int
name|fuzz_done
parameter_list|(
name|struct
name|fuzz
modifier|*
name|fuzz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the length and a pointer to the current fuzzed case */
end_comment

begin_function_decl
name|size_t
name|fuzz_len
parameter_list|(
name|struct
name|fuzz
modifier|*
name|fuzz
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_char
modifier|*
name|fuzz_ptr
parameter_list|(
name|struct
name|fuzz
modifier|*
name|fuzz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Dump the current fuzz case to stderr */
end_comment

begin_function_decl
name|void
name|fuzz_dump
parameter_list|(
name|struct
name|fuzz
modifier|*
name|fuzz
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TEST_HELPER_H */
end_comment

end_unit

