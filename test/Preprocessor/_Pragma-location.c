begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | not grep 'scratch space'
end_comment

begin_define
define|#
directive|define
name|push
value|_Pragma ("pack(push)")
end_define

begin_macro
name|push
end_macro

end_unit

