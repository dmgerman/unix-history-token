begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_MRLOCK_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_MRLOCK_H__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
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

begin_include
include|#
directive|include
file|<support/debug.h>
end_include

begin_comment
comment|/*  * Implement mrlocks on FreeBSD that work for XFS.  * Use FreeBSD sx lock and add necessary functions  * if additional functionality is requested  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|sx
name|mrlock_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MR_ACCESS
value|1
end_define

begin_define
define|#
directive|define
name|MR_UPDATE
value|2
end_define

begin_comment
comment|/*   * Compatibility defines, not really used  */
end_comment

begin_define
define|#
directive|define
name|MRLOCK_BARRIER
value|0x1
end_define

begin_define
define|#
directive|define
name|MRLOCK_ALLOW_EQUAL_PRI
value|0x8
end_define

begin_comment
comment|/*  * mraccessf/mrupdatef take flags to be passed in while sleeping;  * only PLTWAIT is currently supported.  */
end_comment

begin_define
define|#
directive|define
name|mrinit
parameter_list|(
name|lock
parameter_list|,
name|name
parameter_list|)
value|sx_init(lock, name)
end_define

begin_define
define|#
directive|define
name|mrlock_init
parameter_list|(
name|lock
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|seq
parameter_list|)
value|sx_init(lock, name)
end_define

begin_define
define|#
directive|define
name|mrfree
parameter_list|(
name|lock
parameter_list|)
value|_sx_xfs_destroy(lock)
end_define

begin_define
define|#
directive|define
name|mraccessf
parameter_list|(
name|lock
parameter_list|,
name|f
parameter_list|)
value|sx_slock(lock)
end_define

begin_define
define|#
directive|define
name|mrupdatef
parameter_list|(
name|lock
parameter_list|,
name|f
parameter_list|)
value|sx_xlock(lock)
end_define

begin_define
define|#
directive|define
name|mraccunlock
parameter_list|(
name|lock
parameter_list|)
value|sx_sunlock(lock)
end_define

begin_define
define|#
directive|define
name|mrtryaccess
parameter_list|(
name|lock
parameter_list|)
value|sx_try_slock(lock)
end_define

begin_define
define|#
directive|define
name|mrtryupdate
parameter_list|(
name|lock
parameter_list|)
value|sx_try_xlock(lock)
end_define

begin_define
define|#
directive|define
name|mraccess
parameter_list|(
name|mrp
parameter_list|)
value|mraccessf(mrp, 0)
end_define

begin_define
define|#
directive|define
name|mrupdate
parameter_list|(
name|mrp
parameter_list|)
value|mrupdatef(mrp, 0)
end_define

begin_define
define|#
directive|define
name|mrislocked_access
parameter_list|(
name|lock
parameter_list|)
value|_sx_xfs_xowned(lock)
end_define

begin_define
define|#
directive|define
name|mrislocked_update
parameter_list|(
name|lock
parameter_list|)
value|_sx_xfs_sowned(lock)
end_define

begin_define
define|#
directive|define
name|mrtrypromote
parameter_list|(
name|lock
parameter_list|)
value|sx_try_upgrade(lock)
end_define

begin_define
define|#
directive|define
name|mrdemote
parameter_list|(
name|lock
parameter_list|)
value|sx_downgrade(lock)
end_define

begin_function_decl
name|int
name|ismrlocked
parameter_list|(
name|mrlock_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_sx_xfs_lock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
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
name|_sx_xfs_unlock
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
parameter_list|,
specifier|const
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
name|_sx_xfs_destroy
parameter_list|(
name|struct
name|sx
modifier|*
name|sx
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_sx_xfs_xowned
parameter_list|(
name|lock
parameter_list|)
value|((lock)->sx_cnt< 0)
end_define

begin_define
define|#
directive|define
name|_sx_xfs_sowned
parameter_list|(
name|lock
parameter_list|)
value|((lock)->sx_cnt> 0)
end_define

begin_comment
comment|/*  * Functions, not implemented in FreeBSD   */
end_comment

begin_define
define|#
directive|define
name|mrunlock
parameter_list|(
name|lock
parameter_list|)
define|\
value|_sx_xfs_unlock(lock, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|mrlock
parameter_list|(
name|lock
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
define|\
value|_sx_xfs_lock(lock, type, __FILE__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_MRLOCK_H__ */
end_comment

end_unit

