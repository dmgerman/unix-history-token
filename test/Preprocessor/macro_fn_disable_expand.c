begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -E | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|foo
parameter_list|(
name|x
parameter_list|)
value|bar x
end_define

begin_macro
name|foo
argument_list|(
argument|foo
argument_list|)
end_macro

begin_expr_stmt
operator|(
literal|2
operator|)
comment|// CHECK: bar foo (2)
define|#
directive|define
name|m
parameter_list|(
name|a
parameter_list|)
value|a(w)
define|#
directive|define
name|w
value|ABCD
name|m
argument_list|(
argument|m
argument_list|)
comment|// CHECK: m(ABCD)
comment|// rdar://7466570 PR4438, PR5163
comment|// We should get '42' in the argument list for gcc compatibility.
define|#
directive|define
name|A
value|1
define|#
directive|define
name|B
value|2
define|#
directive|define
name|C
parameter_list|(
name|x
parameter_list|)
value|(x + 1)
name|X
operator|:
name|C
argument_list|(
ifdef|#
directive|ifdef
name|A
if|#
directive|if
name|A
operator|==
literal|1
if|#
directive|if
name|B
literal|42
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
argument_list|)
end_expr_stmt

begin_comment
comment|// CHECK: X: (42 + 1)
end_comment

end_unit

