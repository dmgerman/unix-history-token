begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm< %s -o %t
end_comment

begin_comment
comment|// RUN: grep 'dllexport' %t | count 1
end_comment

begin_comment
comment|// RUN: not grep 'dllimport' %t
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllimport
operator|)
argument_list|)
name|foo1
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|foo1
argument_list|()
block|{}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|dllexport
operator|)
argument_list|)
name|foo2
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

