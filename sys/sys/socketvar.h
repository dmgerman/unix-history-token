begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)socketvar.h	8.3 (Berkeley) 2/19/95  * $Id: socketvar.h,v 1.22 1997/09/14 02:25:41 peter Exp $  */
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
comment|/*  * Variables for connection queuing.  * Socket where accepts occur is so_head in all subsidiary sockets.  * If so_head is 0, socket is not related to an accept.  * For head socket so_q0 queues partially completed connections,  * while so_q is a queue of connections ready to be accepted.  * If a connection is aborted and it has so_head set, then  * it has to be pulled out of either so_q0 or so_q.  * We allow connections to queue up based on current queue lengths  * and limit on number of queued connections for this socket.  */
name|struct
name|socket
modifier|*
name|so_head
decl_stmt|;
comment|/* back pointer to accept socket */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|socket
argument_list|)
name|so_incomp
expr_stmt|;
comment|/* queue of partial unaccepted connections */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|socket
argument_list|)
name|so_comp
expr_stmt|;
comment|/* queue of complete unaccepted connections */
name|TAILQ_ENTRY
argument_list|(
argument|socket
argument_list|)
name|so_list
expr_stmt|;
comment|/* list of unaccepted connections */
name|short
name|so_qlen
decl_stmt|;
comment|/* number of unaccepted connections */
name|short
name|so_incqlen
decl_stmt|;
comment|/* number of unaccepted incomplete 					   connections */
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
name|SS_CANTSENDMORE
value|0x0010
end_define

begin_comment
comment|/* can't send more data to peer */
end_comment

begin_define
define|#
directive|define
name|SS_CANTRCVMORE
value|0x0020
end_define

begin_comment
comment|/* can't receive more data from peer */
end_comment

begin_define
define|#
directive|define
name|SS_RCVATMARK
value|0x0040
end_define

begin_comment
comment|/* at mark on input */
end_comment

begin_comment
comment|/*efine	SS_PRIV			0x0080	   privileged for broadcast, raw... */
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
name|SS_INCOMP
value|0x0800
end_define

begin_comment
comment|/* unaccepted, incomplete connection */
end_comment

begin_define
define|#
directive|define
name|SS_COMP
value|0x1000
end_define

begin_comment
comment|/* unaccepted, complete connection */
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
value|((so)->so_rcv.sb_cc>= (so)->so_rcv.sb_lowat || \ 	((so)->so_state& SS_CANTRCVMORE) || \ 	(so)->so_comp.tqh_first || (so)->so_error)
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
value|((sbspace(&(so)->so_snd)>= (so)->so_snd.sb_lowat&& \ 	(((so)->so_state&SS_ISCONNECTED) || \ 	  ((so)->so_proto->pr_flags&PR_CONNREQUIRED)==0)) || \      ((so)->so_state& SS_CANTSENDMORE) || \      (so)->so_error)
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

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

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
name|M_SOCKET
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
name|u_long
name|sb_max
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|filedesc
struct_decl|;
end_struct_decl

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
name|stat
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * File operations on sockets.  */
end_comment

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
name|cmd
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
name|soo_poll
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
name|fp
operator|,
name|int
name|events
operator|,
expr|struct
name|ucred
operator|*
name|cred
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
name|soo_stat
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|stat
operator|*
name|ub
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * From uipc_socket and friends  */
end_comment

begin_decl_stmt
name|struct
name|sockaddr
modifier|*
name|dup_sockaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
name|sa
operator|,
name|int
name|canwait
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getsock
name|__P
argument_list|(
operator|(
expr|struct
name|filedesc
operator|*
name|fdp
operator|,
name|int
name|fdes
operator|,
expr|struct
name|file
operator|*
operator|*
name|fpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sockargs
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
name|mp
operator|,
name|caddr_t
name|buf
operator|,
name|int
name|buflen
operator|,
name|int
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getsockaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockaddr
operator|*
operator|*
name|namp
operator|,
name|caddr_t
name|uaddr
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbappend
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sbappendaddr
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|,
expr|struct
name|sockaddr
operator|*
name|asa
operator|,
expr|struct
name|mbuf
operator|*
name|m0
operator|,
expr|struct
name|mbuf
operator|*
name|control
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sbappendcontrol
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|,
expr|struct
name|mbuf
operator|*
name|m0
operator|,
expr|struct
name|mbuf
operator|*
name|control
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbappendrecord
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|,
expr|struct
name|mbuf
operator|*
name|m0
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbcheck
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbcompress
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|,
expr|struct
name|mbuf
operator|*
name|m
operator|,
expr|struct
name|mbuf
operator|*
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mbuf
modifier|*
name|sbcreatecontrol
name|__P
argument_list|(
operator|(
name|caddr_t
name|p
operator|,
name|int
name|size
operator|,
name|int
name|type
operator|,
name|int
name|level
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbdrop
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbdroprecord
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbflush
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbinsertoob
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|,
expr|struct
name|mbuf
operator|*
name|m0
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sbrelease
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sbreserve
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|,
name|u_long
name|cc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sbwait
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sb_lock
name|__P
argument_list|(
operator|(
expr|struct
name|sockbuf
operator|*
name|sb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|soabort
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|soaccept
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|nam
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sobind
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
name|nam
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
name|void
name|socantrcvmore
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|socantsendmore
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|soclose
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|soconnect
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
name|nam
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
name|soconnect2
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so1
operator|,
expr|struct
name|socket
operator|*
name|so2
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|socreate
name|__P
argument_list|(
operator|(
name|int
name|dom
operator|,
expr|struct
name|socket
operator|*
operator|*
name|aso
operator|,
name|int
name|type
operator|,
name|int
name|proto
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
name|sodisconnect
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sofree
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sogetopt
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|level
operator|,
name|int
name|optname
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mp
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
name|void
name|sohasoutofband
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|soisconnected
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|soisconnecting
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|soisdisconnected
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|soisdisconnecting
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|solisten
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|backlog
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
name|struct
name|socket
modifier|*
name|sodropablereq
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|head
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|socket
modifier|*
name|sonewconn
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

begin_decl_stmt
name|int
name|sopoll
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|events
operator|,
expr|struct
name|ucred
operator|*
name|cred
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
name|soreceive
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
operator|*
name|paddr
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mp0
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|controlp
operator|,
name|int
operator|*
name|flagsp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|soreserve
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|u_long
name|sndcc
operator|,
name|u_long
name|rcvcc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sorflush
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sosend
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockaddr
operator|*
name|addr
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|mbuf
operator|*
name|top
operator|,
expr|struct
name|mbuf
operator|*
name|control
operator|,
name|int
name|flags
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
name|sosetopt
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|level
operator|,
name|int
name|optname
operator|,
expr|struct
name|mbuf
operator|*
name|m0
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
name|soshutdown
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|int
name|how
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sowakeup
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
expr|struct
name|sockbuf
operator|*
name|sb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SOCKETVAR_H_ */
end_comment

end_unit

