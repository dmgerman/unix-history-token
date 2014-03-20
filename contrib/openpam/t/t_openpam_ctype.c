begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  */
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
file|"openpam_ctype.h"
end_include

begin_include
include|#
directive|include
file|"t.h"
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
value|T_FUNC(t_oc_##set, "is_" #set)					\ 	{								\ 		char crib[256];						\ 		unsigned int i, ret;					\ 									\ 		memset(crib, 0, sizeof crib);				\ 		for (i = 0; oc_##set[i]; ++i)				\ 			crib[(int)oc_##set[i]] = 1;			\ 		for (i = ret = 0; i< sizeof crib; ++i) {		\ 			if (is_##set(i) != crib[i]) {			\ 				t_verbose("is_%s() incorrect "		\ 				    "for %#02x\n", #set, i);		\ 				++ret;					\ 			}						\ 		}							\ 		return (ret == 0);					\ 	}
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

begin_decl_stmt
specifier|const
name|struct
name|t_test
modifier|*
name|t_plan
index|[]
init|=
block|{
name|T
argument_list|(
name|t_oc_digit
argument_list|)
block|,
name|T
argument_list|(
name|t_oc_xdigit
argument_list|)
block|,
name|T
argument_list|(
name|t_oc_upper
argument_list|)
block|,
name|T
argument_list|(
name|t_oc_lower
argument_list|)
block|,
name|T
argument_list|(
name|t_oc_letter
argument_list|)
block|,
name|T
argument_list|(
name|t_oc_lws
argument_list|)
block|,
name|T
argument_list|(
name|t_oc_ws
argument_list|)
block|,
name|T
argument_list|(
name|t_oc_p
argument_list|)
block|,
name|T
argument_list|(
name|t_oc_pfcs
argument_list|)
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|struct
name|t_test
modifier|*
modifier|*
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
return|return
operator|(
name|t_plan
operator|)
return|;
block|}
end_function

begin_function
name|void
name|t_cleanup
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

