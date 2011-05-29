begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Version of sigsetmask.c    Written by Steve Chamberlain (sac@cygnus.com).    Contributed by Cygnus Support.    This file is in the public doamin. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental int sigsetmask (int @var{set})  Sets the signal mask to the one provided in @var{set} and returns the old mask (which, for libiberty's implementation, will always be the value @code{1}).  @end deftypefn  */
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

begin_decl_stmt
specifier|extern
name|void
name|abort
argument_list|(
name|void
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SIG_SETMASK
end_ifdef

begin_function
name|int
name|sigsetmask
parameter_list|(
name|int
name|set
parameter_list|)
block|{
name|sigset_t
name|new_sig
decl_stmt|;
name|sigset_t
name|old_sig
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|new_sig
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
name|new_sig
argument_list|,
operator|&
name|old_sig
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
comment|/* FIXME, we always return 1 as old value.  */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

