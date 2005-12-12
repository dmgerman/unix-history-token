begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_RWSEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_RWSEM_H__
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

begin_define
define|#
directive|define
name|rw_semaphore
value|sx
end_define

begin_define
define|#
directive|define
name|init_rwsem
parameter_list|(
name|sem
parameter_list|)
value|sx_init(sem, "rwsem")
end_define

begin_define
define|#
directive|define
name|free_rwsem
parameter_list|(
name|sem
parameter_list|)
value|sx_destroy(sem)
end_define

begin_define
define|#
directive|define
name|down_read
parameter_list|(
name|sem
parameter_list|)
value|sx_slock(sem)
end_define

begin_define
define|#
directive|define
name|down_read_trylock
parameter_list|(
name|sem
parameter_list|)
value|sx_try_slock(sem)
end_define

begin_define
define|#
directive|define
name|down_write
parameter_list|(
name|sem
parameter_list|)
value|sx_xlock(sem)
end_define

begin_define
define|#
directive|define
name|down_write_trylock
parameter_list|(
name|sem
parameter_list|)
value|sx_try_xlock(sem)
end_define

begin_define
define|#
directive|define
name|up_read
parameter_list|(
name|sem
parameter_list|)
value|sx_sunlock(sem)
end_define

begin_define
define|#
directive|define
name|up_write
parameter_list|(
name|sem
parameter_list|)
value|sx_xunlock(sem)
end_define

begin_define
define|#
directive|define
name|downgrade_write
parameter_list|(
name|sem
parameter_list|)
value|sx_downgrade(sem)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_RWSEM_H__ */
end_comment

end_unit

