begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_tsan -O1 %s -o %t&& %env_tsan_opts=flush_memory_ms=1:memory_limit_mb=1 %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// setuid(0) hangs on powerpc64 big endian.  When this is fixed remove
end_comment

begin_comment
comment|// the unsupported flag.
end_comment

begin_comment
comment|// https://llvm.org/bugs/show_bug.cgi?id=25799
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// UNSUPPORTED: powerpc64-unknown-linux-gnu
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|// Test that setuid call works in presence of stoptheworld.
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|unsigned
name|long
name|long
name|tp0
decl_stmt|,
name|tp1
decl_stmt|;
name|tp0
operator|=
name|monotonic_clock_ns
argument_list|()
expr_stmt|;
name|tp1
operator|=
name|monotonic_clock_ns
argument_list|()
expr_stmt|;
while|while
condition|(
name|tp1
operator|-
name|tp0
operator|<
literal|3
operator|*
literal|1000000000ull
condition|)
block|{
name|tp1
operator|=
name|monotonic_clock_ns
argument_list|()
expr_stmt|;
name|setuid
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
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

end_unit

