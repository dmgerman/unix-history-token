begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Version of sigsetmask.c    Written by Steve Chamberlain (sac@cygnus.com).    Contributed by Cygnus Support.    This file is in the public doamin. */
end_comment

begin_comment
comment|/* Set the current signal mask to the set provided, and return the     previous value */
end_comment

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_comment
comment|/* Including<sys/types.h> seems to be needed by ISC. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SIG_SETMASK
end_ifdef

begin_decl_stmt
name|int
name|DEFUN
argument_list|(
name|sigsetmask
argument_list|,
operator|(
name|set
operator|)
argument_list|,
name|int
name|set
argument_list|)
block|{
name|sigset_t
name|new
decl_stmt|;
name|sigset_t
name|old
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|new
argument_list|)
expr_stmt|;
if|if
condition|(
name|set
operator|!=
literal|0
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
comment|/* FIXME, we don't know how to translate old mask to new */
block|}
name|sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|new
argument_list|,
operator|&
name|old
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
comment|/* FIXME, we always return 1 as old value.  */
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

