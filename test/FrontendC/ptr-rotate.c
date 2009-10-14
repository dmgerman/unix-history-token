begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -c -m32 -o /dev/null
end_comment

begin_comment
comment|// RUN: %llvmgcc %s -c -O1 -m32 -emit-llvm -o - | llc -march=x86 -mtriple=i386-apple-darwin9.7 | FileCheck %s -check-prefix=DARWIN
end_comment

begin_function
name|unsigned
name|int
name|func
parameter_list|(
name|void
modifier|*
name|A
parameter_list|)
block|{
comment|// DARWIN: roll $27
return|return
operator|(
operator|(
operator|(
operator|(
name|unsigned
name|long
name|long
operator|)
name|A
operator|)
operator|>>
literal|5
operator|)
operator||
operator|(
operator|(
operator|(
name|unsigned
name|long
name|long
operator|)
name|A
operator|)
operator|<<
literal|27
operator|)
operator|)
return|;
block|}
end_function

end_unit

