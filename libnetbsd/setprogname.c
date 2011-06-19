begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: setprogname.c,v 1.4 2008/04/29 08:13:38 martin Exp $	*/
end_comment

begin_comment
comment|/*	from	NetBSD: setprogname.c,v 1.3 2002/01/31 19:21:58 tv Exp	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Todd Vierling.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"tnftp.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|__progname
init|=
literal|"<unset_progname>"
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|setprogname
parameter_list|(
specifier|const
name|char
modifier|*
name|progname
parameter_list|)
block|{
name|__progname
operator|=
name|strrchr
argument_list|(
name|progname
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
if|if
condition|(
name|__progname
operator|==
name|NULL
condition|)
name|__progname
operator|=
name|progname
expr_stmt|;
else|else
name|__progname
operator|++
expr_stmt|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|getprogname
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|__progname
return|;
block|}
end_function

end_unit

