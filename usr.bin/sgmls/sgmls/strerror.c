begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strerror.c -    ANSI C strerror() function.        Written by James Clark (jjc@jclark.com). */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|STRERROR_MISSING
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|n
parameter_list|)
name|int
name|n
decl_stmt|;
block|{
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
specifier|static
name|char
name|buf
index|[
sizeof|sizeof
argument_list|(
literal|"Error "
argument_list|)
operator|+
literal|1
operator|+
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
if|if
condition|(
name|n
operator|>=
literal|0
operator|&&
name|n
operator|<
name|sys_nerr
operator|&&
name|sys_errlist
index|[
name|n
index|]
operator|!=
literal|0
condition|)
return|return
name|sys_errlist
index|[
name|n
index|]
return|;
else|else
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"Error %d"
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STRERROR_MISSING */
end_comment

begin_comment
comment|/* Local Variables: c-indent-level: 5 c-continued-statement-offset: 5 c-brace-offset: -5 c-argdecl-indent: 0 c-label-offset: -5 End: */
end_comment

end_unit

