begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name macros.c %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|MACRO
value|return; bar()
end_define

begin_define
define|#
directive|define
name|MACRO_2
value|bar()
end_define

begin_define
define|#
directive|define
name|MACRO_1
value|return; MACRO_2
end_define

begin_define
define|#
directive|define
name|MACRO_3
value|MACRO_2
end_define

begin_function
name|void
name|bar
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: func
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:13 -> [[@LINE+5]]:2 = #0
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+1]]:3 -> [[@LINE+1]]:8 = #0
name|MACRO
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:8 -> [[@LINE+2]]:2 = 0
name|i
operator|=
literal|2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 1, 3:15 -> 3:28 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 3:23 -> 3:28 = 0
end_comment

begin_comment
comment|// CHECK-NEXT: func2
end_comment

begin_function
name|void
name|func2
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE+5]]:2 = #0
name|int
name|i
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+1]]:3 -> [[@LINE+1]]:10 = #0
name|MACRO_1
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:10 -> [[@LINE+2]]:2 = 0
name|i
operator|=
literal|2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 1, 5:17 -> 5:32 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 1, 5:25 -> 5:32 = 0
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, 4:17 -> 4:22 = 0
end_comment

begin_comment
comment|// CHECK-NEXT: func3
end_comment

begin_function
name|void
name|func3
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE+3]]:2 = #0
name|MACRO_2
expr_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE]]:3 -> [[@LINE]]:10 = #0
name|MACRO_2
expr_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE]]:3 -> [[@LINE]]:10 = #0
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 1, 4:17 -> 4:22 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, 4:17 -> 4:22 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: func4
end_comment

begin_function
name|void
name|func4
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE+6]]:2 = #0
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|++
operator|<
literal|10
condition|)
comment|// CHECK-NEXT: File 0, [[@LINE]]:10 -> [[@LINE]]:18 = (#0 + #1)
if|if
condition|(
name|i
operator|<
literal|5
condition|)
comment|// CHECK-NEXT: File 0, [[@LINE]]:5 -> [[@LINE+2]]:14 = #1
comment|// CHECK-NEXT: File 0, [[@LINE-1]]:9 -> [[@LINE-1]]:14 = #1
name|MACRO_2
expr_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE]]:7 -> [[@LINE]]:14 = #2
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 1, 4:17 -> 4:22 = #2
end_comment

begin_comment
comment|// CHECK-NOT: File 1
end_comment

begin_comment
comment|// CHECK-NEXT: func5
end_comment

begin_function
name|void
name|func5
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE+4]]:2 = #0
name|int
name|i
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|i
operator|>
literal|5
condition|)
comment|// CHECK-NEXT: File 0, [[@LINE]]:7 -> [[@LINE]]:12 = #0
name|MACRO_3
expr_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE]]:5 -> [[@LINE]]:12 = #1
block|}
end_function

begin_comment
comment|// CHECK-NEXT: Expansion,File 1, 6:17 -> 6:24 = #1
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, 4:17 -> 4:22 = #1
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|func
argument_list|()
expr_stmt|;
name|func2
argument_list|()
expr_stmt|;
name|func3
argument_list|()
expr_stmt|;
name|func4
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

