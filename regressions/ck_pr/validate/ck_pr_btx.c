begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2011 David Joseph.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<ck_pr.h>
end_include

begin_include
include|#
directive|include
file|"../../common.h"
end_include

begin_define
define|#
directive|define
name|REPEAT
value|2000000
end_define

begin_define
define|#
directive|define
name|TEST_BTX
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|L
parameter_list|,
name|P
parameter_list|,
name|D
parameter_list|,
name|R
parameter_list|)
define|\
value|static bool									\ 	test_##K##_##S(M *target, int offset)						\ 	{										\ 		T previous;								\ 		const L change = R (0x01<< offset);					\ 											\ 		previous = (T)*target;							\ 		*target = previous P change;						\ 		return ((previous>> offset)& 0x01);					\ 	}										\ 	static void									\ 	run_test_##K##_##S(void)							\ 	{										\ 		int i, offset, m;							\ 		bool serial_t, ck_pr_t;							\ 		T x = 65535, y = 65535;							\ 											\ 		common_srand((unsigned int)getpid());					\ 		m = sizeof(T) * 8;							\ 											\ 		puts("***TESTING ck_pr_"#K"_"#S"***");					\ 		for (i = 0; i< REPEAT; ++i) {						\ 			offset = common_rand() % m;						\ 			serial_t = test_##K##_##S(&x, offset);				\ 			ck_pr_t = ck_pr_##K##_##S(&y, offset);				\ 											\ 			if (serial_t != ck_pr_t || x != y ) {				\ 				printf("Serial(%"#D") and ck_pr(%"#D")"			\ 					#K"_"#S " do not match.\n"			\ 					"FAILURE.\n", 					\ 					serial_t, ck_pr_t);				\ 											\ 				return;							\ 			}								\ 		}									\ 		printf("\tserial_"#K"_"#S": %"#D"\n"					\ 			"\tck_pr_"#K"_"#S": %"#D"\n"					\ 			"SUCCESS.\n",							\ 			x, y);								\ 											\ 		return;									\ 	}
end_define

begin_define
define|#
directive|define
name|TEST_BTX_S
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|P
parameter_list|,
name|D
parameter_list|,
name|R
parameter_list|)
value|TEST_BTX(K, S, T, T, T, P, D, R)
end_define

begin_define
define|#
directive|define
name|GENERATE_TEST
parameter_list|(
name|K
parameter_list|,
name|P
parameter_list|,
name|R
parameter_list|)
define|\
value|TEST_BTX_S(K, int, int, P, d, R)		\ 	TEST_BTX_S(K, uint, unsigned int, P, u, R)	\ 	static void					\ 	run_test_##K(void)				\ 	{						\ 		run_test_##K##_int();			\ 		run_test_##K##_uint();			\ 							\ 		return;					\ 	}
end_define

begin_macro
name|GENERATE_TEST
argument_list|(
argument|btc
argument_list|,
argument|^
argument_list|,
literal|0
argument|+
argument_list|)
end_macro

begin_macro
name|GENERATE_TEST
argument_list|(
argument|btr
argument_list|,
argument|&
argument_list|,
argument|~
argument_list|)
end_macro

begin_macro
name|GENERATE_TEST
argument_list|(
argument|bts
argument_list|,
argument||
argument_list|,
literal|0
argument|+
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|GENERATE_TEST
end_undef

begin_undef
undef|#
directive|undef
name|TEST_BTX_S
end_undef

begin_undef
undef|#
directive|undef
name|TEST_BTX
end_undef

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|run_test_btc
argument_list|()
expr_stmt|;
name|run_test_btr
argument_list|()
expr_stmt|;
name|run_test_bts
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

