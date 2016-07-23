begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|WHILE
value|while (0) {}
end_define

begin_comment
comment|// CHECK: counters_in_macro_following_unreachable
end_comment

begin_function
name|void
name|counters_in_macro_following_unreachable
parameter_list|()
block|{
comment|// CHECK-NEXT: File 0, [[@LINE-1]]:48 -> {{[0-9]+}}:2 = #0
return|return;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+2]]:3 -> [[@LINE+2]]:8 = 0
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:8 -> [[@LINE+2]]:2 = 0
name|WHILE
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 1, 3:15 -> 3:27 = 0
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 3:22 -> 3:23 = #1
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 3:25 -> 3:27 = #1
end_comment

end_unit

