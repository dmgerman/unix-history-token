begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test the GNU comma swallowing extension.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E | grep 'foo{A, }'
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E | grep 'fo2{A,}'
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E | grep '{foo}'
end_comment

begin_define
define|#
directive|define
name|X
parameter_list|(
name|Y
parameter_list|)
value|foo{A, Y}
end_define

begin_macro
name|X
argument_list|()
end_macro

begin_define
define|#
directive|define
name|X2
parameter_list|(
name|Y
parameter_list|)
value|fo2{A,##Y}
end_define

begin_macro
name|X2
argument_list|()
end_macro

begin_comment
comment|// should eat the comma.
end_comment

begin_define
define|#
directive|define
name|X3
parameter_list|(
name|b
parameter_list|,
modifier|...
parameter_list|)
value|{b, ## __VA_ARGS__}
end_define

begin_macro
name|X3
argument_list|(
argument|foo
argument_list|)
end_macro

begin_comment
comment|// RUN: %clang_cc1 %s -E | grep 'AA BB'
end_comment

begin_comment
comment|// PR3880
end_comment

begin_define
define|#
directive|define
name|X4
parameter_list|(
modifier|...
parameter_list|)
value|AA , ## __VA_ARGS__ BB
end_define

begin_macro
name|X4
argument_list|()
end_macro

end_unit

