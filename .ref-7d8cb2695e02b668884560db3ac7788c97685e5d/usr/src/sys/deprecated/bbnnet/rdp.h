begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Log:	rdp.h,v $  * Revision 2.13  85/06/18  14:33:36  walsh  * added extern decl.  *   * Revision 2.12  84/11/29  12:50:15  walsh  * changed references to currentrtt into references to srtt, a better  * and less misleading mnemonic.  *   * Revision 2.11  84/11/15  09:55:15  walsh  * redid how we deal with compiler padding in the RDP header structure.  *   * Revision 2.10  84/11/08  16:09:21  walsh  * Added code to gather statistics on RDP traffic.  This makes the RDPCB  * too big unles you make mbufs 512 bytes large.  RDP_CS should be turned off  * unless you do.  *   * Revision 2.9  84/11/06  15:24:02  walsh  * *** empty log message ***  *   * Revision 2.8  84/11/06  14:29:44  walsh  * intorduced RDP_HLSHIFT  *   * Revision 2.7  84/11/05  12:42:04  walsh  * Set things up so can debug RDP connections just like can debug TCP  * connections.  *   * Revision 2.6  84/11/05  11:14:03  walsh  * *** empty log message ***  *   * Revision 2.5  84/11/05  11:03:55  walsh  * comment and adjust number for rdp_iss in a mathematically correct way  * as a result of benchmarks (cf. operationally correct).  *   * Revision 2.4  84/11/02  18:21:13  walsh  * Protocol specifiers want NULL message to have own sequence number in  * case of slow (t>NULL msg timeout) packets.  I don't see this as a problem,  * and even if happened (dubious) would only delay discovery, but I  * didn't win this one.  Initially not designed for this, but fixes are  * in almost neatly.  *   * Revision 2.3  84/11/02  15:26:42  walsh  * Allow for RDP header fields not on natural boundries.  (Protocol  * specifiers say will be part of next version in 6-12 months).  * Until then, there goes the speed...  Yucho modifications.  *   * Revision 2.2  84/11/02  13:12:29  walsh  * use rdp typedefs for packet header fields to reduce lint errors.  *   * Revision 2.1  84/11/02  10:10:49  walsh  * Fixed to include RCS comments in checked out source.  *    * description:  * Reliable Datagram Protocol definitions.  *   * revision 1.10          * date: 84/07/25 09:45:36;  author: walsh;  state: Exp;  lines added/del: 1/1  * RDP finally has an official protocol number assigned by Postel.  *   * revision 1.9          * date: 84/07/19 10:20:37;  author: walsh;  state: Exp;  lines added/del: 1/31  * Organized macros and classified their definitions in rdp_macros.h.  *   * revision 1.8          * date: 84/07/18 18:49:39;  author: walsh;  state: Exp;  lines added/del: 7/1  * Added provision for sending of NULL messages.  These are sent on an idle  * connection to determine that the other side still exists.  *   * revision 1.7          * date: 84/07/18 13:51:54;  author: walsh;  state: Exp;  lines added/del: 1/0  * constant RDP_MAXTIMERVAL to go with type rdptimerval.  *   * revision 1.6          * date: 84/07/18 13:27:06;  author: walsh;  state: Exp;  lines added/del: 11/4  * Bouncing datagrams off goonhilly-echo eventually causes RTTL timeout.  So,  * have re-worked:  * 	1.  rxtime = 1.5 srtt, not factor of 2 used before  * 	2.  max rxtime now 20 sec, not 30 seconds  * 	3.  provisions for user definition of RTTL period.  *   * revision 1.5          * date: 84/07/12 13:44:12;  author: walsh;  state: Exp;  lines added/del: 26/19  * Rather than in-line stuffing of IP/RDP headers, at least half of which are  * constant, copy headers in from a template of what the headers are like.  The  * bcopy() call is turned into a movc3 instruction on the VAX by a sed script  * run over the assembler output of the C compiler.  Marginal speed-up.  *   * revision 1.4          * date: 84/07/10 14:42:34;  author: walsh;  state: Exp;  lines added/del: 20/23  * simplified check for if debugging on in RDP_ACTION, since rdpcb, inpcb,  * and socket structure all last equally as long.  *   * revision 1.3          * date: 84/07/09 14:23:00;  author: walsh;  state: Exp;  lines added/del: 2/1  * Added ACK-delay timer.  *   * revision 1.2          * date: 84/07/06 09:46:45;  author: walsh;  state: Exp;  lines added/del: 36/1  * This version seems to run bug-free.  *   * revision 1.1          * date: 84/06/26 14:16:27;  author: walsh;  state: Exp;    * Initial revision  *   */
end_comment

begin_comment
comment|/*  * Here's how I've tried to name things to keep them consistent.  * For RDP_?..., the ? means:  *  *	f	flag (in packet header)  *	i	input event  *	o	option (in syn packet header)  *	p	port number  *	s	state (of connection in rdpcb)  *	t	timer  *	tv	timer value  */
end_comment

begin_typedef
typedef|typedef
name|char
name|boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|rdpstate
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|rdpsequence
typedef|;
end_typedef

begin_comment
comment|/* sequence # or ack # */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|rdpchecksum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|rdptimerval
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RDP_MAXTIMERVAL
value|255
end_define

begin_typedef
typedef|typedef
name|u_char
name|rdpportnum
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|inpcb
name|INPCB
typedef|;
end_typedef

begin_comment
comment|/* belongs in in_pcb.h */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mbuf
name|MBUF
typedef|;
end_typedef

begin_comment
comment|/* belongs in mbuf.h */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rdphdr
block|{
name|char
name|rh_ver
range|:
literal|2
decl_stmt|,
comment|/* version of packet header */
name|rh_flags
range|:
literal|6
decl_stmt|;
name|u_char
name|rh_hdrlen
decl_stmt|;
comment|/* in units of 2 bytes */
name|rdpportnum
name|rh_sport
decl_stmt|;
comment|/* source port */
name|rdpportnum
name|rh_dport
decl_stmt|;
comment|/* destination port */
name|u_short
name|rh_dlen
decl_stmt|;
comment|/* amount of data following the header */
name|rdpsequence
name|rh_seqno
decl_stmt|;
name|rdpsequence
name|rh_ackno
decl_stmt|;
comment|/* valid iff ACK set */
name|rdpchecksum
name|rh_cksum
decl_stmt|;
block|}
name|RDPHDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RDP_VERSION
value|1
end_define

begin_comment
comment|/* rh_ver */
end_comment

begin_define
define|#
directive|define
name|RDP_fNULL
value|0x02
end_define

begin_comment
comment|/* rh_flags */
end_comment

begin_define
define|#
directive|define
name|RDP_fRST
value|0x04
end_define

begin_define
define|#
directive|define
name|RDP_fEACK
value|0x08
end_define

begin_define
define|#
directive|define
name|RDP_fACK
value|0x10
end_define

begin_define
define|#
directive|define
name|RDP_fSYN
value|0x20
end_define

begin_define
define|#
directive|define
name|RDP_HLSHIFT
value|1
end_define

begin_comment
comment|/* Header Length SHIFT */
end_comment

begin_define
define|#
directive|define
name|hdrlen
parameter_list|(
name|x
parameter_list|)
value|((x)->rh_hdrlen<< RDP_HLSHIFT)
end_define

begin_comment
comment|/*  * RDP port numbers 1-63 for servers, 64-255 assigned to clients  */
end_comment

begin_define
define|#
directive|define
name|RDP_pANY
value|0
end_define

begin_define
define|#
directive|define
name|RDP_RESERVED
value|63
end_define

begin_define
define|#
directive|define
name|RDP_USERRESERVED
value|63
end_define

begin_define
define|#
directive|define
name|RDP_MAXPORT
value|255
end_define

begin_comment
comment|/*  * Due to the compiler aligning header fields on natural boundries,  * the rdp header is 18 bytes on the network, but sizeof(RDPHDR) = 20  * So, skip sizeof and define macros to access fields after the gap.  */
end_comment

begin_define
define|#
directive|define
name|RDPHDRSZ
value|18
end_define

begin_comment
comment|/* on the network */
end_comment

begin_define
define|#
directive|define
name|RDP_SEQNO
parameter_list|(
name|pkt
parameter_list|)
value|(* ((u_long *) (&((char *) (pkt))[6])))
end_define

begin_define
define|#
directive|define
name|RDP_ACKNO
parameter_list|(
name|pkt
parameter_list|)
value|(* ((u_long *) (&((char *) (pkt))[10])))
end_define

begin_define
define|#
directive|define
name|RDP_CKSUM
parameter_list|(
name|pkt
parameter_list|)
value|(* ((u_long *) (&((char *) (pkt))[14])))
end_define

begin_define
define|#
directive|define
name|RDP_OPT
parameter_list|(
name|pkt
parameter_list|,
name|type
parameter_list|)
value|((type) (&((char *) (pkt))[RDPHDRSZ]))
end_define

begin_comment
comment|/*  * In a SYN packet, this will immediately follow the rdphdr  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|synoptions
block|{
name|short
name|rh_nbuf
decl_stmt|;
comment|/* # dgrams he can buffer */
name|u_short
name|rh_maxlen
decl_stmt|;
comment|/* max length of a dgram */
name|short
name|rh_options
decl_stmt|;
define|#
directive|define
name|RDP_oSEQUENTIAL
value|1
block|}
name|SYNOPTIONS
typedef|;
end_typedef

begin_comment
comment|/*  * For an established connection, a variable length array of these  * may immediately follow the rdphdr  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|eackoptions
block|{
name|rdpsequence
name|rh_eackno
decl_stmt|;
block|}
name|EACKOPTIONS
typedef|;
end_typedef

begin_comment
comment|/*  * RDP connection states  */
end_comment

begin_define
define|#
directive|define
name|RDP_sSAME
value|0
end_define

begin_comment
comment|/* no state transition for this input to fsm */
end_comment

begin_define
define|#
directive|define
name|RDP_sUNOPENED
value|1
end_define

begin_comment
comment|/* after socket(2), before listen or connect */
end_comment

begin_define
define|#
directive|define
name|RDP_sLISTEN
value|2
end_define

begin_comment
comment|/* after listen(2) */
end_comment

begin_define
define|#
directive|define
name|RDP_sSYNSENT
value|3
end_define

begin_comment
comment|/* after connect(2) */
end_comment

begin_define
define|#
directive|define
name|RDP_sLSYNRCVD
value|4
end_define

begin_comment
comment|/* child socket after SYN gets to LISTENer */
end_comment

begin_define
define|#
directive|define
name|RDP_sSYNRCVD
value|5
end_define

begin_comment
comment|/* after SYN gets to SYNSENT */
end_comment

begin_define
define|#
directive|define
name|RDP_sESTAB
value|6
end_define

begin_comment
comment|/* after get both SYN and ACK */
end_comment

begin_define
define|#
directive|define
name|RDP_sCLOSEWAIT
value|7
end_define

begin_comment
comment|/* after send or receive RST */
end_comment

begin_define
define|#
directive|define
name|RDP_sCLOSED
value|8
end_define

begin_comment
comment|/* after CLOSEWAIT timeout */
end_comment

begin_define
define|#
directive|define
name|RDP_NSTATES
value|9
end_define

begin_comment
comment|/*  * Inputs that (possibly) cause state transition  */
end_comment

begin_define
define|#
directive|define
name|RDP_iCONNECT
value|0
end_define

begin_comment
comment|/* user connect(2) request == active open */
end_comment

begin_define
define|#
directive|define
name|RDP_iLISTEN
value|1
end_define

begin_comment
comment|/* user listen(2) request == passive open */
end_comment

begin_define
define|#
directive|define
name|RDP_iNETR
value|2
end_define

begin_comment
comment|/* network reception of packet */
end_comment

begin_define
define|#
directive|define
name|RDP_iUCLOSE
value|3
end_define

begin_comment
comment|/* user close(2) request */
end_comment

begin_define
define|#
directive|define
name|RDP_iTIMER
value|4
end_define

begin_comment
comment|/* a timer went off */
end_comment

begin_define
define|#
directive|define
name|RDP_iRCV
value|5
end_define

begin_comment
comment|/* user has picked up a packet */
end_comment

begin_define
define|#
directive|define
name|RDP_iSEND
value|6
end_define

begin_comment
comment|/* user send request */
end_comment

begin_define
define|#
directive|define
name|RDP_NINPUTS
value|7
end_define

begin_comment
comment|/*  * rq_maxqlen = MIN(desired, RDP_MAXDGRAMS)  */
end_comment

begin_define
define|#
directive|define
name|RDP_MAXDGRAMS
value|40
end_define

begin_comment
comment|/*  * In rq_msgs, pointers follow:  *	sendq:: NULL x PRU_SEND ->  *		ptr x (E)ACK ->  *		RDP_DELIVERED x move front -> NULL  *  *	rcvq::	NULL x net reception ->  *		ptr x pass to user ->  *		RDP_DELIVERED x (PRU_RECV + move front) -> NULL  *  *		on last transition, we also (E)ACK the packet.  */
end_comment

begin_define
define|#
directive|define
name|RDP_DELIVERED
value|((struct mbuf *) (-1))
end_define

begin_define
define|#
directive|define
name|RDP_NULLMSG
value|((struct mbuf *) (-2))
end_define

begin_comment
comment|/*  * rq_msgs points into an mbuf that we use for an array of pointers to  * mbuf chains.  On input, each mbuf chain holds an RDP packet (header and  * data).  On output, each mbuf chain holds the data portion of the packet  * in case it is needed for re-transmission.  *			+---------------+  *	rq_msgs -->	|		|  *			|   o-----------|---> mbuf chain (== packet or data)  *			| RDP_DELIVERED	|  *			| RDP_NULLMSG	|  *			|		|  *			+---------------+  *			array in mbuf  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rdp_msgq
block|{
name|int
name|rq_maxqlen
decl_stmt|;
comment|/* 1...RDP_MAXDGRAMS inclusive */
name|int
name|rq_maxiplen
decl_stmt|;
comment|/* max IP length of dgram can put on q*/
name|int
name|rq_front
decl_stmt|;
comment|/* 0...(rq_maxqlen-1) inclusive */
name|rdpsequence
name|rq_baseseq
decl_stmt|;
comment|/* RDP seq # of rq_msgs[rq_front] */
name|MBUF
modifier|*
modifier|*
name|rq_msgs
decl_stmt|;
comment|/* -> into mbuf holding array of ptrs*/
block|}
name|RDP_MSGQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rdpcb
block|{
name|struct
name|inpcb
modifier|*
name|r_inpcb
decl_stmt|;
name|rdpstate
name|r_state
decl_stmt|;
comment|/* state of connection */
name|rdpsequence
name|r_iss
decl_stmt|;
comment|/* initial sequence # sent (in SYN) */
name|rdpsequence
name|r_irs
decl_stmt|;
comment|/* initial sequence # rcvd (in SYN) */
name|rdpsequence
name|r_sndnxt
decl_stmt|;
comment|/* seq # for next datagram we send */
name|struct
name|rdp_msgq
name|r_sendq
decl_stmt|,
name|r_rcvq
decl_stmt|;
define|#
directive|define
name|r_hisnbuf
value|r_sendq.rq_maxqlen
comment|/* # RDP messages he can buffer */
define|#
directive|define
name|r_hismaxlen
value|r_sendq.rq_maxiplen
comment|/* biggest IP datagram he'll take */
define|#
directive|define
name|r_snduna
value|r_sendq.rq_baseseq
comment|/* seq # of oldest unacked dgram sent */
define|#
directive|define
name|r_ournbuf
value|r_rcvq.rq_maxqlen
comment|/* # RDP messages we can buffer */
define|#
directive|define
name|r_ourmaxlen
value|r_rcvq.rq_maxiplen
comment|/* biggest RDP data length we'll take */
name|boolean
name|r_synrcvd
decl_stmt|;
comment|/* have we rcvd his SYN? */
name|boolean
name|r_synacked
decl_stmt|;
comment|/* has he ACKed our SYN? */
name|boolean
name|r_usrclosed
decl_stmt|;
comment|/* has user process close(2)ed yet? */
name|boolean
name|r_sendrst
decl_stmt|;
comment|/* set reset in outgoing packet */
name|boolean
name|r_sendnull
decl_stmt|;
comment|/* set null in outgoing packet */
name|boolean
name|r_sequential
decl_stmt|;
comment|/* sequential delivery? */
name|boolean
name|r_rttiming
decl_stmt|;
comment|/* are we measuring rtt? */
name|rdptimerval
name|r_closewait
decl_stmt|;
comment|/* # 0.5 sec units before destroy *cb */
define|#
directive|define
name|RDP_tvCLOSEWAIT
value|120
comment|/* default idea of CLOSEWAIT timer */
name|rdptimerval
name|r_rttl
decl_stmt|;
comment|/* error if dgram unacked in this time*/
define|#
directive|define
name|RDP_tvRTTL
value|120
comment|/* default idea of RTTL timer */
name|rdptimerval
name|r_tvnull
decl_stmt|;
comment|/* for testing connection existence */
define|#
directive|define
name|RDP_tvNULL
value|240
comment|/* default idea time to 1st NULL */
name|char
name|r_nullsent
decl_stmt|;
comment|/* # successive null messages sent */
define|#
directive|define
name|RDP_MAXNULL
value|5
comment|/* 	 * For now, each retransmission of a packet will take the same 	 * amount of time. 	 */
name|rdptimerval
name|r_rxmitime
decl_stmt|;
comment|/* current idea of re-xmission time */
define|#
directive|define
name|RDP_tvRXMAX
value|40
comment|/* max value of re-xmit timer (20 sec)*/
define|#
directive|define
name|RDP_tvRXMIN
value|4
comment|/* min value of re-xmit timer ( 2 sec)*/
comment|/* 	 * (3 * (RDP_tvRXMIN = 4)) / 2 = 6 	 * So, allows AT LEAST one second of variance from srtt until 	 * hits RDP_tvRXMAX ceiling. 	 */
define|#
directive|define
name|update_rxmitime
parameter_list|(
name|r
parameter_list|)
define|\
value|(r)->r_rxmitime = MAX(RDP_tvRXMIN, \ 			MIN(RDP_tvRXMAX, (3 * (r)->r_srtt) / 2));
comment|/* 	 * if we're measuring the round trip time, (r_rttiming == TRUE), 	 * then r_rtt counts time til get ack of dgram # r_rttimed. 	 * r_rtt starts at 0 when send packet # r_rttimed, and is incremented 	 * each 0.5 second.  r_srtt is updated when r_rttimed is acked. 	 * At that time, r_rxmitime should also be updated.  srtt represents 	 * a weighted average of the recent round trip times. 	 */
name|rdpsequence
name|r_rttimed
decl_stmt|;
comment|/* seq # of dgram finding rtt for */
name|rdptimerval
name|r_rtt
decl_stmt|;
comment|/* round trip time (in 0.5 sec units)*/
name|rdptimerval
name|r_srtt
decl_stmt|;
comment|/* smoothed round trip time */
define|#
directive|define
name|ALPHA
value|4
define|#
directive|define
name|BETA
value|1
ifdef|#
directive|ifdef
name|RDP_CS
define|#
directive|define
name|update_rttestimate
parameter_list|(
name|r
parameter_list|)
define|\
value|{ \   (r)->r_srtt = (ALPHA*(r)->r_srtt + BETA*(r)->r_rtt) / (ALPHA+BETA) \   (r)->r_nrtt ++;					\   (r)->r_totalrtt += (r)->r_rtt;			\   if ((r)->r_nrtt == 1)					\ 	(r)->r_minrtt = (r)->r_maxrtt = (r)->r_rtt;	\   else if ((r)->r_rtt< (r)->r_minrtt)			\ 	(r)->r_minrtt = (r)->r_rtt;			\   else if ((r)->r_rtt> (r)->r_maxrtt)			\ 	(r)->r_maxrtt = (r)->r_rtt;			\   }
else|#
directive|else
define|#
directive|define
name|update_rttestimate
parameter_list|(
name|r
parameter_list|)
define|\
value|(r)->r_srtt = (ALPHA*(r)->r_srtt + BETA*(r)->r_rtt) / (ALPHA+BETA)
endif|#
directive|endif
comment|/* 	 * if we have at least one packet being timed for re-transmission, 	 * then we have a "retransmit took too long" timer also set.  One such 	 * timer suffices.  This timer is associated with rxtimers[rttlindex] 	 * and r_sendq.rq_msgs[rttlindex] 	 */
name|int
name|r_rttlindex
decl_stmt|;
define|#
directive|define
name|RDP_tCLOSEWAIT
value|0
define|#
directive|define
name|RDP_tRTTL
value|1
comment|/* retransmit took too long (not in spec) */
define|#
directive|define
name|RDP_tRXMIT
value|2
comment|/* if set, check rxtimers */
define|#
directive|define
name|RDP_tACKDELAY
value|3
define|#
directive|define
name|RDP_tNULL
value|4
define|#
directive|define
name|RDP_NTIMERS
value|5
name|rdptimerval
name|r_timers
index|[
name|RDP_NTIMERS
index|]
decl_stmt|;
comment|/* 	 * The re-transmission timer array is parallel to r_sendq.rq_msgs 	 */
name|rdptimerval
name|r_rxtimers
index|[
name|RDP_MAXDGRAMS
index|]
decl_stmt|;
comment|/* send retransmit timers */
define|#
directive|define
name|RDP_tvRXCHECK
value|1
comment|/* check per-pkt rxmit timers every 0.5 sec   */
comment|/* 	 * and for a (minor) speedup, just byte copy the constant header fields 	 */
define|#
directive|define
name|RDP_TEMPLSIZE
value|(sizeof(struct ip) + RDPHDRSZ)
name|char
name|r_template
index|[
name|RDP_TEMPLSIZE
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|RDP_CS
name|rdptimerval
name|r_minrtt
decl_stmt|;
comment|/* minimum rtt observed */
name|rdptimerval
name|r_maxrtt
decl_stmt|;
comment|/* maximum rtt observed */
name|int
name|r_totalrtt
decl_stmt|;
comment|/* total of all rtt packets */
name|int
name|r_nrtt
decl_stmt|;
comment|/* # rtt packets measured */
name|u_long
name|r_entered
index|[
name|RDP_NSTATES
index|]
decl_stmt|;
comment|/* .001 sec */
struct|struct
block|{
name|int
name|r_total
decl_stmt|;
name|int
name|r_nullpkts
decl_stmt|;
name|int
name|r_synpkts
decl_stmt|;
name|int
name|r_rstpkts
decl_stmt|;
name|int
name|r_retrans
decl_stmt|;
name|int
name|r_nbytes
decl_stmt|;
comment|/* to/from user */
block|}
name|r_sent
struct|,
name|r_rcvd
struct|;
endif|#
directive|endif
block|}
name|RDPCB
typedef|;
end_typedef

begin_define
define|#
directive|define
name|rdpcbtoso
parameter_list|(
name|r
parameter_list|)
value|((r)->r_inpcb->inp_socket)
end_define

begin_comment
comment|/*  * RDP desires control over the IP length.  We really only have good  * control on the RDP data length in the UNIX socket code.  Use the following  * as the difference between the two.  *  * Allow how much space for eacks?  * (Don't care on input.  Can drop eack options on output.)  */
end_comment

begin_define
define|#
directive|define
name|HDRSLOP
value|(RDPHDRSZ + sizeof(struct ip))
end_define

begin_comment
comment|/*  * Active opens (connect) and children of listener can time out via RDP_tRTTL.  * Is a timeout for passive opens (LISTEN state) desireable?  Prob not  * since user can always use alarm(2) system call.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|r_debug
block|{
name|u_long
name|rd_iptime
decl_stmt|;
comment|/* 0.001 second units */
name|int
name|rd_input
decl_stmt|;
name|rdpstate
name|rd_newstate
decl_stmt|;
name|RDPCB
name|rd_rdpcb
decl_stmt|;
name|int
name|rd_timer
decl_stmt|;
comment|/* iff input == RDP_iTIMER */
name|struct
name|ip
name|rd_iphdr
decl_stmt|;
comment|/* iff input == RDP_iNETR */
name|RDPHDR
name|rd_rdphdr
decl_stmt|;
comment|/* iff input == RDP_iNETR */
block|}
name|R_DEBUG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RCDBLEN
value|((CLBYTES/sizeof(R_DEBUG)) * sizeof(R_DEBUG))
end_define

begin_define
define|#
directive|define
name|RDBLEN
value|((MLEN   /sizeof(R_DEBUG)) * sizeof(R_DEBUG))
end_define

begin_define
define|#
directive|define
name|inptordpcb
parameter_list|(
name|i
parameter_list|)
value|((RDPCB *) ((i)->inp_ppcb))
end_define

begin_struct
struct|struct
name|rdp_stat
block|{
name|struct
name|in_stat
name|r_in
decl_stmt|;
define|#
directive|define
name|r_total
value|r_in.in_total
define|#
directive|define
name|r_badsum
value|r_in.in_badsum
define|#
directive|define
name|r_tooshort
value|r_in.in_tooshort
define|#
directive|define
name|r_drops
value|r_in.in_drops
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Each host chooses the starting point of the packet numbering for a  * connection so that datagrams from different incarnations of a  * connection have no sequence numbers in common.  SYN packets are used  * by each side to make the other aware of the starting point.  If we  * can send N packets per slow timeout, then if we update rdp_iss  * by RDP_ISSINCR> N every slow timeout (one connection bangs away  * all timeout period) and by RDP_ISSINCR every time we make a connection  * (many incarnations of same connection per timeout period), then we're  * o.k.  */
end_comment

begin_decl_stmt
specifier|extern
name|rdpsequence
name|rdp_iss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vax can send 180 packets/second */
end_comment

begin_define
define|#
directive|define
name|RDP_ISSINCR
value|((200/PR_SLOWHZ) +1)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|dfilter
name|rdp_dfilter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|inpcb
name|rdp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rdp_stat
name|rdpstat
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern rdp_pcbdisconnect(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|rdp_qremove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rdpchecksum
name|rdp_cksum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|rdp_conn_used
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|rdp_action
parameter_list|(
name|input
parameter_list|,
name|rdpcb
parameter_list|,
name|arg
parameter_list|)
value|rdpaction(input, rdpcb, (int) arg)
end_define

begin_comment
comment|/*  * RDP finite state machine  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RDPDEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rdpstates
index|[
name|RDP_NSTATES
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rdpstate -> string */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rdpinputs
index|[
name|RDP_NINPUTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rdptimers
index|[
name|RDP_NTIMERS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|rdp_action_table
index|[
name|RDP_NSTATES
index|]
index|[
name|RDP_NINPUTS
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

