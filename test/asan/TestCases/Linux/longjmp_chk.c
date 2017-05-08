begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Verify that use of longjmp() in a _FORTIFY_SOURCE'd library (without ASAN)
end_comment

begin_comment
comment|// is correctly intercepted such that the stack is unpoisoned.
end_comment

begin_comment
comment|// Note: it is essential that the external library is not built with ASAN,
end_comment

begin_comment
comment|// otherwise it would be able to unpoison the stack before use.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -DIS_LIBRARY -D_FORTIFY_SOURCE=2 -O2 %s -c -o %t.o
end_comment

begin_comment
comment|// RUN: %clang_asan -O2 %s %t.o -o %t
end_comment

begin_comment
comment|// RUN: %run %t
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IS_LIBRARY
end_ifdef

begin_comment
comment|/* the library */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<sanitizer/asan_interface.h>
end_include

begin_decl_stmt
specifier|static
name|jmp_buf
name|jenv
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|external_callme
parameter_list|(
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
if|if
condition|(
name|setjmp
argument_list|(
name|jenv
argument_list|)
operator|==
literal|0
condition|)
block|{
name|callback
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|external_longjmp
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|)
block|{
name|longjmp
argument_list|(
name|jenv
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|external_check_stack
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|buf
index|[
literal|256
index|]
init|=
literal|""
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|256
condition|;
name|i
operator|++
control|)
block|{
name|assert
argument_list|(
operator|!
name|__asan_address_is_poisoned
argument_list|(
name|buf
operator|+
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* main program */
end_comment

begin_function_decl
specifier|extern
name|void
name|external_callme
parameter_list|(
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|external_longjmp
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|external_check_stack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|callback
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|msg
index|[
literal|16
index|]
decl_stmt|;
comment|/* Note: this triggers addition of a redzone. */
comment|/* Note: msg is passed to prevent compiler optimization from removing it. */
name|external_longjmp
argument_list|(
name|msg
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|external_callme
argument_list|(
name|callback
argument_list|)
expr_stmt|;
name|external_check_stack
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

