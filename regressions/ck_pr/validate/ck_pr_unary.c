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

begin_define
define|#
directive|define
name|REPEAT
value|2000000
end_define

begin_define
define|#
directive|define
name|TEST_UNARY
parameter_list|(
name|K
parameter_list|,
name|S
parameter_list|,
name|M
parameter_list|,
name|T
parameter_list|,
name|P
parameter_list|,
name|D
parameter_list|,
name|H
parameter_list|)
define|\
value|static void											\ 	test_##K##_##S(M *target)									\ 	{												\ 		*target = *target P 1;									\ 													\ 		return;											\ 	}												\ 	static void											\ 	test_##K##_##S##_zero(M *target, bool *zero)							\ 	{												\ 		*zero = *target == H;									\ 		*target = *target P 1;									\ 													\ 		return;											\ 	}												\ 	static void											\ 	run_test_##K##_##S(bool use_zero)								\ 	{												\ 		int i;											\ 		T x = 1, y = 1;										\ 		bool zero_x = false, zero_y = false;							\ 													\ 		use_zero ? puts("***TESTING ck_pr_"#K"_"#S"_zero***")					\ 			 : puts("***TESTING ck_pr_"#K"_"#S"***");					\ 		for (i = 0; i< REPEAT; ++i) {								\ 			if (use_zero) {									\ 				test_##K##_##S##_zero(&x,&zero_x);					\ 				ck_pr_##K##_##S##_zero(&y,&zero_y);					\ 			}										\ 			else {										\ 				test_##K##_##S(&x);							\ 				ck_pr_##K##_##S(&y);							\ 			}										\ 													\ 			if (x != y || zero_x != zero_y) {						\ 				printf("Serial(%"#D") and ck_pr(%"#D")"					\ 					#K"_"#S" do not match.\n"					\ 					"FAILURE.\n",							\ 					x, y);								\ 													\ 				return;									\ 			}										\ 													\ 			if (zero_x)									\ 				printf("Variables are zero at iteration %d\n", i);			\ 		}											\ 													\ 													\ 		printf("\tserial_"#K"_"#S": %"#D"\n"							\ 			"\tck_pr_"#K"_"#S": %"#D"\n"							\ 			"SUCCESS.\n",									\ 			x, y);										\ 													\ 		return;											\ 	}
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
name|Y
parameter_list|,
name|Z
parameter_list|)
define|\
value|TEST_UNARY(K, int, int, int, P, d, Y)				\ 	TEST_UNARY(K, uint, unsigned int, unsigned int, P, u, Z)	\ 	static void							\ 	run_test_##K(void)						\ 	{								\ 		run_test_##K##_int(false);				\ 		run_test_##K##_int(true);				\ 		run_test_##K##_uint(false);				\ 		run_test_##K##_uint(true);				\ 	}
end_define

begin_macro
name|GENERATE_TEST
argument_list|(
argument|inc
argument_list|,
argument|+
argument_list|,
argument|-
literal|1
argument_list|,
argument|UINT_MAX
argument_list|)
end_macro

begin_macro
name|GENERATE_TEST
argument_list|(
argument|dec
argument_list|,
argument|-
argument_list|,
literal|1
argument_list|,
literal|1
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
name|TEST_UNARY
end_undef

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|run_test_inc
argument_list|()
expr_stmt|;
name|run_test_dec
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

