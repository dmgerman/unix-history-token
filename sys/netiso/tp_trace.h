begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tp_trace.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_TP_TRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_TP_TRACE_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * ARGO TP  *  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/tp_trace.h,v $  *  *  * Definitions needed for the protocol trace mechanism.  */
end_comment

begin_define
define|#
directive|define
name|TPPTsendack
value|1
end_define

begin_define
define|#
directive|define
name|TPPTgotack
value|2
end_define

begin_define
define|#
directive|define
name|TPPTXack
value|3
end_define

begin_define
define|#
directive|define
name|TPPTgotXack
value|4
end_define

begin_define
define|#
directive|define
name|TPPTack
value|5
end_define

begin_define
define|#
directive|define
name|TPPTindicate
value|6
end_define

begin_define
define|#
directive|define
name|TPPTusrreq
value|7
end_define

begin_define
define|#
directive|define
name|TPPTmisc
value|8
end_define

begin_define
define|#
directive|define
name|TPPTpcb
value|9
end_define

begin_define
define|#
directive|define
name|TPPTref
value|10
end_define

begin_define
define|#
directive|define
name|TPPTtpduin
value|11
end_define

begin_define
define|#
directive|define
name|TPPTparam
value|12
end_define

begin_define
define|#
directive|define
name|TPPTertpdu
value|13
end_define

begin_define
define|#
directive|define
name|TPPTdriver
value|14
end_define

begin_define
define|#
directive|define
name|TPPTtpduout
value|15
end_define

begin_include
include|#
directive|include
file|<netiso/tp_pcb.h>
end_include

begin_comment
comment|/* this #if is to avoid lint */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TP_TRACEFILE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netiso/tp_tpdu.h>
end_include

begin_define
define|#
directive|define
name|TPTRACE_STRLEN
value|50
end_define

begin_comment
comment|/* for packet tracing */
end_comment

begin_struct
struct|struct
name|tp_timeval
block|{
name|SeqNum
name|tptv_seq
decl_stmt|;
name|u_int
name|tptv_kind
decl_stmt|;
name|u_int
name|tptv_window
decl_stmt|;
name|u_int
name|tptv_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tp_Trace
block|{
name|u_int
name|tpt_event
decl_stmt|;
name|u_int
name|tpt_arg
decl_stmt|;
name|u_int
name|tpt_arg2
decl_stmt|;
name|int
name|tpt_tseq
decl_stmt|;
name|struct
name|timeval
name|tpt_time
decl_stmt|;
union|union
block|{
name|struct
name|inpcb
name|tpt_Inpcb
decl_stmt|;
comment|/* protocol control block */
name|struct
name|tp_ref
name|tpt_Ref
decl_stmt|;
comment|/* ref part of pcb */
name|struct
name|tpdu
name|tpt_Tpdu
decl_stmt|;
comment|/* header*/
name|struct
name|tp_refinfo
name|tpt_Param
decl_stmt|;
comment|/* ?? bytes, make sure< 128??*/
name|struct
name|tp_timeval
name|tpt_Time
decl_stmt|;
struct|struct
block|{
name|u_int
name|tptm_2
decl_stmt|;
name|u_int
name|tptm_3
decl_stmt|;
name|u_int
name|tptm_4
decl_stmt|;
name|u_int
name|tptm_5
decl_stmt|;
name|char
name|tpt_Str
index|[
name|TPTRACE_STRLEN
index|]
decl_stmt|;
name|u_int
name|tptm_1
decl_stmt|;
block|}
name|tptmisc
struct|;
name|u_char
name|tpt_Ertpdu
decl_stmt|;
comment|/* use rest of structure */
block|}
name|tpt_stuff
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|tpt_inpcb
value|tpt_stuff.tpt_Inpcb
end_define

begin_define
define|#
directive|define
name|tpt_pcb
value|tpt_stuff.tpt_Pcb
end_define

begin_define
define|#
directive|define
name|tpt_ref
value|tpt_stuff.tpt_Ref
end_define

begin_define
define|#
directive|define
name|tpt_tpdu
value|tpt_stuff.tpt_Tpdu
end_define

begin_define
define|#
directive|define
name|tpt_param
value|tpt_stuff.tpt_Param
end_define

begin_define
define|#
directive|define
name|tpt_ertpdu
value|tpt_stuff.tpt_Ertpdu
end_define

begin_define
define|#
directive|define
name|tpt_str
value|tpt_stuff.tptmisc.tpt_Str
end_define

begin_define
define|#
directive|define
name|tpt_m1
value|tpt_stuff.tptmisc.tptm_1
end_define

begin_define
define|#
directive|define
name|tpt_m2
value|tpt_stuff.tptmisc.tptm_2
end_define

begin_define
define|#
directive|define
name|tpt_m3
value|tpt_stuff.tptmisc.tptm_3
end_define

begin_define
define|#
directive|define
name|tpt_m4
value|tpt_stuff.tptmisc.tptm_4
end_define

begin_define
define|#
directive|define
name|tpt_m5
value|tpt_stuff.tptmisc.tptm_5
end_define

begin_define
define|#
directive|define
name|tpt_seq
value|tpt_stuff.tpt_Time.tptv_seq
end_define

begin_define
define|#
directive|define
name|tpt_kind
value|tpt_stuff.tpt_Time.tptv_kind
end_define

begin_define
define|#
directive|define
name|tpt_window
value|tpt_stuff.tpt_Time.tptv_window
end_define

begin_define
define|#
directive|define
name|tpt_size
value|tpt_stuff.tpt_Time.tptv_size
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(TP_TRACEFILE)||!defined(KERNEL) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TPPT
end_ifdef

begin_define
define|#
directive|define
name|TPTRACEN
value|300
end_define

begin_define
define|#
directive|define
name|tptrace
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|,
name|F
parameter_list|)
define|\
value|tpTrace((struct tp_pcb *)0,\ 	(u_int)(A),(u_int)(B),(u_int)(C),(u_int)(D),(u_int)(E),(u_int)(F))
end_define

begin_define
define|#
directive|define
name|tptraceTPCB
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|,
name|F
parameter_list|)
define|\
value|tpTrace(tpcb,\ 	(u_int)(A),(u_int)(B),(u_int)(C),(u_int)(D),(u_int)(E),(u_int)(F))
end_define

begin_function_decl
specifier|extern
name|void
name|tpTrace
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|tp_Trace
name|tp_Trace
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|tp_traceflags
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tp_Tracen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IFTRACE
parameter_list|(
name|ascii
parameter_list|)
define|\
value|if(tp_traceflags[ascii]) {
end_define

begin_comment
comment|/*  * for some reason lint complains about tp_param being undefined no  * matter where or how many times I define it.  */
end_comment

begin_define
define|#
directive|define
name|ENDTRACE
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* TPPT */
end_comment

begin_comment
comment|/***********************************************  * NO TPPT TRACE STUFF  **********************************************/
end_comment

begin_define
define|#
directive|define
name|TPTRACEN
value|1
end_define

begin_define
define|#
directive|define
name|tptrace
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|,
name|F
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|tptraceTPCB
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|,
name|F
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|IFTRACE
parameter_list|(
name|ascii
parameter_list|)
value|if (0) {
end_define

begin_define
define|#
directive|define
name|ENDTRACE
value|}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TPPT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

