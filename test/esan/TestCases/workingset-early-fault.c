begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test shadow faults during esan initialization as well as
end_comment

begin_comment
comment|// faults during dlsym's calloc during interceptor init.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang_esan_wset %s -o %t
end_comment

begin_comment
comment|// RUN: %run %t 2>&1 | FileCheck %s
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

begin_comment
comment|// Our goal is to emulate an instrumented allocator, whose calloc
end_comment

begin_comment
comment|// invoked from dlsym will trigger shadow faults, to test an
end_comment

begin_comment
comment|// early shadow fault during esan interceptor init.
end_comment

begin_comment
comment|// We do this by replacing calloc:
end_comment

begin_function
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|n
parameter_list|)
block|{
comment|// Unfortunately we can't print anything to make the test
comment|// ensure we got here b/c the sanitizer interceptors can't
comment|// handle that during interceptor init.
comment|// Ensure we trigger a shadow write fault:
name|int
name|x
index|[
literal|16
index|]
decl_stmt|;
name|x
index|[
literal|0
index|]
operator|=
name|size
expr_stmt|;
comment|// Now just emulate calloc.
name|void
modifier|*
name|res
init|=
name|malloc
argument_list|(
name|size
operator|*
name|n
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|res
argument_list|,
literal|0
argument_list|,
name|size
operator|*
name|n
argument_list|)
expr_stmt|;
return|return
name|res
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
name|printf
argument_list|(
literal|"all done\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: all done
end_comment

end_unit

