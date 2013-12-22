begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-apple-darwin10 -target-cpu yonah -fsyntax-only -verify -std=c89 %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// FIXME: Disable inclusion of mm_malloc.h, our current implementation is broken
end_comment

begin_comment
comment|// on win32 since we don't generally know how to find errno.h.
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

begin_comment
comment|// PR6658
end_comment

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

end_unit

