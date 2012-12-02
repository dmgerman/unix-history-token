begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -Eonly -verify %s
end_comment

begin_comment
comment|// Try different path permutations of __has_include with existing file.
end_comment

begin_if
if|#
directive|if
name|__has_include
argument_list|(
literal|"stdint.h"
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
name|stdint
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
literal|"stdint.h"
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
literal|"stdint.h"
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
literal|"stdint.h"
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
literal|"stdint.h"
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
comment|// FIXME: We can recover better in almost all of these cases. (PR13335)
end_comment

begin_comment
comment|// expected-error@+1 {{missing '(' after '__has_include'}}
end_comment

begin_if
if|#
directive|if
name|__has_include
literal|"stdint.h"
if|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{expected "FILENAME" or<FILENAME>}} expected-error@+1 {{token is not a valid binary operator in a preprocessor subexpression}}
end_comment

begin_if
if|#
directive|if
name|__has_include
argument_list|(
name|stdint
operator|.
name|h
argument_list|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{expected "FILENAME" or<FILENAME>}}
end_comment

begin_if
if|#
directive|if
name|__has_include
argument_list|()
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{missing '(' after '__has_include'}}
end_comment

begin_if
if|#
directive|if
name|__has_include
if|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{missing '(' after '__has_include'}}
end_comment

begin_if
if|#
directive|if
name|__has_include
operator|<
name|stdint
operator|.
name|h
operator|>
if|)
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// expected-error@+1 {{expected "FILENAME" or<FILENAME>}} expected-warning@+1 {{missing terminating '"' character}}  expected-error@+1 {{invalid token at start of a preprocessor expression}}
end_comment

begin_if
if|#
directive|if
name|__has_include
argument_list|(
literal|"stdint.h)
argument|#endif
comment|// expected-error@+1 {{expected "FILENAME" or<FILENAME>}} expected-warning@+1 {{missing terminating '"' character}} expected-error@+1 {{token is not a valid binary operator in a preprocessor subexpression}}
argument|#if __has_include(stdint.h
literal|")
argument|#endif
comment|// expected-error@+1 {{expected "FILENAME" or<FILENAME>}} expected-error@+1 {{token is not a valid binary operator in a preprocessor subexpression}}
argument|#if __has_include(stdint.h>) #endif
comment|// expected-error@+1 {{missing '(' after '__has_include'}}
argument|__has_include
comment|// expected-error@+1 {{missing ')' after '__has_include'}} // expected-error@+1 {{expected value in expression}}  // expected-note@+1 {{to match this '('}}
argument|#if __has_include(
literal|"stdint.h"
argument|#endif
comment|// expected-error@+1 {{expected "FILENAME" or<FILENAME>}} // expected-error@+1 {{expected value in expression}}
argument|#if __has_include( #endif
comment|// expected-error@+1 {{missing '(' after '__has_include'}} // expected-error@+1 {{expected value in expression}}
argument|#if __has_include #endif
comment|// expected-error@+1 {{missing ')' after '__has_include'}}  // expected-error@+1 {{expected value in expression}}  // expected-note@+1 {{to match this '('}}
argument|#if __has_include(<stdint.h> #endif
comment|// expected-error@+1 {{expected "FILENAME" or<FILENAME>}} // expected-error@+1 {{expected value in expression}}
argument|#if __has_include(<stdint.h) #endif
end_if

end_unit

