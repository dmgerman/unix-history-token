begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp_debug.h	8.1 (Berkeley) 6/10/93  * $Id$  */
end_comment

begin_struct
struct|struct
name|tcp_debug
block|{
name|n_time
name|td_time
decl_stmt|;
name|short
name|td_act
decl_stmt|;
name|short
name|td_ostate
decl_stmt|;
name|caddr_t
name|td_tcb
decl_stmt|;
name|struct
name|tcpiphdr
name|td_ti
decl_stmt|;
name|short
name|td_req
decl_stmt|;
name|struct
name|tcpcb
name|td_cb
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TA_INPUT
value|0
end_define

begin_define
define|#
directive|define
name|TA_OUTPUT
value|1
end_define

begin_define
define|#
directive|define
name|TA_USER
value|2
end_define

begin_define
define|#
directive|define
name|TA_RESPOND
value|3
end_define

begin_define
define|#
directive|define
name|TA_DROP
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TANAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|tanames
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
name|TCP_NDEBUG
value|100
end_define

begin_decl_stmt
name|struct
name|tcp_debug
name|tcp_debug
index|[
name|TCP_NDEBUG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp_debx
decl_stmt|;
end_decl_stmt

end_unit

