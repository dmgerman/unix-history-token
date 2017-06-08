begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)socketvar.h	8.3 (Berkeley) 2/19/95  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/osd.h>
end_include

begin_include
include|#
directive|include
file|<sys/_sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockstate.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/caprights.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockopt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|vnet
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Kernel structure per socket.  * Contains send and receive buffer queues,  * handle on protocol and pointer to protocol  * private data and error information.  */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|so_gen_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|so_upcall_t
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
end_typedef

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_comment
comment|/*-  * Locking key to struct socket:  * (a) constant after allocation, no locking required.  * (b) locked by SOCK_LOCK(so).  * (cr) locked by SOCKBUF_LOCK(&so->so_rcv).  * (cs) locked by SOCKBUF_LOCK(&so->so_rcv).  * (e) locked by SOLISTEN_LOCK() of corresponding listening socket.  * (f) not locked since integer reads/writes are atomic.  * (g) used only as a sleep/wakeup address, no value.  * (h) locked by global mutex so_global_mtx.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|accept_queue
argument_list|,
name|socket
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|socket
block|{
name|struct
name|mtx
name|so_lock
decl_stmt|;
specifier|volatile
name|u_int
name|so_count
decl_stmt|;
comment|/* (b / refcount) */
name|struct
name|selinfo
name|so_rdsel
decl_stmt|;
comment|/* (b/cr) for so_rcv/so_comp */
name|struct
name|selinfo
name|so_wrsel
decl_stmt|;
comment|/* (b/cs) for so_snd */
name|short
name|so_type
decl_stmt|;
comment|/* (a) generic type, see socket.h */
name|short
name|so_options
decl_stmt|;
comment|/* (b) from socket call, see socket.h */
name|short
name|so_linger
decl_stmt|;
comment|/* time to linger close(2) */
name|short
name|so_state
decl_stmt|;
comment|/* (b) internal state flags SS_* */
name|void
modifier|*
name|so_pcb
decl_stmt|;
comment|/* protocol control block */
name|struct
name|vnet
modifier|*
name|so_vnet
decl_stmt|;
comment|/* (a) network stack instance */
name|struct
name|protosw
modifier|*
name|so_proto
decl_stmt|;
comment|/* (a) protocol handle */
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
name|struct
name|osd
name|osd
decl_stmt|;
comment|/* Object Specific extensions */
comment|/* 	 * so_fibnum, so_user_cookie and friends can be used to attach 	 * some user-specified metadata to a socket, which then can be 	 * used by the kernel for various actions. 	 * so_user_cookie is used by ipfw/dummynet. 	 */
name|int
name|so_fibnum
decl_stmt|;
comment|/* routing domain for this socket */
name|uint32_t
name|so_user_cookie
decl_stmt|;
name|int
name|so_ts_clock
decl_stmt|;
comment|/* type of the clock used for timestamps */
name|uint32_t
name|so_max_pacing_rate
decl_stmt|;
comment|/* (f) TX rate limit in bytes/s */
union|union
block|{
comment|/* Regular (data flow) socket. */
struct|struct
block|{
comment|/* (cr, cs) Receive and send buffers. */
name|struct
name|sockbuf
name|so_rcv
decl_stmt|,
name|so_snd
decl_stmt|;
comment|/* (e) Our place on accept queue. */
name|TAILQ_ENTRY
argument_list|(
argument|socket
argument_list|)
name|so_list
expr_stmt|;
name|struct
name|socket
modifier|*
name|so_listen
decl_stmt|;
comment|/* (b) */
enum|enum
block|{
name|SQ_NONE
init|=
literal|0
block|,
name|SQ_INCOMP
init|=
literal|0x0800
block|,
comment|/* on sol_incomp */
name|SQ_COMP
init|=
literal|0x1000
block|,
comment|/* on sol_comp */
block|}
name|so_qstate
enum|;
comment|/* (b) */
comment|/* (b) cached MAC label for peer */
name|struct
name|label
modifier|*
name|so_peerlabel
decl_stmt|;
name|u_long
name|so_oobmark
decl_stmt|;
comment|/* chars to oob mark */
block|}
struct|;
comment|/* 		 * Listening socket, where accepts occur, is so_listen in all 		 * subsidiary sockets.  If so_listen is NULL, socket is not 		 * related to an accept.  For a listening socket itself 		 * sol_incomp queues partially completed connections, while 		 * sol_comp is a queue of connections ready to be accepted. 		 * If a connection is aborted and it has so_listen set, then 		 * it has to be pulled out of either sol_incomp or sol_comp. 		 * We allow connections to queue up based on current queue 		 * lengths and limit on number of queued connections for this 		 * socket. 		 */
struct|struct
block|{
comment|/* (e) queue of partial unaccepted connections */
name|struct
name|accept_queue
name|sol_incomp
decl_stmt|;
comment|/* (e) queue of complete unaccepted connections */
name|struct
name|accept_queue
name|sol_comp
decl_stmt|;
name|u_int
name|sol_qlen
decl_stmt|;
comment|/* (e) sol_comp length */
name|u_int
name|sol_incqlen
decl_stmt|;
comment|/* (e) sol_incomp length */
name|u_int
name|sol_qlimit
decl_stmt|;
comment|/* (e) queue limit */
comment|/* accept_filter(9) optional data */
name|struct
name|accept_filter
modifier|*
name|sol_accept_filter
decl_stmt|;
name|void
modifier|*
name|sol_accept_filter_arg
decl_stmt|;
comment|/* saved filter args */
name|char
modifier|*
name|sol_accept_filter_str
decl_stmt|;
comment|/* saved user args */
comment|/* Optional upcall, for kernel socket. */
name|so_upcall_t
modifier|*
name|sol_upcall
decl_stmt|;
comment|/* (e) */
name|void
modifier|*
name|sol_upcallarg
decl_stmt|;
comment|/* (e) */
comment|/* Socket buffer parameters, to be copied to 			 * dataflow sockets, accepted from this one. */
name|int
name|sol_sbrcv_lowat
decl_stmt|;
name|int
name|sol_sbsnd_lowat
decl_stmt|;
name|u_int
name|sol_sbrcv_hiwat
decl_stmt|;
name|u_int
name|sol_sbsnd_hiwat
decl_stmt|;
name|short
name|sol_sbrcv_flags
decl_stmt|;
name|short
name|sol_sbsnd_flags
decl_stmt|;
name|sbintime_t
name|sol_sbrcv_timeo
decl_stmt|;
name|sbintime_t
name|sol_sbsnd_timeo
decl_stmt|;
block|}
struct|;
block|}
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SOCK_MTX
parameter_list|(
name|so
parameter_list|)
value|&(so)->so_lock
end_define

begin_define
define|#
directive|define
name|SOCK_LOCK
parameter_list|(
name|so
parameter_list|)
value|mtx_lock(&(so)->so_lock)
end_define

begin_define
define|#
directive|define
name|SOCK_OWNED
parameter_list|(
name|so
parameter_list|)
value|mtx_owned(&(so)->so_lock)
end_define

begin_define
define|#
directive|define
name|SOCK_UNLOCK
parameter_list|(
name|so
parameter_list|)
value|mtx_unlock(&(so)->so_lock)
end_define

begin_define
define|#
directive|define
name|SOCK_LOCK_ASSERT
parameter_list|(
name|so
parameter_list|)
value|mtx_assert(&(so)->so_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|SOCK_UNLOCK_ASSERT
parameter_list|(
name|so
parameter_list|)
value|mtx_assert(&(so)->so_lock, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|SOLISTENING
parameter_list|(
name|sol
parameter_list|)
value|(((sol)->so_options& SO_ACCEPTCONN) != 0)
end_define

begin_define
define|#
directive|define
name|SOLISTEN_LOCK
parameter_list|(
name|sol
parameter_list|)
value|do {					\ 	mtx_lock(&(sol)->so_lock);					\ 	KASSERT(SOLISTENING(sol),					\ 	    ("%s: %p not listening", __func__, (sol)));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|SOLISTEN_TRYLOCK
parameter_list|(
name|sol
parameter_list|)
value|mtx_trylock(&(sol)->so_lock)
end_define

begin_define
define|#
directive|define
name|SOLISTEN_UNLOCK
parameter_list|(
name|sol
parameter_list|)
value|do {					\ 	KASSERT(SOLISTENING(sol),					\ 	    ("%s: %p not listening", __func__, (sol)));			\ 	mtx_unlock(&(sol)->so_lock);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|SOLISTEN_LOCK_ASSERT
parameter_list|(
name|sol
parameter_list|)
value|do {				\ 	mtx_assert(&(sol)->so_lock, MA_OWNED);				\ 	KASSERT(SOLISTENING(sol),					\ 	    ("%s: %p not listening", __func__, (sol)));			\ } while (0)
end_define

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
name|u_int
name|so_qlen
decl_stmt|;
name|u_int
name|so_incqlen
decl_stmt|;
name|u_int
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
name|struct
name|xsockbuf
name|so_rcv
decl_stmt|,
name|so_snd
decl_stmt|;
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
comment|/*  * Flags to sblock().  */
end_comment

begin_define
define|#
directive|define
name|SBL_WAIT
value|0x00000001
end_define

begin_comment
comment|/* Wait if not immediately available. */
end_comment

begin_define
define|#
directive|define
name|SBL_NOINTR
value|0x00000002
end_define

begin_comment
comment|/* Force non-interruptible sleep. */
end_comment

begin_define
define|#
directive|define
name|SBL_VALID
value|(SBL_WAIT | SBL_NOINTR)
end_define

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
name|soreadabledata
parameter_list|(
name|so
parameter_list|)
define|\
value|(sbavail(&(so)->so_rcv)>= (so)->so_rcv.sb_lowat ||  (so)->so_error)
end_define

begin_define
define|#
directive|define
name|soreadable
parameter_list|(
name|so
parameter_list|)
define|\
value|(soreadabledata(so) || ((so)->so_rcv.sb_state& SBS_CANTRCVMORE))
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
comment|/*  * soref()/sorele() ref-count the socket structure.  * soref() may be called without owning socket lock, but in that case a  * caller must own something that holds socket, and so_count must be not 0.  * Note that you must still explicitly close the socket, but the last ref  * count will free the structure.  */
end_comment

begin_define
define|#
directive|define
name|soref
parameter_list|(
name|so
parameter_list|)
value|refcount_acquire(&(so)->so_count)
end_define

begin_define
define|#
directive|define
name|sorele
parameter_list|(
name|so
parameter_list|)
value|do {							\ 	SOCK_LOCK_ASSERT(so);						\ 	if (refcount_release(&(so)->so_count))				\ 		sofree(so);						\ 	else								\ 		SOCK_UNLOCK(so);					\ } while (0)
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
name|int
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

begin_comment
comment|/*  * Socket specific helper hook point identifiers  * Do not leave holes in the sequence, hook registration is a loop.  */
end_comment

begin_define
define|#
directive|define
name|HHOOK_SOCKET_OPT
value|0
end_define

begin_define
define|#
directive|define
name|HHOOK_SOCKET_CREATE
value|1
end_define

begin_define
define|#
directive|define
name|HHOOK_SOCKET_RCV
value|2
end_define

begin_define
define|#
directive|define
name|HHOOK_SOCKET_SND
value|3
end_define

begin_define
define|#
directive|define
name|HHOOK_FILT_SOREAD
value|4
end_define

begin_define
define|#
directive|define
name|HHOOK_FILT_SOWRITE
value|5
end_define

begin_define
define|#
directive|define
name|HHOOK_SOCKET_CLOSE
value|6
end_define

begin_define
define|#
directive|define
name|HHOOK_SOCKET_LAST
value|HHOOK_SOCKET_CLOSE
end_define

begin_struct
struct|struct
name|socket_hhook_data
block|{
name|struct
name|socket
modifier|*
name|so
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|void
modifier|*
name|hctx
decl_stmt|;
comment|/* hook point specific data*/
name|int
name|status
decl_stmt|;
block|}
struct|;
end_struct

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
name|so_gen_t
name|so_gencnt
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|filecaps
struct_decl|;
end_struct_decl

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
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_comment
comment|/* 'which' values for socket upcalls. */
end_comment

begin_define
define|#
directive|define
name|SO_RCV
value|1
end_define

begin_define
define|#
directive|define
name|SO_SND
value|2
end_define

begin_comment
comment|/* Return values for socket upcalls. */
end_comment

begin_define
define|#
directive|define
name|SU_OK
value|0
end_define

begin_define
define|#
directive|define
name|SU_ISCONNECTED
value|1
end_define

begin_comment
comment|/*  * From uipc_socket and friends  */
end_comment

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
name|int
name|getsock_cap
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|fd
parameter_list|,
name|cap_rights_t
modifier|*
name|rightsp
parameter_list|,
name|struct
name|file
modifier|*
modifier|*
name|fpp
parameter_list|,
name|u_int
modifier|*
name|fflagp
parameter_list|,
name|struct
name|filecaps
modifier|*
name|havecaps
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
name|void
name|soaio_enqueue
parameter_list|(
name|struct
name|task
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soaio_rcv
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soaio_snd
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|int
name|pending
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
name|int
name|sobindat
parameter_list|(
name|int
name|fd
parameter_list|,
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
name|soconnectat
parameter_list|(
name|int
name|fd
parameter_list|,
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
name|int
name|solisten_dequeue
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
modifier|*
parameter_list|,
name|int
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
name|struct
name|socket
modifier|*
name|sopeeloff
parameter_list|(
name|struct
name|socket
modifier|*
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
name|soreceive_stream
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
name|soreceive_dgram
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
name|soupcall_clear
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|soupcall_set
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|so_upcall_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|solisten_upcall_set
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|so_upcall_t
parameter_list|,
name|void
modifier|*
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

begin_function_decl
name|void
name|sowakeup_aio
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

begin_function_decl
name|void
name|solisten_wakeup
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|selsocket
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
name|timeval
modifier|*
name|tv
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

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

