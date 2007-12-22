begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPPORT_SV_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPPORT_SV_H__
end_define

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_comment
comment|/*   * Synchronisation variables   *  * parameters "pri", "svf" and "rts" are not (yet?) implemented  *  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cv
name|sv_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|init_sv
parameter_list|(
name|sv
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|flag
parameter_list|)
value|cv_init(sv, name)
end_define

begin_define
define|#
directive|define
name|sv_init
parameter_list|(
name|sv
parameter_list|,
name|flag
parameter_list|,
name|name
parameter_list|)
value|cv_init(sv, name)
end_define

begin_comment
comment|/* sv_wait should exit with lock unlocked */
end_comment

begin_define
define|#
directive|define
name|sv_wait
parameter_list|(
name|sv
parameter_list|,
name|pri
parameter_list|,
name|lock
parameter_list|,
name|spl
parameter_list|)
value|cv_wait_unlock(sv, lock)
end_define

begin_define
define|#
directive|define
name|sv_wait_sig
parameter_list|(
name|sv
parameter_list|,
name|pri
parameter_list|,
name|lock
parameter_list|,
name|spl
parameter_list|)
value|cv_wait_sig_nolock(sv, lock)
end_define

begin_define
define|#
directive|define
name|sv_signal
parameter_list|(
name|sv
parameter_list|)
value|cv_signal(sv)
end_define

begin_define
define|#
directive|define
name|sv_broadcast
parameter_list|(
name|sv
parameter_list|)
value|cv_broadcast(sv)
end_define

begin_define
define|#
directive|define
name|sv_destroy
parameter_list|(
name|sv
parameter_list|)
value|cv_destroy(sv)
end_define

begin_define
define|#
directive|define
name|SV_FIFO
value|0x0
end_define

begin_comment
comment|/* sv_t is FIFO type */
end_comment

begin_define
define|#
directive|define
name|SV_LIFO
value|0x2
end_define

begin_comment
comment|/* sv_t is LIFO type */
end_comment

begin_define
define|#
directive|define
name|SV_PRIO
value|0x4
end_define

begin_comment
comment|/* sv_t is PRIO type */
end_comment

begin_define
define|#
directive|define
name|SV_KEYED
value|0x6
end_define

begin_comment
comment|/* sv_t is KEYED type */
end_comment

begin_define
define|#
directive|define
name|SV_DEFAULT
value|SV_FIFO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPPORT_SV_H__ */
end_comment

end_unit

