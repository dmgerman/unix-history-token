begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name macroparams.c %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|MACRO2
parameter_list|(
name|X2
parameter_list|)
value|(X2 + 2)
end_define

begin_comment
comment|// CHECK-DAG: File 2, [[@LINE]]:20 -> [[@LINE]]:28 = #0 (HasCodeBefore = 0)
end_comment

begin_define
define|#
directive|define
name|MACRO
parameter_list|(
name|X
parameter_list|)
value|MACRO2(x)
end_define

begin_comment
comment|// CHECK-DAG: File 1, [[@LINE]]:25 -> [[@LINE]]:26 = #0 (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-DAG: Expansion,File 1, [[@LINE-1]]:18 -> [[@LINE-1]]:24 = #0 (HasCodeBefore = 0, Expanded file = 2)
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK-DAG: File 0, [[@LINE]]:12 -> [[@LINE+4]]:2 = #0 (HasCodeBefore = 0)
name|int
name|x
init|=
literal|0
decl_stmt|;
name|MACRO
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK-DAG: Expansion,File 0, [[@LINE]]:3 -> [[@LINE]]:8 = #0 (HasCodeBefore = 0, Expanded file = 1)
return|return
literal|0
return|;
block|}
end_function

end_unit

