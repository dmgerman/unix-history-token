begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -o /dev/null -S
end_comment

begin_comment
comment|// Note:
end_comment

begin_comment
comment|//  We fail this on Sparc because the C library seems to be missing complex.h
end_comment

begin_comment
comment|//  and the corresponding C99 complex support.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  We could modify the test to use only GCC extensions, but I don't know if
end_comment

begin_comment
comment|//  that would change the nature of the test.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// XFAIL: sparc
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__CYGWIN__
end_ifdef

begin_include
include|#
directive|include
file|<mingw/complex.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<complex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|foo
parameter_list|(
name|complex
name|float
name|c
parameter_list|)
block|{
return|return
name|creal
argument_list|(
name|c
argument_list|)
return|;
block|}
end_function

end_unit

