begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386-unknown-unknown -emit-llvm -S -o - %s | FileCheck %s
end_comment

begin_decl_stmt
specifier|const
name|int
name|AA
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @f1
end_comment

begin_decl_stmt
name|int
name|f1
argument_list|(
expr|enum
block|{
name|AA
block|,
name|BB
block|}
name|E
argument_list|)
block|{
comment|// CHECK: ret i32 1
return|return
name|BB
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-LABEL: define i32 @f2
end_comment

begin_decl_stmt
name|int
name|f2
argument_list|(
expr|enum
block|{
name|AA
operator|=
literal|7
block|,
name|BB
block|}
name|E
argument_list|)
block|{
comment|// CHECK: ret i32 7
return|return
name|AA
return|;
block|}
end_decl_stmt

begin_comment
comment|// Check nested function declarators work.
end_comment

begin_decl_stmt
name|int
name|f
argument_list|(
name|void
argument_list|(
operator|*
name|g
argument_list|)
argument_list|()
argument_list|,
expr|enum
block|{
name|AA
block|,
name|BB
block|}
name|h
argument_list|)
block|{
comment|// CHECK: ret i32 0
return|return
name|AA
return|;
block|}
end_decl_stmt

end_unit

