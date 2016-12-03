begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_posix_fallocate.c,v 1.1 2015/01/31 23:06:57 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright 2015, Google Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * Neither the name of Google nor the names of its contributors may  *    be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_posix_fallocate.c,v 1.1 2015/01/31 23:06:57 christos Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_expr_stmt
name|ATF_TC_WITHOUT_HEAD
argument_list|(
name|ebadf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|ebadf
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|int
name|rc
decl_stmt|,
name|saved
decl_stmt|;
name|errno
operator|=
literal|1111
expr_stmt|;
name|rc
operator|=
name|posix_fallocate
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|4096
argument_list|)
expr_stmt|;
name|saved
operator|=
name|errno
expr_stmt|;
if|if
condition|(
name|rc
operator|==
operator|-
literal|1
operator|&&
name|saved
operator|!=
literal|1111
condition|)
name|atf_tc_fail
argument_list|(
literal|"Should return error %s without setting errno."
argument_list|,
name|strerror
argument_list|(
name|saved
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
name|EBADF
condition|)
name|atf_tc_fail
argument_list|(
literal|"returned %s but expected %s."
argument_list|,
name|strerror
argument_list|(
name|saved
argument_list|)
argument_list|,
name|strerror
argument_list|(
name|EBADF
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|saved
operator|!=
literal|1111
condition|)
name|atf_tc_fail
argument_list|(
literal|"errno should be %d but got changed to %d."
argument_list|,
literal|1111
argument_list|,
name|saved
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
name|ebadf
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

