begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_convfp.c,v 1.7 2011/06/14 11:58:22 njoly Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
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

begin_comment
comment|/*  * This value is representable as an unsigned int, but not as an int.  * According to ISO C it must survive the convsion back from a double  * to an unsigned int (everything> -1 and< UINT_MAX+1 has to)  */
end_comment

begin_define
define|#
directive|define
name|UINT_TESTVALUE
value|(INT_MAX+42U)
end_define

begin_comment
comment|/* The same for unsigned long */
end_comment

begin_define
define|#
directive|define
name|ULONG_TESTVALUE
value|(LONG_MAX+42UL)
end_define

begin_expr_stmt
name|ATF_TC
argument_list|(
name|conv_uint
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|conv_uint
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
literal|"test conversions to unsigned int"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|conv_uint
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|unsigned
name|int
name|ui
decl_stmt|;
name|double
name|d
decl_stmt|;
comment|/* unsigned int test */
name|d
operator|=
name|UINT_TESTVALUE
expr_stmt|;
name|ui
operator|=
operator|(
name|unsigned
name|int
operator|)
name|d
expr_stmt|;
if|if
condition|(
name|ui
operator|!=
name|UINT_TESTVALUE
condition|)
name|atf_tc_fail
argument_list|(
literal|"FAILED: unsigned int %u (0x%x) != %u (0x%x)"
argument_list|,
name|ui
argument_list|,
name|ui
argument_list|,
name|UINT_TESTVALUE
argument_list|,
name|UINT_TESTVALUE
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|conv_ulong
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|conv_ulong
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
literal|"test conversions to unsigned long"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|conv_ulong
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|unsigned
name|long
name|ul
decl_stmt|;
name|long
name|double
name|dt
decl_stmt|;
name|double
name|d
decl_stmt|;
comment|/* unsigned long vs. {long} double test */
if|if
condition|(
sizeof|sizeof
argument_list|(
name|d
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|ul
argument_list|)
condition|)
block|{
name|d
operator|=
name|ULONG_TESTVALUE
expr_stmt|;
name|ul
operator|=
operator|(
name|unsigned
name|long
operator|)
name|d
expr_stmt|;
name|printf
argument_list|(
literal|"testing double vs. long\n"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
sizeof|sizeof
argument_list|(
name|dt
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|ul
argument_list|)
condition|)
block|{
name|dt
operator|=
name|ULONG_TESTVALUE
expr_stmt|;
name|ul
operator|=
operator|(
name|unsigned
name|long
operator|)
name|dt
expr_stmt|;
name|printf
argument_list|(
literal|"testing long double vs. long\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"sizeof(long) = %zu, sizeof(double) = %zu, "
literal|"sizeof(long double) = %zu\n"
argument_list|,
sizeof|sizeof
argument_list|(
name|ul
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|d
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|dt
argument_list|)
argument_list|)
expr_stmt|;
name|atf_tc_skip
argument_list|(
literal|"no suitable {long} double type found"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ul
operator|!=
name|ULONG_TESTVALUE
condition|)
name|atf_tc_fail
argument_list|(
literal|"unsigned long %lu (0x%lx) != %lu (0x%lx)"
argument_list|,
name|ul
argument_list|,
name|ul
argument_list|,
name|ULONG_TESTVALUE
argument_list|,
name|ULONG_TESTVALUE
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|cast_ulong
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|cast_ulong
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
literal|"test double to unsigned long cast"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|cast_ulong
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|double
name|nv
decl_stmt|;
name|unsigned
name|long
name|uv
decl_stmt|;
name|nv
operator|=
literal|5.6
expr_stmt|;
name|uv
operator|=
operator|(
name|unsigned
name|long
operator|)
name|nv
expr_stmt|;
name|ATF_CHECK_EQ_MSG
argument_list|(
name|uv
argument_list|,
literal|5
argument_list|,
literal|"%.3f casted to unsigned long is %lu"
argument_list|,
name|nv
argument_list|,
name|uv
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|ATF_TC
argument_list|(
name|cast_ulong2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|cast_ulong2
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
literal|"test double/long double casts to unsigned long"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|cast_ulong2
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|double
name|dv
init|=
literal|1.9
decl_stmt|;
name|long
name|double
name|ldv
init|=
name|dv
decl_stmt|;
name|unsigned
name|long
name|l1
init|=
name|dv
decl_stmt|;
name|unsigned
name|long
name|l2
init|=
name|ldv
decl_stmt|;
name|ATF_CHECK_EQ_MSG
argument_list|(
name|l1
argument_list|,
literal|1
argument_list|,
literal|"double 1.9 casted to unsigned long should be 1, but is %lu"
argument_list|,
name|l1
argument_list|)
expr_stmt|;
name|ATF_CHECK_EQ_MSG
argument_list|(
name|l2
argument_list|,
literal|1
argument_list|,
literal|"long double 1.9 casted to unsigned long should be 1, but is %lu"
argument_list|,
name|l2
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
name|conv_uint
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|conv_ulong
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|cast_ulong
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|cast_ulong2
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

