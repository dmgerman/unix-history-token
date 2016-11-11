begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2014 Ion Badulescu  * Copyright (c) 1997-2014 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *  * File: am-utils/libamu/strerror.c  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_include
include|#
directive|include
file|<am_defs.h>
end_include

begin_include
include|#
directive|include
file|<amu.h>
end_include

begin_comment
comment|/*  * Convert errno to a string  */
end_comment

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|int
name|errnum
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_EXTERN_SYS_ERRLIST
if|if
condition|(
name|errnum
operator|<
literal|0
operator|||
name|errnum
operator|>=
operator|(
sizeof|sizeof
argument_list|(
name|sys_errlist
argument_list|)
operator|>>
literal|2
operator|)
condition|)
block|{
specifier|static
name|char
name|errstr
index|[
literal|30
index|]
decl_stmt|;
name|xsnprintf
argument_list|(
name|errstr
argument_list|,
sizeof|sizeof
argument_list|(
name|errstr
argument_list|)
argument_list|,
literal|"Unknown error #%d"
argument_list|,
name|errnum
argument_list|)
expr_stmt|;
return|return
name|errstr
return|;
block|}
return|return
name|sys_errlist
index|[
name|error
index|]
return|;
else|#
directive|else
comment|/* not HAVE_EXTERN_SYS_ERRLIST */
return|return
literal|"unknown (strerror not available)"
return|;
endif|#
directive|endif
comment|/* not HAVE_EXTERN_SYS_ERRLIST */
block|}
end_function

end_unit

