begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR13606 - Clang crashes with large alignment attribute
end_comment

begin_comment
comment|// RUN: %clang -S -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: x
end_comment

begin_comment
comment|// CHECK: align
end_comment

begin_comment
comment|// CHECK: 1048576
end_comment

begin_decl_stmt
specifier|volatile
name|char
name|x
index|[
literal|4000
index|]
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|0x100000
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
comment|// CHECK: y
comment|// CHECK: align
comment|// CHECK: 1048576
specifier|volatile
name|char
name|y
index|[
literal|4000
index|]
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|0x100000
argument_list|)
operator|)
argument_list|)
decl_stmt|;
return|return
name|y
index|[
name|argc
index|]
return|;
block|}
end_function

end_unit

