begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name macro-expansion.c %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: func
end_comment

begin_comment
comment|// CHECK:      File 1, [[@LINE+5]]:12 -> [[@LINE+5]]:38 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, [[@LINE+4]]:15 -> [[@LINE+4]]:28 = (#0 + #2)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, [[@LINE+3]]:21 -> [[@LINE+3]]:22 = (#0 + #2)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, [[@LINE+2]]:24 -> [[@LINE+2]]:26 = #3
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, [[@LINE+1]]:36 -> [[@LINE+1]]:37 = (#0 + #2)
end_comment

begin_define
define|#
directive|define
name|M1
value|do { if (0) {} } while (0)
end_define

begin_comment
comment|// CHECK-NEXT: File 2, [[@LINE+10]]:15 -> [[@LINE+10]]:41 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, [[@LINE+9]]:18 -> [[@LINE+9]]:31 = (#0 + #4)
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, [[@LINE+8]]:24 -> [[@LINE+8]]:25 = (#0 + #4)
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, [[@LINE+7]]:27 -> [[@LINE+7]]:29 = #5
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, [[@LINE+6]]:39 -> [[@LINE+6]]:40 = (#0 + #4)
end_comment

begin_comment
comment|// CHECK-NEXT: File 3, [[@LINE+5]]:15 -> [[@LINE+5]]:41 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 3, [[@LINE+4]]:18 -> [[@LINE+4]]:31 = (#0 + #6)
end_comment

begin_comment
comment|// CHECK-NEXT: File 3, [[@LINE+3]]:24 -> [[@LINE+3]]:25 = (#0 + #6)
end_comment

begin_comment
comment|// CHECK-NEXT: File 3, [[@LINE+2]]:27 -> [[@LINE+2]]:29 = #7
end_comment

begin_comment
comment|// CHECK-NEXT: File 3, [[@LINE+1]]:39 -> [[@LINE+1]]:40 = (#0 + #6)
end_comment

begin_define
define|#
directive|define
name|M2
parameter_list|(
name|x
parameter_list|)
value|do { if (x) {} } while (0)
end_define

begin_comment
comment|// CHECK-NEXT: File 4, [[@LINE+4]]:15 -> [[@LINE+4]]:38 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 4, [[@LINE+3]]:18 -> [[@LINE+3]]:28 = (#0 + #8)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 4, [[@LINE+2]]:20 -> [[@LINE+2]]:22 = (#0 + #8)
end_comment

begin_comment
comment|// CHECK-NEXT: File 4, [[@LINE+1]]:36 -> [[@LINE+1]]:37 = (#0 + #8)
end_comment

begin_define
define|#
directive|define
name|M3
parameter_list|(
name|x
parameter_list|)
value|do { M2(x); } while (0)
end_define

begin_comment
comment|// CHECK-NEXT: File 5, [[@LINE+2]]:15 -> [[@LINE+2]]:27 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 5, [[@LINE+1]]:23 -> [[@LINE+1]]:26 = #12
end_comment

begin_define
define|#
directive|define
name|M4
parameter_list|(
name|x
parameter_list|)
value|((x)&& (x))
end_define

begin_comment
comment|// CHECK-NEXT: File 6, [[@LINE+2]]:15 -> [[@LINE+2]]:27 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 6, [[@LINE+1]]:23 -> [[@LINE+1]]:26 = #14
end_comment

begin_define
define|#
directive|define
name|M5
parameter_list|(
name|x
parameter_list|)
value|((x) || (x))
end_define

begin_comment
comment|// CHECK-NEXT: File 7, [[@LINE+1]]:15 -> [[@LINE+1]]:26 = #0
end_comment

begin_define
define|#
directive|define
name|M6
parameter_list|(
name|x
parameter_list|)
value|((x) + (x))
end_define

begin_comment
comment|// CHECK-NEXT: File 8, [[@LINE+1]]:15 -> [[@LINE+1]]:18 = #0
end_comment

begin_define
define|#
directive|define
name|M7
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|// Check for the expansion of M2 within M3.
end_comment

begin_comment
comment|// CHECK-NEXT: File 9, {{[0-9]+}}:15 -> {{[0-9]+}}:41 = (#0 + #8)
end_comment

begin_comment
comment|// CHECK-NEXT: File 9, {{[0-9]+}}:18 -> {{[0-9]+}}:31 = ((#0 + #8) + #9)
end_comment

begin_comment
comment|// CHECK-NEXT: File 9, {{[0-9]+}}:24 -> {{[0-9]+}}:25 = ((#0 + #8) + #9)
end_comment

begin_comment
comment|// CHECK-NEXT: File 9, {{[0-9]+}}:27 -> {{[0-9]+}}:29 = #10
end_comment

begin_comment
comment|// CHECK-NEXT: File 9, {{[0-9]+}}:39 -> {{[0-9]+}}:40 = ((#0 + #8) + #9)
end_comment

begin_function
name|void
name|func
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
condition|)
block|{}
name|M1
expr_stmt|;
name|M2
argument_list|(
operator|!
name|x
argument_list|)
expr_stmt|;
name|M2
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|M3
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|M4
argument_list|(
name|x
argument_list|)
condition|)
block|{}
if|if
condition|(
name|M5
argument_list|(
name|x
argument_list|)
condition|)
block|{}
if|if
condition|(
name|M6
argument_list|(
name|x
argument_list|)
condition|)
block|{}
if|if
condition|(
name|M7
argument_list|(
name|x
argument_list|)
condition|)
block|{}
block|}
end_function

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
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

