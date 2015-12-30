begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t&& %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK-NOT: WARNING
end_comment

begin_comment
comment|// CHECK: OK
end_comment

begin_comment
comment|// This test is failing on powerpc64 (VMA=44). After calling pthread_cancel,
end_comment

begin_comment
comment|// the Thread-specific data destructors are not called, so the destructor
end_comment

begin_comment
comment|// "thread_finalize" (defined in tsan_interceptors.cc) can not set the status
end_comment

begin_comment
comment|// of the thread to "ThreadStatusFinished" failing a check in "SetJoined"
end_comment

begin_comment
comment|// (defined in sanitizer_thread_registry.cc). It might seem a bug on glibc,
end_comment

begin_comment
comment|// however the same version GLIBC-2.17 will not make fail the test on
end_comment

begin_comment
comment|// powerpc64 BE (VMA=46)
end_comment

begin_comment
comment|// XFAIL: powerpc64-unknown-linux-gnu
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_decl_stmt
name|pthread_mutex_t
name|m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pthread_cond_t
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|my_cleanup
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|printf
argument_list|(
literal|"my_cleanup\n"
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|(
name|pthread_mutex_t
operator|*
operator|)
name|arg
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|thr1
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|m
argument_list|)
expr_stmt|;
name|pthread_cleanup_push
argument_list|(
name|my_cleanup
argument_list|,
operator|&
name|m
argument_list|)
expr_stmt|;
name|barrier_wait
argument_list|(
operator|&
name|barrier
argument_list|)
expr_stmt|;
while|while
condition|(
name|x
operator|==
literal|0
condition|)
name|pthread_cond_wait
argument_list|(
operator|&
name|c
argument_list|,
operator|&
name|m
argument_list|)
expr_stmt|;
name|pthread_cleanup_pop
argument_list|(
literal|1
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
parameter_list|()
block|{
name|barrier_init
argument_list|(
operator|&
name|barrier
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|pthread_t
name|th
decl_stmt|;
name|pthread_mutex_init
argument_list|(
operator|&
name|m
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_cond_init
argument_list|(
operator|&
name|c
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_create
argument_list|(
operator|&
name|th
argument_list|,
literal|0
argument_list|,
name|thr1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|barrier_wait
argument_list|(
operator|&
name|barrier
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// let it block on cond var
name|pthread_cancel
argument_list|(
name|th
argument_list|)
expr_stmt|;
name|pthread_join
argument_list|(
name|th
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|m
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|m
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"OK\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

