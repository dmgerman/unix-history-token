begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name macro-expansion.c %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|LBRAC
value|{
end_define

begin_define
define|#
directive|define
name|RBRAC
value|}
end_define

begin_comment
comment|// CHECK: main:
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:40 -> {{[0-9]+}}:2 = #0
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
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:7 -> [[@LINE+1]]:12 = #0
if|if
condition|(
operator|!
name|argc
condition|)
block|{}
comment|// CHECK-NEXT: File 0, [[@LINE]]:14 -> [[@LINE]]:16 = #1
comment|// CHECK-NEXT: File 0, [[@LINE+3]]:7 -> [[@LINE+3]]:12 = #0
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+2]]:14 -> [[@LINE+2]]:19 = #2
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:19 -> [[@LINE+4]]:8 = #2
if|if
condition|(
operator|!
name|argc
condition|)
name|LBRAC
return|return
literal|0
return|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+1]]:3 -> [[@LINE+1]]:8 = #2
name|RBRAC
comment|// CHECK-NEXT: File 0, [[@LINE+4]]:3 -> [[@LINE+15]]:2 = (#0 - #2)
comment|// CHECK-NEXT: File 0, [[@LINE+3]]:7 -> [[@LINE+3]]:12 = (#0 - #2)
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+2]]:14 -> [[@LINE+2]]:19 = #3
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:19 -> [[@LINE+3]]:4 = #3
if|if
condition|(
operator|!
name|argc
condition|)
name|LBRAC
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 0, [[@LINE+3]]:3 -> [[@LINE+7]]:2 = ((#0 - #2) - #3)
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, [[@LINE+2]]:7 -> [[@LINE+2]]:12 = ((#0 - #2) - #3)
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:14 -> [[@LINE+4]]:8 = #4
end_comment

begin_if
if|if
condition|(
operator|!
name|argc
condition|)
block|{
return|return
literal|0
return|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+1]]:3 -> [[@LINE+1]]:8 = #4
name|RBRAC
block|}
end_if

begin_comment
comment|// CHECK-NEXT: File 1, 3:15 -> 3:16 = #2
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, 4:15 -> 4:16 = #2
end_comment

begin_comment
comment|// CHECK-NEXT: File 3, 3:15 -> 3:16 = #3
end_comment

begin_comment
comment|// CHECK-NEXT: File 4, 4:15 -> 4:16 = #4
end_comment

end_unit

