begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	socketvar.h	4.14	82/01/19	*/
end_comment

begin_comment
comment|/*  * Kernel structure per socket.  * Contains send and receive buffer queues,  * handle on protocol and pointer to protocol  * private data and error information.  */
end_comment

begin_struct
struct|struct
name|socket
block|{
name|short
name|so_type
decl_stmt|;
comment|/* generic type, see socket.h */
name|short
name|so_options
decl_stmt|;
comment|/* from socket call, see socket.h */
name|short
name|so_linger
decl_stmt|;
comment|/* time to linger while closing */
name|short
name|so_state
decl_stmt|;
comment|/* internal state flags SS_*, below */
name|caddr_t
name|so_pcb
decl_stmt|;
comment|/* protocol control block */
name|struct
name|protosw
modifier|*
name|so_proto
decl_stmt|;
comment|/* protocol handle */
struct|struct
name|sockbuf
block|{
name|short
name|sb_cc
decl_stmt|;
comment|/* actual chars in buffer */
name|short
name|sb_hiwat
decl_stmt|;
comment|/* max actual char count */
name|short
name|sb_mbcnt
decl_stmt|;
comment|/* chars of mbufs used */
name|short
name|sb_mbmax
decl_stmt|;
comment|/* max chars of mbufs to use */
name|short
name|sb_lowat
decl_stmt|;
comment|/* low water mark (not used yet) */
name|short
name|sb_timeo
decl_stmt|;
comment|/* timeout (not used yet) */
name|struct
name|mbuf
modifier|*
name|sb_mb
decl_stmt|;
comment|/* the mbuf chain */
name|struct
name|proc
modifier|*
name|sb_sel
decl_stmt|;
comment|/* process selecting read/write */
name|short
name|sb_flags
decl_stmt|;
comment|/* flags, see below */
block|}
name|so_rcv
struct|,
name|so_snd
struct|;
define|#
directive|define
name|SB_LOCK
value|0x01
comment|/* lock on data queue (so_rcv only) */
define|#
directive|define
name|SB_WANT
value|0x02
comment|/* someone is waiting to lock */
define|#
directive|define
name|SB_WAIT
value|0x04
comment|/* someone is waiting for data/space */
define|#
directive|define
name|SB_SEL
value|0x08
comment|/* buffer is selected */
define|#
directive|define
name|SB_COLL
value|0x10
comment|/* collision selecting */
name|short
name|so_timeo
decl_stmt|;
comment|/* connection timeout */
name|u_short
name|so_error
decl_stmt|;
comment|/* error affecting connection */
name|struct
name|sockaddr
name|so_addr
decl_stmt|;
comment|/* socket address */
name|short
name|so_oobmark
decl_stmt|;
comment|/* chars to oob mark */
name|short
name|so_pgrp
decl_stmt|;
comment|/* pgrp for signals */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Socket state bits.  */
end_comment

begin_define
define|#
directive|define
name|SS_USERGONE
value|0x01
end_define

begin_comment
comment|/* no file table ref any more */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTED
value|0x02
end_define

begin_comment
comment|/* socket connected to a peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTING
value|0x04
end_define

begin_comment
comment|/* in process of connecting to peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISDISCONNECTING
value|0x08
end_define

begin_comment
comment|/* in process of disconnecting */
end_comment

begin_define
define|#
directive|define
name|SS_CANTSENDMORE
value|0x10
end_define

begin_comment
comment|/* can't send more data to peer */
end_comment

begin_define
define|#
directive|define
name|SS_CANTRCVMORE
value|0x20
end_define

begin_comment
comment|/* can't receive more data from peer */
end_comment

begin_define
define|#
directive|define
name|SS_CONNAWAITING
value|0x40
end_define

begin_comment
comment|/* connections awaiting acceptance */
end_comment

begin_define
define|#
directive|define
name|SS_RCVATMARK
value|0x80
end_define

begin_comment
comment|/* at mark on input */
end_comment

begin_comment
comment|/*  * Macros for sockets and socket buffering.  */
end_comment

begin_comment
comment|/* how much space is there in a socket buffer (so->so_snd or so->so_rcv) */
end_comment

begin_define
define|#
directive|define
name|sbspace
parameter_list|(
name|sb
parameter_list|)
define|\
value|(MIN((sb)->sb_hiwat-(sb)->sb_cc, ((sb)->sb_mbmax-(sb)->sb_mbcnt)))
end_define

begin_comment
comment|/* do we have to send all at once on a socket? */
end_comment

begin_define
define|#
directive|define
name|sosendallatonce
parameter_list|(
name|so
parameter_list|)
define|\
value|(((so)->so_options& SO_NONBLOCKING) || ((so)->so_proto->pr_flags& PR_ATOMIC))
end_define

begin_comment
comment|/* can we read something from so? */
end_comment

begin_define
define|#
directive|define
name|soreadable
parameter_list|(
name|so
parameter_list|)
define|\
value|((so)->so_rcv.sb_cc || ((so)->so_state& (SS_CANTRCVMORE|SS_CONNAWAITING)))
end_define

begin_comment
comment|/* can we write something to so? */
end_comment

begin_define
define|#
directive|define
name|sowriteable
parameter_list|(
name|so
parameter_list|)
define|\
value|(sbspace(&(so)->so_snd)> 0&& \ 	(((so)->so_state&SS_ISCONNECTED) || \ 	  ((so)->so_proto->pr_flags&PR_CONNREQUIRED)==0) || \      ((so)->so_state& SS_CANTSENDMORE))
end_define

begin_comment
comment|/* adjust counters in sb reflecting allocation of m */
end_comment

begin_define
define|#
directive|define
name|sballoc
parameter_list|(
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(sb)->sb_cc += (m)->m_len; \ 	(sb)->sb_mbcnt += MSIZE; \ 	if ((m)->m_off> MMAXOFF) \ 		(sb)->sb_mbcnt += CLBYTES; \ }
end_define

begin_comment
comment|/* adjust counters in sb reflecting freeing of m */
end_comment

begin_define
define|#
directive|define
name|sbfree
parameter_list|(
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(sb)->sb_cc -= (m)->m_len; \ 	(sb)->sb_mbcnt -= MSIZE; \ 	if ((m)->m_off> MMAXOFF) \ 		(sb)->sb_mbcnt -= CLBYTES; \ }
end_define

begin_comment
comment|/* set lock on sockbuf sb */
end_comment

begin_define
define|#
directive|define
name|sblock
parameter_list|(
name|sb
parameter_list|)
value|{ \ 	while ((sb)->sb_flags& SB_LOCK) { \ 		(sb)->sb_flags |= SB_WANT; \ 		sleep((caddr_t)&(sb)->sb_flags, PZERO+1); \ 	} \ 	(sb)->sb_flags |= SB_LOCK; \ }
end_define

begin_comment
comment|/* release lock on sockbuf sb */
end_comment

begin_define
define|#
directive|define
name|sbunlock
parameter_list|(
name|sb
parameter_list|)
value|{ \ 	(sb)->sb_flags&= ~SB_LOCK; \ 	if ((sb)->sb_flags& SB_WANT) { \ 		(sb)->sb_flags&= ~SB_WANT; \ 		wakeup((caddr_t)&(sb)->sb_flags); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sorwakeup
parameter_list|(
name|so
parameter_list|)
value|sbwakeup(&(so)->so_rcv)
end_define

begin_define
define|#
directive|define
name|sowwakeup
parameter_list|(
name|so
parameter_list|)
value|sbwakeup(&(so)->so_snd)
end_define

end_unit

