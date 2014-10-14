begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: h_cancel.c,v 1.1 2010/07/16 15:42:53 jmmv Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__COPYRIGHT
argument_list|(
literal|"@(#) Copyright (c) 2008\  The NetBSD Foundation, inc. All rights reserved."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: h_cancel.c,v 1.1 2010/07/16 15:42:53 jmmv Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|str1
index|[]
init|=
literal|"You should see this.\n"
decl_stmt|;
name|char
name|str2
index|[]
init|=
literal|"You should not see this.\n"
decl_stmt|;
name|printf
argument_list|(
literal|"Cancellation test: Self-cancellation and disabling.\n"
argument_list|)
expr_stmt|;
name|pthread_cancel
argument_list|(
name|pthread_self
argument_list|()
argument_list|)
expr_stmt|;
name|pthread_setcancelstate
argument_list|(
name|PTHREAD_CANCEL_DISABLE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|STDOUT_FILENO
argument_list|,
name|str1
argument_list|,
sizeof|sizeof
argument_list|(
name|str1
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|pthread_setcancelstate
argument_list|(
name|PTHREAD_CANCEL_ENABLE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|STDOUT_FILENO
argument_list|,
name|str2
argument_list|,
sizeof|sizeof
argument_list|(
name|str2
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

