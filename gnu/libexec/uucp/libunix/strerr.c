begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strerr.c    Return a string for a Unix errno value.  */
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|sys_nerr
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|sys_errlist
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|strerror
end_undef

begin_function
name|char
modifier|*
name|strerror
parameter_list|(
name|ierr
parameter_list|)
name|int
name|ierr
decl_stmt|;
block|{
if|if
condition|(
name|ierr
operator|>=
literal|0
operator|&&
name|ierr
operator|<
name|sys_nerr
condition|)
return|return
name|sys_errlist
index|[
name|ierr
index|]
return|;
return|return
operator|(
name|char
operator|*
operator|)
literal|"unknown error"
return|;
block|}
end_function

end_unit

