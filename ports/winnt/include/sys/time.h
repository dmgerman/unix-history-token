begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ports/winnt/include/sys/time.h  *  * routines declared in Unix systems' sys/time.h  */
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
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys/timeb.h>
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

begin_define
define|#
directive|define
name|TIMEOFDAY
value|0
end_define

begin_comment
comment|/* getclock() clktyp arg */
end_comment

begin_function_decl
specifier|extern
name|int
name|getclock
parameter_list|(
name|int
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|settimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_win_precise_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_TIME_H */
end_comment

end_unit

