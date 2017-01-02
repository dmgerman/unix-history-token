begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name macroception.c %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|M2
value|{
end_define

begin_define
define|#
directive|define
name|M1
value|M2
end_define

begin_define
define|#
directive|define
name|M22
value|}
end_define

begin_define
define|#
directive|define
name|M11
value|M22
end_define

begin_comment
comment|// CHECK-LABEL: main:
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+2]]:12 -> [[@LINE+2]]:14 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:14 -> [[@LINE+3]]:2 = #0
end_comment

begin_expr_stmt
name|int
expr|main
operator|(
operator|)
name|M1
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

begin_comment
unit|}
comment|// CHECK-NEXT: Expansion,File 1, 4:12 -> 4:14 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, 3:12 -> 3:13 = #0
end_comment

begin_comment
comment|// CHECK-LABEL: func2:
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, [[@LINE+2]]:14 -> [[@LINE+4]]:4 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+3]]:1 -> [[@LINE+3]]:4 = #0
end_comment

begin_macro
unit|void
name|func2
argument_list|()
end_macro

begin_block
block|{
name|int
name|x
init|=
literal|0
decl_stmt|;
name|M11
comment|// CHECK-NEXT: Expansion,File 1, 6:13 -> 6:16 = #0
comment|// CHECK-NEXT: File 2, 5:13 -> 5:14 = #0
comment|// CHECK-LABEL: func3:
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+3]]:14 -> [[@LINE+3]]:16 = #0
comment|// CHECK-NEXT: File 0, [[@LINE+2]]:16 -> [[@LINE+4]]:4 = #0
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+3]]:1 -> [[@LINE+3]]:4 = #0
name|void
name|func3
argument_list|()
name|M1
name|int
name|x
operator|=
literal|0
expr_stmt|;
name|M11
comment|// CHECK-NEXT: Expansion,File 1, 4:12 -> 4:14 = #0
comment|// CHECK-NEXT: Expansion,File 2, 6:13 -> 6:16 = #0
comment|// CHECK-NEXT: File 3, 3:12 -> 3:13 = #0
comment|// CHECK-NEXT: File 4, 5:13 -> 5:14 = #0
comment|// CHECK-LABEL: func4:
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+3]]:14 -> [[@LINE+3]]:16 = #0
comment|// CHECK-NEXT: File 0, [[@LINE+2]]:16 -> [[@LINE+2]]:20 = #0
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+1]]:17 -> [[@LINE+1]]:20 = #0
name|void
name|func4
argument_list|()
name|M1
name|M11
end_block

begin_comment
comment|// CHECK-NEXT: Expansion,File 1, 4:12 -> 4:14 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 2, 6:13 -> 6:16 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 3, 3:12 -> 3:13 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 4, 5:13 -> 5:14 = #0
end_comment

end_unit

