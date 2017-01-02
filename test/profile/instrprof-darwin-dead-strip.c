begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: osx-ld64-live_support
end_comment

begin_comment
comment|// REQUIRES: lto
end_comment

begin_comment
comment|// RUN: %clang_profgen=%t.profraw -fcoverage-mapping -mllvm -enable-name-compression=false -Wl,-dead_strip -o %t %s
end_comment

begin_comment
comment|// RUN: %run %t
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.profdata %t.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions %t.profdata | FileCheck %s -check-prefix=PROF
end_comment

begin_comment
comment|// RUN: llvm-cov show %t -instr-profile %t.profdata | FileCheck %s -check-prefix=COV
end_comment

begin_comment
comment|// RUN: nm %t | FileCheck %s -check-prefix=NM
end_comment

begin_comment
comment|// RUN: otool -s __DATA __llvm_prf_names %t | FileCheck %s -check-prefix=PRF_NAMES
end_comment

begin_comment
comment|// RUN: otool -s __DATA __llvm_prf_cnts %t | FileCheck %s -check-prefix=PRF_CNTS
end_comment

begin_comment
comment|// RUN: %clang_lto_profgen=%t.lto.profraw -fcoverage-mapping -mllvm -enable-name-compression=false -Wl,-dead_strip -flto -o %t.lto %s
end_comment

begin_comment
comment|// RUN: %run %t.lto
end_comment

begin_comment
comment|// RUN: llvm-profdata merge -o %t.lto.profdata %t.lto.profraw
end_comment

begin_comment
comment|// RUN: llvm-profdata show --all-functions %t.lto.profdata | FileCheck %s -check-prefix=PROF
end_comment

begin_comment
comment|// RUN: llvm-cov show %t.lto -instr-profile %t.lto.profdata | FileCheck %s -check-prefix=COV
end_comment

begin_comment
comment|// RUN: nm %t.lto | FileCheck %s -check-prefix=NM
end_comment

begin_comment
comment|// RUN: otool -s __DATA __llvm_prf_names %t.lto | FileCheck %s -check-prefix=PRF_NAMES
end_comment

begin_comment
comment|// RUN: otool -s __DATA __llvm_prf_cnts %t.lto | FileCheck %s -check-prefix=PRF_CNTS
end_comment

begin_comment
comment|// Note: We expect foo() and some of the profiling data associated with it to
end_comment

begin_comment
comment|// be dead-stripped.
end_comment

begin_comment
comment|// COV: [[@LINE+1]]{{ *}}|{{ *}}0|void foo()
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{}
end_function

begin_comment
comment|// COV: [[@LINE+1]]{{ *}}|{{ *}}1|int main
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// NM-NOT: foo
end_comment

begin_comment
comment|// PROF: Counters:
end_comment

begin_comment
comment|// PROF-NEXT:   main:
end_comment

begin_comment
comment|// PROF-NEXT:     Hash:
end_comment

begin_comment
comment|// PROF-NEXT:     Counters: 1
end_comment

begin_comment
comment|// PROF-NEXT:     Function count: 1
end_comment

begin_comment
comment|// PROF-NEXT: Functions shown: 1
end_comment

begin_comment
comment|// PROF-NEXT: Total functions: 1
end_comment

begin_comment
comment|// PROF-NEXT: Maximum function count: 1
end_comment

begin_comment
comment|// PROF-NEXT: Maximum internal block count: 0
end_comment

begin_comment
comment|// Note: We don't expect the names of dead-stripped functions to disappear from
end_comment

begin_comment
comment|// __llvm_prf_names, because collectPGOFuncNameStrings() glues the names
end_comment

begin_comment
comment|// together.
end_comment

begin_comment
comment|// PRF_NAMES: Contents of (__DATA,__llvm_prf_names) section
end_comment

begin_comment
comment|// PRF_NAMES-NEXT: {{.*}} 08 00 66 6f 6f 01 6d 61 69 6e{{ +$}}
end_comment

begin_comment
comment|//                        |  |  f  o  o  #  m  a  i  n
end_comment

begin_comment
comment|//                        |  |___________|
end_comment

begin_comment
comment|//                        |              |
end_comment

begin_comment
comment|//               UncompressedLen = 8     |
end_comment

begin_comment
comment|//                                       |
end_comment

begin_comment
comment|//                                CompressedLen = 0
end_comment

begin_comment
comment|// Note: We expect the profile counters for dead-stripped functions to also be
end_comment

begin_comment
comment|// dead-stripped.
end_comment

begin_comment
comment|// PRF_CNTS: Contents of (__DATA,__llvm_prf_cnts) section
end_comment

begin_comment
comment|// PRF_CNTS-NEXT: {{.*}} 00 00 00 00 00 00 00 00{{ +$}}
end_comment

end_unit

