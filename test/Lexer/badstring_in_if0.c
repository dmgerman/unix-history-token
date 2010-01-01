begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s 2>&1 | not grep error
end_comment

begin_if
if|#
directive|if
literal|0
end_if

unit|"    '  #endif
end_unit

