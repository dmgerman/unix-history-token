begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Regression test for thread lifetime tracking. Thread data should be
end_comment

begin_comment
comment|// considered live during the thread's termination, at least until the
end_comment

begin_comment
comment|// user-installed TSD destructors have finished running (since they may contain
end_comment

begin_comment
comment|// additional cleanup tasks). LSan doesn't actually meet that goal 100%, but it
end_comment

begin_comment
comment|// makes its best effort.
end_comment

begin_comment
comment|// RUN: LSAN_BASE="report_objects=1:use_registers=0:use_stacks=0:use_globals=0"
end_comment

begin_comment
comment|// RUN: %clang_lsan %s -o %t
end_comment

begin_comment
comment|// RUN: LSAN_OPTIONS=$LSAN_BASE:use_tls=1 %run %t
end_comment

begin_comment
comment|// RUN: LSAN_OPTIONS=$LSAN_BASE:use_tls=0 not %run %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

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
file|"sanitizer/lsan_interface.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/print_address.h"
end_include

begin_decl_stmt
name|pthread_key_t
name|key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__thread
name|void
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|key_destructor
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
comment|// Generally this may happen on a different thread.
name|__lsan_do_leak_check
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
modifier|*
name|thread_func
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|p
operator|=
name|malloc
argument_list|(
literal|1337
argument_list|)
expr_stmt|;
name|print_address
argument_list|(
literal|"Test alloc: "
argument_list|,
literal|1
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|int
name|res
init|=
name|pthread_setspecific
argument_list|(
name|key
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|1
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|res
operator|==
literal|0
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
name|int
name|res
init|=
name|pthread_key_create
argument_list|(
operator|&
name|key
argument_list|,
operator|&
name|key_destructor
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|res
operator|==
literal|0
argument_list|)
expr_stmt|;
name|pthread_t
name|thread_id
decl_stmt|;
name|res
operator|=
name|pthread_create
argument_list|(
operator|&
name|thread_id
argument_list|,
literal|0
argument_list|,
name|thread_func
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|res
operator|==
literal|0
argument_list|)
expr_stmt|;
name|res
operator|=
name|pthread_join
argument_list|(
name|thread_id
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|res
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: Test alloc: [[ADDR:0x[0-9,a-f]+]]
end_comment

begin_comment
comment|// CHECK: [[ADDR]] (1337 bytes)
end_comment

end_unit

