begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2011 David Joseph.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<ck_pr.h>
end_include

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
name|TEST_BINARY
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
parameter_list|)
define|\
value|static void							\ 	run_test_##K##_##S(void)					\ 	{								\ 		int i, r;						\ 		T serial_result = 65535;				\ 		T ck_result = 65535;					\ 									\ 		puts("***TESTING ck_pr_" #K "_" #S "***");		\ 		common_srand((unsigned int)getpid());			\ 		for (i = 0; i< REPEAT; ++i) {				\ 			r = common_rand();					\ 			serial_result = serial_result P r;		\ 			ck_pr_##K##_##S(&ck_result, r);			\ 		}							\ 									\ 		printf("Value of operation " #K " on 2000000 "		\ 			"random numbers\n\tusing " #P ": %" #D ",\n"	\ 			"\tusing ck_pr_"#K"_"#S": %" #D "\n",		\ 				 serial_result, ck_result);		\ 		(serial_result == ck_result) ? puts("SUCCESS.")		\ 					     : puts("FAILURE.");	\ 									\ 		return;							\ 	}								\  #define GENERATE_TEST(K, P)				\ 	TEST_BINARY(K, int, int, P, d)			\ 	TEST_BINARY(K, uint, unsigned int, P, u)	\ 	static void					\ 	run_test_##K(void)				\ 	{						\ 		run_test_##K##_int();			\ 		run_test_##K##_uint();			\ 							\ 		return;					\ 	}
end_define

begin_macro
name|GENERATE_TEST
argument_list|(
argument|add
argument_list|,
argument|+
argument_list|)
end_macro

begin_macro
name|GENERATE_TEST
argument_list|(
argument|sub
argument_list|,
argument|-
argument_list|)
end_macro

begin_macro
name|GENERATE_TEST
argument_list|(
argument|and
argument_list|,
argument|&
argument_list|)
end_macro

begin_macro
name|GENERATE_TEST
argument_list|(
argument|or
argument_list|,
argument||
argument_list|)
end_macro

begin_macro
name|GENERATE_TEST
argument_list|(
argument|xor
argument_list|,
argument|^
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
name|TEST_BINARY
end_undef

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|run_test_add
argument_list|()
expr_stmt|;
name|run_test_sub
argument_list|()
expr_stmt|;
name|run_test_and
argument_list|()
expr_stmt|;
name|run_test_or
argument_list|()
expr_stmt|;
name|run_test_xor
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

