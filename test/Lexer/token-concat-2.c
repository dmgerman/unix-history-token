begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -x c -o - %s | grep '[.][*]'
end_comment

begin_comment
comment|// PR4395
end_comment

begin_define
define|#
directive|define
name|X
value|.*
end_define

begin_macro
name|X
end_macro

end_unit

