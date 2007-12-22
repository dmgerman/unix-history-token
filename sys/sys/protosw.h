begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)protosw.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
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
name|thread
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

begin_struct_decl
struct_decl|struct
name|sockopt
struct_decl|;
end_struct_decl

begin_comment
comment|/*#ifdef _KERNEL*/
end_comment

begin_comment
comment|/*  * Protocol switch table.  *  * Each protocol has a handle initializing one of these structures,  * which is used for protocol-protocol and system-protocol communication.  *  * A protocol is called through the pr_init entry before any other.  * Thereafter it is called every 200ms through the pr_fasttimo entry and  * every 500ms through the pr_slowtimo for timer based actions.  * The system will call the pr_drain entry if it is low on space and  * this should throw away any non-critical data.  *  * Protocols pass data between themselves as chains of mbufs using  * the pr_input and pr_output hooks.  Pr_input passes data up (towards  * the users) and pr_output passes it down (towards the interfaces); control  * information passes up and down on pr_ctlinput and pr_ctloutput.  * The protocol is responsible for the space occupied by any the  * arguments to these entries and must dispose it.  *  * In retrospect, it would be a lot nicer to use an interface  * similar to the vnode VOP interface.  */
end_comment

begin_comment
comment|/* USE THESE FOR YOUR PROTOTYPES ! */
end_comment

begin_typedef
typedef|typedef
name|void
name|pr_input_t
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|pr_input6_t
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* XXX FIX THIS */
end_comment

begin_typedef
typedef|typedef
name|void
name|pr_in_input_t
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* XXX FIX THIS */
end_comment

begin_typedef
typedef|typedef
name|int
name|pr_output_t
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|pr_in_output_t
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|pr_ctlinput_t
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|pr_ctloutput_t
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|pr_init_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|pr_fasttimo_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|pr_slowtimo_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|pr_drain_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|pr_usrreq_t
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_typedef

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
name|pr_input_t
modifier|*
name|pr_input
decl_stmt|;
comment|/* input to protocol (from below) */
name|pr_output_t
modifier|*
name|pr_output
decl_stmt|;
comment|/* output to protocol (from above) */
name|pr_ctlinput_t
modifier|*
name|pr_ctlinput
decl_stmt|;
comment|/* control input (from below) */
name|pr_ctloutput_t
modifier|*
name|pr_ctloutput
decl_stmt|;
comment|/* control output (from above) */
comment|/* user-protocol hook */
name|pr_usrreq_t
modifier|*
name|pr_ousrreq
decl_stmt|;
comment|/* utility hooks */
name|pr_init_t
modifier|*
name|pr_init
decl_stmt|;
name|pr_fasttimo_t
modifier|*
name|pr_fasttimo
decl_stmt|;
comment|/* fast timeout (200ms) */
name|pr_slowtimo_t
modifier|*
name|pr_slowtimo
decl_stmt|;
comment|/* slow timeout (500ms) */
name|pr_drain_t
modifier|*
name|pr_drain
decl_stmt|;
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
comment|/*  * This number should be defined again within each protocol family to avoid  * confusion.  */
end_comment

begin_define
define|#
directive|define
name|PROTO_SPACER
value|32767
end_define

begin_comment
comment|/* spacer for loadable protocols */
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

begin_define
define|#
directive|define
name|PR_LASTHDR
value|0x40
end_define

begin_comment
comment|/* enforce ipsec policy; last header */
end_comment

begin_comment
comment|/*  * In earlier BSD network stacks, a single pr_usrreq() function pointer was  * invoked with an operation number indicating what operation was desired.  * We now provide individual function pointers which protocols can implement,  * which offers a number of benefits (such as type checking for arguments).  * These older constants are still present in order to support TCP debugging.  *  * The arguments to usrreq were:  *	(*protosw[].pr_usrreq)(up, req, m, nam, opt);  * where up is a (struct socket *), req is one of these requests,  * m is an optional mbuf chain containing a message,  * nam is an optional mbuf chain containing an address,  * and opt is a pointer to a socketopt structure or nil.  * The protocol is responsible for disposal of the mbuf chain m,  * the caller is responsible for any space held by nam and opt.  * A non-zero return from usrreq gives an  * UNIX error number which should be passed to higher level software.  */
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
name|PRU_SOSETLABEL
value|23
end_define

begin_comment
comment|/* MAC label change */
end_comment

begin_define
define|#
directive|define
name|PRU_CLOSE
value|24
end_define

begin_comment
comment|/* socket close */
end_comment

begin_define
define|#
directive|define
name|PRU_NREQ
value|24
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PRUREQUESTS
end_ifdef

begin_decl_stmt
specifier|const
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
block|,
literal|"SOSETLABEL"
block|,
literal|"CLOSE"
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
name|_KERNEL
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
comment|/*  * If the ordering here looks odd, that's because it's alphabetical.  These  * should eventually be merged back into struct protosw.  *  * Some fields initialized to defaults if they are NULL.  * See uipc_domain.c:net_init_domain()  */
end_comment

begin_struct
struct|struct
name|pr_usrreqs
block|{
name|double
name|__Break_the_struct_layout_for_now
decl_stmt|;
name|void
function_decl|(
modifier|*
name|pru_abort
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_accept
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_attach
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|proto
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_bind
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|nam
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_connect
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|nam
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_connect2
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so1
parameter_list|,
name|struct
name|socket
modifier|*
name|so2
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_control
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pru_detach
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_disconnect
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_listen
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|backlog
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_peeraddr
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_rcvd
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_rcvoob
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_send
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
define|#
directive|define
name|PRUS_OOB
value|0x1
define|#
directive|define
name|PRUS_EOF
value|0x2
define|#
directive|define
name|PRUS_MORETOCOME
value|0x4
name|int
function_decl|(
modifier|*
name|pru_sense
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_shutdown
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_sockaddr
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_sosend
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|struct
name|mbuf
modifier|*
name|top
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_soreceive
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|paddr
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp0
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|controlp
parameter_list|,
name|int
modifier|*
name|flagsp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pru_sopoll
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|events
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pru_sosetlabel
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|pru_close
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * All nonvoid pru_*() functions below return EOPNOTSUPP.  */
end_comment

begin_function_decl
name|int
name|pru_accept_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_attach_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|proto
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_bind_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|nam
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_connect_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|nam
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_connect2_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so1
parameter_list|,
name|struct
name|socket
modifier|*
name|so2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_control_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_disconnect_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_listen_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|backlog
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_peeraddr_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_rcvd_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_rcvoob_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_send_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_sense_null
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_shutdown_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_sockaddr_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|nam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_sosend_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|struct
name|mbuf
modifier|*
name|top
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_soreceive_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
name|paddr
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp0
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|controlp
parameter_list|,
name|int
modifier|*
name|flagsp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pru_sopoll_notsupp
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|events
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
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
name|PRC_UNREACH_ADMIN_PROHIB
value|21
end_define

begin_comment
comment|/* packet administrativly prohibited */
end_comment

begin_define
define|#
directive|define
name|PRC_NCMDS
value|22
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
block|,
literal|"ADMIN-UNREACH"
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
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|pfctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfctlinput2
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protosw
modifier|*
name|pffindproto
parameter_list|(
name|int
name|family
parameter_list|,
name|int
name|protocol
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protosw
modifier|*
name|pffindtype
parameter_list|(
name|int
name|family
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_proto_register
parameter_list|(
name|int
name|family
parameter_list|,
name|struct
name|protosw
modifier|*
name|npr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pf_proto_unregister
parameter_list|(
name|int
name|family
parameter_list|,
name|int
name|protocol
parameter_list|,
name|int
name|type
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

end_unit

