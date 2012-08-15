begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Eonly -verify %s
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_if
if|#
directive|if
literal|1
end_if

begin_endif
endif|#
directive|endif
endif|junk
end_endif

begin_comment
comment|// shouldn't produce diagnostics
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
endif|#
directive|endif
endif|junk
end_endif

begin_comment
comment|// expected-warning{{extra tokens at end of #endif directive}}
end_comment

begin_if
if|#
directive|if
literal|1
name|junk
end_if

begin_comment
comment|// expected-error{{token is not a valid binary operator in a preprocessor subexpression}}
end_comment

begin_empty
empty|#X
end_empty

begin_comment
comment|// shouldn't produce diagnostics (block #if condition not valid, so skipped)
end_comment

begin_else
else|#
directive|else
end_else

begin_empty
empty|#X
end_empty

begin_comment
comment|// expected-error{{invalid preprocessing directive}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// diagnostics should not be produced until final #endif
end_comment

begin_empty
empty|#X
end_empty

begin_include
include|#
directive|include
end_include

begin_if
if|#
directive|if
literal|1
name|junk
end_if

begin_else
else|#
directive|else
else|junk
end_else

begin_endif
endif|#
directive|endif
endif|junk
end_endif

begin_line
line|#
directive|line
line|-2
end_line

begin_error
error|#
directive|error
end_error

begin_warning
warning|#
directive|warning
end_warning

begin_endif
endif|#
directive|endif
endif|junk
end_endif

begin_comment
comment|// expected-warning{{extra tokens at end of #endif directive}}
end_comment

end_unit

