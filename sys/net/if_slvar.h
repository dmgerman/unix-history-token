begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_slvar.h	8.3 (Berkeley) 2/1/94  *  * $Id: if_slvar.h,v 1.13 1997/02/22 09:41:06 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_SLVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_SLVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_comment
comment|/*  * Definitions for SLIP interface data structures  *  * (This exists so programs like slstats can get at the definition  *  of sl_softc.)  */
end_comment

begin_struct
struct|struct
name|sl_softc
block|{
name|struct
name|ifnet
name|sc_if
decl_stmt|;
comment|/* network-visible interface */
name|struct
name|ifqueue
name|sc_fastq
decl_stmt|;
comment|/* interactive output queue */
name|struct
name|tty
modifier|*
name|sc_ttyp
decl_stmt|;
comment|/* pointer to tty structure */
name|u_char
modifier|*
name|sc_mp
decl_stmt|;
comment|/* pointer to next available buf char */
name|u_char
modifier|*
name|sc_ep
decl_stmt|;
comment|/* pointer to last available buf char */
name|u_char
modifier|*
name|sc_buf
decl_stmt|;
comment|/* input buffer */
name|u_int
name|sc_flags
decl_stmt|;
comment|/* see below */
name|u_int
name|sc_escape
decl_stmt|;
comment|/* =1 if last char input was FRAME_ESCAPE */
name|long
name|sc_lasttime
decl_stmt|;
comment|/* last time a char arrived */
name|long
name|sc_abortcount
decl_stmt|;
comment|/* number of abort escape chars */
name|long
name|sc_starttime
decl_stmt|;
comment|/* time of first abort in window */
name|u_int
name|sc_keepalive
decl_stmt|;
comment|/* time	to decide link hang */
name|u_int
name|sc_outfill
decl_stmt|;
comment|/* time	to send	FRAME_END when output idle */
comment|/* 					 * Handles for scheduling outfill and 					 * keepalive timeouts. 					 */
name|struct
name|callout_handle
name|sc_ofhandle
decl_stmt|;
name|struct
name|callout_handle
name|sc_kahandle
decl_stmt|;
ifdef|#
directive|ifdef
name|INET
comment|/* XXX */
name|struct
name|slcompress
name|sc_comp
decl_stmt|;
comment|/* tcp compression data */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* internal flags */
end_comment

begin_define
define|#
directive|define
name|SC_ERROR
value|0x0001
end_define

begin_comment
comment|/* had an input error */
end_comment

begin_define
define|#
directive|define
name|SC_OUTWAIT
value|0x0002
end_define

begin_comment
comment|/* waiting for output fill */
end_comment

begin_define
define|#
directive|define
name|SC_KEEPALIVE
value|0x0004
end_define

begin_comment
comment|/* input keepalive */
end_comment

begin_define
define|#
directive|define
name|SC_STATIC
value|0x0008
end_define

begin_comment
comment|/* it is static unit */
end_comment

begin_comment
comment|/* visible flags */
end_comment

begin_define
define|#
directive|define
name|SC_COMPRESS
value|IFF_LINK0
end_define

begin_comment
comment|/* compress TCP traffic */
end_comment

begin_define
define|#
directive|define
name|SC_NOICMP
value|IFF_LINK1
end_define

begin_comment
comment|/* suppress ICMP traffic */
end_comment

begin_define
define|#
directive|define
name|SC_AUTOCOMP
value|IFF_LINK2
end_define

begin_comment
comment|/* auto-enable TCP compression */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

