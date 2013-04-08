begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|nomips16
operator|)
argument_list|)
name|foo32
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unknown attribute 'nomips16' ignored}}
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|mips16
operator|)
argument_list|)
name|foo16
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unknown attribute 'mips16' ignored}}
end_comment

end_unit

