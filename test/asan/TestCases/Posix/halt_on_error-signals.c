begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test interaction of Asan recovery mode with asynch signals.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_asan -fsanitize-recover=address -pthread %s -o %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: rm -f %t.log
end_comment

begin_comment
comment|// RUN: %env_asan_opts=halt_on_error=false:suppress_equal_pcs=false %run %t 100>>%t.log 2>&1 || true
end_comment

begin_comment
comment|// Collision will almost always get triggered but we still need to check the unlikely case:
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-COLLISION %s< %t.log || FileCheck --check-prefix=CHECK-NO-COLLISION %s< %t.log
end_comment

begin_define
define|#
directive|define
name|_SVID_SOURCE
value|1
end_define

begin_comment
comment|// SA_NODEFER
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sanitizer/asan_interface.h>
end_include

begin_function
name|void
name|random_delay
parameter_list|(
name|unsigned
modifier|*
name|seed
parameter_list|)
block|{
operator|*
name|seed
operator|=
literal|1664525
operator|*
operator|*
name|seed
operator|+
literal|1013904223
expr_stmt|;
name|struct
name|timespec
name|delay
init|=
block|{
literal|0
block|,
operator|(
operator|*
name|seed
operator|%
literal|1000
operator|)
operator|*
literal|1000
block|}
decl_stmt|;
name|nanosleep
argument_list|(
operator|&
name|delay
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|volatile
name|char
name|bad
index|[
literal|2
index|]
init|=
block|{
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|error
parameter_list|()
block|{
comment|// CHECK-COLLISION: AddressSanitizer: nested bug in the same thread, aborting
comment|// CHECK-NO-COLLISION: AddressSanitizer: use-after-poison
specifier|volatile
name|int
name|idx
init|=
literal|0
decl_stmt|;
name|bad
index|[
name|idx
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|CHECK_CALL
parameter_list|(
name|e
parameter_list|,
name|msg
parameter_list|)
value|do {             \   if (0 != (e)) {                           \     fprintf(stderr, "Failed to " msg "\n"); \     exit(1);                                \   }                                         \ } while (0)
end_define

begin_decl_stmt
name|size_t
name|niter
init|=
literal|10
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_t
name|sender_tid
decl_stmt|,
name|receiver_tid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_mutex_t
name|keep_alive_mu
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|sender
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|unsigned
name|seed
init|=
literal|0
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|niter
condition|;
operator|++
name|i
control|)
block|{
name|random_delay
argument_list|(
operator|&
name|seed
argument_list|)
expr_stmt|;
name|CHECK_CALL
argument_list|(
name|pthread_kill
argument_list|(
name|receiver_tid
argument_list|,
name|SIGUSR1
argument_list|)
argument_list|,
literal|"send signal"
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|handler
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
comment|// Expect error collisions here
name|error
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|receiver
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|unsigned
name|seed
init|=
literal|1
decl_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|niter
condition|;
operator|++
name|i
control|)
block|{
name|random_delay
argument_list|(
operator|&
name|seed
argument_list|)
expr_stmt|;
comment|// And here
name|error
argument_list|()
expr_stmt|;
block|}
comment|// Parent will release this when it's ok to terminate
name|CHECK_CALL
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|keep_alive_mu
argument_list|)
argument_list|,
literal|"unlock mutex"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Syntax: %s niter\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|niter
operator|=
operator|(
name|size_t
operator|)
name|strtoul
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|struct
name|sigaction
name|sa
decl_stmt|;
name|memset
argument_list|(
operator|&
name|sa
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|sa
argument_list|)
argument_list|)
expr_stmt|;
name|sa
operator|.
name|sa_handler
operator|=
name|handler
expr_stmt|;
name|sa
operator|.
name|sa_flags
operator|=
name|SA_NODEFER
expr_stmt|;
comment|// Enable nested handlers to add more stress
name|CHECK_CALL
argument_list|(
name|sigaction
argument_list|(
name|SIGUSR1
argument_list|,
operator|&
name|sa
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"set sighandler"
argument_list|)
expr_stmt|;
name|__asan_poison_memory_region
argument_list|(
operator|&
name|bad
argument_list|,
sizeof|sizeof
argument_list|(
name|bad
argument_list|)
argument_list|)
expr_stmt|;
name|CHECK_CALL
argument_list|(
name|pthread_mutex_lock
argument_list|(
operator|&
name|keep_alive_mu
argument_list|)
argument_list|,
literal|"lock mutex"
argument_list|)
expr_stmt|;
name|CHECK_CALL
argument_list|(
name|pthread_create
argument_list|(
operator|&
name|receiver_tid
argument_list|,
literal|0
argument_list|,
name|receiver
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"start thread"
argument_list|)
expr_stmt|;
name|CHECK_CALL
argument_list|(
name|pthread_create
argument_list|(
operator|&
name|sender_tid
argument_list|,
literal|0
argument_list|,
name|sender
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"start thread"
argument_list|)
expr_stmt|;
name|CHECK_CALL
argument_list|(
name|pthread_join
argument_list|(
name|sender_tid
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"join thread"
argument_list|)
expr_stmt|;
comment|// Now allow receiver to die
name|CHECK_CALL
argument_list|(
name|pthread_mutex_unlock
argument_list|(
operator|&
name|keep_alive_mu
argument_list|)
argument_list|,
literal|"unlock mutex"
argument_list|)
expr_stmt|;
name|CHECK_CALL
argument_list|(
name|pthread_join
argument_list|(
name|receiver_tid
argument_list|,
literal|0
argument_list|)
argument_list|,
literal|"join thread"
argument_list|)
expr_stmt|;
comment|// CHECK-NO-COLLISION: All threads terminated
name|printf
argument_list|(
literal|"All threads terminated\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

