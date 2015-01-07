begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_dfsan                         -m64 %s -o %t&& %run %t | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_dfsan  -mllvm -dfsan-args-abi -m64 %s -o %t&& %run %t | FileCheck %s
end_comment

begin_comment
comment|// Tests that the custom implementation of write() does writes with or without
end_comment

begin_comment
comment|// a callback set using dfsan_set_write_callback().
end_comment

begin_include
include|#
directive|include
file|<sanitizer/dfsan_interface.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|// Check write callback arguments by having the callback store them in
end_comment

begin_comment
comment|// the following variables:
end_comment

begin_decl_stmt
specifier|static
name|int
name|last_callback_arg_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|void
modifier|*
name|last_callback_arg_buf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|size_t
name|last_callback_arg_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Allow tests to check the number of callbacks made by incrementing
end_comment

begin_comment
comment|// this count.  When callbacks are verified, the count is reset.
end_comment

begin_decl_stmt
specifier|static
name|int
name|count_unverified_callbacks
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This callbact will be installed using dfsan_set_write_callback()
end_comment

begin_comment
comment|// in tests below.
end_comment

begin_function
specifier|static
name|void
name|write_callback
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
comment|// Do not do anything in this function that might call write().
name|count_unverified_callbacks
operator|++
expr_stmt|;
name|last_callback_arg_fd
operator|=
name|fd
expr_stmt|;
name|last_callback_arg_buf
operator|=
name|buf
expr_stmt|;
name|last_callback_arg_count
operator|=
name|count
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|write_string_to_stdout
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
block|{
name|char
modifier|*
name|cur
init|=
name|string
decl_stmt|;
name|int
name|bytes_left
init|=
name|strlen
argument_list|(
name|string
argument_list|)
decl_stmt|;
while|while
condition|(
name|bytes_left
operator|>
literal|0
condition|)
block|{
name|int
name|res
init|=
name|write
argument_list|(
name|fileno
argument_list|(
name|stdout
argument_list|)
argument_list|,
name|cur
argument_list|,
name|bytes_left
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|res
operator|>=
literal|0
argument_list|)
expr_stmt|;
name|cur
operator|+=
name|res
expr_stmt|;
name|bytes_left
operator|-=
name|res
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|test_can_write_without_callback
parameter_list|()
block|{
name|dfsan_set_write_callback
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|count_unverified_callbacks
operator|=
literal|0
expr_stmt|;
name|char
name|aString
index|[]
init|=
literal|"Test that writes work without callback.\n"
decl_stmt|;
comment|// CHECK: Test that writes work without callback.
name|write_string_to_stdout
argument_list|(
name|aString
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|count_unverified_callbacks
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|test_can_write_with_callback
parameter_list|()
block|{
name|dfsan_set_write_callback
argument_list|(
name|write_callback
argument_list|)
expr_stmt|;
name|count_unverified_callbacks
operator|=
literal|0
expr_stmt|;
name|char
name|stringWithCallback
index|[]
init|=
literal|"Test that writes work with callback.\n"
decl_stmt|;
comment|// CHECK: Test that writes work with callback.
name|write_string_to_stdout
argument_list|(
name|stringWithCallback
argument_list|)
expr_stmt|;
comment|// Data was written, so at least one call to write() was made.
comment|// Because a write may not process all the bytes it is passed, there
comment|// may have been several calls to write().
name|assert
argument_list|(
name|count_unverified_callbacks
operator|>
literal|0
argument_list|)
expr_stmt|;
name|count_unverified_callbacks
operator|=
literal|0
expr_stmt|;
name|dfsan_set_write_callback
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|char
name|stringWithoutCallback
index|[]
init|=
literal|"Writes work after the callback is removed.\n"
decl_stmt|;
comment|// CHECK: Writes work after the callback is removed.
name|write_string_to_stdout
argument_list|(
name|stringWithoutCallback
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|count_unverified_callbacks
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|test_failing_write_runs_callback
parameter_list|()
block|{
comment|// Open /dev/null in read-only mode.  Calling write() on fd will fail.
name|int
name|fd
init|=
name|open
argument_list|(
literal|"/dev/null"
argument_list|,
name|O_RDONLY
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|fd
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// Install a callback.
name|dfsan_set_write_callback
argument_list|(
name|write_callback
argument_list|)
expr_stmt|;
comment|// Write to the read-only file handle.  The write will fail, but the callback
comment|// should still be invoked.
name|char
name|aString
index|[]
init|=
literal|"This text will fail to be written.\n"
decl_stmt|;
name|int
name|len
init|=
name|strlen
argument_list|(
name|aString
argument_list|)
decl_stmt|;
name|int
name|write_result
init|=
name|write
argument_list|(
name|fd
argument_list|,
name|aString
argument_list|,
name|len
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|write_result
operator|==
operator|-
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|count_unverified_callbacks
operator|==
literal|1
argument_list|)
expr_stmt|;
name|count_unverified_callbacks
operator|=
literal|0
expr_stmt|;
name|assert
argument_list|(
name|fd
operator|==
name|last_callback_arg_fd
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|aString
operator|==
name|last_callback_arg_buf
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|len
operator|==
name|last_callback_arg_count
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
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
name|argv
index|[]
parameter_list|)
block|{
name|test_can_write_without_callback
argument_list|()
expr_stmt|;
name|test_can_write_with_callback
argument_list|()
expr_stmt|;
name|test_failing_write_runs_callback
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

