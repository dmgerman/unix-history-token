begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)protosw.h	8.1 (Berkeley) 6/2/93  *	$Id: protosw.h,v 1.22 1997/12/21 16:35:10 bde Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PROTOSW_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PROTOSW_H_
end_define

begin_comment
comment|/* Forward declare these structures referenced from prototypes below. */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_comment
comment|/*#ifdef KERNEL*/
end_comment

begin_comment
comment|/*  * Protocol switch table.  *  * Each protocol has a handle initializing one of these structures,  * which is used for protocol-protocol and system-protocol communication.  *  * A protocol is called through the pr_init entry before any other.  * Thereafter it is called every 200ms through the pr_fasttimo entry and  * every 500ms through the pr_slowtimo for timer based actions.  * The system will call the pr_drain entry if it is low on space and  * this should throw away any non-critical data.  *  * Protocols pass data between themselves as chains of mbufs using  * the pr_input and pr_output hooks.  Pr_input passes data up (towards  * UNIX) and pr_output passes it down (towards the imps); control  * information passes up and down on pr_ctlinput and pr_ctloutput.  * The protocol is responsible for the space occupied by any the  * arguments to these entries and must dispose it.  *  * The userreq routine interfaces protocols to the system and is  * described below.  */
end_comment

begin_struct
struct|struct
name|protosw
block|{
name|short
name|pr_type
decl_stmt|;
comment|/* socket type used for */
name|struct
name|domain
modifier|*
name|pr_domain
decl_stmt|;
comment|/* domain protocol a member of */
name|short
name|pr_protocol
decl_stmt|;
comment|/* protocol number */
name|short
name|pr_flags
decl_stmt|;
comment|/* see below */
comment|/* protocol-protocol hooks */
name|void
argument_list|(
argument|*pr_input
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
name|len
operator|)
argument_list|)
expr_stmt|;
comment|/* input to protocol (from below) */
name|int
argument_list|(
argument|*pr_output
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
name|m
operator|,
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
expr_stmt|;
comment|/* output to protocol (from above) */
name|void
argument_list|(
argument|*pr_ctlinput
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* control input (from below) */
name|int
argument_list|(
argument|*pr_ctloutput
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|socket
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* control output (from above) */
comment|/* user-protocol hook */
name|void
modifier|*
name|pr_ousrreq
decl_stmt|;
comment|/* utility hooks */
name|void
argument_list|(
argument|*pr_init
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* initialization hook */
name|void
argument_list|(
argument|*pr_fasttimo
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* fast timeout (200ms) */
name|void
argument_list|(
argument|*pr_slowtimo
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* slow timeout (500ms) */
name|void
argument_list|(
argument|*pr_drain
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* flush any excess space possible */
name|struct
name|pr_usrreqs
modifier|*
name|pr_usrreqs
decl_stmt|;
comment|/* supersedes pr_usrreq() */
block|}
struct|;
end_struct

begin_comment
comment|/*#endif*/
end_comment

begin_define
define|#
directive|define
name|PR_SLOWHZ
value|2
end_define

begin_comment
comment|/* 2 slow timeouts per second */
end_comment

begin_define
define|#
directive|define
name|PR_FASTHZ
value|5
end_define

begin_comment
comment|/* 5 fast timeouts per second */
end_comment

begin_comment
comment|/*  * Values for pr_flags.  * PR_ADDR requires PR_ATOMIC;  * PR_ADDR and PR_CONNREQUIRED are mutually exclusive.  * PR_IMPLOPCL means that the protocol allows sendto without prior connect,  *	and the protocol understands the MSG_EOF flag.  The first property is  *	is only relevant if PR_CONNREQUIRED is set (otherwise sendto is allowed  *	anyhow).  */
end_comment

begin_define
define|#
directive|define
name|PR_ATOMIC
value|0x01
end_define

begin_comment
comment|/* exchange atomic messages only */
end_comment

begin_define
define|#
directive|define
name|PR_ADDR
value|0x02
end_define

begin_comment
comment|/* addresses given with messages */
end_comment

begin_define
define|#
directive|define
name|PR_CONNREQUIRED
value|0x04
end_define

begin_comment
comment|/* connection required by protocol */
end_comment

begin_define
define|#
directive|define
name|PR_WANTRCVD
value|0x08
end_define

begin_comment
comment|/* want PRU_RCVD calls */
end_comment

begin_define
define|#
directive|define
name|PR_RIGHTS
value|0x10
end_define

begin_comment
comment|/* passes capabilities */
end_comment

begin_define
define|#
directive|define
name|PR_IMPLOPCL
value|0x20
end_define

begin_comment
comment|/* implied open/close */
end_comment

begin_comment
comment|/*  * The arguments to usrreq are:  *	(*protosw[].pr_usrreq)(up, req, m, nam, opt);  * where up is a (struct socket *), req is one of these requests,  * m is a optional mbuf chain containing a message,  * nam is an optional mbuf chain containing an address,  * and opt is a pointer to a socketopt structure or nil.  * The protocol is responsible for disposal of the mbuf chain m,  * the caller is responsible for any space held by nam and opt.  * A non-zero return from usrreq gives an  * UNIX error number which should be passed to higher level software.  */
end_comment

begin_define
define|#
directive|define
name|PRU_ATTACH
value|0
end_define

begin_comment
comment|/* attach protocol to up */
end_comment

begin_define
define|#
directive|define
name|PRU_DETACH
value|1
end_define

begin_comment
comment|/* detach protocol from up */
end_comment

begin_define
define|#
directive|define
name|PRU_BIND
value|2
end_define

begin_comment
comment|/* bind socket to address */
end_comment

begin_define
define|#
directive|define
name|PRU_LISTEN
value|3
end_define

begin_comment
comment|/* listen for connection */
end_comment

begin_define
define|#
directive|define
name|PRU_CONNECT
value|4
end_define

begin_comment
comment|/* establish connection to peer */
end_comment

begin_define
define|#
directive|define
name|PRU_ACCEPT
value|5
end_define

begin_comment
comment|/* accept connection from peer */
end_comment

begin_define
define|#
directive|define
name|PRU_DISCONNECT
value|6
end_define

begin_comment
comment|/* disconnect from peer */
end_comment

begin_define
define|#
directive|define
name|PRU_SHUTDOWN
value|7
end_define

begin_comment
comment|/* won't send any more data */
end_comment

begin_define
define|#
directive|define
name|PRU_RCVD
value|8
end_define

begin_comment
comment|/* have taken data; more room now */
end_comment

begin_define
define|#
directive|define
name|PRU_SEND
value|9
end_define

begin_comment
comment|/* send this data */
end_comment

begin_define
define|#
directive|define
name|PRU_ABORT
value|10
end_define

begin_comment
comment|/* abort (fast DISCONNECT, DETATCH) */
end_comment

begin_define
define|#
directive|define
name|PRU_CONTROL
value|11
end_define

begin_comment
comment|/* control operations on protocol */
end_comment

begin_define
define|#
directive|define
name|PRU_SENSE
value|12
end_define

begin_comment
comment|/* return status into m */
end_comment

begin_define
define|#
directive|define
name|PRU_RCVOOB
value|13
end_define

begin_comment
comment|/* retrieve out of band data */
end_comment

begin_define
define|#
directive|define
name|PRU_SENDOOB
value|14
end_define

begin_comment
comment|/* send out of band data */
end_comment

begin_define
define|#
directive|define
name|PRU_SOCKADDR
value|15
end_define

begin_comment
comment|/* fetch socket's address */
end_comment

begin_define
define|#
directive|define
name|PRU_PEERADDR
value|16
end_define

begin_comment
comment|/* fetch peer's address */
end_comment

begin_define
define|#
directive|define
name|PRU_CONNECT2
value|17
end_define

begin_comment
comment|/* connect two sockets */
end_comment

begin_comment
comment|/* begin for protocols internal use */
end_comment

begin_define
define|#
directive|define
name|PRU_FASTTIMO
value|18
end_define

begin_comment
comment|/* 200ms timeout */
end_comment

begin_define
define|#
directive|define
name|PRU_SLOWTIMO
value|19
end_define

begin_comment
comment|/* 500ms timeout */
end_comment

begin_define
define|#
directive|define
name|PRU_PROTORCV
value|20
end_define

begin_comment
comment|/* receive from below */
end_comment

begin_define
define|#
directive|define
name|PRU_PROTOSEND
value|21
end_define

begin_comment
comment|/* send to below */
end_comment

begin_comment
comment|/* end for protocol's internal use */
end_comment

begin_define
define|#
directive|define
name|PRU_SEND_EOF
value|22
end_define

begin_comment
comment|/* send and close */
end_comment

begin_define
define|#
directive|define
name|PRU_NREQ
value|22
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PRUREQUESTS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|prurequests
index|[]
init|=
block|{
literal|"ATTACH"
block|,
literal|"DETACH"
block|,
literal|"BIND"
block|,
literal|"LISTEN"
block|,
literal|"CONNECT"
block|,
literal|"ACCEPT"
block|,
literal|"DISCONNECT"
block|,
literal|"SHUTDOWN"
block|,
literal|"RCVD"
block|,
literal|"SEND"
block|,
literal|"ABORT"
block|,
literal|"CONTROL"
block|,
literal|"SENSE"
block|,
literal|"RCVOOB"
block|,
literal|"SENDOOB"
block|,
literal|"SOCKADDR"
block|,
literal|"PEERADDR"
block|,
literal|"CONNECT2"
block|,
literal|"FASTTIMO"
block|,
literal|"SLOWTIMO"
block|,
literal|"PROTORCV"
block|,
literal|"PROTOSEND"
block|,
literal|"SEND_EOF"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* users shouldn't see this decl */
end_comment

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * If the ordering here looks odd, that's because it's alphabetical.  * Having this structure separated out from the main protoswitch is allegedly  * a big (12 cycles per call) lose on high-end CPUs.  We will eventually  * migrate this stuff back into the main structure.  */
end_comment

begin_struct
struct|struct
name|pr_usrreqs
block|{
name|int
argument_list|(
argument|*pru_abort
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_accept
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_attach
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|proto
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_bind
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
name|nam
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_connect
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
name|nam
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_connect2
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so1
operator|,
expr|struct
name|socket
operator|*
name|so2
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_control
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|cmd
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_detach
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_disconnect
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_listen
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_peeraddr
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_rcvd
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|flags
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_rcvoob
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|,
name|int
name|flags
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_send
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|flags
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|,
expr|struct
name|sockaddr
operator|*
name|addr
operator|,
expr|struct
name|mbuf
operator|*
name|control
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|PRUS_OOB
value|0x1
define|#
directive|define
name|PRUS_EOF
value|0x2
name|int
argument_list|(
argument|*pru_sense
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|stat
operator|*
name|sb
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_shutdown
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_sockaddr
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
expr_stmt|;
comment|/* 	 * These three added later, so they are out of order.  They are used 	 * for shortcutting (fast path input/output) in some protocols. 	 * XXX - that's a lie, they are not implemented yet 	 * Rather than calling sosend() etc. directly, calls are made 	 * through these entry points.  For protocols which still use 	 * the generic code, these just point to those routines. 	 */
name|int
argument_list|(
argument|*pru_sosend
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
name|addr
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|mbuf
operator|*
name|top
operator|,
expr|struct
name|mbuf
operator|*
name|control
operator|,
name|int
name|flags
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_soreceive
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|paddr
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mp0
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|controlp
operator|,
name|int
operator|*
name|flagsp
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*pru_sopoll
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|events
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|pru_accept_notsupp
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pru_connect_notsupp
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
name|nam
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pru_connect2_notsupp
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so1
operator|,
expr|struct
name|socket
operator|*
name|so2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pru_control_notsupp
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|cmd
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|ifnet
operator|*
name|ifp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pru_listen_notsupp
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pru_rcvd_notsupp
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pru_rcvoob_notsupp
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pru_sense_null
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|stat
operator|*
name|sb
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

begin_comment
comment|/*  * The arguments to the ctlinput routine are  *	(*protosw[].pr_ctlinput)(cmd, sa, arg);  * where cmd is one of the commands below, sa is a pointer to a sockaddr,  * and arg is a `void *' argument used within a protocol family.  */
end_comment

begin_define
define|#
directive|define
name|PRC_IFDOWN
value|0
end_define

begin_comment
comment|/* interface transition */
end_comment

begin_define
define|#
directive|define
name|PRC_ROUTEDEAD
value|1
end_define

begin_comment
comment|/* select new route if possible ??? */
end_comment

begin_define
define|#
directive|define
name|PRC_IFUP
value|2
end_define

begin_comment
comment|/* interface has come back up */
end_comment

begin_define
define|#
directive|define
name|PRC_QUENCH2
value|3
end_define

begin_comment
comment|/* DEC congestion bit says slow down */
end_comment

begin_define
define|#
directive|define
name|PRC_QUENCH
value|4
end_define

begin_comment
comment|/* some one said to slow down */
end_comment

begin_define
define|#
directive|define
name|PRC_MSGSIZE
value|5
end_define

begin_comment
comment|/* message size forced drop */
end_comment

begin_define
define|#
directive|define
name|PRC_HOSTDEAD
value|6
end_define

begin_comment
comment|/* host appears to be down */
end_comment

begin_define
define|#
directive|define
name|PRC_HOSTUNREACH
value|7
end_define

begin_comment
comment|/* deprecated (use PRC_UNREACH_HOST) */
end_comment

begin_define
define|#
directive|define
name|PRC_UNREACH_NET
value|8
end_define

begin_comment
comment|/* no route to network */
end_comment

begin_define
define|#
directive|define
name|PRC_UNREACH_HOST
value|9
end_define

begin_comment
comment|/* no route to host */
end_comment

begin_define
define|#
directive|define
name|PRC_UNREACH_PROTOCOL
value|10
end_define

begin_comment
comment|/* dst says bad protocol */
end_comment

begin_define
define|#
directive|define
name|PRC_UNREACH_PORT
value|11
end_define

begin_comment
comment|/* bad port # */
end_comment

begin_comment
comment|/* was	PRC_UNREACH_NEEDFRAG	12	   (use PRC_MSGSIZE) */
end_comment

begin_define
define|#
directive|define
name|PRC_UNREACH_SRCFAIL
value|13
end_define

begin_comment
comment|/* source route failed */
end_comment

begin_define
define|#
directive|define
name|PRC_REDIRECT_NET
value|14
end_define

begin_comment
comment|/* net routing redirect */
end_comment

begin_define
define|#
directive|define
name|PRC_REDIRECT_HOST
value|15
end_define

begin_comment
comment|/* host routing redirect */
end_comment

begin_define
define|#
directive|define
name|PRC_REDIRECT_TOSNET
value|16
end_define

begin_comment
comment|/* redirect for type of service& net */
end_comment

begin_define
define|#
directive|define
name|PRC_REDIRECT_TOSHOST
value|17
end_define

begin_comment
comment|/* redirect for tos& host */
end_comment

begin_define
define|#
directive|define
name|PRC_TIMXCEED_INTRANS
value|18
end_define

begin_comment
comment|/* packet lifetime expired in transit */
end_comment

begin_define
define|#
directive|define
name|PRC_TIMXCEED_REASS
value|19
end_define

begin_comment
comment|/* lifetime expired on reass q */
end_comment

begin_define
define|#
directive|define
name|PRC_PARAMPROB
value|20
end_define

begin_comment
comment|/* header incorrect */
end_comment

begin_define
define|#
directive|define
name|PRC_NCMDS
value|21
end_define

begin_define
define|#
directive|define
name|PRC_IS_REDIRECT
parameter_list|(
name|cmd
parameter_list|)
define|\
value|((cmd)>= PRC_REDIRECT_NET&& (cmd)<= PRC_REDIRECT_TOSHOST)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PRCREQUESTS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|prcrequests
index|[]
init|=
block|{
literal|"IFDOWN"
block|,
literal|"ROUTEDEAD"
block|,
literal|"IFUP"
block|,
literal|"DEC-BIT-QUENCH2"
block|,
literal|"QUENCH"
block|,
literal|"MSGSIZE"
block|,
literal|"HOSTDEAD"
block|,
literal|"#7"
block|,
literal|"NET-UNREACH"
block|,
literal|"HOST-UNREACH"
block|,
literal|"PROTO-UNREACH"
block|,
literal|"PORT-UNREACH"
block|,
literal|"#12"
block|,
literal|"SRCFAIL-UNREACH"
block|,
literal|"NET-REDIRECT"
block|,
literal|"HOST-REDIRECT"
block|,
literal|"TOSNET-REDIRECT"
block|,
literal|"TOSHOST-REDIRECT"
block|,
literal|"TX-INTRANS"
block|,
literal|"TX-REASS"
block|,
literal|"PARAMPROB"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The arguments to ctloutput are:  *	(*protosw[].pr_ctloutput)(req, so, level, optname, optval, p);  * req is one of the actions listed below, so is a (struct socket *),  * level is an indication of which protocol layer the option is intended.  * optname is a protocol dependent socket option request,  * optval is a pointer to a mbuf-chain pointer, for value-return results.  * The protocol is responsible for disposal of the mbuf chain *optval  * if supplied,  * the caller is responsible for any space held by *optval, when returned.  * A non-zero return from usrreq gives an  * UNIX error number which should be passed to higher level software.  */
end_comment

begin_define
define|#
directive|define
name|PRCO_GETOPT
value|0
end_define

begin_define
define|#
directive|define
name|PRCO_SETOPT
value|1
end_define

begin_define
define|#
directive|define
name|PRCO_NCMDS
value|2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PRCOREQUESTS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|prcorequests
index|[]
init|=
block|{
literal|"GETOPT"
block|,
literal|"SETOPT"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|pfctlinput
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sockaddr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|protosw
modifier|*
name|pffindproto
name|__P
argument_list|(
operator|(
name|int
name|family
operator|,
name|int
name|protocol
operator|,
name|int
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|protosw
modifier|*
name|pffindtype
name|__P
argument_list|(
operator|(
name|int
name|family
operator|,
name|int
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

