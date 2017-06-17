begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000,2001 Jonathan Lemon<jlemon@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EVENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EVENT_H_
end_define

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|EVFILT_READ
value|(-1)
end_define

begin_define
define|#
directive|define
name|EVFILT_WRITE
value|(-2)
end_define

begin_define
define|#
directive|define
name|EVFILT_AIO
value|(-3)
end_define

begin_comment
comment|/* attached to aio requests */
end_comment

begin_define
define|#
directive|define
name|EVFILT_VNODE
value|(-4)
end_define

begin_comment
comment|/* attached to vnodes */
end_comment

begin_define
define|#
directive|define
name|EVFILT_PROC
value|(-5)
end_define

begin_comment
comment|/* attached to struct proc */
end_comment

begin_define
define|#
directive|define
name|EVFILT_SIGNAL
value|(-6)
end_define

begin_comment
comment|/* attached to struct proc */
end_comment

begin_define
define|#
directive|define
name|EVFILT_TIMER
value|(-7)
end_define

begin_comment
comment|/* timers */
end_comment

begin_define
define|#
directive|define
name|EVFILT_PROCDESC
value|(-8)
end_define

begin_comment
comment|/* attached to process descriptors */
end_comment

begin_define
define|#
directive|define
name|EVFILT_FS
value|(-9)
end_define

begin_comment
comment|/* filesystem events */
end_comment

begin_define
define|#
directive|define
name|EVFILT_LIO
value|(-10)
end_define

begin_comment
comment|/* attached to lio requests */
end_comment

begin_define
define|#
directive|define
name|EVFILT_USER
value|(-11)
end_define

begin_comment
comment|/* User events */
end_comment

begin_define
define|#
directive|define
name|EVFILT_SENDFILE
value|(-12)
end_define

begin_comment
comment|/* attached to sendfile requests */
end_comment

begin_define
define|#
directive|define
name|EVFILT_EMPTY
value|(-13)
end_define

begin_comment
comment|/* empty send socket buf */
end_comment

begin_define
define|#
directive|define
name|EVFILT_SYSCOUNT
value|13
end_define

begin_define
define|#
directive|define
name|EV_SET
parameter_list|(
name|kevp_
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|do {	\ 	struct kevent *kevp = (kevp_);		\ 	(kevp)->ident = (a);			\ 	(kevp)->filter = (b);			\ 	(kevp)->flags = (c);			\ 	(kevp)->fflags = (d);			\ 	(kevp)->data = (e);			\ 	(kevp)->udata = (f);			\ 	(kevp)->ext[0] = 0;			\ 	(kevp)->ext[1] = 0;			\ 	(kevp)->ext[2] = 0;			\ 	(kevp)->ext[3] = 0;			\ } while(0)
end_define

begin_struct
struct|struct
name|kevent
block|{
name|__uintptr_t
name|ident
decl_stmt|;
comment|/* identifier for this event */
name|short
name|filter
decl_stmt|;
comment|/* filter for event */
name|unsigned
name|short
name|flags
decl_stmt|;
name|unsigned
name|int
name|fflags
decl_stmt|;
name|__int64_t
name|data
decl_stmt|;
name|void
modifier|*
name|udata
decl_stmt|;
comment|/* opaque user data identifier */
name|__uint64_t
name|ext
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* actions */
end_comment

begin_define
define|#
directive|define
name|EV_ADD
value|0x0001
end_define

begin_comment
comment|/* add event to kq (implies enable) */
end_comment

begin_define
define|#
directive|define
name|EV_DELETE
value|0x0002
end_define

begin_comment
comment|/* delete event from kq */
end_comment

begin_define
define|#
directive|define
name|EV_ENABLE
value|0x0004
end_define

begin_comment
comment|/* enable event */
end_comment

begin_define
define|#
directive|define
name|EV_DISABLE
value|0x0008
end_define

begin_comment
comment|/* disable event (not reported) */
end_comment

begin_define
define|#
directive|define
name|EV_FORCEONESHOT
value|0x0100
end_define

begin_comment
comment|/* enable _ONESHOT and force trigger */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|EV_ONESHOT
value|0x0010
end_define

begin_comment
comment|/* only report one occurrence */
end_comment

begin_define
define|#
directive|define
name|EV_CLEAR
value|0x0020
end_define

begin_comment
comment|/* clear event state after reporting */
end_comment

begin_define
define|#
directive|define
name|EV_RECEIPT
value|0x0040
end_define

begin_comment
comment|/* force EV_ERROR on success, data=0 */
end_comment

begin_define
define|#
directive|define
name|EV_DISPATCH
value|0x0080
end_define

begin_comment
comment|/* disable event after reporting */
end_comment

begin_define
define|#
directive|define
name|EV_SYSFLAGS
value|0xF000
end_define

begin_comment
comment|/* reserved by system */
end_comment

begin_define
define|#
directive|define
name|EV_DROP
value|0x1000
end_define

begin_comment
comment|/* note should be dropped */
end_comment

begin_define
define|#
directive|define
name|EV_FLAG1
value|0x2000
end_define

begin_comment
comment|/* filter-specific flag */
end_comment

begin_define
define|#
directive|define
name|EV_FLAG2
value|0x4000
end_define

begin_comment
comment|/* filter-specific flag */
end_comment

begin_comment
comment|/* returned values */
end_comment

begin_define
define|#
directive|define
name|EV_EOF
value|0x8000
end_define

begin_comment
comment|/* EOF detected */
end_comment

begin_define
define|#
directive|define
name|EV_ERROR
value|0x4000
end_define

begin_comment
comment|/* error, data contains errno */
end_comment

begin_comment
comment|/*   * data/hint flags/masks for EVFILT_USER, shared with userspace   *   * On input, the top two bits of fflags specifies how the lower twenty four   * bits should be applied to the stored value of fflags.   *   * On output, the top two bits will always be set to NOTE_FFNOP and the   * remaining twenty four bits will contain the stored fflags value.   */
end_comment

begin_define
define|#
directive|define
name|NOTE_FFNOP
value|0x00000000
end_define

begin_comment
comment|/* ignore input fflags */
end_comment

begin_define
define|#
directive|define
name|NOTE_FFAND
value|0x40000000
end_define

begin_comment
comment|/* AND fflags */
end_comment

begin_define
define|#
directive|define
name|NOTE_FFOR
value|0x80000000
end_define

begin_comment
comment|/* OR fflags */
end_comment

begin_define
define|#
directive|define
name|NOTE_FFCOPY
value|0xc0000000
end_define

begin_comment
comment|/* copy fflags */
end_comment

begin_define
define|#
directive|define
name|NOTE_FFCTRLMASK
value|0xc0000000
end_define

begin_comment
comment|/* masks for operations */
end_comment

begin_define
define|#
directive|define
name|NOTE_FFLAGSMASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|NOTE_TRIGGER
value|0x01000000
end_define

begin_comment
comment|/* Cause the event to be 						   triggered for output. */
end_comment

begin_comment
comment|/*  * data/hint flags for EVFILT_{READ|WRITE}, shared with userspace  */
end_comment

begin_define
define|#
directive|define
name|NOTE_LOWAT
value|0x0001
end_define

begin_comment
comment|/* low water mark */
end_comment

begin_define
define|#
directive|define
name|NOTE_FILE_POLL
value|0x0002
end_define

begin_comment
comment|/* behave like poll() */
end_comment

begin_comment
comment|/*  * data/hint flags for EVFILT_VNODE, shared with userspace  */
end_comment

begin_define
define|#
directive|define
name|NOTE_DELETE
value|0x0001
end_define

begin_comment
comment|/* vnode was removed */
end_comment

begin_define
define|#
directive|define
name|NOTE_WRITE
value|0x0002
end_define

begin_comment
comment|/* data contents changed */
end_comment

begin_define
define|#
directive|define
name|NOTE_EXTEND
value|0x0004
end_define

begin_comment
comment|/* size increased */
end_comment

begin_define
define|#
directive|define
name|NOTE_ATTRIB
value|0x0008
end_define

begin_comment
comment|/* attributes changed */
end_comment

begin_define
define|#
directive|define
name|NOTE_LINK
value|0x0010
end_define

begin_comment
comment|/* link count changed */
end_comment

begin_define
define|#
directive|define
name|NOTE_RENAME
value|0x0020
end_define

begin_comment
comment|/* vnode was renamed */
end_comment

begin_define
define|#
directive|define
name|NOTE_REVOKE
value|0x0040
end_define

begin_comment
comment|/* vnode access was revoked */
end_comment

begin_define
define|#
directive|define
name|NOTE_OPEN
value|0x0080
end_define

begin_comment
comment|/* vnode was opened */
end_comment

begin_define
define|#
directive|define
name|NOTE_CLOSE
value|0x0100
end_define

begin_comment
comment|/* file closed, fd did not 						   allowed write */
end_comment

begin_define
define|#
directive|define
name|NOTE_CLOSE_WRITE
value|0x0200
end_define

begin_comment
comment|/* file closed, fd did allowed 						   write */
end_comment

begin_define
define|#
directive|define
name|NOTE_READ
value|0x0400
end_define

begin_comment
comment|/* file was read */
end_comment

begin_comment
comment|/*  * data/hint flags for EVFILT_PROC and EVFILT_PROCDESC, shared with userspace  */
end_comment

begin_define
define|#
directive|define
name|NOTE_EXIT
value|0x80000000
end_define

begin_comment
comment|/* process exited */
end_comment

begin_define
define|#
directive|define
name|NOTE_FORK
value|0x40000000
end_define

begin_comment
comment|/* process forked */
end_comment

begin_define
define|#
directive|define
name|NOTE_EXEC
value|0x20000000
end_define

begin_comment
comment|/* process exec'd */
end_comment

begin_define
define|#
directive|define
name|NOTE_PCTRLMASK
value|0xf0000000
end_define

begin_comment
comment|/* mask for hint bits */
end_comment

begin_define
define|#
directive|define
name|NOTE_PDATAMASK
value|0x000fffff
end_define

begin_comment
comment|/* mask for pid */
end_comment

begin_comment
comment|/* additional flags for EVFILT_PROC */
end_comment

begin_define
define|#
directive|define
name|NOTE_TRACK
value|0x00000001
end_define

begin_comment
comment|/* follow across forks */
end_comment

begin_define
define|#
directive|define
name|NOTE_TRACKERR
value|0x00000002
end_define

begin_comment
comment|/* could not track child */
end_comment

begin_define
define|#
directive|define
name|NOTE_CHILD
value|0x00000004
end_define

begin_comment
comment|/* am a child process */
end_comment

begin_comment
comment|/* additional flags for EVFILT_TIMER */
end_comment

begin_define
define|#
directive|define
name|NOTE_SECONDS
value|0x00000001
end_define

begin_comment
comment|/* data is seconds */
end_comment

begin_define
define|#
directive|define
name|NOTE_MSECONDS
value|0x00000002
end_define

begin_comment
comment|/* data is milliseconds */
end_comment

begin_define
define|#
directive|define
name|NOTE_USECONDS
value|0x00000004
end_define

begin_comment
comment|/* data is microseconds */
end_comment

begin_define
define|#
directive|define
name|NOTE_NSECONDS
value|0x00000008
end_define

begin_comment
comment|/* data is nanoseconds */
end_comment

begin_define
define|#
directive|define
name|NOTE_ABSTIME
value|0x00000010
end_define

begin_comment
comment|/* timeout is absolute */
end_comment

begin_struct_decl
struct_decl|struct
name|knote
struct_decl|;
end_struct_decl

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|klist
argument_list|,
name|knote
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct_decl
struct_decl|struct
name|kqueue
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|kqlist
argument_list|,
name|kqueue
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|knlist
block|{
name|struct
name|klist
name|kl_list
decl_stmt|;
name|void
function_decl|(
modifier|*
name|kl_lock
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* lock function */
name|void
function_decl|(
modifier|*
name|kl_unlock
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|kl_assert_locked
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|kl_assert_unlocked
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|kl_lockarg
decl_stmt|;
comment|/* argument passed to lock functions */
name|int
name|kl_autodestroy
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Flags for knote call  */
end_comment

begin_define
define|#
directive|define
name|KNF_LISTLOCKED
value|0x0001
end_define

begin_comment
comment|/* knlist is locked */
end_comment

begin_define
define|#
directive|define
name|KNF_NOKQLOCK
value|0x0002
end_define

begin_comment
comment|/* do not keep KQ_LOCK */
end_comment

begin_define
define|#
directive|define
name|KNOTE
parameter_list|(
name|list
parameter_list|,
name|hint
parameter_list|,
name|flags
parameter_list|)
value|knote(list, hint, flags)
end_define

begin_define
define|#
directive|define
name|KNOTE_LOCKED
parameter_list|(
name|list
parameter_list|,
name|hint
parameter_list|)
value|knote(list, hint, KNF_LISTLOCKED)
end_define

begin_define
define|#
directive|define
name|KNOTE_UNLOCKED
parameter_list|(
name|list
parameter_list|,
name|hint
parameter_list|)
value|knote(list, hint, 0)
end_define

begin_define
define|#
directive|define
name|KNLIST_EMPTY
parameter_list|(
name|list
parameter_list|)
value|SLIST_EMPTY(&(list)->kl_list)
end_define

begin_comment
comment|/*  * Flag indicating hint is a signal.  Used by EVFILT_SIGNAL, and also  * shared by EVFILT_PROC  (all knotes attached to p->p_klist)  */
end_comment

begin_define
define|#
directive|define
name|NOTE_SIGNAL
value|0x08000000
end_define

begin_comment
comment|/*  * Hint values for the optional f_touch event filter.  If f_touch is not set   * to NULL and f_isfd is zero the f_touch filter will be called with the type  * argument set to EVENT_REGISTER during a kevent() system call.  It is also  * called under the same conditions with the type argument set to EVENT_PROCESS  * when the event has been triggered.  */
end_comment

begin_define
define|#
directive|define
name|EVENT_REGISTER
value|1
end_define

begin_define
define|#
directive|define
name|EVENT_PROCESS
value|2
end_define

begin_struct
struct|struct
name|filterops
block|{
name|int
name|f_isfd
decl_stmt|;
comment|/* true if ident == filedescriptor */
name|int
function_decl|(
modifier|*
name|f_attach
function_decl|)
parameter_list|(
name|struct
name|knote
modifier|*
name|kn
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|f_detach
function_decl|)
parameter_list|(
name|struct
name|knote
modifier|*
name|kn
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|f_event
function_decl|)
parameter_list|(
name|struct
name|knote
modifier|*
name|kn
parameter_list|,
name|long
name|hint
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|f_touch
function_decl|)
parameter_list|(
name|struct
name|knote
modifier|*
name|kn
parameter_list|,
name|struct
name|kevent
modifier|*
name|kev
parameter_list|,
name|u_long
name|type
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * An in-flux knote cannot be dropped from its kq while the kq is  * unlocked.  If the KN_SCAN flag is not set, a thread can only set  * kn_influx when it is exclusive owner of the knote state, and can  * modify kn_status as if it had the KQ lock.  KN_SCAN must not be set  * on a knote which is already in flux.  *  * kn_sfflags, kn_sdata, and kn_kevent are protected by the knlist lock.  */
end_comment

begin_struct
struct|struct
name|knote
block|{
name|SLIST_ENTRY
argument_list|(
argument|knote
argument_list|)
name|kn_link
expr_stmt|;
comment|/* for kq */
name|SLIST_ENTRY
argument_list|(
argument|knote
argument_list|)
name|kn_selnext
expr_stmt|;
comment|/* for struct selinfo */
name|struct
name|knlist
modifier|*
name|kn_knlist
decl_stmt|;
comment|/* f_attach populated */
name|TAILQ_ENTRY
argument_list|(
argument|knote
argument_list|)
name|kn_tqe
expr_stmt|;
name|struct
name|kqueue
modifier|*
name|kn_kq
decl_stmt|;
comment|/* which queue we are on */
name|struct
name|kevent
name|kn_kevent
decl_stmt|;
name|void
modifier|*
name|kn_hook
decl_stmt|;
name|int
name|kn_hookid
decl_stmt|;
name|int
name|kn_status
decl_stmt|;
comment|/* protected by kq lock */
define|#
directive|define
name|KN_ACTIVE
value|0x01
comment|/* event has been triggered */
define|#
directive|define
name|KN_QUEUED
value|0x02
comment|/* event is on queue */
define|#
directive|define
name|KN_DISABLED
value|0x04
comment|/* event is disabled */
define|#
directive|define
name|KN_DETACHED
value|0x08
comment|/* knote is detached */
define|#
directive|define
name|KN_MARKER
value|0x20
comment|/* ignore this knote */
define|#
directive|define
name|KN_KQUEUE
value|0x40
comment|/* this knote belongs to a kq */
define|#
directive|define
name|KN_HASKQLOCK
value|0x80
comment|/* for _inevent */
define|#
directive|define
name|KN_SCAN
value|0x100
comment|/* flux set in kqueue_scan() */
name|int
name|kn_influx
decl_stmt|;
name|int
name|kn_sfflags
decl_stmt|;
comment|/* saved filter flags */
name|int64_t
name|kn_sdata
decl_stmt|;
comment|/* saved data field */
union|union
block|{
name|struct
name|file
modifier|*
name|p_fp
decl_stmt|;
comment|/* file data pointer */
name|struct
name|proc
modifier|*
name|p_proc
decl_stmt|;
comment|/* proc pointer */
name|struct
name|kaiocb
modifier|*
name|p_aio
decl_stmt|;
comment|/* AIO job pointer */
name|struct
name|aioliojob
modifier|*
name|p_lio
decl_stmt|;
comment|/* LIO job pointer */
name|void
modifier|*
name|p_v
decl_stmt|;
comment|/* generic other pointer */
block|}
name|kn_ptr
union|;
name|struct
name|filterops
modifier|*
name|kn_fop
decl_stmt|;
define|#
directive|define
name|kn_id
value|kn_kevent.ident
define|#
directive|define
name|kn_filter
value|kn_kevent.filter
define|#
directive|define
name|kn_flags
value|kn_kevent.flags
define|#
directive|define
name|kn_fflags
value|kn_kevent.fflags
define|#
directive|define
name|kn_data
value|kn_kevent.data
define|#
directive|define
name|kn_fp
value|kn_ptr.p_fp
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kevent_copyops
block|{
name|void
modifier|*
name|arg
decl_stmt|;
name|int
function_decl|(
modifier|*
name|k_copyout
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|struct
name|kevent
modifier|*
name|kevp
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|k_copyin
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|struct
name|kevent
modifier|*
name|kevp
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
name|size_t
name|kevent_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|knlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mtx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rwlock
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|knote
parameter_list|(
name|struct
name|knlist
modifier|*
name|list
parameter_list|,
name|long
name|hint
parameter_list|,
name|int
name|lockflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|knote_fork
parameter_list|(
name|struct
name|knlist
modifier|*
name|list
parameter_list|,
name|int
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|knlist
modifier|*
name|knlist_alloc
parameter_list|(
name|struct
name|mtx
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|knlist_detach
parameter_list|(
name|struct
name|knlist
modifier|*
name|knl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|knlist_add
parameter_list|(
name|struct
name|knlist
modifier|*
name|knl
parameter_list|,
name|struct
name|knote
modifier|*
name|kn
parameter_list|,
name|int
name|islocked
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|knlist_remove
parameter_list|(
name|struct
name|knlist
modifier|*
name|knl
parameter_list|,
name|struct
name|knote
modifier|*
name|kn
parameter_list|,
name|int
name|islocked
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|knlist_empty
parameter_list|(
name|struct
name|knlist
modifier|*
name|knl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|knlist_init
parameter_list|(
name|struct
name|knlist
modifier|*
name|knl
parameter_list|,
name|void
modifier|*
name|lock
parameter_list|,
name|void
function_decl|(
modifier|*
name|kl_lock
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|kl_unlock
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|kl_assert_locked
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
name|kl_assert_unlocked
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|knlist_init_mtx
parameter_list|(
name|struct
name|knlist
modifier|*
name|knl
parameter_list|,
name|struct
name|mtx
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|knlist_init_rw_reader
parameter_list|(
name|struct
name|knlist
modifier|*
name|knl
parameter_list|,
name|struct
name|rwlock
modifier|*
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|knlist_destroy
parameter_list|(
name|struct
name|knlist
modifier|*
name|knl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|knlist_cleardel
parameter_list|(
name|struct
name|knlist
modifier|*
name|knl
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|islocked
parameter_list|,
name|int
name|killkn
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|knlist_clear
parameter_list|(
name|knl
parameter_list|,
name|islocked
parameter_list|)
define|\
value|knlist_cleardel((knl), NULL, (islocked), 0)
end_define

begin_define
define|#
directive|define
name|knlist_delete
parameter_list|(
name|knl
parameter_list|,
name|td
parameter_list|,
name|islocked
parameter_list|)
define|\
value|knlist_cleardel((knl), (td), (islocked), 1)
end_define

begin_function_decl
name|void
name|knote_fdclose
parameter_list|(
name|struct
name|thread
modifier|*
name|p
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kqfd_register
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|kevent
modifier|*
name|kev
parameter_list|,
name|struct
name|thread
modifier|*
name|p
parameter_list|,
name|int
name|waitok
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kqueue_add_filteropts
parameter_list|(
name|int
name|filt
parameter_list|,
name|struct
name|filterops
modifier|*
name|filtops
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kqueue_del_filteropts
parameter_list|(
name|int
name|filt
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|int
name|kqueue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kevent
parameter_list|(
name|int
name|kq
parameter_list|,
specifier|const
name|struct
name|kevent
modifier|*
name|changelist
parameter_list|,
name|int
name|nchanges
parameter_list|,
name|struct
name|kevent
modifier|*
name|eventlist
parameter_list|,
name|int
name|nevents
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_EVENT_H_ */
end_comment

end_unit

