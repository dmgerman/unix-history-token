begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$KAME: prefix.h,v 1.3 2000/11/19 11:45:38 itojun Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_struct
struct|struct
name|prefix
block|{
name|struct
name|sockaddr_storage
name|a
decl_stmt|;
name|int
name|l
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|config
block|{
name|struct
name|config
modifier|*
name|next
decl_stmt|;
name|int
name|permit
decl_stmt|;
name|struct
name|prefix
name|match
decl_stmt|;
name|struct
name|prefix
name|dest
decl_stmt|;
name|struct
name|prefix
name|src
decl_stmt|;
comment|/* src to use for outgoing connection */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_PATH_PREFIX_CONF
value|"/etc/faithd.conf"
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|prefix_string
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|prefix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|prefix_match
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|prefix
operator|*
operator|,
specifier|const
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|config_load
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|config
modifier|*
name|config_match
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

