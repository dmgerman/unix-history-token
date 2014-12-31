begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_randomid.c,v 1.3 2011/07/07 09:49:59 jruoho Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<randomid.h>
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

begin_define
define|#
directive|define
name|PERIOD
value|30000
end_define

begin_decl_stmt
name|uint64_t
name|last
index|[
literal|65536
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ATF_TC
argument_list|(
name|randomid_basic
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|randomid_basic
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
literal|"Check randomid(3)"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|randomid_basic
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|static
name|randomid_t
name|ctx
init|=
name|NULL
decl_stmt|;
name|uint64_t
name|lowest
decl_stmt|,
name|n
decl_stmt|,
name|diff
decl_stmt|;
name|uint16_t
name|id
decl_stmt|;
name|memset
argument_list|(
name|last
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|last
argument_list|)
argument_list|)
expr_stmt|;
name|ctx
operator|=
name|randomid_new
argument_list|(
literal|16
argument_list|,
operator|(
name|long
operator|)
literal|3600
argument_list|)
expr_stmt|;
name|lowest
operator|=
name|UINT64_MAX
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
literal|1000000
condition|;
name|n
operator|++
control|)
block|{
name|id
operator|=
name|randomid
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
if|if
condition|(
name|last
index|[
name|id
index|]
operator|>
literal|0
condition|)
block|{
name|diff
operator|=
name|n
operator|-
name|last
index|[
name|id
index|]
expr_stmt|;
if|if
condition|(
name|diff
operator|<=
name|lowest
condition|)
block|{
if|if
condition|(
name|lowest
operator|!=
name|UINT64_MAX
condition|)
name|printf
argument_list|(
literal|"id %5d: last call at %9"
name|PRIu64
literal|", current call %9"
name|PRIu64
literal|" (diff %5"
name|PRIu64
literal|"), "
literal|"lowest %"
name|PRIu64
literal|"\n"
argument_list|,
name|id
argument_list|,
name|last
index|[
name|id
index|]
argument_list|,
name|n
argument_list|,
name|diff
argument_list|,
name|lowest
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|diff
operator|>=
name|PERIOD
argument_list|,
literal|"diff (%"
name|PRIu64
literal|") less than minimum "
literal|"period (%d)"
argument_list|,
name|diff
argument_list|,
name|PERIOD
argument_list|)
expr_stmt|;
name|lowest
operator|=
name|diff
expr_stmt|;
block|}
block|}
name|last
index|[
name|id
index|]
operator|=
name|n
expr_stmt|;
block|}
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
name|randomid_basic
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

