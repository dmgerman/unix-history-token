begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that the -fprofile-instrument-path= form works.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -main-file-name c-generate.c %s -o - -emit-llvm -fprofile-instrument=clang -fprofile-instrument-path=c-generate-test.profraw | FileCheck %s --check-prefix=PROF-INSTR-PATH
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -o - -emit-llvm -fprofile-instrument=none | FileCheck %s --check-prefix=PROF-INSTR-NONE
end_comment

begin_comment
comment|// RUN: not %clang_cc1 %s -o - -emit-llvm -fprofile-instrument=garbage 2>&1 | FileCheck %s --check-prefix=PROF-INSTR-GARBAGE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PROF-INSTR-PATH: constant [24 x i8] c"c-generate-test.profraw\00"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PROF-INSTR-NONE-NOT: __llvm_prf
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PROF-INSTR-GARBAGE: invalid PGO instrumentor in argument '-fprofile-instrument=garbage'
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

