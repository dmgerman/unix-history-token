begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_slvar.h	8.3 (Berkeley) 2/1/94  *  * $Id$  */
end_comment

begin_comment
comment|/*  * Definitions for SLIP interface data structures  *   * (This exists so programs like slstats can get at the definition  *  of sl_softc.)  */
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
comment|/* number of abort esacpe chars */
name|long
name|sc_starttime
decl_stmt|;
comment|/* time of first abort in window */
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
name|caddr_t
name|sc_bpf
decl_stmt|;
comment|/* BPF data */
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
comment|/* supress ICMP traffic */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|slattach
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|slclose
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|slinput
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|tty
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|slioctl
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|slopen
name|__P
argument_list|(
operator|(
name|dev_t
operator|,
expr|struct
name|tty
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sloutput
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|slstart
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sltioctl
name|__P
argument_list|(
operator|(
expr|struct
name|tty
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

