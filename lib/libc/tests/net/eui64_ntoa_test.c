begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2004 The Aerospace Corporation.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions, and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions, and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  The name of The Aerospace Corporation may not be used to endorse or  *     promote products derived from this software.  *  * THIS SOFTWARE IS PROVIDED BY THE AEROSPACE CORPORATION "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AEROSPACE CORPORATION BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/eui64.h>
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
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|"test-eui64.h"
end_include

begin_function
specifier|static
name|void
name|test_str
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|struct
name|eui64
modifier|*
name|eui
parameter_list|)
block|{
name|char
name|a
index|[
name|EUI64_SIZ
index|]
decl_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|eui64_ntoa
argument_list|(
operator|&
name|test_eui64_id
argument_list|,
name|a
argument_list|,
sizeof|sizeof
argument_list|(
name|a
argument_list|)
argument_list|)
operator|==
literal|0
argument_list|,
literal|"eui64_ntoa failed"
argument_list|)
expr_stmt|;
name|ATF_REQUIRE_MSG
argument_list|(
name|strcmp
argument_list|(
name|a
argument_list|,
name|test_eui64_id_ascii
argument_list|)
operator|==
literal|0
argument_list|,
literal|"the strings mismatched: `%s` != `%s`"
argument_list|,
name|a
argument_list|,
name|test_eui64_id_ascii
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|id_ascii
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|id_ascii
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|test_str
argument_list|(
name|test_eui64_id_ascii
argument_list|,
operator|&
name|test_eui64_id
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
name|id_ascii
argument_list|)
expr_stmt|;
return|return
operator|(
name|atf_no_error
argument_list|()
operator|)
return|;
block|}
end_block

end_unit

