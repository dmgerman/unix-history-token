begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	dup2 -- 7th Edition UNIX system call emulation for UNIX System V  	last edit:	11-Feb-1987	D A Gwyn */
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

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|close
argument_list|()
decl_stmt|,
name|fcntl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|dup2
parameter_list|(
name|oldfd
parameter_list|,
name|newfd
parameter_list|)
name|int
name|oldfd
decl_stmt|;
comment|/* already-open file descriptor */
name|int
name|newfd
decl_stmt|;
comment|/* desired duplicate descriptor */
block|{
specifier|register
name|int
name|ret
decl_stmt|;
comment|/* for fcntl() return value */
specifier|register
name|int
name|save
decl_stmt|;
comment|/* for saving entry errno */
if|if
condition|(
name|oldfd
operator|==
name|newfd
condition|)
return|return
name|oldfd
return|;
comment|/* be careful not to close() */
name|save
operator|=
name|errno
expr_stmt|;
comment|/* save entry errno */
operator|(
name|void
operator|)
name|close
argument_list|(
name|newfd
argument_list|)
expr_stmt|;
comment|/* in case newfd is open */
comment|/* (may have just clobbered the original errno value) */
name|ret
operator|=
name|fcntl
argument_list|(
name|oldfd
argument_list|,
name|F_DUPFD
argument_list|,
name|newfd
argument_list|)
expr_stmt|;
comment|/* dupe it */
if|if
condition|(
name|ret
operator|>=
literal|0
condition|)
name|errno
operator|=
name|save
expr_stmt|;
comment|/* restore entry errno */
elseif|else
comment|/* fcntl() returned error */
if|if
condition|(
name|errno
operator|==
name|EINVAL
condition|)
name|errno
operator|=
name|EBADF
expr_stmt|;
comment|/* we think of everything */
return|return
name|ret
return|;
comment|/* return file descriptor */
block|}
end_function

end_unit

