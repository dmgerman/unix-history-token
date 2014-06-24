begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"file.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_macro
name|FILE_RCSID
argument_list|(
literal|"@(#)$File: pread.c,v 1.2 2013/04/02 16:23:07 christos Exp $"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|ssize_t
name|pread
parameter_list|(
name|int
name|fd
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|off_t
name|off
parameter_list|)
block|{
if|if
condition|(
name|lseek
argument_list|(
name|fd
argument_list|,
name|off
argument_list|,
name|SEEK_SET
argument_list|)
operator|==
operator|(
name|off_t
operator|)
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

end_unit

