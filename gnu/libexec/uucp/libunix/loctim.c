begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* loctim.c    Turn a time epoch into a struct tm.  This is trivial on Unix.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_if
if|#
directive|if
name|TM_IN_SYS_TIME
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|localtime
end_ifndef

begin_function_decl
specifier|extern
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|usysdep_localtime
parameter_list|(
name|itime
parameter_list|,
name|q
parameter_list|)
name|long
name|itime
decl_stmt|;
name|struct
name|tm
modifier|*
name|q
decl_stmt|;
block|{
name|time_t
name|i
decl_stmt|;
name|i
operator|=
operator|(
name|time_t
operator|)
name|itime
expr_stmt|;
operator|*
name|q
operator|=
operator|*
name|localtime
argument_list|(
operator|&
name|i
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

