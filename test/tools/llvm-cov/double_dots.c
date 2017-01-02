begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// To create the covmapping for this file, copy this file to /tmp/dots/,
end_comment

begin_comment
comment|// cd into /tmp/dots, and pass "../dots/double_dots.c" to the compiler. Use
end_comment

begin_comment
comment|// llvm-cov convert-for-testing to extract the covmapping.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/double_dots.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/double_dots.covmapping -instr-profile=%t.profdata -o %t.dir
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t.dir/index.txt %s
end_comment

begin_comment
comment|// RUN: llvm-cov show -format=html %S/Inputs/double_dots.covmapping -instr-profile=%t.profdata -o %t.dir
end_comment

begin_comment
comment|// RUN: FileCheck -input-file=%t.dir/index.html %s
end_comment

begin_comment
comment|// CHECK-NOT: coverage{{.*}}dots{{.*}}..{{.*}}dots
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{}
end_function

begin_comment
comment|// Re-purpose this file to test that we use relative paths when creating
end_comment

begin_comment
comment|// report indices:
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=REL-INDEX -input-file %t.dir/index.txt %s
end_comment

begin_comment
comment|// REL-INDEX-NOT: %t.dir
end_comment

begin_comment
comment|// Check that we get the right error when writing to an invalid path:
end_comment

begin_comment
comment|// RUN: not llvm-cov show %S/Inputs/double_dots.covmapping -instr-profile=%t.profdata -o /dev/null 2>&1 | FileCheck %s -check-prefix=ERROR-MESSAGE
end_comment

begin_comment
comment|// ERROR-MESSAGE: error: {{.*}}: Could not create index file!
end_comment

end_unit

