begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * If we're doing flock(2) emulation, we need to get the LOCK_* #defines.  * This stub<sys/file.h> includes the real one, and, if they're not in  * it, we #define them here.  */
end_comment

begin_include
include|#
directive|include
file|</usr/include/sys/file.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_SH
end_ifndef

begin_comment
comment|/* lock operations for flock(2) */
end_comment

begin_define
define|#
directive|define
name|LOCK_SH
value|0x01
end_define

begin_comment
comment|/* shared file lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_EX
value|0x02
end_define

begin_comment
comment|/* exclusive file lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_NB
value|0x04
end_define

begin_comment
comment|/* don't block when locking */
end_comment

begin_define
define|#
directive|define
name|LOCK_UN
value|0x08
end_define

begin_comment
comment|/* unlock file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

