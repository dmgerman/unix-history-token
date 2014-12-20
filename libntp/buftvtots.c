begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * buftvtots - pull a Unix-format (struct timeval) time stamp out of  *	       an octet stream and convert it to a l_fp time stamp.  *	       This is useful when using the clock line discipline.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_string.h"
end_include

begin_include
include|#
directive|include
file|"timevalops.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_WINNT
end_ifndef

begin_function
name|int
name|buftvtots
parameter_list|(
specifier|const
name|char
modifier|*
name|bufp
parameter_list|,
name|l_fp
modifier|*
name|ts
parameter_list|)
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
comment|/* 	 * copy to adhere to alignment restrictions 	 */
name|memcpy
argument_list|(
operator|&
name|tv
argument_list|,
name|bufp
argument_list|,
sizeof|sizeof
argument_list|(
name|tv
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * and use it 	 */
if|if
condition|(
name|tv
operator|.
name|tv_usec
operator|>
name|MICROSECONDS
operator|-
literal|1
condition|)
return|return
name|FALSE
return|;
operator|*
name|ts
operator|=
name|tval_stamp_to_lfp
argument_list|(
name|tv
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SYS_WINNT */
end_comment

end_unit

