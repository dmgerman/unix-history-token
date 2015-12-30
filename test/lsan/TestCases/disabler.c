begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test for __lsan_disable() / __lsan_enable().
end_comment

begin_comment
comment|// RUN: LSAN_BASE="report_objects=1:use_registers=0:use_stacks=0:use_globals=0:use_tls=0"
end_comment

begin_comment
comment|// RUN: %clang_lsan %s -o %t
end_comment

begin_comment
comment|// RUN: LSAN_OPTIONS=$LSAN_BASE not %run %t 2>&1 | FileCheck %s
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
file|"sanitizer/lsan_interface.h"
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|void
modifier|*
modifier|*
name|p
decl_stmt|;
block|{
name|__lsan_disable
argument_list|()
expr_stmt|;
name|p
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|__lsan_enable
argument_list|()
expr_stmt|;
block|}
operator|*
name|p
operator|=
name|malloc
argument_list|(
literal|666
argument_list|)
expr_stmt|;
name|void
modifier|*
name|q
init|=
name|malloc
argument_list|(
literal|1337
argument_list|)
decl_stmt|;
comment|// Break optimization.
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Test alloc: %p.\n"
argument_list|,
name|q
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: SUMMARY: {{(Leak|Address)}}Sanitizer: 1337 byte(s) leaked in 1 allocation(s)
end_comment

end_unit

