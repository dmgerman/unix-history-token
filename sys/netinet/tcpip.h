begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcpip.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCPIP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCPIP_H_
end_define

begin_comment
comment|/*  * Tcp+ip header, after ip options removed.  */
end_comment

begin_struct
struct|struct
name|tcpiphdr
block|{
name|struct
name|ipovly
name|ti_i
decl_stmt|;
comment|/* overlaid ip structure */
name|struct
name|tcphdr
name|ti_t
decl_stmt|;
comment|/* tcp header */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/*  * Tcp+ip header, after ip options removed but including TCP options.  */
end_comment

begin_struct
struct|struct
name|full_tcpiphdr
block|{
name|struct
name|ipovly
name|ti_i
decl_stmt|;
comment|/* overlaid ip structure */
name|struct
name|tcphdr
name|ti_t
decl_stmt|;
comment|/* tcp header */
name|char
name|ti_o
index|[
name|TCP_MAXOLEN
index|]
decl_stmt|;
comment|/* space for tcp options */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notyet */
end_comment

begin_define
define|#
directive|define
name|ti_x1
value|ti_i.ih_x1
end_define

begin_define
define|#
directive|define
name|ti_pr
value|ti_i.ih_pr
end_define

begin_define
define|#
directive|define
name|ti_len
value|ti_i.ih_len
end_define

begin_define
define|#
directive|define
name|ti_src
value|ti_i.ih_src
end_define

begin_define
define|#
directive|define
name|ti_dst
value|ti_i.ih_dst
end_define

begin_define
define|#
directive|define
name|ti_sport
value|ti_t.th_sport
end_define

begin_define
define|#
directive|define
name|ti_dport
value|ti_t.th_dport
end_define

begin_define
define|#
directive|define
name|ti_seq
value|ti_t.th_seq
end_define

begin_define
define|#
directive|define
name|ti_ack
value|ti_t.th_ack
end_define

begin_define
define|#
directive|define
name|ti_x2
value|ti_t.th_x2
end_define

begin_define
define|#
directive|define
name|ti_off
value|ti_t.th_off
end_define

begin_define
define|#
directive|define
name|ti_flags
value|ti_t.th_flags
end_define

begin_define
define|#
directive|define
name|ti_win
value|ti_t.th_win
end_define

begin_define
define|#
directive|define
name|ti_sum
value|ti_t.th_sum
end_define

begin_define
define|#
directive|define
name|ti_urp
value|ti_t.th_urp
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

