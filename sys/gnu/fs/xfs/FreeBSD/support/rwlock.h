begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_RWLOCK_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_RWLOCK_H__
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

begin_typedef
typedef|typedef
name|struct
name|sx
name|rwlock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|wait_queue_head_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|rwlock_init
parameter_list|(
name|lock
parameter_list|)
value|sx_init(lock, "rwlock")
end_define

begin_define
define|#
directive|define
name|rwlock_destroy
parameter_list|(
name|lock
parameter_list|)
value|sx_destroy(lock)
end_define

begin_define
define|#
directive|define
name|read_lock
parameter_list|(
name|lock
parameter_list|)
value|sx_slock(lock)
end_define

begin_define
define|#
directive|define
name|read_unlock
parameter_list|(
name|lock
parameter_list|)
value|sx_sunlock(lock)
end_define

begin_define
define|#
directive|define
name|write_lock
parameter_list|(
name|lock
parameter_list|)
value|sx_xlock(lock)
end_define

begin_define
define|#
directive|define
name|write_trylock
parameter_list|(
name|lock
parameter_list|)
value|sx_try_xlock(lock)
end_define

begin_define
define|#
directive|define
name|write_unlock
parameter_list|(
name|lock
parameter_list|)
value|sx_xunlock(lock)
end_define

begin_define
define|#
directive|define
name|rwlock_trypromote
parameter_list|(
name|lock
parameter_list|)
value|sx_try_upgrade(lock)
end_define

begin_define
define|#
directive|define
name|rwlock_demote
parameter_list|(
name|lock
parameter_list|)
value|sx_downgrade(lock)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_RWLOCK_H__ */
end_comment

end_unit

