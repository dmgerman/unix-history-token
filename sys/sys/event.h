begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000,2001 Jonathan Lemon<jlemon@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
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
name|EVFILT_SYSCOUNT
value|6
end_define

begin_define
define|#
directive|define
name|EV_SET
parameter_list|(
name|kevp
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
value|do {	\ 	(kevp)->ident = (a);			\ 	(kevp)->filter = (b);			\ 	(kevp)->flags = (c);			\ 	(kevp)->fflags = (d);			\ 	(kevp)->data = (e);			\ 	(kevp)->udata = (f);			\ } while(0)
end_define

begin_struct
struct|struct
name|kevent
block|{
name|uintptr_t
name|ident
decl_stmt|;
comment|/* identifier for this event */
name|short
name|filter
decl_stmt|;
comment|/* filter for event */
name|u_short
name|flags
decl_stmt|;
name|u_int
name|fflags
decl_stmt|;
name|intptr_t
name|data
decl_stmt|;
name|void
modifier|*
name|udata
decl_stmt|;
comment|/* opaque user data identifier */
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
name|EV_SYSFLAGS
value|0xF000
end_define

begin_comment
comment|/* reserved by system */
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

begin_comment
comment|/*  * data/hint flags for EVFILT_PROC, shared with userspace  */
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
comment|/*  * This is currently visible to userland to work around broken  * programs which pull in<sys/proc.h> or<sys/select.h>.  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|KNOTE
parameter_list|(
name|list
parameter_list|,
name|hint
parameter_list|)
value|if ((list) != NULL) knote(list, hint)
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

begin_struct
struct|struct
name|filterops
block|{
name|int
name|f_isfd
decl_stmt|;
comment|/* true if ident == filedescriptor */
name|int
argument_list|(
argument|*f_attach
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|knote
operator|*
name|kn
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*f_detach
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|knote
operator|*
name|kn
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*f_event
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|knote
operator|*
name|kn
operator|,
name|long
name|hint
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

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
comment|/* for fd */
name|SLIST_ENTRY
argument_list|(
argument|knote
argument_list|)
name|kn_selnext
expr_stmt|;
comment|/* for struct selinfo */
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
name|int
name|kn_status
decl_stmt|;
name|int
name|kn_sfflags
decl_stmt|;
comment|/* saved filter flags */
name|intptr_t
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
block|}
name|kn_ptr
union|;
name|struct
name|filterops
modifier|*
name|kn_fop
decl_stmt|;
name|caddr_t
name|kn_hook
decl_stmt|;
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

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|knote
parameter_list|(
name|struct
name|klist
modifier|*
name|list
parameter_list|,
name|long
name|hint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|knote_remove
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|klist
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|knote_fdclose
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kqueue_register
parameter_list|(
name|struct
name|kqueue
modifier|*
name|kq
parameter_list|,
name|struct
name|kevent
modifier|*
name|kev
parameter_list|,
name|struct
name|proc
modifier|*
name|p
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

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|kqueue
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kevent
name|__P
argument_list|(
operator|(
name|int
name|kq
operator|,
specifier|const
expr|struct
name|kevent
operator|*
name|changelist
operator|,
name|int
name|nchanges
operator|,
expr|struct
name|kevent
operator|*
name|eventlist
operator|,
name|int
name|nevents
operator|,
specifier|const
expr|struct
name|timespec
operator|*
name|timeout
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

