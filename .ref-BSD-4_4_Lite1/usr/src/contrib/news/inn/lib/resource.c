begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.3 $ ** */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_include
include|#
directive|include
file|"macros.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RES_RUSAGE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_define
define|#
directive|define
name|TIMEVALasDOUBLE
parameter_list|(
name|t
parameter_list|)
define|\
value|((double)(t).tv_sec + ((double)(t).tv_usec) / 1000000.0)
end_define

begin_function
name|int
name|GetResourceUsage
parameter_list|(
name|usertime
parameter_list|,
name|systime
parameter_list|)
name|double
modifier|*
name|usertime
decl_stmt|;
name|double
modifier|*
name|systime
decl_stmt|;
block|{
name|struct
name|rusage
name|R
decl_stmt|;
if|if
condition|(
name|getrusage
argument_list|(
name|RUSAGE_SELF
argument_list|,
operator|&
name|R
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
operator|*
name|usertime
operator|=
name|TIMEVALasDOUBLE
argument_list|(
name|R
operator|.
name|ru_utime
argument_list|)
expr_stmt|;
operator|*
name|systime
operator|=
name|TIMEVALasDOUBLE
argument_list|(
name|R
operator|.
name|ru_stime
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(RES_RUSAGE) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|RES_TIMES
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HZ
argument_list|)
end_if

begin_define
define|#
directive|define
name|HZ
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HZ) */
end_comment

begin_define
define|#
directive|define
name|CPUTIMEasDOUBLE
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|)
value|((double)(t1 + t2) / (double)HZ)
end_define

begin_function
name|int
name|GetResourceUsage
parameter_list|(
name|usertime
parameter_list|,
name|systime
parameter_list|)
name|double
modifier|*
name|usertime
decl_stmt|;
name|double
modifier|*
name|systime
decl_stmt|;
block|{
name|struct
name|tms
name|T
decl_stmt|;
if|if
condition|(
name|times
argument_list|(
operator|&
name|T
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
operator|*
name|usertime
operator|=
name|CPUTIMEasDOUBLE
argument_list|(
name|T
operator|.
name|tms_utime
argument_list|,
name|T
operator|.
name|tms_cutime
argument_list|)
expr_stmt|;
operator|*
name|systime
operator|=
name|CPUTIMEasDOUBLE
argument_list|(
name|T
operator|.
name|tms_stime
argument_list|,
name|T
operator|.
name|tms_cstime
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(RES_TIMES) */
end_comment

end_unit

