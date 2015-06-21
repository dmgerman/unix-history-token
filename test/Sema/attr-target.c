begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu  -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"avx,sse4.2,arch=ivybridge"
argument_list|)
operator|)
argument_list|)
name|foo
argument_list|()
block|{
return|return
literal|4
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|()
operator|)
argument_list|)
name|bar
argument_list|()
block|{
return|return
literal|4
return|;
block|}
end_decl_stmt

begin_comment
comment|//expected-error {{'target' attribute takes one argument}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"tune=sandybridge"
argument_list|)
operator|)
argument_list|)
name|baz
argument_list|()
block|{
return|return
literal|4
return|;
block|}
end_decl_stmt

begin_comment
comment|//expected-warning {{Ignoring unsupported 'tune=' in the target attribute string}}
end_comment

begin_decl_stmt
name|int
name|__attribute__
argument_list|(
operator|(
name|target
argument_list|(
literal|"fpmath=387"
argument_list|)
operator|)
argument_list|)
name|walrus
argument_list|()
block|{
return|return
literal|4
return|;
block|}
end_decl_stmt

begin_comment
comment|//expected-warning {{Ignoring unsupported 'fpmath=' in the target attribute string}}
end_comment

end_unit

