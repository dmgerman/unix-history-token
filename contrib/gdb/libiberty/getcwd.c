begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Emulate getcwd using getwd.    This function is in the public domain. */
end_comment

begin_comment
comment|/* NAME 	getcwd -- get absolute pathname for current working directory  SYNOPSIS 	char *getcwd (char pathname[len], len)  DESCRIPTION 	Copy the absolute pathname for the current working directory into 	the supplied buffer and return a pointer to the buffer.  If the  	current directory's path doesn't fit in LEN characters, the result 	is NULL and errno is set.  BUGS 	Emulated via the getwd() call, which is reasonable for most 	systems that do not have getcwd().  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_SYS_PARAM_H
end_ifndef

begin_include
include|#
directive|include
file|<sys/param.h>
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

begin_function_decl
specifier|extern
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|char
modifier|*
name|getcwd
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
name|char
name|ourbuf
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
modifier|*
name|result
decl_stmt|;
name|result
operator|=
name|getwd
argument_list|(
name|ourbuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
condition|)
block|{
if|if
condition|(
name|strlen
argument_list|(
name|ourbuf
argument_list|)
operator|>=
name|len
condition|)
block|{
name|errno
operator|=
name|ERANGE
expr_stmt|;
return|return
literal|0
return|;
block|}
name|strcpy
argument_list|(
name|buf
argument_list|,
name|ourbuf
argument_list|)
expr_stmt|;
block|}
return|return
name|buf
return|;
block|}
end_function

end_unit

