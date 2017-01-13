begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: t_bind.c,v 1.3 2015/04/05 23:28:10 rtr Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2015 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_expr_stmt
name|ATF_TC
argument_list|(
name|bind_foreign_family
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|bind_foreign_family
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"Checks that binding a socket "
literal|"with a different address family fails"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|bind_foreign_family
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
comment|/* addr.sin_family = AF_UNSPEC = 0 */
name|memset
argument_list|(
operator|&
name|addr
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|addr
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * it is not necessary to initialize sin_{addr,port} since 	 * those structure members shall not be accessed if bind 	 * fails correctly. 	 */
name|int
name|sock
init|=
name|socket
argument_list|(
name|AF_LOCAL
argument_list|,
name|SOCK_STREAM
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|ATF_REQUIRE
argument_list|(
name|sock
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* should fail but currently doesn't */
name|ATF_REQUIRE
argument_list|(
operator|-
literal|1
operator|==
name|bind
argument_list|(
name|sock
argument_list|,
operator|(
expr|struct
name|sockaddr
operator|*
operator|)
operator|&
name|addr
argument_list|,
sizeof|sizeof
argument_list|(
name|addr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|EAFNOSUPPORT
operator|==
name|errno
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|sock
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|bind_foreign_family
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

