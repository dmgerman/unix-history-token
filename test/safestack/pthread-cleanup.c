begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_safestack %s -pthread -o %t
end_comment

begin_comment
comment|// RUN: not --crash %run %t
end_comment

begin_comment
comment|// Test that unsafe stacks are deallocated correctly on thread exit.
end_comment

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

begin_enum
enum|enum
block|{
name|kBufferSize
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|}
enum|;
end_enum

begin_function
name|void
modifier|*
name|t1_start
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|char
name|buffer
index|[
name|kBufferSize
index|]
decl_stmt|;
return|return
name|buffer
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
name|pthread_t
name|t1
decl_stmt|;
name|char
modifier|*
name|buffer
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|pthread_create
argument_list|(
operator|&
name|t1
argument_list|,
name|NULL
argument_list|,
name|t1_start
argument_list|,
name|NULL
argument_list|)
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|pthread_join
argument_list|(
name|t1
argument_list|,
operator|&
name|buffer
argument_list|)
condition|)
name|abort
argument_list|()
expr_stmt|;
comment|// should segfault here
name|memset
argument_list|(
name|buffer
argument_list|,
literal|0
argument_list|,
name|kBufferSize
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

