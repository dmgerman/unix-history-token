begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that initially callocked memory is properly freed
end_comment

begin_comment
comment|// (see https://github.com/google/sanitizers/issues/626).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -o %t
end_comment

begin_comment
comment|// RUN: env LD_PRELOAD=%shared_libasan %run %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// REQUIRES: asan-dynamic-runtime
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This way of setting LD_PRELOAD does not work with Android test runner.
end_comment

begin_comment
comment|// REQUIRES: not-android
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

begin_decl_stmt
specifier|static
name|void
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This constructor will run before __asan_init
end_comment

begin_comment
comment|// so calloc will allocate memory from special pool.
end_comment

begin_function
specifier|static
name|void
name|init
parameter_list|()
block|{
name|ptr
operator|=
name|calloc
argument_list|(
literal|10
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(section(
literal|".preinit_array"
argument|), used)
argument_list|)
end_macro

begin_decl_stmt
name|void
modifier|*
name|dummy
init|=
name|init
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|free_memory
parameter_list|()
block|{
comment|// This used to abort because
comment|// Asan's free didn't recognize ptr.
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|free_memory
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

