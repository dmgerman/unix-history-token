begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	protosw.h	4.9	81/12/21	*/
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
name|short
name|pr_family
decl_stmt|;
comment|/* protocol family */
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

begin_comment
comment|/*  * The arguments to usrreq are:  *	(*protosw[].pr_usrreq)(up, req, m, addr);  * where up is a (struct socket *), req is one of these requests,  * m is a optional mbuf chain, and addr is an optional meta-internetwork  * address representation.  The protocol is responsible for  * disposal of the mbuf chain.  A non-zero return from usrreq gives an  * UNIX error number which should be passed to higher level software.  */
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
name|PRU_CONNECT
value|2
end_define

begin_comment
comment|/* establish connection to peer */
end_comment

begin_define
define|#
directive|define
name|PRU_ACCEPT
value|3
end_define

begin_comment
comment|/* accept connection from peer */
end_comment

begin_define
define|#
directive|define
name|PRU_DISCONNECT
value|4
end_define

begin_comment
comment|/* disconnect from peer */
end_comment

begin_define
define|#
directive|define
name|PRU_SHUTDOWN
value|5
end_define

begin_comment
comment|/* won't send any more data */
end_comment

begin_define
define|#
directive|define
name|PRU_RCVD
value|6
end_define

begin_comment
comment|/* have taken data; more room now */
end_comment

begin_define
define|#
directive|define
name|PRU_SEND
value|7
end_define

begin_comment
comment|/* send this data */
end_comment

begin_define
define|#
directive|define
name|PRU_ABORT
value|8
end_define

begin_comment
comment|/* abort (fast DISCONNECT, DETATCH) */
end_comment

begin_define
define|#
directive|define
name|PRU_CONTROL
value|9
end_define

begin_comment
comment|/* control operations on protocol */
end_comment

begin_define
define|#
directive|define
name|PRU_SENSE
value|10
end_define

begin_comment
comment|/* return status into m */
end_comment

begin_define
define|#
directive|define
name|PRU_RCVOOB
value|11
end_define

begin_comment
comment|/* retrieve out of band data */
end_comment

begin_define
define|#
directive|define
name|PRU_SENDOOB
value|12
end_define

begin_comment
comment|/* send out of band data */
end_comment

begin_comment
comment|/* begin for protocols internal use */
end_comment

begin_define
define|#
directive|define
name|PRU_FASTTIMO
value|13
end_define

begin_comment
comment|/* 200ms timeout */
end_comment

begin_define
define|#
directive|define
name|PRU_SLOWTIMO
value|14
end_define

begin_comment
comment|/* 500ms timeout */
end_comment

begin_define
define|#
directive|define
name|PRU_PROTORCV
value|15
end_define

begin_comment
comment|/* receive from below */
end_comment

begin_define
define|#
directive|define
name|PRU_PROTOSEND
value|16
end_define

begin_comment
comment|/* send to below */
end_comment

begin_comment
comment|/* need some stuff for splice */
end_comment

begin_define
define|#
directive|define
name|PRU_NREQ
value|17
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|protosw
name|protosw
index|[]
decl_stmt|,
modifier|*
name|protoswLAST
decl_stmt|;
end_decl_stmt

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

