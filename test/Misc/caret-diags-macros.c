begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck %s -strict-whitespace
end_comment

begin_define
define|#
directive|define
name|M1
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|M2
value|1;
end_define

begin_function
name|void
name|foo
parameter_list|()
block|{
name|M1
argument_list|(
name|M2
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:7:{{[0-9]+}}: warning: expression result unused
comment|// CHECK: {{.*}}:4:{{[0-9]+}}: note: expanded from macro 'M2'
comment|// CHECK: {{.*}}:3:{{[0-9]+}}: note: expanded from macro 'M1'
block|}
end_function

begin_define
define|#
directive|define
name|A
value|1
end_define

begin_define
define|#
directive|define
name|B
value|A
end_define

begin_define
define|#
directive|define
name|C
value|B
end_define

begin_function
name|void
name|bar
parameter_list|()
block|{
name|C
expr_stmt|;
comment|// CHECK: {{.*}}:17:3: warning: expression result unused
comment|// CHECK: {{.*}}:15:11: note: expanded from macro 'C'
comment|// CHECK: {{.*}}:14:11: note: expanded from macro 'B'
comment|// CHECK: {{.*}}:13:11: note: expanded from macro 'A'
block|}
end_function

begin_comment
comment|// rdar://7597492
end_comment

begin_define
define|#
directive|define
name|sprintf
parameter_list|(
name|str
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
define|\
value|__builtin___sprintf_chk (str, 0, 42, A, B)
end_define

begin_function
name|void
name|baz
parameter_list|(
name|char
modifier|*
name|Msg
parameter_list|)
block|{
name|sprintf
argument_list|(
name|Msg
argument_list|,
literal|"  sizeof FoooLib            : =%3u\n"
argument_list|,
literal|12LL
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// PR9279: comprehensive tests for multi-level macro back traces
end_comment

begin_define
define|#
directive|define
name|macro_args1
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|macro_args2
parameter_list|(
name|x
parameter_list|)
value|macro_args1(x)
end_define

begin_define
define|#
directive|define
name|macro_args3
parameter_list|(
name|x
parameter_list|)
value|macro_args2(x)
end_define

begin_define
define|#
directive|define
name|macro_many_args1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|y
end_define

begin_define
define|#
directive|define
name|macro_many_args2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|macro_many_args1(x, y, z)
end_define

begin_define
define|#
directive|define
name|macro_many_args3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|macro_many_args2(x, y, z)
end_define

begin_function
name|void
name|test
parameter_list|()
block|{
name|macro_args3
argument_list|(
literal|11
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:43:15: warning: expression result unused
comment|// Also check that the 'caret' printing agrees with the location here where
comment|// its easy to FileCheck.
comment|// CHECK-NEXT:      macro_args3(11);
comment|// CHECK-NEXT: {{^              \^~}}
comment|// CHECK: {{.*}}:36:36: note: expanded from macro 'macro_args3'
comment|// CHECK: {{.*}}:35:36: note: expanded from macro 'macro_args2'
comment|// CHECK: {{.*}}:34:24: note: expanded from macro 'macro_args1'
name|macro_many_args3
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:55:5: warning: expression result unused
comment|// CHECK: {{.*}}:40:55: note: expanded from macro 'macro_many_args3'
comment|// CHECK: {{.*}}:39:55: note: expanded from macro 'macro_many_args2'
comment|// CHECK: {{.*}}:38:35: note: expanded from macro 'macro_many_args1'
name|macro_many_args3
argument_list|(
literal|1
argument_list|,
name|M2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:64:5: warning: expression result unused
comment|// CHECK: {{.*}}:4:12: note: expanded from macro 'M2'
comment|// CHECK: {{.*}}:40:55: note: expanded from macro 'macro_many_args3'
comment|// CHECK: {{.*}}:39:55: note: expanded from macro 'macro_many_args2'
comment|// CHECK: {{.*}}:38:35: note: expanded from macro 'macro_many_args1'
name|macro_many_args3
argument_list|(
literal|1
argument_list|,
name|macro_args2
argument_list|(
literal|22
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:74:17: warning: expression result unused
comment|// This caret location needs to be printed *inside* a different macro's
comment|// arguments.
comment|// CHECK-NEXT:        macro_args2(22),
comment|// CHECK-NEXT: {{^                \^~}}
comment|// CHECK: {{.*}}:35:36: note: expanded from macro 'macro_args2'
comment|// CHECK: {{.*}}:34:24: note: expanded from macro 'macro_args1'
comment|// CHECK: {{.*}}:40:55: note: expanded from macro 'macro_many_args3'
comment|// CHECK: {{.*}}:39:55: note: expanded from macro 'macro_many_args2'
comment|// CHECK: {{.*}}:38:35: note: expanded from macro 'macro_many_args1'
block|}
end_function

begin_define
define|#
directive|define
name|variadic_args1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|y
end_define

begin_define
define|#
directive|define
name|variadic_args2
parameter_list|(
name|x
parameter_list|,
modifier|...
parameter_list|)
value|variadic_args1(x, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|variadic_args3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|variadic_args2(x, y, __VA_ARGS__)
end_define

begin_function
name|void
name|test2
parameter_list|()
block|{
name|variadic_args3
argument_list|(
literal|1
argument_list|,
literal|22
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:93:21: warning: expression result unused
comment|// CHECK-NEXT:      variadic_args3(1, 22, 3, 4);
comment|// CHECK-NEXT: {{^                    \^~}}
comment|// CHECK: {{.*}}:90:53: note: expanded from macro 'variadic_args3'
comment|// CHECK: {{.*}}:89:50: note: expanded from macro 'variadic_args2'
comment|// CHECK: {{.*}}:88:35: note: expanded from macro 'variadic_args1'
block|}
end_function

begin_define
define|#
directive|define
name|variadic_pasting_args1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|y
end_define

begin_define
define|#
directive|define
name|variadic_pasting_args2
parameter_list|(
name|x
parameter_list|,
modifier|...
parameter_list|)
value|variadic_pasting_args1(x ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|variadic_pasting_args2a
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|variadic_pasting_args1(x, y ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|variadic_pasting_args3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|variadic_pasting_args2(x, y, __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|variadic_pasting_args3a
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
modifier|...
parameter_list|)
value|variadic_pasting_args2a(x, y, __VA_ARGS__)
end_define

begin_function
name|void
name|test3
parameter_list|()
block|{
name|variadic_pasting_args3
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:109:32: warning: expression result unused
comment|// CHECK: {{.*}}:105:72: note: expanded from macro 'variadic_pasting_args3'
comment|// CHECK: {{.*}}:103:68: note: expanded from macro 'variadic_pasting_args2'
comment|// CHECK: {{.*}}:102:41: note: expanded from macro 'variadic_pasting_args1'
name|variadic_pasting_args3a
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:115:30: warning: expression result unused
comment|// CHECK: {{.*}}:106:71: note: expanded from macro 'variadic_pasting_args3a'
comment|// CHECK: {{.*}}:104:70: note: expanded from macro 'variadic_pasting_args2a'
comment|// CHECK: {{.*}}:102:41: note: expanded from macro 'variadic_pasting_args1'
block|}
end_function

begin_define
define|#
directive|define
name|BAD_CONDITIONAL_OPERATOR
value|(2<3)?2:3
end_define

begin_decl_stmt
name|int
name|test4
init|=
name|BAD_CONDITIONAL_OPERATOR
operator|+
name|BAD_CONDITIONAL_OPERATOR
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:         {{.*}}:122:39: note: expanded from macro 'BAD_CONDITIONAL_OPERATOR'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define BAD_CONDITIONAL_OPERATOR (2<3)?2:3
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                      \^}}
end_comment

begin_comment
comment|// CHECK:         {{.*}}:122:39: note: expanded from macro 'BAD_CONDITIONAL_OPERATOR'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define BAD_CONDITIONAL_OPERATOR (2<3)?2:3
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                      \^}}
end_comment

begin_comment
comment|// CHECK:         {{.*}}:122:39: note: expanded from macro 'BAD_CONDITIONAL_OPERATOR'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define BAD_CONDITIONAL_OPERATOR (2<3)?2:3
end_comment

begin_comment
comment|// CHECK-NEXT: {{^                                 ~~~~~\^~~~}}
end_comment

begin_define
define|#
directive|define
name|QMARK
value|?
end_define

begin_define
define|#
directive|define
name|TWOL
value|(2<
end_define

begin_define
define|#
directive|define
name|X
value|1+TWOL 3) QMARK 4:5
end_define

begin_decl_stmt
name|int
name|x
init|=
name|X
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:         {{.*}}:137:9: note: place parentheses around the '+' expression to silence this warning
end_comment

begin_comment
comment|// CHECK-NEXT:    int x = X;
end_comment

begin_comment
comment|// CHECK-NEXT: {{^        \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:136:21: note: expanded from macro 'X'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define X 1+TWOL 3) QMARK 4:5
end_comment

begin_comment
comment|// CHECK-NEXT: {{^          ~~~~~~~~~ \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:134:15: note: expanded from macro 'QMARK'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define QMARK ?
end_comment

begin_comment
comment|// CHECK-NEXT: {{^              \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:137:9: note: place parentheses around the '?:' expression to evaluate it first
end_comment

begin_comment
comment|// CHECK-NEXT:    int x = X;
end_comment

begin_comment
comment|// CHECK-NEXT: {{^        \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:136:21: note: expanded from macro 'X'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define X 1+TWOL 3) QMARK 4:5
end_comment

begin_comment
comment|// CHECK-NEXT: {{^            ~~~~~~~~\^~~~~~~~~}}
end_comment

begin_define
define|#
directive|define
name|ONEPLUS
value|1+
end_define

begin_define
define|#
directive|define
name|Y
value|ONEPLUS (2<3) QMARK 4:5
end_define

begin_decl_stmt
name|int
name|y
init|=
name|Y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK:         {{.*}}:156:9: warning: operator '?:' has lower precedence than '+'; '+' will be evaluated first
end_comment

begin_comment
comment|// CHECK-NEXT:    int y = Y;
end_comment

begin_comment
comment|// CHECK-NEXT: {{^        \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:155:25: note: expanded from macro 'Y'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define Y ONEPLUS (2<3) QMARK 4:5
end_comment

begin_comment
comment|// CHECK-NEXT: {{^          ~~~~~~~~~~~~~ \^}}
end_comment

begin_comment
comment|// CHECK-NEXT:    {{.*}}:134:15: note: expanded from macro 'QMARK'
end_comment

begin_comment
comment|// CHECK-NEXT:    #define QMARK ?
end_comment

begin_comment
comment|// CHECK-NEXT: {{^              \^}}
end_comment

end_unit

