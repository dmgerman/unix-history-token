begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name macroparams.c %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: main
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, {{[0-9]+}}:12 -> {{[0-9]+}}:2 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 0, {{[0-9]+}}:3 -> {{[0-9]+}}:8 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, [[@LINE+2]]:18 -> [[@LINE+2]]:27 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 1, [[@LINE+1]]:18 -> [[@LINE+1]]:24 = #0
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
comment|// CHECK-NEXT: File 2, [[@LINE+1]]:20 -> [[@LINE+1]]:28 = #0
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

begin_function
name|int
name|main
parameter_list|()
block|{
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
return|return
literal|0
return|;
block|}
end_function

end_unit

