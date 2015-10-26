begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_calendar.h"
end_include

begin_function_decl
name|time_t
name|timefunc
parameter_list|(
name|time_t
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|settime
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|d
parameter_list|,
name|int
name|H
parameter_list|,
name|int
name|M
parameter_list|,
name|int
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|time_t
name|nowtime
decl_stmt|;
end_decl_stmt

end_unit

