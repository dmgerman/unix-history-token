begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)in_proto.c	7.5 (Berkeley) 6/28/90  *	$Id: in_proto.c,v 1.3 1993/12/19 00:52:38 wollman Exp $  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"socket.h"
end_include

begin_include
include|#
directive|include
file|"protosw.h"
end_include

begin_include
include|#
directive|include
file|"domain.h"
end_include

begin_include
include|#
directive|include
file|"mbuf.h"
end_include

begin_include
include|#
directive|include
file|"net/if.h"
end_include

begin_include
include|#
directive|include
file|"net/route.h"
end_include

begin_include
include|#
directive|include
file|"in.h"
end_include

begin_include
include|#
directive|include
file|"in_systm.h"
end_include

begin_include
include|#
directive|include
file|"in_var.h"
end_include

begin_comment
comment|/* IP prototypes */
end_comment

begin_include
include|#
directive|include
file|"ip.h"
end_include

begin_include
include|#
directive|include
file|"ip_var.h"
end_include

begin_comment
comment|/* more IP prototypes */
end_comment

begin_include
include|#
directive|include
file|"ip_icmp.h"
end_include

begin_include
include|#
directive|include
file|"icmp_var.h"
end_include

begin_comment
comment|/* ICMP prototypes */
end_comment

begin_include
include|#
directive|include
file|"udp.h"
end_include

begin_include
include|#
directive|include
file|"udp_var.h"
end_include

begin_comment
comment|/* UDP prototypes */
end_comment

begin_include
include|#
directive|include
file|"igmp.h"
end_include

begin_include
include|#
directive|include
file|"igmp_var.h"
end_include

begin_comment
comment|/* IGMP prototypes */
end_comment

begin_include
include|#
directive|include
file|"tcp.h"
end_include

begin_include
include|#
directive|include
file|"tcp_fsm.h"
end_include

begin_include
include|#
directive|include
file|"tcp_seq.h"
end_include

begin_include
include|#
directive|include
file|"tcp_timer.h"
end_include

begin_include
include|#
directive|include
file|"tcp_var.h"
end_include

begin_comment
comment|/* TCP prototypes */
end_comment

begin_comment
comment|/*  * TCP/IP protocol family: IP, ICMP, UDP, TCP.  */
end_comment

begin_decl_stmt
name|in_output_t
name|ip_output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|in_ctloutput_t
name|ip_ctloutput
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ip_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_slowtimo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ip_drain
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|in_input_t
name|udp_input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|in_ctlinput_t
name|udp_ctlinput
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|udp_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|udp_init
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|in_input_t
name|tcp_input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|in_ctlinput_t
name|tcp_ctlinput
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|tcp_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|in_ctloutput_t
name|tcp_ctloutput
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|tcp_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_fasttimo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_slowtimo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcp_drain
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|in_input_t
name|rip_input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|in_output_t
name|rip_output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|in_ctloutput_t
name|rip_ctloutput
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|rip_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * IMP protocol family: raw interface.  * Using the raw interface entry to get the timer routine  * in is a kludge.  */
end_comment

begin_include
include|#
directive|include
file|"imp.h"
end_include

begin_if
if|#
directive|if
name|NIMP
operator|>
literal|0
end_if

begin_function_decl
name|int
name|rimp_output
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hostslowtimo
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NSIP
end_ifdef

begin_decl_stmt
name|in_input_t
name|idpip_input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|in_ctlinput_t
name|nsip_ctlinput
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TPIP
end_ifdef

begin_decl_stmt
name|in_input_t
name|tpip_input
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|in_ctlinput_t
name|tpip_ctlinput
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|in_ctloutput_t
name|tp_ctloutput
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|tp_usrreq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tp_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tp_slowtimo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tp_drain
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EON
end_ifdef

begin_decl_stmt
name|in_input_t
name|eoninput
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|in_ctlinput_t
name|eonctlinput
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|eonprotoinit
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EON */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|inetdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|in_protosw
name|inetsw
index|[]
init|=
block|{
block|{
literal|0
block|,
operator|&
name|inetdomain
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|ip_output
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|ip_init
block|,
literal|0
block|,
name|ip_slowtimo
block|,
name|ip_drain
block|, }
block|,
block|{
name|SOCK_DGRAM
block|,
operator|&
name|inetdomain
block|,
name|IPPROTO_UDP
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|udp_input
block|,
literal|0
block|,
name|udp_ctlinput
block|,
name|ip_ctloutput
block|,
name|udp_usrreq
block|,
name|udp_init
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|,
block|{
name|SOCK_STREAM
block|,
operator|&
name|inetdomain
block|,
name|IPPROTO_TCP
block|,
name|PR_CONNREQUIRED
operator||
name|PR_WANTRCVD
block|,
name|tcp_input
block|,
literal|0
block|,
name|tcp_ctlinput
block|,
name|tcp_ctloutput
block|,
name|tcp_usrreq
block|,
name|tcp_init
block|,
name|tcp_fasttimo
block|,
name|tcp_slowtimo
block|,
name|tcp_drain
block|, }
block|,
block|{
name|SOCK_RAW
block|,
operator|&
name|inetdomain
block|,
name|IPPROTO_RAW
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|rip_input
block|,
name|rip_output
block|,
literal|0
block|,
name|rip_ctloutput
block|,
name|rip_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|,
block|{
name|SOCK_RAW
block|,
operator|&
name|inetdomain
block|,
name|IPPROTO_ICMP
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|icmp_input
block|,
name|rip_output
block|,
literal|0
block|,
name|rip_ctloutput
block|,
name|rip_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|,
ifdef|#
directive|ifdef
name|TPIP
block|{
name|SOCK_SEQPACKET
block|,
operator|&
name|inetdomain
block|,
name|IPPROTO_TP
block|,
name|PR_CONNREQUIRED
operator||
name|PR_WANTRCVD
block|,
name|tpip_input
block|,
literal|0
block|,
name|tpip_ctlinput
block|,
name|tp_ctloutput
block|,
name|tp_usrreq
block|,
name|tp_init
block|,
literal|0
block|,
name|tp_slowtimo
block|,
name|tp_drain
block|, }
block|,
endif|#
directive|endif
comment|/* EON (ISO CLNL over IP) */
ifdef|#
directive|ifdef
name|EON
block|{
name|SOCK_RAW
block|,
operator|&
name|inetdomain
block|,
name|IPPROTO_EON
block|,
literal|0
block|,
name|eoninput
block|,
literal|0
block|,
name|eonctlinput
block|,
literal|0
block|,
literal|0
block|,
name|eonprotoinit
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MULTICAST
block|{
name|SOCK_RAW
block|,
operator|&
name|inetdomain
block|,
name|IPPROTO_IGMP
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|igmp_input
block|,
name|rip_output
block|,
literal|0
block|,
name|rip_ctloutput
block|,
name|rip_usrreq
block|,
name|igmp_init
block|,
name|igmp_fasttimo
block|,
literal|0
block|,
literal|0
block|, }
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NSIP
block|{
name|SOCK_RAW
block|,
operator|&
name|inetdomain
block|,
name|IPPROTO_IDP
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|idpip_input
block|,
name|rip_output
block|,
name|nsip_ctlinput
block|,
literal|0
block|,
name|rip_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|,
endif|#
directive|endif
comment|/* raw wildcard */
block|{
name|SOCK_RAW
block|,
operator|&
name|inetdomain
block|,
literal|0
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
name|rip_input
block|,
name|rip_output
block|,
literal|0
block|,
name|rip_ctloutput
block|,
name|rip_usrreq
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|, }
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|inetdomain
init|=
block|{
name|AF_INET
block|,
literal|"internet"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|(
expr|struct
name|protosw
operator|*
operator|)
name|inetsw
block|,
operator|(
expr|struct
name|protosw
operator|*
operator|)
operator|&
name|inetsw
index|[
sizeof|sizeof
argument_list|(
name|inetsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|inetsw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|NIMP
operator|>
literal|0
end_if

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|impdomain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|protosw
name|impsw
index|[]
init|=
block|{
block|{
name|SOCK_RAW
block|,
operator|&
name|impdomain
block|,
literal|0
block|,
name|PR_ATOMIC
operator||
name|PR_ADDR
block|,
literal|0
block|,
name|rimp_output
block|,
literal|0
block|,
literal|0
block|,
name|rip_usrreq
block|,
literal|0
block|,
literal|0
block|,
name|hostslowtimo
block|,
literal|0
block|, }
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|domain
name|impdomain
init|=
block|{
name|AF_IMPLINK
block|,
literal|"imp"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|impsw
block|,
operator|&
name|impsw
index|[
sizeof|sizeof
argument_list|(
name|impsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|impsw
index|[
literal|0
index|]
argument_list|)
index|]
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

