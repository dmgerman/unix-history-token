begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2009 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|R_REPEAT
end_ifndef

begin_define
define|#
directive|define
name|R_REPEAT
value|200000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Bit selector.  */
end_comment

begin_define
define|#
directive|define
name|BM
parameter_list|(
name|v
parameter_list|,
name|b
parameter_list|)
value|(((v)>> (b))& 1)
end_define

begin_define
define|#
directive|define
name|CK_PR_BTC_T
parameter_list|(
name|w
parameter_list|,
name|v
parameter_list|)
define|\
value|{									\ 		unsigned int j;							\ 		uint##w##_t r = v;						\ 		bool t;								\ 		for (j = 0; j< (w); j++) {					\ 			t = ck_pr_btc_##w(&r, j);				\ 			if ((t&& !BM(v, j)) || ((BM(v, j) + BM(r, j)) != 1)) {	\ 				printf("FAIL [%" PRIx##w ":%u]\n", r, j);	\ 				exit(EXIT_FAILURE);				\ 			}							\ 		}								\ 	}
end_define

begin_define
define|#
directive|define
name|CK_PR_BTC_B
parameter_list|(
name|w
parameter_list|)
define|\
value|{						\ 		uint##w##_t o;				\ 		unsigned int i;				\ 		printf("ck_pr_btc_" #w ": ");		\ 		for (i = 0; i< R_REPEAT; i++) {	\ 			o = (uint##w##_t)common_rand();	\ 			CK_PR_BTC_T(w, o);		\ 		}					\ 		printf("  SUCCESS\n");			\ 	}
end_define

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|common_srand
argument_list|(
operator|(
name|unsigned
name|int
operator|)
name|getpid
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|CK_F_PR_BTC_64
name|CK_PR_BTC_B
argument_list|(
literal|64
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CK_F_PR_BTC_32
name|CK_PR_BTC_B
argument_list|(
literal|32
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CK_F_PR_BTC_16
name|CK_PR_BTC_B
argument_list|(
literal|16
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CK_F_PR_BTC_8
name|CK_PR_BTC_B
argument_list|(
literal|8
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

