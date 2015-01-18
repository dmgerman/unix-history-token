begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name macroparams2.c %s | FileCheck %s
end_comment

begin_comment
comment|// A test case for when the first macro parameter is used after the second
end_comment

begin_comment
comment|// macro parameter.
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MACRO
parameter_list|(
name|REFS
parameter_list|,
name|CALLS
parameter_list|)
value|(4 * (CALLS)< (REFS))
end_define

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: File 0, [[@LINE]]:12 -> [[@LINE+7]]:2 = #0 (HasCodeBefore = 0)
name|struct
name|S
name|arr
index|[
literal|32
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+2]]:7 -> [[@LINE+2]]:12 = #0 (HasCodeBefore = 0, Expanded file = 1)
name|int
name|n
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:13 -> [[@LINE+1]]:21 = #0 (HasCodeBefore = 0)
if|if
condition|(
name|MACRO
argument_list|(
name|arr
index|[
name|n
index|]
operator|.
name|j
argument_list|,
name|arr
index|[
name|n
index|]
operator|.
name|i
argument_list|)
condition|)
block|{
comment|// CHECK-NEXT: File 0, [[@LINE]]:23 -> [[@LINE]]:31 = #0 (HasCodeBefore = 0)
name|n
operator|=
literal|1
expr_stmt|;
comment|// CHECK-NEXT: File 0, [[@LINE-1]]:34 -> [[@LINE+1]]:4 = #1 (HasCodeBefore = 0)
block|}
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|// CHECK-NEXT: File 1, [[@LINE-9]]:29 -> [[@LINE-9]]:51 = #0 (HasCodeBefore = 0
end_comment

end_unit

