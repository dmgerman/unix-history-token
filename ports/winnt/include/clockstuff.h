begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_CLOCKSTUFF_H
end_ifndef

begin_define
define|#
directive|define
name|_CLOCKSTUFF_H
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<sys\timeb.h>
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_function_decl
name|void
name|init_winnt_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset_winnt_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lock_thread_to_processor
parameter_list|(
name|HANDLE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 100ns intervals between 1/1/1601 and 1/1/1970 as reported by  * SystemTimeToFileTime()  */
end_comment

begin_define
define|#
directive|define
name|FILETIME_1970
value|0x019db1ded53e8000
end_define

begin_define
define|#
directive|define
name|HECTONANOSECONDS
value|10000000
end_define

begin_comment
comment|/*  * Multimedia Timer  */
end_comment

begin_function_decl
name|void
name|set_mm_timer
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|MM_TIMER_LORES
block|,
name|MM_TIMER_HIRES
block|}
enum|;
end_enum

begin_comment
comment|/*  * get_sys_time_as_filetime is a function pointer to  * either GetSystemTimeAsFileTime provided by Windows  * or ntpd's interpolating replacement.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|WINAPI
modifier|*
name|PGSTAFT
function_decl|)
parameter_list|(
name|LPFILETIME
name|pftResult
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|PGSTAFT
name|get_sys_time_as_filetime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PGSTAFT
name|pGetSystemTimePreciseAsFileTime
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|lock_thread_to_processor
parameter_list|(
name|HANDLE
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

