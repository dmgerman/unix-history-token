begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Eonly -verify %s
end_comment

begin_comment
comment|// Try different path permutations of __has_include with existing file.
end_comment

begin_if
if|#
directive|if
name|__has_include
argument_list|(
literal|"stdio.h"
argument_list|)
end_if

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"__has_include failed (1)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_include
argument_list|(
operator|<
name|stdio
operator|.
name|h
operator|>
argument_list|)
end_if

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"__has_include failed (2)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try unary expression.
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_include
argument_list|(
literal|"stdio.h"
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"__has_include failed (5)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try binary expression.
end_comment

begin_if
if|#
directive|if
name|__has_include
argument_list|(
literal|"stdio.h"
argument_list|)
operator|&&
name|__has_include
argument_list|(
literal|"stddef.h"
argument_list|)
end_if

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"__has_include failed (6)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try non-existing file.
end_comment

begin_if
if|#
directive|if
name|__has_include
argument_list|(
literal|"blahblah.h"
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"__has_include failed (7)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try defined.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__has_include
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"defined(__has_include) failed (8)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try different path permutations of __has_include_next with existing file.
end_comment

begin_if
if|#
directive|if
name|__has_include_next
argument_list|(
literal|"stddef.h"
argument_list|)
end_if

begin_comment
comment|// expected-warning {{#include_next in primary source file}}
end_comment

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"__has_include failed (1)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_include_next
argument_list|(
operator|<
name|stddef
operator|.
name|h
operator|>
argument_list|)
end_if

begin_comment
comment|// expected-warning {{#include_next in primary source file}}
end_comment

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"__has_include failed (2)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try unary expression.
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_include_next
argument_list|(
literal|"stdio.h"
argument_list|)
end_if

begin_comment
comment|// expected-warning {{#include_next in primary source file}}
end_comment

begin_error
error|#
directive|error
literal|"__has_include_next failed (5)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try binary expression.
end_comment

begin_if
if|#
directive|if
name|__has_include_next
argument_list|(
literal|"stdio.h"
argument_list|)
operator|&&
name|__has_include
argument_list|(
literal|"stddef.h"
argument_list|)
end_if

begin_comment
comment|// expected-warning {{#include_next in primary source file}}
end_comment

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"__has_include_next failed (6)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try non-existing file.
end_comment

begin_if
if|#
directive|if
name|__has_include_next
argument_list|(
literal|"blahblah.h"
argument_list|)
end_if

begin_comment
comment|// expected-warning {{#include_next in primary source file}}
end_comment

begin_error
error|#
directive|error
literal|"__has_include_next failed (7)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try defined.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__has_include_next
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"defined(__has_include_next) failed (8)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Try badly formed expressions.
end_comment

begin_comment
comment|// FIXME: I don't quite know how to avoid preprocessor side effects.
end_comment

begin_comment
comment|// Use FileCheck?
end_comment

begin_comment
comment|// It also assert due to unterminated #if's.
end_comment

begin_comment
comment|//#if __has_include("stdio.h"
end_comment

begin_comment
comment|//#if __has_include "stdio.h")
end_comment

begin_comment
comment|//#if __has_include(stdio.h)
end_comment

begin_comment
comment|//#if __has_include()
end_comment

begin_comment
comment|//#if __has_include(
end_comment

begin_comment
comment|//#if __has_include)
end_comment

begin_comment
comment|//#if __has_include
end_comment

begin_comment
comment|//#if __has_include(<stdio.h>
end_comment

begin_comment
comment|//#if __has_include<stdio.h>)
end_comment

begin_comment
comment|//#if __has_include("stdio.h)
end_comment

begin_comment
comment|//#if __has_include(stdio.h")
end_comment

begin_comment
comment|//#if __has_include(<stdio.h)
end_comment

begin_comment
comment|//#if __has_include(stdio.h>)
end_comment

end_unit

