begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The coverage reader should be able to handle universal binaries
end_comment

begin_comment
comment|// CHECK: [[@LINE+1]]| 100|int main
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
comment|// RUN: llvm-cov export %S/Inputs/universal-binary -instr-profile %t.profdata -arch x86_64 2>&1 | FileCheck %S/Inputs/universal-binary.json
end_comment

begin_comment
comment|// RUN: not llvm-cov show %S/Inputs/universal-binary -instr-profile %t.profdata -filename-equivalence %s -arch i386 2>&1 | FileCheck --check-prefix=WRONG-ARCH %s
end_comment

begin_comment
comment|// WRONG-ARCH: Failed to load coverage
end_comment

begin_comment
comment|// RUN: not llvm-cov report -instr-profile %t.profdata 2>&1 | FileCheck --check-prefix=MISSING-BINARY %s
end_comment

begin_comment
comment|// MISSING-BINARY: No filenames specified!
end_comment

end_unit

