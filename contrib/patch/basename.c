begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* basename.c -- return the last element in a path */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<backupfile.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FILESYSTEM_PREFIX_LEN
end_ifndef

begin_define
define|#
directive|define
name|FILESYSTEM_PREFIX_LEN
parameter_list|(
name|f
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ISSLASH
end_ifndef

begin_define
define|#
directive|define
name|ISSLASH
parameter_list|(
name|c
parameter_list|)
value|((c) == '/')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* In general, we can't use the builtin `basename' function if available,    since it has different meanings in different environments.    In some environments the builtin `basename' modifies its argument.  */
end_comment

begin_function
name|char
modifier|*
name|base_name
parameter_list|(
name|name
parameter_list|)
name|char
specifier|const
modifier|*
name|name
decl_stmt|;
block|{
name|char
specifier|const
modifier|*
name|base
init|=
name|name
operator|+=
name|FILESYSTEM_PREFIX_LEN
argument_list|(
name|name
argument_list|)
decl_stmt|;
for|for
control|(
init|;
operator|*
name|name
condition|;
name|name
operator|++
control|)
if|if
condition|(
name|ISSLASH
argument_list|(
operator|*
name|name
argument_list|)
condition|)
name|base
operator|=
name|name
operator|+
literal|1
expr_stmt|;
return|return
operator|(
name|char
operator|*
operator|)
name|base
return|;
block|}
end_function

end_unit

