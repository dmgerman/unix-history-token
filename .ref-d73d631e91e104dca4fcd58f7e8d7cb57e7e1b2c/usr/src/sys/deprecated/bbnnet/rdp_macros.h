begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Log:	rdp_macros.h,v $  * Revision 2.6  84/11/14  13:24:53  walsh  * macro to go with monitoring outgoing packets on a debugged RDP connection.  *   * Revision 2.5  84/11/08  16:11:38  walsh  * Added code to gather statistics on RDP traffic.  This makes the RDPCB  * too big unles you make mbufs 512 bytes large.  RDP_CS should be turned off  * unless you do.  *   * Revision 2.4  84/11/05  15:53:21  walsh  * update_nulltimer() macro began to look inappropriate with recent  * changes, so its been stripped out and put in-line.  *   * Revision 2.3  84/11/05  14:24:45  walsh  * added comment.  *   * Revision 2.2  84/11/02  18:23:51  walsh  * Protocol specifiers want NULL message to have own sequence number in  * case of slow (t>NULL msg timeout) packets.  I don't see this as a problem,  * and even if happened (dubious) would only delay discovery, but I  * didn't win this one.  Initially not designed for this, but fixes are  * in almost neatly.  *   * Revision 2.1  84/11/02  10:13:25  walsh  * Fixed to include RCS comments in checked out source.  *   *  * description:  * Organized macros used by RDP and put most of them here.  *   * revision 1.3          * date: 84/07/19 13:53:16;  author: walsh;  state: Exp;  lines added/del: 24/4  * worked on retransmit took too long macro.  Should now advise  * sockets sleeping in connect(2) and does trash child sockets  * who cannot connect to their peers.  *   * revision 1.2          * date: 84/07/19 10:53:06;  author: walsh;  state: Exp;  lines added/del: 8/5  * Changed retransmit took too long timer to be advisory in nature.  It  * reports error to user, but does not affect connection state.  *   * revision 1.1          * date: 84/07/19 10:24:08;  author: walsh;  state: Exp;    * Initial revision  */
end_comment

begin_comment
comment|/********** Macros to hide (socket) level above **********/
end_comment

begin_comment
comment|/*  * The user notifies the RDP of the maximum sized datagram he's willing to  * receive by adjusting the socket receive buffering accordingly.  */
end_comment

begin_define
define|#
directive|define
name|pick_ourmaxlen
parameter_list|(
name|rdpcb
parameter_list|)
define|\
value|((rdpcb)->r_ourmaxlen = (rdpcb)->r_inpcb->inp_socket->so_rcv.sb_hiwat)
end_define

begin_comment
comment|/*  * Notify user of error condition via the socket  */
end_comment

begin_define
define|#
directive|define
name|set_error
parameter_list|(
name|rdpcb
parameter_list|,
name|error
parameter_list|)
value|(rdpcb)->r_inpcb->inp_socket->so_error = error;
end_define

begin_comment
comment|/*  * On packet reception, can we q a datagram on the socket for the user?  * We only q one on the socket at a time.  */
end_comment

begin_define
define|#
directive|define
name|usr_rbuf_is_empty
parameter_list|(
name|rdpcb
parameter_list|)
define|\
value|((rdpcb)->r_inpcb->inp_socket->so_rcv.sb_cc == 0)
end_define

begin_comment
comment|/*  * All the datagrams are buffered by RDP.  RDP has reached its buffering  * limit, so prevent the user from queueing more up until we get some  * acknowledgements back from the other side.  */
end_comment

begin_define
define|#
directive|define
name|sendbufisfull
parameter_list|(
name|rdpcb
parameter_list|)
define|\
value|{ struct sockbuf *sosnd;				\ 	  sosnd =&(rdpcb)->r_inpcb->inp_socket->so_snd;	\ 	  sosnd->sb_cc = sosnd->sb_hiwat;			\ 	}
end_define

begin_comment
comment|/*  * Permit the user to q up more datagrams for sending.  *  * We only need to wake up a writer if he's blocked for  * buffering space.  RDP allows at most 1 datagram in  * the socket code, and no datagrams for transmission  * are stored on the socket due to RDP's messing with  * so_snd.sb_cc, so we are able to do the wakeup iff necessary  */
end_comment

begin_define
define|#
directive|define
name|sendbufhasspace
parameter_list|(
name|rdpcb
parameter_list|)
define|\
value|{ struct socket *so;			\ 	  so = (rdpcb)->r_inpcb->inp_socket;	\ 	  if (so->so_snd.sb_cc) {		\ 		  so->so_snd.sb_cc = 0;		\ 		  sowwakeup(so);		\ 	}}
end_define

begin_define
define|#
directive|define
name|wakeup_reader
parameter_list|(
name|rdpcb
parameter_list|)
value|sorwakeup((rdpcb)->r_inpcb->inp_socket)
end_define

begin_define
define|#
directive|define
name|wakeup_writer
parameter_list|(
name|rdpcb
parameter_list|)
value|sowwakeup((rdpcb)->r_inpcb->inp_socket)
end_define

begin_comment
comment|/*  * We can't send any new datagrams after we've been reset.  */
end_comment

begin_define
define|#
directive|define
name|user_cantsendmore
parameter_list|(
name|rdpcb
parameter_list|)
value|socantsendmore((rdpcb)->r_inpcb->inp_socket)
end_define

begin_define
define|#
directive|define
name|user_cantreadmore
parameter_list|(
name|rdpcb
parameter_list|)
value|socantrcvmore((rdpcb)->r_inpcb->inp_socket)
end_define

begin_comment
comment|/*  * The socket code prevents read(2) or write(2) until we're connected to  * the other end.  Nor can a child socket be accept(2)ed until the connection  * is established.  */
end_comment

begin_define
define|#
directive|define
name|rdpisconnected
parameter_list|(
name|rdpcb
parameter_list|)
value|soisconnected((rdpcb)->r_inpcb->inp_socket)
end_define

begin_comment
comment|/********** Macros to save duplicating code fragments **********/
end_comment

begin_comment
comment|/*  * set up re-transmission timer for packet we just sent.  */
end_comment

begin_define
define|#
directive|define
name|set_rxtimer
parameter_list|(
name|rdpcb
parameter_list|,
name|N
parameter_list|)
define|\
value|{ (rdpcb)->r_rxtimers[N] = (rdpcb)->r_rxmitime;		\ 	  (rdpcb)->r_timers[RDP_tRXMIT] = RDP_tvRXCHECK;	\ 	  if ((rdpcb)->r_rttlindex< 0) {			\ 		(rdpcb)->r_rttlindex = N;			\ 		(rdpcb)->r_timers[RDP_tRTTL] = (rdpcb)->r_rttl;	\ 	} }
end_define

begin_comment
comment|/*  * we received the other guy's SYN, and it was in packet seqnum  */
end_comment

begin_define
define|#
directive|define
name|got_syn
parameter_list|(
name|rdpcb
parameter_list|,
name|seqnum
parameter_list|)
define|\
value|{ (rdpcb)->r_synrcvd = TRUE;                \ 	  (rdpcb)->r_rcvq.rq_baseseq = (seqnum) +1; \ 	  (rdpcb)->r_irs = seqnum;                  \ 	}
end_define

begin_comment
comment|/*  * RFC 908 section 3.5 page 16 says to use twice the advertised buffering  * This is a bad idea that is an attempt to make up for network latency  * and to try to keep things pipelined.  We'll use only advertised buffering.  * Approach:  Don't make trouble, other end must ask for it.  (by  * advertising more than has)  */
end_comment

begin_define
define|#
directive|define
name|process_synopt
parameter_list|(
name|rdpcb
parameter_list|,
name|synopt
parameter_list|)
define|\
value|{ (rdpcb)->r_hisnbuf = MAX(1, MIN (ntohs((u_short)(synopt)->rh_nbuf), \ 					   RDP_MAXDGRAMS));	 \ 	  (rdpcb)->r_hismaxlen = ntohs((u_short)(synopt)->rh_maxlen);     \ 	  (rdpcb)->r_sequential = (rdpcb)->r_sequential ||       \ 		(ntohs((u_short)(synopt)->rh_options)& RDP_oSEQUENTIAL); \ 	  sbreserve(&((rdpcb)->r_inpcb->inp_socket->so_snd),     \ 		(rdpcb)->r_hismaxlen - HDRSLOP);		 \ 	}
end_define

begin_comment
comment|/*  * Advisory and does not close connection.  Allows user to pick up any  * q'd received datagrams.  But, if there's no host-host communications  * then these probably aren't useful.  The real reason for advisory nature  * is that the user process knows best what to do, having contextual info.  * ??? break this up into specific code in state timeout functions ???  *  * RTTL occurs for 1) normal user datagrams, and 2) NULL messages  */
end_comment

begin_define
define|#
directive|define
name|rttl
parameter_list|(
name|rdpcb
parameter_list|)
define|\
value|{ struct socket *rttlso;					\ 									\ 	rttlso = (rdpcb)->r_inpcb->inp_socket;				\ 	if (rttlso->so_state& SS_NOFDREF)				\
comment|/*							\ 		 * was a child socket of a listen(2)er trying to	\ 		 * establish connection with other end.  RDP_sLSYNRCVD	\ 		 */
value|\ 		trash_pcbs(rdpcb);					\ 	else {								\ 		set_error(rdpcb, ETIMEDOUT);				\
comment|/*							\ 		 * sleeping in connect(2) and not using NBIO.		\ 		 * RDP_sSYNSENT (syn not acked yet)			\ 		 */
value|\ 		wakeup((caddr_t)&rttlso->so_timeo);			\
comment|/*							\ 		 * sleeping in write(2) waiting for buffer space	\ 		 * or sleeping in select(2).  RDP_sESTAB		\ 		 */
value|\ 		wakeup_writer(rdpcb);					\
comment|/*							\ 		 * sleeping in read(2) for datagram from other side	\ 		 * and NULL msgs imply connection lost RDP_sESTAB	\ 		 */
value|\ 		wakeup_reader(rdpcb);					\ 		(rdpcb)->r_timers[RDP_tRTTL] = (rdpcb)->r_rttl;		\ 	}}
end_define

begin_comment
comment|/*  * Pass datagram to user.  * On UNIX, mark end of datagram by setting m_act on last mbuf in chain.  */
end_comment

begin_define
define|#
directive|define
name|usr_rbuf_append
parameter_list|(
name|rdpcb
parameter_list|,
name|m
parameter_list|)
define|\
value|{ MBUF *x;						\ 	  for (x = (m); x->m_next; x = x->m_next)		\ 		;						\ 	  x->m_act = ((MBUF *) 1);				\ 	  sbappend(&(rdpcb)->r_inpcb->inp_socket->so_rcv, m);	\ 	}
end_define

begin_comment
comment|/*  * For in-line coding of the state transition function.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RDP_CS
end_ifdef

begin_define
define|#
directive|define
name|RDP_ACTION1
value|(rdpcb)->r_entered[newstate] = iptime();
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RDP_ACTION1
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|debug_rdpcb
parameter_list|(
name|r
parameter_list|)
value|((r)->r_inpcb->inp_socket->so_options& SO_DEBUG)
end_define

begin_define
define|#
directive|define
name|RDP_ACTION
parameter_list|(
name|input
parameter_list|,
name|rdpcb
parameter_list|,
name|arg
parameter_list|,
name|newstate
parameter_list|)
define|\
value|{ int	(*func)();						\ \ 	func = rdp_action_table[(rdpcb)->r_state][input];		\ 	if (! func){							\
comment|/*							\ 		 * invalid state transition, just print a message and ignore \ 		 */
value|\ 		printf("rdp bad transition: rdpcb 0x%x state %d input %d\n", \ 			(rdpcb), (rdpcb)->r_state, (input));		\ 		if (arg&& (input == RDP_iNETR))			\ 			m_freem(dtom(arg));				\ 		newstate = RDP_sSAME;					\ 	} else {							\ 		boolean debug_on;					\ \ 		debug_on = debug_rdpcb(rdpcb);				\ 		newstate = (*func)(rdpcb, arg);				\ 		if (debug_on)						\ 			rdp_debug (rdpcb, arg, input, newstate);	\ \
comment|/*							\ 		 * No longer have mbufs for protocol control blocks if closed \ 		 */
value|\ 		if ((newstate != RDP_sSAME)&& (newstate != RDP_sCLOSED)){ \ 			rdpcb->r_state = newstate;			\ 			RDP_ACTION1					\ 	} } }
end_define

end_unit

