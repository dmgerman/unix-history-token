begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)protosw.h	7.2 (Berkeley) %G%  */
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
name|int
function_decl|(
modifier|*
name|pr_input
function_decl|)
parameter_list|()
function_decl|;
comment|/* input to protocol (from below) */
name|int
function_decl|(
modifier|*
name|pr_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* output to protocol (from above) */
name|int
function_decl|(
modifier|*
name|pr_ctlinput
function_decl|)
parameter_list|()
function_decl|;
comment|/* control input (from below) */
name|int
function_decl|(
modifier|*
name|pr_ctloutput
function_decl|)
parameter_list|()
function_decl|;
comment|/* control output (from above) */
comment|/* user-protocol hook */
name|int
function_decl|(
modifier|*
name|pr_usrreq
function_decl|)
parameter_list|()
function_decl|;
comment|/* user request: see list below */
comment|/* utility hooks */
name|int
function_decl|(
modifier|*
name|pr_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* initialization hook */
name|int
function_decl|(
modifier|*
name|pr_fasttimo
function_decl|)
parameter_list|()
function_decl|;
comment|/* fast timeout (200ms) */
name|int
function_decl|(
modifier|*
name|pr_slowtimo
function_decl|)
parameter_list|()
function_decl|;
comment|/* slow timeout (500ms) */
name|int
function_decl|(
modifier|*
name|pr_drain
function_decl|)
parameter_list|()
function_decl|;
comment|/* flush any excess space possible */
block|}
struct|;
end_struct

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
comment|/*  * Values for pr_flags  */
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

begin_comment
comment|/* in the current implementation, PR_ADDR needs PR_ATOMIC to work */
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

begin_define
define|#
directive|define
name|PRU_NREQ
value|21
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
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The arguments to the ctlinput routine are  *	(*protosw[].pr_ctlinput)(cmd, arg);  * where cmd is one of the commands below, and arg is  * an optional argument (caddr_t).  *  * N.B. The IMP code, in particular, pressumes the values  *      of some of the commands; change with extreme care.  * TODO:  *	spread out codes so new ICMP codes can be  *	accomodated more easily  */
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
comment|/* select new route if possible */
end_comment

begin_define
define|#
directive|define
name|PRC_QUENCH
value|4
end_define

begin_comment
comment|/* some said to slow down */
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
comment|/* normally from IMP */
end_comment

begin_define
define|#
directive|define
name|PRC_HOSTUNREACH
value|7
end_define

begin_comment
comment|/* ditto */
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

begin_define
define|#
directive|define
name|PRC_UNREACH_NEEDFRAG
value|12
end_define

begin_comment
comment|/* IP_DF caused drop */
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
literal|"#2"
block|,
literal|"#3"
block|,
literal|"QUENCH"
block|,
literal|"MSGSIZE"
block|,
literal|"HOSTDEAD"
block|,
literal|"HOSTUNREACH"
block|,
literal|"NET-UNREACH"
block|,
literal|"HOST-UNREACH"
block|,
literal|"PROTO-UNREACH"
block|,
literal|"PORT-UNREACH"
block|,
literal|"FRAG-UNREACH"
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
comment|/*  * The arguments to ctloutput are:  *	(*protosw[].pr_ctloutput)(req, so, level, optname, optval);  * req is one of the actions listed below, so is a (struct socket *),  * level is an indication of which protocol layer the option is intended.  * optname is a protocol dependent socket option request,  * optval is a pointer to a mbuf-chain pointer, for value-return results.  * The protocol is responsible for disposal of the mbuf chain *optval  * if supplied,  * the caller is responsible for any space held by *optval, when returned.  * A non-zero return from usrreq gives an  * UNIX error number which should be passed to higher level software.  */
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
specifier|extern
name|struct
name|protosw
modifier|*
name|pffindproto
argument_list|()
decl_stmt|,
modifier|*
name|pffindtype
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

