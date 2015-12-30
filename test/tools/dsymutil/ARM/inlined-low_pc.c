begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Compiled with: clang -arch=arm64 -O2 -g -c inlined_low_pc.c */
end_comment

begin_function
specifier|static
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
literal|42
operator|+
name|i
return|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|foo
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// RUN: llvm-dsymutil -f -y %p/dummy-debug-map-amr64.map -oso-prepend-path %p/../Inputs/inlined-low_pc -o - | llvm-dwarfdump - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: DW_TAG_subprogram
end_comment

begin_comment
comment|// CHECK: DW_AT_low_pc{{.*}}0x0000000000010000
end_comment

begin_comment
comment|// CHECK: DW_AT_name{{.*}}"bar"
end_comment

begin_comment
comment|// CHECK-NOT: NULL
end_comment

begin_comment
comment|// CHECK: DW_TAG_inlined_subroutine
end_comment

begin_comment
comment|// CHECK-NEXT: DW_AT_abstract_origin{{.*}}"foo"
end_comment

begin_comment
comment|// CHECK-NEXT: DW_AT_low_pc{{.*}}0x0000000000010000
end_comment

end_unit

