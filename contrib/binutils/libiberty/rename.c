begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rename -- rename a file    This function is in the public domain. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental int rename (const char *@var{old}, const char *@var{new})  Renames a file from @var{old} to @var{new}.  If @var{new} already exists, it is removed.  @end deftypefn  */
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
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|rename
parameter_list|(
name|zfrom
parameter_list|,
name|zto
parameter_list|)
name|char
modifier|*
name|zfrom
decl_stmt|;
name|char
modifier|*
name|zto
decl_stmt|;
block|{
if|if
condition|(
name|link
argument_list|(
name|zfrom
argument_list|,
name|zto
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EEXIST
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|unlink
argument_list|(
name|zto
argument_list|)
operator|<
literal|0
operator|||
name|link
argument_list|(
name|zfrom
argument_list|,
name|zto
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
block|}
return|return
name|unlink
argument_list|(
name|zfrom
argument_list|)
return|;
block|}
end_function

end_unit

