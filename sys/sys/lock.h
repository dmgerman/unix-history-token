begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from BSDI $Id: mutex.h,v 2.7.2.35 2000/04/27 03:10:26 cp Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_LOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_LOCK_H_
end_define

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
name|thread
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Lock classes.  Each lock has a class which describes characteristics  * common to all types of locks of a given class.  *  * Spin locks in general must always protect against preemption, as it is  * an error to perform any type of context switch while holding a spin lock.  * Also, for an individual lock to be recursable, its class must allow  * recursion and the lock itself must explicitly allow recursion.  *  * The 'lc_ddb_show' function pointer is used to dump class-specific  * data for the 'show lock' DDB command.  The 'lc_lock' and  * 'lc_unlock' function pointers are used in sleep(9) and cv_wait(9)  * to lock and unlock locks while blocking on a sleep queue.  The  * return value of 'lc_unlock' will be passed to 'lc_lock' on resume  * to allow communication of state between the two routines.  */
end_comment

begin_struct
struct|struct
name|lock_class
block|{
specifier|const
name|char
modifier|*
name|lc_name
decl_stmt|;
name|u_int
name|lc_flags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|lc_ddb_show
function_decl|)
parameter_list|(
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|lc_lock
function_decl|)
parameter_list|(
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|,
name|int
name|how
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|lc_unlock
function_decl|)
parameter_list|(
name|struct
name|lock_object
modifier|*
name|lock
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LC_SLEEPLOCK
value|0x00000001
end_define

begin_comment
comment|/* Sleep lock. */
end_comment

begin_define
define|#
directive|define
name|LC_SPINLOCK
value|0x00000002
end_define

begin_comment
comment|/* Spin lock. */
end_comment

begin_define
define|#
directive|define
name|LC_SLEEPABLE
value|0x00000004
end_define

begin_comment
comment|/* Sleeping allowed with this lock. */
end_comment

begin_define
define|#
directive|define
name|LC_RECURSABLE
value|0x00000008
end_define

begin_comment
comment|/* Locks of this type may recurse. */
end_comment

begin_define
define|#
directive|define
name|LC_UPGRADABLE
value|0x00000010
end_define

begin_comment
comment|/* Upgrades and downgrades permitted. */
end_comment

begin_define
define|#
directive|define
name|LO_CLASSFLAGS
value|0x0000ffff
end_define

begin_comment
comment|/* Class specific flags. */
end_comment

begin_define
define|#
directive|define
name|LO_INITIALIZED
value|0x00010000
end_define

begin_comment
comment|/* Lock has been initialized. */
end_comment

begin_define
define|#
directive|define
name|LO_WITNESS
value|0x00020000
end_define

begin_comment
comment|/* Should witness monitor this lock. */
end_comment

begin_define
define|#
directive|define
name|LO_QUIET
value|0x00040000
end_define

begin_comment
comment|/* Don't log locking operations. */
end_comment

begin_define
define|#
directive|define
name|LO_RECURSABLE
value|0x00080000
end_define

begin_comment
comment|/* Lock may recurse. */
end_comment

begin_define
define|#
directive|define
name|LO_SLEEPABLE
value|0x00100000
end_define

begin_comment
comment|/* Lock may be held while sleeping. */
end_comment

begin_define
define|#
directive|define
name|LO_UPGRADABLE
value|0x00200000
end_define

begin_comment
comment|/* Lock may be upgraded/downgraded. */
end_comment

begin_define
define|#
directive|define
name|LO_DUPOK
value|0x00400000
end_define

begin_comment
comment|/* Don't check for duplicate acquires */
end_comment

begin_define
define|#
directive|define
name|LO_ENROLLPEND
value|0x00800000
end_define

begin_comment
comment|/* On the pending enroll list. */
end_comment

begin_define
define|#
directive|define
name|LO_CLASSMASK
value|0x0f000000
end_define

begin_comment
comment|/* Class index bitmask. */
end_comment

begin_define
define|#
directive|define
name|LO_NOPROFILE
value|0x10000000
end_define

begin_comment
comment|/* Don't profile this lock */
end_comment

begin_define
define|#
directive|define
name|LO_CONTESTED
value|0x20000000
end_define

begin_comment
comment|/* Lock was contested */
end_comment

begin_comment
comment|/*  * Lock classes are statically assigned an index into the gobal lock_classes  * array.  Debugging code looks up the lock class for a given lock object  * by indexing the array.  */
end_comment

begin_define
define|#
directive|define
name|LO_CLASSSHIFT
value|24
end_define

begin_define
define|#
directive|define
name|LO_CLASSINDEX
parameter_list|(
name|lock
parameter_list|)
value|((((lock)->lo_flags)& LO_CLASSMASK)>> LO_CLASSSHIFT)
end_define

begin_define
define|#
directive|define
name|LOCK_CLASS
parameter_list|(
name|lock
parameter_list|)
value|(lock_classes[LO_CLASSINDEX((lock))])
end_define

begin_define
define|#
directive|define
name|LOCK_CLASS_MAX
value|(LO_CLASSMASK>> LO_CLASSSHIFT)
end_define

begin_define
define|#
directive|define
name|LI_RECURSEMASK
value|0x0000ffff
end_define

begin_comment
comment|/* Recursion depth of lock instance. */
end_comment

begin_define
define|#
directive|define
name|LI_EXCLUSIVE
value|0x00010000
end_define

begin_comment
comment|/* Exclusive lock instance. */
end_comment

begin_comment
comment|/*  * Option flags passed to lock operations that witness also needs to know  * about or that are generic across all locks.  */
end_comment

begin_define
define|#
directive|define
name|LOP_NEWORDER
value|0x00000001
end_define

begin_comment
comment|/* Define a new lock order. */
end_comment

begin_define
define|#
directive|define
name|LOP_QUIET
value|0x00000002
end_define

begin_comment
comment|/* Don't log locking operations. */
end_comment

begin_define
define|#
directive|define
name|LOP_TRYLOCK
value|0x00000004
end_define

begin_comment
comment|/* Don't check lock order. */
end_comment

begin_define
define|#
directive|define
name|LOP_EXCLUSIVE
value|0x00000008
end_define

begin_comment
comment|/* Exclusive lock. */
end_comment

begin_define
define|#
directive|define
name|LOP_DUPOK
value|0x00000010
end_define

begin_comment
comment|/* Don't check for duplicate acquires */
end_comment

begin_comment
comment|/* Flags passed to witness_assert. */
end_comment

begin_define
define|#
directive|define
name|LA_UNLOCKED
value|0x00000000
end_define

begin_comment
comment|/* Lock is unlocked. */
end_comment

begin_define
define|#
directive|define
name|LA_LOCKED
value|0x00000001
end_define

begin_comment
comment|/* Lock is at least share locked. */
end_comment

begin_define
define|#
directive|define
name|LA_SLOCKED
value|0x00000002
end_define

begin_comment
comment|/* Lock is exactly share locked. */
end_comment

begin_define
define|#
directive|define
name|LA_XLOCKED
value|0x00000004
end_define

begin_comment
comment|/* Lock is exclusively locked. */
end_comment

begin_define
define|#
directive|define
name|LA_RECURSED
value|0x00000008
end_define

begin_comment
comment|/* Lock is recursed. */
end_comment

begin_define
define|#
directive|define
name|LA_NOTRECURSED
value|0x00000010
end_define

begin_comment
comment|/* Lock is not recursed. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Lock instances.  A lock instance is the data associated with a lock while  * it is held by witness.  For example, a lock instance will hold the  * recursion count of a lock.  Lock instances are held in lists.  Spin locks  * are held in a per-cpu list while sleep locks are held in per-thread list.  */
end_comment

begin_struct
struct|struct
name|lock_instance
block|{
name|struct
name|lock_object
modifier|*
name|li_lock
decl_stmt|;
specifier|const
name|char
modifier|*
name|li_file
decl_stmt|;
comment|/* File and line of last acquire. */
name|int
name|li_line
decl_stmt|;
name|u_int
name|li_flags
decl_stmt|;
comment|/* Recursion count and LI_* flags. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A simple list type used to build the list of locks held by a thread  * or CPU.  We can't simply embed the list in struct lock_object since a  * lock may be held by more than one thread if it is a shared lock.  Locks  * are added to the head of the list, so we fill up each list entry from  * "the back" logically.  To ease some of the arithmetic, we actually fill  * in each list entry the normal way (childer[0] then children[1], etc.) but  * when we traverse the list we read children[count-1] as the first entry  * down to children[0] as the final entry.  */
end_comment

begin_define
define|#
directive|define
name|LOCK_NCHILDREN
value|3
end_define

begin_struct
struct|struct
name|lock_list_entry
block|{
name|struct
name|lock_list_entry
modifier|*
name|ll_next
decl_stmt|;
name|struct
name|lock_instance
name|ll_children
index|[
name|LOCK_NCHILDREN
index|]
decl_stmt|;
name|u_int
name|ll_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * If any of WITNESS, INVARIANTS, or KTR_LOCK KTR tracing has been enabled,  * then turn on LOCK_DEBUG.  When this option is on, extra debugging  * facilities such as tracking the file and line number of lock operations  * are enabled.  Also, mutex locking operations are not inlined to avoid  * bloat from all the extra debugging code.  We also have to turn on all the  * calling conventions for this debugging code in modules so that modules can  * work with both debug and non-debug kernels.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
operator|||
name|defined
argument_list|(
name|WITNESS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|||
name|defined
argument_list|(
name|INVARIANT_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|KTR
argument_list|)
operator|||
name|defined
argument_list|(
name|LOCK_PROFILING
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOCK_DEBUG
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCK_DEBUG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * In the LOCK_DEBUG case, use the filename and line numbers for debugging  * operations.  Otherwise, use default values to avoid the unneeded bloat.  */
end_comment

begin_if
if|#
directive|if
name|LOCK_DEBUG
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|LOCK_FILE
value|__FILE__
end_define

begin_define
define|#
directive|define
name|LOCK_LINE
value|__LINE__
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCK_FILE
value|NULL
end_define

begin_define
define|#
directive|define
name|LOCK_LINE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macros for KTR_LOCK tracing.  *  * opname  - name of this operation (LOCK/UNLOCK/SLOCK, etc.)  * lo      - struct lock_object * for this lock  * flags   - flags passed to the lock operation  * recurse - this locks recursion level (or 0 if class is not recursable)  * result  - result of a try lock operation  * file    - file name  * line    - line number  */
end_comment

begin_define
define|#
directive|define
name|LOCK_LOG_TEST
parameter_list|(
name|lo
parameter_list|,
name|flags
parameter_list|)
define|\
value|(((flags)& LOP_QUIET) == 0&& ((lo)->lo_flags& LO_QUIET) == 0)
end_define

begin_define
define|#
directive|define
name|LOCK_LOG_LOCK
parameter_list|(
name|opname
parameter_list|,
name|lo
parameter_list|,
name|flags
parameter_list|,
name|recurse
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {	\ 	if (LOCK_LOG_TEST((lo), (flags)))				\ 		CTR5(KTR_LOCK, opname " (%s) %s r = %d at %s:%d",	\ 		    LOCK_CLASS(lo)->lc_name, (lo)->lo_name,		\ 		    (u_int)(recurse), (file), (line));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|LOCK_LOG_TRY
parameter_list|(
name|opname
parameter_list|,
name|lo
parameter_list|,
name|flags
parameter_list|,
name|result
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|do {	\ 	if (LOCK_LOG_TEST((lo), (flags)))				\ 		CTR5(KTR_LOCK, "TRY_" opname " (%s) %s result=%d at %s:%d",\ 		    LOCK_CLASS(lo)->lc_name, (lo)->lo_name,		\ 		    (u_int)(result), (file), (line));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|LOCK_LOG_INIT
parameter_list|(
name|lo
parameter_list|,
name|flags
parameter_list|)
value|do {					\ 	if (LOCK_LOG_TEST((lo), (flags)))				\ 		CTR4(KTR_LOCK, "%s: %p (%s) %s", __func__, (lo),	\  		    LOCK_CLASS(lo)->lc_name, (lo)->lo_name);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|LOCK_LOG_DESTROY
parameter_list|(
name|lo
parameter_list|,
name|flags
parameter_list|)
value|LOCK_LOG_INIT(lo, flags)
end_define

begin_define
define|#
directive|define
name|lock_initalized
parameter_list|(
name|lo
parameter_list|)
value|((lo)->lo_flags& LO_INITIALIZED)
end_define

begin_comment
comment|/*  * Helpful macros for quickly coming up with assertions with informative  * panic messages.  */
end_comment

begin_define
define|#
directive|define
name|MPASS
parameter_list|(
name|ex
parameter_list|)
value|MPASS4(ex, #ex, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|MPASS2
parameter_list|(
name|ex
parameter_list|,
name|what
parameter_list|)
value|MPASS4(ex, what, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|MPASS3
parameter_list|(
name|ex
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
value|MPASS4(ex, #ex, file, line)
end_define

begin_define
define|#
directive|define
name|MPASS4
parameter_list|(
name|ex
parameter_list|,
name|what
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|KASSERT((ex), ("Assertion %s failed at %s:%d", what, file, line))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|lock_class
name|lock_class_mtx_sleep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|lock_class
name|lock_class_mtx_spin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|lock_class
name|lock_class_sx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|lock_class
name|lock_class_rw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|lock_class
name|lock_class_lockmgr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|lock_class
modifier|*
name|lock_classes
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|lock_init
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
name|struct
name|lock_class
modifier|*
parameter_list|,
specifier|const
name|char
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

begin_function_decl
name|void
name|lock_destroy
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spinlock_enter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|spinlock_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_init
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_destroy
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|witness_defineorder
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_checkorder
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_lock
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_upgrade
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_downgrade
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_unlock
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_save
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_restore
parameter_list|(
name|struct
name|lock_object
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

begin_function_decl
name|int
name|witness_list_locks
parameter_list|(
name|struct
name|lock_list_entry
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|witness_warn
parameter_list|(
name|int
parameter_list|,
name|struct
name|lock_object
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_assert
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|witness_display_spinlock
parameter_list|(
name|struct
name|lock_object
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
name|witness_line
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|witness_file
parameter_list|(
name|struct
name|lock_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WITNESS
end_ifdef

begin_comment
comment|/* Flags for witness_warn(). */
end_comment

begin_define
define|#
directive|define
name|WARN_GIANTOK
value|0x01
end_define

begin_comment
comment|/* Giant is exempt from this check. */
end_comment

begin_define
define|#
directive|define
name|WARN_PANIC
value|0x02
end_define

begin_comment
comment|/* Panic if check fails. */
end_comment

begin_define
define|#
directive|define
name|WARN_SLEEPOK
value|0x04
end_define

begin_comment
comment|/* Sleepable locks are exempt from check. */
end_comment

begin_define
define|#
directive|define
name|WITNESS_INIT
parameter_list|(
name|lock
parameter_list|)
define|\
value|witness_init((lock))
end_define

begin_define
define|#
directive|define
name|WITNESS_DESTROY
parameter_list|(
name|lock
parameter_list|)
define|\
value|witness_destroy(lock)
end_define

begin_define
define|#
directive|define
name|WITNESS_CHECKORDER
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|witness_checkorder((lock), (flags), (file), (line))
end_define

begin_define
define|#
directive|define
name|WITNESS_DEFINEORDER
parameter_list|(
name|lock1
parameter_list|,
name|lock2
parameter_list|)
define|\
value|witness_defineorder((struct lock_object *)(lock1),		\ 	    (struct lock_object *)(lock2))
end_define

begin_define
define|#
directive|define
name|WITNESS_LOCK
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|witness_lock((lock), (flags), (file), (line))
end_define

begin_define
define|#
directive|define
name|WITNESS_UPGRADE
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|witness_upgrade((lock), (flags), (file), (line))
end_define

begin_define
define|#
directive|define
name|WITNESS_DOWNGRADE
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|witness_downgrade((lock), (flags), (file), (line))
end_define

begin_define
define|#
directive|define
name|WITNESS_UNLOCK
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|witness_unlock((lock), (flags), (file), (line))
end_define

begin_define
define|#
directive|define
name|WITNESS_CHECK
parameter_list|(
name|flags
parameter_list|,
name|lock
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|witness_warn((flags), (lock), (fmt), ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WITNESS_WARN
parameter_list|(
name|flags
parameter_list|,
name|lock
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|witness_warn((flags), (lock), (fmt), ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|WITNESS_SAVE_DECL
parameter_list|(
name|n
parameter_list|)
define|\
value|const char * __CONCAT(n, __wf);					\ 	int __CONCAT(n, __wl)
end_define

begin_define
define|#
directive|define
name|WITNESS_SAVE
parameter_list|(
name|lock
parameter_list|,
name|n
parameter_list|)
define|\
value|witness_save((lock),&__CONCAT(n, __wf),&__CONCAT(n, __wl))
end_define

begin_define
define|#
directive|define
name|WITNESS_RESTORE
parameter_list|(
name|lock
parameter_list|,
name|n
parameter_list|)
define|\
value|witness_restore((lock), __CONCAT(n, __wf), __CONCAT(n, __wl))
end_define

begin_define
define|#
directive|define
name|WITNESS_FILE
parameter_list|(
name|lock
parameter_list|)
define|\
value|witness_file(lock)
end_define

begin_define
define|#
directive|define
name|WITNESS_LINE
parameter_list|(
name|lock
parameter_list|)
define|\
value|witness_line(lock)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* WITNESS */
end_comment

begin_define
define|#
directive|define
name|WITNESS_INIT
parameter_list|(
name|lock
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_DESTROY
parameter_list|(
name|lock
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_DEFINEORDER
parameter_list|(
name|lock1
parameter_list|,
name|lock2
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|WITNESS_CHECKORDER
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_LOCK
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_UPGRADE
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_DOWNGRADE
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_UNLOCK
parameter_list|(
name|lock
parameter_list|,
name|flags
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_CHECK
parameter_list|(
name|flags
parameter_list|,
name|lock
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|WITNESS_WARN
parameter_list|(
name|flags
parameter_list|,
name|lock
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_SAVE_DECL
parameter_list|(
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_SAVE
parameter_list|(
name|lock
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_RESTORE
parameter_list|(
name|lock
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WITNESS_FILE
parameter_list|(
name|lock
parameter_list|)
value|("?")
end_define

begin_define
define|#
directive|define
name|WITNESS_LINE
parameter_list|(
name|lock
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITNESS */
end_comment

begin_comment
comment|/*  * Helper macros to allow developers to add explicit lock order checks  * wherever they please without having to actually grab a lock to do so.  */
end_comment

begin_define
define|#
directive|define
name|witness_check
parameter_list|(
name|l
parameter_list|)
define|\
value|WITNESS_CHECKORDER(&(l)->lock_object, LOP_EXCLUSIVE, LOCK_FILE,	\ 	    LOCK_LINE)
end_define

begin_define
define|#
directive|define
name|witness_check_shared
parameter_list|(
name|l
parameter_list|)
define|\
value|WITNESS_CHECKORDER(&(l)->lock_object, 0, LOCK_FILE, LOCK_LINE)
end_define

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
comment|/* _SYS_LOCK_H_ */
end_comment

end_unit

