begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_UTIME_H
end_ifndef

begin_define
define|#
directive|define
name|_UTIME_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_TIME_H
end_ifndef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|utimbuf
block|{
name|time_t
name|actime
decl_stmt|;
name|time_t
name|modtime
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|utime
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|utimbuf
modifier|*
name|times
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

