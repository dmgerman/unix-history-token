begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_safestack %s -pthread -o %t
end_comment

begin_comment
comment|// RUN: %run %t
end_comment

begin_comment
comment|// XFAIL: darwin
end_comment

begin_comment
comment|// Test that pthreads receive their own unsafe stack.
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

begin_include
include|#
directive|include
file|"utils.h"
end_include

begin_decl_stmt
specifier|static
name|int
name|ptr_test
init|=
literal|42
decl_stmt|;
end_decl_stmt

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
if|if
condition|(
name|ptr
operator|!=
operator|&
name|ptr_test
condition|)
name|abort
argument_list|()
expr_stmt|;
comment|// safe stack
name|int
name|val
init|=
name|ptr_test
operator|*
literal|5
decl_stmt|;
comment|// unsafe stack
name|char
name|buffer
index|[
literal|8096
index|]
decl_stmt|;
comment|// two pages
name|memset
argument_list|(
name|buffer
argument_list|,
name|val
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
argument_list|)
expr_stmt|;
name|break_optimization
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
return|return
name|ptr
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
name|void
modifier|*
name|ptr
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
operator|&
name|ptr_test
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
name|ptr
argument_list|)
condition|)
name|abort
argument_list|()
expr_stmt|;
if|if
condition|(
name|ptr
operator|!=
operator|&
name|ptr_test
condition|)
name|abort
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

