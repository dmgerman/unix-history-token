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
comment|// CHECK: {{.*}}:6:{{[0-9]+}}: warning: expression result unused
comment|// CHECK: {{.*}}:7:{{[0-9]+}}: note: instantiated from:
comment|// CHECK: {{.*}}:4:{{[0-9]+}}: note: instantiated from:
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
comment|// CHECK: {{.*}}:17:{{[0-9]+}}: warning: expression result unused
comment|// CHECK: {{.*}}:15:{{[0-9]+}}: note: instantiated from:
comment|// CHECK: {{.*}}:14:{{[0-9]+}}: note: instantiated from:
comment|// CHECK: {{.*}}:13:{{[0-9]+}}: note: instantiated from:
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

end_unit

