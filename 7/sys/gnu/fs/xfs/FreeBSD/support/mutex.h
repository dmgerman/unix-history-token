begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_MUTEX_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_MUTEX_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
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

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_comment
comment|/*  * Map the mutex'es from IRIX to FreeBSD. Irix holds mutexes across  * sleeps, so on FreeBSD we have a choice of sema, sx or lockmgr  * to use as a underlining implemenation. Go with sx always locked  * in exclusive mode for now as it gets all the benefits of witness  * checking.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|sx
name|mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mutex_init
parameter_list|(
name|lock
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|)
value|sx_init(lock, name)
end_define

begin_define
define|#
directive|define
name|mutex_lock
parameter_list|(
name|lock
parameter_list|,
name|num
parameter_list|)
value|sx_xlock(lock)
end_define

begin_define
define|#
directive|define
name|mutex_trylock
parameter_list|(
name|lock
parameter_list|)
value|sx_try_xlock(lock)
end_define

begin_define
define|#
directive|define
name|mutex_unlock
parameter_list|(
name|lock
parameter_list|)
value|sx_xunlock(lock)
end_define

begin_define
define|#
directive|define
name|mutex_destroy
parameter_list|(
name|lock
parameter_list|)
value|sx_destroy(lock)
end_define

begin_comment
comment|/*  * Type for mutex_init()  */
end_comment

begin_define
define|#
directive|define
name|MUTEX_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_MUTEX_H__ */
end_comment

end_unit

