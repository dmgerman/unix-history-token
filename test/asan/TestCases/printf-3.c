begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_asan -O2 %s -o %t
end_comment

begin_comment
comment|// RUN: env ASAN_OPTIONS=check_printf=1 not %run %t 2>&1 | FileCheck --check-prefix=CHECK-ON %s
end_comment

begin_comment
comment|// RUN: env ASAN_OPTIONS=check_printf=0 %run %t 2>&1 | FileCheck --check-prefix=CHECK-OFF %s
end_comment

begin_comment
comment|// RUN: not %run %t 2>&1 | FileCheck --check-prefix=CHECK-ON %s
end_comment

begin_comment
comment|// FIXME: printf is not intercepted on Windows yet.
end_comment

begin_comment
comment|// XFAIL: win32
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|volatile
name|char
name|c
init|=
literal|'0'
decl_stmt|;
specifier|volatile
name|int
name|x
init|=
literal|12
decl_stmt|;
specifier|volatile
name|float
name|f
init|=
literal|1.239
decl_stmt|;
specifier|volatile
name|char
name|s
index|[]
init|=
literal|"34"
decl_stmt|;
specifier|volatile
name|int
name|n
index|[
literal|1
index|]
decl_stmt|;
name|printf
argument_list|(
literal|"%c %d %.3f %s%n\n"
argument_list|,
name|c
argument_list|,
name|x
argument_list|,
name|f
argument_list|,
name|s
argument_list|,
operator|&
name|n
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|// Check that %n is sanitized.
comment|// CHECK-ON: stack-buffer-overflow
comment|// CHECK-ON-NOT: 0 12 1.239 34
comment|// CHECK-OFF: 0 12 1.239 34
block|}
end_function

end_unit

