begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_round.c,v 1.4 2013/11/11 23:57:34 joerg Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/*  * This tests for a bug in the initial implementation where  * precision was lost in an internal substraction, leading to  * rounding into the wrong direction.  */
end_comment

begin_comment
comment|/* 0.5 - EPSILON */
end_comment

begin_define
define|#
directive|define
name|VAL
value|0x0.7ffffffffffffcp0
end_define

begin_define
define|#
directive|define
name|VALF
value|0x0.7fffff8p0
end_define

begin_define
define|#
directive|define
name|VALL
value|(0.5 - LDBL_EPSILON)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__vax__
end_ifdef

begin_define
define|#
directive|define
name|SMALL_NUM
value|1.0e-38
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SMALL_NUM
value|1.0e-40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|ATF_TC
argument_list|(
name|round_dir
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|round_dir
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Check for rounding in wrong direction"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|round_dir
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|double
name|a
init|=
name|VAL
decl_stmt|,
name|b
decl_stmt|,
name|c
decl_stmt|;
name|float
name|af
init|=
name|VALF
decl_stmt|,
name|bf
decl_stmt|,
name|cf
decl_stmt|;
name|long
name|double
name|al
init|=
name|VALL
decl_stmt|,
name|bl
decl_stmt|,
name|cl
decl_stmt|;
name|b
operator|=
name|round
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|bf
operator|=
name|roundf
argument_list|(
name|af
argument_list|)
expr_stmt|;
name|bl
operator|=
name|roundl
argument_list|(
name|al
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|fabs
argument_list|(
name|b
argument_list|)
operator|<
name|SMALL_NUM
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|fabsf
argument_list|(
name|bf
argument_list|)
operator|<
name|SMALL_NUM
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|fabsl
argument_list|(
name|bl
argument_list|)
operator|<
name|SMALL_NUM
argument_list|)
expr_stmt|;
name|c
operator|=
name|round
argument_list|(
operator|-
name|a
argument_list|)
expr_stmt|;
name|cf
operator|=
name|roundf
argument_list|(
operator|-
name|af
argument_list|)
expr_stmt|;
name|cl
operator|=
name|roundl
argument_list|(
operator|-
name|al
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|fabs
argument_list|(
name|c
argument_list|)
operator|<
name|SMALL_NUM
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|fabsf
argument_list|(
name|cf
argument_list|)
operator|<
name|SMALL_NUM
argument_list|)
expr_stmt|;
name|ATF_CHECK
argument_list|(
name|fabsl
argument_list|(
name|cl
argument_list|)
operator|<
name|SMALL_NUM
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|round_dir
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

