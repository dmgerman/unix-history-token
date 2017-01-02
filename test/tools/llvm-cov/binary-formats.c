begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Checks for reading various formats.
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
comment|// RUN: llvm-profdata merge %S/Inputs/binary-formats.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/binary-formats.macho32l -instr-profile %t.profdata -filename-equivalence %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/binary-formats.macho64l -instr-profile %t.profdata -filename-equivalence %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/binary-formats.macho32b -instr-profile %t.profdata -filename-equivalence %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: llvm-cov export %S/Inputs/binary-formats.macho32l -instr-profile %t.profdata | FileCheck %S/Inputs/binary-formats.canonical.json
end_comment

begin_comment
comment|// RUN: llvm-cov export %S/Inputs/binary-formats.macho64l -instr-profile %t.profdata | FileCheck %S/Inputs/binary-formats.canonical.json
end_comment

begin_comment
comment|// RUN: llvm-cov export %S/Inputs/binary-formats.macho32b -instr-profile %t.profdata | FileCheck %S/Inputs/binary-formats.canonical.json
end_comment

end_unit

