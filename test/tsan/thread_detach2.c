begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t&& %run %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_comment
comment|// Test for https://llvm.org/bugs/show_bug.cgi?id=23235
end_comment

begin_comment
comment|// The bug was that synchronization between thread creation and thread start
end_comment

begin_comment
comment|// is not established if pthread_create is followed by pthread_detach.
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|Thread
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
block|{
name|x
operator|=
literal|42
expr_stmt|;
name|barrier_wait
argument_list|(
operator|&
name|barrier
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
name|t
decl_stmt|;
name|x
operator|=
literal|43
expr_stmt|;
name|pthread_create
argument_list|(
operator|&
name|t
argument_list|,
literal|0
argument_list|,
name|Thread
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pthread_detach
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|barrier_wait
argument_list|(
operator|&
name|barrier
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"PASS\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-NOT: WARNING: ThreadSanitizer: data race
end_comment

begin_comment
comment|// CHECK: PASS
end_comment

end_unit

