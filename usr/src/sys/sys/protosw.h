begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	protosw.h	4.1	81/11/07	*/
end_comment

begin_comment
comment|/*  * Protocol switch table.  *  * Each protocol has a handle initializing one of these structures,  * which is used for protocol-protocol and system-protocol communication.  *  * Protocols pass data between themselves as chains of mbufs using  * the pr_input and pr_output hooks.  Pr_input passes data up (towards  * UNIX) and pr_output passes it down (towards the imps).  * The protocol is responsible for the space occupied by any of its  * arguments and must dispose of the space when it is finished with it.  *  * The advise entry is used by lower level protocols to inform  * a higher level protocol of errors and routing advisories and the like.  * Fasttimo is called every 100ms and is typically used to instantaeously  * delay sending ACK's while slowtimo is called every 500ms and is used  * for longer term cleanup.  *  * The drain routine is called if the system is low on buffer space, and  * should throw away non-cricital data.  The userreq routine interfaces  * protocols to the system and is described below.  The sense routine  * returns protocol status into the argument buffer.  This is used by  * the system in providing session-level abstractions out of network  * level protocols, and may also be returned by socket ioctl's.  * The amount of data returned by a sense is limited to the maxsense  * value.  (The space for the sense is allocated by the caller, based on this.)  */
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
name|int
name|pr_flags
decl_stmt|;
comment|/* see below */
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
name|pr_advise
function_decl|)
parameter_list|()
function_decl|;
comment|/* advise about error condition */
name|int
function_decl|(
modifier|*
name|pr_fasttimo
function_decl|)
parameter_list|()
function_decl|;
comment|/* fast timeout (100ms) */
name|int
function_decl|(
modifier|*
name|pr_slowtimo
function_decl|)
parameter_list|()
function_decl|;
comment|/* slow timeout (1 sec) */
name|int
function_decl|(
modifier|*
name|pr_drain
function_decl|)
parameter_list|()
function_decl|;
comment|/* flush any excess space possible */
name|int
function_decl|(
modifier|*
name|pr_usrreq
function_decl|)
parameter_list|()
function_decl|;
comment|/* user request: see list below */
name|int
function_decl|(
modifier|*
name|pr_sense
function_decl|)
parameter_list|()
function_decl|;
comment|/* sense state of protocol */
name|int
name|pr_maxsize
decl_stmt|;
comment|/* max size of sense value */
block|}
struct|;
end_struct

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
comment|/* detach protocol to up */
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
name|PRU_DISCONNECT
value|3
end_define

begin_comment
comment|/* disconnect from peer */
end_comment

begin_comment
comment|/* for ISCONN and ISDISCONN a 0 return means yes */
end_comment

begin_define
define|#
directive|define
name|PRU_ISCONN
value|4
end_define

begin_comment
comment|/* is connection to peer complete? */
end_comment

begin_define
define|#
directive|define
name|PRU_ISDISCONN
value|5
end_define

begin_comment
comment|/* is disconnection from peer complete? */
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
name|PRU_CLEAR
value|9
end_define

begin_comment
comment|/* network went down: clean up */
end_comment

begin_define
define|#
directive|define
name|PRU_CONTROL
value|10
end_define

begin_comment
comment|/* control operations on protocol */
end_comment

begin_define
define|#
directive|define
name|PRU_FASTTIMO
value|11
end_define

begin_comment
comment|/* for protocol's use only: fast timeout */
end_comment

begin_define
define|#
directive|define
name|PRU_SLOWTIMO
value|12
end_define

begin_comment
comment|/* for protocol's use only: slow timeout */
end_comment

begin_comment
comment|/* need some stuff for splice */
end_comment

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
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

