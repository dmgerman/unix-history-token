begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Max Khon<fjoe@freebsd.org>  * Copyright (c) 2012 Oleksandr Tymoshenko<gonzo@bluezbox.com>  * Copyright (c) 2013 Jared D. McNeill<jmcneill@invisible.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__VCHI_BSD_H__
end_ifndef

begin_define
define|#
directive|define
name|__VCHI_BSD_H__
end_define

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * Copy from/to user API  */
end_comment

begin_define
define|#
directive|define
name|copy_from_user
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|n
parameter_list|)
value|copyin((from), (to), (n))
end_define

begin_define
define|#
directive|define
name|copy_to_user
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|n
parameter_list|)
value|copyout((from), (to), (n))
end_define

begin_comment
comment|/*  * Bit API  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|test_and_set_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|val
decl_stmt|;
do|do
block|{
name|val
operator|=
operator|*
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|addr
expr_stmt|;
block|}
do|while
condition|(
name|atomic_cmpset_int
argument_list|(
name|addr
argument_list|,
name|val
argument_list|,
name|val
operator||
operator|(
literal|1
operator|<<
name|nr
operator|)
argument_list|)
operator|==
literal|0
condition|)
do|;
return|return
operator|(
name|val
operator|&
operator|(
literal|1
operator|<<
name|nr
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|int
name|test_and_clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|val
decl_stmt|;
do|do
block|{
name|val
operator|=
operator|*
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|addr
expr_stmt|;
block|}
do|while
condition|(
name|atomic_cmpset_int
argument_list|(
name|addr
argument_list|,
name|val
argument_list|,
name|val
operator|&
operator|~
operator|(
literal|1
operator|<<
name|nr
operator|)
argument_list|)
operator|==
literal|0
condition|)
do|;
return|return
operator|(
name|val
operator|&
operator|(
literal|1
operator|<<
name|nr
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Atomic API  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|atomic_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|atomic_set
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|(*(p) = (v))
end_define

begin_define
define|#
directive|define
name|atomic_read
parameter_list|(
name|p
parameter_list|)
value|(*(p))
end_define

begin_define
define|#
directive|define
name|atomic_inc
parameter_list|(
name|p
parameter_list|)
value|atomic_add_int(p, 1)
end_define

begin_define
define|#
directive|define
name|atomic_dec
parameter_list|(
name|p
parameter_list|)
value|atomic_subtract_int(p, 1)
end_define

begin_define
define|#
directive|define
name|atomic_dec_and_test
parameter_list|(
name|p
parameter_list|)
value|(atomic_fetchadd_int(p, -1) == 1)
end_define

begin_define
define|#
directive|define
name|atomic_inc_return
parameter_list|(
name|v
parameter_list|)
value|atomic_add_return(1, (v))
end_define

begin_define
define|#
directive|define
name|atomic_dec_return
parameter_list|(
name|v
parameter_list|)
value|atomic_sub_return(1, (v))
end_define

begin_define
define|#
directive|define
name|atomic_add
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|atomic_add_int(p, v)
end_define

begin_define
define|#
directive|define
name|atomic_sub
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|atomic_subtract_int(p, v)
end_define

begin_define
define|#
directive|define
name|ATOMIC_INIT
parameter_list|(
name|v
parameter_list|)
value|(v)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|atomic_add_return
parameter_list|(
name|int
name|i
parameter_list|,
name|atomic_t
modifier|*
name|v
parameter_list|)
block|{
return|return
name|i
operator|+
name|atomic_fetchadd_int
argument_list|(
name|v
argument_list|,
name|i
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|atomic_sub_return
parameter_list|(
name|int
name|i
parameter_list|,
name|atomic_t
modifier|*
name|v
parameter_list|)
block|{
return|return
name|atomic_fetchadd_int
argument_list|(
name|v
argument_list|,
operator|-
name|i
argument_list|)
operator|-
name|i
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|atomic_cmpxchg
parameter_list|(
name|atomic_t
modifier|*
name|v
parameter_list|,
name|int
name|oldv
parameter_list|,
name|int
name|newv
parameter_list|)
block|{
if|if
condition|(
name|atomic_cmpset_rel_int
argument_list|(
name|v
argument_list|,
name|oldv
argument_list|,
name|newv
argument_list|)
condition|)
return|return
name|newv
return|;
else|else
return|return
operator|*
name|v
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|atomic_xchg
parameter_list|(
name|atomic_t
modifier|*
name|v
parameter_list|,
name|int
name|newv
parameter_list|)
block|{
name|int
name|oldv
decl_stmt|;
if|if
condition|(
name|newv
operator|==
literal|0
condition|)
return|return
name|atomic_readandclear_int
argument_list|(
name|v
argument_list|)
return|;
else|else
block|{
do|do
block|{
name|oldv
operator|=
name|atomic_load_acq_int
argument_list|(
name|v
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|atomic_cmpset_rel_int
argument_list|(
name|v
argument_list|,
name|oldv
argument_list|,
name|newv
argument_list|)
condition|)
do|;
block|}
return|return
operator|(
name|oldv
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Spinlock API  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mtx
name|spinlock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEFINE_SPINLOCK
parameter_list|(
name|name
parameter_list|)
define|\
value|struct mtx name
end_define

begin_define
define|#
directive|define
name|spin_lock_init
parameter_list|(
name|lock
parameter_list|)
value|mtx_init(lock, "VCHI spinlock " # lock, NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|spin_lock_destroy
parameter_list|(
name|lock
parameter_list|)
value|mtx_destroy(lock)
end_define

begin_define
define|#
directive|define
name|spin_lock
parameter_list|(
name|lock
parameter_list|)
value|mtx_lock(lock)
end_define

begin_define
define|#
directive|define
name|spin_unlock
parameter_list|(
name|lock
parameter_list|)
value|mtx_unlock(lock)
end_define

begin_define
define|#
directive|define
name|spin_lock_bh
parameter_list|(
name|lock
parameter_list|)
value|spin_lock(lock)
end_define

begin_define
define|#
directive|define
name|spin_unlock_bh
parameter_list|(
name|lock
parameter_list|)
value|spin_unlock(lock)
end_define

begin_comment
comment|/*  * Mutex API  */
end_comment

begin_struct
struct|struct
name|mutex
block|{
name|struct
name|mtx
name|mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|lmutex_init
parameter_list|(
name|lock
parameter_list|)
value|mtx_init(&(lock)->mtx, #lock, NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|lmutex_lock
parameter_list|(
name|lock
parameter_list|)
value|mtx_lock(&(lock)->mtx)
end_define

begin_define
define|#
directive|define
name|lmutex_lock_interruptible
parameter_list|(
name|lock
parameter_list|)
value|(mtx_lock(&(lock)->mtx),0)
end_define

begin_define
define|#
directive|define
name|lmutex_unlock
parameter_list|(
name|lock
parameter_list|)
value|mtx_unlock(&(lock)->mtx)
end_define

begin_define
define|#
directive|define
name|lmutex_destroy
parameter_list|(
name|lock
parameter_list|)
value|mtx_destroy(&(lock)->mtx)
end_define

begin_comment
comment|/*  * Rwlock API  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|sx
name|rwlock_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SX_ADAPTIVESPIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SX_NOADAPTIVE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SX_NOADAPTIVE
value|SX_ADAPTIVESPIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEFINE_RWLOCK
parameter_list|(
name|name
parameter_list|)
define|\
value|struct sx name;					\ 	SX_SYSINIT(name,&name, #name)
end_define

begin_define
define|#
directive|define
name|rwlock_init
parameter_list|(
name|rwlock
parameter_list|)
value|sx_init_flags(rwlock, "VCHI rwlock", SX_NOADAPTIVE)
end_define

begin_define
define|#
directive|define
name|read_lock
parameter_list|(
name|rwlock
parameter_list|)
value|sx_slock(rwlock)
end_define

begin_define
define|#
directive|define
name|read_unlock
parameter_list|(
name|rwlock
parameter_list|)
value|sx_sunlock(rwlock)
end_define

begin_define
define|#
directive|define
name|write_lock
parameter_list|(
name|rwlock
parameter_list|)
value|sx_xlock(rwlock)
end_define

begin_define
define|#
directive|define
name|write_unlock
parameter_list|(
name|rwlock
parameter_list|)
value|sx_xunlock(rwlock)
end_define

begin_define
define|#
directive|define
name|write_lock_irqsave
parameter_list|(
name|rwlock
parameter_list|,
name|flags
parameter_list|)
define|\
value|do {						\ 		sx_xlock(rwlock);			\ 		(void)&(flags);			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|write_unlock_irqrestore
parameter_list|(
name|rwlock
parameter_list|,
name|flags
parameter_list|)
define|\
value|sx_xunlock(rwlock)
end_define

begin_define
define|#
directive|define
name|read_lock_bh
parameter_list|(
name|rwlock
parameter_list|)
value|sx_slock(rwlock)
end_define

begin_define
define|#
directive|define
name|read_unlock_bh
parameter_list|(
name|rwlock
parameter_list|)
value|sx_sunlock(rwlock)
end_define

begin_define
define|#
directive|define
name|write_lock_bh
parameter_list|(
name|rwlock
parameter_list|)
value|sx_xlock(rwlock)
end_define

begin_define
define|#
directive|define
name|write_unlock_bh
parameter_list|(
name|rwlock
parameter_list|)
value|sx_xunlock(rwlock)
end_define

begin_comment
comment|/*  * Timer API  */
end_comment

begin_struct
struct|struct
name|timer_list
block|{
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|callout
name|callout
decl_stmt|;
name|unsigned
name|long
name|expires
decl_stmt|;
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
name|unsigned
name|long
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|init_timer
parameter_list|(
name|struct
name|timer_list
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setup_timer
parameter_list|(
name|struct
name|timer_list
modifier|*
name|t
parameter_list|,
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|unsigned
name|long
parameter_list|)
parameter_list|,
name|unsigned
name|long
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mod_timer
parameter_list|(
name|struct
name|timer_list
modifier|*
name|t
parameter_list|,
name|unsigned
name|long
name|expires
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_timer
parameter_list|(
name|struct
name|timer_list
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|del_timer
parameter_list|(
name|struct
name|timer_list
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|del_timer_sync
parameter_list|(
name|struct
name|timer_list
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Completion API  */
end_comment

begin_struct
struct|struct
name|completion
block|{
name|struct
name|cv
name|cv
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
name|int
name|done
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|init_completion
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|destroy_completion
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|try_wait_for_completion
parameter_list|(
name|struct
name|completion
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wait_for_completion_interruptible
parameter_list|(
name|struct
name|completion
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wait_for_completion_interruptible_timeout
parameter_list|(
name|struct
name|completion
modifier|*
parameter_list|,
name|unsigned
name|long
name|ticks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wait_for_completion_killable
parameter_list|(
name|struct
name|completion
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wait_for_completion
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|complete
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|complete_all
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|INIT_COMPLETION_locked
parameter_list|(
name|struct
name|completion
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|INIT_COMPLETION
parameter_list|(
name|x
parameter_list|)
value|INIT_COMPLETION_locked(&(x))
end_define

begin_comment
comment|/*  * Semaphore API  */
end_comment

begin_struct
struct|struct
name|semaphore
block|{
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|cv
name|cv
decl_stmt|;
name|int
name|value
decl_stmt|;
name|int
name|waiters
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEFINE_SEMAPHORE
parameter_list|(
name|name
parameter_list|)
define|\
value|struct semaphore name;		\ 	SYSINIT(name##_sema_sysinit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    sema_sysinit,&name);					\ 	SYSUNINIT(name##_sema_sysuninit, SI_SUB_LOCK, SI_ORDER_MIDDLE,	\ 	    _sema_destroy, __DEVOLATILE(void *,&(name)))
end_define

begin_function_decl
name|void
name|sema_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_sema_init
parameter_list|(
name|struct
name|semaphore
modifier|*
name|s
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_sema_destroy
parameter_list|(
name|struct
name|semaphore
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|down
parameter_list|(
name|struct
name|semaphore
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|down_interruptible
parameter_list|(
name|struct
name|semaphore
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|down_trylock
parameter_list|(
name|struct
name|semaphore
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|up
parameter_list|(
name|struct
name|semaphore
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Logging and assertions API  */
end_comment

begin_function_decl
name|void
name|rlprintf
parameter_list|(
name|int
name|pps
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|device_rlprintf
parameter_list|(
name|int
name|pps
parameter_list|,
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|might_sleep
parameter_list|()
end_define

begin_define
define|#
directive|define
name|WARN
parameter_list|(
name|condition
parameter_list|,
name|msg
parameter_list|)
define|\
value|({							\ 	int __ret_warn_on = !!(condition);		\ 	if (unlikely(__ret_warn_on))			\ 		printf((msg));				\ 	unlikely(__ret_warn_on);			\ })
end_define

begin_define
define|#
directive|define
name|WARN_ON
parameter_list|(
name|condition
parameter_list|)
define|\
value|({							\ 	int __ret_warn_on = !!(condition);		\ 	if (unlikely(__ret_warn_on))			\ 		printf("WARN_ON: " #condition "\n");	\ 	unlikely(__ret_warn_on);			\ })
end_define

begin_define
define|#
directive|define
name|WARN_ON_ONCE
parameter_list|(
name|condition
parameter_list|)
value|({			\ 	static int __warned;				\ 	int __ret_warn_once = !!(condition);		\ 							\ 	if (unlikely(__ret_warn_once))			\ 		if (WARN_ON(!__warned))			\ 			__warned = 1;			\ 	unlikely(__ret_warn_once);			\ })
end_define

begin_define
define|#
directive|define
name|BUG_ON
parameter_list|(
name|cond
parameter_list|)
define|\
value|do {						\ 		if (cond)				\ 			panic("BUG_ON: " #cond);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|BUG
parameter_list|()
define|\
value|do {						\ 		panic("BUG: %s:%d", __FILE__, __LINE__);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|vchiq_static_assert
parameter_list|(
name|cond
parameter_list|)
value|CTASSERT(cond)
end_define

begin_define
define|#
directive|define
name|KERN_EMERG
value|"<0>"
end_define

begin_comment
comment|/* system is unusable			*/
end_comment

begin_define
define|#
directive|define
name|KERN_ALERT
value|"<1>"
end_define

begin_comment
comment|/* action must be taken immediately	*/
end_comment

begin_define
define|#
directive|define
name|KERN_CRIT
value|"<2>"
end_define

begin_comment
comment|/* critical conditions			*/
end_comment

begin_define
define|#
directive|define
name|KERN_ERR
value|"<3>"
end_define

begin_comment
comment|/* error conditions			*/
end_comment

begin_define
define|#
directive|define
name|KERN_WARNING
value|"<4>"
end_define

begin_comment
comment|/* warning conditions			*/
end_comment

begin_define
define|#
directive|define
name|KERN_NOTICE
value|"<5>"
end_define

begin_comment
comment|/* normal but significant condition	*/
end_comment

begin_define
define|#
directive|define
name|KERN_INFO
value|"<6>"
end_define

begin_comment
comment|/* informational			*/
end_comment

begin_define
define|#
directive|define
name|KERN_DEBUG
value|"<7>"
end_define

begin_comment
comment|/* debug-level messages			*/
end_comment

begin_define
define|#
directive|define
name|KERN_CONT
value|""
end_define

begin_define
define|#
directive|define
name|printk
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printf(fmt, ##args)
end_define

begin_define
define|#
directive|define
name|vprintk
parameter_list|(
name|fmt
parameter_list|,
name|args
parameter_list|)
value|vprintf(fmt, args)
end_define

begin_comment
comment|/*  * Malloc API  */
end_comment

begin_define
define|#
directive|define
name|GFP_KERNEL
value|0
end_define

begin_define
define|#
directive|define
name|GFP_ATOMIC
value|0
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_VCHI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|kmalloc
parameter_list|(
name|size
parameter_list|,
name|flags
parameter_list|)
value|malloc((size), M_VCHI, M_NOWAIT | M_ZERO)
end_define

begin_define
define|#
directive|define
name|kcalloc
parameter_list|(
name|n
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|)
value|malloc((n) * (size), M_VCHI, M_NOWAIT | M_ZERO)
end_define

begin_define
define|#
directive|define
name|kzalloc
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|kcalloc(1, (a), (b))
end_define

begin_define
define|#
directive|define
name|kfree
parameter_list|(
name|p
parameter_list|)
value|free(p, M_VCHI)
end_define

begin_comment
comment|/*  * Kernel module API  */
end_comment

begin_define
define|#
directive|define
name|__init
end_define

begin_define
define|#
directive|define
name|__exit
end_define

begin_define
define|#
directive|define
name|__devinit
end_define

begin_define
define|#
directive|define
name|__devexit
end_define

begin_define
define|#
directive|define
name|__devinitdata
end_define

begin_comment
comment|/*  * Time API  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* emulate jiffies */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|_jiffies
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|microuptime
argument_list|(
operator|&
name|tv
argument_list|)
expr_stmt|;
return|return
name|tvtohz
argument_list|(
operator|&
name|tv
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|msecs_to_jiffies
parameter_list|(
name|unsigned
name|long
name|msecs
parameter_list|)
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|tv
operator|.
name|tv_sec
operator|=
name|msecs
operator|/
literal|1000000UL
expr_stmt|;
name|tv
operator|.
name|tv_usec
operator|=
name|msecs
operator|%
literal|1000000UL
expr_stmt|;
return|return
name|tvtohz
argument_list|(
operator|&
name|tv
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|jiffies
value|_jiffies()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|jiffies
value|ticks
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HZ
value|hz
end_define

begin_define
define|#
directive|define
name|udelay
parameter_list|(
name|usec
parameter_list|)
value|DELAY(usec)
end_define

begin_define
define|#
directive|define
name|mdelay
parameter_list|(
name|msec
parameter_list|)
value|DELAY((msec) * 1000)
end_define

begin_define
define|#
directive|define
name|schedule_timeout
parameter_list|(
name|jiff
parameter_list|)
value|pause("dhdslp", jiff)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|msleep
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|msleep
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|msleep
parameter_list|(
name|msec
parameter_list|)
value|mdelay(msec)
end_define

begin_define
define|#
directive|define
name|time_after
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b))
end_define

begin_define
define|#
directive|define
name|time_after_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>= (b))
end_define

begin_define
define|#
directive|define
name|time_before
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|time_after((b), (a))
end_define

begin_comment
comment|/*  * kthread API (we use proc)  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|proc
modifier|*
name|VCHIQ_THREAD_T
typedef|;
end_typedef

begin_function_decl
name|VCHIQ_THREAD_T
name|vchiq_thread_create
parameter_list|(
name|int
function_decl|(
modifier|*
name|threadfn
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|char
name|namefmt
index|[]
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_user_nice
parameter_list|(
name|VCHIQ_THREAD_T
name|p
parameter_list|,
name|int
name|nice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wake_up_process
parameter_list|(
name|VCHIQ_THREAD_T
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Proc APIs  */
end_comment

begin_function_decl
name|void
name|flush_signals
parameter_list|(
name|VCHIQ_THREAD_T
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fatal_signal_pending
parameter_list|(
name|VCHIQ_THREAD_T
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * mbox API  */
end_comment

begin_function_decl
name|void
name|bcm_mbox_write
parameter_list|(
name|int
name|channel
parameter_list|,
name|uint32_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Misc API  */
end_comment

begin_define
define|#
directive|define
name|ENODATA
value|EINVAL
end_define

begin_define
define|#
directive|define
name|__user
end_define

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 1)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
end_define

begin_define
define|#
directive|define
name|current
value|curproc
end_define

begin_define
define|#
directive|define
name|EXPORT_SYMBOL
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|round_page(addr)
end_define

begin_typedef
typedef|typedef
name|void
name|irqreturn_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|off_t
name|loff_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BCM2835_MBOX_CHAN_VCHIQ
value|3
end_define

begin_define
define|#
directive|define
name|smp_mb
value|wmb
end_define

begin_define
define|#
directive|define
name|smp_rmb
value|rmb
end_define

begin_define
define|#
directive|define
name|smp_wmb
value|wmb
end_define

begin_define
define|#
directive|define
name|device_print_prettyname
parameter_list|(
name|dev
parameter_list|)
value|device_printf((dev), "")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __VCHI_BSD_H__ */
end_comment

end_unit

