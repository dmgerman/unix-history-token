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
file|"ntp_unixtime.h"
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
name|ts
operator|->
name|l_ui
operator|=
name|tv
operator|.
name|tv_sec
operator|+
operator|(
name|u_long
operator|)
name|JAN_1970
expr_stmt|;
if|if
condition|(
name|tv
operator|.
name|tv_usec
operator|>
literal|999999
condition|)
return|return
literal|0
return|;
name|TVUTOTSF
argument_list|(
name|tv
operator|.
name|tv_usec
argument_list|,
name|ts
operator|->
name|l_uf
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_comment
comment|/*  * Windows doesn't have the tty_clock line discipline, so  * don't look for a timestamp where there is none.  */
end_comment

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
name|UNUSED_ARG
argument_list|(
name|bufp
argument_list|)
expr_stmt|;
name|UNUSED_ARG
argument_list|(
name|ts
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
comment|/* SYS_WINNT */
end_comment

end_unit

