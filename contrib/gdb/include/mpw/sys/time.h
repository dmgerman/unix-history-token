begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Imitation sys/time.h. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SYS_TIME_H__
end_ifndef

begin_define
define|#
directive|define
name|__SYS_TIME_H__
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_struct
struct|struct
name|timeval
block|{
name|long
name|tv_sec
decl_stmt|;
name|long
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SYS_TIME_H__ */
end_comment

end_unit

