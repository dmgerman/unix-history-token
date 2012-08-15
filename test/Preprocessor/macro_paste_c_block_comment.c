begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Eonly -verify
end_comment

begin_comment
comment|// expected-error@9 {{EOF}}
end_comment

begin_define
define|#
directive|define
name|COMM
value|/ ## *
end_define

begin_macro
name|COMM
end_macro

begin_comment
comment|// expected-error {{pasting formed '/*', an invalid preprocessing token}}
end_comment

begin_comment
comment|// Demonstrate that an invalid preprocessing token
end_comment

begin_comment
comment|// doesn't swallow the rest of the file...
end_comment

begin_error
error|#
directive|error
error|EOF
end_error

end_unit

