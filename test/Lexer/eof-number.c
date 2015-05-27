begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -Wnewline-eof
end_comment

begin_comment
comment|// vim: set binary noeol:
end_comment

begin_comment
comment|// This file intentionally ends without a \n on the last line.  Make sure your
end_comment

begin_comment
comment|// editor doesn't add one.
end_comment

begin_comment
comment|// expected-error@+2{{unterminated conditional directive}}
end_comment

begin_comment
comment|// expected-warning@+1{{no newline at end of file}}
end_comment

begin_if
if|#
directive|if
literal|0
end_if

end_unit

