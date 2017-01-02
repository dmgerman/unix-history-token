begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// To create the covmapping for this file on Linux, copy this file to /tmp
end_comment

begin_comment
comment|// cd into /tmp. Use llvm-cov convert-for-testing to extract the covmapping.
end_comment

begin_comment
comment|// This test is Windows-only. It checks that all paths, which are generated
end_comment

begin_comment
comment|// in the index and source coverage reports, are native path. For example,
end_comment

begin_comment
comment|// on Windows all '/' are converted to '\'.
end_comment

begin_comment
comment|// REQUIRES: system-windows
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/double_dots.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/native_separators.covmapping -instr-profile=%t.profdata -o %t.dir
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefixes=TEXT-INDEX -input-file=%t.dir/index.txt %s
end_comment

begin_comment
comment|// RUN: llvm-cov show -format=html %S/Inputs/native_separators.covmapping -instr-profile=%t.profdata -filename-equivalence ../llvm-"config"/../llvm-"cov"/native_separators.c -o %t.dir
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefixes=HTML-INDEX -input-file=%t.dir/index.html %s
end_comment

begin_comment
comment|// RUN: llvm-cov show -format=html %S/Inputs/native_separators.covmapping -instr-profile=%t.profdata -filename-equivalence %s -o %t.dir
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefixes=HTML -input-file=%t.dir/coverage/tmp/native_separators.c.html %s
end_comment

begin_comment
comment|// TEXT-INDEX: \tmp\native_separators.c
end_comment

begin_comment
comment|// HTML-INDEX:>tmp\native_separators.c</a>
end_comment

begin_comment
comment|// HTML:<pre>\tmp\native_separators.c</pre>
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{}
end_function

end_unit

