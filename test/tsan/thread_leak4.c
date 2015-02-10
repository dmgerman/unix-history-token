begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t&& %run %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_function
name|void
modifier|*
name|Thread
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
name|sleep
argument_list|(
literal|100
argument_list|)
expr_stmt|;
comment|// leave the thread "running"
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
name|pthread_t
name|t
decl_stmt|;
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
name|printf
argument_list|(
literal|"DONE\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: DONE
end_comment

begin_comment
comment|// CHECK-NOT: WARNING: ThreadSanitizer: thread leak
end_comment

end_unit

