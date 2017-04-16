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
file|<tgmath.h>
end_include

begin_comment
comment|// Test the #include_next of tgmath.h works on Darwin.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_TGMATH_H
end_ifndef

begin_error
error|#
directive|error
literal|"SYS_TGMATH_H not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__CLANG_TGMATH_H
end_ifndef

begin_error
error|#
directive|error
literal|"__CLANG_TGMATH_H not defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

