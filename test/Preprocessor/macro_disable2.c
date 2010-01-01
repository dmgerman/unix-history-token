begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep 'A B C A B A C A B C A'
end_comment

begin_define
define|#
directive|define
name|A
value|A B C
end_define

begin_define
define|#
directive|define
name|B
value|B C A
end_define

begin_define
define|#
directive|define
name|C
value|C A B
end_define

begin_macro
name|A
end_macro

end_unit

