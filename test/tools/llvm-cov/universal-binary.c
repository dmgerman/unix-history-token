begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The coverage reader should be able to handle universal binaries
end_comment

begin_comment
comment|// CHECK: 100| [[@LINE+1]]|int main
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
block|{}
end_function

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/universal-binary.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/universal-binary -instr-profile %t.profdata -filename-equivalence %s -arch x86_64 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not llvm-cov show %S/Inputs/universal-binary -instr-profile %t.profdata -filename-equivalence %s -arch i386 2>&1 | FileCheck --check-prefix=WRONG-ARCH %s
end_comment

begin_comment
comment|// WRONG-ARCH: Failed to load coverage
end_comment

end_unit

