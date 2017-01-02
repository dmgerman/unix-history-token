begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that llvm-cov loads real coverage mapping data for a function
end_comment

begin_comment
comment|// even though dummy coverage data for that function comes first.
end_comment

begin_comment
comment|// Dummy coverage data is exported if the definition of an inline function
end_comment

begin_comment
comment|// is seen but the function is not used in the translation unit.
end_comment

begin_comment
comment|// If you need to rebuild the 'covmapping' file for this test, please use
end_comment

begin_comment
comment|// the following commands:
end_comment

begin_comment
comment|// clang++ -fprofile-instr-generate -fcoverage-mapping -o tmp -x c++ prefer_used_to_unused.h prefer_used_to_unused.cpp
end_comment

begin_comment
comment|// llvm-cov convert-for-testing -o prefer_used_to_unused.covmapping tmp
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/prefer_used_to_unused.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: llvm-cov show %S/Inputs/prefer_used_to_unused.covmapping -instr-profile %t.profdata -filename-equivalence %s | FileCheck %s
end_comment

begin_comment
comment|// Coverage data for this function has a non-zero hash value if it is used in the translation unit.
end_comment

begin_function
specifier|inline
name|int
name|sampleFunc
parameter_list|(
name|int
name|A
parameter_list|)
block|{
comment|// CHECK:      [[@LINE]]| 1|inline int sampleFunc(int A) {
if|if
condition|(
name|A
operator|>
literal|0
condition|)
comment|// CHECK-NEXT: [[@LINE]]| 1|  if (A> 0)
return|return
name|A
return|;
comment|// CHECK-NEXT: [[@LINE]]| 1|    return A;
return|return
literal|0
return|;
comment|// CHECK-NEXT: [[@LINE]]| 0|  return 0;
block|}
end_function

begin_comment
comment|// CHECK-NEXT: [[@LINE]]| 1|}
end_comment

begin_comment
comment|// The hash for this function is zero in both cases, either it is used in the translation unit or not.
end_comment

begin_function
specifier|inline
name|int
name|simpleFunc
parameter_list|(
name|int
name|A
parameter_list|)
block|{
comment|// CHECK:      [[@LINE]]| 1|inline int simpleFunc(int A) {
return|return
name|A
return|;
comment|// CHECK-NEXT: [[@LINE]]| 1|  return A;
block|}
end_function

begin_comment
comment|// CHECK-NEXT: [[@LINE]]| 1|}
end_comment

end_unit

