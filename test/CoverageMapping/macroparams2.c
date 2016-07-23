begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name macroparams2.c %s | FileCheck %s
end_comment

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

begin_comment
comment|// CHECK: File 0, [[@LINE+1]]:12 -> [[@LINE+10]]:2 = #0
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
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
name|int
name|n
init|=
literal|0
decl_stmt|;
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE+2]]:7 -> [[@LINE+2]]:12 = #0
comment|// CHECK-NEXT: File 0, [[@LINE+1]]:34 -> [[@LINE+3]]:4 = #1
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
name|n
operator|=
literal|1
expr_stmt|;
block|}
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|// CHECK: File 1, 3:29 -> 3:51 = #0
end_comment

end_unit

