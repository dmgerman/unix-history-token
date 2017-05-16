begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_safestack -fno-stack-protector -D_FORTIFY_SOURCE=0 -g %s -o %t.nossp
end_comment

begin_comment
comment|// RUN: %run %t.nossp 2>&1 | FileCheck --check-prefix=NOSSP %s
end_comment

begin_comment
comment|// RUN: %clang_safestack -fstack-protector-all -D_FORTIFY_SOURCE=0 -g %s -o %t.ssp
end_comment

begin_comment
comment|// RUN: env LIBC_FATAL_STDERR_=1 not --crash %run %t.ssp 2>&1 | \
end_comment

begin_comment
comment|// RUN:     FileCheck -check-prefix=SSP %s
end_comment

begin_comment
comment|// Test stack canaries on the unsafe stack.
end_comment

begin_comment
comment|// REQUIRES: stable-runtime
end_comment

begin_include
include|#
directive|include
file|<assert.h>
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

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|void
name|f
parameter_list|(
name|unsigned
modifier|*
name|y
parameter_list|)
block|{
name|char
name|x
decl_stmt|;
name|char
modifier|*
specifier|volatile
name|p
init|=
operator|&
name|x
decl_stmt|;
name|char
modifier|*
specifier|volatile
name|q
init|=
operator|(
name|char
operator|*
operator|)
name|y
decl_stmt|;
name|assert
argument_list|(
name|p
operator|<
name|q
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|q
operator|-
name|p
operator|<
literal|1024
argument_list|)
expr_stmt|;
comment|// sanity
comment|// This has technically undefined behavior, but we know the actual layout of
comment|// the unsafe stack and this should not touch anything important.
name|memset
argument_list|(
operator|&
name|x
argument_list|,
literal|0xab
argument_list|,
name|q
operator|-
name|p
operator|+
sizeof|sizeof
argument_list|(
operator|*
name|y
argument_list|)
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
modifier|*
name|argv
parameter_list|)
block|{
name|unsigned
name|y
decl_stmt|;
comment|// NOSSP: main 1
comment|// SSP: main 1
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"main 1\n"
argument_list|)
expr_stmt|;
name|f
argument_list|(
operator|&
name|y
argument_list|)
expr_stmt|;
comment|// NOSSP: main 2
comment|// SSP-NOT: main 2
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"main 2\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

