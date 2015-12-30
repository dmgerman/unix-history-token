begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding -fno-lax-vector-conversions %s -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -ffreestanding -x c++ %s -verify
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_comment
comment|// Include the metaheader that includes all x86 intrinsic headers.
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

