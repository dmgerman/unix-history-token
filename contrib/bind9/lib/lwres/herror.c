begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2000, 2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1993  *    The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  * 	This product includes software developed by the University of  * 	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)herror.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: herror.c,v 1.10.12.2 2004/03/06 08:15:31 marka Exp $"
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
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<lwres/netdb.h>
end_include

begin_include
include|#
directive|include
file|<lwres/platform.h>
end_include

begin_decl_stmt
name|LIBLWRES_EXTERNAL_DATA
name|int
name|lwres_h_errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * these have never been declared in any header file so make them static  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|h_errlist
index|[]
init|=
block|{
literal|"Resolver Error 0 (no error)"
block|,
literal|"Unknown host"
block|,
comment|/* 1 HOST_NOT_FOUND */
literal|"Host name lookup failure"
block|,
comment|/* 2 TRY_AGAIN */
literal|"Unknown server error"
block|,
comment|/* 3 NO_RECOVERY */
literal|"No address associated with name"
block|,
comment|/* 4 NO_ADDRESS */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|h_nerr
init|=
block|{
sizeof|sizeof
argument_list|(
name|h_errlist
argument_list|)
operator|/
expr|sizeof
operator|(
name|h_errlist
index|[
literal|0
index|]
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * herror --  *	print the error indicated by the h_errno value.  */
end_comment

begin_function
name|void
name|lwres_herror
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|s
argument_list|,
name|lwres_hstrerror
argument_list|(
name|lwres_h_errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * hstrerror --  *	return the string associated with a given "host" errno value.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|lwres_hstrerror
parameter_list|(
name|int
name|err
parameter_list|)
block|{
if|if
condition|(
name|err
operator|<
literal|0
condition|)
return|return
operator|(
literal|"Resolver internal error"
operator|)
return|;
elseif|else
if|if
condition|(
name|err
operator|<
name|h_nerr
condition|)
return|return
operator|(
name|h_errlist
index|[
name|err
index|]
operator|)
return|;
return|return
operator|(
literal|"Unknown resolver error"
operator|)
return|;
block|}
end_function

end_unit

