begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | grep noalias
end_comment

begin_decl_stmt
name|void
modifier|*
name|__attribute__
argument_list|(
operator|(
name|malloc
operator|)
argument_list|)
name|foo
argument_list|(
name|void
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

end_unit

