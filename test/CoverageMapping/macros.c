begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name macros.c %s | FileCheck %s
end_comment

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|;
end_function_decl

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

begin_comment
comment|// CHECK: func
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:13 -> [[@LINE+4]]:2 = #0 (HasCodeBefore = 0)
name|int
name|i
init|=
literal|0
decl_stmt|;
name|MACRO
expr_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE]]:3 -> [[@LINE]]:8 = #0 (HasCodeBefore = 0, Expanded file = 1)
name|i
operator|=
literal|2
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE]]:8 = 0 (HasCodeBefore = 0)
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 1, 4:15 -> 4:21 = #0 (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 4:23 -> 4:28 = 0 (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: func2
end_comment

begin_function
name|void
name|func2
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE+4]]:2 = #0 (HasCodeBefore = 0)
name|int
name|i
init|=
literal|0
decl_stmt|;
name|MACRO_1
expr_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE]]:3 -> [[@LINE]]:10 = #0 (HasCodeBefore = 0, Expanded file = 1)
name|i
operator|=
literal|2
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE]]:3 -> [[@LINE]]:8 = 0 (HasCodeBefore = 0)
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 1, 6:17 -> 6:23 = #0 (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 1, 6:25 -> 6:32 = 0 (HasCodeBefore = 0, Expanded file = 2)
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, 5:17 -> 5:22 = 0 (HasCodeBefore = 0)
end_comment

end_unit

