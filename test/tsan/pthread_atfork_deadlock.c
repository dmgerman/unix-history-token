begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -lpthread -o %t&& %deflake %run %t | FileCheck %s
end_comment

begin_comment
comment|// Regression test for
end_comment

begin_comment
comment|// https://code.google.com/p/thread-sanitizer/issues/detail?id=61
end_comment

begin_comment
comment|// When the data race was reported, pthread_atfork() handler used to be
end_comment

begin_comment
comment|// executed which caused another race report in the same thread, which resulted
end_comment

begin_comment
comment|// in a deadlock.
end_comment

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
file|<unistd.h>
end_include

begin_decl_stmt
name|int
name|glob
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|worker
parameter_list|(
name|void
modifier|*
name|unused
parameter_list|)
block|{
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|glob
operator|++
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|void
name|atfork
parameter_list|()
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ATFORK\n"
argument_list|)
expr_stmt|;
name|glob
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|pthread_atfork
argument_list|(
name|atfork
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|pthread_t
name|t
decl_stmt|;
name|pthread_create
argument_list|(
operator|&
name|t
argument_list|,
name|NULL
argument_list|,
name|worker
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|glob
operator|++
expr_stmt|;
name|pthread_join
argument_list|(
name|t
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|// CHECK: ThreadSanitizer: data race
comment|// CHECK-NOT: ATFORK
return|return
literal|0
return|;
block|}
end_function

end_unit

