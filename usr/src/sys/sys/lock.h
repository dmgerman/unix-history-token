begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code contains ideas from software contributed to Berkeley by  * Avadis Tevanian, Jr., Michael Wayne Young, and the Mach Operating  * System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)lock.h	8.10 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOCK_H_
end_define

begin_comment
comment|/*  * The general lock structure.  Provides for multiple shared locks,  * upgrading from shared to exclusive, and sleeping until the lock  * can be gained. The simple locks are defined in<machine/param.h>.  */
end_comment

begin_struct
struct|struct
name|lock
block|{
name|struct
name|simplelock
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
name|char
modifier|*
name|lk_wmesg
decl_stmt|;
comment|/* resource sleeping (for tsleep) */
name|int
name|lk_timo
decl_stmt|;
comment|/* maximum sleep time (for tsleep) */
name|pid_t
name|lk_lockholder
decl_stmt|;
comment|/* pid of exclusive lock holder */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Lock request types:  *   LK_SHARED - get one of many possible shared locks. If a process  *	holding an exclusive lock requests a shared lock, the exclusive  *	lock(s) will be downgraded to shared locks.  *   LK_EXCLUSIVE - stop further shared locks, when they are cleared,  *	grant a pending upgrade if it exists, then grant an exclusive  *	lock. Only one exclusive lock may exist at a time, except that  *	a process holding an exclusive lock may get additional exclusive  *	locks if it explicitly sets the LK_CANRECURSE flag in the lock  *	request, or if the LK_CANRECUSE flag was set when the lock was  *	initialized.  *   LK_UPGRADE - the process must hold a shared lock that it wants to  *	have upgraded to an exclusive lock. Other processes may get  *	exclusive access to the resource between the time that the upgrade  *	is requested and the time that it is granted.  *   LK_EXCLUPGRADE - the process must hold a shared lock that it wants to  *	have upgraded to an exclusive lock. If the request succeeds, no  *	other processes will have gotten exclusive access to the resource  *	between the time that the upgrade is requested and the time that  *	it is granted. However, if another process has already requested  *	an upgrade, the request will fail (see error returns below).  *   LK_DOWNGRADE - the process must hold an exclusive lock that it wants  *	to have downgraded to a shared lock. If the process holds multiple  *	(recursive) exclusive locks, they will all be downgraded to shared  *	locks.  *   LK_RELEASE - release one instance of a lock.  *   LK_DRAIN - wait for all activity on the lock to end, then mark it  *	decommissioned. This feature is used before freeing a lock that  *	is part of a piece of memory that is about to be freed.  *  * These are flags that are passed to the lockmgr routine.  */
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

begin_comment
comment|/*  * External lock flags.  *  * These flags may be set in lock_init to set their mode permanently,  * or passed in as arguments to the lock manager.  */
end_comment

begin_define
define|#
directive|define
name|LK_EXTFLG_MASK
value|0x000000f0
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

begin_comment
comment|/*  * Internal lock flags.  *  * These flags are used internally to the lock manager.  */
end_comment

begin_define
define|#
directive|define
name|LK_WANT_UPGRADE
value|0x00000100
end_define

begin_comment
comment|/* waiting for share-to-excl upgrade */
end_comment

begin_define
define|#
directive|define
name|LK_WANT_EXCL
value|0x00000200
end_define

begin_comment
comment|/* exclusive lock sought */
end_comment

begin_define
define|#
directive|define
name|LK_HAVE_EXCL
value|0x00000400
end_define

begin_comment
comment|/* exclusive lock obtained */
end_comment

begin_define
define|#
directive|define
name|LK_WAITDRAIN
value|0x00000800
end_define

begin_comment
comment|/* process waiting for lock to drain */
end_comment

begin_define
define|#
directive|define
name|LK_DRAINING
value|0x00004000
end_define

begin_comment
comment|/* lock is being drained */
end_comment

begin_define
define|#
directive|define
name|LK_DRAINED
value|0x00008000
end_define

begin_comment
comment|/* lock has been decommissioned */
end_comment

begin_comment
comment|/*  * Control flags  *  * Non-persistent external flags.  */
end_comment

begin_define
define|#
directive|define
name|LK_INTERLOCK
value|0x00010000
end_define

begin_comment
comment|/* unlock passed simple lock after 					   getting lk_interlock */
end_comment

begin_define
define|#
directive|define
name|LK_RETRY
value|0x00020000
end_define

begin_comment
comment|/* vn_lock: retry until locked */
end_comment

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
value|((pid_t) -2)
end_define

begin_define
define|#
directive|define
name|LK_NOPROC
value|((pid_t) -1)
end_define

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|lockinit
name|__P
argument_list|(
operator|(
expr|struct
name|lock
operator|*
operator|,
name|int
name|prio
operator|,
name|char
operator|*
name|wmesg
operator|,
name|int
name|timo
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lockmgr
name|__P
argument_list|(
operator|(
name|__volatile
expr|struct
name|lock
operator|*
operator|,
name|u_int
name|flags
operator|,
expr|struct
name|simplelock
operator|*
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
name|lockstatus
name|__P
argument_list|(
operator|(
expr|struct
name|lock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|void
name|simple_unlock
name|__P
argument_list|(
operator|(
name|__volatile
expr|struct
name|simplelock
operator|*
name|alp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|simple_lock_try
name|__P
argument_list|(
operator|(
name|__volatile
expr|struct
name|simplelock
operator|*
name|alp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|simple_lock
name|__P
argument_list|(
operator|(
name|__volatile
expr|struct
name|simplelock
operator|*
name|alp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|simple_lock_init
name|__P
argument_list|(
operator|(
expr|struct
name|simplelock
operator|*
name|alp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DEBUG */
end_comment

begin_if
if|#
directive|if
name|NCPUS
operator|==
literal|1
end_if

begin_comment
comment|/* no multiprocessor locking is necessary */
end_comment

begin_define
define|#
directive|define
name|simple_lock_init
parameter_list|(
name|alp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|simple_lock
parameter_list|(
name|alp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|simple_lock_try
parameter_list|(
name|alp
parameter_list|)
value|(1)
end_define

begin_comment
comment|/* always succeeds */
end_comment

begin_define
define|#
directive|define
name|simple_unlock
parameter_list|(
name|alp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCPUS == 1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LOCK_H_ */
end_comment

end_unit

