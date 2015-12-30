begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -triple powerpc64le-linux-gnu -emit-llvm %s -o -
end_comment

begin_decl_stmt
name|long
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"power8-vector,no-vsx"
argument_list|)
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

begin_comment
comment|// expected-error {{option '-mpower8-vector' cannot be specified with '-mno-vsx'}}
end_comment

end_unit

