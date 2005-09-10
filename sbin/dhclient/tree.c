begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: tree.c,v 1.13 2004/05/06 22:29:15 deraadt Exp $	*/
end_comment

begin_comment
comment|/* Routines for manipulating parse trees... */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995, 1996, 1997 The Internet Software Consortium.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Internet Software Consortium nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INTERNET SOFTWARE CONSORTIUM AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE INTERNET SOFTWARE CONSORTIUM OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This software has been written for the Internet Software Consortium  * by Ted Lemon<mellon@fugue.com> in cooperation with Vixie  * Enterprises.  To learn more about the Internet Software Consortium,  * see ``http://www.vix.com/isc''.  To learn more about Vixie  * Enterprises, see ``http://www.vix.com''.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"dhcpd.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_function
name|pair
name|cons
parameter_list|(
name|caddr_t
name|car
parameter_list|,
name|pair
name|cdr
parameter_list|)
block|{
name|pair
name|foo
init|=
name|calloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|foo
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|foo
condition|)
name|error
argument_list|(
literal|"no memory for cons."
argument_list|)
expr_stmt|;
name|foo
operator|->
name|car
operator|=
name|car
expr_stmt|;
name|foo
operator|->
name|cdr
operator|=
name|cdr
expr_stmt|;
return|return
operator|(
name|foo
operator|)
return|;
block|}
end_function

end_unit

