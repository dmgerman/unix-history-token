begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test the GNU comma swallowing extension.
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -E | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// CHECK: 1: foo{A, }
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

begin_expr_stmt
literal|1
operator|:
name|X
argument_list|()
comment|// CHECK: 2: fo2{A,}
define|#
directive|define
name|X2
parameter_list|(
name|Y
parameter_list|)
value|fo2{A,##Y}
literal|2
operator|:
name|X2
argument_list|()
comment|// should eat the comma.
comment|// CHECK: 3: {foo}
define|#
directive|define
name|X3
parameter_list|(
name|b
parameter_list|,
modifier|...
parameter_list|)
value|{b, ## __VA_ARGS__}
literal|3
operator|:
name|X3
argument_list|(
name|foo
argument_list|)
comment|// PR3880
comment|// CHECK: 4: AA BB
define|#
directive|define
name|X4
parameter_list|(
modifier|...
parameter_list|)
value|AA , ## __VA_ARGS__ BB
literal|4
operator|:
name|X4
argument_list|()
comment|// PR7943
comment|// CHECK: 5: 1
define|#
directive|define
name|X5
parameter_list|(
name|x
parameter_list|,
modifier|...
parameter_list|)
value|x##,##__VA_ARGS__
literal|5
operator|:
name|X5
argument_list|(
literal|1
argument_list|)
end_expr_stmt

end_unit

