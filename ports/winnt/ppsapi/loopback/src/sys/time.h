begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This sys/time.h is part of ppsapi-prov skeleton sample source code  * for a Windows PPSAPI provider DLL.  It was adapted from  * ports/winnt/include/sys/time.h in ntpd.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_TIME_H
end_ifndef

begin_define
define|#
directive|define
name|SYS_TIME_H
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|timespec
block|{
name|time_t
name|tv_sec
decl_stmt|;
name|long
name|tv_nsec
decl_stmt|;
block|}
name|timespec_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_TIME_H */
end_comment

end_unit

