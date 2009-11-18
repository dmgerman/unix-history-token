begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -E 2>&1 | grep 'DO_PRAGMA (STR'
end_comment

begin_comment
comment|// RUN: clang-cc %s -E 2>&1 | grep '7:3'
end_comment

begin_define
define|#
directive|define
name|DO_PRAGMA
value|_Pragma
end_define

begin_define
define|#
directive|define
name|STR
value|"GCC dependency \"parse.y\"")
end_define

begin_comment
comment|// Test that this line is printed by caret diagnostics.
end_comment

begin_macro
name|DO_PRAGMA
argument_list|(
argument|STR
end_macro

end_unit

