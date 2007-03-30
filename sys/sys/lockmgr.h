begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code contains ideas from software contributed to Berkeley by  * Avadis Tevanian, Jr., Michael Wayne Young, and the Mach Operating  * System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)lock.h	8.12 (Berkeley) 5/19/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LOCKMGR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LOCKMGR_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_LOCKS
end_ifdef

begin_include
include|#
directive|include
file|<sys/stack.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_struct_decl
struct_decl|struct
name|mtx
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The general lock structure.  Provides for multiple shared locks,  * upgrading from shared to exclusive, and sleeping until the lock  * can be gained.  */
end_comment

begin_struct
struct|struct
name|lock
block|{
name|struct
name|lock_object
name|lk_object
decl_stmt|;
comment|/* common lock properties */
name|struct
name|mtx
modifier|*
name|lk_interlock
decl_stmt|;
comment|/* lock on remaining fields */
name|u_int
name|lk_flags
decl_stmt|;
comment|/* see below */
name|int
name|lk_sharecount
decl_stmt|;
comment|/* # of accepted shared locks */
name|int
name|lk_waitcount
decl_stmt|;
comment|/* # of processes sleeping for lock */
name|short
name|lk_exclusivecount
decl_stmt|;
comment|/* # of recursive exclusive locks */
name|short
name|lk_prio
decl_stmt|;
comment|/* priority at which to sleep */
name|int
name|lk_timo
decl_stmt|;
comment|/* maximum sleep time (for tsleep) */
name|struct
name|thread
modifier|*
name|lk_lockholder
decl_stmt|;
comment|/* thread of exclusive lock holder */
name|struct
name|lock
modifier|*
name|lk_newlock
decl_stmt|;
comment|/* lock taking over this lock */
ifdef|#
directive|ifdef
name|DEBUG_LOCKS
name|struct
name|stack
name|lk_stack
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|lk_wmesg
value|lk_object.lo_name
end_define

begin_comment
comment|/*  * Lock request types:  *   LK_SHARED - get one of many possible shared locks. If a process  *	holding an exclusive lock requests a shared lock, the exclusive  *	lock(s) will be downgraded to shared locks.  *   LK_EXCLUSIVE - stop further shared locks, when they are cleared,  *	grant a pending upgrade if it exists, then grant an exclusive  *	lock. Only one exclusive lock may exist at a time, except that  *	a process holding an exclusive lock may get additional exclusive  *	locks if it explicitly sets the LK_CANRECURSE flag in the lock  *	request, or if the LK_CANRECUSE flag was set when the lock was  *	initialized.  *   LK_UPGRADE - the process must hold a shared lock that it wants to  *	have upgraded to an exclusive lock. Other processes may get  *	exclusive access to the resource between the time that the upgrade  *	is requested and the time that it is granted.  *   LK_EXCLUPGRADE - the process must hold a shared lock that it wants to  *	have upgraded to an exclusive lock. If the request succeeds, no  *	other processes will have gotten exclusive access to the resource  *	between the time that the upgrade is requested and the time that  *	it is granted. However, if another process has already requested  *	an upgrade, the request will fail (see error returns below).  *   LK_DOWNGRADE - the process must hold an exclusive lock that it wants  *	to have downgraded to a shared lock. If the process holds multiple  *	(recursive) exclusive locks, they will all be downgraded to shared  *	locks.  *   LK_RELEASE - release one instance of a lock.  *   LK_DRAIN - wait for all activity on the lock to end, then mark it  *	decommissioned. This feature is used before freeing a lock that  *	is part of a piece of memory that is about to be freed.  *   LK_EXCLOTHER - return for lockstatus().  Used when another process  *	holds the lock exclusively.  *  * These are flags that are passed to the lockmgr routine.  */
end_comment

begin_define
define|#
directive|define
name|LK_TYPE_MASK
value|0x0000000f
end_define

begin_comment
comment|/* type of lock sought */
end_comment

begin_define
define|#
directive|define
name|LK_SHARED
value|0x00000001
end_define

begin_comment
comment|/* shared lock */
end_comment

begin_define
define|#
directive|define
name|LK_EXCLUSIVE
value|0x00000002
end_define

begin_comment
comment|/* exclusive lock */
end_comment

begin_define
define|#
directive|define
name|LK_UPGRADE
value|0x00000003
end_define

begin_comment
comment|/* shared-to-exclusive upgrade */
end_comment

begin_define
define|#
directive|define
name|LK_EXCLUPGRADE
value|0x00000004
end_define

begin_comment
comment|/* first shared-to-exclusive upgrade */
end_comment

begin_define
define|#
directive|define
name|LK_DOWNGRADE
value|0x00000005
end_define

begin_comment
comment|/* exclusive-to-shared downgrade */
end_comment

begin_define
define|#
directive|define
name|LK_RELEASE
value|0x00000006
end_define

begin_comment
comment|/* release any type of lock */
end_comment

begin_define
define|#
directive|define
name|LK_DRAIN
value|0x00000007
end_define

begin_comment
comment|/* wait for all lock activity to end */
end_comment

begin_define
define|#
directive|define
name|LK_EXCLOTHER
value|0x00000008
end_define

begin_comment
comment|/* other process holds lock */
end_comment

begin_comment
comment|/*  * External lock flags.  *  * These may be set in lock_init to set their mode permanently,  * or passed in as arguments to the lock manager.  */
end_comment

begin_define
define|#
directive|define
name|LK_EXTFLG_MASK
value|0x00000ff0
end_define

begin_comment
comment|/* mask of external flags */
end_comment

begin_define
define|#
directive|define
name|LK_NOWAIT
value|0x00000010
end_define

begin_comment
comment|/* do not sleep to await lock */
end_comment

begin_define
define|#
directive|define
name|LK_SLEEPFAIL
value|0x00000020
end_define

begin_comment
comment|/* sleep, then return failure */
end_comment

begin_define
define|#
directive|define
name|LK_CANRECURSE
value|0x00000040
end_define

begin_comment
comment|/* allow recursive exclusive lock */
end_comment

begin_define
define|#
directive|define
name|LK_NOSHARE
value|0x00000080
end_define

begin_comment
comment|/* Only allow exclusive locks */
end_comment

begin_define
define|#
directive|define
name|LK_TIMELOCK
value|0x00000100
end_define

begin_comment
comment|/* use lk_timo, else no timeout */
end_comment

begin_comment
comment|/*  * Nonpersistent external flags.  */
end_comment

begin_define
define|#
directive|define
name|LK_RETRY
value|0x00001000
end_define

begin_comment
comment|/* vn_lock: retry until locked */
end_comment

begin_define
define|#
directive|define
name|LK_INTERLOCK
value|0x00002000
end_define

begin_comment
comment|/* 				    * unlock passed mutex after getting 				    * lk_interlock 				    */
end_comment

begin_comment
comment|/*  * Internal lock flags.  *  * These flags are used internally to the lock manager.  */
end_comment

begin_define
define|#
directive|define
name|LK_WANT_UPGRADE
value|0x00010000
end_define

begin_comment
comment|/* waiting for share-to-excl upgrade */
end_comment

begin_define
define|#
directive|define
name|LK_WANT_EXCL
value|0x00020000
end_define

begin_comment
comment|/* exclusive lock sought */
end_comment

begin_define
define|#
directive|define
name|LK_HAVE_EXCL
value|0x00040000
end_define

begin_comment
comment|/* exclusive lock obtained */
end_comment

begin_define
define|#
directive|define
name|LK_WAITDRAIN
value|0x00080000
end_define

begin_comment
comment|/* process waiting for lock to drain */
end_comment

begin_define
define|#
directive|define
name|LK_DRAINING
value|0x00100000
end_define

begin_comment
comment|/* lock is being drained */
end_comment

begin_define
define|#
directive|define
name|LK_INTERNAL
value|0x00200000
end_define

begin_comment
comment|/* The internal lock is already held */
end_comment

begin_comment
comment|/*  * Internal state flags corresponding to lk_sharecount, and lk_waitcount  */
end_comment

begin_define
define|#
directive|define
name|LK_SHARE_NONZERO
value|0x01000000
end_define

begin_define
define|#
directive|define
name|LK_WAIT_NONZERO
value|0x02000000
end_define

begin_comment
comment|/*  * Lock return status.  *  * Successfully obtained locks return 0. Locks will always succeed  * unless one of the following is true:  *	LK_FORCEUPGRADE is requested and some other process has already  *	    requested a lock upgrade (returns EBUSY).  *	LK_WAIT is set and a sleep would be required (returns EBUSY).  *	LK_SLEEPFAIL is set and a sleep was done (returns ENOLCK).  *	PCATCH is set in lock priority and a signal arrives (returns  *	    either EINTR or ERESTART if system calls is to be restarted).  *	Non-null lock timeout and timeout expires (returns EWOULDBLOCK).  * A failed lock attempt always returns a non-zero error value. No lock  * is held after an error return (in particular, a failed LK_UPGRADE  * or LK_FORCEUPGRADE will have released its shared access lock).  */
end_comment

begin_comment
comment|/*  * Indicator that no process holds exclusive lock  */
end_comment

begin_define
define|#
directive|define
name|LK_KERNPROC
value|((struct thread *)-2)
end_define

begin_define
define|#
directive|define
name|LK_NOPROC
value|((struct thread *) -1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|LOCKMGR_ASSERT
parameter_list|(
name|lkp
parameter_list|,
name|what
parameter_list|,
name|p
parameter_list|)
value|do {				\ 	switch ((what)) {						\ 	case LK_SHARED:							\ 		if (lockstatus((lkp), (p)) == LK_SHARED)		\ 			break;						\
comment|/* fall into exclusive */
value|\ 	case LK_EXCLUSIVE:						\ 		if (lockstatus((lkp), (p)) != LK_EXCLUSIVE)		\ 			panic("lock %s %s not held at %s:%d",		\ 			    (lkp)->lk_wmesg, #what, __FILE__,		\ 			    __LINE__);					\ 		break;							\ 	default:							\ 		panic("unknown LOCKMGR_ASSERT at %s:%d", __FILE__,	\ 		    __LINE__);						\ 	}								\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* INVARIANTS */
end_comment

begin_define
define|#
directive|define
name|LOCKMGR_ASSERT
parameter_list|(
name|lkp
parameter_list|,
name|p
parameter_list|,
name|what
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INVARIANTS */
end_comment

begin_function_decl
name|void
name|dumplockinfo
parameter_list|(
name|struct
name|lock
modifier|*
name|lkp
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|lockinit
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|int
name|prio
parameter_list|,
specifier|const
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|timo
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lockdestroy
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_lockmgr
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|u_int
name|flags
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
name|p
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|transferlockers
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|struct
name|lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lockmgr_printinfo
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockstatus
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockcount
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lockwaiters
parameter_list|(
name|struct
name|lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|lockmgr
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|mtx
parameter_list|,
name|td
parameter_list|)
value|_lockmgr((lock), (flags), (mtx), (td), __FILE__, __LINE__)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_function_decl
name|int
name|lockmgr_chain
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|thread
modifier|*
modifier|*
name|ownerp
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
comment|/* !_SYS_LOCKMGR_H_ */
end_comment

end_unit

