begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-1999  *	HD Associates, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HD Associates, Inc  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY HD ASSOCIATES AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL HD ASSOCIATES OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|199309L
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|p26
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|)
block|{
name|int
name|ret
init|=
literal|0
decl_stmt|;
ifndef|#
directive|ifndef
name|_POSIX_VERSION
name|printf
argument_list|(
literal|"POSIX is not supported.\n"
argument_list|)
expr_stmt|;
name|ret
operator|=
operator|-
literal|1
expr_stmt|;
else|#
directive|else
comment|/* _POSIX_VERSION */
if|#
directive|if
operator|(
name|_POSIX_VERSION
operator|==
literal|198808L
operator|)
name|printf
argument_list|(
literal|"POSIX.1 is supported but not POSIX.1B (FIPS 151-1)\n"
argument_list|)
expr_stmt|;
elif|#
directive|elif
operator|(
name|_POSIX_VERSION
operator|==
literal|199009L
operator|)
name|printf
argument_list|(
literal|"POSIX.1 is supported but not POSIX.1B (FIPS 151-2)\n"
argument_list|)
expr_stmt|;
elif|#
directive|elif
operator|(
name|_POSIX_VERSION
operator|>=
literal|199309L
operator|)
name|printf
argument_list|(
literal|"POSIX.1 and POSIX.1B are supported.\n"
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"_POSIX_VERSION (%ld) not 198808, 199009, or>= 199309.\n"
argument_list|,
name|_POSIX_VERSION
argument_list|)
expr_stmt|;
name|ret
operator|=
operator|-
literal|1
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* _POSIX_VERSION */
return|return
name|ret
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|STANDALONE_TESTS
end_ifdef

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
return|return
name|p26
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

