begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: metachar.h,v 1.4 2015/06/21 20:26:02 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2015 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_METACHAR_H
end_ifndef

begin_define
define|#
directive|define
name|_METACHAR_H
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|_metachar
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ismeta
parameter_list|(
name|c
parameter_list|)
value|_metachar[(c)& 0x7f]
end_define

begin_function
specifier|static
specifier|inline
name|int
name|hasmeta
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd
parameter_list|)
block|{
while|while
condition|(
operator|!
name|ismeta
argument_list|(
operator|*
name|cmd
argument_list|)
condition|)
name|cmd
operator|++
expr_stmt|;
return|return
operator|*
name|cmd
operator|!=
literal|'\0'
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|needshell
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd
parameter_list|,
name|int
name|white
parameter_list|)
block|{
while|while
condition|(
operator|!
name|ismeta
argument_list|(
operator|*
name|cmd
argument_list|)
operator|&&
operator|*
name|cmd
operator|!=
literal|':'
operator|&&
operator|*
name|cmd
operator|!=
literal|'='
condition|)
block|{
if|if
condition|(
name|white
operator|&&
name|isspace
argument_list|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|cmd
argument_list|)
condition|)
break|break;
name|cmd
operator|++
expr_stmt|;
block|}
return|return
operator|*
name|cmd
operator|!=
literal|'\0'
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _METACHAR_H */
end_comment

end_unit

