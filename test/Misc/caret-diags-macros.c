begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck %s
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
comment|// CHECK: :7:{{[0-9]+}}: warning: expression result unused
comment|// CHECK: :4:{{[0-9]+}}: note: expanded from:
comment|// CHECK: :3:{{[0-9]+}}: note: expanded from:
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
comment|// CHECK: :17:3: warning: expression result unused
comment|// CHECK: :15:11: note: expanded from:
comment|// CHECK: :14:11: note: expanded from:
comment|// CHECK: :13:11: note: expanded from:
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
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:43:15: warning: expression result unused
comment|// Also check that the 'caret' printing agrees with the location here where
comment|// its easy to FileCheck.
comment|// CHECK-NEXT: macro_args3(1);
comment|// CHECK-NEXT: ~~~~~~~~~~~~^~
comment|// CHECK: {{.*}}:36:36: note: expanded from:
comment|// CHECK: {{.*}}:35:36: note: expanded from:
comment|// CHECK: {{.*}}:34:24: note: expanded from:
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
comment|// CHECK: {{.*}}:40:55: note: expanded from:
comment|// CHECK: {{.*}}:39:55: note: expanded from:
comment|// CHECK: {{.*}}:38:35: note: expanded from:
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
comment|// CHECK: {{.*}}:4:12: note: expanded from:
comment|// CHECK: {{.*}}:40:55: note: expanded from:
comment|// CHECK: {{.*}}:39:55: note: expanded from:
comment|// CHECK: {{.*}}:38:35: note: expanded from:
name|macro_many_args3
argument_list|(
literal|1
argument_list|,
name|macro_args2
argument_list|(
literal|2
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:74:17: warning: expression result unused
comment|// This caret location needs to be printed *inside* a different macro's
comment|// arguments.
comment|// CHECK-NEXT: macro_args2(2),
comment|// CHECK-NEXT: ~~~~~~~~~~~~^~~
comment|// CHECK: {{.*}}:35:36: note: expanded from:
comment|// CHECK: {{.*}}:34:24: note: expanded from:
comment|// CHECK: {{.*}}:40:55: note: expanded from:
comment|// CHECK: {{.*}}:39:55: note: expanded from:
comment|// CHECK: {{.*}}:38:35: note: expanded from:
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
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: {{.*}}:93:21: warning: expression result unused
comment|// CHECK-NEXT: variadic_args3(1, 2, 3, 4);
comment|// CHECK-NEXT: ~~~~~~~~~~~~~~~~~~^~~~~~~~
comment|// CHECK: {{.*}}:90:53: note: expanded from:
comment|// CHECK: {{.*}}:89:50: note: expanded from:
comment|// CHECK: {{.*}}:88:35: note: expanded from:
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
comment|// CHECK: {{.*}}:105:72: note: expanded from:
comment|// CHECK: {{.*}}:103:68: note: expanded from:
comment|// CHECK: {{.*}}:102:41: note: expanded from:
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
comment|// CHECK: {{.*}}:106:71: note: expanded from:
comment|// CHECK: {{.*}}:104:70: note: expanded from:
comment|// CHECK: {{.*}}:102:41: note: expanded from:
block|}
end_function

end_unit

