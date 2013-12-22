begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -fms-compatibility %s -o %t
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t
end_comment

begin_define
define|#
directive|define
name|M2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x + y
end_define

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{x, y}
end_define

begin_define
define|#
directive|define
name|M
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|M2(x, P(x, y))
end_define

begin_macro
name|M
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|)
end_macro

begin_comment
comment|// CHECK: a + {a, b}
end_comment

begin_comment
comment|// Regression test for PR13924
end_comment

begin_define
define|#
directive|define
name|GTEST_CONCAT_TOKEN_
parameter_list|(
name|foo
parameter_list|,
name|bar
parameter_list|)
value|GTEST_CONCAT_TOKEN_IMPL_(foo, bar)
end_define

begin_define
define|#
directive|define
name|GTEST_CONCAT_TOKEN_IMPL_
parameter_list|(
name|foo
parameter_list|,
name|bar
parameter_list|)
value|foo ## bar
end_define

begin_define
define|#
directive|define
name|GMOCK_INTERNAL_COUNT_AND_2_VALUE_PARAMS
parameter_list|(
name|p0
parameter_list|,
name|p1
parameter_list|)
value|P2
end_define

begin_define
define|#
directive|define
name|GMOCK_ACTION_CLASS_
parameter_list|(
name|name
parameter_list|,
name|value_params
parameter_list|)
define|\
value|GTEST_CONCAT_TOKEN_(name##Action, GMOCK_INTERNAL_COUNT_##value_params)
end_define

begin_define
define|#
directive|define
name|ACTION_TEMPLATE
parameter_list|(
name|name
parameter_list|,
name|template_params
parameter_list|,
name|value_params
parameter_list|)
define|\
value|class GMOCK_ACTION_CLASS_(name, value_params) {\ }
end_define

begin_expr_stmt
name|ACTION_TEMPLATE
argument_list|(
name|InvokeArgument
argument_list|,
name|HAS_1_TEMPLATE_PARAMS
argument_list|(
name|int
argument_list|,
name|k
argument_list|)
argument_list|,
name|AND_2_VALUE_PARAMS
argument_list|(
name|p0
argument_list|,
name|p1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This tests compatibility with behaviour needed for type_traits in VS2012
end_comment

begin_comment
comment|// Test based on _VARIADIC_EXPAND_0X macros in xstddef of VS2012
end_comment

begin_define
define|#
directive|define
name|_COMMA
value|,
end_define

begin_define
define|#
directive|define
name|MAKER
parameter_list|(
name|_arg1
parameter_list|,
name|_comma
parameter_list|,
name|_arg2
parameter_list|)
define|\
value|void func(_arg1 _comma _arg2) {}
end_define

begin_define
define|#
directive|define
name|MAKE_FUNC
parameter_list|(
name|_makerP1
parameter_list|,
name|_makerP2
parameter_list|,
name|_arg1
parameter_list|,
name|_comma
parameter_list|,
name|_arg2
parameter_list|)
define|\
value|_makerP1##_makerP2(_arg1, _comma, _arg2)
end_define

begin_macro
name|MAKE_FUNC
argument_list|(
argument|MAK
argument_list|,
argument|ER
argument_list|,
argument|int a
argument_list|,
argument|_COMMA
argument_list|,
argument|int b
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: void func(int a , int b) {}
end_comment

end_unit

