begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)spp_debug.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNS_SPP_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNS_SPP_DEBUG_H_
end_define

begin_struct
struct|struct
name|spp_debug
block|{
name|u_long
name|sd_time
decl_stmt|;
name|short
name|sd_act
decl_stmt|;
name|short
name|sd_ostate
decl_stmt|;
name|caddr_t
name|sd_cb
decl_stmt|;
name|short
name|sd_req
decl_stmt|;
name|struct
name|spidp
name|sd_si
decl_stmt|;
name|struct
name|sppcb
name|sd_sp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SA_INPUT
value|0
end_define

begin_define
define|#
directive|define
name|SA_OUTPUT
value|1
end_define

begin_define
define|#
directive|define
name|SA_USER
value|2
end_define

begin_define
define|#
directive|define
name|SA_RESPOND
value|3
end_define

begin_define
define|#
directive|define
name|SA_DROP
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SANAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|sanames
index|[]
init|=
block|{
literal|"input"
block|,
literal|"output"
block|,
literal|"user"
block|,
literal|"respond"
block|,
literal|"drop"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SPP_NDEBUG
value|100
end_define

begin_decl_stmt
name|struct
name|spp_debug
name|spp_debug
index|[
name|SPP_NDEBUG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spp_debx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

