begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)uipc_proto.c	7.6 (Berkeley) 5/9/91  *	$Id: uipc_proto.c,v 1.2 1993/10/16 15:25:09 rgrimes Exp $  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"net/raw_cb.h"
end_include

begin_comment
comment|/*  * Definitions of protocols supported in the UNIX domain.  */
end_comment

begin_function_decl
name|int
name|uipc_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|unixdomain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* or at least forward */
end_comment

begin_decl_stmt
name|struct
name|protosw
name|unixsw
index|[]
init|=
block|{
block|{
name|SOCK_STREAM
block|,
operator|&
name|unixdomain
block|,
literal|0
block|,
name|PR_CONNREQUIRED
operator||
name|PR_WANTRCVD
operator||
name|PR_RIGHTS
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|uipc_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|,
block|{
name|SOCK_DGRAM
block|,
operator|&
name|unixdomain
block|,
literal|0
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
operator||
name|PR_RIGHTS
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|uipc_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|raw_input
block|,
literal|0
block|,
name|raw_ctlinput
block|,
literal|0
block|,
name|raw_usrreq
block|,
name|raw_init
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unp_externalize
argument_list|()
decl_stmt|,
name|unp_dispose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|unixdomain
init|=
block|{
name|AF_UNIX
block|,
literal|"unix"
block|,
literal|0
block|,
name|unp_externalize
block|,
name|unp_dispose
block|,
name|unixsw
block|,
operator|&
name|unixsw
index|[
sizeof|sizeof
argument_list|(
name|unixsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|unixsw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
decl_stmt|;
end_decl_stmt

end_unit

