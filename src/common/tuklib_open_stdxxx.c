begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_open_stdxxx.c
end_comment

begin_comment
comment|/// \brief      Make sure that file descriptors 0, 1, and 2 are open
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"tuklib_open_stdxxx.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_DOSLIKE
end_ifndef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

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

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|extern
name|void
name|tuklib_open_stdxxx
parameter_list|(
name|int
name|err_status
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|TUKLIB_DOSLIKE
comment|// Do nothing, just silence warnings.
operator|(
name|void
operator|)
name|err_status
expr_stmt|;
else|#
directive|else
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<=
literal|2
condition|;
operator|++
name|i
control|)
block|{
comment|// We use fcntl() to check if the file descriptor is open.
if|if
condition|(
name|fcntl
argument_list|(
name|i
argument_list|,
name|F_GETFD
argument_list|)
operator|==
operator|-
literal|1
operator|&&
name|errno
operator|==
name|EBADF
condition|)
block|{
comment|// With stdin, we could use /dev/full so that
comment|// writing to stdin would fail. However, /dev/full
comment|// is Linux specific, and if the program tries to
comment|// write to stdin, there's already a problem anyway.
specifier|const
name|int
name|fd
init|=
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
name|O_NOCTTY
operator||
operator|(
name|i
operator|==
literal|0
condition|?
name|O_WRONLY
else|:
name|O_RDONLY
operator|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|!=
name|i
condition|)
block|{
if|if
condition|(
name|fd
operator|!=
operator|-
literal|1
condition|)
operator|(
name|void
operator|)
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
comment|// Something went wrong. Exit with the
comment|// exit status we were given. Don't try
comment|// to print an error message, since stderr
comment|// may very well be non-existent. This
comment|// error should be extremely rare.
name|exit
argument_list|(
name|err_status
argument_list|)
expr_stmt|;
block|}
block|}
block|}
endif|#
directive|endif
return|return;
block|}
end_function

end_unit

