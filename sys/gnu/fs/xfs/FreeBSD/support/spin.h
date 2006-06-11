begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_SPIN_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_SPIN_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_define
define|#
directive|define
name|SPLDECL
parameter_list|(
name|s
parameter_list|)
value|register_t s
end_define

begin_comment
comment|/*  * Map the spinlocks from IRIX to FreeBSD  */
end_comment

begin_define
define|#
directive|define
name|spinlock_init
parameter_list|(
name|lock
parameter_list|,
name|name
parameter_list|)
value|mtx_init(lock, name, NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|spinlock_destroy
parameter_list|(
name|lock
parameter_list|)
value|mtx_destroy(lock)
end_define

begin_comment
comment|/*  * Map lock_t from IRIX to FreeBSD mutexes  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mtx
name|lock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nested_spinunlock
parameter_list|(
name|lock
parameter_list|)
value|mtx_unlock(lock)
end_define

begin_define
define|#
directive|define
name|nested_spinlock
parameter_list|(
name|lock
parameter_list|)
value|mtx_lock(lock)
end_define

begin_define
define|#
directive|define
name|nested_spintrylock
parameter_list|(
name|lock
parameter_list|)
value|mtx_trylock(lock)
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
name|mutex_spinlock
parameter_list|(
name|lock
parameter_list|)
value|(spin_lock(lock),0)
end_define

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|register_t
name|mutex_spinlock
parameter_list|(
name|lock_t
modifier|*
name|lock
parameter_list|)
block|{
name|mtx_lock
argument_list|(
name|lock
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mutex_spinunlock
parameter_list|(
name|lock
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 		spin_unlock(lock); \ 		if (&s) {} \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_SPIN_H__ */
end_comment

end_unit

