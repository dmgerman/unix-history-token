begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.6 $ ** */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FDCOUNT_GETDTAB
argument_list|)
end_if

begin_function
name|int
name|getfdcount
parameter_list|()
block|{
specifier|static
name|int
name|size
decl_stmt|;
if|if
condition|(
name|size
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|size
operator|=
name|getdtablesize
argument_list|()
operator|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
block|}
return|return
name|size
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(FDCOUNT_GETDTAB) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FDCOUNT_GETRLIMIT
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

begin_function
name|int
name|getfdcount
parameter_list|()
block|{
specifier|static
name|int
name|size
decl_stmt|;
name|struct
name|rlimit
name|rl
decl_stmt|;
if|if
condition|(
name|size
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
name|getrlimit
argument_list|(
name|RLIMIT_NOFILE
argument_list|,
operator|&
name|rl
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|size
operator|=
name|rl
operator|.
name|rlim_cur
expr_stmt|;
block|}
return|return
name|size
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(FDCOUNT_GETRLIMIT) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FDCOUNT_SYSCONF
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_function
name|int
name|getfdcount
parameter_list|()
block|{
specifier|static
name|int
name|size
decl_stmt|;
if|if
condition|(
name|size
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|size
operator|=
name|sysconf
argument_list|(
name|_SC_OPEN_MAX
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
block|}
return|return
name|size
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(FDCOUNT_SYSCONF) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FDCOUNT_ULIMIT
argument_list|)
end_if

begin_function
name|int
name|getfdcount
parameter_list|()
block|{
specifier|static
name|int
name|size
decl_stmt|;
if|if
condition|(
name|size
operator|<=
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|size
operator|=
name|ulimit
argument_list|(
literal|4
argument_list|,
literal|0L
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
block|}
return|return
name|size
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(FDCOUNT_ULIMIT) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FDCOUNT_CONSTANT
argument_list|)
end_if

begin_function
name|int
name|getfdcount
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|NOFILE
argument_list|)
return|return
name|NOFILE
return|;
else|#
directive|else
return|return
literal|20
return|;
endif|#
directive|endif
comment|/* defined(NOFILE) */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(FDCOUNT_CONSTANT) */
end_comment

end_unit

