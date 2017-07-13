begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Coverage/profile data recycled from the showLineExecutionCounts.cpp test.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/lineExecutionCounts.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/lineExecutionCounts.covmapping -j 1 -o %t1.dir -instr-profile %t.profdata -filename-equivalence %S/showLineExecutionCounts.cpp
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/lineExecutionCounts.covmapping -num-threads 2 -o %t2.dir -instr-profile %t.profdata -filename-equivalence %S/showLineExecutionCounts.cpp
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/lineExecutionCounts.covmapping -o %t3.dir -instr-profile %t.profdata -filename-equivalence %S/showLineExecutionCounts.cpp
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: diff %t1.dir/index.txt %t2.dir/index.txt
end_comment

begin_comment
comment|// RUN: diff %t1.dir/coverage/tmp/showLineExecutionCounts.cpp.txt %t2.dir/coverage/tmp/showLineExecutionCounts.cpp.txt
end_comment

begin_comment
comment|// RUN: diff %t1.dir/index.txt %t3.dir/index.txt
end_comment

begin_comment
comment|// RUN: diff %t1.dir/coverage/tmp/showLineExecutionCounts.cpp.txt %t3.dir/coverage/tmp/showLineExecutionCounts.cpp.txt
end_comment

end_unit

