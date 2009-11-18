begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -Eonly 2>&1 | grep error
end_comment

begin_comment
comment|// RUN: clang-cc %s -Eonly 2>&1 | not grep unterminated
end_comment

begin_comment
comment|// RUN: clang-cc %s -Eonly 2>&1 | not grep scratch
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

end_unit

