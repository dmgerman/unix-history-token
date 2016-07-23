begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|ifc
value|if
end_define

begin_comment
comment|// CHECK: main
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, {{[0-9]+}}:40 -> [[END:[0-9]+]]:2 = #0
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
comment|// CHECK: Expansion,File 0, [[@LINE+1]]:3 -> [[@LINE+1]]:6 = #0
name|ifc
argument_list|(
literal|1
argument_list|)
return|return
literal|0
return|;
comment|// Expansion,File 0, [[@LINE+2]]:3 -> [[@LINE+2]]:6 = (#0 - #1)
comment|// File 0, [[@LINE+1]]:6 -> [[END]]:2 = (#0 - #1)
name|ifc
argument_list|(
literal|1
argument_list|)
return|return
literal|0
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

