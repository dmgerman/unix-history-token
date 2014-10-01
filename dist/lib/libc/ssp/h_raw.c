begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: h_raw.c,v 1.6 2011/07/24 14:00:36 christos Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__COPYRIGHT
argument_list|(
literal|"@(#) Copyright (c) 2011\  The NetBSD Foundation, inc. All rights reserved."
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: h_raw.c,v 1.6 2011/07/24 14:00:36 christos Exp $"
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

begin_function_decl
name|void
name|poke
parameter_list|(
name|int
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|poke
parameter_list|(
name|int
modifier|*
name|b
parameter_list|,
name|size_t
name|index
parameter_list|)
block|{
name|size_t
name|i
decl_stmt|;
specifier|volatile
name|int
name|sum
init|=
literal|0
decl_stmt|;
name|b
index|[
name|index
index|]
operator|=
literal|42
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
name|sum
operator|+=
name|b
index|[
name|i
index|]
expr_stmt|;
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
name|int
name|b
index|[
literal|10
index|]
decl_stmt|;
name|poke
argument_list|(
name|b
argument_list|,
name|atoi
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

