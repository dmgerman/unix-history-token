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
name|TEST_N
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
value|static void						\ 	run_test_##K##_##S(void)				\ 	{							\ 		int i, r;					\ 		T x = 0, y = 0;					\ 								\ 		puts("***TESTING ck_pr_"#K"_"#S"***");		\ 		common_srand((unsigned int)getpid());		\ 		for (i = 0; i< REPEAT; ++i) {			\ 			r = common_rand();				\ 			x += r;					\ 			x = P x;				\ 			y += r;					\ 			ck_pr_##K##_##S(&y);			\ 		}						\ 								\ 		printf("Value of operation "#K" on 2000000 "	\ 			"random numbers\n"			\ 			"\tusing "#P": %"#D",\n"		\ 			"\tusing ck_pr_"#K"_"#S": %"#D",\n",	\ 			x, y);					\ 		(x == y) ? puts("SUCCESS.")			\ 			 : puts("FAILURE.");			\ 								\ 		return;						\ 	}
end_define

begin_define
define|#
directive|define
name|GENERATE_TEST
parameter_list|(
name|K
parameter_list|,
name|P
parameter_list|)
define|\
value|TEST_N(K, int, int, P, d)		\ 	TEST_N(K, uint, unsigned int, P, u)	\ 	static void				\ 	run_test_##K(void)			\ 	{					\ 		run_test_##K##_int();		\ 		run_test_##K##_uint();		\ 						\ 		return;				\ 	}
end_define

begin_macro
name|GENERATE_TEST
argument_list|(
argument|not
argument_list|,
argument|~
argument_list|)
end_macro

begin_macro
name|GENERATE_TEST
argument_list|(
argument|neg
argument_list|,
argument|-
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
name|TEST_N
end_undef

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|run_test_not
argument_list|()
expr_stmt|;
name|run_test_neg
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

