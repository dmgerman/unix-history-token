begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)sysexits.c	8.1 (Berkeley) 6/7/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_comment
comment|/* **  SYSEXITS.C -- error messages corresponding to sysexits.h ** **	If the first character of the string is a colon, interpolate **	the current errno after the rest of the string. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SysExMsg
index|[]
init|=
block|{
comment|/* 64 USAGE */
literal|" 500 Bad usage"
block|,
comment|/* 65 DATAERR */
literal|" 501 Data format error"
block|,
comment|/* 66 NOINPUT */
literal|":550 Cannot open input"
block|,
comment|/* 67 NOUSER */
literal|" 550 User unknown"
block|,
comment|/* 68 NOHOST */
literal|" 550 Host unknown"
block|,
comment|/* 69 UNAVAILABLE */
literal|" 554 Service unavailable"
block|,
comment|/* 70 SOFTWARE */
literal|":554 Internal error"
block|,
comment|/* 71 OSERR */
literal|":451 Operating system error"
block|,
comment|/* 72 OSFILE */
literal|":554 System file missing"
block|,
comment|/* 73 CANTCREAT */
literal|":550 Can't create output"
block|,
comment|/* 74 IOERR */
literal|":451 I/O error"
block|,
comment|/* 75 TEMPFAIL */
literal|" 250 Deferred"
block|,
comment|/* 76 PROTOCOL */
literal|" 554 Remote protocol error"
block|,
comment|/* 77 NOPERM */
literal|":550 Insufficient permission"
block|,
comment|/* 78 CONFIG */
literal|" 554 Local configuration error"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|N_SysEx
init|=
sizeof|sizeof
argument_list|(
name|SysExMsg
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|SysExMsg
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

