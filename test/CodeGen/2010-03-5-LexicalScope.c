begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -g %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: DW_TAG_lexical_block
end_comment

begin_comment
comment|// CHECK: DW_TAG_lexical_block
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|i
condition|)
block|{
name|int
name|j
init|=
literal|2
decl_stmt|;
block|}
else|else
block|{
name|int
name|j
init|=
literal|3
decl_stmt|;
block|}
return|return
name|i
return|;
block|}
end_function

end_unit

