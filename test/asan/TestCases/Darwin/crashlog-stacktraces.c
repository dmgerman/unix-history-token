begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_asan -O0 %s -o %t
end_comment

begin_comment
comment|// RUN: not %run %t 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<execinfo.h>
end_include

begin_include
include|#
directive|include
file|<sanitizer/common_interface_defs.h>
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

begin_function
name|void
name|death_function
parameter_list|()
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"DEATH CALLBACK\n"
argument_list|)
expr_stmt|;
name|void
modifier|*
name|callstack
index|[
literal|128
index|]
decl_stmt|;
name|int
name|i
decl_stmt|,
name|frames
init|=
name|backtrace
argument_list|(
name|callstack
argument_list|,
literal|128
argument_list|)
decl_stmt|;
name|char
modifier|*
modifier|*
name|strs
init|=
name|backtrace_symbols
argument_list|(
name|callstack
argument_list|,
name|frames
argument_list|)
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|frames
condition|;
operator|++
name|i
control|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s\n"
argument_list|,
name|strs
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|strs
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"END OF BACKTRACE\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|fault_function
parameter_list|()
block|{
name|char
modifier|*
name|x
init|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
literal|10
operator|*
sizeof|sizeof
argument_list|(
name|char
argument_list|)
argument_list|)
decl_stmt|;
name|free
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
name|x
index|[
literal|5
index|]
return|;
comment|// BOOM
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|__sanitizer_set_death_callback
argument_list|(
name|death_function
argument_list|)
expr_stmt|;
name|fault_function
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: {{.*ERROR: AddressSanitizer: heap-use-after-free on address}}
end_comment

begin_comment
comment|// CHECK: {{READ of size 1 at 0x.* thread T0}}
end_comment

begin_comment
comment|// CHECK: {{    #0 0x.* in fault_function}}
end_comment

begin_comment
comment|// CHECK: DEATH CALLBACK
end_comment

begin_comment
comment|// CHECK: death_function
end_comment

begin_comment
comment|// CHECK: fault_function
end_comment

begin_comment
comment|// CHECK: main
end_comment

begin_comment
comment|// CHECK: END OF BACKTRACE
end_comment

end_unit

