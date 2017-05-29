begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s 2>&1 | FileCheck %s -strict-whitespace
end_comment

begin_comment
comment|// PR6101
end_comment

begin_decl_stmt
name|int
name|a
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: # 1 "{{.*}}line-directive-output.c"
end_comment

begin_comment
comment|// Check that we do not emit an enter marker for the main file.
end_comment

begin_comment
comment|// CHECK-NOT: # 1 "{{.*}}line-directive-output.c" 1
end_comment

begin_comment
comment|// CHECK: int a;
end_comment

begin_comment
comment|// CHECK-NEXT: # 50 "{{.*}}line-directive-output.c"
end_comment

begin_comment
comment|// CHECK-NEXT: int b;
end_comment

begin_line
line|#
directive|line
number|50
end_line

begin_decl_stmt
name|int
name|b
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: # 13 "{{.*}}line-directive-output.c"
end_comment

begin_comment
comment|// CHECK-NEXT: int c;
end_comment

begin_empty
empty|# 13
end_empty

begin_decl_stmt
name|int
name|c
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-NEXT: # 1 "A.c"
end_comment

begin_line
line|#
directive|line
number|1
file|"A.c"
end_line

begin_comment
comment|// CHECK-NEXT: # 2 "A.c"
end_comment

begin_line
line|#
directive|line
number|2
end_line

begin_comment
comment|// CHECK-NEXT: # 1 "B.c"
end_comment

begin_line
line|#
directive|line
number|1
file|"B.c"
end_line

begin_comment
comment|// CHECK-NEXT: # 1000 "A.c"
end_comment

begin_line
line|#
directive|line
number|1000
file|"A.c"
end_line

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: # 1010 "A.c"
end_comment

begin_decl_stmt
name|int
name|z
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_empty
empty|# 3 "temp2.h" 1
end_empty

begin_decl_stmt
specifier|extern
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_empty
empty|# 7 "A.c" 2
end_empty

begin_decl_stmt
specifier|extern
name|int
name|z
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: # 25 "A.c"
end_comment

begin_comment
comment|// CHECK: # 50 "C.c" 1
end_comment

begin_empty
empty|# 50 "C.c" 1
end_empty

begin_comment
comment|// CHECK-NEXT: # 2000 "A.c" 2
end_comment

begin_empty
empty|# 2000 "A.c" 2
end_empty

begin_empty
empty|# 42 "A.c"
end_empty

begin_empty
empty|# 44 "A.c"
end_empty

begin_empty
empty|# 49 "A.c"
end_empty

begin_comment
comment|// CHECK: # 50 "a\n.c"
end_comment

begin_empty
empty|# 50 "a\012.c"
end_empty

begin_empty
empty|# 1 "system.h" 3
end_empty

begin_empty
empty|# 2
end_empty

begin_function_decl
name|void
name|sys_foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// CHECK: # 1 "system.h" 3
end_comment

begin_comment
comment|// CHECK-NEXT: # 2 "system.h" 3
end_comment

begin_comment
comment|// CHECK-NEXT: void sys_foo(void);
end_comment

end_unit

