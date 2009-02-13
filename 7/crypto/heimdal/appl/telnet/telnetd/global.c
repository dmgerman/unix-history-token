begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* a *lot* of ugly global definitions that really should be removed...  */
end_comment

begin_include
include|#
directive|include
file|"telnetd.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: global.c,v 1.13 2001/07/19 16:00:42 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Telnet server variable declarations  */
end_comment

begin_decl_stmt
name|char
name|options
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|do_dont_resp
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|will_wont_resp
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linemode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* linemode on/off */
end_comment

begin_decl_stmt
name|int
name|flowmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current flow control state */
end_comment

begin_decl_stmt
name|int
name|restartany
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* restart output on any character state */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTICS
end_ifdef

begin_decl_stmt
name|int
name|diagnostic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* telnet diagnostic capabilities */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIAGNOSTICS */
end_comment

begin_decl_stmt
name|int
name|require_otp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|slcfun
name|slctab
index|[
name|NSLC
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* slc mapping table */
end_comment

begin_decl_stmt
name|char
modifier|*
name|terminaltype
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * I/O data buffers, pointers, and counters.  */
end_comment

begin_decl_stmt
name|char
name|ptyobuf
index|[
name|BUFSIZ
operator|+
name|NETSLOP
index|]
decl_stmt|,
modifier|*
name|pfrontp
decl_stmt|,
modifier|*
name|pbackp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|netibuf
index|[
name|BUFSIZ
index|]
decl_stmt|,
modifier|*
name|netip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|netobuf
index|[
name|BUFSIZ
operator|+
name|NETSLOP
index|]
decl_stmt|,
modifier|*
name|nfrontp
decl_stmt|,
modifier|*
name|nbackp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|neturg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one past last bye of urgent data */
end_comment

begin_decl_stmt
name|int
name|pcc
decl_stmt|,
name|ncc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ourpty
decl_stmt|,
name|net
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SYNCHing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we are in TELNET SYNCH mode */
end_comment

begin_comment
comment|/*  * The following are some clocks used to decide how to interpret  * the relationship between various variables.  */
end_comment

begin_decl_stmt
name|struct
name|clocks_t
name|clocks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whether to log unauthenticated login attempts */
end_comment

begin_decl_stmt
name|int
name|log_unauth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do not print warning if connection is not encrypted */
end_comment

begin_decl_stmt
name|int
name|no_warn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This function appends data to nfrontp and advances nfrontp.  */
end_comment

begin_function
name|int
name|output_data
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|args
decl_stmt|;
name|int
name|remaining
decl_stmt|,
name|ret
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|remaining
operator|=
name|BUFSIZ
operator|-
operator|(
name|nfrontp
operator|-
name|netobuf
operator|)
expr_stmt|;
name|ret
operator|=
name|vsnprintf
argument_list|(
name|nfrontp
argument_list|,
name|remaining
argument_list|,
name|format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|nfrontp
operator|+=
name|min
argument_list|(
name|ret
argument_list|,
name|remaining
operator|-
literal|1
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

