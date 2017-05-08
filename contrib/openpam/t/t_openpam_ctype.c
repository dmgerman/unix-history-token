begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014-2017 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: t_openpam_ctype.c 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<cryb/test.h>
end_include

begin_include
include|#
directive|include
file|"openpam_ctype.h"
end_include

begin_define
define|#
directive|define
name|OC_DIGIT
value|"0123456789"
end_define

begin_define
define|#
directive|define
name|OC_XDIGIT
value|OC_DIGIT "ABCDEFabcdef"
end_define

begin_define
define|#
directive|define
name|OC_UPPER
value|"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
end_define

begin_define
define|#
directive|define
name|OC_LOWER
value|"abcdefghijklmnopqrstuvwxyz"
end_define

begin_define
define|#
directive|define
name|OC_LETTER
value|OC_UPPER OC_LOWER
end_define

begin_define
define|#
directive|define
name|OC_LWS
value|" \t\f\r"
end_define

begin_define
define|#
directive|define
name|OC_WS
value|OC_LWS "\n"
end_define

begin_define
define|#
directive|define
name|OC_P
value|"!\"#$%&'()*+,-./" OC_DIGIT ":;<=>?@" OC_UPPER "[\\]^_`" OC_LOWER "{|}~"
end_define

begin_define
define|#
directive|define
name|OC_PFCS
value|OC_DIGIT OC_LETTER "._-"
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
name|oc_digit
index|[]
init|=
name|OC_DIGIT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|oc_xdigit
index|[]
init|=
name|OC_XDIGIT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|oc_upper
index|[]
init|=
name|OC_UPPER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|oc_lower
index|[]
init|=
name|OC_LOWER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|oc_letter
index|[]
init|=
name|OC_LETTER
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|oc_lws
index|[]
init|=
name|OC_LWS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|oc_ws
index|[]
init|=
name|OC_WS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|oc_p
index|[]
init|=
name|OC_P
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|oc_pfcs
index|[]
init|=
name|OC_PFCS
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|T_OC
parameter_list|(
name|set
parameter_list|)
define|\
value|static int							\ 	t_oc_##set(char **desc, void *arg)				\ 	{								\ 		char crib[256];						\ 		unsigned int i, ret;					\ 									\ 		(void)desc;						\ 		(void)arg;						\ 		memset(crib, 0, sizeof crib);				\ 		for (i = 0; oc_##set[i]; ++i)				\ 			crib[(int)oc_##set[i]] = 1;			\ 		for (i = ret = 0; i< sizeof crib; ++i) {		\ 			if (is_##set(i) != crib[i]) {			\ 				t_printv("is_%s() incorrect "		\ 				    "for %#02x\n", #set, i);		\ 				++ret;					\ 			}						\ 		}							\ 		return (ret == 0);					\ 	}
end_define

begin_define
define|#
directive|define
name|T_OC_ADD
parameter_list|(
name|set
parameter_list|)
value|t_add_test(&t_oc_##set, NULL, "is_"#set)
end_define

begin_macro
name|T_OC
argument_list|(
argument|digit
argument_list|)
end_macro

begin_macro
name|T_OC
argument_list|(
argument|xdigit
argument_list|)
end_macro

begin_macro
name|T_OC
argument_list|(
argument|upper
argument_list|)
end_macro

begin_macro
name|T_OC
argument_list|(
argument|lower
argument_list|)
end_macro

begin_macro
name|T_OC
argument_list|(
argument|letter
argument_list|)
end_macro

begin_macro
name|T_OC
argument_list|(
argument|lws
argument_list|)
end_macro

begin_macro
name|T_OC
argument_list|(
argument|ws
argument_list|)
end_macro

begin_macro
name|T_OC
argument_list|(
argument|p
argument_list|)
end_macro

begin_macro
name|T_OC
argument_list|(
argument|pfcs
argument_list|)
end_macro

begin_escape
end_escape

begin_comment
comment|/***************************************************************************  * Boilerplate  */
end_comment

begin_function
specifier|static
name|int
name|t_prepare
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
operator|(
name|void
operator|)
name|argc
expr_stmt|;
operator|(
name|void
operator|)
name|argv
expr_stmt|;
name|T_OC_ADD
argument_list|(
name|digit
argument_list|)
expr_stmt|;
name|T_OC_ADD
argument_list|(
name|xdigit
argument_list|)
expr_stmt|;
name|T_OC_ADD
argument_list|(
name|upper
argument_list|)
expr_stmt|;
name|T_OC_ADD
argument_list|(
name|lower
argument_list|)
expr_stmt|;
name|T_OC_ADD
argument_list|(
name|letter
argument_list|)
expr_stmt|;
name|T_OC_ADD
argument_list|(
name|lws
argument_list|)
expr_stmt|;
name|T_OC_ADD
argument_list|(
name|ws
argument_list|)
expr_stmt|;
name|T_OC_ADD
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|T_OC_ADD
argument_list|(
name|pfcs
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|t_main
argument_list|(
name|t_prepare
argument_list|,
name|NULL
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

