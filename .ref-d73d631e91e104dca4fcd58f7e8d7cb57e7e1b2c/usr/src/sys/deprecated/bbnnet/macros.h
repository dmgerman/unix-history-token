begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*** macros to simulate action() ***/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcprint
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TCP_DEBUG
parameter_list|(
name|soptr
parameter_list|,
name|tptr
parameter_list|,
name|wptr
parameter_list|,
name|act
parameter_list|,
name|newstate
parameter_list|)
define|\
value|if (soptr){ \ 		if ((soptr)->so_options& SO_DEBUG) { \ 			if (tcprint) \ 				printf("via 0x%x, ", fsactab[act]); \ 			tcp_debug(tptr, wptr, newstate); \ 		} \ 	}
end_define

begin_comment
comment|/*  * Simulates calls to action.  *	tp	valid tcpcb pointer ( == wp->w_tcb )  *	so	valid socket pointer ( == tp->t_in_pcb->inp_socket )  *	wp	valid work pointer  *	wtype	== wp->w_type, used so compiler can remove constant conditionals  *	wdat	== wp->w_dat  *  *	act, newstate	integers  *  * Remember that if the state transition results in CLOSED, then we have  * lost the mbuf(s) containing the tcpcb...  *  * moved tcp->net_keep to tcp_net_keep to avoid race condition since don't  * always have MBUF holding tcp after state transition function returns.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcp_net_keep
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ACTION
parameter_list|(
name|tp
parameter_list|,
name|so
parameter_list|,
name|wp
parameter_list|,
name|wtype
parameter_list|,
name|wdat
parameter_list|,
name|act
parameter_list|,
name|newstate
parameter_list|)
define|\
value|{	act = fstab[(tp)->t_state][wtype]; \ 	if (act == 0)  { \
comment|/* \ 		 * invalid state transition, just print a message and ignore \ 		 */
value|\ 		printf("tcp bad state: tcb=%x state=%d input=%d\n", \ 			tp, (tp)->t_state, wtype); \ 		if (wdat != NULL&& wtype == INRECV) \ 			m_freem(dtom(wdat)); \ 	} else { \ 		tcp_net_keep = FALSE; \ 		newstate = (*fsactab[act])(wp); \ 		TCP_DEBUG (so, tp, wp, act, newstate); \ 		if (wdat != NULL&& !tcp_net_keep&& wtype == INRECV) \ 			m_freem(dtom(wdat)); \ 		if ((newstate != SAME)&& (newstate != CLOSED)) \ 			(tp)->t_state = newstate; \ 	} \ }
end_define

begin_decl_stmt
specifier|extern
name|char
name|fstab
index|[
name|TCP_NSTATES
index|]
index|[
name|INOP
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|fsactab
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * like w_alloc() macro, but suitable for above ACTION.  */
end_comment

begin_define
define|#
directive|define
name|W_ALLOC
parameter_list|(
name|type
parameter_list|,
name|stype
parameter_list|,
name|tp
parameter_list|,
name|m
parameter_list|,
name|so
parameter_list|,
name|act
parameter_list|,
name|newstate
parameter_list|)
define|\
value|{									\ 	struct work w; \ 	w.w_type = type; w.w_stype = stype; w.w_tcb = tp; w.w_dat = (char *)m; \ 	ACTION(tp, so,&w, type, m, act, newstate); \ }
end_define

begin_comment
comment|/*  * Enqueue/dequeue segment on tcp sequencing queue  */
end_comment

begin_define
define|#
directive|define
name|TCP_ENQ
parameter_list|(
name|new
parameter_list|,
name|list
parameter_list|,
name|tp
parameter_list|)
define|\
value|{	(tp)->t_rcv_len += (new)->t_len; \ 	insque(new, list); \ }
end_define

begin_define
define|#
directive|define
name|TCP_DEQ
parameter_list|(
name|old
parameter_list|,
name|tp
parameter_list|)
define|\
value|{	(tp)->t_rcv_len -= (old)->t_len; \ 	remque(old); \ }
end_define

begin_comment
comment|/*  * Macro form of firstempty().  Find the first empty spot in rcv buffer.  */
end_comment

begin_define
define|#
directive|define
name|FIRSTEMPTY
parameter_list|(
name|tp
parameter_list|,
name|retval
parameter_list|)
define|\
value|{	register struct th *p; \  \ 	if ((p = (tp)->t_rcv_next) == (struct th *)(tp) || \ 	    SEQ_LT((tp)->rcv_nxt, p->t_seq)) \ 		retval = (tp)->rcv_nxt; \ 	else { \ 		register struct th *q; \  \ 		while ((q = p->t_next) != (struct th *)(tp)&& \ 		       SEQ_EQ(t_end(p)+1, q->t_seq)) \ 			p = q; \  \ 		retval = t_end(p) + 1; \ 	}}
end_define

begin_comment
comment|/*  * macro form of present_data().  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|extract_oob
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PRESENT_DATA
parameter_list|(
name|tp
parameter_list|)
define|\
value|{ \
comment|/* connection must be synced and data available for user */
value|\  \ 	if ((tp)->syn_acked){ \ 		register struct th *t; \ 			 struct socket *so; \  \ 		so = (tp)->t_in_pcb->inp_socket; \ 		if ((t = (tp)->t_rcv_next) != (struct th *)(tp)) { \
comment|/* \ 		     * move as many mbufs as possible from tcb \ 		     * to user queue.  Used to use firstempty(), \ 		     * but that caused traversal of list twice. \ 		     */
value|\ 		    if (SEQ_LEQ(t->t_seq, (tp)->rcv_nxt)) { \ 		        register struct sockbuf *sorcv; \ 			register int	done; \ 			register struct mbuf *m; \ 			register struct th *next; \  \ 		        sorcv =&so->so_rcv; \ 			done = FALSE; \ 			while (sbspace(sorcv)> 0&& !done) { \
comment|/* \ 				 * Note order of events: sbappend tries to \ 				 * coalesce mbufs, so if get a packet in, it \ 				 * may use the mbuf that sbappend may free. \ 				 */
value|\  \
comment|/* dequeue chunk from tcb */
value|\  \ 				next = t->t_next; \ 				TCP_DEQ(t, tp); \ 				m = dtom(t); \  \
comment|/* \ 				 * check for end of list and gaps. \ 				 */
value|\ 				if ((next == (struct th *)tp) || \ 				    (t_end(t)+1 != next->t_seq)) \ 					done = TRUE; \  \
comment|/* SS_CANTRCVMORE == usr_abort */
value|\ 				if (so->so_state& SS_CANTRCVMORE) \ 					m_freem(m); \ 				else { \
comment|/* \ 					 * remove urgent data from input stream\ 					 */
value|\ 					if (SEQ_GEQ((tp)->rcv_urpend, (tp)->rcv_urp)) \ 						m = extract_oob(tp, m, sorcv); \  \ 					if (m) \
comment|/* \ 						 * chain new data to user \ 						 * receive buf \ 						 */
value|\ 						sbappend(sorcv, m); \ 				} \  \ 				t = next; \ 			} \  \
comment|/* awaken reader only if any data on user rcv queue */
value|\ 		        if (sorcv->sb_cc> 0) \ 				sbwakeup(sorcv); \ 		    } \ 		} \  \
comment|/* let user know about foreign tcp close if no more data \ 		 * OR if no data ever transferred. \ 		 */
value|\  \ 		if ((tp)->fin_rcvd&&
comment|/* !tp->usr_closed&& */
value|rcv_empty(tp)) \ 			socantrcvmore(so); \ 	}}
end_define

end_unit

