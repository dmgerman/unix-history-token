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

begin_comment
comment|/*  * XXX - compatability until lockmgr() goes away or all the #includes are  * updated.  */
end_comment

begin_include
include|#
directive|include
file|<sys/lockmgr.h>
end_include

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

begin_comment
comment|/*  * Lock classes.  Each lock has a class which describes characteristics  * common to all types of locks of a given class.  *  * Spin locks in general must always protect against preemption, as it is  * an error to perform any type of context switch while holding a spin lock.  * Also, for an individual lock to be recursable, its class must allow  * recursion and the lock itself must explicitly allow recursion.  */
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
name|LO_LOCKED
value|0x01000000
end_define

begin_comment
comment|/* Someone holds this lock. */
end_comment

begin_define
define|#
directive|define
name|LO_RECURSED
value|0x02000000
end_define

begin_comment
comment|/* Someone has recursed on this lock. */
end_comment

begin_comment
comment|/*  * Option flags passed to lock operations that witness also needs to know  * about or that are generic across all locks.  */
end_comment

begin_define
define|#
directive|define
name|LOP_NOSWITCH
value|0x00000001
end_define

begin_comment
comment|/* Lock doesn't switch on release. */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * A simple list type used to build the list of locks held by a process  * or CPU.  We can't simply embed the list in struct lock_object since a  * lock may be held by more than one process if it is a shared lock.  Locks  * are added to the head of the list, so we fill up each list entry from  * "the back" logically.  To ease some of the arithmetic, we actually fill  * in each list entry the normal way (childer[0] then children[1], etc.) but  * when we traverse the list we read children[count-1] as the first entry  * down to children[0] as the final entry.  */
end_comment

begin_define
define|#
directive|define
name|LOCK_NCHILDREN
value|6
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
name|lock_object
modifier|*
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
value|do {	\ 	if (LOCK_LOG_TEST((lo), (flags)))				\ 		CTR5(KTR_LOCK, opname " (%s) %s r = %d at %s:%d",	\ 		    (lo)->lo_class->lc_name, (lo)->lo_name,		\ 		    (u_int)(recurse), (file), (line));			\ } while (0)
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
value|do {	\ 	if (LOCK_LOG_TEST((lo), (flags)))				\ 		CTR5(KTR_LOCK, "TRY_" opname " (%s) %s result=%d at %s:%d",\ 		    (lo)->lo_class->lc_name, (lo)->lo_name,		\ 		    (u_int)(result), (file), (line));			\ } while (0)
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
value|do {					\ 	if (LOCK_LOG_TEST((lo), (flags)))				\ 		CTR3(KTR_LOCK, __func__ ": %p (%s) %s",	(lo),		\  		    (lo)->lo_class->lc_name, (lo)->lo_name);		\ } while (0)
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
name|witness_list
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|witness_sleep
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WITNESS
end_ifdef

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
name|WITNESS_SLEEP
parameter_list|(
name|check
parameter_list|,
name|lock
parameter_list|)
define|\
value|witness_sleep((check), (lock), __FILE__, __LINE__)
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
value|(lock)->lo_flags |= LO_INITIALIZED
end_define

begin_define
define|#
directive|define
name|WITNESS_DESTROY
parameter_list|(
name|lock
parameter_list|)
value|(lock)->lo_flags&= ~LO_INITIALIZED
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
name|WITNESS_SLEEP
parameter_list|(
name|check
parameter_list|,
name|lock
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITNESS */
end_comment

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

