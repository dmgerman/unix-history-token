begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * Include<sys/file.h>, not<fcntl.h>, the flock(2)  * #defines were found there on historical systems.  */
end_comment

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<compat.h>
end_include

begin_comment
comment|/*  * Use lockf(2) locking to fake flock(2) locking.  */
end_comment

begin_function
name|int
name|flock
parameter_list|(
name|fd
parameter_list|,
name|operation
parameter_list|)
name|int
name|fd
decl_stmt|,
name|operation
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|lockf
argument_list|(
name|fd
argument_list|,
name|operation
operator|&
name|LOCK_UN
condition|?
name|F_ULOCK
else|:
name|operation
operator|&
name|LOCK_NB
condition|?
name|F_TLOCK
else|:
name|F_LOCK
argument_list|,
literal|0
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|errno
operator|==
name|EACCES
operator|||
name|errno
operator|==
name|EAGAIN
condition|)
name|errno
operator|=
name|EWOULDBLOCK
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

