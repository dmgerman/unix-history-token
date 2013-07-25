begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdatomic.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/*  * Tool for testing the logical behaviour of operations on atomic  * integer types. These tests make no attempt to actually test whether  * the functions are atomic or provide the right barrier semantics.  *  * For every type, we create an array of 16 elements and repeat the test  * on every element in the array. This allows us to test whether the  * atomic operations have no effect on surrounding values. This is  * especially useful for the smaller integer types, as it may be the  * case that these operations are implemented by processing entire words  * (e.g. on MIPS).  */
end_comment

begin_function
specifier|static
specifier|inline
name|intmax_t
name|rndnum
parameter_list|(
name|void
parameter_list|)
block|{
name|intmax_t
name|v
decl_stmt|;
name|arc4random_buf
argument_list|(
operator|&
name|v
argument_list|,
sizeof|sizeof
argument_list|(
name|v
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|v
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|DO_FETCH_TEST
parameter_list|(
name|T
parameter_list|,
name|a
parameter_list|,
name|name
parameter_list|,
name|result
parameter_list|)
value|do {				\ 	T v1 = atomic_load(a);						\ 	T v2 = rndnum();						\ 	assert(atomic_##name(a, v2) == v1); 				\ 	assert(atomic_load(a) == (T)(result)); 				\ } while (0)
end_define

begin_define
define|#
directive|define
name|DO_COMPARE_EXCHANGE_TEST
parameter_list|(
name|T
parameter_list|,
name|a
parameter_list|,
name|name
parameter_list|)
value|do {			\ 	T v1 = atomic_load(a);						\ 	T v2 = rndnum();						\ 	T v3 = rndnum();						\ 	if (atomic_compare_exchange_##name(a,&v2, v3))			\ 		assert(v1 == v2);					\ 	else								\ 		assert(atomic_compare_exchange_##name(a,&v2, v3));	\ 	assert(atomic_load(a) == v3);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|DO_ALL_TESTS
parameter_list|(
name|T
parameter_list|,
name|a
parameter_list|)
value|do {						\ 	{								\ 		T v1 = rndnum();					\ 		atomic_init(a, v1);					\ 		assert(atomic_load(a) == v1);				\ 	}								\ 	{								\ 		T v1 = rndnum();					\ 		atomic_store(a, v1);					\ 		assert(atomic_load(a) == v1);				\ 	}								\ 									\ 	DO_FETCH_TEST(T, a, exchange, v2);				\ 	DO_FETCH_TEST(T, a, fetch_add, v1 + v2);			\ 	DO_FETCH_TEST(T, a, fetch_and, v1& v2);			\ 	DO_FETCH_TEST(T, a, fetch_or, v1 | v2);				\ 	DO_FETCH_TEST(T, a, fetch_sub, v1 - v2);			\ 	DO_FETCH_TEST(T, a, fetch_xor, v1 ^ v2);			\ 									\ 	DO_COMPARE_EXCHANGE_TEST(T, a, weak);				\ 	DO_COMPARE_EXCHANGE_TEST(T, a, strong);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|TEST_TYPE
parameter_list|(
name|T
parameter_list|)
value|do {						\ 	int j;								\ 	struct { _Atomic(T) v[16]; } list, cmp;				\ 	arc4random_buf(&cmp, sizeof(cmp));				\ 	for (j = 0; j< 16; j++) {					\ 		list = cmp;						\ 		DO_ALL_TESTS(T,&list.v[j]);				\ 		list.v[j] = cmp.v[j];					\ 		assert(memcmp(&list,&cmp, sizeof(list)) == 0);		\ 	}								\ } while (0)
end_define

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|1000
condition|;
name|i
operator|++
control|)
block|{
name|TEST_TYPE
argument_list|(
name|int8_t
argument_list|)
expr_stmt|;
name|TEST_TYPE
argument_list|(
name|uint8_t
argument_list|)
expr_stmt|;
name|TEST_TYPE
argument_list|(
name|int16_t
argument_list|)
expr_stmt|;
name|TEST_TYPE
argument_list|(
name|uint16_t
argument_list|)
expr_stmt|;
name|TEST_TYPE
argument_list|(
name|int32_t
argument_list|)
expr_stmt|;
name|TEST_TYPE
argument_list|(
name|uint32_t
argument_list|)
expr_stmt|;
name|TEST_TYPE
argument_list|(
name|int64_t
argument_list|)
expr_stmt|;
name|TEST_TYPE
argument_list|(
name|uint64_t
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

