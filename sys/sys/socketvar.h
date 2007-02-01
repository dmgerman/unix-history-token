begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)socketvar.h	8.3 (Berkeley) 2/19/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SOCKETVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SOCKETVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* for TAILQ macros */
end_comment

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_comment
comment|/* for struct selinfo */
end_comment

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_comment
comment|/*  * Kernel structure per socket.  * Contains send and receive buffer queues,  * handle on protocol and pointer to protocol  * private data and error information.  */
end_comment

begin_typedef
typedef|typedef
name|u_quad_t
name|so_gen_t
typedef|;
end_typedef

begin_comment
comment|/*-  * Locking key to struct socket:  * (a) constant after allocation, no locking required.  * (b) locked by SOCK_LOCK(so).  * (c) locked by SOCKBUF_LOCK(&so->so_rcv).  * (d) locked by SOCKBUF_LOCK(&so->so_snd).  * (e) locked by ACCEPT_LOCK().  * (f) not locked since integer reads/writes are atomic.  * (g) used only as a sleep/wakeup address, no value.  * (h) locked by global mutex so_global_mtx.  */
end_comment

begin_struct
struct|struct
name|socket
block|{
name|int
name|so_count
decl_stmt|;
comment|/* (b) reference count */
name|short
name|so_type
decl_stmt|;
comment|/* (a) generic type, see socket.h */
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
comment|/* (b) internal state flags SS_* */
name|int
name|so_qstate
decl_stmt|;
comment|/* (e) internal state flags SQ_* */
name|void
modifier|*
name|so_pcb
decl_stmt|;
comment|/* protocol control block */
name|struct
name|protosw
modifier|*
name|so_proto
decl_stmt|;
comment|/* (a) protocol handle */
comment|/*  * Variables for connection queuing.  * Socket where accepts occur is so_head in all subsidiary sockets.  * If so_head is 0, socket is not related to an accept.  * For head socket so_incomp queues partially completed connections,  * while so_comp is a queue of connections ready to be accepted.  * If a connection is aborted and it has so_head set, then  * it has to be pulled out of either so_incomp or so_comp.  * We allow connections to queue up based on current queue lengths  * and limit on number of queued connections for this socket.  */
name|struct
name|socket
modifier|*
name|so_head
decl_stmt|;
comment|/* (e) back pointer to listen socket */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|socket
argument_list|)
name|so_incomp
expr_stmt|;
comment|/* (e) queue of partial unaccepted connections */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|socket
argument_list|)
name|so_comp
expr_stmt|;
comment|/* (e) queue of complete unaccepted connections */
name|TAILQ_ENTRY
argument_list|(
argument|socket
argument_list|)
name|so_list
expr_stmt|;
comment|/* (e) list of unaccepted connections */
name|u_short
name|so_qlen
decl_stmt|;
comment|/* (e) number of unaccepted connections */
name|u_short
name|so_incqlen
decl_stmt|;
comment|/* (e) number of unaccepted incomplete 					   connections */
name|u_short
name|so_qlimit
decl_stmt|;
comment|/* (e) max number queued connections */
name|short
name|so_timeo
decl_stmt|;
comment|/* (g) connection timeout */
name|u_short
name|so_error
decl_stmt|;
comment|/* (f) error affecting connection */
name|struct
name|sigio
modifier|*
name|so_sigio
decl_stmt|;
comment|/* [sg] information for async I/O or 					   out of band data (SIGURG) */
name|u_long
name|so_oobmark
decl_stmt|;
comment|/* (c) chars to oob mark */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|aiocblist
argument_list|)
name|so_aiojobq
expr_stmt|;
comment|/* AIO ops waiting on socket */
comment|/*  * Variables for socket buffering.  */
struct|struct
name|sockbuf
block|{
name|struct
name|selinfo
name|sb_sel
decl_stmt|;
comment|/* process selecting read/write */
name|struct
name|mtx
name|sb_mtx
decl_stmt|;
comment|/* sockbuf lock */
name|short
name|sb_state
decl_stmt|;
comment|/* (c/d) socket state on sockbuf */
define|#
directive|define
name|sb_startzero
value|sb_mb
name|struct
name|mbuf
modifier|*
name|sb_mb
decl_stmt|;
comment|/* (c/d) the mbuf chain */
name|struct
name|mbuf
modifier|*
name|sb_mbtail
decl_stmt|;
comment|/* (c/d) the last mbuf in the chain */
name|struct
name|mbuf
modifier|*
name|sb_lastrecord
decl_stmt|;
comment|/* (c/d) first mbuf of last 						 * record in socket buffer */
name|u_int
name|sb_cc
decl_stmt|;
comment|/* (c/d) actual chars in buffer */
name|u_int
name|sb_hiwat
decl_stmt|;
comment|/* (c/d) max actual char count */
name|u_int
name|sb_mbcnt
decl_stmt|;
comment|/* (c/d) chars of mbufs used */
name|u_int
name|sb_mbmax
decl_stmt|;
comment|/* (c/d) max chars of mbufs to use */
name|u_int
name|sb_ctl
decl_stmt|;
comment|/* (c/d) non-data chars in buffer */
name|int
name|sb_lowat
decl_stmt|;
comment|/* (c/d) low water mark */
name|int
name|sb_timeo
decl_stmt|;
comment|/* (c/d) timeout for read/write */
name|short
name|sb_flags
decl_stmt|;
comment|/* (c/d) flags, see below */
block|}
name|so_rcv
struct|,
name|so_snd
struct|;
comment|/*  * Constants for sb_flags field of struct sockbuf.  */
define|#
directive|define
name|SB_MAX
value|(256*1024)
comment|/* default for max chars in sockbuf */
comment|/*  * Constants for sb_flags field of struct sockbuf.  */
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
name|SB_UPCALL
value|0x20
comment|/* someone wants an upcall */
define|#
directive|define
name|SB_NOINTR
value|0x40
comment|/* operations not interruptible */
define|#
directive|define
name|SB_AIO
value|0x80
comment|/* AIO operations queued */
define|#
directive|define
name|SB_KNOTE
value|0x100
comment|/* kernel note attached */
define|#
directive|define
name|SB_AUTOSIZE
value|0x800
comment|/* automatically size socket buffer */
name|void
function_decl|(
modifier|*
name|so_upcall
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
modifier|*
name|so_upcallarg
decl_stmt|;
name|struct
name|ucred
modifier|*
name|so_cred
decl_stmt|;
comment|/* (a) user credentials */
name|struct
name|label
modifier|*
name|so_label
decl_stmt|;
comment|/* (b) MAC label for socket */
name|struct
name|label
modifier|*
name|so_peerlabel
decl_stmt|;
comment|/* (b) cached MAC label for peer */
comment|/* NB: generation count must not be first. */
name|so_gen_t
name|so_gencnt
decl_stmt|;
comment|/* (h) generation count */
name|void
modifier|*
name|so_emuldata
decl_stmt|;
comment|/* (b) private data for emulators */
struct|struct
name|so_accf
block|{
name|struct
name|accept_filter
modifier|*
name|so_accept_filter
decl_stmt|;
name|void
modifier|*
name|so_accept_filter_arg
decl_stmt|;
comment|/* saved filter args */
name|char
modifier|*
name|so_accept_filter_str
decl_stmt|;
comment|/* saved user args */
block|}
modifier|*
name|so_accf
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SB_EMPTY_FIXUP
parameter_list|(
name|sb
parameter_list|)
value|do {						\ 	if ((sb)->sb_mb == NULL) {					\ 		(sb)->sb_mbtail = NULL;					\ 		(sb)->sb_lastrecord = NULL;				\ 	}								\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_comment
comment|/*  * Global accept mutex to serialize access to accept queues and  * fields associated with multiple sockets.  This allows us to  * avoid defining a lock order between listen and accept sockets  * until such time as it proves to be a good idea.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|accept_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ACCEPT_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&accept_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ACCEPT_UNLOCK_ASSERT
parameter_list|()
value|mtx_assert(&accept_mtx, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|ACCEPT_LOCK
parameter_list|()
value|mtx_lock(&accept_mtx)
end_define

begin_define
define|#
directive|define
name|ACCEPT_UNLOCK
parameter_list|()
value|mtx_unlock(&accept_mtx)
end_define

begin_comment
comment|/*  * Per-socket buffer mutex used to protect most fields in the socket  * buffer.  */
end_comment

begin_define
define|#
directive|define
name|SOCKBUF_MTX
parameter_list|(
name|_sb
parameter_list|)
value|(&(_sb)->sb_mtx)
end_define

begin_define
define|#
directive|define
name|SOCKBUF_LOCK_INIT
parameter_list|(
name|_sb
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(SOCKBUF_MTX(_sb), _name, NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|SOCKBUF_LOCK_DESTROY
parameter_list|(
name|_sb
parameter_list|)
value|mtx_destroy(SOCKBUF_MTX(_sb))
end_define

begin_define
define|#
directive|define
name|SOCKBUF_LOCK
parameter_list|(
name|_sb
parameter_list|)
value|mtx_lock(SOCKBUF_MTX(_sb))
end_define

begin_define
define|#
directive|define
name|SOCKBUF_OWNED
parameter_list|(
name|_sb
parameter_list|)
value|mtx_owned(SOCKBUF_MTX(_sb))
end_define

begin_define
define|#
directive|define
name|SOCKBUF_UNLOCK
parameter_list|(
name|_sb
parameter_list|)
value|mtx_unlock(SOCKBUF_MTX(_sb))
end_define

begin_define
define|#
directive|define
name|SOCKBUF_LOCK_ASSERT
parameter_list|(
name|_sb
parameter_list|)
value|mtx_assert(SOCKBUF_MTX(_sb), MA_OWNED)
end_define

begin_define
define|#
directive|define
name|SOCKBUF_UNLOCK_ASSERT
parameter_list|(
name|_sb
parameter_list|)
value|mtx_assert(SOCKBUF_MTX(_sb), MA_NOTOWNED)
end_define

begin_comment
comment|/*  * Per-socket mutex: we reuse the receive socket buffer mutex for space  * efficiency.  This decision should probably be revisited as we optimize  * locking for the socket code.  */
end_comment

begin_define
define|#
directive|define
name|SOCK_MTX
parameter_list|(
name|_so
parameter_list|)
value|SOCKBUF_MTX(&(_so)->so_rcv)
end_define

begin_define
define|#
directive|define
name|SOCK_LOCK
parameter_list|(
name|_so
parameter_list|)
value|SOCKBUF_LOCK(&(_so)->so_rcv)
end_define

begin_define
define|#
directive|define
name|SOCK_OWNED
parameter_list|(
name|_so
parameter_list|)
value|SOCKBUF_OWNED(&(_so)->so_rcv)
end_define

begin_define
define|#
directive|define
name|SOCK_UNLOCK
parameter_list|(
name|_so
parameter_list|)
value|SOCKBUF_UNLOCK(&(_so)->so_rcv)
end_define

begin_define
define|#
directive|define
name|SOCK_LOCK_ASSERT
parameter_list|(
name|_so
parameter_list|)
value|SOCKBUF_LOCK_ASSERT(&(_so)->so_rcv)
end_define

begin_comment
comment|/*  * Socket state bits.  *  * Historically, this bits were all kept in the so_state field.  For  * locking reasons, they are now in multiple fields, as they are  * locked differently.  so_state maintains basic socket state protected  * by the socket lock.  so_qstate holds information about the socket  * accept queues.  Each socket buffer also has a state field holding  * information relevant to that socket buffer (can't send, rcv).  Many  * fields will be read without locks to improve performance and avoid  * lock order issues.  However, this approach must be used with caution.  */
end_comment

begin_define
define|#
directive|define
name|SS_NOFDREF
value|0x0001
end_define

begin_comment
comment|/* no file table ref any more */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTED
value|0x0002
end_define

begin_comment
comment|/* socket connected to a peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONNECTING
value|0x0004
end_define

begin_comment
comment|/* in process of connecting to peer */
end_comment

begin_define
define|#
directive|define
name|SS_ISDISCONNECTING
value|0x0008
end_define

begin_comment
comment|/* in process of disconnecting */
end_comment

begin_define
define|#
directive|define
name|SS_NBIO
value|0x0100
end_define

begin_comment
comment|/* non-blocking ops */
end_comment

begin_define
define|#
directive|define
name|SS_ASYNC
value|0x0200
end_define

begin_comment
comment|/* async i/o notify */
end_comment

begin_define
define|#
directive|define
name|SS_ISCONFIRMING
value|0x0400
end_define

begin_comment
comment|/* deciding to accept connection req */
end_comment

begin_define
define|#
directive|define
name|SS_ISDISCONNECTED
value|0x2000
end_define

begin_comment
comment|/* socket disconnected from peer */
end_comment

begin_comment
comment|/*  * Protocols can mark a socket as SS_PROTOREF to indicate that, following  * pru_detach, they still want the socket to persist, and will free it  * themselves when they are done.  Protocols should only ever call sofree()  * following setting this flag in pru_detach(), and never otherwise, as  * sofree() bypasses socket reference counting.  */
end_comment

begin_define
define|#
directive|define
name|SS_PROTOREF
value|0x4000
end_define

begin_comment
comment|/* strong protocol reference */
end_comment

begin_comment
comment|/*  * Socket state bits now stored in the socket buffer state field.  */
end_comment

begin_define
define|#
directive|define
name|SBS_CANTSENDMORE
value|0x0010
end_define

begin_comment
comment|/* can't send more data to peer */
end_comment

begin_define
define|#
directive|define
name|SBS_CANTRCVMORE
value|0x0020
end_define

begin_comment
comment|/* can't receive more data from peer */
end_comment

begin_define
define|#
directive|define
name|SBS_RCVATMARK
value|0x0040
end_define

begin_comment
comment|/* at mark on input */
end_comment

begin_comment
comment|/*  * Socket state bits stored in so_qstate.  */
end_comment

begin_define
define|#
directive|define
name|SQ_INCOMP
value|0x0800
end_define

begin_comment
comment|/* unaccepted, incomplete connection */
end_comment

begin_define
define|#
directive|define
name|SQ_COMP
value|0x1000
end_define

begin_comment
comment|/* unaccepted, complete connection */
end_comment

begin_comment
comment|/*  * Externalized form of struct socket used by the sysctl(3) interface.  */
end_comment

begin_struct
struct|struct
name|xsocket
block|{
name|size_t
name|xso_len
decl_stmt|;
comment|/* length of this structure */
name|struct
name|socket
modifier|*
name|xso_so
decl_stmt|;
comment|/* makes a convenient handle sometimes */
name|short
name|so_type
decl_stmt|;
name|short
name|so_options
decl_stmt|;
name|short
name|so_linger
decl_stmt|;
name|short
name|so_state
decl_stmt|;
name|caddr_t
name|so_pcb
decl_stmt|;
comment|/* another convenient handle */
name|int
name|xso_protocol
decl_stmt|;
name|int
name|xso_family
decl_stmt|;
name|u_short
name|so_qlen
decl_stmt|;
name|u_short
name|so_incqlen
decl_stmt|;
name|u_short
name|so_qlimit
decl_stmt|;
name|short
name|so_timeo
decl_stmt|;
name|u_short
name|so_error
decl_stmt|;
name|pid_t
name|so_pgid
decl_stmt|;
name|u_long
name|so_oobmark
decl_stmt|;
struct|struct
name|xsockbuf
block|{
name|u_int
name|sb_cc
decl_stmt|;
name|u_int
name|sb_hiwat
decl_stmt|;
name|u_int
name|sb_mbcnt
decl_stmt|;
name|u_int
name|sb_mbmax
decl_stmt|;
name|int
name|sb_lowat
decl_stmt|;
name|int
name|sb_timeo
decl_stmt|;
name|short
name|sb_flags
decl_stmt|;
block|}
name|so_rcv
struct|,
name|so_snd
struct|;
name|uid_t
name|so_uid
decl_stmt|;
comment|/* XXX */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Macros for sockets and socket buffering.  */
end_comment

begin_comment
comment|/*  * Do we need to notify the other side when I/O is possible?  */
end_comment

begin_define
define|#
directive|define
name|sb_notify
parameter_list|(
name|sb
parameter_list|)
value|(((sb)->sb_flags& (SB_WAIT | SB_SEL | SB_ASYNC | \     SB_UPCALL | SB_AIO | SB_KNOTE)) != 0)
end_define

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
value|((so)->so_rcv.sb_cc>= (so)->so_rcv.sb_lowat || \ 	((so)->so_rcv.sb_state& SBS_CANTRCVMORE) || \ 	!TAILQ_EMPTY(&(so)->so_comp) || (so)->so_error)
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
value|((sbspace(&(so)->so_snd)>= (so)->so_snd.sb_lowat&& \ 	(((so)->so_state&SS_ISCONNECTED) || \ 	  ((so)->so_proto->pr_flags&PR_CONNREQUIRED)==0)) || \      ((so)->so_snd.sb_state& SBS_CANTSENDMORE) || \      (so)->so_error)
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
value|{ \ 	(sb)->sb_cc += (m)->m_len; \ 	if ((m)->m_type != MT_DATA&& (m)->m_type != MT_OOBDATA) \ 		(sb)->sb_ctl += (m)->m_len; \ 	(sb)->sb_mbcnt += MSIZE; \ 	if ((m)->m_flags& M_EXT) \ 		(sb)->sb_mbcnt += (m)->m_ext.ext_size; \ }
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
value|{ \ 	(sb)->sb_cc -= (m)->m_len; \ 	if ((m)->m_type != MT_DATA&& (m)->m_type != MT_OOBDATA) \ 		(sb)->sb_ctl -= (m)->m_len; \ 	(sb)->sb_mbcnt -= MSIZE; \ 	if ((m)->m_flags& M_EXT) \ 		(sb)->sb_mbcnt -= (m)->m_ext.ext_size; \ }
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
value|do { \ 	SOCKBUF_LOCK_ASSERT(sb); \ 	(sb)->sb_flags&= ~SB_LOCK; \ 	if ((sb)->sb_flags& SB_WANT) { \ 		(sb)->sb_flags&= ~SB_WANT; \ 		wakeup(&(sb)->sb_flags); \ 	} \ } while (0)
end_define

begin_comment
comment|/*  * soref()/sorele() ref-count the socket structure.  Note that you must  * still explicitly close the socket, but the last ref count will free  * the structure.  */
end_comment

begin_define
define|#
directive|define
name|soref
parameter_list|(
name|so
parameter_list|)
value|do {							\ 	SOCK_LOCK_ASSERT(so);						\ 	++(so)->so_count;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|sorele
parameter_list|(
name|so
parameter_list|)
value|do {							\ 	ACCEPT_LOCK_ASSERT();						\ 	SOCK_LOCK_ASSERT(so);						\ 	if ((so)->so_count<= 0)					\ 		panic("sorele");					\ 	if (--(so)->so_count == 0)					\ 		sofree(so);						\ 	else {								\ 		SOCK_UNLOCK(so);					\ 		ACCEPT_UNLOCK();					\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|sotryfree
parameter_list|(
name|so
parameter_list|)
value|do {						\ 	ACCEPT_LOCK_ASSERT();						\ 	SOCK_LOCK_ASSERT(so);						\ 	if ((so)->so_count == 0)					\ 		sofree(so);						\ 	else {								\ 		SOCK_UNLOCK(so);					\ 		ACCEPT_UNLOCK();					\ 	}								\ } while(0)
end_define

begin_comment
comment|/*  * In sorwakeup() and sowwakeup(), acquire the socket buffer lock to  * avoid a non-atomic test-and-wakeup.  However, sowakeup is  * responsible for releasing the lock if it is called.  We unlock only  * if we don't call into sowakeup.  If any code is introduced that  * directly invokes the underlying sowakeup() primitives, it must  * maintain the same semantics.  */
end_comment

begin_define
define|#
directive|define
name|sorwakeup_locked
parameter_list|(
name|so
parameter_list|)
value|do {					\ 	SOCKBUF_LOCK_ASSERT(&(so)->so_rcv);				\ 	if (sb_notify(&(so)->so_rcv))					\ 		sowakeup((so),&(so)->so_rcv);	 			\ 	else								\ 		SOCKBUF_UNLOCK(&(so)->so_rcv);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|sorwakeup
parameter_list|(
name|so
parameter_list|)
value|do {						\ 	SOCKBUF_LOCK(&(so)->so_rcv);					\ 	sorwakeup_locked(so);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|sowwakeup_locked
parameter_list|(
name|so
parameter_list|)
value|do {					\ 	SOCKBUF_LOCK_ASSERT(&(so)->so_snd);				\ 	if (sb_notify(&(so)->so_snd))					\ 		sowakeup((so),&(so)->so_snd); 				\ 	else								\ 		SOCKBUF_UNLOCK(&(so)->so_snd);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|sowwakeup
parameter_list|(
name|so
parameter_list|)
value|do {						\ 	SOCKBUF_LOCK(&(so)->so_snd);					\ 	sowwakeup_locked(so);						\ } while (0)
end_define

begin_comment
comment|/*  * Argument structure for sosetopt et seq.  This is in the KERNEL  * section because it will never be visible to user code.  */
end_comment

begin_enum
enum|enum
name|sopt_dir
block|{
name|SOPT_GET
block|,
name|SOPT_SET
block|}
enum|;
end_enum

begin_struct
struct|struct
name|sockopt
block|{
name|enum
name|sopt_dir
name|sopt_dir
decl_stmt|;
comment|/* is this a get or a set? */
name|int
name|sopt_level
decl_stmt|;
comment|/* second arg of [gs]etsockopt */
name|int
name|sopt_name
decl_stmt|;
comment|/* third arg of [gs]etsockopt */
name|void
modifier|*
name|sopt_val
decl_stmt|;
comment|/* fourth arg of [gs]etsockopt */
name|size_t
name|sopt_valsize
decl_stmt|;
comment|/* (almost) fifth arg of [gs]etsockopt */
name|struct
name|thread
modifier|*
name|sopt_td
decl_stmt|;
comment|/* calling thread or null if kernel */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|accept_filter
block|{
name|char
name|accf_name
index|[
literal|16
index|]
decl_stmt|;
name|void
function_decl|(
modifier|*
name|accf_callback
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|waitflag
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|accf_create
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|char
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|accf_destroy
function_decl|)
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
name|SLIST_ENTRY
argument_list|(
argument|accept_filter
argument_list|)
name|accf_next
expr_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ACCF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_PCB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_SONAME
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|maxsockets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|sb_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uma_zone
modifier|*
name|socket_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|so_gen_t
name|so_gencnt
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
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
comment|/*  * From uipc_socket and friends  */
end_comment

begin_function_decl
name|int
name|do_getopt_accept_filter
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_setopt_accept_filter
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|so_setsockopt
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|optname
parameter_list|,
name|void
modifier|*
name|optval
parameter_list|,
name|size_t
name|optlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sockargs
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|int
name|buflen
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getsockaddr
parameter_list|(
name|struct
name|sockaddr
modifier|*
modifier|*
name|namp
parameter_list|,
name|caddr_t
name|uaddr
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappend
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappend_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendstream
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendstream_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbappendaddr
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|asa
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbappendaddr_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|asa
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbappendcontrol
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbappendcontrol_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|mbuf
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendrecord
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbappendrecord_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbcheck
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbcompress
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|mbuf
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|sbcreatecontrol
parameter_list|(
name|caddr_t
name|p
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdestroy
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdrop
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdrop_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdroprecord
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbdroprecord_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbflush
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbflush_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbrelease
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbrelease_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbreserve
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|u_long
name|cc
parameter_list|,
name|struct
name|socket
modifier|*
name|so
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
name|sbreserve_locked
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|u_long
name|cc
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sbtoxsockbuf
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|,
name|struct
name|xsockbuf
modifier|*
name|xsb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sbwait
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sb_lock
parameter_list|(
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soabort
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
name|soaccept
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
name|socheckuid
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|uid_t
name|uid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sobind
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
name|void
name|socantrcvmore
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantrcvmore_locked
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantsendmore
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|socantsendmore_locked
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
name|soclose
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
name|soconnect
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
name|soconnect2
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
name|socow_setup
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|socreate
parameter_list|(
name|int
name|dom
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
name|aso
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|proto
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

begin_function_decl
name|int
name|sodisconnect
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sockaddr
modifier|*
name|sodupsockaddr
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
name|int
name|mflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sofree
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
name|sogetopt
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sohasoutofband
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisconnected
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisconnecting
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisdisconnected
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soisdisconnecting
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
name|solisten
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
name|void
name|solisten_proto
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|backlog
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|solisten_proto_check
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|socket
modifier|*
name|sonewconn
parameter_list|(
name|struct
name|socket
modifier|*
name|head
parameter_list|,
name|int
name|connstatus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sooptcopyin
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
name|minlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sooptcopyout
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX; prepare mbuf for (__FreeBSD__< 3) routines. */
end_comment

begin_function_decl
name|int
name|soopt_getm
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|soopt_mcopyin
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|soopt_mcopyout
parameter_list|(
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sopoll
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
name|active_cred
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
name|sopoll_generic
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
name|active_cred
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
name|soreceive
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
name|soreceive_generic
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
name|soreserve
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|u_long
name|sndcc
parameter_list|,
name|u_long
name|rcvcc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sorflush
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
name|sosend
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
name|sosend_dgram
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
name|sosend_generic
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
name|sosetopt
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockopt
modifier|*
name|sopt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|soshutdown
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|how
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sotoxsocket
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|xsocket
modifier|*
name|xso
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sowakeup
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|sockbuf
modifier|*
name|sb
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SOCKBUF_DEBUG
end_ifdef

begin_function_decl
name|void
name|sblastrecordchk
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SBLASTRECORDCHK
parameter_list|(
name|sb
parameter_list|)
value|sblastrecordchk((sb), __FILE__, __LINE__)
end_define

begin_function_decl
name|void
name|sblastmbufchk
parameter_list|(
name|struct
name|sockbuf
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SBLASTMBUFCHK
parameter_list|(
name|sb
parameter_list|)
value|sblastmbufchk((sb), __FILE__, __LINE__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SBLASTRECORDCHK
parameter_list|(
name|sb
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|SBLASTMBUFCHK
parameter_list|(
name|sb
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOCKBUF_DEBUG */
end_comment

begin_comment
comment|/*  * Accept filter functions (duh).  */
end_comment

begin_function_decl
name|int
name|accept_filt_add
parameter_list|(
name|struct
name|accept_filter
modifier|*
name|filt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|accept_filt_del
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|accept_filter
modifier|*
name|accept_filt_get
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ACCEPT_FILTER_MOD
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_inet_accf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|accept_filt_generic_mod_event
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|event
parameter_list|,
name|void
modifier|*
name|data
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

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SOCKETVAR_H_ */
end_comment

end_unit

