begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Eonly -trigraphs %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Eonly -verify %s
end_comment

begin_comment
comment|//\
end_comment

begin_error
error|#
directive|error
error|bar
end_error

begin_comment
comment|//??/
end_comment

begin_error
error|#
directive|error
error|qux
end_error

begin_comment
comment|// expected-error@-1 {{qux}}
end_comment

begin_comment
comment|// Trailing whitespace!
end_comment

begin_comment
comment|//\
end_comment

begin_error
error|#
directive|error
error|quux
end_error

begin_comment
comment|// expected-warning@-2 {{backslash and newline separated by space}}
end_comment

end_unit

