begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Juniper Networks.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_comment
comment|/* null */
end_comment

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|null_handler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|null_handler
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
name|set_constraint_handler_s
argument_list|(
name|abort_handler_s
argument_list|)
operator|==
name|NULL
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* abort handler */
end_comment

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|abort_handler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|abort_handler
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|set_constraint_handler_s
argument_list|(
name|abort_handler_s
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|set_constraint_handler_s
argument_list|(
name|ignore_handler_s
argument_list|)
operator|==
name|abort_handler_s
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ignore handler */
end_comment

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|ignore_handler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|ignore_handler
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|set_constraint_handler_s
argument_list|(
name|ignore_handler_s
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|set_constraint_handler_s
argument_list|(
name|abort_handler_s
argument_list|)
operator|==
name|ignore_handler_s
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
name|null_handler
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|abort_handler
argument_list|)
expr_stmt|;
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|ignore_handler
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

