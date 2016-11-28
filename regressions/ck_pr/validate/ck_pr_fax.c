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
name|TEST_FAX_FN
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|,
name|M
parameter_list|)
define|\
value|static T									\ 	test_faa_##S(M *target, T delta)						\ 	{										\ 		T previous = (T)*target;						\ 		*target = (T)*target + delta;						\ 											\ 		return (previous);							\ 	}										\ 	static T									\ 	test_fas_##S(M *target, T update)						\ 	{										\ 		T previous = *target;							\ 		*target = update;							\ 											\ 		return (previous);							\ 	}
end_define

begin_define
define|#
directive|define
name|TEST_FAX_FN_S
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
value|TEST_FAX_FN(S, T, T)
end_define

begin_macro
name|TEST_FAX_FN_S
argument_list|(
argument|int
argument_list|,
argument|int
argument_list|)
end_macro

begin_macro
name|TEST_FAX_FN_S
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|TEST_FAX_FN_S
end_undef

begin_undef
undef|#
directive|undef
name|TEST_FAX_FN
end_undef

begin_define
define|#
directive|define
name|TEST_FAX
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|D
parameter_list|)
define|\
value|static void									\ 	run_test_##K##_##S(void)							\ 	{										\ 		int i, r;								\ 		T x = 0, y = 0, x_b, y_b;						\ 											\ 		puts("***TESTING ck_pr_"#K"_"#S"***");					\ 		common_srand((unsigned int)getpid());					\ 		for (i = 0; i< REPEAT; ++i) {						\ 			r = common_rand();							\ 			x_b = test_##K##_##S(&x, r);					\ 			y_b = ck_pr_##K##_##S(&y, r);					\ 											\ 			if (x_b != y_b) {						\ 				printf("Serial fetch does not match ck_pr fetch.\n"	\ 					"\tSerial: %"#D"\n"				\ 					"\tck_pr: %"#D"\n",				\ 					x_b, y_b);					\ 											\ 				return;							\ 			}								\ 		}									\ 											\ 		printf("Final result:\n"						\ 			"\tSerial: %"#D"\n"						\ 			"\tck_pr: %"#D"\n",						\ 			x, y);								\ 		(x == y) ? puts("SUCCESS.")						\ 			 : puts("FAILURE.");						\ 											\ 		return;									\ 	}										\   #define GENERATE_TEST(K)				\ 	TEST_FAX(K, int, int, d)			\ 	TEST_FAX(K, uint, unsigned int, u)		\ 	static void					\ 	run_test_##K(void)				\ 	{						\ 		run_test_##K##_int();			\ 		run_test_##K##_uint();			\ 	}
end_define

begin_macro
name|GENERATE_TEST
argument_list|(
argument|faa
argument_list|)
end_macro

begin_macro
name|GENERATE_TEST
argument_list|(
argument|fas
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
name|TEST_FAX
end_undef

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|run_test_faa
argument_list|()
expr_stmt|;
name|run_test_fas
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

