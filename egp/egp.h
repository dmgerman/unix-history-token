begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* egp.h */
end_comment

begin_comment
comment|/* EGP User Process, ISI 23-Jun-84 */
end_comment

begin_comment
comment|/* uses defs.h */
end_comment

begin_struct
struct|struct
name|egpngh
block|{
name|struct
name|egpngh
modifier|*
name|ng_next
decl_stmt|;
comment|/* next state table of linked list */
comment|/*	struct	interface *ng_ifp;	/* pointer to shared net interface  					   table */
name|int
name|ng_state
decl_stmt|;
name|int
name|ng_reach
decl_stmt|;
comment|/* reachability substate */
name|int
name|ng_flags
decl_stmt|;
name|u_char
name|ng_status
decl_stmt|;
comment|/* Info saved for cease retransmission */
name|u_long
name|ng_myaddr
decl_stmt|;
comment|/* My inet address for common net */
name|u_long
name|ng_addr
decl_stmt|;
comment|/* Neighbor's inet address */
name|u_short
name|ng_sid
decl_stmt|;
comment|/* seq.# next acq., hello or poll to send */
name|u_short
name|ng_rid
decl_stmt|;
comment|/* seq.# last acq., hello or poll recvd */
comment|/* Acquire and hello info */
name|int
name|ng_retry
decl_stmt|;
comment|/* For states ACQUIRE_SENT and CEASE_SENT, 				  No. retries to acquire or cease neighbor. 				  For NEIGHBOR state, no. consecutive times 					neighbor is unreachable */
name|int
name|ng_hint
decl_stmt|;
comment|/* Send acquire, hello or cease interval  					in seconds */
name|long
name|ng_htime
decl_stmt|;
comment|/* Time for next acquire, hello, or cease */
name|int
name|ng_responses
decl_stmt|;
comment|/* Shift register of responses for determining 				reachability, each set bit corresponds to a 				response, each zero to no response */
name|int
name|ng_rcmd
decl_stmt|;
comment|/* No. acq., hello and poll commands recvd 				   since lats check */
comment|/* NR Poll info */
name|int
name|ng_snpoll
decl_stmt|;
comment|/* No. sends of this NR poll id */
name|int
name|ng_spint
decl_stmt|;
comment|/* Send NR poll interval (in seconds) */
name|long
name|ng_stime
decl_stmt|;
comment|/* Time to send next NR poll */
name|int
name|ng_runsol
decl_stmt|;
comment|/* No. unsolicited NR msgs received for  				   previous id */
name|int
name|ng_rnpoll
decl_stmt|;
comment|/* No. polls received before next poll time */
name|int
name|ng_rpint
decl_stmt|;
comment|/* Rcv NR poll interval (in seconds) */
name|long
name|ng_rtime
decl_stmt|;
comment|/* Time to rcv next NR poll */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|egpng
value|struct egpngh
end_define

begin_comment
comment|/* States */
end_comment

begin_define
define|#
directive|define
name|EMPTY
value|0
end_define

begin_define
define|#
directive|define
name|UNACQUIRED
value|1
end_define

begin_define
define|#
directive|define
name|ACQUIRE_SENT
value|2
end_define

begin_define
define|#
directive|define
name|NEIGHBOR
value|3
end_define

begin_define
define|#
directive|define
name|CEASE_SENT
value|4
end_define

begin_define
define|#
directive|define
name|BAD
value|5
end_define

begin_comment
comment|/* reachability substates for state NEIGHBOR */
end_comment

begin_define
define|#
directive|define
name|BOTH_UP
value|0
end_define

begin_define
define|#
directive|define
name|NG_DOWN
value|1
end_define

begin_comment
comment|/* according to me my peer is unreachable */
end_comment

begin_define
define|#
directive|define
name|ME_DOWN
value|2
end_define

begin_comment
comment|/* according to my peer I am unreachable */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|NG_BAD
value|1
end_define

begin_comment
comment|/* change to state BAD when cease complete */
end_comment

begin_comment
comment|/* Basic EGP packet */
end_comment

begin_define
define|#
directive|define
name|egpkt
value|struct egppkt
end_define

begin_macro
name|egpkt
end_macro

begin_block
block|{
name|u_char
name|egp_ver
decl_stmt|;
comment|/* Version # */
name|u_char
name|egp_type
decl_stmt|;
comment|/* Opcode */
name|u_char
name|egp_code
decl_stmt|;
name|u_char
name|egp_status
decl_stmt|;
name|u_short
name|egp_chksum
decl_stmt|;
name|u_short
name|egp_system
decl_stmt|;
comment|/* Autonomous system */
name|u_short
name|egp_id
decl_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* EGP neighbor acquisition packet */
end_comment

begin_struct
struct|struct
name|egpacq
block|{
name|egpkt
name|ea_pkt
decl_stmt|;
name|u_short
name|ea_hint
decl_stmt|;
comment|/* Hello interval in seconds */
name|u_short
name|ea_pint
decl_stmt|;
comment|/* NR poll interval in seconds */
block|}
struct|;
end_struct

begin_comment
comment|/* EGP NR poll packet */
end_comment

begin_struct
struct|struct
name|egppoll
block|{
name|egpkt
name|ep_pkt
decl_stmt|;
name|u_short
name|ep_unused
decl_stmt|;
name|u_long
name|ep_net
decl_stmt|;
comment|/* Source net */
block|}
struct|;
end_struct

begin_comment
comment|/* EGP NR Message packet */
end_comment

begin_struct
struct|struct
name|egpnr
block|{
name|egpkt
name|en_pkt
decl_stmt|;
name|u_char
name|en_igw
decl_stmt|;
comment|/* No. internal gateways */
name|u_char
name|en_egw
decl_stmt|;
comment|/* No. external gateways */
name|u_long
name|en_net
decl_stmt|;
comment|/* shared net */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NRMAXNETUNIT
value|9
end_define

begin_comment
comment|/* maximum size per net in octets of net part 				of NR message */
end_comment

begin_comment
comment|/* EGP Error packet */
end_comment

begin_struct
struct|struct
name|egperr
block|{
name|egpkt
name|ee_pkt
decl_stmt|;
name|u_short
name|ee_rsn
decl_stmt|;
name|u_char
name|ee_egphd
index|[
literal|12
index|]
decl_stmt|;
comment|/* First 12 bytes of bad egp pkt */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EGPLEN
value|(sizeof(egpkt))
end_define

begin_define
define|#
directive|define
name|EGPVER
value|2
end_define

begin_comment
comment|/* EGP Types */
end_comment

begin_define
define|#
directive|define
name|EGPNR
value|1
end_define

begin_define
define|#
directive|define
name|EGPPOLL
value|2
end_define

begin_define
define|#
directive|define
name|EGPACQ
value|3
end_define

begin_define
define|#
directive|define
name|EGPHELLO
value|5
end_define

begin_define
define|#
directive|define
name|EGPERR
value|8
end_define

begin_comment
comment|/* Neighbor Acquisition Codes */
end_comment

begin_define
define|#
directive|define
name|NAREQ
value|0
end_define

begin_comment
comment|/* Neighbor acq. request */
end_comment

begin_define
define|#
directive|define
name|NACONF
value|1
end_define

begin_comment
comment|/* Neighbor acq. confirmation */
end_comment

begin_define
define|#
directive|define
name|NAREFUS
value|2
end_define

begin_comment
comment|/* Neighbor acq. refuse */
end_comment

begin_define
define|#
directive|define
name|NACEASE
value|3
end_define

begin_comment
comment|/* Neighbor cease */
end_comment

begin_define
define|#
directive|define
name|NACACK
value|4
end_define

begin_comment
comment|/* Neighbor cease ack */
end_comment

begin_comment
comment|/* Neighbour Acquisition Message Status Info */
end_comment

begin_define
define|#
directive|define
name|UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|PASSIVE
value|2
end_define

begin_define
define|#
directive|define
name|NORESOURCE
value|3
end_define

begin_define
define|#
directive|define
name|ADMINPROHIB
value|4
end_define

begin_define
define|#
directive|define
name|GODOWN
value|5
end_define

begin_define
define|#
directive|define
name|PARAMPROB
value|6
end_define

begin_define
define|#
directive|define
name|PROTOVIOL
value|7
end_define

begin_comment
comment|/* Neighbor Hello Codes */
end_comment

begin_define
define|#
directive|define
name|HELLO
value|0
end_define

begin_define
define|#
directive|define
name|HEARDU
value|1
end_define

begin_comment
comment|/* Reachability, poll and update status */
end_comment

begin_define
define|#
directive|define
name|INDETERMINATE
value|0
end_define

begin_define
define|#
directive|define
name|UP
value|1
end_define

begin_define
define|#
directive|define
name|DOWN
value|2
end_define

begin_define
define|#
directive|define
name|UNSOLICITED
value|128
end_define

begin_comment
comment|/* Error reason status */
end_comment

begin_define
define|#
directive|define
name|EUNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|EBADHEAD
value|1
end_define

begin_define
define|#
directive|define
name|EBADDATA
value|2
end_define

begin_define
define|#
directive|define
name|ENOREACH
value|3
end_define

begin_define
define|#
directive|define
name|EXSPOLL
value|4
end_define

begin_define
define|#
directive|define
name|ENORESPONSE
value|5
end_define

end_unit

