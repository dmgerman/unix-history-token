begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: llvm-cov show %S/Inputs/prevent_false_instantiations.covmapping -instr-profile %S/Inputs/elf_binary_comdat.profdata -filename-equivalence /dev/null | FileCheck %s -allow-empty -check-prefix=FAKE-FILE-STDOUT
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/prevent_false_instantiations.covmapping -instr-profile %S/Inputs/elf_binary_comdat.profdata -filename-equivalence /dev/null 2>&1 | FileCheck %s -check-prefix=FAKE-FILE-STDERR
end_comment

begin_comment
comment|// RUN: not llvm-cov report %S/Inputs/prevent_false_instantiations.covmapping -instr-profile %S/Inputs/elf_binary_comdat.profdata -format=html
end_comment

begin_comment
comment|// RUN: not llvm-cov export %S/Inputs/prevent_false_instantiations.covmapping -instr-profile %S/Inputs/elf_binary_comdat.profdata -format=html
end_comment

begin_comment
comment|// FAKE-FILE-STDOUT-NOT: warning: The file '{{.*}}' isn't covered.
end_comment

begin_comment
comment|// FAKE-FILE-STDERR: warning: The file '{{.*}}' isn't covered.
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/prevent_false_instantiations.covmapping -instr-profile %S/Inputs/elf_binary_comdat.profdata -filename-equivalence -name ".*" /dev/null | FileCheck %s -allow-empty -check-prefix=FAKE-FUNC-STDOUT
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/prevent_false_instantiations.covmapping -instr-profile %S/Inputs/elf_binary_comdat.profdata -filename-equivalence -name-regex ".*" /dev/null 2>&1 | FileCheck %s -check-prefix=FAKE-FUNC-STDERR
end_comment

begin_comment
comment|// FAKE-FUNC-STDOUT-NOT: warning: Could not read coverage for '{{.*}}'.
end_comment

begin_comment
comment|// FAKE-FUNC-STDERR: Could not read coverage for '{{.*}}'.
end_comment

end_unit

