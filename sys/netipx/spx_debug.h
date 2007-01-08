begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1984, 1985, 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (c) 1995, Mike Mitchell  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)spx_debug.h  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETIPX_SPX_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETIPX_SPX_DEBUG_H_
end_define

begin_struct
struct|struct
name|spx_debug
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
name|spx
name|sd_si
decl_stmt|;
name|struct
name|spxpcb
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
specifier|const
name|char
modifier|*
name|spxnames
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
name|SPX_NDEBUG
value|100
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* XXX common variables for broken applications. */
end_comment

begin_decl_stmt
name|struct
name|spx_debug
name|spx_debug
index|[
name|SPX_NDEBUG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spx_debx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|prurequests
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sanames
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tcpstates
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|spx_trace
parameter_list|(
name|int
name|act
parameter_list|,
name|int
name|ostate
parameter_list|,
name|struct
name|spxpcb
modifier|*
name|sp
parameter_list|,
name|struct
name|spx
modifier|*
name|si
parameter_list|,
name|int
name|req
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NETIPX_SPX_DEBUG_H_ */
end_comment

end_unit

