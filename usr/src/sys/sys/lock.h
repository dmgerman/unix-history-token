begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Avadis Tevanian, Jr., Michael Wayne Young, and the Mach Operating  * System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)lock.h	8.1 (Berkeley) %G%  */
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
comment|/*  * XXX This belongs in<machine/param.h>, but is here for now.  */
end_comment

begin_define
define|#
directive|define
name|NCPUS
value|1
end_define

begin_comment
comment|/*  * An atomic spin lock.  *  * This structure only sets one bit of data, but is sized based on the  * minimum word size that can be operated on by the hardware test-and-set  * instruction. It is only needed for multiprocessors, as uniprocessors  * will always run to completion or a sleep. It is an error to hold one  * of these locks while a process is sleeping.  */
end_comment

begin_struct
struct|struct
name|atomic_lk
block|{
name|int
name|lock_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The general lock structure.  Provides for multiple shared locks,  * upgrading from shared to exclusive, and sleeping until the lock  * can be gained.  */
end_comment

begin_struct
struct|struct
name|lock
block|{
name|struct
name|atomic_lk
name|lk_interlock
decl_stmt|;
comment|/* lock on remaining fields */
name|int
name|lk_flags
decl_stmt|;
comment|/* see below */
name|int
name|lk_sharecount
decl_stmt|;
comment|/* # of accepted shared locks */
name|int
name|lk_exclusivecount
decl_stmt|;
comment|/* # of recursive exclusive locks */
name|int
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
comment|/*  * Lock request types.  *  * These are flags that are passed to the lockmgr routine.  */
end_comment

begin_define
define|#
directive|define
name|LK_TYPE_MASK
value|0x00000007
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
name|LK_DOWNGRADE
value|0x00000004
end_define

begin_comment
comment|/* exclusive-to-shared downgrade */
end_comment

begin_define
define|#
directive|define
name|LK_RELEASE
value|0x00000005
end_define

begin_comment
comment|/* release any type of lock */
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
name|LK_WAITING
value|0x00000100
end_define

begin_comment
comment|/* process is sleeping on lock */
end_comment

begin_define
define|#
directive|define
name|LK_WANT_UPGRADE
value|0x00000200
end_define

begin_comment
comment|/* waiting for share-to-excl upgrade */
end_comment

begin_define
define|#
directive|define
name|LK_WANT_EXCL
value|0x00000400
end_define

begin_comment
comment|/* exclusive lock sought */
end_comment

begin_define
define|#
directive|define
name|LK_HAVE_EXCL
value|0x00000800
end_define

begin_comment
comment|/* exclusive lock obtained */
end_comment

begin_comment
comment|/*  * Lock return status.  *  * Successfully obtained locks return 0. Locks will always succeed  * unless one of the following is true:  *	LK_WAIT is set and a sleep would be required (returns EBUSY).  *	LK_SLEEPFAIL is set and a sleep was done (returns ENOLCK).  *	PCATCH is set in lock priority and a signal arrives (returns  *	    either EINTR or ERESTART if system calls is to be restarted).  *	Non-null lock timeout and timeout expires (returns EWOULDBLOCK).  * A failed lock attempt always returns a non-zero error value.  * If the lock acquisition caused the process to sleep, the LK_SLEPT  * flag is set otherwise it is cleared.  */
end_comment

begin_define
define|#
directive|define
name|LK_SLEPT
value|0x00001000
end_define

begin_comment
comment|/* process slept while acquiring lock */
end_comment

begin_comment
comment|/*  * Indicator that no process holds exclusive lock  */
end_comment

begin_define
define|#
directive|define
name|LK_NOPROC
value|((pid_t) -1)
end_define

begin_decl_stmt
name|void
name|lock_init
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
expr|struct
name|lock
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|NCPUS
operator|>
literal|1
end_if

begin_comment
comment|/*  * The simple-lock routines are the primitives out of which the lock  * package is built. The machine-dependent code must implement an  * atomic test_and_set operation that indivisibly sets the atomic_lk  * to non-zero and returns its old value. It also assumes that the  * setting of the lock to zero below is indivisible. Atomic locks may  * only be used for exclusive locks.  */
end_comment

begin_function
specifier|inline
name|void
name|atomic_lock_init
parameter_list|(
name|lkp
parameter_list|)
name|struct
name|atomic_lk
modifier|*
name|lkp
decl_stmt|;
block|{
name|lkp
operator|->
name|lock_data
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|atomic_lock
parameter_list|(
name|lkp
parameter_list|)
name|struct
name|atomic_lk
modifier|*
name|lkp
decl_stmt|;
block|{
while|while
condition|(
name|test_and_set
argument_list|(
operator|&
name|lkp
operator|->
name|lock_data
argument_list|)
condition|)
continue|continue;
block|}
end_function

begin_function
specifier|inline
name|void
name|atomic_unlock
parameter_list|(
name|lkp
parameter_list|)
name|struct
name|atomic_lk
modifier|*
name|lkp
decl_stmt|;
block|{
name|lkp
operator|->
name|lock_data
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NCPUS == 1, so no multiprocessor locking is necessary */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DIAGNOSTIC
end_ifdef

begin_function
specifier|inline
name|void
name|atomic_lock_init
parameter_list|(
name|alp
parameter_list|)
name|struct
name|atomic_lk
modifier|*
name|alp
decl_stmt|;
block|{
name|alp
operator|->
name|lock_data
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|atomic_lock
parameter_list|(
name|alp
parameter_list|)
name|struct
name|atomic_lk
modifier|*
name|alp
decl_stmt|;
block|{
if|if
condition|(
name|alp
operator|->
name|lock_data
operator|==
literal|1
condition|)
name|panic
argument_list|(
literal|"atomic lock held"
argument_list|)
expr_stmt|;
else|else
name|alp
operator|->
name|lock_data
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|atomic_unlock
parameter_list|(
name|alp
parameter_list|)
name|struct
name|atomic_lk
modifier|*
name|alp
decl_stmt|;
block|{
if|if
condition|(
name|alp
operator|->
name|lock_data
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"atomic lock not held"
argument_list|)
expr_stmt|;
else|else
name|alp
operator|->
name|lock_data
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !DIAGNOSTIC */
end_comment

begin_define
define|#
directive|define
name|atomic_lock_init
parameter_list|(
name|alp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|atomic_lock
parameter_list|(
name|alp
parameter_list|)
end_define

begin_define
define|#
directive|define
name|atomic_unlock
parameter_list|(
name|alp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DIAGNOSTIC */
end_comment

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
comment|/* !_LOCK_H_ */
end_comment

end_unit

