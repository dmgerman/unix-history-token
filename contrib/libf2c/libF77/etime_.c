begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"time.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_undef
undef|#
directive|undef
name|USE_CLOCK
end_undef

begin_define
define|#
directive|define
name|USE_CLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_CLOCK
end_ifndef

begin_define
define|#
directive|define
name|_INCLUDE_POSIX_SOURCE
end_define

begin_comment
comment|/* for HP-UX */
end_comment

begin_define
define|#
directive|define
name|_INCLUDE_XOPEN_SOURCE
end_define

begin_comment
comment|/* for HP-UX */
end_comment

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_include
include|#
directive|include
file|"sys/times.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|Hz
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|CLK_TCK
end_ifdef

begin_define
define|#
directive|define
name|Hz
value|CLK_TCK
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HZ
end_ifdef

begin_define
define|#
directive|define
name|Hz
value|HZ
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Hz
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|double
ifdef|#
directive|ifdef
name|KR_headers
name|etime_
parameter_list|(
name|tarray
parameter_list|)
name|float
modifier|*
name|tarray
decl_stmt|;
else|#
directive|else
function|etime_
parameter_list|(
name|float
modifier|*
name|tarray
parameter_list|)
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|USE_CLOCK
ifndef|#
directive|ifndef
name|CLOCKS_PER_SECOND
define|#
directive|define
name|CLOCKS_PER_SECOND
value|Hz
endif|#
directive|endif
name|double
name|t
init|=
name|clock
argument_list|()
decl_stmt|;
name|tarray
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|tarray
index|[
literal|0
index|]
operator|=
name|t
operator|/
name|CLOCKS_PER_SECOND
return|;
else|#
directive|else
name|struct
name|tms
name|t
decl_stmt|;
name|times
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
return|return
operator|(
name|tarray
index|[
literal|0
index|]
operator|=
name|t
operator|.
name|tms_utime
operator|/
name|Hz
operator|)
operator|+
operator|(
name|tarray
index|[
literal|1
index|]
operator|=
name|t
operator|.
name|tms_stime
operator|/
name|Hz
operator|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

