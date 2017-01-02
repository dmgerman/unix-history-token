begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: system-darwin
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsyntax-only -std=c11 -isysroot %S/Inputs %s
end_comment

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_comment
comment|// Test the #include_next on float.h works on Darwin.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_HAS_SUBNORM
end_ifndef

begin_error
error|#
directive|error
literal|"FLT_HAS_SUBNORM not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Test that definition from builtin are also present.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLT_MAX
end_ifndef

begin_error
error|#
directive|error
literal|"FLT_MAX not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

