begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXRESOLVSORT
end_ifndef

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|MAXRESOLVSORT
value|10
end_define

begin_comment
comment|/* number of net to sort on */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_RES_STATE_EXT
end_ifndef

begin_struct
struct|struct
name|__res_state_ext
block|{
name|struct
name|sockaddr_storage
name|nsaddr_list
index|[
name|MAXNS
index|]
decl_stmt|;
struct|struct
block|{
name|int
name|af
decl_stmt|;
comment|/* address family for addr, mask */
union|union
block|{
name|struct
name|in_addr
name|ina
decl_stmt|;
ifdef|#
directive|ifdef
name|INET6
name|struct
name|in6_addr
name|in6a
decl_stmt|;
endif|#
directive|endif
block|}
name|addr
union|,
name|mask
union|;
block|}
name|sort_list
index|[
name|MAXRESOLVSORT
index|]
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|__res_state_ext
name|_res_ext
decl_stmt|;
end_decl_stmt

end_unit

