begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E | grep 'foo(A, )'
end_comment

begin_define
define|#
directive|define
name|X
parameter_list|(
name|Y
parameter_list|)
value|foo(A, Y)
end_define

begin_macro
name|X
argument_list|()
end_macro

end_unit

