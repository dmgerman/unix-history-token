begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | grep "barbaz123"
end_comment

begin_define
define|#
directive|define
name|FOO
value|bar ## baz ## 123
end_define

begin_macro
name|FOO
end_macro

end_unit

