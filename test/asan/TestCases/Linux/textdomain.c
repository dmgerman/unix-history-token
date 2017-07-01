begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_asan -O0 -g %s -o %t
end_comment

begin_comment
comment|// RUN: %env_asan_opts=strict_string_checks=1 %run %t
end_comment

begin_comment
comment|// Android NDK does not have libintl.h
end_comment

begin_comment
comment|// UNSUPPORTED: android
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_function
name|int
name|main
parameter_list|()
block|{
name|textdomain
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

