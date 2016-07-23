begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name include-macros.c %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"Inputs/macros.h"
end_include

begin_function
name|void
name|f1
parameter_list|()
block|{
name|M2
argument_list|(
literal|"a"
argument_list|,
literal|"b"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: f1:
end_comment

begin_comment
comment|// CHECK-NEXT:   File 0, 5:11 -> 7:2 = #0
end_comment

begin_comment
comment|// CHECK-NEXT:   Expansion,File 0, 6:3 -> 6:5 = #0 (Expanded file = 1)
end_comment

begin_comment
comment|// CHECK-NEXT:   File 1, 13:20 -> 13:50 = #0
end_comment

begin_comment
comment|// CHECK-NEXT:   Expansion,File 1, 13:20 -> 13:22 = #0 (Expanded file = 2)
end_comment

begin_comment
comment|// CHECK-NEXT:   File 2, 7:20 -> 7:46 = #0
end_comment

begin_comment
comment|// CHECK-NEXT:   Expansion,File 2, 7:33 -> 7:44 = #0 (Expanded file = 3)
end_comment

begin_comment
comment|// CHECK-NEXT:   File 3, 13:26 -> 13:34 = #0
end_comment

begin_comment
comment|// CHECK-NEXT:   Expansion,File 3, 13:26 -> 13:33 = #0 (Expanded file = 4)
end_comment

begin_comment
comment|// CHECK-NEXT:   File 4, 3:17 -> 3:18 = #0
end_comment

end_unit

