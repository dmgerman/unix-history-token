begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)socketvar.h	7.22 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_comment
comment|/* for struct selinfo */
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
comment|/*  * Variables for connection queueing.  * Socket where accepts occur is so_head in all subsidiary sockets.  * If so_head is 0, socket is not related to an accept.  * For head socket so_q0 queues partially completed connections,  * while so_q is a queue of connections ready to be accepted.  * If a connection is aborted and it has so_head set, then  * it has to be pulled out of either so_q0 or so_q.  * We allow connections to queue up based on current queue lengths  * and limit on number of queued connections for this socket.  */
name|struct
name|socket
modifier|*
name|so_head
decl_stmt|;
comment|/* back pointer to accept socket */
name|struct
name|socket
modifier|*
name|so_q0
decl_stmt|;
comment|/* queue of partial connections */
name|struct
name|socket
modifier|*
name|so_q
decl_stmt|;
comment|/* queue of incoming connections */
name|short
name|so_q0len
decl_stmt|;
comment|/* partials on so_q0 */
name|short
name|so_qlen
decl_stmt|;
comment|/* number of connections on so_q */
name|short
name|so_qlimit
decl_stmt|;
comment|/* max number queued connections */
name|short
name|so_timeo
decl_stmt|;
comment|/* connection timeout */
name|u_short
name|so_error
decl_stmt|;
comment|/* error affecting connection */
name|pid_t
name|so_pgid
decl_stmt|;
comment|/* pgid for signals */
name|u_long
name|so_oobmark
decl_stmt|;
comment|/* chars to oob mark */
comment|/*  * Variables for socket buffering.  */
struct|struct
name|sockbuf
block|{
name|u_long
name|sb_cc
decl_stmt|;
comment|/* actual chars in buffer */
name|u_long
name|sb_hiwat
decl_stmt|;
comment|/* max actual char count */
name|u_long
name|sb_mbcnt
decl_stmt|;
comment|/* chars of mbufs used */
name|u_long
name|sb_mbmax
decl_stmt|;
comment|/* max chars of mbufs to use */
name|long
name|sb_lowat
decl_stmt|;
comment|/* low water mark */
name|struct
name|mbuf
modifier|*
name|sb_mb
decl_stmt|;
comment|/* the mbuf chain */
name|struct
name|selinfo
name|sb_sel
decl_stmt|;
comment|/* process selecting read/write */
name|short
name|sb_flags
decl_stmt|;
comment|/* flags, see below */
name|short
name|sb_timeo
decl_stmt|;
comment|/* timeout for read/write */
block|}
name|so_rcv
struct|,
name|so_snd
struct|;
define|#
directive|define
name|SB_MAX
value|(256*1024)
comment|/* default for max chars in sockbuf */
define|#
directive|define
name|SB_LOCK
value|0x01
comment|/* lock on data queue */
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
comment|/* someone is selecting */
define|#
directive|define
name|SB_ASYNC
value|0x10
comment|/* ASYNC I/O, need signals */
define|#
directive|define
name|SB_NOTIFY
value|(SB_WAIT|SB_SEL|SB_ASYNC)
define|#
directive|define
name|SB_NOINTR
value|0x40
comment|/* operations not interruptible */
name|caddr_t
name|so_tpcb
decl_stmt|;
comment|/* Wisc. protocol control block XXX */
name|void
argument_list|(
argument|*so_upcall
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|caddr_t
name|arg
operator|,
name|int
name|waitf
operator|)
argument_list|)
expr_stmt|;
name|caddr_t
name|so_upcallarg
decl_stmt|;
comment|/* Arg for above */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Socket state bits.  */
end_comment

begin_define
define|#
directive|define
name|SS_NOFDREF
value|0x001
end_define

begin_comment
comment|/* no file table ref any more */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTED
value|0x002
end_define

begin_comment
comment|/* socket connected to a peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTING
value|0x004
end_define

begin_comment
comment|/* in process of connecting to peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISDISCONNECTING
value|0x008
end_define

begin_comment
comment|/* in process of disconnecting */
end_comment

begin_define
define|#
directive|define
name|SS_CANTSENDMORE
value|0x010
end_define

begin_comment
comment|/* can't send more data to peer */
end_comment

begin_define
define|#
directive|define
name|SS_CANTRCVMORE
value|0x020
end_define

begin_comment
comment|/* can't receive more data from peer */
end_comment

begin_define
define|#
directive|define
name|SS_RCVATMARK
value|0x040
end_define

begin_comment
comment|/* at mark on input */
end_comment

begin_define
define|#
directive|define
name|SS_PRIV
value|0x080
end_define

begin_comment
comment|/* privileged for broadcast, raw... */
end_comment

begin_define
define|#
directive|define
name|SS_NBIO
value|0x100
end_define

begin_comment
comment|/* non-blocking ops */
end_comment

begin_define
define|#
directive|define
name|SS_ASYNC
value|0x200
end_define

begin_comment
comment|/* async i/o notify */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONFIRMING
value|0x400
end_define

begin_comment
comment|/* deciding to accept connection req */
end_comment

begin_comment
comment|/*  * Macros for sockets and socket buffering.  */
end_comment

begin_comment
comment|/*  * How much space is there in a socket buffer (so->so_snd or so->so_rcv)?  * This is problematical if the fields are unsigned, as the space might  * still be negative (cc> hiwat or mbcnt> mbmax).  Should detect  * overflow and return 0.  Should use "lmin" but it doesn't exist now.  */
end_comment

begin_define
define|#
directive|define
name|sbspace
parameter_list|(
name|sb
parameter_list|)
define|\
value|((long) imin((int)((sb)->sb_hiwat - (sb)->sb_cc), \ 	 (int)((sb)->sb_mbmax - (sb)->sb_mbcnt)))
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
value|((so)->so_proto->pr_flags& PR_ATOMIC)
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
value|((so)->so_rcv.sb_cc>= (so)->so_rcv.sb_lowat || \ 	((so)->so_state& SS_CANTRCVMORE) || \ 	(so)->so_qlen || (so)->so_error)
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
value|(sbspace(&(so)->so_snd)>= (so)->so_snd.sb_lowat&& \ 	(((so)->so_state&SS_ISCONNECTED) || \ 	  ((so)->so_proto->pr_flags&PR_CONNREQUIRED)==0) || \      ((so)->so_state& SS_CANTSENDMORE) || \      (so)->so_error)
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
value|{ \ 	(sb)->sb_cc += (m)->m_len; \ 	(sb)->sb_mbcnt += MSIZE; \ 	if ((m)->m_flags& M_EXT) \ 		(sb)->sb_mbcnt += (m)->m_ext.ext_size; \ }
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
value|{ \ 	(sb)->sb_cc -= (m)->m_len; \ 	(sb)->sb_mbcnt -= MSIZE; \ 	if ((m)->m_flags& M_EXT) \ 		(sb)->sb_mbcnt -= (m)->m_ext.ext_size; \ }
end_define

begin_comment
comment|/*  * Set lock on sockbuf sb; sleep if lock is already held.  * Unless SB_NOINTR is set on sockbuf, sleep is interruptible.  * Returns error without lock if sleep is interrupted.  */
end_comment

begin_define
define|#
directive|define
name|sblock
parameter_list|(
name|sb
parameter_list|,
name|wf
parameter_list|)
value|((sb)->sb_flags& SB_LOCK ? \ 		(((wf) == M_WAITOK) ? sb_lock(sb) : EWOULDBLOCK) : \ 		((sb)->sb_flags |= SB_LOCK), 0)
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
value|{ sowakeup((so),&(so)->so_rcv); \ 			  if ((so)->so_upcall) \ 			    (*((so)->so_upcall))((so), (so)->so_upcallarg, M_DONTWAIT); \ 			}
end_define

begin_define
define|#
directive|define
name|sowwakeup
parameter_list|(
name|so
parameter_list|)
value|sowakeup((so),&(so)->so_snd)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|u_long
name|sb_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to catch callers missing new second argument to sonewconn: */
end_comment

begin_define
define|#
directive|define
name|sonewconn
parameter_list|(
name|head
parameter_list|,
name|connstatus
parameter_list|)
value|sonewconn1((head), (connstatus))
end_define

begin_decl_stmt
name|struct
name|socket
modifier|*
name|sonewconn1
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|head
operator|,
name|int
name|connstatus
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* strings for sleep message: */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|netio
index|[]
decl_stmt|,
name|netcon
index|[]
decl_stmt|,
name|netcls
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * File operations on sockets.  */
end_comment

begin_decl_stmt
name|int
name|soo_read
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|soo_write
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|soo_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
name|int
name|com
operator|,
name|caddr_t
name|data
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
name|soo_select
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
name|int
name|which
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
name|soo_close
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

