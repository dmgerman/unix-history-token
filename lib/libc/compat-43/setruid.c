begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"From: @(#)setruid.c	5.5 (Berkeley) 2/23/91"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: setruid.c,v 1.2 1994/04/04 19:33:58 wollman Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|MESSAGE
value|": warning: this program uses setruid, which doesn't do anything\r\n(but used to)\r\n"
end_define

begin_function
name|int
ifdef|#
directive|ifdef
name|__STDC__
name|setruid
parameter_list|(
name|uid_t
name|ruid
parameter_list|)
else|#
directive|else
function|setruid
parameter_list|(
name|ruid
parameter_list|)
name|int
name|ruid
decl_stmt|;
endif|#
directive|endif
block|{
specifier|extern
name|char
modifier|*
name|__progname
decl_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
name|__progname
argument_list|,
name|strlen
argument_list|(
name|__progname
argument_list|)
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
name|MESSAGE
argument_list|,
sizeof|sizeof
argument_list|(
name|MESSAGE
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
return|return
operator|(
name|setreuid
argument_list|(
name|ruid
argument_list|,
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

begin_asm
asm|asm(".stabs \"warning: setruid function referenced\", 30, 0, 0, 0");
end_asm

begin_asm
asm|asm(".stabs \"_setruid\", 1, 0, 0, 0");
end_asm

end_unit

